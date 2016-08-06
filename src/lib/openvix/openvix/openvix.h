#pragma once
#ifndef HELLOLIB_H
#define HELLOLIB_H

#ifdef openvix_EXPORTS
#define OPENVIXAPI __declspec(dllexport)
#else
#define OPENVIXAPI __declspec(dllimport)
#endif

<<<<<<< 28814525bb674016a5fa6ec712e4a8c30f823630
OPENVIXAPI
int
openvix_sum
(
    int value1,
    int value2
);

=======
>>>>>>> initial commit
#endif
