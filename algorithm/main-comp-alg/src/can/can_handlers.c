#include "vs_can_api.h"
#include "can_handlers.h"
#include "can_master.h"


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
/* This function updates state machine's CAN_Data with:
 *     Pack Minimum voltage
 *     Pack Maximum Voltage
 *     Pack Average Temperature
 *     Pack Highest Temperature
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void bms_other_handler(VSCAN_MSG *msg, CAN_Data *data){
	short min_vol = *((short *) (&(msg->Data[0])));
	short max_vol = *((short *) (&(msg->Data[2])));
	short avg_temp = *((short *) (&(msg->Data[4])));
	short high_temp = *((short *) (&(msg->Data[6])));

	__atomic_store_n(&(data->min_vol), min_vol, __ATOMIC_RELAXED);
	__atomic_store_n(&(data->max_vol), max_vol, __ATOMIC_RELAXED);
	__atomic_store_n(&(data->avg_temp), avg_temp, __ATOMIC_RELAXED);
	__atomic_store_n(&(data->high_temp), high_temp, __ATOMIC_RELAXED);

}

/* This function updates state machine's CAN_Data with:
 *     Pack Failsafe Status
 *     Pack DTC Flags #1
 *     Pack DTC Flags #2
 *     Pack Rolling Counter
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */

void bms_error_handler(VSCAN_MSG *msg, CAN_Data *data){
	short failsafe_status = *((short *) (&(msg->Data[0])));
	short dtc_flags_1 = *((short *) (&(msg->Data[1])));
	short dtc_flags_2 = *((short *) (&(msg->Data[2])));
	short rolling_counter = *((short *) (&(msg->Data[4])));

	__atomic_store_n(&(data->failsafe_status), failsafe_status, __ATOMIC_RELAXED);
	__atomic_store_n(&(data->dtc_flags_1), dtc_flags_1, __ATOMIC_RELAXED);
	__atomic_store_n(&(data->dtc_flags_2), dtc_flags_2, __ATOMIC_RELAXED);
	__atomic_store_n(&(data->rolling_counter), rolling_counter, __ATOMIC_RELAXED);

}
/*NOT FINISHED*/
/* This function updates state machine's CAN_Data with:
 *     Pack Status Flags
 *     Pack Electrical Isolation (ohm/vol)
 *     
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void iso_state_handler(VSCAN_MSG *msg, CAN_Data *data){
	short status_flags = *((short *) (&(msg->Data[0])));
	short electrical_isolation = *((short *) (&(msg->Data[1])));
	short uncertainty_1 = *((short *) (&(msg->Data[3])));
	short energy_stored = *((short *) (&(msg->Data[5])));
	short uncertainty_2 = *((short *) (&(msg->Data[7])));


}

