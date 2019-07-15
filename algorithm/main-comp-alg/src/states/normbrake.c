#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

int normbrake_state(Fpga *fpga, Thresholds *thresholds, int command) {
	// TODO: enter true velocity
	printf(">> NORMAL BRAKE STATE - %d %d\n", 1, acknowledge_command);

	//check speed, repeat until zero?

	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	else if ((*fpga).cache.tape_velocity <= 0) {
		printf("Pod stopped: Entering Idle state\n");

		if (NiFpga_write_actuate_brakes(*fpga, NiFpga_False) != 0) {
			printf("ERROR: fpga failed to retract brakes!");
			return NORMBRAKE_SID;
			//TODO: handle the NI is trash error better
		}

		return IDLE_SID;
	} else if (!fpga->cache.brake_state) {
		if(NiFpga_IsError(write_actuate_brakes(fpga, NiFpga_True))) {
			//TODO: handle the NI is trash error better
			printf("ERROR: fpga failed to actuate brakes!");
		}
	}

	return NORMBRAKE_SID;
}
