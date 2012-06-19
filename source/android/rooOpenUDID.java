/*
java implementation of the rooOpenUDID extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;


class rooOpenUDID
{
    public void rooOpenUDID_init()
    {
         org.OpenUDID.OpenUDID_manager.sync(LoaderActivity.m_Activity.getApplicationContext());
    }
    public boolean rooOpenUDID_isInitialized()
    {
        return org.OpenUDID.OpenUDID_manager.isInitialized();
    }
    public String rooOpenUDID_getValue()
    {
        return org.OpenUDID.OpenUDID_manager.getOpenUDID();
    }
}
