#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include <time.h>
#include "can_master.h"
#include "vs_can_api.h"

#define UNIT_TESTING 1
#include "can_master.c"

#define UNUSED(x) (void)(x)


static void test_no_timeout(void **state) {
    struct timespec start, stop, timeout;
    
    UNUSED(state);
    
    /*** Test no timeout ***/
    start.tv_sec    = 0;
    start.tv_nsec   = 0;
    stop.tv_sec     = 1;
    stop.tv_nsec    = 0;
    timeout.tv_sec  = 2;
    timeout.tv_nsec = 0;
    
    assert_false(timeout_overrun(&start, &stop, &timeout));
}

static void test_no_timeout_rollover(void **state) {
    struct timespec start, stop, timeout;
    
    UNUSED(state);
    
    /*** Test no timeout ***/
    start.tv_sec    = 0;
    start.tv_nsec   = 500000000;
    stop.tv_sec     = 3;
    stop.tv_nsec    = 400000000;
    timeout.tv_sec  = 2;
    timeout.tv_nsec = 950000000;
    
    assert_false(timeout_overrun(&start, &stop, &timeout));
}

static void test_timeout(void **state) {
    struct timespec start, stop, timeout;
    
    UNUSED(state);
    
    /*** Test for timeout ***/
    start.tv_sec    = 1;
    start.tv_nsec   = 0;
    stop.tv_sec     = 3;
    stop.tv_nsec    = 500000000;
    timeout.tv_sec  = 2;
    timeout.tv_nsec = 0;
    
    assert_true(timeout_overrun(&start, &stop, &timeout));
}

static void test_timeout_rollover(void **state) {
    struct timespec start, stop, timeout;
    
    UNUSED(state);
    
    /*** Test for timeout ***/
    start.tv_sec    = 0;
    start.tv_nsec   = 500000000;
    stop.tv_sec     = 3;
    stop.tv_nsec    = 400000000;
    timeout.tv_sec  = 2;
    timeout.tv_nsec = 800000000;
    
    assert_true(timeout_overrun(&start, &stop, &timeout));
}

/******************************************************************************/
/***    RUN TESTS                                                           ***/
/******************************************************************************/

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_no_timeout),
        cmocka_unit_test(test_no_timeout_rollover),
        cmocka_unit_test(test_timeout),
        cmocka_unit_test(test_timeout_rollover),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}
