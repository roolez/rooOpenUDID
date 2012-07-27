/*
 * iphone-specific implementation of the rooOpenUDID extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "rooOpenUDID_internal.h"
#include "OpenUDID.h"
#include "s3eDebug.h"

const char * g_rooOpenUDID_str; 
s3eResult rooOpenUDIDInit_platform()
{
    s3eDebugOutputString("rooOpenUDIDInit_platform");
    g_rooOpenUDID_str = nil;
    return S3E_RESULT_SUCCESS;
}

void rooOpenUDIDTerminate_platform()
{
    s3eDebugOutputString("rooOpenUDIDTerminate_platform");

    if(g_rooOpenUDID_str)
        free((void*)g_rooOpenUDID_str);
}

void rooOpenUDID_init_platform()
{
    s3eDebugOutputString("rooOpenUDID_init_platform");
}

bool rooOpenUDID_isInitialized_platform()
{
    s3eDebugOutputString("rooOpenUDID_isInitialized_platform");
    return true;
}

const char * rooOpenUDID_getValue_platform()
{
    s3eDebugOutputString("rooOpenUDID_getValue_platform");

    {
        NSString* s1 = [OpenUDID value];
        s3eDebugOutputString("5");
        if(g_rooOpenUDID_str)
            free((void*)g_rooOpenUDID_str);
        g_rooOpenUDID_str = strdup([s1 UTF8String]);
        s3eDebugOutputString(g_rooOpenUDID_str);
        s3eDebugOutputString("5");
        
    }
    return g_rooOpenUDID_str;
}
