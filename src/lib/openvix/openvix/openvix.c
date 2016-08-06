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
<<<<<<< 28814525bb674016a5fa6ec712e4a8c30f823630

OPENVIXAPI
int 
openvix_sum
(
    int value1, 
    int value2
)
{
    int result = value1 + value2;
    printf("The result is: %d\n", result);

    return result;
}
=======
>>>>>>> initial commit
