#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "can_master.h"
#include "vs_can_api.h"

#define UNIT_TESTING 1
#include "can_handlers.c"

#define UNUSED(x) (void)(x)


static void test_bms_pack_handler(void **state) {
    CAN_Data data;
    VSCAN_MSG msg;
    
    UNUSED(state);
    
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
    
    bms_pack_handler(&msg, &data);
    
    assert_true(data.pack_soc == 94);
    assert_true(data.pack_voltage == 6245);
    assert_true(data.pack_current == 1987);
}

static void test_bms_other_handler(void **state) {
    CAN_Data data;
    VSCAN_MSG msg;
    
    UNUSED(state);
    
    msg.Flags = VSCAN_FLAGS_STANDARD;
    msg.Id = 0x302;
    msg.Size = 8;
    /* 32105 10E-4 V */
    msg.Data[0] = 0x69;
    msg.Data[1] = 0x7D;
    
    /* 38941 10E-4 V */
    msg.Data[2] = 0x1D;
    msg.Data[3] = 0x98;
    
    /* 35 C */
    msg.Data[4] = 0x23;
    msg.Data[5] = 0x00;
    
    /* 39 C */
    msg.Data[6] = 0x27;
    msg.Data[7] = 0x00;
    
    bms_other_handler(&msg, &data);
    
    assert_true(data.min_voltage == 32105);
    assert_true(data.max_voltage == 38941);
    assert_true(data.avg_temp == 35);
    assert_true(data.high_temp == 39);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_bms_pack_handler),
        cmocka_unit_test(test_bms_other_handler),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
