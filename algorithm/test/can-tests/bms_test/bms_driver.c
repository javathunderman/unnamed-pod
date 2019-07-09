#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "can_init.h"
#include "can_master.h"


#define CAN_FREQ 1000000L /* 1 kHz */
#define NS_IN_SEC 1000000000L
#define UPDATE_DELAY(name) name.tv_sec = name.tv_sec + ((name.tv_nsec + CAN_FREQ) / NS_IN_SEC);\
                           name.tv_nsec = (name.tv_nsec + CAN_FREQ) % NS_IN_SEC;
#define INIT_TIMES(name, time) sec = name.tv_sec + ((name.tv_nsec + time) / NS_IN_SEC);\
                               nsec = (name.tv_nsec + time) % NS_IN_SEC;


int g_abort_run = 0;

static void run_test(CAN_Data *data);
static unsigned int check_message(CAN_Data *data, CAN_Response_Index index, unsigned int prev);
static void dump_can_data(CAN_Data *data);

/* Test receiving BMS CAN messages
 */
int main(void) {
    CAN_Data data;
    
    printf("STARTING TEST\n");
    
    if (can_init(&data) != 0) {
        printf("EXITING TEST\n");
    } else {
        printf("INFINITE LOOPING\n");
        run_test(&data);
        printf("EXITING TEST\n");
    }
    
    return 0;
}

void run_test(CAN_Data *data) {
    unsigned int pack_count = 0, other_count = 0, error_count = 0;
    
    /* Initialize loop timing */
    struct timespec now;
    if(clock_gettime(CLOCK_MONOTONIC, &now) == -1) {
        printf("driver clock_gettime() error: %s\n", strerror(errno));
        return;
    }
    time_t sec = now.tv_sec;
    long nsec = now.tv_nsec;

    INIT_TIMES(now, CAN_FREQ)
    struct timespec delay = {sec, nsec};
    
    
    while (1) {
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &delay, NULL);
        
        pack_count = check_message(data, BMS_PACK_RX, pack_count);
        other_count = check_message(data, BMS_OTHER_RX, other_count);
        error_count = check_message(data, BMS_ERROR_RX, error_count);
        
        UPDATE_DELAY(delay)
    }
}

unsigned int check_message(CAN_Data *data, CAN_Response_Index index, unsigned int prev) {
    unsigned int next;
    
    next = LOAD(data->responses[index].rx_count);
    if (next != prev) {
        if (prev == 0) {
            /* Turn on timeouts */
            STORE(data->responses[index].check_timeout, true);
        }
        printf("Received msg_id: %d\n", index);
        printf("\trx_count=%u\n", next);
        printf("\tcheck_timeout=%d\n", LOAD(data->responses[index].check_timeout));
        printf("\ttimeout_interval=%ld sec, %ld nsec\n", LOAD(data->responses[index].timeout_interval.tv_sec), LOAD(data->responses[index].timeout_interval.tv_nsec));
        printf("\tlast_time=%ld sec, %ld nsec\n", LOAD(data->responses[index].last_time.tv_sec), LOAD(data->responses[index].last_time.tv_nsec));
        printf("\n");
        
        dump_can_data(data);
    }
    
    return next;
}

void dump_can_data(CAN_Data *data) {
    printf("CAN Data:\n");
    
    printf("\tpack_soc=%hu\n", LOAD(data->pack_soc));
    printf("\tpack_voltage=%hu\n", LOAD(data->pack_voltage));
    printf("\tpack_current=%hu\n", LOAD(data->pack_current));
    
    printf("\tmin_voltage=%hu\n", LOAD(data->min_voltage));
    printf("\tmax_voltage=%hu\n", LOAD(data->max_voltage));
    printf("\tavg_temp=%hu\n", LOAD(data->avg_temp));
    printf("\thigh_temp=%hu\n", LOAD(data->high_temp));
    
    printf("\tfailsafe_status=%hhu\n", LOAD(data->failsafe_status));
    printf("\tdtc_flags_1=%hhu\n", LOAD(data->dtc_flags_1));
    printf("\tdtc_flags_2=%hu\n", LOAD(data->dtc_flags_2));
    printf("\trolling_counter=%hu\n", LOAD(data->rolling_counter));
    
    printf("\n");
}


