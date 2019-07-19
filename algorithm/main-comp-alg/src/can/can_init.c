#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <pthread.h>
#include "can_init.h"
#include "can_handlers.h"
#include "can_master.h"
#include "vs_can_api.h"


/* This function intializes a connection to the NetCAN device.
 * This function must run successfully before any CAN messages are
 * sent or received.
 *
 * Params:
 *     CAN_Data *data -> pointer to CAN_Data struct used by state machine
 *
 * Returns:
 *      0 -> success
 *     -1 -> VSCAN_Open failure
 *     -2 -> bitrate configuration failure
 *     -3 -> pthread failure
 */
int can_init(CAN_Data *data) {
    handle = -1;
    pthread_t can_tid;
    DWORD bitrate = 500000;
    char *tty = "10.25.37.4:2001"; //TODO: Verify IP
    
    /* Establish connection to NetCAN device */
    handle = VSCAN_Open(tty, VSCAN_MODE_NORMAL);
    if (handle <= 0) {
        printf("Could not connect to NetCAN device!\n");
        return -1;
    }
    
    /* Set CAN bus bitrate */
    if (VSCAN_Ioctl(handle, VSCAN_IOCTL_SET_SPEED, (void *)bitrate) != VSCAN_ERR_OK) {
        printf("Setting CAN speed failed");
        return -2;
    }
    
    
    /* Create VSCAN_MSGs that will be used during the run */
    init_can_requests();
    init_can_responses();
    
    /* Initialize CAN_Data fields */
    init_can_data(data);
    
    /* Launch master CAN thread */
    if (pthread_create(&can_tid, NULL, can_master, data) != 0) {
        printf("can_master pthread create failed...\n");
        return -3;
    } else {
        printf("Created can_master thread...\n");
    }
    
    return 0;
}

/* This function initializes the CAN_Data struct by zeroing all data values
 * and setting default values for all CAN message metadata.  All CAN responses
 * and requests are initialized with timeouts, but leave check_timeout FALSE.
 * The requesting code must set check_timeout to TRUE to use timeouts.
 *
 * Params:
 *     CAN_Data *data -> pointer to CAN_Data struct used by state machine
 *
 * Returns:
 *     void
 */
