#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdbool.h>
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

static void test_can_master_check_timeout_none(void **state) {
    CAN_Data data;
    struct timespec timestamp = {10, 0};
    int i;
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_data(&data);
    
    /* Setup CAN metadata, all check_timeouts are false */
    for (i = 0; i < NUM_CAN_RESPONSES; i++) {
        data.responses[i].timeout_interval.tv_sec = 0;
        data.responses[i].timeout_interval.tv_nsec = 0;
    }
    for (i = 0; i < NUM_CAN_REQUESTS; i++) {
        data.requests[i].state = WAITING;
        data.requests[i].timeout_interval.tv_sec = 0;
        data.requests[i].timeout_interval.tv_nsec = 0;
    }
    
    /* Pre-Conditions */
    for (i = 0; i < NUM_CAN_RESPONSES; i++) {
        assert_true(data.responses[i].rx_count == 0);
        assert_false(data.responses[i].check_timeout);
        assert_true(data.responses[i].last_time.tv_sec == 0);
        assert_true(data.responses[i].last_time.tv_nsec == 0);
        assert_true(data.responses[i].timeout_interval.tv_sec == 0);
        assert_true(data.responses[i].timeout_interval.tv_nsec == 0);
    }
    for (i = 0; i < NUM_CAN_REQUESTS; i++) {
        assert_true(data.requests[i].state == WAITING);
        assert_true(data.requests[i].tx_count == 0);
        assert_false(data.requests[i].check_timeout);
        assert_true(data.requests[i].timeout_count == 0);
        assert_true(data.requests[i].sent_time.tv_sec == 0);
        assert_true(data.requests[i].sent_time.tv_nsec == 0);
        assert_true(data.requests[i].timeout_interval.tv_sec == 0);
        assert_true(data.requests[i].timeout_interval.tv_nsec == 0);
    }
    g_abort_run = 0;
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    check_timeouts(&data, &timestamp);
    
    /* Post-Conditions */
    assert_false(g_abort_run);
    
    for (i = 0; i < NUM_CAN_RESPONSES; i++) {
        assert_true(data.responses[i].rx_count == 0);
        assert_false(data.responses[i].check_timeout);
        assert_true(data.responses[i].last_time.tv_sec == 0);
        assert_true(data.responses[i].last_time.tv_nsec == 0);
        assert_true(data.responses[i].timeout_interval.tv_sec == 0);
        assert_true(data.responses[i].timeout_interval.tv_nsec == 0);
    }
    for (i = 0; i < NUM_CAN_REQUESTS; i++) {
        assert_true(data.requests[i].state == WAITING);
        assert_true(data.requests[i].tx_count == 0);
        assert_false(data.requests[i].check_timeout);
        assert_true(data.requests[i].timeout_count == 0);
        assert_true(data.requests[i].sent_time.tv_sec == 0);
        assert_true(data.requests[i].sent_time.tv_nsec == 0);
        assert_true(data.requests[i].timeout_interval.tv_sec == 0);
        assert_true(data.requests[i].timeout_interval.tv_nsec == 0);
    }
}

