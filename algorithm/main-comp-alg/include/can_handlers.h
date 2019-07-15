#ifndef CAN_HANDLERS_H
#define CAN_HANDLERS_H

#include "vs_can_api.h"
#include "can_master.h"


/* CAN Receive Handler Functions */
void bms_pack_handler(VSCAN_MSG *msg, CAN_Data *data);
void bms_other_handler(VSCAN_MSG *msg, CAN_Data *data);
void bms_error_handler(VSCAN_MSG *msg, CAN_Data *data);
void iso_state_handler(VSCAN_MSG *msg, CAN_Data *data);
void iso_resistance_handler(VSCAN_MSG *msg, CAN_Data *data);
void iso_error_handler(VSCAN_MSG *msg, CAN_Data *data);
void lipo_handler(VSCAN_MSG *msg, CAN_Data *data);
void ready_to_transmit_handler(VSCAN_MSG *msg, CAN_Data *data);
void transmit_enable_handler(VSCAN_MSG *msg, CAN_Data *data);
void max_speed_handler(VSCAN_MSG *msg, CAN_Data *data);
void device_current_handler(VSCAN_MSG *msg, CAN_Data *data);
void current_200pc_handler(VSCAN_MSG *msg, CAN_Data *data);
void actual_speed_handler(VSCAN_MSG *msg, CAN_Data *data);
void actual_current_handler(VSCAN_MSG *msg, CAN_Data *data);
void actual_position_handler(VSCAN_MSG *msg, CAN_Data *data);
void controller_volt_handler(VSCAN_MSG *msg, CAN_Data *data);
void controller_errors_handler(VSCAN_MSG *msg, CAN_Data *data);
void controller_status_handler(VSCAN_MSG *msg, CAN_Data *data);


#endif
