#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#include <sched.h>
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
static unsigned int check_response(CAN_Data *data, CAN_Response_Index index, unsigned int prev);
static CAN_State check_request(CAN_Data *data, CAN_Request_Index index, CAN_State prev);
static void try_send(CAN_Data *data, CAN_Request_Index index);
static void dump_can_data(CAN_Data *data);

/* Test receiving BMS CAN messages
 */
int main(void) {
    CAN_Data data;
    const struct sched_param priority = {80};
    
    printf("STARTING TEST\n");
    
    if (pthread_setschedparam(pthread_self(), SCHED_FIFO, &priority) != 0) {
        printf("Failed to set driver thread priority...\n");
        return -1;
    }
    
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
    int cycle_num = 0;
    CAN_State req_state[NUM_CAN_REQUESTS];
    unsigned int res_count[NUM_CAN_RESPONSES];
    unsigned int prev;
    bool dump = false;
    int i;
    
    /* Zero arrays*/
    for (i = 0; i < NUM_CAN_REQUESTS; i++) {
        req_state[i] = LOAD(data->requests[i].state);
    }
    for (i = 0; i < NUM_CAN_RESPONSES; i++) {
        res_count[i] = LOAD(data->responses[i].rx_count);
    }
    
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
    
    /* Setup request timeouts */
    STORE(data->requests[ISO_STATE_TX].check_timeout, true);
    STORE(data->requests[ISO_RESISTANCE_TX].check_timeout, true);
    STORE(data->requests[ISO_ERROR_TX].check_timeout, true);
    STORE(data->requests[LIPO_VOLTAGE_TX].check_timeout, true);
    
    while (1) {
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &delay, NULL);
        cycle_num = (cycle_num == 1000) ? 1 : cycle_num + 1;
        
        /* Send requests */
        if (cycle_num % 500 == 0) {
            try_send(data, ISO_STATE_TX);
            try_send(data, ISO_RESISTANCE_TX);
            try_send(data, ISO_ERROR_TX);
            try_send(data, LIPO_VOLTAGE_TX);
        }
        
        /* Check for new responses */
        for (i = 0; i < NUM_CAN_RESPONSES; i++) {
            prev = res_count[i];
            res_count[i] = check_response(data, i, res_count[i]);
            dump = dump || (prev != res_count[i]);
        }
        
        /* Check for request state transitions */
        for (i = 0; i < NUM_CAN_REQUESTS; i++) {
            req_state[i] = check_request(data, i, req_state[i]);
        }
        
        /* Dump CAN_Data struct */
        if (dump) {
            dump_can_data(data);
            dump = false;
        }
        
        UPDATE_DELAY(delay)
    }
}

void try_send(CAN_Data *data, CAN_Request_Index index) {
    if (SEQ_LOAD(data->requests[index].state) != WAITING) {
        SEQ_STORE(data->requests[index].state, SEND);
    } else {
        printf("Couldn't send request #%d: still in WAITING state\n", index);
        printf("\n");
    }
}

unsigned int check_response(CAN_Data *data, CAN_Response_Index index, unsigned int prev) {
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
    }
    
    return next;
}

CAN_State check_request(CAN_Data *data, CAN_Request_Index index, CAN_State prev) {
    CAN_State next;
    
    next = LOAD(data->requests[index].state);
    if (next != prev) {
        printf("Request #%d state transition: %d -> %d\n", index, prev, next);
        printf("\ttx_count=%u\n", LOAD(data->requests[index].tx_count));
        printf("\tcheck_timeout=%d\n", LOAD(data->requests[index].check_timeout));
        printf("\ttimeout_count=%u\n", LOAD(data->requests[index].timeout_count));
        printf("\ttimeout_interval=%ld sec, %ld nsec\n", LOAD(data->requests[index].timeout_interval.tv_sec), LOAD(data->requests[index].timeout_interval.tv_nsec));
        printf("\tsent_time=%ld sec, %ld nsec\n", LOAD(data->requests[index].sent_time.tv_sec), LOAD(data->requests[index].sent_time.tv_nsec));
        printf("\n");
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


