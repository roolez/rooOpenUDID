/*
Generic implementation of the rooOpenUDID extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "rooOpenUDID_internal.h"
s3eResult rooOpenUDIDInit()
{
    //Add any generic initialisation code here
    return rooOpenUDIDInit_platform();
}

void rooOpenUDIDTerminate()
{
    //Add any generic termination code here
    rooOpenUDIDTerminate_platform();
}

void rooOpenUDID_init()
{
	rooOpenUDID_init_platform();
}

bool rooOpenUDID_isInitialized()
{
	return rooOpenUDID_isInitialized_platform();
}

const char * rooOpenUDID_getValue()
{
	return rooOpenUDID_getValue_platform();
}
