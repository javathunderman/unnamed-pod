#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include <time.h>
#include "can_master.h"
#include "can_init.h"
#include "vs_can_api.h"

#define UNIT_TESTING 1
#include "can_master.c"

#define UNUSED(x) (void)(x)


VSCAN_STATUS __wrap_VSCAN_Flush(VSCAN_HANDLE Handle);
VSCAN_STATUS __wrap_VSCAN_Write(VSCAN_HANDLE Handle, VSCAN_MSG *Buf, DWORD Size, DWORD *Written);
VSCAN_STATUS __wrap_VSCAN_Read(VSCAN_HANDLE Handle, VSCAN_MSG *Buf, DWORD Size, DWORD *Read);

static void normal_read(void);
static void normal_write(void);
static void normal_flush(void);
static void send_message(CAN_Request_Index index, CAN_Request *copy);
static void verify_sent(CAN_Request_Index index, CAN_Request *before, struct timespec *time);
static void verify_not_sent(CAN_Request_Index index, CAN_Request *before);
static void copy_req(CAN_Request_Index index, CAN_Request *copy);

/* Global test variables */
CAN_Data test_data;
VSCAN_MSG test_buffer[CAN_BUF_LEN];


static void test_cycle_read_error(void **state) {
    /* Set current time {sec, nsec} */
    struct timespec now = {5, 0};
    
    /* Set return values */
    will_return(__wrap_VSCAN_Read, 0);
    will_return(__wrap_VSCAN_Read, VSCAN_ERR_ERR);
    
    /* Pre-Conditions */
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    can_cycle(&test_data, test_buffer, &now);
    
    /* Post-Conditions */
    assert_true(g_abort_run);
}

static void test_cycle_write_error(void **state) {
    CAN_Request copy;
    
    /* Set current time {sec, nsec} */
    struct timespec now = {5, 0};
    
    /* Set return values */
    normal_read();
    will_return(__wrap_VSCAN_Write, 1);
    will_return(__wrap_VSCAN_Write, VSCAN_ERR_ERR);
    
    /* Pre-Conditions */
    send_message(ISO_STATE_TX, &copy);
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    can_cycle(&test_data, test_buffer, &now);
    
    /* Post-Conditions */
    assert_true(g_abort_run);
    verify_not_sent(ISO_STATE_TX, &copy);
}

static void test_cycle_flush_error(void **state) {
    CAN_Request copy;
    
    /* Set current time {sec, nsec} */
    struct timespec now = {5, 0};
    
    /* Set return values */
    normal_read();
    normal_write();
    will_return(__wrap_VSCAN_Flush, VSCAN_ERR_ERR);
    
    /* Pre-Conditions */
    send_message(ISO_STATE_TX, &copy);
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    can_cycle(&test_data, test_buffer, &now);
    
    /* Post-Conditions */
    assert_true(g_abort_run);
    verify_sent(ISO_STATE_TX, &copy, &now);
}

/* Test setup function */
static int setup_test(void **state) {
    init_can_requests();
    init_can_responses();
    init_can_data(&test_data);
    g_abort_run= 0;
    
    return 0;
}

static void normal_read(void) {
    will_return(__wrap_VSCAN_Read, 0);
    will_return(__wrap_VSCAN_Read, VSCAN_ERR_OK);
}

static void normal_write(void) {
    will_return(__wrap_VSCAN_Write, 1);
    will_return(__wrap_VSCAN_Write, VSCAN_ERR_OK);
}

static void normal_flush(void) {
    will_return(__wrap_VSCAN_Flush, VSCAN_ERR_OK);
}

static void send_message(CAN_Request_Index index, CAN_Request *copy) {
    STORE(test_data.requests[index].state, SEND);
    copy_req(index, copy);
}

static void verify_sent(CAN_Request_Index index, CAN_Request *before, struct timespec *time) {
    assert_true(LOAD(test_data.requests[index].state) == WAITING);
    assert_true(LOAD(test_data.requests[index].tx_count) == before->tx_count + 1);
    assert_true(LOAD(test_data.requests[index].check_timeout) == before->check_timeout);
    assert_true(LOAD(test_data.requests[index].timeout_count) == before->timeout_count);
    assert_true(LOAD(test_data.requests[index].timeout_interval.tv_sec) == before->timeout_interval.tv_sec);
    assert_true(LOAD(test_data.requests[index].timeout_interval.tv_nsec) == before->timeout_interval.tv_nsec);
    assert_true(LOAD(test_data.requests[index].sent_time.tv_sec) == time->tv_sec);
    assert_true(LOAD(test_data.requests[index].sent_time.tv_nsec) == time->tv_nsec);
}

static void verify_not_sent(CAN_Request_Index index, CAN_Request *before) {
    assert_true(LOAD(test_data.requests[index].state) == before->state);
    assert_true(LOAD(test_data.requests[index].tx_count) == before->tx_count);
    assert_true(LOAD(test_data.requests[index].check_timeout) == before->check_timeout);
    assert_true(LOAD(test_data.requests[index].timeout_count) == before->timeout_count);
    assert_true(LOAD(test_data.requests[index].timeout_interval.tv_sec) == before->timeout_interval.tv_sec);
    assert_true(LOAD(test_data.requests[index].timeout_interval.tv_nsec) == before->timeout_interval.tv_nsec);
    assert_true(LOAD(test_data.requests[index].sent_time.tv_sec) == before->sent_time.tv_sec);
    assert_true(LOAD(test_data.requests[index].sent_time.tv_nsec) == before->sent_time.tv_nsec);
}

static void copy_req(CAN_Request_Index index, CAN_Request *copy) {
    copy->state = LOAD(test_data.requests[index].state);
    copy->tx_count = LOAD(test_data.requests[index].tx_count);
    copy->check_timeout = LOAD(test_data.requests[index].check_timeout);
    copy->timeout_count = LOAD(test_data.requests[index].timeout_count);
    copy->timeout_interval.tv_sec = LOAD(test_data.requests[index].timeout_interval.tv_sec);
    copy->timeout_interval.tv_nsec = LOAD(test_data.requests[index].timeout_interval.tv_nsec);
    copy->sent_time.tv_sec = LOAD(test_data.requests[index].sent_time.tv_sec);
    copy->sent_time.tv_nsec = LOAD(test_data.requests[index].sent_time.tv_nsec);
}

/******************************************************************************/
/***    MOCK VSCAN API                                                      ***/
/******************************************************************************/

VSCAN_STATUS __wrap_VSCAN_Flush(VSCAN_HANDLE Handle) {
    return mock();
}

VSCAN_STATUS __wrap_VSCAN_Write(VSCAN_HANDLE Handle, VSCAN_MSG *Buf, DWORD Size, DWORD *Written) {
    *Written = mock();
    return mock();
}

VSCAN_STATUS __wrap_VSCAN_Read(VSCAN_HANDLE Handle, VSCAN_MSG *Buf, DWORD Size, DWORD *Read) {
    *Read = mock();
    return mock();
}

/******************************************************************************/
/***    RUN TESTS                                                           ***/
/******************************************************************************/

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup(test_cycle_read_error, setup_test),
        cmocka_unit_test_setup(test_cycle_write_error, setup_test),
        cmocka_unit_test_setup(test_cycle_flush_error, setup_test),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
