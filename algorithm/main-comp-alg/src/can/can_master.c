#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "can_master.h"
#include "can_handlers.h"
#include "vs_can_api.h"


#define CAN_FREQ 1000000L /* 1 kHz */
#define NS_IN_SEC 1000000000L
#define UPDATE_DELAY(name) name.tv_sec = name.tv_sec + ((name.tv_nsec + CAN_FREQ) / NS_IN_SEC);\
                           name.tv_nsec = (name.tv_nsec + CAN_FREQ) % NS_IN_SEC;
#define INIT_TIMES(name, time) sec = name.tv_sec + ((name.tv_nsec + time) / NS_IN_SEC);\
                               nsec = (name.tv_nsec + time) % NS_IN_SEC;

#define CAN_BUF_LEN 100


/* Global variables */
VSCAN_MSG request_lookup[NUM_CAN_REQUESTS];
VSCAN_MSG response_lookup[NUM_CAN_RESPONSES];
VSCAN_HANDLE handle;


/* This function executes all CAN bus reads and writes through the NetCAN
 * device. This function should only be launched by can_init() after successful 
 * initialization of CAN messages and data.
 * 
 * NOTE: This function will loop as a thread, waiting for the state machine or other
 * functions to signal that a CAN message should be sent.
 *
 * Params:
 *
 * Returns:
 *
 */
void *can_master(void *args) {
    /* Buffer to read CAN messages into */
    VSCAN_MSG read_buffer[CAN_BUF_LEN];
    DWORD num_read;
    VSCAN_STATUS status;
    
    /* Initialize loop timing */
    struct timespec now;
    if(clock_gettime(CLOCK_MONOTONIC, &now) == -1) {
        printf("clock_gettime() error: %s\n", strerror(errno));
        //TODO: Comm Loss
    }
    __time_t sec = now.tv_sec;
    __syscall_slong_t nsec = now.tv_nsec;

    INIT_TIMES(now, CAN_FREQ)
    struct timespec delay = {sec, nsec};
    
    
    while (1) {
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &delay, NULL);
        
        /* Read CAN bus messages */
        status = VSCAN_Read(handle, read_buffer, CAN_BUF_LEN, &num_read);
        if (status == VSCAN_ERR_OK) {
            for (int i = 0; i < num_read; i++) {
                handle_can_message(&(read_buffer[i]));
            }
        } else {
            //TODO: Comm Loss
        }
        
        /* Write CAN bus messages */
        
        UPDATE_DELAY(delay)
    }
}

void handle_can_message(VSCAN_MSG *msg) {
    
}

