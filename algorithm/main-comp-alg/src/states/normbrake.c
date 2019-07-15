#ifndef __NORMBRAKE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __NORMBRAKE__
#endif

int normbrake_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> NORMAL BRAKE STATE - %d %d\n", pod_vel, acknowledge_command);

	//check speed, repeat until zero?

	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	else if ((*fpga).cache.tape_velocity <= 0) {
		printf("Pod stopped: Entering Idle state\n");

		if (write_actuate_brakes(*fpga, NiFpga_False) != 0) {
			printf("ERROR: fpga failed to actuate brakes!");
		}

		return IDLE_SID;
	}
	else {

		if (write_actuate_brakes(*fpga, NiFpga_True) != 0) {
			printf("ERROR: fpga failed to actuate brakes!");
		}

		return NORMBRAKE_SID;
	}

}
