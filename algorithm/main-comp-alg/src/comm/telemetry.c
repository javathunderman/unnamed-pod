#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include "spacex.h"
#include "telemetry.h"


#define PKT_LENGTH 228
#define TLM_FREQ 1000000000L
#define NS_IN_SEC 1000000000L
#define UPDATE_DELAY(name) name.tv_sec = name.tv_sec + ((name.tv_nsec + TLM_FREQ) / NS_IN_SEC);\
                           name.tv_nsec = (name.tv_nsec + TLM_FREQ) % NS_IN_SEC;
#define INIT_TIMES(name, time) sec = name.tv_sec + ((name.tv_nsec + time) / NS_IN_SEC);\
                               nsec = (name.tv_nsec + time) % NS_IN_SEC;

void *send_tlm(void *args) {
    Telemetry tlm;

    int socket = ((TelemetryArgs *)args)->socket;
    SA * dest_addr = ((TelemetryArgs *)args)->dest_addr;
    socklen_t dest_len = ((TelemetryArgs *)args)->dest_len;

    struct timespec now;
    if(clock_gettime(CLOCK_MONOTONIC, &now) == -1) {
        printf("clock_gettime() error: %s\n", strerror(errno));
        exit(-3);
    }
    __time_t sec = now.tv_sec;
    __syscall_slong_t nsec = now.tv_nsec;

    INIT_TIMES(now, 1000000000L)
    struct timespec delay_1 = {sec, nsec};


    while(1) {
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &delay_1, NULL);
        update_telemetry_1_1(&tlm);

        if(sendto(socket, &tlm, PKT_LENGTH, 0, dest_addr, dest_len) == -1) {
            printf("%s\n", strerror(errno));
            //TODO: Comm Loss
        }

        if(send_spacex(&tlm) == -1) {
            //TODO: Comm Loss
        }

        UPDATE_DELAY(delay_1)
    }
}

static void update_telemetry_1_1(Telemetry *tlm) {
    tlm->POD_TEMP = 0;
    tlm->POD_PRESSURE = 0;
    tlm->ACCEL_X = 0;
    tlm->ACCEL_Y = 0;
    tlm->ACCEL_Z = 0;
    tlm->VEL_X = 0;
    tlm->VEL_Y = 0;
    tlm->VEL_Z = 0;
    tlm->POS_X = 0;
    tlm->POS_Y = 0;
    tlm->POS_Z = 0;
    tlm->PRIM1_V = 0;
    tlm->PRIM2_V = 0;
    tlm->RESV_V = 0;
    tlm->PRIM1_A = 0;
    tlm->PRIM2_A = 0;
    tlm->RESV_A = 0;
    tlm->PRIM1_TEMP = 0;
    tlm->PRIM2_TEMP = 0;
    tlm->RESV_TEMP = 0;
    tlm->MTR_RPM = 0;
    tlm->MTR_V = 0;
    tlm->MTR_A = 0;
    tlm->MTR_TEMP = 0;
    tlm->CAN_CONNECTED = 0;
    tlm->CAN_STATE = 0;
    tlm->CAN_ERR = 0;
    tlm->HIGH_TRANSDUCER1 = 0;
    tlm->HIGH_TRANSDUCER2 = 0;
    tlm->LOW_TRANSDUCER1 = 0;
    tlm->LOW_TRANSDUCER2 = 0;
    tlm->TANK_TEMP = 0;
    tlm->PRESSURE_DRAIN = 0;
    tlm->SOLENOID1 = 0;
    tlm->SOLENOID2 = 0;
    tlm->FSM_STATE = 0;
    tlm->INIT_CHECKS = 0;
    tlm->TIME_SEC = 0;
    tlm->TIME_USEC = 0;
    tlm->LAST_COMMAND = 0;
    tlm->THROTTLE = 0;
    tlm->PACK_V = 0;
    tlm->PACK_A = 0;
    tlm->RELAYS = 0;
    tlm->ISOLATION = 0;
    tlm->FUSE = 0;
    tlm->PACK_CHARGE = 0;
    tlm->MODULE1_TEMP = 0;
    tlm->MODULE2_TEMP = 0;
    tlm->MODULE3_TEMP = 0;
    tlm->MODULE4_TEMP = 0;
    tlm->MODULE5_TEMP = 0;
    tlm->MODULE6_TEMP = 0;
    tlm->MODULE7_TEMP = 0;
    tlm->MODULE8_TEMP = 0;
    tlm->MAX_CELL = 0;
    tlm->MIN_CELL = 0;
}

