#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "abort_run.h"
#include "can_master.h"
#include "can_init.h"
#include "vs_can_api.h"

#define UNIT_TESTING 1
#include "can_master.c"

#define UNUSED(x) (void)(x)


/******************************************************************************/
/***    TEST CASES                                                          ***/
/******************************************************************************/

static void test_can_master_handle_can_message_unknown(void **state) {
    CAN_Data data;
    VSCAN_MSG msg;
    struct timespec timestamp = {0, 0};
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_requests();
    init_can_responses();
    init_can_data(&data);
    
    /* Setup unkown msg */
    msg.Flags = VSCAN_FLAGS_STANDARD;
    msg.Id = 0x00;
    msg.Size = 0;
    
    g_abort_run = 0;
    assert_false(g_abort_run);
    
    handle_can_message(&data, &msg, &timestamp);
    
    assert_true(g_abort_run);
    
    /* Setup unkown msg */
    msg.Flags = VSCAN_FLAGS_STANDARD;
    msg.Id = 0x77;
    msg.Size = 2;
    msg.Data[0] = 0x02;
    msg.Data[1] = 0x30;
    
    g_abort_run = 0;
    assert_false(g_abort_run);
    
    handle_can_message(&data, &msg, &timestamp);
    
    assert_true(g_abort_run);
    g_abort_run = 0;
}

static void test_can_master_handle_can_message_metadata(void **state) {
    CAN_Data data;
    VSCAN_MSG msg;
    struct timespec timestamp = {123L, 456L};
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_requests();
    init_can_responses();
    init_can_data(&data);
    
    /* Setup BMS_PACK_RX message */
    msg.Flags = VSCAN_FLAGS_STANDARD;
    msg.Id = 0x301;
    msg.Size = 6;
    /* 94 percent */
    msg.Data[0] = 0x5E;
    msg.Data[1] = 0x00;
    /* 6245 mV */
    msg.Data[2] = 0x65;
    msg.Data[3] = 0x18;
    /* 1987 mA */
    msg.Data[4] = 0xC3;
    msg.Data[5] = 0x07;
    
    /* First handle */
    g_abort_run = 0;
    assert_false(g_abort_run);
    assert_true(data.responses[BMS_PACK_RX].rx_count == 0);
    
    handle_can_message(&data, &msg, &timestamp);
    
    assert_true(data.responses[BMS_PACK_RX].rx_count == 1);
    assert_true(data.responses[BMS_PACK_RX].last_time.tv_sec == 123L);
    assert_true(data.responses[BMS_PACK_RX].last_time.tv_nsec == 456L);
    assert_false(g_abort_run);
    
    /* Second handle */
    timestamp.tv_sec = 987L;
    timestamp.tv_nsec = 654L;
    
    handle_can_message(&data, &msg, &timestamp);
    
    assert_true(data.responses[BMS_PACK_RX].rx_count == 2);
    assert_true(data.responses[BMS_PACK_RX].last_time.tv_sec == 987L);
    assert_true(data.responses[BMS_PACK_RX].last_time.tv_nsec == 654L);
    assert_false(g_abort_run);
}

/******************************************************************************/
/***    RUN TESTS                                                           ***/
/******************************************************************************/

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_can_master_handle_can_message_unknown),
        cmocka_unit_test(test_can_master_handle_can_message_metadata),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
