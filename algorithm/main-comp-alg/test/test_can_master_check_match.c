#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "can_master.h"
#include "vs_can_api.h"

#define UNIT_TESTING 1
#include "can_master.c"

#define UNUSED(x) (void)(x)


/******************************************************************************/
/***    TEST CASES                                                          ***/
/******************************************************************************/

static void test_check_match_empty(void **state) {
    VSCAN_MSG msg1, msg2;
    
    UNUSED(state);
    
    /* Setup msg1 */
    msg1.Flags = VSCAN_FLAGS_STANDARD;
    msg1.Id = 0x00;
    msg1.Size = 0;
    
    /* Setup msg2 */
    msg2.Flags = VSCAN_FLAGS_STANDARD;
    msg2.Id = 0x00;
    msg2.Size = 0;
    
    assert_true(check_match(&msg1, &msg2));
}

static void test_check_match_flags(void **state) {
    VSCAN_MSG msg1, msg2;
    
    UNUSED(state);
    
    /* Setup msg1 */
    msg1.Flags = VSCAN_FLAGS_STANDARD;
    msg1.Id = 0x00;
    msg1.Size = 0;
    
    /* Setup msg2 */
    msg2.Flags = VSCAN_FLAGS_EXTENDED;
    msg2.Id = 0x00;
    msg2.Size = 0;
    
    assert_false(check_match(&msg1, &msg2));
}

static void test_check_match_id(void **state) {
    VSCAN_MSG msg1, msg2;
    
    UNUSED(state);
    
    /* Setup msg1 */
    msg1.Flags = VSCAN_FLAGS_STANDARD;
    msg1.Id = 0x00;
    msg1.Size = 0;
    
    /* Setup msg2 */
    msg2.Flags = VSCAN_FLAGS_STANDARD;
    msg2.Id = 0x07;
    msg2.Size = 0;
    
    assert_false(check_match(&msg1, &msg2));
}

static void test_check_match_data1(void **state) {
    VSCAN_MSG msg1, msg2;
    
    UNUSED(state);
    
    /* Setup msg1 */
    msg1.Flags = VSCAN_FLAGS_EXTENDED;
    msg1.Id = 0x03;
    msg1.Size = 2;
    msg1.Data[0] = 0xF0;
    msg1.Data[1] = 0x0F;
    
    /* Setup msg2 */
    msg2.Flags = VSCAN_FLAGS_EXTENDED;
    msg2.Id = 0x03;
    msg2.Size = 2;
    msg2.Data[0] = 0xF0;
    msg2.Data[1] = 0x0F;
    
    assert_true(check_match(&msg1, &msg2));
}

static void test_check_match_data2(void **state) {
    VSCAN_MSG msg1, msg2;
    
    UNUSED(state);
    
    /* Setup msg1 */
    msg1.Flags = VSCAN_FLAGS_STANDARD;
    msg1.Id = 0x12;
    msg1.Size = 3;
    msg1.Data[0] = 0xF0;
    msg1.Data[1] = 0x0F;
    msg1.Data[2] = 0xFF;
    
    /* Setup msg2 */
    msg2.Flags = VSCAN_FLAGS_STANDARD;
    msg2.Id = 0x12;
    msg2.Size = 3;
    msg2.Data[0] = 0xF0;
    msg2.Data[1] = 0x0F;
    msg2.Data[2] = 0x00;
    
    assert_false(check_match(&msg1, &msg2));
}

static void test_check_match_data3(void **state) {
    VSCAN_MSG msg1, msg2;
    
    UNUSED(state);
    
    /* Setup msg1 */
    msg1.Flags = VSCAN_FLAGS_STANDARD;
    msg1.Id = 0x12;
    msg1.Size = 3;
    msg1.Data[0] = 0xF0;
    msg1.Data[1] = 0x0F;
    msg1.Data[2] = 0xFF;
    
    /* Setup msg2 */
    msg2.Flags = VSCAN_FLAGS_STANDARD;
    msg2.Id = 0x12;
    msg2.Size = 5;
    msg2.Data[0] = 0xF0;
    msg2.Data[1] = 0x0F;
    msg2.Data[2] = 0xFF;
    msg2.Data[3] = 0x12;
    msg2.Data[4] = 0x34;
    
    assert_true(check_match(&msg1, &msg2));
}

/******************************************************************************/
/***    MOCK VSCAN API                                                      ***/
/******************************************************************************/

VSCAN_STATUS __wrap_VSCAN_Read(VSCAN_HANDLE Handle, VSCAN_MSG *Buf, DWORD Size, DWORD *Read) {
    /* Not used during these tests */
    return VSCAN_ERR_OK;
}

VSCAN_STATUS __wrap_VSCAN_Write(VSCAN_HANDLE Handle, VSCAN_MSG *Buf, DWORD Size, DWORD *Written) {
    /* Not used during these tests */
    return VSCAN_ERR_OK;
}

VSCAN_STATUS VSCAN_Flush(VSCAN_HANDLE Handle) {
    /* Not used during these tests */
    return VSCAN_ERR_OK;
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_check_match_empty),
        cmocka_unit_test(test_check_match_flags),
        cmocka_unit_test(test_check_match_id),
        cmocka_unit_test(test_check_match_data1),
        cmocka_unit_test(test_check_match_data2),
        cmocka_unit_test(test_check_match_data3),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
