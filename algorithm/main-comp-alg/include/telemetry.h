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
    unsigned int POD_TEMP : 32;
    unsigned int POD_PRESSURE : 32;
    unsigned int ACCEL_X : 32;
    unsigned int ACCEL_Y : 32;
    unsigned int ACCEL_Z : 32;
    unsigned int VEL_X : 32;
    unsigned int VEL_Y : 32;
    unsigned int VEL_Z : 32;
    unsigned int POS_X : 32;
    unsigned int POS_Y : 32;
    unsigned int POS_Z : 32;
    unsigned int PRIM1_V : 32;
    unsigned int PRIM2_V : 32;
    unsigned int RESV_V : 32;
    unsigned int PRIM1_A : 32;
    unsigned int PRIM2_A : 32;
    unsigned int RESV_A : 32;
    unsigned int PRIM1_TEMP : 32;
    unsigned int PRIM2_TEMP : 32;
    unsigned int RESV_TEMP : 32;
    unsigned int MTR_RPM : 32;
    unsigned int MTR_V : 32;
    unsigned int MTR_A : 32;
    unsigned int MTR_TEMP : 32;
    unsigned int CAN_CONNECTED : 32;
    unsigned int CAN_STATE : 32;
    unsigned int CAN_ERR : 32;
    unsigned int HIGH_TRANSDUCER1 : 32;
    unsigned int HIGH_TRANSDUCER2 : 32;
    unsigned int LOW_TRANSDUCER1 : 32;
    unsigned int LOW_TRANSDUCER2 : 32;
    unsigned int TANK_TEMP : 32;
    unsigned int PRESSURE_DRAIN : 32;
    unsigned int SOLENOID1 : 32;
    unsigned int SOLENOID2 : 32;
    unsigned int FSM_STATE : 32;
    unsigned int INIT_CHECKS : 32;
    unsigned int TIME_SEC : 32;
    unsigned int TIME_USEC : 32;
    unsigned int LAST_COMMAND : 32;
    unsigned int THROTTLE : 32;
    unsigned int PACK_V : 32;
    unsigned int PACK_A : 32;
    unsigned int RELAYS : 32;
    unsigned int ISOLATION : 32;
    unsigned int FUSE : 32;
    unsigned int PACK_CHARGE : 32;
    unsigned int MODULE1_TEMP : 32;
    unsigned int MODULE2_TEMP : 32;
    unsigned int MODULE3_TEMP : 32;
    unsigned int MODULE4_TEMP : 32;
    unsigned int MODULE5_TEMP : 32;
    unsigned int MODULE6_TEMP : 32;
    unsigned int MODULE7_TEMP : 32;
    unsigned int MODULE8_TEMP : 32;
    unsigned int MAX_CELL : 32;
    unsigned int MIN_CELL : 32;
} Telemetry;



void *send_tlm(void *args);

void update_telemetry_1_1(Telemetry *tlm);


#endif