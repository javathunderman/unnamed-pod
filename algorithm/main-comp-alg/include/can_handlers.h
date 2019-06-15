#ifndef CAN_HANDLERS_H
#define CAN_HANDLERS_H

#include "vs_can_api.h"

/* This struct holds data received from CAN devices to be used
 * by the state machine.
 * 
 * IMPORTANT: Every load/store using this struct must use
 * gcc atomics to guarantee correctness of simultaneous
 * thread access.
 */
typedef struct {
    volatile short pack_soc;               /* Percent         */
    volatile short pack_voltage;           /* deci-Volts      */
    volatile short pack_current;           /* deci-Amps       */
} CAN_Data;


/* CAN Receive Handler Functions */
void bms_pack_handler(VSCAN_MSG *msg, CAN_Data *data);
void bms_other_handler(VSCAN_MSG *msg, CAN_Data *data);
void bms_error_handler(VSCAN_MSG *msg, CAN_Data *data);
void iso_state_handler(VSCAN_MSG *msg, CAN_Data *data);
void iso_resistance_handler(VSCAN_MSG *msg, CAN_Data *data);
void iso_error_handler(VSCAN_MSG *msg, CAN_Data *data);
void lipo_handler(VSCAN_MSG *msg, CAN_Data *data);
void max_speed_handler(VSCAN_MSG *msg, CAN_Data *data);
void device_current_handler(VSCAN_MSG *msg, CAN_Data *data);
void current_200pc_handler(VSCAN_MSG *msg, CAN_Data *data);
void true_speed_handler(VSCAN_MSG *msg, CAN_Data *data);
void true_current_handler(VSCAN_MSG *msg, CAN_Data *data);
void true_position_handler(VSCAN_MSG *msg, CAN_Data *data);

#endif