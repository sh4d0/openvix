#include <openvix/openvix.h>

#include <Windows.h>
#include <stdio.h>

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved)  // reserved
{
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

