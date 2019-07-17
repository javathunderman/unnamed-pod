#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"
#include "fpga_cache.h"

int estop_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf("EMERGENCY STOP!\n");

	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}

	//(C3) Zero Velocity
	if ((*fpga).cache.tape_velocity <= 0) {
		printf("Pod stopped: Entering Idle state\n");

		fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_False), "retract brakes")

		return NiFpga_IsNotError(fpga->status) ? IDLE_SID : ESTOP_SID;
	} 
	else if (!fpga->cache.brake_state) {
		fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_True), "actuate brakes")

		return NiFpga_IsNotError(fpga->status) ? ESTOP_SID : ESTOP_SID;
	}

	return ESTOP_SID;
}
