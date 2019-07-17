#ifndef TELEMETRY_H
#define TELEMETRY_H


#include <sys/socket.h>
#include <arpa/inet.h>
#include "states.h"

#define SA struct sockaddr
#define TO_USEC 100000
#define PORT 8187

typedef struct {
    int socket;
    struct sockaddr_in dest_addr;
    socklen_t dest_len;
    UMData *data;
} TelemetryArgs;

typedef struct {
    unsigned int K1_HIGH : 8;
    unsigned int K2_PRECHARGE : 8;
    unsigned int K3_LOW : 8;
    unsigned int K4_DISCHARGE : 8;
    unsigned int PRI1_ALG_SHUTOFF : 8;
    unsigned int PRI2_ALG_SHUTOFF : 8;
    unsigned int RES_ALG_SHUTOFF : 8;
    unsigned int BRAKE_STATE : 8;
    unsigned int DRAIN_STATE : 8;
    unsigned int ENABLE_CHECKS_STATE : 8;
    unsigned int LED_1 : 8;
    unsigned int LED_2 : 8;
    unsigned int TAPE_BL_COUNT : 8;
    unsigned int TAPE_BR_COUNT : 8;
    unsigned int TAPE_FL_COUNT : 8;
    unsigned int TAPE_L_COUNT : 8;
    unsigned int TAPE_R_COUNT : 8;
    unsigned int LIGHT_SENSOR_STATUS : 8;
    unsigned int HIGH_PRESSURE_1 : 32;
    unsigned int HIGH_PRESSURE_2 : 32;
    unsigned int LOW_PRESSURE_1 : 32;
    unsigned int LOW_PRESSURE_2 : 32;
    unsigned int PRI1_TEMP : 32;
    unsigned int PRI2_TEMP : 32;
    unsigned int RES_TEMP : 32;
    unsigned int CRIO_TEMP : 32;
    unsigned int EXTRA1_TEMP : 32;
    unsigned int EXTRA2_TEMP : 32;
    unsigned int PISTON1_TEMP : 32;
    unsigned int PISTON2_TEMP : 32;
    unsigned int PISTON3_TEMP : 32;
    unsigned int PISTON4_TEMP : 32;
    unsigned int PISTON5_TEMP : 32;
    unsigned int PISTON6_TEMP : 32;
    unsigned int PISTON7_TEMP : 32;
    unsigned int PISTON8_TEMP : 32;
    unsigned int TANK_TEMP : 32;
    unsigned int POD_TEMP : 32;
    unsigned int BRAKE_DISTANCE : 32;
    unsigned int BRAKE_FORCE : 32;
    unsigned int CUR_THRESH_MAX : 32;
    unsigned int CUR_THRESH_MIN : 32;
    unsigned int PRI1_CURRENT : 32;
    unsigned int PRI2_CURRENT : 32;
    unsigned int RES_CURRENT : 32;
    unsigned int POD_DISTANCE : 32;
    unsigned int IMU_DISTANCE : 32;
    unsigned int MTR_DISTANCE : 32;
    unsigned int TAPE_DISTANCE : 32;
    unsigned int TAPE_VELOCITY : 32;
    unsigned int PRI1_VOLTAGE : 32;
    unsigned int PRI2_VOLTAGE : 32;
    unsigned int RES_VOLTAGE : 32;
    unsigned int CUR_THRESH_PERSISTENCE : 32;
    unsigned int CUR_THRESH_RATIO : 32;
    unsigned int FAULT_LONG_2 : 32;
    unsigned int FAULT_LONG_3 : 32;
    unsigned int HARD_FAULT : 32;
    unsigned int SOFT_FAULT : 32;
    unsigned int PACK_CHARGE : 16;
    unsigned int PACK_VOLTAGE : 16;
    unsigned int PACK_CURRENT : 16;
    unsigned int MIN_CELL : 16;
    unsigned int MAX_CELL : 16;
    unsigned int PACK_AVG_TEMP : 16;
    unsigned int PACK_HIGH_TEMP : 16;
    unsigned int BMS_FAILSAFE_STATUS : 8;
    unsigned int DTC_FLAGS_1 : 8;
    unsigned int DTC_FLAGS_2 : 16;
    unsigned int ROLLING_COUNTER : 16;
    unsigned int ISO_STATUS_FLAGS : 8;
    unsigned int ISO_ERROR_FLAGS : 8;
    unsigned int ELECTRICAL_ISOLATION : 16;
    unsigned int ELECTRICAL_ISOLATION_UNCERT : 8;
    unsigned int ENERGY_STORED : 16;
    unsigned int ENERGY_STORED_UNCERT : 8;
    unsigned int HIGH_RAIL_RESISTANCE : 16;
    unsigned int HIGH_RAIL_RESISTANCE_UNCERT : 8;
    unsigned int LOW_RAIL_RESISTANCE : 16;
    unsigned int LOW_RAIL_RESISTANCE_UNCERT : 8;
    unsigned int BATTERY_VOLTAGE : 16;
    unsigned int BATTERY_VOLTAGE_UNCERT : 8;
    unsigned int MAX_BATTERY_VOLTAGE : 16;
    unsigned int MAX_BATTERY_VOLTAGE_UNCERT : 8;
    unsigned int MAX_SPEED : 16;
    unsigned int DEVICE_CURRENT : 16;
    unsigned int CURRENT_200PC : 16;
    unsigned int PERCENT_MAX_SPEED : 16;
    unsigned int TRUE_CURRENT : 16;
    unsigned int REVOLUTIONS : 32;
    unsigned int CONTROLLER_BUS_VOLTAGE : 16;
    unsigned int CONTROLLER_ERRORS : 32;
    unsigned int CONTROLLER_STATUS : 16;
} Telemetry;



void *send_tlm(void *args);

void update_telemetry_1_1(Telemetry *tlm, UMData *data);


#endif