#ifndef CAN_MASTER_H
#define CAN_MASTER_H

#include <pthread.h>
#include <stdbool.h>
#include "vs_can_api.h"


/* Used to safely load/store values in CAN_Data struct */
#define STORE(var, val) (__atomic_store_n(&(var), (val), __ATOMIC_RELAXED))
#define LOAD(var) (__atomic_load_n(&(var), __ATOMIC_RELAXED))

#define SEQ_STORE(var, val) (__atomic_store_n(&(var), (val), __ATOMIC_SEQ_CST))
#define SEQ_LOAD(var) (__atomic_load_n(&(var), __ATOMIC_SEQ_CST))

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
} CAN_Request_Index;

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
} CAN_Response_Index;

typedef struct {
    volatile unsigned char rx_count;
    volatile bool check_timeout;
    volatile struct timespec timeout_interval;
    volatile struct timespec last_time;
} CAN_Response;

typedef struct {
    volatile CAN_State state;
    volatile unsigned char tx_count;
    volatile bool check_timeout;
    volatile unsigned char timeout_count;
    volatile struct timespec timeout_interval;
    volatile struct timespec sent_time;
} CAN_Request;

typedef struct{
    volatile unsigned char hardware_error;        /*0 if no Hardware error, 1 if hardware error*/
    volatile unsigned char no_new_estimates;      /*0 if new isolation values have been calculated, 1 if not */
    volatile unsigned char high_uncertainty;      /*0 if uncertainty is less than 5%, 1 if greater than 5% */
    volatile unsigned char undefined;             /*none*/
    volatile unsigned char high_battery_voltage; /*0 if Observed battery voltage less than Max_battery_working_voltage, 1 if greater or not set*/
    volatile unsigned char low_batter_voltage;   /*0 if observed battery voltage greater than 15 V, 1 if battery voltage is less than 15 V*/
    volatile unsigned char isolation_status;      /*00 if isolation status is OK, 10 if isolation status < 500 Ohm/V limit, 11 if Isolation fault iso status < 100 Ohm/V limit*/
} Iso_Status_Bits;

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
    
    volatile short min_voltage;                         /* 10E-4 V */
    volatile short max_voltage;                         /* 10E-4 V */
    volatile short avg_temp;                            /* Celcius */
    volatile short high_temp;                           /* Celcius */
    
    volatile char failsafe_status;                      /* Bit Flags */
    volatile char dtc_flags_1;                          /* Bit Flags */
    volatile short dtc_flags_2;                         /* Bit Flags */
    volatile short rolling_counter;                     /* Counter   */
    
    volatile char error_flags;
    
    volatile short electrical_isolation;                /* ohm/V */
    volatile char electrical_isolation_uncert;         
    volatile short energy_stored;                       /* mJ */
    volatile char energy_stored_uncert;
    
    volatile short rp_iso_resistance;                   /* kohm */
    volatile char rp_iso_resistance_uncert;
    volatile short rn_iso_resistance;                   /* kohm */
    volatile char rn_iso_resistance_uncert;
    
    volatile Iso_Status_Bits status_bits;
    
    volatile short battery_volt;                        /* V */
    volatile char battery_volt_uncert;
    volatile short max_battery_volt;                    /* V */
    volatile char max_battery_volt_uncert;
    
    volatile short max_speed;                           /* rpm */
    
    volatile short dev_current;                         /* dA */
    
    volatile short current_200pc;                       /* ADC units */
    
    volatile short percent_max_speed;                   
    
    volatile short true_current;                        /* ADC units */
    
    volatile int revolutions;                           /* revolutions */
    
    
    /* --- Transmit Data --- */
    volatile CAN_Request requests[NUM_CAN_REQUESTS];
    volatile CAN_Response responses[NUM_CAN_RESPONSES];
} CAN_Data;

typedef struct {
    VSCAN_MSG msg;
    void (*handler)(VSCAN_MSG *msg, CAN_Data *data);
    int request_num;
} CAN_Response_Lookup;

/* Global variables */
extern VSCAN_MSG request_lookup[NUM_CAN_REQUESTS];
extern CAN_Response_Lookup response_lookup[NUM_CAN_RESPONSES];
extern VSCAN_HANDLE handle;


/* Used by state machine */
int can_send(CAN_Request_Index request, CAN_Data *data);

/* CAN master thread */
void *can_master(void *args);

#endif
