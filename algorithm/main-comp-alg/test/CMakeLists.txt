set(ALG_PATH "/mnt/c/Users/Ryan/GitHub/cmocka-1.1.5/umdloop/main-comp-alg")
set(INCLUDE_FLAGS "${DEFAULT_C_COMPILE_FLAGS};-I${ALG_PATH}/include;-I${ALG_PATH}/src;-I${ALG_PATH}/src/can;-I${ALG_PATH}/src/comm;-I${ALG_PATH}/src/states")
set(VSCAN_LIB "${ALG_PATH}/include/libvs_can_api_x86-64.so")

add_cmocka_test(test_handlers
                SOURCES test_can_handlers.c
                COMPILE_OPTIONS ${INCLUDE_FLAGS}
                LINK_LIBRARIES ${CMOCKA_SHARED_LIBRARY})

add_cmocka_test(test_can_master_check_match
                SOURCES test_can_master_check_match.c
                COMPILE_OPTIONS ${INCLUDE_FLAGS}
                LINK_LIBRARIES ${CMOCKA_SHARED_LIBRARY} ${VSCAN_LIB})

add_cmocka_test(test_can_master_handle_can_message
                SOURCES test_can_master_handle_can_message.c
                COMPILE_OPTIONS ${INCLUDE_FLAGS}
                LINK_LIBRARIES ${CMOCKA_SHARED_LIBRARY} "-Wl,--wrap=VSCAN_Open,--wrap=VSCAN_Ioctl")