static void test_can_master_check_timeout_all(void **state) {
    CAN_Data data;
    struct timespec timestamp = {10, 0};
    int i;
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_data(&data);
    
    /* Setup CAN metadata, all check_timeouts are true */
    for (i = 0; i < NUM_CAN_RESPONSES; i++) {
        data.responses[i].check_timeout = true;
        data.responses[i].timeout_interval.tv_sec = 0;
        data.responses[i].timeout_interval.tv_nsec = 10000000;
    }
    for (i = 0; i < NUM_CAN_REQUESTS; i++) {
        data.requests[i].state = WAITING;
        data.requests[i].check_timeout = true;
        data.requests[i].timeout_interval.tv_sec = 2;
        data.requests[i].timeout_interval.tv_nsec = 0;
    }
    
    /* Pre-Conditions */
    for (i = 0; i < NUM_CAN_RESPONSES; i++) {
        assert_true(data.responses[i].rx_count == 0);
        assert_true(data.responses[i].check_timeout);
        assert_true(data.responses[i].last_time.tv_sec == 0);
        assert_true(data.responses[i].last_time.tv_nsec == 0);
        assert_true(data.responses[i].timeout_interval.tv_sec == 0);
        assert_true(data.responses[i].timeout_interval.tv_nsec == 10000000);
    }
    for (i = 0; i < NUM_CAN_REQUESTS; i++) {
        assert_true(data.requests[i].state == WAITING);
        assert_true(data.requests[i].tx_count == 0);
        assert_true(data.requests[i].check_timeout);
        assert_true(data.requests[i].timeout_count == 0);
        assert_true(data.requests[i].sent_time.tv_sec == 0);
        assert_true(data.requests[i].sent_time.tv_nsec == 0);
        assert_true(data.requests[i].timeout_interval.tv_sec == 2);
        assert_true(data.requests[i].timeout_interval.tv_nsec == 0);
    }
    g_abort_run = 0;
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    check_timeouts(&data, &timestamp);
    
    /* Post-Conditions */
    assert_true(g_abort_run);
    
    for (i = 0; i < NUM_CAN_RESPONSES; i++) {
        assert_true(data.responses[i].rx_count == 0);
        assert_true(data.responses[i].check_timeout);
        assert_true(data.responses[i].last_time.tv_sec == 0);
        assert_true(data.responses[i].last_time.tv_nsec == 0);
        assert_true(data.responses[i].timeout_interval.tv_sec == 0);
        assert_true(data.responses[i].timeout_interval.tv_nsec == 10000000);
    }
    for (i = 0; i < NUM_CAN_REQUESTS; i++) {
        assert_true(data.requests[i].state == TIMEOUT);
        assert_true(data.requests[i].tx_count == 0);
        assert_true(data.requests[i].check_timeout);
        assert_true(data.requests[i].timeout_count == 1);
        assert_true(data.requests[i].sent_time.tv_sec == 0);
        assert_true(data.requests[i].sent_time.tv_nsec == 0);
        assert_true(data.requests[i].timeout_interval.tv_sec == 2);
        assert_true(data.requests[i].timeout_interval.tv_nsec == 0);
    }
}

static void test_can_master_check_timeout_request_idle_state(void **state) {
    CAN_Data data;
    struct timespec timestamp = {10, 0};
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_data(&data);
    g_abort_run = 0;
    
    /*** Test timeout NOT triggered for IDLE state ***/
    data.requests[0].state = IDLE;
    data.requests[0].check_timeout = true;
    data.requests[0].timeout_interval.tv_sec = 2;
    data.requests[0].timeout_interval.tv_nsec = 0;
    
    /* Pre-Conditions */
    assert_true(data.requests[0].state == IDLE);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    check_timeouts(&data, &timestamp);
    
    /* Post-Conditions */
    assert_true(data.requests[0].state == IDLE);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
}

static void test_can_master_check_timeout_request_send_state(void **state) {
    CAN_Data data;
    struct timespec timestamp = {10, 0};
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_data(&data);
    g_abort_run = 0;
    
    /*** Test timeout NOT triggered for SEND state ***/
    data.requests[0].state = SEND;
    data.requests[0].check_timeout = true;
    data.requests[0].timeout_interval.tv_sec = 2;
    data.requests[0].timeout_interval.tv_nsec = 0;
    
    /* Pre-Conditions */
    assert_true(data.requests[0].state == SEND);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    check_timeouts(&data, &timestamp);
    
    /* Post-Conditions */
    assert_true(data.requests[0].state == SEND);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
}

static void test_can_master_check_timeout_request_timeout_state(void **state) {
    CAN_Data data;
    struct timespec timestamp = {10, 0};
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_data(&data);
    g_abort_run = 0;
    
    /*** Test timeout NOT triggered for TIMEOUT state ***/
    data.requests[0].state = TIMEOUT;
    data.requests[0].check_timeout = true;
    data.requests[0].timeout_interval.tv_sec = 2;
    data.requests[0].timeout_interval.tv_nsec = 0;
    
    /* Pre-Conditions */
    assert_true(data.requests[0].state == TIMEOUT);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    check_timeouts(&data, &timestamp);
    
    /* Post-Conditions */
    assert_true(data.requests[0].state == TIMEOUT);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
}

static void test_can_master_check_timeout_request_complete_state(void **state) {
    CAN_Data data;
    struct timespec timestamp = {10, 0};
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_data(&data);
    g_abort_run = 0;
    
    /*** Test timeout NOT triggered for COMPLETE state ***/
    data.requests[0].state = COMPLETE;
    data.requests[0].check_timeout = true;
    data.requests[0].timeout_interval.tv_sec = 2;
    data.requests[0].timeout_interval.tv_nsec = 0;
    
    /* Pre-Conditions */
    assert_true(data.requests[0].state == COMPLETE);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    check_timeouts(&data, &timestamp);
    
    /* Post-Conditions */
    assert_true(data.requests[0].state == COMPLETE);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
}

