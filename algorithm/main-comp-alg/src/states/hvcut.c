#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"
#include "run_data.h"
#include "can_control.h"

#define __STANDBY__
#endif

int hvcut_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> IDLE STATE - Command: %d\n", command);

	can_motor_end_run(&(run_data.can_data));

	//(H8) E-STOP
	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	
	//(C3) Zero Velocity
	if ((*fpga).cache.tape_velocity <= 0) {
		printf("Pod stopped: Entering Idle state\n");

		fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_False), "retract brakes");

		return NiFpga_IsNotError(fpga->status) ? DISCHARGE_SID : HVCUT_SID;
	} 
	else if (!fpga->cache.brake_state) {
		fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_True), "actuate brakes");

		return NiFpga_IsNotError(fpga->status) ? HVCUT_SID : HVCUT_SID;
	}

	return IDLE_SID;
}