void init_can_data(CAN_Data *data) {
    int i;
    
    /* Init response fields */
    for (i = 0; i < NUM_CAN_RESPONSES; i++) {
        STORE(data->responses[i].rx_count, 0);
        STORE(data->responses[i].last_time.tv_sec, 0L);
        STORE(data->responses[i].last_time.tv_nsec, 0L);
        STORE(data->responses[i].check_timeout, false);
         
        /* Configure timeout per message */
        switch (i) {
            case BMS_PACK_RX:
            case BMS_OTHER_RX:
            case BMS_ERROR_RX:
                /* 300ms timeout */
                STORE(data->responses[i].timeout_interval.tv_sec, 0L);
                STORE(data->responses[i].timeout_interval.tv_nsec, 300000000L);
                break;
            
            case ISO_STATE_RX:
            case ISO_RESISTANCE_RX:
            case ISO_ERROR_RX:
            case LIPO_VOLTAGE_RX:
                /* 1.5sec timeout */
                STORE(data->responses[i].timeout_interval.tv_sec, 1L);
                STORE(data->responses[i].timeout_interval.tv_nsec, 500000000L);
                break;
            
            case ACTUAL_SPEED_RX:
            case ACTUAL_CURRENT_RX:
            case ACTUAL_POSITION_RX:
                /* 20ms timeout */
                STORE(data->responses[i].timeout_interval.tv_sec, 0L);
                STORE(data->responses[i].timeout_interval.tv_nsec, 20000000L);
                break;
            
            default: 
                /* No timeout */
                STORE(data->responses[i].timeout_interval.tv_sec, LONG_MAX);
                STORE(data->responses[i].timeout_interval.tv_nsec, 999999999L);
        }
    }
    
    /* Init request fields */
    for (i = 0; i < NUM_CAN_REQUESTS; i++) {
        STORE(data->requests[i].state, IDLE);
        STORE(data->requests[i].tx_count, 0);
        STORE(data->requests[i].check_timeout, false);
        STORE(data->requests[i].timeout_count, 0);
        STORE(data->requests[i].sent_time.tv_sec, 0L);
        STORE(data->requests[i].sent_time.tv_nsec, 0L);
        STORE(data->requests[i].timeout_interval.tv_sec, 0L);
        STORE(data->requests[i].timeout_interval.tv_nsec, 20000000L); /* 20ms timeout */
    }
    
    /* Init values to 0 */
    STORE(data->pack_soc, 0);
    STORE(data->pack_voltage, 0);
    STORE(data->pack_current, 0);
    STORE(data->min_voltage, 0);
    STORE(data->max_voltage, 0);
    STORE(data->avg_temp, 0);
    STORE(data->high_temp, 0);
    STORE(data->failsafe_status, 0);
    STORE(data->dtc_flags_1, 0);
    STORE(data->dtc_flags_2, 0);
    STORE(data->rolling_counter, 0);
    STORE(data->iso_status_flags, 0);
    STORE(data->iso_error_flags, 0);
    STORE(data->electrical_isolation, 0);
    STORE(data->electrical_isolation_uncert, 0);
    STORE(data->energy_stored, 0);
    STORE(data->energy_stored_uncert, 0);
    STORE(data->rp_iso_resistance, 0);
    STORE(data->rp_iso_resistance_uncert, 0);
    STORE(data->rn_iso_resistance, 0);
    STORE(data->rn_iso_resistance_uncert, 0);
    STORE(data->battery_volt, 0);
    STORE(data->battery_volt_uncert, 0);
    STORE(data->max_battery_volt, 0);
    STORE(data->max_battery_volt_uncert, 0);
    STORE(data->max_speed, 0);
    STORE(data->dev_current, 0);
    STORE(data->current_200pc, 0);
    STORE(data->percent_max_speed, 0);
    STORE(data->true_current, 0);
    STORE(data->revolutions, 0);
    STORE(data->controller_bus_voltage, 0);
    STORE(data->controller_errors, 0);
}

/* This function initializes the request_lookup array with CAN messages
 * to be sent during the run. This function must run during startup before any
 * CAN messages are sent.
 *
 * Params:
 *     void
 * 
 * Returns:
 *     void
 */
