#include "openvixtest.h"

#include <windows.h>
#include <stdio.h>
<<<<<<< 28814525bb674016a5fa6ec712e4a8c30f823630
=======
#include <vix.h>
>>>>>>> initial commit

#include <openvix/openvix.h>

int main(int argc, char* argv[])
{
    int result = 0;
<<<<<<< 28814525bb674016a5fa6ec712e4a8c30f823630
    printf("Hello World!\n");

    result = openvix_sum(5, 6);
    if (result == 11)
    {
        printf("openvix_sum() SUCCESS\n");
    }
    else
    {
        printf("openvix_sum() FAIL\n");
    }
=======
    VixHandle hostHandle = VIX_INVALID_HANDLE;
    VixHandle jobHandle = VIX_INVALID_HANDLE;

    printf("Test Vix!\n");

    jobHandle = VixHost_Connect(VIX_API_VERSION, VIX_SERVICEPROVIDER_VMWARE_WORKSTATION, NULL, 0, NULL, NULL, 0, VIX_INVALID_HANDLE, NULL, NULL);
    printf("JOB Handle: %d\n", jobHandle);
>>>>>>> initial commit

    return EXIT_SUCCESS;
}
