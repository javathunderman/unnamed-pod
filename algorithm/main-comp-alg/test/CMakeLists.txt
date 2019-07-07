set(ALG_PATH "/mnt/c/Users/Ryan/GitHub/cmocka-1.1.5/umdloop/main-comp-alg")
set(INCLUDE_FLAGS "${DEFAULT_C_COMPILE_FLAGS};-I${ALG_PATH}/include;-I${ALG_PATH}/src;-I${ALG_PATH}/src/can;-I${ALG_PATH}/src/comm;-I${ALG_PATH}/src/states")

add_cmocka_test(test_handlers
                SOURCES test_can_handlers.c
                COMPILE_OPTIONS ${INCLUDE_FLAGS}
                LINK_LIBRARIES ${CMOCKA_SHARED_LIBRARY})

add_cmocka_test(test_can_master_check_match
                SOURCES test_can_master_check_match.c
                COMPILE_OPTIONS ${INCLUDE_FLAGS}
                LINK_LIBRARIES ${CMOCKA_SHARED_LIBRARY})
set_property(TARGET
                 test_can_master_check_match
             PROPERTY
                 LINK_FLAGS
                    "${DEFAULT_LINK_FLAGS} -Wl,--wrap=VSCAN_Read,--wrap=VSCAN_Write,--wrap=VSCAN_Flush")
