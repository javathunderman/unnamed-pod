#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"
#include "abort_run.h"
#include "utils.h"
#include "can_control.h"
#include "run_data.h"

#define __STANDBY__
#endif

int standby_state(Fpga *fpga, Thresholds *thresholds, int command) {
    FSM_Status ret_val;
    
    printf(">> STANDBY STATE - Command: %d\n", command);
    /*printf("threshold stuct values: bd:%f ad:%f %f %f %f\n", 
        thresholds.brake_distance, 
        thresholds.acceleration_distance, 
        thresholds.battery_temperature_low, 
        thresholds.battery_temperature_high, 
        thresholds.battery_temperature_pers);*/

    fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_False), "retract brakes");

    //(H8) E-STOP
    if (command == EMERGENCY_BRAKE) {
        printf("SHUTTING DOWN POD!\n");
        return ESTOP_SID;
    }
    
    //(H7) Shutdown
    if (command == SHUTDOWN) {
        SHUTOFF_POD;
        return ENDRUN_SID;
    }
    
    /* Assert motor is disabled and ready */
    ret_val = can_motor_ready(&(run_data.can_data));
    if (ret_val == FSM_FAILED || ret_val == FSM_WAITING) {
        return STANDBY_SID;
    }
    
    if (command == PRELAUNCH) {
        printf("PRELAUNCH COMMAND RECEIVED!\n");
        return INITIALIZE_SID;
    }
    
    else if (command == ENTER_SERVICE) {
        printf("ENTER SERVICE COMMAND RECEIVED!\n");
        return SERVICE_SID;
    }

    return STANDBY_SID;
}


