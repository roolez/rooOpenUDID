/*
 * Internal header for the rooOpenUDID extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef ROOOPENUDID_INTERNAL_H
#define ROOOPENUDID_INTERNAL_H

#include "s3eTypes.h"
#include "rooOpenUDID.h"
#include "rooOpenUDID_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult rooOpenUDIDInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult rooOpenUDIDInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void rooOpenUDIDTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void rooOpenUDIDTerminate_platform();
void rooOpenUDID_init_platform();

bool rooOpenUDID_isInitialized_platform();

const char * rooOpenUDID_getValue_platform();


#endif /* !ROOOPENUDID_INTERNAL_H */