#ifndef CAN_MASTER_H
#define CAN_MASTER_H

#include <pthread.h>
#include "vs_can_api.h"


typedef enum {
    IDLE,
    SEND,
    WAITING,
    TIMEOUT,
    COMPLETE
} CAN_State;

typedef enum {
    /* Isolation Monitor */
    ISO_STATE,
    ISO_RESISTANCE,
    ISO_ERROR,
    LIPO_VOLTAGE,
    
    /* Motor Controller */
    READY_TO_TRANSMIT,
    DISABLE_MOTOR,
    ENABLE_MOTOR,
    TRANSMIT_ENABLE,
    ACCEL_RAMP,
    DECEL_RAMP,
    STOP_MOTOR,
    SET_SPEED,
    MAX_SPEED,
    DEVICE_CURRENT,
    CURRENT_200PC,
    ACTUAL_SPEED,
    ACTUAL_CURRENT,
    ACTUAL_POSITION,
    
    
    NUM_CAN_REQUESTS
} CAN_Request;

/* This struct holds data received from CAN devices to be used
 * by the state machine.
 *
 * This struct also holds an array of CAN_State variables that should be
 * indexed by the enum type CAN_Request to signal the master CAN communication
 * thread to send messages on the CAN bus.
 * 
 * IMPORTANT: Every load/store using this struct must use
 * gcc atomics to guarantee correctness of simultaneous
 * thread access.
 */
typedef struct {
    /* --- Receive Data --- */
    
    /* Battery Management System */
    volatile short pack_soc;               /* Percent         */
    volatile short pack_voltage;           /* deci-Volts      */
    volatile short pack_current;           /* deci-Amps       */
    
    
    
    /* --- Transmit Data --- */
    volatile CAN_State requests[NUM_CAN_REQUESTS];
} CAN_Data;


/* Used by state machine */
int can_send(CAN_Request, CAN_Data *data);

#endif