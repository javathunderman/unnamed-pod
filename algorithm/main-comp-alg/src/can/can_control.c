#include <stdio.h>
#include "can_master.h"
#include "can_control.h"
#include "abort_run.h"
#include "utils.h"


#define NS_IN_SEC 1000000000L
#define CYCLES_IN_SEC (NS_IN_SEC / CAN_FREQ)
#define HZ_20 (CYCLES_IN_SEC / 20)

#define CHARGE_THRESHOLD 20250

static FSM_Status satisfy_request(CAN_Data *data, CAN_Request_Index index);
static FSM_Status reset_request_state(CAN_Data *data, CAN_Request_Index index);
static void try_send(CAN_Data *data, CAN_Request_Index index);
static int can_data_threshold(CAN_Data *data);

void control_cycle(CAN_Data *data, int cycle_num) {
    /* Send ISO requests */
    if ((cycle_num % HZ_20) == 0) {
        //try_send(data, ISO_STATE_TX);
        //try_send(data, ISO_RESISTANCE_TX);
        //try_send(data, ISO_ERROR_TX);
        try_send(data, LIPO_VOLTAGE_TX);
    }
    if (can_data_threshold(data)){
        //ABORT_RUN;
    }
}

FSM_Status can_motor_ready(CAN_Data *data) {
    FSM_Status ret_val;
    
    /* Satisfy READY_TO_TRANSMIT_TX */
    ret_val = satisfy_request(data, READY_TO_TRANSMIT_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy DISABLE_MOTOR_TX */
    ret_val = satisfy_request(data, DISABLE_MOTOR_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    return FSM_COMPLETE;
}

FSM_Status can_motor_enable(CAN_Data *data) {
    FSM_Status ret_val;
    
    /* Satisfy TRANSMIT_ENABLE_TX */
    ret_val = satisfy_request(data, TRANSMIT_ENABLE_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy ENABLE_MOTOR_TX */
    ret_val = satisfy_request(data, ENABLE_MOTOR_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    return FSM_COMPLETE;
}

FSM_Status can_motor_constants(CAN_Data *data) {
    FSM_Status ret_val;
    
    /* Satisfy MAX_SPEED_TX */
    ret_val = satisfy_request(data, MAX_SPEED_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy DEVICE_CURRENT_TX */
    ret_val = satisfy_request(data, DEVICE_CURRENT_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy CURRENT_200PC_TX */
    ret_val = satisfy_request(data, CURRENT_200PC_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    return FSM_COMPLETE;
}

FSM_Status can_motor_precharge(CAN_Data *data) {
    FSM_Status ret_val;
    
    /* Satisfy CONTROLLER_VOLT_TX */
    ret_val = satisfy_request(data, CONTROLLER_VOLT_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    if (SEQ_LOAD(data->controller_bus_voltage) < CHARGE_THRESHOLD) {
        return FSM_WAITING;
    }
    
    /* Satisfy CONTROLLER_VOLT_STOP_TX */
    ret_val = satisfy_request(data, CONTROLLER_VOLT_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    return FSM_COMPLETE;
}

FSM_Status can_motor_start_highrate(CAN_Data *data) {
    FSM_Status ret_val;
    
    /* Satisfy ACTUAL_SPEED_TX */
    ret_val = satisfy_request(data, ACTUAL_SPEED_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy ACTUAL_CURRENT_TX */
    ret_val = satisfy_request(data, ACTUAL_CURRENT_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy ACTUAL_POSITION_TX */
    ret_val = satisfy_request(data, ACTUAL_POSITION_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy CONTROLLER_ERROR_TX */
    ret_val = satisfy_request(data, CONTROLLER_ERROR_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    return FSM_COMPLETE;
}

FSM_Status can_motor_stop_highrate(CAN_Data *data) {
    FSM_Status ret_val;
    
    /* Satisfy ACTUAL_SPEED_STOP_TX */
    ret_val = satisfy_request(data, ACTUAL_SPEED_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy ACTUAL_CURRENT_STOP_TX */
    ret_val = satisfy_request(data, ACTUAL_CURRENT_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy ACTUAL_POSITION_STOP_TX */
    ret_val = satisfy_request(data, ACTUAL_POSITION_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy CONTROLLER_ERROR_STOP_TX */
    ret_val = satisfy_request(data, CONTROLLER_ERROR_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    return FSM_COMPLETE;
}

FSM_Status can_motor_end_run(CAN_Data *data) {
    FSM_Status ret_val;
    
    /* Satisfy STOP_MOTOR_TX */
    ret_val = satisfy_request(data, STOP_MOTOR_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Satisfy DISABLE_MOTOR_TX */
    ret_val = satisfy_request(data, DISABLE_MOTOR_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    return FSM_COMPLETE;
}

FSM_Status can_reset_precharge(CAN_Data *data) {
    FSM_Status ret_val;
    
    /* Reset ACTUAL_SPEED_TX */
    ret_val = reset_request_state(data, ACTUAL_SPEED_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_CURRENT_TX */
    ret_val = reset_request_state(data, ACTUAL_CURRENT_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_POSITION_TX */
    ret_val = reset_request_state(data, ACTUAL_POSITION_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CONTROLLER_VOLT_TX */
    ret_val = reset_request_state(data, CONTROLLER_VOLT_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CONTROLLER_ERROR_TX */
    ret_val = reset_request_state(data, CONTROLLER_ERROR_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_SPEED_STOP_TX */
    ret_val = reset_request_state(data, ACTUAL_SPEED_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_CURRENT_STOP_TX */
    ret_val = reset_request_state(data, ACTUAL_CURRENT_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_POSITION_STOP_TX */
    ret_val = reset_request_state(data, ACTUAL_POSITION_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CONTROLLER_ERROR_STOP_TX */
    ret_val = reset_request_state(data, CONTROLLER_ERROR_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CONTROLLER_VOLT_STOP_TX */
    ret_val = reset_request_state(data, CONTROLLER_VOLT_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    return FSM_COMPLETE;
}

FSM_Status can_reset_motor(CAN_Data *data) {
    FSM_Status ret_val;
    
    /* Reset precharge */
    ret_val = can_reset_precharge(data);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset READY_TO_TRANSMIT_TX */
    ret_val = reset_request_state(data, READY_TO_TRANSMIT_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset DISABLE_MOTOR_TX */
    ret_val = reset_request_state(data, DISABLE_MOTOR_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ENABLE_MOTOR_TX */
    ret_val = reset_request_state(data, ENABLE_MOTOR_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset TRANSMIT_ENABLE_TX */
    ret_val = reset_request_state(data, TRANSMIT_ENABLE_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACCEL_RAMP_TX */
    ret_val = reset_request_state(data, ACCEL_RAMP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset DECEL_RAMP_TX */
    ret_val = reset_request_state(data, DECEL_RAMP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset STOP_MOTOR_TX */
    ret_val = reset_request_state(data, STOP_MOTOR_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset SET_SPEED_TX */
    ret_val = reset_request_state(data, SET_SPEED_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset MAX_SPEED_TX */
    ret_val = reset_request_state(data, MAX_SPEED_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset DEVICE_CURRENT_TX */
    ret_val = reset_request_state(data, MAX_SPEED_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CURRENT_200PC_TX */
    ret_val = reset_request_state(data, MAX_SPEED_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_SPEED_TX */
    ret_val = reset_request_state(data, ACTUAL_SPEED_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_CURRENT_TX */
    ret_val = reset_request_state(data, ACTUAL_CURRENT_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_POSITION_TX */
    ret_val = reset_request_state(data, ACTUAL_POSITION_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CONTROLLER_VOLT_TX */
    ret_val = reset_request_state(data, CONTROLLER_VOLT_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_SPEED_STOP_TX */
    ret_val = reset_request_state(data, ACTUAL_SPEED_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_CURRENT_STOP_TX */
    ret_val = reset_request_state(data, ACTUAL_CURRENT_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset ACTUAL_POSITION_STOP_TX */
    ret_val = reset_request_state(data, ACTUAL_POSITION_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CONTROLLER_VOLT_STOP_TX */
    ret_val = reset_request_state(data, CONTROLLER_VOLT_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CONTROLLER_ERROR_STOP_TX */
    ret_val = reset_request_state(data, CONTROLLER_ERROR_STOP_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CONTROLLER_STATUS_TX */
    ret_val = reset_request_state(data, CONTROLLER_STATUS_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    /* Reset CONTROLLER_CLEAR_ERRORS_TX */
    ret_val = reset_request_state(data, CONTROLLER_CLEAR_ERRORS_TX);
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return ret_val;
    }
    
    return FSM_COMPLETE;
}

/******************************************************************************/
/***     STATIC HELPER FUNCTIONS                                            ***/
/******************************************************************************/

/* This function satisfies a CAN request by properly signaling the master
 * master CAN thread and checking for a completion status. In the event of a
 * timeout, the request will be retried MAX_CAN_RETRIES number of times.
 *
 * Params:
 *     CAN_Request_Index index -> enum value of request to be completed
 *     CAN_Data *data -> CAN_Data *data -> pointer to CAN_Data struct used by state machine
 *
 * Returns:
 *     FSM_WAITING  -> Request in progress
 *     FSM_COMPLETE -> Request successfully completed
 *     FSM_FAILED   -> Request failed
 */
static FSM_Status satisfy_request(CAN_Data *data, CAN_Request_Index index) {
    CAN_State state = SEQ_LOAD(data->requests[index].state);
    
    if (state == COMPLETE) {
        return FSM_COMPLETE;
    } else if (state == WAITING || state == SEND) {
        return FSM_WAITING;
    } else {
        if ((state == TIMEOUT) && (SEQ_LOAD(data->requests[index].timeout_count) > MAX_CAN_RETRIES)) {
            return FSM_FAILED;
        } else {
            SEQ_STORE(data->requests[index].state, SEND);
        }
    }
    
    return FSM_WAITING;
}

/* This function tries to send one CAN message
 * 
 */
static void try_send(CAN_Data *data, CAN_Request_Index index) {
    CAN_State state = SEQ_LOAD(data->requests[index].state);
    
    if ((state != SEND) && (state != WAITING)) {
        if ((state == TIMEOUT) && (SEQ_LOAD(data->requests[index].timeout_count) > MAX_CAN_RETRIES)) {
            ABORT_RUN;
            printf("Can request #%d exceeded %d timeouts in try_send()\n", index, MAX_CAN_RETRIES);
        } else {
            SEQ_STORE(data->requests[index].state, SEND);
        }
    }
}

static FSM_Status reset_request_state(CAN_Data *data, CAN_Request_Index index) {
    CAN_State state = SEQ_LOAD(data->requests[index].state);
    
    if (state == IDLE) {
        return FSM_COMPLETE;
    } else if (state == SEND || state == WAITING) {
        return FSM_WAITING;
    } else {
        SEQ_STORE(data->requests[index].state, IDLE);
        return FSM_COMPLETE;
    }
}

static int can_data_threshold(CAN_Data *data){
    
    if (data->min_voltage < 2.7){
        return 1;
    }
    if (data->max_voltage > 4.2){
        return 1;      
    }
    if (data->avg_temp > 65){
        return 1;   
    }
    if (data->high_temp > 70){
        return 1;   
    }
    if (data->controller_errors != 0){
        return 1;   
    }
    if (data->true_current > data->current_200pc){
        return 1;   
    }
    
    return 0;
}
