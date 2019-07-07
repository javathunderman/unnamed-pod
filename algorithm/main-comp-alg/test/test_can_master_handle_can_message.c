#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

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
    can_init(&data);
    
    /* Setup unkown msg */
    msg.Flags = VSCAN_FLAGS_STANDARD;
    msg.Id = 0x00;
    msg.Size = 0;
    
    handle_can_message(&data, &msg, &timestamp);
    assert_true(check_match(&msg1, &msg2));
}

/******************************************************************************/
/***    MOCK VSCAN API                                                      ***/
/******************************************************************************/

VSCAN_HANDLE __wrap_VSCAN_Open(CHAR *SerialNrORComPortORNet, DWORD Mode) {
    /* Not mocked for these tests */
    return VSCAN_ERR_OK;
}

VSCAN_STATUS __wrap_VSCAN_Ioctl(VSCAN_HANDLE Handle, DWORD Ioctl, VOID *Param) {
    /* Not mocked for these tests */
    return VSCAN_ERR_OK;
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_can_master_handle_can_message_unknown),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