static void test_can_master_check_timeout_request_waiting_state(void **state) {
    CAN_Data data;
    struct timespec timestamp = {10, 0};
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_data(&data);
    g_abort_run = 0;
    
    /*** Test timeout IS triggered for WAITING state ***/
    data.requests[0].state = WAITING;
    data.requests[0].check_timeout = true;
    data.requests[0].timeout_interval.tv_sec = 2;
    data.requests[0].timeout_interval.tv_nsec = 0;
    
    /* Pre-Conditions */
    assert_true(data.requests[0].state == WAITING);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    check_timeouts(&data, &timestamp);
    
    /* Post-Conditions */
    assert_true(data.requests[0].state == TIMEOUT);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 1);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
}

static void test_can_master_check_timeout_request(void **state) {
    CAN_Data data;
    struct timespec timestamp = {1, 0};
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_data(&data);
    g_abort_run = 0;
    
    /*** Test timeout is not triggered ***/
    data.requests[0].state = WAITING;
    data.requests[0].check_timeout = true;
    data.requests[0].timeout_interval.tv_sec = 2;
    data.requests[0].timeout_interval.tv_nsec = 0;
    
    /* Pre-Conditions */
    assert_true(data.requests[0].state == WAITING);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    check_timeouts(&data, &timestamp);
    
    /* Post-Conditions */
    assert_true(data.requests[0].state == WAITING);
    assert_true(data.requests[0].tx_count == 0);
    assert_true(data.requests[0].check_timeout);
    assert_true(data.requests[0].timeout_count == 0);
    assert_true(data.requests[0].sent_time.tv_sec == 0);
    assert_true(data.requests[0].sent_time.tv_nsec == 0);
    assert_true(data.requests[0].timeout_interval.tv_sec == 2);
    assert_true(data.requests[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
}

static void test_can_master_check_timeout_response(void **state) {
    CAN_Data data;
    struct timespec timestamp = {10, 0};
    
    UNUSED(state);
    
    /* Init CAN_Data */
    init_can_data(&data);
    g_abort_run = 0;
    
    /*** Test no timeout does not trigger ABORT_RUN ***/
    data.responses[0].check_timeout = true;
    data.responses[0].last_time.tv_sec = 0;
    data.responses[0].last_time.tv_nsec = 0;
    data.responses[0].timeout_interval.tv_sec = 15;
    data.responses[0].timeout_interval.tv_nsec = 0;
    
    /* Pre-Conditions */
    assert_true(data.responses[0].check_timeout);
    assert_true(data.responses[0].rx_count == 0);
    assert_true(data.responses[0].last_time.tv_sec == 0);
    assert_true(data.responses[0].last_time.tv_nsec == 0);
    assert_true(data.responses[0].timeout_interval.tv_sec == 15);
    assert_true(data.responses[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
    
    /* Call function to be tested */
    check_timeouts(&data, &timestamp);
    
    /* Post-Conditions */
    assert_true(data.responses[0].check_timeout);
    assert_true(data.responses[0].rx_count == 0);
    assert_true(data.responses[0].last_time.tv_sec == 0);
    assert_true(data.responses[0].last_time.tv_nsec == 0);
    assert_true(data.responses[0].timeout_interval.tv_sec == 15);
    assert_true(data.responses[0].timeout_interval.tv_nsec == 0);
    assert_false(g_abort_run);
}

/******************************************************************************/
/***    RUN TESTS                                                           ***/
/******************************************************************************/

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_can_master_check_timeout_none),
        cmocka_unit_test(test_can_master_check_timeout_all),
        cmocka_unit_test(test_can_master_check_timeout_request_idle_state),
        cmocka_unit_test(test_can_master_check_timeout_request_send_state),
        cmocka_unit_test(test_can_master_check_timeout_request_timeout_state),
        cmocka_unit_test(test_can_master_check_timeout_request_complete_state),
        cmocka_unit_test(test_can_master_check_timeout_request_waiting_state),
        cmocka_unit_test(test_can_master_check_timeout_request),
        cmocka_unit_test(test_can_master_check_timeout_response),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
