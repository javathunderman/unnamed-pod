#include "vs_can_api.h"
#include "can_handlers.h"
#include "can_master.h"

/* Used internally to set isolation monitor status bits */
static void set_status_bits(CAN_Data *data, char status_flags);


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
    
    STORE(data->pack_soc, pack_soc)
    STORE(data->pack_voltage, pack_voltage)
    STORE(data->pack_current, pack_current)
}


/* This function updates state machine's CAN_Data with:
 *     Minimum voltage
 *     Maximum Voltage
 *     Average Temperature
 *     Highest Temperature
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void bms_other_handler(VSCAN_MSG *msg, CAN_Data *data){
    short min_voltage = *((short *) (&(msg->Data[0])));
    short max_voltage = *((short *) (&(msg->Data[2])));
    short avg_temp = *((short *) (&(msg->Data[4])));
    short high_temp = *((short *) (&(msg->Data[6])));

    STORE(data->min_voltage, min_voltage)
    STORE(data->max_voltage, max_voltage)
    STORE(data->avg_temp, avg_temp)
    STORE(data->high_temp, high_temp)

}



/* This function updates state machine's CAN_Data with:
 *     Failsafe Status
 *     DTC Flags #1
 *     DTC Flags #2
 *     Rolling Counter
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void bms_error_handler(VSCAN_MSG *msg, CAN_Data *data){
    char failsafe_status = *((short *) (&(msg->Data[0])));
    char dtc_flags_1 = *((short *) (&(msg->Data[1])));
    short dtc_flags_2 = *((short *) (&(msg->Data[2])));
    short rolling_counter = *((short *) (&(msg->Data[4])));

    STORE(data->failsafe_status, failsafe_status)
    STORE(data->dtc_flags_1, dtc_flags_1)
    STORE(data->dtc_flags_2, dtc_flags_2)
    STORE(data->rolling_counter, rolling_counter)

}




/* This function updates state machine's CAN_Data with:
 *     Status Flags
 *     Electrical Isolation (ohm/vol)
 *     Electrical Isolation Uncertainty
 *     Energy Stored
 *     Energy Stored Uncertainty
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void iso_state_handler(VSCAN_MSG *msg, CAN_Data *data){
    char status_flags = *((short *) (&(msg->Data[1])));
    short electrical_isolation = *((short *) (&(msg->Data[2])));
    char electrical_isolation_uncert = *((short *) (&(msg->Data[4])));
    short energy_stored = *((short *) (&(msg->Data[5])));
    char energy_stored_uncert = *((short *) (&(msg->Data[7])));

    set_status_bits(data, status_flags);
    STORE(data->electrical_isolation, electrical_isolation)
    STORE(data->electrical_isolation_uncert, electrical_isolation_uncert)
    STORE(data->energy_stored, energy_stored)
    STORE(data->energy_stored_uncert, energy_stored_uncert)

}




/* This function updates state machine's CAN_Data with:
 *     status flags
 *     rp Isolation resistance
 *     rp Isolation resistance uncertainty
 *     rn Isolation resistance
 *     rn Isolation resistance uncertainty
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void iso_resistance_handler(VSCAN_MSG *msg, CAN_Data *data){
    char status_flags = *((short *) (&(msg->Data[1])));
    short rp_iso_resistance = *((short *) (&(msg->Data[2])));
    char rp_iso_resistance_uncert = *((short *) (&(msg->Data[4])));
    short rn_iso_resistance = *((short *) (&(msg->Data[5])));
    char rn_iso_resistance_uncert = *((short *) (&(msg->Data[7])));

    set_status_bits(data, status_flags);
    STORE(data->rp_iso_resistance, rp_iso_resistance)
    STORE(data->rp_iso_resistance_uncert, rp_iso_resistance_uncert)
    STORE(data->rn_iso_resistance, rn_iso_resistance )
    STORE(data->rn_iso_resistance_uncert, rn_iso_resistance_uncert)
}




/* This function updates state machine's CAN_Data with:
 *     Pack Status Flags
 *     Pack error flags
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void iso_error_handler(VSCAN_MSG *msg, CAN_Data *data){
    char status_flags = *((short *) (&(msg->Data[1])));
    char error_flags = *((short *) (&(msg->Data[2])));

    set_status_bits(data, status_flags);
    STORE(data->error_flags, error_flags)

}




/* This function updates state machine's CAN_Data with:
 *     Pack status flags
 *     Pack battery voltage
 *     Pack battery voltage uncertainty
 *     Pack Max battery voltage
 *     Pack max battery voltage uncertainty
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void lipo_handler(VSCAN_MSG *msg, CAN_Data *data){
   char status_flags = *((short *) (&(msg->Data[1])));
   short battery_volt = *((short *) (&(msg->Data[2])));
   char battery_volt_uncert = *((short *) (&(msg->Data[4])));
   short max_battery_volt = *((short *) (&(msg->Data[5])));
   char max_battery_volt_uncert = *((short *) (&(msg->Data[7])));

   set_status_bits(data, status_flags);
   STORE(data->battery_volt, battery_volt)
   STORE(data->battery_volt_uncert, battery_volt_uncert)
   STORE(data->max_battery_volt, max_battery_volt )
   STORE(data->max_battery_volt_uncert, max_battery_volt_uncert)
}




/* This function updates state machine's CAN_Data with:
 *     Pack max speed
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void max_speed_handler(VSCAN_MSG *msg, CAN_Data *data){
   short max_speed = *((short *) (&(msg->Data[1])));
   STORE(data->max_speed, max_speed)

}




/* This function updates state machine's CAN_Data with:
 *     Pack device current
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void device_current_handler(VSCAN_MSG *msg, CAN_Data *data){
   short dev_current = *((short *) (&(msg->Data[1])));
   STORE(data->dev_current, dev_current)
}





/* This function updates state machine's CAN_Data with:
 *     Current 200pc
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void current_200pc_handler(VSCAN_MSG *msg, CAN_Data *data){
   short current_200pc = *((short *) (&(msg->Data[1])));
   STORE(data->current_200pc, current_200pc)

}




/* This function updates state machine's CAN_Data with:
 *     Percent Max Spered
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void true_speed_handler(VSCAN_MSG *msg, CAN_Data *data){
   short percent_max_speed = *((short *) (&(msg->Data[1])));
   STORE(data->percent_max_speed, percent_max_speed)

}




/* This function updates state machine's CAN_Data with:
 *     True current
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void true_current_handler(VSCAN_MSG *msg, CAN_Data *data){
   short true_current = *((short *) (&(msg->Data[1])));
   STORE(data->true_current, true_current)
}





/* This function updates state machine's CAN_Data with:
 *     Revolutions
 *
 * Params:
 *     VSCAN_MSG *msg -> pointer to received CAN message frame
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *
 * Returns:
 *     void
 */
void true_position_handler(VSCAN_MSG *msg, CAN_Data *data){
   int revolutions = *((int *) (&(msg->Data[1])));
   STORE(data->revolutions, revolutions)


}

/* This function updates the feilds of the Iso_Status_Bits struct inside CAN_Data
 *
 * Params: 
 *     CAN_Data *data -> pointer to CAN_data struct used by state machine
 *     char status_flags -> char holding the status flags from the VSCAN_MSG *msg from the caller function
 *
 * Returns:
 *     void
 */
void set_status_bits(CAN_Data *data, char status_flags) {
    STORE(data->status_bits.hardware_error, ((status_flags >> 7) & 0x0001));
    STORE(data->status_bits.no_new_estimates, ((status_flags >> 6) & 0x0001));
    STORE(data->status_bits.high_uncertainty, ((status_flags >> 5) & 0x0001));
    STORE(data->status_bits.undefined, ((status_flags >> 4) & 0x0001));
    STORE(data->status_bits.high_battery_voltage, ((status_flags >> 3) & 0x0001));
    STORE(data->status_bits.low_batter_voltage, ((status_flags >> 2) & 0x0001));
    STORE(data->status_bits.isolation_status, ((status_flags >> 1) & 0x0011));
}
