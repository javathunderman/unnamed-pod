#include "vs_can_api.h"
#include "can_handlers.h"


/* This function updates state machine's CAN_Data with:
 *     Pack State of Charge
 *     Pack Voltage
 *     Pack Current
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void bms_pack_handler(VSCAN_MSG *msg, CAN_Data *data) {
    short pack_soc     = *((short *) (&(msg->Data[0])));
    short pack_voltage = *((short *) (&(msg->Data[2])));
    short pack_current = *((short *) (&(msg->Data[4])));
    
    __atomic_store_n(&(data->pack_soc), pack_soc, __ATOMIC_RELAXED);
    __atomic_store_n(&(data->pack_voltage), pack_voltage, __ATOMIC_RELAXED);
    __atomic_store_n(&(data->pack_current), pack_current, __ATOMIC_RELAXED);
}