void init_can_requests() {
    /* ISO_STATE_TX */
    request_lookup[ISO_STATE_TX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[ISO_STATE_TX].msg.Id = 0xA100101;
    request_lookup[ISO_STATE_TX].msg.Size = 1;
    request_lookup[ISO_STATE_TX].msg.Data[0] = 0xE0;
    request_lookup[ISO_STATE_TX].expect_response = true;
    
    /* ISO_RESISTANCE_TX */
    request_lookup[ISO_RESISTANCE_TX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[ISO_RESISTANCE_TX].msg.Id = 0xA100101;
    request_lookup[ISO_RESISTANCE_TX].msg.Size = 1;
    request_lookup[ISO_RESISTANCE_TX].msg.Data[0] = 0xE1;
    request_lookup[ISO_RESISTANCE_TX].expect_response = true;
    
    /* ISO_ERROR_TX */
    request_lookup[ISO_ERROR_TX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[ISO_ERROR_TX].msg.Id = 0xA100101;
    request_lookup[ISO_ERROR_TX].msg.Size = 1;
    request_lookup[ISO_ERROR_TX].msg.Data[0] = 0xE5;
    request_lookup[ISO_ERROR_TX].expect_response = true;
    
    /* LIPO_VOLTAGE_TX */
    request_lookup[LIPO_VOLTAGE_TX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[LIPO_VOLTAGE_TX].msg.Id = 0xA100101;
    request_lookup[LIPO_VOLTAGE_TX].msg.Size = 1;
    request_lookup[LIPO_VOLTAGE_TX].msg.Data[0] = 0xE4;
    request_lookup[LIPO_VOLTAGE_TX].expect_response = true;
    
    /* READY_TO_TRANSMIT_TX */
    request_lookup[READY_TO_TRANSMIT_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[READY_TO_TRANSMIT_TX].msg.Id = 0x201;
    request_lookup[READY_TO_TRANSMIT_TX].msg.Size = 3;
    request_lookup[READY_TO_TRANSMIT_TX].msg.Data[0] = 0x3D;
    request_lookup[READY_TO_TRANSMIT_TX].msg.Data[1] = 0xE2;
    request_lookup[READY_TO_TRANSMIT_TX].msg.Data[2] = 0x00;
    request_lookup[READY_TO_TRANSMIT_TX].expect_response = true;
    
    /* DISABLE_MOTOR_TX */
    request_lookup[DISABLE_MOTOR_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[DISABLE_MOTOR_TX].msg.Id = 0x201;
    request_lookup[DISABLE_MOTOR_TX].msg.Size = 3;
    request_lookup[DISABLE_MOTOR_TX].msg.Data[0] = 0x51;
    request_lookup[DISABLE_MOTOR_TX].msg.Data[1] = 0x04;
    request_lookup[DISABLE_MOTOR_TX].msg.Data[2] = 0x00;
    request_lookup[DISABLE_MOTOR_TX].expect_response = false;
    
    /* ENABLE_MOTOR_TX */
    request_lookup[ENABLE_MOTOR_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ENABLE_MOTOR_TX].msg.Id = 0x201;
    request_lookup[ENABLE_MOTOR_TX].msg.Size = 3;
    request_lookup[ENABLE_MOTOR_TX].msg.Data[0] = 0x51;
    request_lookup[ENABLE_MOTOR_TX].msg.Data[1] = 0x00;
    request_lookup[ENABLE_MOTOR_TX].msg.Data[2] = 0x00;
    request_lookup[ENABLE_MOTOR_TX].expect_response = false;
    
    /* TRANSMIT_ENABLE_TX */
    request_lookup[TRANSMIT_ENABLE_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[TRANSMIT_ENABLE_TX].msg.Id = 0x201;
    request_lookup[TRANSMIT_ENABLE_TX].msg.Size = 3;
    request_lookup[TRANSMIT_ENABLE_TX].msg.Data[0] = 0x3D;
    request_lookup[TRANSMIT_ENABLE_TX].msg.Data[1] = 0xE8;
    request_lookup[TRANSMIT_ENABLE_TX].msg.Data[2] = 0x00;
    request_lookup[TRANSMIT_ENABLE_TX].expect_response = true;
    
    /* ACCEL_RAMP_TX */
    request_lookup[ACCEL_RAMP_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACCEL_RAMP_TX].msg.Id = 0x201;
    request_lookup[ACCEL_RAMP_TX].msg.Size = 3;
    request_lookup[ACCEL_RAMP_TX].msg.Data[0] = 0x35;
    request_lookup[ACCEL_RAMP_TX].msg.Data[1] = 0xF4;
    request_lookup[ACCEL_RAMP_TX].msg.Data[2] = 0x01;
    request_lookup[ACCEL_RAMP_TX].expect_response = false;
    
    /* DECEL_RAMP_TX */
    request_lookup[DECEL_RAMP_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[DECEL_RAMP_TX].msg.Id = 0x201;
    request_lookup[DECEL_RAMP_TX].msg.Size = 3;
    request_lookup[DECEL_RAMP_TX].msg.Data[0] = 0xED;
    request_lookup[DECEL_RAMP_TX].msg.Data[1] = 0xE8;
    request_lookup[DECEL_RAMP_TX].msg.Data[2] = 0x03;
    request_lookup[DECEL_RAMP_TX].expect_response = false;
    
    /* STOP_MOTOR_TX */
    request_lookup[STOP_MOTOR_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[STOP_MOTOR_TX].msg.Id = 0x201;
    request_lookup[STOP_MOTOR_TX].msg.Size = 3;
    request_lookup[STOP_MOTOR_TX].msg.Data[0] = 0x31;
    request_lookup[STOP_MOTOR_TX].msg.Data[1] = 0x00;
    request_lookup[STOP_MOTOR_TX].msg.Data[2] = 0x00;
    request_lookup[STOP_MOTOR_TX].expect_response = false;
    
    /* SET_SPEED_TX */
    request_lookup[SET_SPEED_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[SET_SPEED_TX].msg.Id = 0x201;
    request_lookup[SET_SPEED_TX].msg.Size = 3;
    request_lookup[SET_SPEED_TX].msg.Data[0] = 0x31;
    request_lookup[SET_SPEED_TX].msg.Data[1] = 0x00;  //TODO: Percent Max Speed
    request_lookup[SET_SPEED_TX].msg.Data[2] = 0x00;  //TODO: Percent Max Speed
    request_lookup[SET_SPEED_TX].expect_response = false;
    
    /* MAX_SPEED_TX */
    request_lookup[MAX_SPEED_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[MAX_SPEED_TX].msg.Id = 0x201;
    request_lookup[MAX_SPEED_TX].msg.Size = 3;
    request_lookup[MAX_SPEED_TX].msg.Data[0] = 0x3D;
    request_lookup[MAX_SPEED_TX].msg.Data[1] = 0xCE;
    request_lookup[MAX_SPEED_TX].msg.Data[2] = 0x00;
    request_lookup[MAX_SPEED_TX].expect_response = true;
    
    /* DEVICE_CURRENT_TX */
    request_lookup[DEVICE_CURRENT_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[DEVICE_CURRENT_TX].msg.Id = 0x201;
    request_lookup[DEVICE_CURRENT_TX].msg.Size = 3;
    request_lookup[DEVICE_CURRENT_TX].msg.Data[0] = 0x3D;
    request_lookup[DEVICE_CURRENT_TX].msg.Data[1] = 0xC6;
    request_lookup[DEVICE_CURRENT_TX].msg.Data[2] = 0x00;
    request_lookup[DEVICE_CURRENT_TX].expect_response = true;
    
    /* CURRENT_200PC_TX */
    request_lookup[CURRENT_200PC_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[CURRENT_200PC_TX].msg.Id = 0x201;
    request_lookup[CURRENT_200PC_TX].msg.Size = 3;
    request_lookup[CURRENT_200PC_TX].msg.Data[0] = 0x3D;
    request_lookup[CURRENT_200PC_TX].msg.Data[1] = 0xD9;
    request_lookup[CURRENT_200PC_TX].msg.Data[2] = 0x00;
    request_lookup[CURRENT_200PC_TX].expect_response = true;
    
    /* ACTUAL_SPEED_TX */
    request_lookup[ACTUAL_SPEED_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACTUAL_SPEED_TX].msg.Id = 0x201;
    request_lookup[ACTUAL_SPEED_TX].msg.Size = 3;
    request_lookup[ACTUAL_SPEED_TX].msg.Data[0] = 0x3D;
    request_lookup[ACTUAL_SPEED_TX].msg.Data[1] = 0x30;
    request_lookup[ACTUAL_SPEED_TX].msg.Data[2] = 0x02;
    request_lookup[ACTUAL_SPEED_TX].expect_response = false;
    
    /* ACTUAL_CURRENT_TX */
    request_lookup[ACTUAL_CURRENT_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACTUAL_CURRENT_TX].msg.Id = 0x201;
    request_lookup[ACTUAL_CURRENT_TX].msg.Size = 3;
    request_lookup[ACTUAL_CURRENT_TX].msg.Data[0] = 0x3D;
    request_lookup[ACTUAL_CURRENT_TX].msg.Data[1] = 0x20;
    request_lookup[ACTUAL_CURRENT_TX].msg.Data[2] = 0x02;
    request_lookup[ACTUAL_CURRENT_TX].expect_response = false;
    
    /* ACTUAL_POSITION_TX */
    request_lookup[ACTUAL_POSITION_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACTUAL_POSITION_TX].msg.Id = 0x201;
    request_lookup[ACTUAL_POSITION_TX].msg.Size = 3;
    request_lookup[ACTUAL_POSITION_TX].msg.Data[0] = 0x3D;
    request_lookup[ACTUAL_POSITION_TX].msg.Data[1] = 0x6D;
    request_lookup[ACTUAL_POSITION_TX].msg.Data[2] = 0x02;
    request_lookup[ACTUAL_POSITION_TX].expect_response = false;
    
    /* CONTROLLER_VOLT_TX */
    request_lookup[CONTROLLER_VOLT_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[CONTROLLER_VOLT_TX].msg.Id = 0x201;
    request_lookup[CONTROLLER_VOLT_TX].msg.Size = 3;
    request_lookup[CONTROLLER_VOLT_TX].msg.Data[0] = 0x3D;
    request_lookup[CONTROLLER_VOLT_TX].msg.Data[1] = 0xEB;
    request_lookup[CONTROLLER_VOLT_TX].msg.Data[2] = 0x02;
    request_lookup[CONTROLLER_VOLT_TX].expect_response = false;
    
    /* CONTROLLER_ERROR_TX */
    request_lookup[CONTROLLER_ERROR_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[CONTROLLER_ERROR_TX].msg.Id = 0x201;
    request_lookup[CONTROLLER_ERROR_TX].msg.Size = 3;
    request_lookup[CONTROLLER_ERROR_TX].msg.Data[0] = 0x3D;
    request_lookup[CONTROLLER_ERROR_TX].msg.Data[1] = 0x8F;
    request_lookup[CONTROLLER_ERROR_TX].msg.Data[2] = 0x02;
    request_lookup[CONTROLLER_ERROR_TX].expect_response = false;
    
    /* ACTUAL_SPEED_STOP_TX */
    request_lookup[ACTUAL_SPEED_STOP_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACTUAL_SPEED_STOP_TX].msg.Id = 0x201;
    request_lookup[ACTUAL_SPEED_STOP_TX].msg.Size = 3;
    request_lookup[ACTUAL_SPEED_STOP_TX].msg.Data[0] = 0x3D;
    request_lookup[ACTUAL_SPEED_STOP_TX].msg.Data[1] = 0x30;
    request_lookup[ACTUAL_SPEED_STOP_TX].msg.Data[2] = 0xFF;
    request_lookup[ACTUAL_SPEED_STOP_TX].expect_response = false;
    
    /* ACTUAL_CURRENT_STOP_TX */
    request_lookup[ACTUAL_CURRENT_STOP_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACTUAL_CURRENT_STOP_TX].msg.Id = 0x201;
    request_lookup[ACTUAL_CURRENT_STOP_TX].msg.Size = 3;
    request_lookup[ACTUAL_CURRENT_STOP_TX].msg.Data[0] = 0x3D;
    request_lookup[ACTUAL_CURRENT_STOP_TX].msg.Data[1] = 0x20;
    request_lookup[ACTUAL_CURRENT_STOP_TX].msg.Data[2] = 0xFF;
    request_lookup[ACTUAL_CURRENT_STOP_TX].expect_response = false;
    
    /* ACTUAL_POSITION_STOP_TX */
    request_lookup[ACTUAL_POSITION_STOP_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACTUAL_POSITION_STOP_TX].msg.Id = 0x201;
    request_lookup[ACTUAL_POSITION_STOP_TX].msg.Size = 3;
    request_lookup[ACTUAL_POSITION_STOP_TX].msg.Data[0] = 0x3D;
    request_lookup[ACTUAL_POSITION_STOP_TX].msg.Data[1] = 0x6D;
    request_lookup[ACTUAL_POSITION_STOP_TX].msg.Data[2] = 0xFF;
    request_lookup[ACTUAL_POSITION_STOP_TX].expect_response = false;
    
    /* CONTROLLER_VOLT_STOP_TX */
    request_lookup[CONTROLLER_VOLT_STOP_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[CONTROLLER_VOLT_STOP_TX].msg.Id = 0x201;
    request_lookup[CONTROLLER_VOLT_STOP_TX].msg.Size = 3;
    request_lookup[CONTROLLER_VOLT_STOP_TX].msg.Data[0] = 0x3D;
    request_lookup[CONTROLLER_VOLT_STOP_TX].msg.Data[1] = 0xEB;
    request_lookup[CONTROLLER_VOLT_STOP_TX].msg.Data[2] = 0xFF;
    request_lookup[CONTROLLER_VOLT_STOP_TX].expect_response = false;
    
    /* CONTROLLER_ERROR_STOP_TX */
    request_lookup[CONTROLLER_ERROR_STOP_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[CONTROLLER_ERROR_STOP_TX].msg.Id = 0x201;
    request_lookup[CONTROLLER_ERROR_STOP_TX].msg.Size = 3;
    request_lookup[CONTROLLER_ERROR_STOP_TX].msg.Data[0] = 0x3D;
    request_lookup[CONTROLLER_ERROR_STOP_TX].msg.Data[1] = 0x8F;
    request_lookup[CONTROLLER_ERROR_STOP_TX].msg.Data[2] = 0xFF;
    request_lookup[CONTROLLER_ERROR_STOP_TX].expect_response = false;
    
    /* CONTROLLER_STATUS_TX */
    request_lookup[CONTROLLER_STATUS_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[CONTROLLER_STATUS_TX].msg.Id = 0x201;
    request_lookup[CONTROLLER_STATUS_TX].msg.Size = 3;
    request_lookup[CONTROLLER_STATUS_TX].msg.Data[0] = 0x3D;
    request_lookup[CONTROLLER_STATUS_TX].msg.Data[1] = 0x40;
    request_lookup[CONTROLLER_STATUS_TX].msg.Data[2] = 0x00;
    request_lookup[CONTROLLER_STATUS_TX].expect_response = true;
    
    /* CONTROLLER_CLEAR_ERRORS_TX */
    request_lookup[CONTROLLER_CLEAR_ERRORS_TX].msg.Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[CONTROLLER_CLEAR_ERRORS_TX].msg.Id = 0x201;
    request_lookup[CONTROLLER_CLEAR_ERRORS_TX].msg.Size = 3;
    request_lookup[CONTROLLER_CLEAR_ERRORS_TX].msg.Data[0] = 0x3D;
    request_lookup[CONTROLLER_CLEAR_ERRORS_TX].msg.Data[1] = 0x8E;
    request_lookup[CONTROLLER_CLEAR_ERRORS_TX].msg.Data[2] = 0x00;
    request_lookup[CONTROLLER_CLEAR_ERRORS_TX].expect_response = false;
}

/* This function initializes the response_lookup array with CAN messages
 * to be received during the run. This function must run during startup before any
 * CAN messages are received.
 *
 * Params:
 *     void
 * 
 * Returns:
 *     void
 */
void init_can_responses() {
    /* BMS_PACK_RX */
    response_lookup[BMS_PACK_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[BMS_PACK_RX].msg.Id = 0x301;
    response_lookup[BMS_PACK_RX].msg.Size = 0;
    response_lookup[BMS_PACK_RX].handler = bms_pack_handler;
    response_lookup[BMS_PACK_RX].request_num = -1;
    
    /* BMS_OTHER_RX */
    response_lookup[BMS_OTHER_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[BMS_OTHER_RX].msg.Id = 0x302;
    response_lookup[BMS_OTHER_RX].msg.Size = 0;
    response_lookup[BMS_OTHER_RX].handler = bms_other_handler;
    response_lookup[BMS_OTHER_RX].request_num = -1;
    
    /* BMS_ERROR_RX */
    response_lookup[BMS_ERROR_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[BMS_ERROR_RX].msg.Id = 0x303;
    response_lookup[BMS_ERROR_RX].msg.Size = 0;
    response_lookup[BMS_ERROR_RX].handler = bms_error_handler;
    response_lookup[BMS_ERROR_RX].request_num = -1;
    
    /* ISO_STATE_RX */
    response_lookup[ISO_STATE_RX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    response_lookup[ISO_STATE_RX].msg.Id = 0xA100100;
    response_lookup[ISO_STATE_RX].msg.Size = 1;
    response_lookup[ISO_STATE_RX].msg.Data[0] = 0xE0;
    response_lookup[ISO_STATE_RX].handler = iso_state_handler;
    response_lookup[ISO_STATE_RX].request_num = ISO_STATE_TX;
    
    /* ISO_RESISTANCE_RX */
    response_lookup[ISO_RESISTANCE_RX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    response_lookup[ISO_RESISTANCE_RX].msg.Id = 0xA100100;
    response_lookup[ISO_RESISTANCE_RX].msg.Size = 1;
    response_lookup[ISO_RESISTANCE_RX].msg.Data[0] = 0xE1;
    response_lookup[ISO_RESISTANCE_RX].handler = iso_resistance_handler;
    response_lookup[ISO_RESISTANCE_RX].request_num = ISO_RESISTANCE_TX;
    
    /* ISO_ERROR_RX */
    response_lookup[ISO_ERROR_RX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    response_lookup[ISO_ERROR_RX].msg.Id = 0xA100100;
    response_lookup[ISO_ERROR_RX].msg.Size = 1;
    response_lookup[ISO_ERROR_RX].msg.Data[0] = 0xE5;
    response_lookup[ISO_ERROR_RX].handler = iso_error_handler;
    response_lookup[ISO_ERROR_RX].request_num = ISO_ERROR_TX;
    
    /* LIPO_VOLTAGE_RX */
    response_lookup[LIPO_VOLTAGE_RX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    response_lookup[LIPO_VOLTAGE_RX].msg.Id = 0xA100100;
    response_lookup[LIPO_VOLTAGE_RX].msg.Size = 1;
    response_lookup[LIPO_VOLTAGE_RX].msg.Data[0] = 0xE4;
    response_lookup[LIPO_VOLTAGE_RX].handler = lipo_handler;
    response_lookup[LIPO_VOLTAGE_RX].request_num = LIPO_VOLTAGE_TX;
    
    /* READY_TO_TRANSMIT_RX */
    response_lookup[READY_TO_TRANSMIT_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Id = 0x181;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Size = 4;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Data[0] = 0xE2;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Data[1] = 0x01;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Data[2] = 0x00;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Data[3] = 0x00;
    response_lookup[READY_TO_TRANSMIT_RX].handler = ready_to_transmit_handler;
    response_lookup[READY_TO_TRANSMIT_RX].request_num = READY_TO_TRANSMIT_TX;
    
    /* TRANSMIT_ENABLE_RX */
    response_lookup[TRANSMIT_ENABLE_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Id = 0x181;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Size = 4;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Data[0] = 0xE8;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Data[1] = 0x01;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Data[2] = 0x00;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Data[3] = 0x00;
    response_lookup[TRANSMIT_ENABLE_RX].handler = transmit_enable_handler;
    response_lookup[TRANSMIT_ENABLE_RX].request_num = TRANSMIT_ENABLE_TX;
    
    /* MAX_SPEED_RX */
    response_lookup[MAX_SPEED_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[MAX_SPEED_RX].msg.Id = 0x181;
    response_lookup[MAX_SPEED_RX].msg.Size = 1;
    response_lookup[MAX_SPEED_RX].msg.Data[0] = 0xCE;
    response_lookup[MAX_SPEED_RX].handler = max_speed_handler;
    response_lookup[MAX_SPEED_RX].request_num = MAX_SPEED_TX;
    
    /* DEVICE_CURRENT_RX */
    response_lookup[DEVICE_CURRENT_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[DEVICE_CURRENT_RX].msg.Id = 0x181;
    response_lookup[DEVICE_CURRENT_RX].msg.Size = 1;
    response_lookup[DEVICE_CURRENT_RX].msg.Data[0] = 0xC6;
    response_lookup[DEVICE_CURRENT_RX].handler = device_current_handler;
    response_lookup[DEVICE_CURRENT_RX].request_num = DEVICE_CURRENT_TX;
    
    /* CURRENT_200PC_RX */
    response_lookup[CURRENT_200PC_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[CURRENT_200PC_RX].msg.Id = 0x181;
    response_lookup[CURRENT_200PC_RX].msg.Size = 1;
    response_lookup[CURRENT_200PC_RX].msg.Data[0] = 0xD9;
    response_lookup[CURRENT_200PC_RX].handler = current_200pc_handler;
    response_lookup[CURRENT_200PC_RX].request_num = CURRENT_200PC_TX;
    
    /* ACTUAL_SPEED_RX */
    response_lookup[ACTUAL_SPEED_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[ACTUAL_SPEED_RX].msg.Id = 0x181;
    response_lookup[ACTUAL_SPEED_RX].msg.Size = 1;
    response_lookup[ACTUAL_SPEED_RX].msg.Data[0] = 0x30;
    response_lookup[ACTUAL_SPEED_RX].handler = actual_speed_handler;
    response_lookup[ACTUAL_SPEED_RX].request_num = -1;
    
    /* ACTUAL_CURRENT_RX */
    response_lookup[ACTUAL_CURRENT_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[ACTUAL_CURRENT_RX].msg.Id = 0x181;
    response_lookup[ACTUAL_CURRENT_RX].msg.Size = 1;
    response_lookup[ACTUAL_CURRENT_RX].msg.Data[0] = 0x20;
    response_lookup[ACTUAL_CURRENT_RX].handler = actual_current_handler;
    response_lookup[ACTUAL_CURRENT_RX].request_num = -1;
    
    /* ACTUAL_POSITION_RX */
    response_lookup[ACTUAL_POSITION_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[ACTUAL_POSITION_RX].msg.Id = 0x181;
    response_lookup[ACTUAL_POSITION_RX].msg.Size = 1;
    response_lookup[ACTUAL_POSITION_RX].msg.Data[0] = 0x6E;
    response_lookup[ACTUAL_POSITION_RX].handler = actual_position_handler;
    response_lookup[ACTUAL_POSITION_RX].request_num = -1;
    
    /* CONTROLLER_VOLT_RX */
    response_lookup[CONTROLLER_VOLT_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[CONTROLLER_VOLT_RX].msg.Id = 0x181;
    response_lookup[CONTROLLER_VOLT_RX].msg.Size = 1;
    response_lookup[CONTROLLER_VOLT_RX].msg.Data[0] = 0xEB;
    response_lookup[CONTROLLER_VOLT_RX].handler = controller_volt_handler;
    response_lookup[CONTROLLER_VOLT_RX].request_num = CONTROLLER_VOLT_TX;
    
    /* CONTROLLER_ERROR_RX */
    response_lookup[CONTROLLER_ERROR_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[CONTROLLER_ERROR_RX].msg.Id = 0x181;
    response_lookup[CONTROLLER_ERROR_RX].msg.Size = 1;
    response_lookup[CONTROLLER_ERROR_RX].msg.Data[0] = 0x8F;
    response_lookup[CONTROLLER_ERROR_RX].handler = controller_errors_handler;
    response_lookup[CONTROLLER_ERROR_RX].request_num = -1;
    
    /* CONTROLLER_STATUS_RX */
    response_lookup[CONTROLLER_STATUS_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[CONTROLLER_STATUS_RX].msg.Id = 0x181;
    response_lookup[CONTROLLER_STATUS_RX].msg.Size = 1;
    response_lookup[CONTROLLER_STATUS_RX].msg.Data[0] = 0x40;
    response_lookup[CONTROLLER_STATUS_RX].handler = controller_errors_handler;
    response_lookup[CONTROLLER_STATUS_RX].request_num = CONTROLLER_STATUS_TX;
}

