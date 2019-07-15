#ifndef __ESTOP__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ESTOP__
#endif

int estop_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf("EMERGENCY STOP!\n");
	int pod_velocity = 0;

	if (write_actuate_brakes(*fpga, NiFpga_True) != 0) {
		printf("ERROR: fpga failed to actuate brakes!");
	}

	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	else if ((*fpga).cache.tape_velocity <= 0) {
		printf("Entering Idle state!");

		if (write_actuate_brakes(*fpga, NiFpga_False) != 0) {
			printf("ERROR: fpga failed to actuate brakes!");
		}

		return IDLE_SID;
	}

	return ESTOP_SID;
}