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

OpenUDID * g_rooOpenUDID; 
const char * g_rooOpenUDID_str; 
s3eResult rooOpenUDIDInit_platform()
{
    // Add any platform-specific initialisation code here
    g_rooOpenUDID = [[OpenUDID alloc] init];
    g_rooOpenUDID_str = nil;
    return S3E_RESULT_SUCCESS;
}

void rooOpenUDIDTerminate_platform()
{
    [g_rooOpenUDID release];
    if(g_rooOpenUDID_str)
        free((void*)g_rooOpenUDID_str);
    // Add any platform-specific termination code here
}

void rooOpenUDID_init_platform()
{
}

bool rooOpenUDID_isInitialized_platform()
{
    return true;
}

const char * rooOpenUDID_getValue_platform()
{
    NSString* s1 = [g_rooOpenUDID value];
    if(g_rooOpenUDID_str)
        free((void*)g_rooOpenUDID_str);
    g_rooOpenUDID_str = strdup([s1 UTF8String]);
    return g_rooOpenUDID_str;
}
