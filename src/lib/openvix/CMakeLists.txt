add_library(openvix SHARED
    openvix/openvix.c  openvix/openvix.h
<<<<<<< 28814525bb674016a5fa6ec712e4a8c30f823630
=======
    openvix/host.c

    vm_basic_types.h
    vix.h
>>>>>>> initial commit
    )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(openvix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

