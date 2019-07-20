#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <pthread.h>
#include "abort_run.h"
#include "spacex.h"
#include "priority.h"
#include "atomics.h"
#include "states.h"
#include "run_data.h"
#include "telemetry.h"


#define PKT_LENGTH 1963
#define TLM_FREQ 20000000L
#define NS_IN_SEC 1000000000L
#define UPDATE_DELAY(name) name.tv_sec = name.tv_sec + ((name.tv_nsec + TLM_FREQ) / NS_IN_SEC);\
                           name.tv_nsec = (name.tv_nsec + TLM_FREQ) % NS_IN_SEC;
#define INIT_TIMES(name, time) sec = name.tv_sec + ((name.tv_nsec + time) / NS_IN_SEC);\
                               nsec = (name.tv_nsec + time) % NS_IN_SEC;

void *send_tlm(void *args) {
    Telemetry tlm;

    int socket = ((TelemetryArgs *)args)->socket;
    SA * dest_addr = (SA *)(&((TelemetryArgs *)args)->dest_addr);
    socklen_t dest_len = ((TelemetryArgs *)args)->dest_len;
    UMData *data = ((TelemetryArgs *)args)->data;

    const struct sched_param priority = {TLM_SEND_PRIO};
    /* Set thread priority */
    if (pthread_setschedparam(pthread_self(), SCHED_FIFO, &priority) != 0) {
        printf("Failed to set TLM thread priority\n");
        return NULL;
    }

    /* Store thread id */
    STORE(run_data.software.tlm_tid, pthread_self());

    struct timespec now;
    if(clock_gettime(CLOCK_MONOTONIC, &now) == -1) {
        ABORT_RUN;
        printf("clock_gettime() error: %s\n", strerror(errno));
        return NULL;
    }
    time_t sec = now.tv_sec;
    long nsec = now.tv_nsec;

    INIT_TIMES(now, 20000000L)
    struct timespec delay_1 = {sec, nsec};


    while (!g_shutoff) {
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &delay_1, NULL);
        update_telemetry_1_1(&tlm, data);

        if(sendto(socket, &tlm, PKT_LENGTH, 0, dest_addr, dest_len) == -1) {
            ABORT_RUN;
            printf("Telemetry sendto() error: %s\n", strerror(errno));
        }

        if(send_spacex(socket, &tlm, data) == -1) {
            ABORT_RUN;
        }

        UPDATE_DELAY(delay_1)
    }

    return NULL;
}

