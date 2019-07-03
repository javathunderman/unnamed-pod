#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <stdbool.h>
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
CAN_Response_Lookup response_lookup[NUM_CAN_RESPONSES];
VSCAN_HANDLE handle;


/* This function executes all CAN bus reads and writes through the NetCAN
 * device. This function should only be launched by can_init() after successful 
 * initialization of CAN messages and data.
 * 
 * NOTE: This function will loop as a thread, waiting for the state machine or other
 * functions to signal that a CAN message should be sent.
 *
 * Params:
 *     CAN_Data *data -> pointer to CAN_Data struct used by state machine
 *
 * Returns:
 *     void *
 */
void *can_master(void *args) {
    /* Buffer to read CAN messages into */
    CAN_Data *data = (CAN_Data *)args;
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
                handle_can_message(data, &(read_buffer[i]), &delay);
            }
        } else {
            //TODO: Comm Loss
        }
        
        /* Check timeouts */
        
        /* Write CAN bus messages */
        
        UPDATE_DELAY(delay)
    }
}

/* This function takes one message received from the CAN bus and:
 *     1) Matches it with a lookup message template
 *     2) Updates CAN_Data associated with identified message
 *     3) Calls message-specific handler function (see can_handlers.c)
 *
 * NOTE: If the message cannot be identified, this function will signal
 *       a communication loss condition to stop the pod.
 *
 * Params:
 *     CAN_Data *data -> pointer to CAN_Data struct used by state machine
 *     VSCAN_MSG *msg -> message received from the CAN bus
 *     timespec *timestamp -> CLOCK_MONOTONIC time the message was received
 *
 * Returns:
 *     void
 */
void handle_can_message(CAN_Data *data, VSCAN_MSG *msg, struct timespec *timestamp) {
    int msg_id = -1;
    
    /* Identify message */
    for (int id = 0; id < NUM_CAN_RESPONSES; id++) {
        if (check_match(&(response_lookup[id].msg), msg)) {
            msg_id = id;
            break;
        }
    }
    
    if (msg_id == -1) {
        //TODO: Comm Loss
    }
    
    /* Update CAN_Data */
    STORE(data->responses[msg_id].state, COMPLETE)
    //LOAD
    
    /* Call handler function */
    response_lookup[msg_id].handler(msg, data);
}

/* This function compares a received CAN message to a lookup message.
 * This function checks the flags, id, and data bytes specified in the template
 * for equality to determine if the two messages match.
 * 
 * Params:
 *     VSCAN_MSG *lookup   -> Cached CAN message template
 *     VSCAN_MSG *received -> Received CAN message
 *
 * Returns:
 *     true  -> messages match
 *     false -> messages do not match
 */
bool check_match(VSCAN_MSG *lookup, VSCAN_MSG *received) {
    if (lookup->Flags != received->Flags)
        return false;
    
    if (lookup->Id != received->Id)
        return false;
    
    for (int i = 0; i < lookup->Size; i++) {
        if (lookup->Data[i] != received->Data[i])
            return false;
    }
    
    return true;
}

