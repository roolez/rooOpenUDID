/*
 * android-specific implementation of the rooOpenUDID extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "rooOpenUDID_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"


const char * g_Str = NULL;



static jobject g_Obj;
static jmethodID g_rooOpenUDID_init;
static jmethodID g_rooOpenUDID_isInitialized;
static jmethodID g_rooOpenUDID_getValue;

s3eResult rooOpenUDIDInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("rooOpenUDID");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_rooOpenUDID_init = env->GetMethodID(cls, "rooOpenUDID_init", "()V");
    if (!g_rooOpenUDID_init)
        goto fail;

    g_rooOpenUDID_isInitialized = env->GetMethodID(cls, "rooOpenUDID_isInitialized", "()Z");
    if (!g_rooOpenUDID_isInitialized)
        goto fail;

    g_rooOpenUDID_getValue = env->GetMethodID(cls, "rooOpenUDID_getValue", "()Ljava/lang/String;");
    if (!g_rooOpenUDID_getValue)
        goto fail;



    IwTrace(ROOOPENUDID, ("ROOOPENUDID init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(rooOpenUDID, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void rooOpenUDIDTerminate_platform()
{
    // Add any platform-specific termination code here
}

void rooOpenUDID_init_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_rooOpenUDID_init);
}

bool rooOpenUDID_isInitialized_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_rooOpenUDID_isInitialized);
}

const char * rooOpenUDID_getValue_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject ret = env->CallObjectMethod(g_Obj, g_rooOpenUDID_getValue);
    jstring s = (jstring)ret;
    jboolean b;
    const char* str = env->GetStringUTFChars(s, &b);
    if(g_Str)
    	free((void*)g_Str);
    g_Str = strdup(str);

    env->ReleaseStringUTFChars(s, str);

    return g_Str;

}
