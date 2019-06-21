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
    ISO_STATE_TX,
    ISO_RESISTANCE_TX,
    ISO_ERROR_TX,
    LIPO_VOLTAGE_TX,
    
    /* Motor Controller */
    READY_TO_TRANSMIT_TX,
    DISABLE_MOTOR_TX,
    ENABLE_MOTOR_TX,
    TRANSMIT_ENABLE_TX,
    ACCEL_RAMP_TX,
    DECEL_RAMP_TX,
    STOP_MOTOR_TX,
    SET_SPEED_TX,
    MAX_SPEED_TX,
    DEVICE_CURRENT_TX,
    CURRENT_200PC_TX,
    ACTUAL_SPEED_TX,
    ACTUAL_CURRENT_TX,
    ACTUAL_POSITION_TX,
    
    NUM_CAN_REQUESTS
} CAN_Request;

typedef enum {
    /* Battery Management System */
    BMS_PACK_RX,
    BMS_OTHER_RX,
    BMS_ERROR_RX,
    
    /* Isolation Monitor */
    ISO_STATE_RX,
    ISO_RESISTANCE_RX,
    ISO_ERROR_RX,
    LIPO_VOLTAGE_RX,
    
    /* Motor Controller */
    READY_TO_TRANSMIT_RX,
    TRANSMIT_ENABLE_RX,
    MAX_SPEED_RX,
    DEVICE_CURRENT_RX,
    CURRENT_200PC_RX,
    ACTUAL_SPEED_RX,
    ACTUAL_CURRENT_RX,
    ACTUAL_POSITION_RX,
    
    NUM_CAN_RESPONSES
} CAN_Response;

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

/* CAN master thread */
void *can_master(void *args);

/* CAN initialization */
int can_init();
void init_can_requests();
void init_can_responses();

#endif