add_library(openvix SHARED
    openvix/openvix.c  openvix/openvix.h

    vix.h
    )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(openvix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

