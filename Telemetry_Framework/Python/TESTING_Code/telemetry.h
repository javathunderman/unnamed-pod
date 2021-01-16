#ifndef TELEMETRY_H
#define TELEMETRY_H


#include <sys/socket.h>

#define SA struct sockaddr
#define TO_USEC 1000000
#define PORT 8187

typedef struct {
    int socket;
    SA * dest_addr;
    socklen_t dest_len;
} TelemetryArgs;

typedef struct {
    unsigned int TBM_TEMP : 32;
    unsigned int EPB_PRESSURE : 32;
    unsigned int ACCEL_X : 32;
    unsigned int ACCEL_Y : 32;
    unsigned int ACCEL_Z : 32;
    unsigned int VEL_X : 32;
    unsigned int VEL_Y : 32;
    unsigned int VEL_Z : 32;
    unsigned int POS_X : 32;
    unsigned int POS_Y : 32;
    unsigned int POS_Z : 32;
    unsigned int MTR_RPM : 32;
    unsigned int MTR_V : 32;
    unsigned int MTR_A : 32;
    unsigned int MTR_TEMP : 32;
    unsigned int TELEMETRY_STATUS : 32;
    unsigned int INT_HYD_TEMP : 32;
    unsigned int EXT_HYD_TEMP : 32;
    unsigned int CIM_SPEED : 32;
    unsigned int SOIL_BOX_WEIGHT : 32;
    unsigned int FSM_STATE : 32;
    unsigned int INIT_CHECKS : 32;
    unsigned int TIME_SEC : 32;
    unsigned int TIME_USEC : 32;
    unsigned int LAST_COMMAND : 32;
    unsigned int THROTTLE : 32;
    unsigned int METHANE : 32;
    unsigned int PIPEJACKING : 32;
    unsigned int GROUND_STATUS : 32;
    unsigned int HV_STATUS : 32;
    unsigned int LV_STATUS : 32;
    unsigned int SENSOR_STATUS : 32;
    unsigned int STEERING_STATUS : 32;
    unsigned int EXCAVATION_STATUS : 32;
    unsigned int CIM_TEMP : 32;
    unsigned int INT_HYD_PRESSURE : 32;
    unsigned int EXT_HYD_PRESSURE : 32;
} Telemetry;



void *send_tlm(void *args);

void update_telemetry_1_1(Telemetry *tlm);


#endif