void update_telemetry_1_1(Telemetry *tlm, UMData *data) {
    tlm->K1_HIGH = LOAD(data->fpga_cache.HVR_1_state);
    tlm->K2_PRECHARGE = LOAD(data->fpga_cache.HVR_2_state);
    tlm->K3_LOW = LOAD(data->fpga_cache.HVR_3_state);
    tlm->K4_DISCHARGE = LOAD(data->fpga_cache.HVR_4_state);
    tlm->PRI1_ALG_SHUTOFF = LOAD(data->fpga_cache.avb_shutoff_p1_state);
    tlm->PRI2_ALG_SHUTOFF = LOAD(data->fpga_cache.avb_shutoff_p2_state);
    tlm->RES_ALG_SHUTOFF = LOAD(data->fpga_cache.avb_shutoff_r_state);
    tlm->BRAKE_STATE = LOAD(data->fpga_cache.brake_state);
    tlm->DRAIN_STATE = LOAD(data->fpga_cache.drain_valve_state);
    tlm->ENABLE_CHECKS_STATE = LOAD(data->fpga_cache.enable_checks_state);
    tlm->LED_1 = LOAD(data->fpga_cache.iso_led_1_state);
    tlm->LED_2 = LOAD(data->fpga_cache.iso_led_2_state);
    tlm->TAPE_BL_COUNT = LOAD(data->fpga_cache.light_BL_count);
    tlm->TAPE_BR_COUNT = LOAD(data->fpga_cache.light_BR_count);
    tlm->TAPE_L_COUNT = LOAD(data->fpga_cache.light_L_count);
    tlm->TAPE_R_COUNT = LOAD(data->fpga_cache.light_R_count);
    tlm->LIGHT_SENSOR_STATUS = LOAD(data->fpga_cache.light_sensor_status);
    tlm->HIGH_PRESSURE_1 = LOAD(data->fpga_cache.P_hp1);
    tlm->HIGH_PRESSURE_2 = LOAD(data->fpga_cache.P_hp2);
    tlm->LOW_PRESSURE_1 = LOAD(data->fpga_cache.P_lp1);
    tlm->LOW_PRESSURE_2 = LOAD(data->fpga_cache.P_lp2);
    tlm->PRI1_TEMP = LOAD(data->fpga_cache.T_avb_p1);
    tlm->PRI2_TEMP = LOAD(data->fpga_cache.T_avb_p2);
    tlm->RES_TEMP = LOAD(data->fpga_cache.T_avb_r);
    tlm->CRIO_TEMP = LOAD(data->fpga_cache.T_cRIO);
    tlm->EXTRA1_TEMP = LOAD(data->fpga_cache.T_extra1);
    tlm->EXTRA2_TEMP = LOAD(data->fpga_cache.T_extra2);
    tlm->PISTON1_TEMP = LOAD(data->fpga_cache.T_piston0);
    tlm->PISTON2_TEMP = LOAD(data->fpga_cache.T_piston1);
    tlm->PISTON3_TEMP = LOAD(data->fpga_cache.T_piston2);
    tlm->PISTON4_TEMP = LOAD(data->fpga_cache.T_piston3);
    tlm->PISTON5_TEMP = LOAD(data->fpga_cache.T_piston4);
    tlm->PISTON6_TEMP = LOAD(data->fpga_cache.T_piston5);
    tlm->PISTON7_TEMP = LOAD(data->fpga_cache.T_piston6);
    tlm->PISTON8_TEMP = LOAD(data->fpga_cache.T_piston7);
    tlm->TANK_TEMP = LOAD(data->fpga_cache.T_pneum);
    tlm->POD_TEMP = LOAD(data->fpga_cache.T_pod);
    tlm->BRAKE_DISTANCE = LOAD(data->fpga_cache.brake_distance);
    tlm->CUR_THRESH_MAX = LOAD(data->fpga_cache.cur_thresh_max);
    tlm->CUR_THRESH_MIN = LOAD(data->fpga_cache.cur_thresh_min);
    tlm->PRI1_CURRENT = LOAD(data->fpga_cache.current_p1);
    tlm->PRI2_CURRENT = LOAD(data->fpga_cache.current_p2);
    tlm->RES_CURRENT = LOAD(data->fpga_cache.current_r);
    tlm->POD_DISTANCE = LOAD(data->fpga_cache.fusion_distance);
    tlm->IMU_DISTANCE = LOAD(data->fpga_cache.imu_distance);
    tlm->IMU_VELOCITY = LOAD(data->fpga_cache.imu_velocity);
    tlm->MTR_DISTANCE = LOAD(data->fpga_cache.mc_distance);
    tlm->TAPE_DISTANCE = LOAD(data->fpga_cache.tape_distance);
    tlm->TAPE_VELOCITY = LOAD(data->fpga_cache.tape_velocity);
    tlm->PRI1_VOLTAGE = LOAD(data->fpga_cache.voltage_p1);
    tlm->PRI2_VOLTAGE = LOAD(data->fpga_cache.voltage_p2);
    tlm->RES_VOLTAGE = LOAD(data->fpga_cache.voltage_r);
    tlm->CUR_THRESH_PERSISTENCE = LOAD(data->fpga_cache.cur_thresh_persistence);
    tlm->CUR_THRESH_RATIO = LOAD(data->fpga_cache.cur_thresh_ratio);
    tlm->FAULT_LONG_2 = LOAD(data->fpga_cache.fault_long_2);
    tlm->FAULT_LONG_3 = LOAD(data->fpga_cache.fault_long_3);
    tlm->HARD_FAULT = LOAD(data->fpga_cache.hard_fault);
    tlm->SOFT_FAULT = LOAD(data->fpga_cache.soft_fault);
    tlm->PACK_CHARGE = LOAD(data->can_data.pack_soc);
    tlm->PACK_VOLTAGE = LOAD(data->can_data.pack_voltage);
    tlm->PACK_CURRENT = LOAD(data->can_data.pack_current);
    tlm->MIN_CELL = LOAD(data->can_data.min_voltage);
    tlm->MAX_CELL = LOAD(data->can_data.max_voltage);
    tlm->PACK_AVG_TEMP = LOAD(data->can_data.avg_temp);
    tlm->PACK_HIGH_TEMP = LOAD(data->can_data.high_temp);
    tlm->BMS_FAILSAFE_STATUS = LOAD(data->can_data.failsafe_status);
    tlm->DTC_FLAGS_1 = LOAD(data->can_data.dtc_flags_1);
    tlm->DTC_FLAGS_2 = LOAD(data->can_data.dtc_flags_2);
    tlm->ROLLING_COUNTER = LOAD(data->can_data.rolling_counter);
    tlm->ISO_STATUS_FLAGS = LOAD(data->can_data.iso_status_flags);
    tlm->ISO_ERROR_FLAGS = LOAD(data->can_data.iso_error_flags);
    tlm->ELECTRICAL_ISOLATION = LOAD(data->can_data.electrical_isolation);
    tlm->ELECTRICAL_ISOLATION_UNCERT = LOAD(data->can_data.electrical_isolation_uncert);
    tlm->ENERGY_STORED = LOAD(data->can_data.energy_stored);
    tlm->ENERGY_STORED_UNCERT = LOAD(data->can_data.energy_stored_uncert);
    tlm->HIGH_RAIL_RESISTANCE = LOAD(data->can_data.rp_iso_resistance);
    tlm->HIGH_RAIL_RESISTANCE_UNCERT = LOAD(data->can_data.rp_iso_resistance_uncert);
    tlm->LOW_RAIL_RESISTANCE = LOAD(data->can_data.rn_iso_resistance);
    tlm->LOW_RAIL_RESISTANCE_UNCERT = LOAD(data->can_data.rn_iso_resistance_uncert);
    tlm->BATTERY_VOLTAGE = LOAD(data->can_data.battery_volt);
    tlm->BATTERY_VOLTAGE_UNCERT = LOAD(data->can_data.battery_volt_uncert);
    tlm->MAX_BATTERY_VOLTAGE = LOAD(data->can_data.max_battery_volt);
    tlm->MAX_BATTERY_VOLTAGE_UNCERT = LOAD(data->can_data.max_battery_volt_uncert);
    tlm->MAX_SPEED = LOAD(data->can_data.max_speed);
    tlm->DEVICE_CURRENT = LOAD(data->can_data.dev_current);
    tlm->CURRENT_200PC = LOAD(data->can_data.current_200pc);
    tlm->PERCENT_MAX_SPEED = LOAD(data->can_data.percent_max_speed);
    tlm->TRUE_CURRENT = LOAD(data->can_data.true_current);
    tlm->REVOLUTIONS = LOAD(data->can_data.revolutions);
    tlm->CONTROLLER_BUS_VOLTAGE = LOAD(data->can_data.controller_bus_voltage);
    tlm->CONTROLLER_ERRORS = LOAD(data->can_data.controller_errors);
    tlm->CONTROLLER_STATUS = LOAD(data->can_data.controller_status);
    tlm->LEFT_ISO_STATUS_FLAGS = LOAD(data->can_data.iso_status_flags_left);
    tlm->LEFT_BATTERY_VOLTAGE = LOAD(data->can_data.battery_volt_left);
    tlm->LEFT_BATTERY_VOLTAGE_UNCERT = LOAD(data->can_data.battery_volt_uncert_left);
    tlm->LEFT_MAX_BATTERY_VOLTAGE = LOAD(data->can_data.max_battery_volt_left);
    tlm->LEFT_MAX_BATTERY_VOLTAGE_UNCERT = LOAD(data->can_data.max_battery_volt_uncert_left);
    tlm->RIGHT_ISO_STATUS_FLAGS = LOAD(data->can_data.iso_status_flags_right);
    tlm->RIGHT_BATTERY_VOLTAGE = LOAD(data->can_data.battery_volt_right);
    tlm->RIGHT_BATTERY_VOLTAGE_UNCERT = LOAD(data->can_data.battery_volt_uncert_right);
    tlm->RIGHT_MAX_BATTERY_VOLTAGE = LOAD(data->can_data.max_battery_volt_right);
    tlm->RIGHT_MAX_BATTERY_VOLTAGE_UNCERT = LOAD(data->can_data.max_battery_volt_uncert_right);
    tlm->CAN_TID = LOAD(data->software.can_tid);
    tlm->CMD_TID = LOAD(data->software.cmd_tid);
    tlm->TLM_TID = LOAD(data->software.tlm_tid);
    tlm->LAST_CMD = LOAD(data->software.last_cmd);
    tlm->POD_STATE = LOAD(data->software.pod_state);
    tlm->BMS_PACK_RX_RXCOUNT = LOAD(data->can_data.responses[0].rx_count);
    tlm->BMS_PACK_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[0].check_timeout);
    tlm->BMS_PACK_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[0].timeout_interval.tv_sec);
    tlm->BMS_PACK_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[0].timeout_interval.tv_nsec);
    tlm->BMS_PACK_RX_LAST_SEC = LOAD(data->can_data.responses[0].last_time.tv_sec);
    tlm->BMS_PACK_RX_LAST_NSEC = LOAD(data->can_data.responses[0].last_time.tv_nsec);
    tlm->BMS_OTHER_RX_RXCOUNT = LOAD(data->can_data.responses[1].rx_count);
    tlm->BMS_OTHER_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[1].check_timeout);
    tlm->BMS_OTHER_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[1].timeout_interval.tv_sec);
    tlm->BMS_OTHER_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[1].timeout_interval.tv_nsec);
    tlm->BMS_OTHER_RX_LAST_SEC = LOAD(data->can_data.responses[1].last_time.tv_sec);
    tlm->BMS_OTHER_RX_LAST_NSEC = LOAD(data->can_data.responses[1].last_time.tv_nsec);
    tlm->BMS_ERROR_RX_RXCOUNT = LOAD(data->can_data.responses[2].rx_count);
    tlm->BMS_ERROR_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[2].check_timeout);
    tlm->BMS_ERROR_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[2].timeout_interval.tv_sec);
    tlm->BMS_ERROR_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[2].timeout_interval.tv_nsec);
    tlm->BMS_ERROR_RX_LAST_SEC = LOAD(data->can_data.responses[2].last_time.tv_sec);
    tlm->BMS_ERROR_RX_LAST_NSEC = LOAD(data->can_data.responses[2].last_time.tv_nsec);
    tlm->ISO_STATE_RX_RXCOUNT = LOAD(data->can_data.responses[3].rx_count);
    tlm->ISO_STATE_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[3].check_timeout);
    tlm->ISO_STATE_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[3].timeout_interval.tv_sec);
    tlm->ISO_STATE_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[3].timeout_interval.tv_nsec);
    tlm->ISO_STATE_RX_LAST_SEC = LOAD(data->can_data.responses[3].last_time.tv_sec);
    tlm->ISO_STATE_RX_LAST_NSEC = LOAD(data->can_data.responses[3].last_time.tv_nsec);
    tlm->ISO_RESISTANCE_RX_RXCOUNT = LOAD(data->can_data.responses[4].rx_count);
    tlm->ISO_RESISTANCE_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[4].check_timeout);
    tlm->ISO_RESISTANCE_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[4].timeout_interval.tv_sec);
    tlm->ISO_RESISTANCE_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[4].timeout_interval.tv_nsec);
    tlm->ISO_RESISTANCE_RX_LAST_SEC = LOAD(data->can_data.responses[4].last_time.tv_sec);
    tlm->ISO_RESISTANCE_RX_LAST_NSEC = LOAD(data->can_data.responses[4].last_time.tv_nsec);
    tlm->ISO_ERROR_RX_RXCOUNT = LOAD(data->can_data.responses[5].rx_count);
    tlm->ISO_ERROR_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[5].check_timeout);
    tlm->ISO_ERROR_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[5].timeout_interval.tv_sec);
    tlm->ISO_ERROR_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[5].timeout_interval.tv_nsec);
    tlm->ISO_ERROR_RX_LAST_SEC = LOAD(data->can_data.responses[5].last_time.tv_sec);
    tlm->ISO_ERROR_RX_LAST_NSEC = LOAD(data->can_data.responses[5].last_time.tv_nsec);
    tlm->LIPO_VOLTAGE_RX_RXCOUNT = LOAD(data->can_data.responses[6].rx_count);
    tlm->LIPO_VOLTAGE_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[6].check_timeout);
    tlm->LIPO_VOLTAGE_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[6].timeout_interval.tv_sec);
    tlm->LIPO_VOLTAGE_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[6].timeout_interval.tv_nsec);
    tlm->LIPO_VOLTAGE_RX_LAST_SEC = LOAD(data->can_data.responses[6].last_time.tv_sec);
    tlm->LIPO_VOLTAGE_RX_LAST_NSEC = LOAD(data->can_data.responses[6].last_time.tv_nsec);
    tlm->READY_TO_TRANSMIT_RX_RXCOUNT = LOAD(data->can_data.responses[7].rx_count);
    tlm->READY_TO_TRANSMIT_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[7].check_timeout);
    tlm->READY_TO_TRANSMIT_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[7].timeout_interval.tv_sec);
    tlm->READY_TO_TRANSMIT_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[7].timeout_interval.tv_nsec);
    tlm->READY_TO_TRANSMIT_RX_LAST_SEC = LOAD(data->can_data.responses[7].last_time.tv_sec);
    tlm->READY_TO_TRANSMIT_RX_LAST_NSEC = LOAD(data->can_data.responses[7].last_time.tv_nsec);
    tlm->TRANSMIT_ENABLE_RX_RXCOUNT = LOAD(data->can_data.responses[8].rx_count);
    tlm->TRANSMIT_ENABLE_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[8].check_timeout);
    tlm->TRANSMIT_ENABLE_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[8].timeout_interval.tv_sec);
    tlm->TRANSMIT_ENABLE_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[8].timeout_interval.tv_nsec);
    tlm->TRANSMIT_ENABLE_RX_LAST_SEC = LOAD(data->can_data.responses[8].last_time.tv_sec);
    tlm->TRANSMIT_ENABLE_RX_LAST_NSEC = LOAD(data->can_data.responses[8].last_time.tv_nsec);
    tlm->MAX_SPEED_RX_RXCOUNT = LOAD(data->can_data.responses[9].rx_count);
    tlm->MAX_SPEED_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[9].check_timeout);
    tlm->MAX_SPEED_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[9].timeout_interval.tv_sec);
    tlm->MAX_SPEED_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[9].timeout_interval.tv_nsec);
    tlm->MAX_SPEED_RX_LAST_SEC = LOAD(data->can_data.responses[9].last_time.tv_sec);
    tlm->MAX_SPEED_RX_LAST_NSEC = LOAD(data->can_data.responses[9].last_time.tv_nsec);
    tlm->DEVICE_CURRENT_RX_RXCOUNT = LOAD(data->can_data.responses[10].rx_count);
    tlm->DEVICE_CURRENT_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[10].check_timeout);
    tlm->DEVICE_CURRENT_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[10].timeout_interval.tv_sec);
    tlm->DEVICE_CURRENT_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[10].timeout_interval.tv_nsec);
    tlm->DEVICE_CURRENT_RX_LAST_SEC = LOAD(data->can_data.responses[10].last_time.tv_sec);
    tlm->DEVICE_CURRENT_RX_LAST_NSEC = LOAD(data->can_data.responses[10].last_time.tv_nsec);
    tlm->CURRENT_200PC_RX_RXCOUNT = LOAD(data->can_data.responses[11].rx_count);
    tlm->CURRENT_200PC_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[11].check_timeout);
    tlm->CURRENT_200PC_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[11].timeout_interval.tv_sec);
    tlm->CURRENT_200PC_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[11].timeout_interval.tv_nsec);
    tlm->CURRENT_200PC_RX_LAST_SEC = LOAD(data->can_data.responses[11].last_time.tv_sec);
    tlm->CURRENT_200PC_RX_LAST_NSEC = LOAD(data->can_data.responses[11].last_time.tv_nsec);
    tlm->ACTUAL_SPEED_RX_RXCOUNT = LOAD(data->can_data.responses[12].rx_count);
    tlm->ACTUAL_SPEED_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[12].check_timeout);
    tlm->ACTUAL_SPEED_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[12].timeout_interval.tv_sec);
    tlm->ACTUAL_SPEED_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[12].timeout_interval.tv_nsec);
    tlm->ACTUAL_SPEED_RX_LAST_SEC = LOAD(data->can_data.responses[12].last_time.tv_sec);
    tlm->ACTUAL_SPEED_RX_LAST_NSEC = LOAD(data->can_data.responses[12].last_time.tv_nsec);
    tlm->ACTUAL_CURRENT_RX_RXCOUNT = LOAD(data->can_data.responses[13].rx_count);
    tlm->ACTUAL_CURRENT_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[13].check_timeout);
    tlm->ACTUAL_CURRENT_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[13].timeout_interval.tv_sec);
    tlm->ACTUAL_CURRENT_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[13].timeout_interval.tv_nsec);
    tlm->ACTUAL_CURRENT_RX_LAST_SEC = LOAD(data->can_data.responses[13].last_time.tv_sec);
    tlm->ACTUAL_CURRENT_RX_LAST_NSEC = LOAD(data->can_data.responses[13].last_time.tv_nsec);
    tlm->ACTUAL_POSITION_RX_RXCOUNT = LOAD(data->can_data.responses[14].rx_count);
    tlm->ACTUAL_POSITION_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[14].check_timeout);
    tlm->ACTUAL_POSITION_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[14].timeout_interval.tv_sec);
    tlm->ACTUAL_POSITION_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[14].timeout_interval.tv_nsec);
    tlm->ACTUAL_POSITION_RX_LAST_SEC = LOAD(data->can_data.responses[14].last_time.tv_sec);
    tlm->ACTUAL_POSITION_RX_LAST_NSEC = LOAD(data->can_data.responses[14].last_time.tv_nsec);
    tlm->CONTROLLER_VOLT_RX_RXCOUNT = LOAD(data->can_data.responses[15].rx_count);
    tlm->CONTROLLER_VOLT_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[15].check_timeout);
    tlm->CONTROLLER_VOLT_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[15].timeout_interval.tv_sec);
    tlm->CONTROLLER_VOLT_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[15].timeout_interval.tv_nsec);
    tlm->CONTROLLER_VOLT_RX_LAST_SEC = LOAD(data->can_data.responses[15].last_time.tv_sec);
    tlm->CONTROLLER_VOLT_RX_LAST_NSEC = LOAD(data->can_data.responses[15].last_time.tv_nsec);
    tlm->CONTROLLER_ERROR_RX_RXCOUNT = LOAD(data->can_data.responses[16].rx_count);
    tlm->CONTROLLER_ERROR_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[16].check_timeout);
    tlm->CONTROLLER_ERROR_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[16].timeout_interval.tv_sec);
    tlm->CONTROLLER_ERROR_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[16].timeout_interval.tv_nsec);
    tlm->CONTROLLER_ERROR_RX_LAST_SEC = LOAD(data->can_data.responses[16].last_time.tv_sec);
    tlm->CONTROLLER_ERROR_RX_LAST_NSEC = LOAD(data->can_data.responses[16].last_time.tv_nsec);
    tlm->CONTROLLER_STATUS_RX_RXCOUNT = LOAD(data->can_data.responses[17].rx_count);
    tlm->CONTROLLER_STATUS_RX_CHECK_TIMEOUT = LOAD(data->can_data.responses[17].check_timeout);
    tlm->CONTROLLER_STATUS_RX_TIMEOUT_SEC = LOAD(data->can_data.responses[17].timeout_interval.tv_sec);
    tlm->CONTROLLER_STATUS_RX_TIMEOUT_NSEC = LOAD(data->can_data.responses[17].timeout_interval.tv_nsec);
    tlm->CONTROLLER_STATUS_RX_LAST_SEC = LOAD(data->can_data.responses[17].last_time.tv_sec);
    tlm->CONTROLLER_STATUS_RX_LAST_NSEC = LOAD(data->can_data.responses[17].last_time.tv_nsec);
    tlm->ISO_STATE_TX_STATE = LOAD(data->can_data.requests[0].state);
    tlm->ISO_STATE_TX_TXCOUNT = LOAD(data->can_data.requests[0].tx_count);
    tlm->ISO_STATE_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[0].check_timeout);
    tlm->ISO_STATE_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[0].timeout_count);
    tlm->ISO_STATE_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[0].timeout_interval.tv_sec);
    tlm->ISO_STATE_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[0].timeout_interval.tv_nsec);
    tlm->ISO_STATE_TX_SENT_SEC = LOAD(data->can_data.requests[0].sent_time.tv_sec);
    tlm->ISO_STATE_TX_SENT_NSEC = LOAD(data->can_data.requests[0].sent_time.tv_nsec);
    tlm->ISO_RESISTANCE_TX_STATE = LOAD(data->can_data.requests[1].state);
    tlm->ISO_RESISTANCE_TX_TXCOUNT = LOAD(data->can_data.requests[1].tx_count);
    tlm->ISO_RESISTANCE_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[1].check_timeout);
    tlm->ISO_RESISTANCE_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[1].timeout_count);
    tlm->ISO_RESISTANCE_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[1].timeout_interval.tv_sec);
    tlm->ISO_RESISTANCE_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[1].timeout_interval.tv_nsec);
    tlm->ISO_RESISTANCE_TX_SENT_SEC = LOAD(data->can_data.requests[1].sent_time.tv_sec);
    tlm->ISO_RESISTANCE_TX_SENT_NSEC = LOAD(data->can_data.requests[1].sent_time.tv_nsec);
    tlm->ISO_ERROR_TX_STATE = LOAD(data->can_data.requests[2].state);
    tlm->ISO_ERROR_TX_TXCOUNT = LOAD(data->can_data.requests[2].tx_count);
    tlm->ISO_ERROR_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[2].check_timeout);
    tlm->ISO_ERROR_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[2].timeout_count);
    tlm->ISO_ERROR_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[2].timeout_interval.tv_sec);
    tlm->ISO_ERROR_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[2].timeout_interval.tv_nsec);
    tlm->ISO_ERROR_TX_SENT_SEC = LOAD(data->can_data.requests[2].sent_time.tv_sec);
    tlm->ISO_ERROR_TX_SENT_NSEC = LOAD(data->can_data.requests[2].sent_time.tv_nsec);
    tlm->LIPO_VOLTAGE_TX_STATE = LOAD(data->can_data.requests[3].state);
    tlm->LIPO_VOLTAGE_TX_TXCOUNT = LOAD(data->can_data.requests[3].tx_count);
    tlm->LIPO_VOLTAGE_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[3].check_timeout);
    tlm->LIPO_VOLTAGE_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[3].timeout_count);
    tlm->LIPO_VOLTAGE_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[3].timeout_interval.tv_sec);
    tlm->LIPO_VOLTAGE_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[3].timeout_interval.tv_nsec);
    tlm->LIPO_VOLTAGE_TX_SENT_SEC = LOAD(data->can_data.requests[3].sent_time.tv_sec);
    tlm->LIPO_VOLTAGE_TX_SENT_NSEC = LOAD(data->can_data.requests[3].sent_time.tv_nsec);
    tlm->READY_TO_TRANSMIT_TX_STATE = LOAD(data->can_data.requests[4].state);
    tlm->READY_TO_TRANSMIT_TX_TXCOUNT = LOAD(data->can_data.requests[4].tx_count);
    tlm->READY_TO_TRANSMIT_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[4].check_timeout);
    tlm->READY_TO_TRANSMIT_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[4].timeout_count);
    tlm->READY_TO_TRANSMIT_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[4].timeout_interval.tv_sec);
    tlm->READY_TO_TRANSMIT_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[4].timeout_interval.tv_nsec);
    tlm->READY_TO_TRANSMIT_TX_SENT_SEC = LOAD(data->can_data.requests[4].sent_time.tv_sec);
    tlm->READY_TO_TRANSMIT_TX_SENT_NSEC = LOAD(data->can_data.requests[4].sent_time.tv_nsec);
    tlm->DISABLE_MOTOR_TX_STATE = LOAD(data->can_data.requests[5].state);
    tlm->DISABLE_MOTOR_TX_TXCOUNT = LOAD(data->can_data.requests[5].tx_count);
    tlm->DISABLE_MOTOR_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[5].check_timeout);
    tlm->DISABLE_MOTOR_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[5].timeout_count);
    tlm->DISABLE_MOTOR_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[5].timeout_interval.tv_sec);
    tlm->DISABLE_MOTOR_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[5].timeout_interval.tv_nsec);
    tlm->DISABLE_MOTOR_TX_SENT_SEC = LOAD(data->can_data.requests[5].sent_time.tv_sec);
    tlm->DISABLE_MOTOR_TX_SENT_NSEC = LOAD(data->can_data.requests[5].sent_time.tv_nsec);
    tlm->ENABLE_MOTOR_TX_STATE = LOAD(data->can_data.requests[6].state);
    tlm->ENABLE_MOTOR_TX_TXCOUNT = LOAD(data->can_data.requests[6].tx_count);
    tlm->ENABLE_MOTOR_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[6].check_timeout);
    tlm->ENABLE_MOTOR_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[6].timeout_count);
    tlm->ENABLE_MOTOR_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[6].timeout_interval.tv_sec);
    tlm->ENABLE_MOTOR_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[6].timeout_interval.tv_nsec);
    tlm->ENABLE_MOTOR_TX_SENT_SEC = LOAD(data->can_data.requests[6].sent_time.tv_sec);
    tlm->ENABLE_MOTOR_TX_SENT_NSEC = LOAD(data->can_data.requests[6].sent_time.tv_nsec);
    tlm->TRANSMIT_ENABLE_TX_STATE = LOAD(data->can_data.requests[7].state);
    tlm->TRANSMIT_ENABLE_TX_TXCOUNT = LOAD(data->can_data.requests[7].tx_count);
    tlm->TRANSMIT_ENABLE_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[7].check_timeout);
    tlm->TRANSMIT_ENABLE_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[7].timeout_count);
    tlm->TRANSMIT_ENABLE_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[7].timeout_interval.tv_sec);
    tlm->TRANSMIT_ENABLE_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[7].timeout_interval.tv_nsec);
    tlm->TRANSMIT_ENABLE_TX_SENT_SEC = LOAD(data->can_data.requests[7].sent_time.tv_sec);
    tlm->TRANSMIT_ENABLE_TX_SENT_NSEC = LOAD(data->can_data.requests[7].sent_time.tv_nsec);
    tlm->ACCEL_RAMP_TX_STATE = LOAD(data->can_data.requests[8].state);
    tlm->ACCEL_RAMP_TX_TXCOUNT = LOAD(data->can_data.requests[8].tx_count);
    tlm->ACCEL_RAMP_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[8].check_timeout);
    tlm->ACCEL_RAMP_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[8].timeout_count);
    tlm->ACCEL_RAMP_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[8].timeout_interval.tv_sec);
    tlm->ACCEL_RAMP_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[8].timeout_interval.tv_nsec);
    tlm->ACCEL_RAMP_TX_SENT_SEC = LOAD(data->can_data.requests[8].sent_time.tv_sec);
    tlm->ACCEL_RAMP_TX_SENT_NSEC = LOAD(data->can_data.requests[8].sent_time.tv_nsec);
    tlm->DECEL_RAMP_TX_STATE = LOAD(data->can_data.requests[9].state);
    tlm->DECEL_RAMP_TX_TXCOUNT = LOAD(data->can_data.requests[9].tx_count);
    tlm->DECEL_RAMP_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[9].check_timeout);
    tlm->DECEL_RAMP_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[9].timeout_count);
    tlm->DECEL_RAMP_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[9].timeout_interval.tv_sec);
    tlm->DECEL_RAMP_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[9].timeout_interval.tv_nsec);
    tlm->DECEL_RAMP_TX_SENT_SEC = LOAD(data->can_data.requests[9].sent_time.tv_sec);
    tlm->DECEL_RAMP_TX_SENT_NSEC = LOAD(data->can_data.requests[9].sent_time.tv_nsec);
    tlm->STOP_MOTOR_TX_STATE = LOAD(data->can_data.requests[10].state);
    tlm->STOP_MOTOR_TX_TXCOUNT = LOAD(data->can_data.requests[10].tx_count);
    tlm->STOP_MOTOR_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[10].check_timeout);
    tlm->STOP_MOTOR_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[10].timeout_count);
    tlm->STOP_MOTOR_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[10].timeout_interval.tv_sec);
    tlm->STOP_MOTOR_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[10].timeout_interval.tv_nsec);
    tlm->STOP_MOTOR_TX_SENT_SEC = LOAD(data->can_data.requests[10].sent_time.tv_sec);
    tlm->STOP_MOTOR_TX_SENT_NSEC = LOAD(data->can_data.requests[10].sent_time.tv_nsec);
    tlm->SET_SPEED_TX_STATE = LOAD(data->can_data.requests[11].state);
    tlm->SET_SPEED_TX_TXCOUNT = LOAD(data->can_data.requests[11].tx_count);
    tlm->SET_SPEED_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[11].check_timeout);
    tlm->SET_SPEED_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[11].timeout_count);
    tlm->SET_SPEED_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[11].timeout_interval.tv_sec);
    tlm->SET_SPEED_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[11].timeout_interval.tv_nsec);
    tlm->SET_SPEED_TX_SENT_SEC = LOAD(data->can_data.requests[11].sent_time.tv_sec);
    tlm->SET_SPEED_TX_SENT_NSEC = LOAD(data->can_data.requests[11].sent_time.tv_nsec);
    tlm->MAX_SPEED_TX_STATE = LOAD(data->can_data.requests[12].state);
    tlm->MAX_SPEED_TX_TXCOUNT = LOAD(data->can_data.requests[12].tx_count);
    tlm->MAX_SPEED_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[12].check_timeout);
    tlm->MAX_SPEED_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[12].timeout_count);
    tlm->MAX_SPEED_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[12].timeout_interval.tv_sec);
    tlm->MAX_SPEED_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[12].timeout_interval.tv_nsec);
    tlm->MAX_SPEED_TX_SENT_SEC = LOAD(data->can_data.requests[12].sent_time.tv_sec);
    tlm->MAX_SPEED_TX_SENT_NSEC = LOAD(data->can_data.requests[12].sent_time.tv_nsec);
    tlm->DEVICE_CURRENT_TX_STATE = LOAD(data->can_data.requests[13].state);
    tlm->DEVICE_CURRENT_TX_TXCOUNT = LOAD(data->can_data.requests[13].tx_count);
    tlm->DEVICE_CURRENT_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[13].check_timeout);
    tlm->DEVICE_CURRENT_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[13].timeout_count);
    tlm->DEVICE_CURRENT_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[13].timeout_interval.tv_sec);
    tlm->DEVICE_CURRENT_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[13].timeout_interval.tv_nsec);
    tlm->DEVICE_CURRENT_TX_SENT_SEC = LOAD(data->can_data.requests[13].sent_time.tv_sec);
    tlm->DEVICE_CURRENT_TX_SENT_NSEC = LOAD(data->can_data.requests[13].sent_time.tv_nsec);
    tlm->CURRENT_200PC_TX_STATE = LOAD(data->can_data.requests[14].state);
    tlm->CURRENT_200PC_TX_TXCOUNT = LOAD(data->can_data.requests[14].tx_count);
    tlm->CURRENT_200PC_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[14].check_timeout);
    tlm->CURRENT_200PC_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[14].timeout_count);
    tlm->CURRENT_200PC_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[14].timeout_interval.tv_sec);
    tlm->CURRENT_200PC_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[14].timeout_interval.tv_nsec);
    tlm->CURRENT_200PC_TX_SENT_SEC = LOAD(data->can_data.requests[14].sent_time.tv_sec);
    tlm->CURRENT_200PC_TX_SENT_NSEC = LOAD(data->can_data.requests[14].sent_time.tv_nsec);
    tlm->ACTUAL_SPEED_TX_STATE = LOAD(data->can_data.requests[15].state);
    tlm->ACTUAL_SPEED_TX_TXCOUNT = LOAD(data->can_data.requests[15].tx_count);
    tlm->ACTUAL_SPEED_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[15].check_timeout);
    tlm->ACTUAL_SPEED_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[15].timeout_count);
    tlm->ACTUAL_SPEED_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[15].timeout_interval.tv_sec);
    tlm->ACTUAL_SPEED_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[15].timeout_interval.tv_nsec);
    tlm->ACTUAL_SPEED_TX_SENT_SEC = LOAD(data->can_data.requests[15].sent_time.tv_sec);
    tlm->ACTUAL_SPEED_TX_SENT_NSEC = LOAD(data->can_data.requests[15].sent_time.tv_nsec);
    tlm->ACTUAL_CURRENT_TX_STATE = LOAD(data->can_data.requests[16].state);
    tlm->ACTUAL_CURRENT_TX_TXCOUNT = LOAD(data->can_data.requests[16].tx_count);
    tlm->ACTUAL_CURRENT_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[16].check_timeout);
    tlm->ACTUAL_CURRENT_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[16].timeout_count);
    tlm->ACTUAL_CURRENT_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[16].timeout_interval.tv_sec);
    tlm->ACTUAL_CURRENT_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[16].timeout_interval.tv_nsec);
    tlm->ACTUAL_CURRENT_TX_SENT_SEC = LOAD(data->can_data.requests[16].sent_time.tv_sec);
    tlm->ACTUAL_CURRENT_TX_SENT_NSEC = LOAD(data->can_data.requests[16].sent_time.tv_nsec);
    tlm->ACTUAL_POSITION_TX_STATE = LOAD(data->can_data.requests[17].state);
    tlm->ACTUAL_POSITION_TX_TXCOUNT = LOAD(data->can_data.requests[17].tx_count);
    tlm->ACTUAL_POSITION_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[17].check_timeout);
    tlm->ACTUAL_POSITION_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[17].timeout_count);
    tlm->ACTUAL_POSITION_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[17].timeout_interval.tv_sec);
    tlm->ACTUAL_POSITION_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[17].timeout_interval.tv_nsec);
    tlm->ACTUAL_POSITION_TX_SENT_SEC = LOAD(data->can_data.requests[17].sent_time.tv_sec);
    tlm->ACTUAL_POSITION_TX_SENT_NSEC = LOAD(data->can_data.requests[17].sent_time.tv_nsec);
    tlm->CONTROLLER_VOLT_TX_STATE = LOAD(data->can_data.requests[18].state);
    tlm->CONTROLLER_VOLT_TX_TXCOUNT = LOAD(data->can_data.requests[18].tx_count);
    tlm->CONTROLLER_VOLT_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[18].check_timeout);
    tlm->CONTROLLER_VOLT_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[18].timeout_count);
    tlm->CONTROLLER_VOLT_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[18].timeout_interval.tv_sec);
    tlm->CONTROLLER_VOLT_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[18].timeout_interval.tv_nsec);
    tlm->CONTROLLER_VOLT_TX_SENT_SEC = LOAD(data->can_data.requests[18].sent_time.tv_sec);
    tlm->CONTROLLER_VOLT_TX_SENT_NSEC = LOAD(data->can_data.requests[18].sent_time.tv_nsec);
    tlm->CONTROLLER_ERROR_TX_STATE = LOAD(data->can_data.requests[19].state);
    tlm->CONTROLLER_ERROR_TX_TXCOUNT = LOAD(data->can_data.requests[19].tx_count);
    tlm->CONTROLLER_ERROR_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[19].check_timeout);
    tlm->CONTROLLER_ERROR_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[19].timeout_count);
    tlm->CONTROLLER_ERROR_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[19].timeout_interval.tv_sec);
    tlm->CONTROLLER_ERROR_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[19].timeout_interval.tv_nsec);
    tlm->CONTROLLER_ERROR_TX_SENT_SEC = LOAD(data->can_data.requests[19].sent_time.tv_sec);
    tlm->CONTROLLER_ERROR_TX_SENT_NSEC = LOAD(data->can_data.requests[19].sent_time.tv_nsec);
    tlm->ACTUAL_SPEED_STOP_TX_STATE = LOAD(data->can_data.requests[20].state);
    tlm->ACTUAL_SPEED_STOP_TX_TXCOUNT = LOAD(data->can_data.requests[20].tx_count);
    tlm->ACTUAL_SPEED_STOP_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[20].check_timeout);
    tlm->ACTUAL_SPEED_STOP_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[20].timeout_count);
    tlm->ACTUAL_SPEED_STOP_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[20].timeout_interval.tv_sec);
    tlm->ACTUAL_SPEED_STOP_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[20].timeout_interval.tv_nsec);
    tlm->ACTUAL_SPEED_STOP_TX_SENT_SEC = LOAD(data->can_data.requests[20].sent_time.tv_sec);
    tlm->ACTUAL_SPEED_STOP_TX_SENT_NSEC = LOAD(data->can_data.requests[20].sent_time.tv_nsec);
    tlm->ACTUAL_CURRENT_STOP_TX_STATE = LOAD(data->can_data.requests[21].state);
    tlm->ACTUAL_CURRENT_STOP_TX_TXCOUNT = LOAD(data->can_data.requests[21].tx_count);
    tlm->ACTUAL_CURRENT_STOP_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[21].check_timeout);
    tlm->ACTUAL_CURRENT_STOP_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[21].timeout_count);
    tlm->ACTUAL_CURRENT_STOP_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[21].timeout_interval.tv_sec);
    tlm->ACTUAL_CURRENT_STOP_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[21].timeout_interval.tv_nsec);
    tlm->ACTUAL_CURRENT_STOP_TX_SENT_SEC = LOAD(data->can_data.requests[21].sent_time.tv_sec);
    tlm->ACTUAL_CURRENT_STOP_TX_SENT_NSEC = LOAD(data->can_data.requests[21].sent_time.tv_nsec);
    tlm->ACTUAL_POSITION_STOP_TX_STATE = LOAD(data->can_data.requests[22].state);
    tlm->ACTUAL_POSITION_STOP_TX_TXCOUNT = LOAD(data->can_data.requests[22].tx_count);
    tlm->ACTUAL_POSITION_STOP_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[22].check_timeout);
    tlm->ACTUAL_POSITION_STOP_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[22].timeout_count);
    tlm->ACTUAL_POSITION_STOP_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[22].timeout_interval.tv_sec);
    tlm->ACTUAL_POSITION_STOP_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[22].timeout_interval.tv_nsec);
    tlm->ACTUAL_POSITION_STOP_TX_SENT_SEC = LOAD(data->can_data.requests[22].sent_time.tv_sec);
    tlm->ACTUAL_POSITION_STOP_TX_SENT_NSEC = LOAD(data->can_data.requests[22].sent_time.tv_nsec);
    tlm->CONTROLLER_VOLT_STOP_TX_STATE = LOAD(data->can_data.requests[23].state);
    tlm->CONTROLLER_VOLT_STOP_TX_TXCOUNT = LOAD(data->can_data.requests[23].tx_count);
    tlm->CONTROLLER_VOLT_STOP_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[23].check_timeout);
    tlm->CONTROLLER_VOLT_STOP_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[23].timeout_count);
    tlm->CONTROLLER_VOLT_STOP_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[23].timeout_interval.tv_sec);
    tlm->CONTROLLER_VOLT_STOP_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[23].timeout_interval.tv_nsec);
    tlm->CONTROLLER_VOLT_STOP_TX_SENT_SEC = LOAD(data->can_data.requests[23].sent_time.tv_sec);
    tlm->CONTROLLER_VOLT_STOP_TX_SENT_NSEC = LOAD(data->can_data.requests[23].sent_time.tv_nsec);
    tlm->CONTROLLER_ERROR_STOP_TX_STATE = LOAD(data->can_data.requests[24].state);
    tlm->CONTROLLER_ERROR_STOP_TX_TXCOUNT = LOAD(data->can_data.requests[24].tx_count);
    tlm->CONTROLLER_ERROR_STOP_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[24].check_timeout);
    tlm->CONTROLLER_ERROR_STOP_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[24].timeout_count);
    tlm->CONTROLLER_ERROR_STOP_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[24].timeout_interval.tv_sec);
    tlm->CONTROLLER_ERROR_STOP_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[24].timeout_interval.tv_nsec);
    tlm->CONTROLLER_ERROR_STOP_TX_SENT_SEC = LOAD(data->can_data.requests[24].sent_time.tv_sec);
    tlm->CONTROLLER_ERROR_STOP_TX_SENT_NSEC = LOAD(data->can_data.requests[24].sent_time.tv_nsec);
    tlm->CONTROLLER_STATUS_TX_STATE = LOAD(data->can_data.requests[25].state);
    tlm->CONTROLLER_STATUS_TX_TXCOUNT = LOAD(data->can_data.requests[25].tx_count);
    tlm->CONTROLLER_STATUS_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[25].check_timeout);
    tlm->CONTROLLER_STATUS_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[25].timeout_count);
    tlm->CONTROLLER_STATUS_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[25].timeout_interval.tv_sec);
    tlm->CONTROLLER_STATUS_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[25].timeout_interval.tv_nsec);
    tlm->CONTROLLER_STATUS_TX_SENT_SEC = LOAD(data->can_data.requests[25].sent_time.tv_sec);
    tlm->CONTROLLER_STATUS_TX_SENT_NSEC = LOAD(data->can_data.requests[25].sent_time.tv_nsec);
    tlm->CONTROLLER_CLEAR_ERRORS_TX_STATE = LOAD(data->can_data.requests[26].state);
    tlm->CONTROLLER_CLEAR_ERRORS_TX_TXCOUNT = LOAD(data->can_data.requests[26].tx_count);
    tlm->CONTROLLER_CLEAR_ERRORS_TX_CHECK_TIMEOUT = LOAD(data->can_data.requests[26].check_timeout);
    tlm->CONTROLLER_CLEAR_ERRORS_TX_TIMEOUT_COUNT = LOAD(data->can_data.requests[26].timeout_count);
    tlm->CONTROLLER_CLEAR_ERRORS_TX_TIMEOUT_SEC = LOAD(data->can_data.requests[26].timeout_interval.tv_sec);
    tlm->CONTROLLER_CLEAR_ERRORS_TX_TIMEOUT_NSEC = LOAD(data->can_data.requests[26].timeout_interval.tv_nsec);
    tlm->CONTROLLER_CLEAR_ERRORS_TX_SENT_SEC = LOAD(data->can_data.requests[26].sent_time.tv_sec);
    tlm->CONTROLLER_CLEAR_ERRORS_TX_SENT_NSEC = LOAD(data->can_data.requests[26].sent_time.tv_nsec);
}

