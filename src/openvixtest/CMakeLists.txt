add_executable(openvixtest
    openvixtest/openvixtest.c    openvixtest/openvixtest.h
    )

target_link_libraries(openvixtest LINK_PUBLIC openvix)
