#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include "spacex.h"
#include "telemetry.h"


#define PKT_LENGTH 152
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

void update_telemetry_1_1(Telemetry *tlm) {
    tlm->TBM_TEMP = ???;
    tlm->EPB_PRESSURE = ???;
    tlm->ACCEL_X = ???;
    tlm->ACCEL_Y = ???;
    tlm->ACCEL_Z = ???;
    tlm->VEL_X = ???;
    tlm->VEL_Y = ???;
    tlm->VEL_Z = ???;
    tlm->POS_X = ???;
    tlm->POS_Y = ???;
    tlm->POS_Z = ???;
    tlm->MTR_RPM = ???;
    tlm->MTR_V = ???;
    tlm->MTR_A = ???;
    tlm->MTR_TEMP = ???;
    tlm->TelemetryTBM_STATUS = ???;
    tlm->INT_HYD_TEMP = ???;
    tlm->EXT_HYD_TEMP = ???;
    tlm->CIM_SPEED = ???;
    tlm->SOIL_BOX_WEIGHT = ???;
    tlm->FSM_STATE = ???;
    tlm->INIT_CHECKS = ???;
    tlm->TIME_SEC = ???;
    tlm->TIME_USEC = ???;
    tlm->LAST_COMMAND = ???;
    tlm->THROTTLE = ???;
    tlm->METHANE = ???;
    tlm->PIPEJACKING = ???;
    tlm->TelemetryGS_STATUS = ???;
    tlm->HV_STATUS = ???;
    tlm->PS_TBM_STATUS = ???;
    tlm->SENSOR_STATUS = ???;
    tlm->STEERING_STATUS = ???;
    tlm->EXCAVATION_STATUS = ???;
    tlm->CIM_TEMP = ???;
    tlm->INT_HYD_PRESSURE = ???;
    tlm->EXT_HYD_PRESSURE = ???;
    tlm->PS_GS_STATUS = ???;
}

