#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "can_init.h"
#include "can_handlers.h"
#include "can_master.h"
#include "vs_can_api.h"


/* This function intializes a connection to the NetCAN device.
 * This function must run successfully before any CAN messages are
 * sent or received.
 *
 * Params:
 *     void
 *
 * Returns:
 *      0 -> success
 *     -1 -> VSCAN_Open failure
 *     -2 -> bitrate configuration failure
 */
int can_init(CAN_Data *data) {
    handle = -1;
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
    //TODO
}

void init_can_data(CAN_Data *data) {
    /* Init response fields */
    int i;
    
    for (i = 0; i < NUM_CAN_RESPONSES; i++) {
        STORE(data->responses[i].rx_count, 0)
        STORE(data->responses[i].last_time.tv_sec, 0)
        STORE(data->responses[i].last_time.tv_nsec, 0)
        STORE(data->responses[i].check_timeout, false)
         
        /* Configure timeout per message */
        switch (i) {
            case BMS_PACK_RX:
            case BMS_OTHER_RX:
            case BMS_ERROR_RX:
                /* 300ms timeout */
                STORE(data->responses[i].timeout_interval.tv_sec, 0L)
                STORE(data->responses[i].timeout_interval.tv_nsec, 300000000L)
                break;
            
            case ISO_STATE_RX:
            case ISO_RESISTANCE_RX:
            case ISO_ERROR_RX:
            case LIPO_VOLTAGE_RX:
                /* 1.5sec timeout */
                STORE(data->responses[i].timeout_interval.tv_sec, 1L)
                STORE(data->responses[i].timeout_interval.tv_nsec, 500000000L)
                break;
            
            case ACTUAL_SPEED_RX:
            case ACTUAL_CURRENT_RX:
            case ACTUAL_POSITION_RX:
                /* 10ms timeout */
                STORE(data->responses[i].timeout_interval.tv_sec, 0L)
                STORE(data->responses[i].timeout_interval.tv_nsec, 10000000L)
                break;
            
            default: 
                /* No timeout */
                STORE(data->responses[i].timeout_interval.tv_sec, LONG_MAX)
                STORE(data->responses[i].timeout_interval.tv_nsec, 999999999L)
        }
    }
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
    request_lookup[ISO_STATE_TX].Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[ISO_STATE_TX].Id = 0xA100101;
    request_lookup[ISO_STATE_TX].Size = 1;
    request_lookup[ISO_STATE_TX].Data[0] = 0xE0;
    
    /* ISO_RESISTANCE_TX */
    request_lookup[ISO_RESISTANCE_TX].Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[ISO_RESISTANCE_TX].Id = 0xA100101;
    request_lookup[ISO_RESISTANCE_TX].Size = 1;
    request_lookup[ISO_RESISTANCE_TX].Data[0] = 0xE1;
    
    /* ISO_ERROR_TX */
    request_lookup[ISO_ERROR_TX].Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[ISO_ERROR_TX].Id = 0xA100101;
    request_lookup[ISO_ERROR_TX].Size = 1;
    request_lookup[ISO_ERROR_TX].Data[0] = 0xE5;
    
    /* LIPO_VOLTAGE_TX */
    request_lookup[LIPO_VOLTAGE_TX].Flags = VSCAN_FLAGS_EXTENDED;
    request_lookup[LIPO_VOLTAGE_TX].Id = 0xA100101;
    request_lookup[LIPO_VOLTAGE_TX].Size = 1;
    request_lookup[LIPO_VOLTAGE_TX].Data[0] = 0xE4;
    
    /* READY_TO_TRANSMIT_TX */
    request_lookup[READY_TO_TRANSMIT_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[READY_TO_TRANSMIT_TX].Id = 0x201;
    request_lookup[READY_TO_TRANSMIT_TX].Size = 3;
    request_lookup[READY_TO_TRANSMIT_TX].Data[0] = 0x3D;
    request_lookup[READY_TO_TRANSMIT_TX].Data[1] = 0xE2;
    request_lookup[READY_TO_TRANSMIT_TX].Data[2] = 0x00;
    
    /* DISABLE_MOTOR_TX */
    request_lookup[DISABLE_MOTOR_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[DISABLE_MOTOR_TX].Id = 0x201;
    request_lookup[DISABLE_MOTOR_TX].Size = 3;
    request_lookup[DISABLE_MOTOR_TX].Data[0] = 0x51;
    request_lookup[DISABLE_MOTOR_TX].Data[1] = 0x04;
    request_lookup[DISABLE_MOTOR_TX].Data[2] = 0x00;
    
    /* ENABLE_MOTOR_TX */
    request_lookup[ENABLE_MOTOR_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ENABLE_MOTOR_TX].Id = 0x201;
    request_lookup[ENABLE_MOTOR_TX].Size = 3;
    request_lookup[ENABLE_MOTOR_TX].Data[0] = 0x51;
    request_lookup[ENABLE_MOTOR_TX].Data[1] = 0x00;
    request_lookup[ENABLE_MOTOR_TX].Data[2] = 0x00;
    
    /* TRANSMIT_ENABLE_TX */
    request_lookup[TRANSMIT_ENABLE_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[TRANSMIT_ENABLE_TX].Id = 0x201;
    request_lookup[TRANSMIT_ENABLE_TX].Size = 3;
    request_lookup[TRANSMIT_ENABLE_TX].Data[0] = 0x3D;
    request_lookup[TRANSMIT_ENABLE_TX].Data[1] = 0xE8;
    request_lookup[TRANSMIT_ENABLE_TX].Data[2] = 0x00;
    
    /* ACCEL_RAMP_TX */
    request_lookup[ACCEL_RAMP_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACCEL_RAMP_TX].Id = 0x201;
    request_lookup[ACCEL_RAMP_TX].Size = 3;
    request_lookup[ACCEL_RAMP_TX].Data[0] = 0x35;
    request_lookup[ACCEL_RAMP_TX].Data[1] = 0xF4;
    request_lookup[ACCEL_RAMP_TX].Data[2] = 0x01;
    
    /* DECEL_RAMP_TX */
    request_lookup[DECEL_RAMP_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[DECEL_RAMP_TX].Id = 0x201;
    request_lookup[DECEL_RAMP_TX].Size = 3;
    request_lookup[DECEL_RAMP_TX].Data[0] = 0xED;
    request_lookup[DECEL_RAMP_TX].Data[1] = 0xE8;
    request_lookup[DECEL_RAMP_TX].Data[2] = 0x03;
    
    /* STOP_MOTOR_TX */
    request_lookup[STOP_MOTOR_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[STOP_MOTOR_TX].Id = 0x201;
    request_lookup[STOP_MOTOR_TX].Size = 3;
    request_lookup[STOP_MOTOR_TX].Data[0] = 0x31;
    request_lookup[STOP_MOTOR_TX].Data[1] = 0x00;
    request_lookup[STOP_MOTOR_TX].Data[2] = 0x00;
    
    /* SET_SPEED_TX */
    request_lookup[SET_SPEED_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[SET_SPEED_TX].Id = 0x201;
    request_lookup[SET_SPEED_TX].Size = 3;
    request_lookup[SET_SPEED_TX].Data[0] = 0x31;
    request_lookup[SET_SPEED_TX].Data[1] = 0x00;  //TODO: Percent Max Speed
    request_lookup[SET_SPEED_TX].Data[2] = 0x00;  //TODO: Percent Max Speed
    
    /* MAX_SPEED_TX */
    request_lookup[MAX_SPEED_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[MAX_SPEED_TX].Id = 0x201;
    request_lookup[MAX_SPEED_TX].Size = 3;
    request_lookup[MAX_SPEED_TX].Data[0] = 0x3D;
    request_lookup[MAX_SPEED_TX].Data[1] = 0xCE;
    request_lookup[MAX_SPEED_TX].Data[2] = 0x00;
    
    /* DEVICE_CURRENT_TX */
    request_lookup[DEVICE_CURRENT_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[DEVICE_CURRENT_TX].Id = 0x201;
    request_lookup[DEVICE_CURRENT_TX].Size = 3;
    request_lookup[DEVICE_CURRENT_TX].Data[0] = 0x3D;
    request_lookup[DEVICE_CURRENT_TX].Data[1] = 0xC6;
    request_lookup[DEVICE_CURRENT_TX].Data[2] = 0x00;
    
    /* CURRENT_200PC_TX */
    request_lookup[CURRENT_200PC_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[CURRENT_200PC_TX].Id = 0x201;
    request_lookup[CURRENT_200PC_TX].Size = 3;
    request_lookup[CURRENT_200PC_TX].Data[0] = 0x3D;
    request_lookup[CURRENT_200PC_TX].Data[1] = 0xD9;
    request_lookup[CURRENT_200PC_TX].Data[2] = 0x00;
    
    /* ACTUAL_SPEED_TX */
    request_lookup[ACTUAL_SPEED_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACTUAL_SPEED_TX].Id = 0x201;
    request_lookup[ACTUAL_SPEED_TX].Size = 3;
    request_lookup[ACTUAL_SPEED_TX].Data[0] = 0x3D;
    request_lookup[ACTUAL_SPEED_TX].Data[1] = 0x30;
    request_lookup[ACTUAL_SPEED_TX].Data[2] = 0x00;
    
    /* ACTUAL_CURRENT_TX */
    request_lookup[ACTUAL_CURRENT_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACTUAL_CURRENT_TX].Id = 0x201;
    request_lookup[ACTUAL_CURRENT_TX].Size = 3;
    request_lookup[ACTUAL_CURRENT_TX].Data[0] = 0x3D;
    request_lookup[ACTUAL_CURRENT_TX].Data[1] = 0x20;
    request_lookup[ACTUAL_CURRENT_TX].Data[2] = 0x00;
    
    /* ACTUAL_POSITION_TX */
    request_lookup[ACTUAL_POSITION_TX].Flags = VSCAN_FLAGS_STANDARD;
    request_lookup[ACTUAL_POSITION_TX].Id = 0x201;
    request_lookup[ACTUAL_POSITION_TX].Size = 3;
    request_lookup[ACTUAL_POSITION_TX].Data[0] = 0x3D;
    request_lookup[ACTUAL_POSITION_TX].Data[1] = 0x6E;
    request_lookup[ACTUAL_POSITION_TX].Data[2] = 0x00;
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
    
    /* BMS_OTHER_RX */
    response_lookup[BMS_OTHER_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[BMS_OTHER_RX].msg.Id = 0x302;
    response_lookup[BMS_OTHER_RX].msg.Size = 0;
    response_lookup[BMS_OTHER_RX].handler = bms_other_handler;
    
    /* BMS_ERROR_RX */
    response_lookup[BMS_ERROR_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[BMS_ERROR_RX].msg.Id = 0x303;
    response_lookup[BMS_ERROR_RX].msg.Size = 0;
    response_lookup[BMS_ERROR_RX].handler = bms_error_handler;
    
    /* ISO_STATE_RX */
    response_lookup[ISO_STATE_RX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    response_lookup[ISO_STATE_RX].msg.Id = 0xA100100;
    response_lookup[ISO_STATE_RX].msg.Size = 1;
    response_lookup[ISO_STATE_RX].msg.Data[0] = 0xE0;
    response_lookup[ISO_STATE_RX].handler = iso_state_handler;
    
    /* ISO_RESISTANCE_RX */
    response_lookup[ISO_RESISTANCE_RX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    response_lookup[ISO_RESISTANCE_RX].msg.Id = 0xA100100;
    response_lookup[ISO_RESISTANCE_RX].msg.Size = 1;
    response_lookup[ISO_RESISTANCE_RX].msg.Data[0] = 0xE1;
    response_lookup[ISO_RESISTANCE_RX].handler = iso_resistance_handler;
    
    /* ISO_ERROR_RX */
    response_lookup[ISO_ERROR_RX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    response_lookup[ISO_ERROR_RX].msg.Id = 0xA100100;
    response_lookup[ISO_ERROR_RX].msg.Size = 1;
    response_lookup[ISO_ERROR_RX].msg.Data[0] = 0xE5;
    response_lookup[ISO_ERROR_RX].handler = iso_error_handler;
    
    /* LIPO_VOLTAGE_RX */
    response_lookup[LIPO_VOLTAGE_RX].msg.Flags = VSCAN_FLAGS_EXTENDED;
    response_lookup[LIPO_VOLTAGE_RX].msg.Id = 0xA100100;
    response_lookup[LIPO_VOLTAGE_RX].msg.Size = 1;
    response_lookup[LIPO_VOLTAGE_RX].msg.Data[0] = 0xE4;
    response_lookup[LIPO_VOLTAGE_RX].handler = lipo_handler;
    
    /* READY_TO_TRANSMIT_RX */
    response_lookup[READY_TO_TRANSMIT_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Id = 0x181;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Size = 4;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Data[0] = 0xE2;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Data[0] = 0x01;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Data[0] = 0x00;
    response_lookup[READY_TO_TRANSMIT_RX].msg.Data[0] = 0x00;
    response_lookup[READY_TO_TRANSMIT_RX].handler = ready_to_transmit_handler;
    
    /* TRANSMIT_ENABLE_RX */
    response_lookup[TRANSMIT_ENABLE_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Id = 0x181;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Size = 4;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Data[0] = 0xE8;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Data[0] = 0x01;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Data[0] = 0x00;
    response_lookup[TRANSMIT_ENABLE_RX].msg.Data[0] = 0x00;
    response_lookup[TRANSMIT_ENABLE_RX].handler = transmit_enable_handler;
    
    /* MAX_SPEED_RX */
    response_lookup[MAX_SPEED_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[MAX_SPEED_RX].msg.Id = 0x181;
    response_lookup[MAX_SPEED_RX].msg.Size = 1;
    response_lookup[MAX_SPEED_RX].msg.Data[0] = 0xCE;
    response_lookup[MAX_SPEED_RX].handler = max_speed_handler;
    
    /* DEVICE_CURRENT_RX */
    response_lookup[DEVICE_CURRENT_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[DEVICE_CURRENT_RX].msg.Id = 0x181;
    response_lookup[DEVICE_CURRENT_RX].msg.Size = 1;
    response_lookup[DEVICE_CURRENT_RX].msg.Data[0] = 0xC6;
    response_lookup[DEVICE_CURRENT_RX].handler = device_current_handler;
    
    /* CURRENT_200PC_RX */
    response_lookup[CURRENT_200PC_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[CURRENT_200PC_RX].msg.Id = 0x181;
    response_lookup[CURRENT_200PC_RX].msg.Size = 1;
    response_lookup[CURRENT_200PC_RX].msg.Data[0] = 0xD9;
    response_lookup[CURRENT_200PC_RX].handler = current_200pc_handler;
    
    /* ACTUAL_SPEED_RX */
    response_lookup[ACTUAL_SPEED_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[ACTUAL_SPEED_RX].msg.Id = 0x181;
    response_lookup[ACTUAL_SPEED_RX].msg.Size = 1;
    response_lookup[ACTUAL_SPEED_RX].msg.Data[0] = 0x30;
    response_lookup[ACTUAL_SPEED_RX].handler = actual_speed_handler;
    
    /* ACTUAL_CURRENT_RX */
    response_lookup[ACTUAL_CURRENT_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[ACTUAL_CURRENT_RX].msg.Id = 0x181;
    response_lookup[ACTUAL_CURRENT_RX].msg.Size = 1;
    response_lookup[ACTUAL_CURRENT_RX].msg.Data[0] = 0x20;
    response_lookup[ACTUAL_CURRENT_RX].handler = actual_current_handler;
    
    /* ACTUAL_POSITION_RX */
    response_lookup[ACTUAL_POSITION_RX].msg.Flags = VSCAN_FLAGS_STANDARD;
    response_lookup[ACTUAL_POSITION_RX].msg.Id = 0x181;
    response_lookup[ACTUAL_POSITION_RX].msg.Size = 1;
    response_lookup[ACTUAL_POSITION_RX].msg.Data[0] = 0x6E;
    response_lookup[ACTUAL_POSITION_RX].handler = actual_position_handler;
}

