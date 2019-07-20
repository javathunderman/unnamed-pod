#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"
#include "utils.h"
#include "run_data.h"
#include "can_control.h"

#define __INITIALIZE__
#endif

static FSM_Status precharge(Fpga *fpga);

int precharge_state(Fpga *fpga, Thresholds *thresholds, int command) {
    printf(">> PRECHARGE STATE - Command: %d\n", command);

    if (command == EMERGENCY_BRAKE) {
        return ESTOP_SID;
    }

    fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_False), "retract brakes");
    //TODO: Motor powering on

    
    if (command == DISCHARGE) {
        printf("DISCHARGE COMMAND RECEIVED!\n");
        return NiFpga_IsNotError(fpga->status) ? DISCHARGE_SID : DISCHARGE_SID;
    }
    else if (precharge(fpga) == FSM_COMPLETE && command == LAUNCH) {
        printf("LAUNCH COMMAND RECEIVED!\n");
        return NiFpga_IsNotError(fpga->status) ? ENABLEMOTOR_SID : STANDBY_SID;
    }

    return PRECHARGE_SID;
}

static FSM_Status precharge(Fpga *fpga) {
    int time, delay_1, delay_2, delay_3;
    FSM_Status status;
    
    delay_1 = LOAD(run_data.software.precharge_delay_1);
    delay_2 = LOAD(run_data.software.precharge_delay_2);
    delay_3 = LOAD(run_data.software.precharge_delay_3);
    time = LOAD(run_data.software.sclk);
    
    if (LOAD(run_data.software.precharge_complete)) {
        return FSM_COMPLETE;
    }
    
    if (delay_1 == -1) {
        fpgaRunAndUpdateIf(fpga, write_hvr_1(fpga, NiFpga_False), "open K1");
        fpgaRunAndUpdateIf(fpga, write_hvr_2(fpga, NiFpga_False), "open K2");
        fpgaRunAndUpdateIf(fpga, write_hvr_3(fpga, NiFpga_False), "open K3");
        fpgaRunAndUpdateIf(fpga, write_hvr_4(fpga, NiFpga_True), "close K4");
        if (NiFpga_IsError(fpga->status)) {
            return FSM_FAILED;
        }
        STORE(run_data.software.precharge_delay_1, time + 15000);
    } else if (time == delay_1) {
        fpgaRunAndUpdateIf(fpga, write_hvr_4(fpga, NiFpga_False), "open K4");
        fpgaRunAndUpdateIf(fpga, write_hvr_3(fpga, NiFpga_True), "close K3");
        if (NiFpga_IsError(fpga->status)) {
            return FSM_FAILED;
        }
        STORE(run_data.software.precharge_delay_2, time + 50);
    } else if (time == delay_2) {
        fpgaRunAndUpdateIf(fpga, write_hvr_2(fpga, NiFpga_True), "close K2");
        if (NiFpga_IsError(fpga->status)) {
            return FSM_FAILED;
        }
    } else if (delay_2 > 0 && time > delay_2 && ((status = can_motor_precharge(&(run_data.can_data))) != FSM_COMPLETE)) {
        return status;
    } else if (delay_3 == -1 && delay_2 > 0 && time > delay_2 && ((status = can_motor_precharge(&(run_data.can_data))) == FSM_COMPLETE)) {
        fpgaRunAndUpdateIf(fpga, write_hvr_1(fpga, NiFpga_True), "close K1");
        if (NiFpga_IsError(fpga->status)) {
            return FSM_FAILED;
        }
        STORE(run_data.software.precharge_delay_3, time + 50);
    } else if (time == delay_3) {
        fpgaRunAndUpdateIf(fpga, write_hvr_1(fpga, NiFpga_True), "open K2");
        if (NiFpga_IsError(fpga->status)) {
            return FSM_FAILED;
        }
        STORE(run_data.software.precharge_complete, 1);
        return FSM_COMPLETE;
    }
    
    return FSM_WAITING;
}

/* Returns 0 on success.
 * 
 */
FSM_Status reset_precharge(Fpga *fpga) {
    STORE(run_data.software.precharge_delay_1, -1);
    STORE(run_data.software.precharge_delay_2, -1);
    STORE(run_data.software.precharge_delay_3, -1);
    STORE(run_data.software.precharge_complete, 0);
    
    fpgaRunAndUpdateIf(fpga, write_hvr_1(fpga, NiFpga_False), "open K1");
    if (NiFpga_IsError(fpga->status)) {
        return FSM_FAILED;
    }
    fpgaRunAndUpdateIf(fpga, write_hvr_2(fpga, NiFpga_False), "open K2");
    if (NiFpga_IsError(fpga->status)) {
        return FSM_FAILED;
    }
    fpgaRunAndUpdateIf(fpga, write_hvr_3(fpga, NiFpga_False), "open K3");
    if (NiFpga_IsError(fpga->status)) {
        return FSM_FAILED;
    }
    
    fpgaRunAndUpdateIf(fpga, write_hvr_4(fpga, NiFpga_False), "open K4");
    if (NiFpga_IsError(fpga->status)) {
        return FSM_FAILED;
    }
    
    return FSM_COMPLETE;
}

