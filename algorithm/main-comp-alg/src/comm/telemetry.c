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
#include "telemetry.h"


#define PKT_LENGTH 244
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


    while(1) {
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
    tlm->TAPE_FL_COUNT = LOAD(data->fpga_cache.light_FL_count);
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
    tlm->BRAKE_FORCE = LOAD(data->fpga_cache.brake_force);
    tlm->CUR_THRESH_MAX = LOAD(data->fpga_cache.cur_thresh_max);
    tlm->CUR_THRESH_MIN = LOAD(data->fpga_cache.cur_thresh_min);
    tlm->PRI1_CURRENT = LOAD(data->fpga_cache.current_p1);
    tlm->PRI2_CURRENT = LOAD(data->fpga_cache.current_p2);
    tlm->RES_CURRENT = LOAD(data->fpga_cache.current_r);
    tlm->POD_DISTANCE = LOAD(data->fpga_cache.fusion_distance);
    tlm->IMU_DISTANCE = LOAD(data->fpga_cache.imu_distance);
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
}

