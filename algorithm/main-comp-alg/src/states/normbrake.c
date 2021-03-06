#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"
#include "fpga_cache.h"
#include "run_data.h"
#include "can_control.h"

int normbrake_state(Fpga *fpga, Thresholds *thresholds, int command) {
	// TODO: enter true velocity
	printf(">> NORMAL BRAKE STATE - %d %d\n", 1, acknowledge_command);

	//(H8) E-STOP
	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	//check speed, repeat until zero?

	if (can_motor_end_run(&(run_data.can_data)) == FSM_FAILED) {
		return HVCUT_SID;
	}

	//(C3) Zero Velocity
	if ((*fpga).cache.tape_velocity <= 0) {
		printf("Pod stopped: Entering Idle state\n");

		fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_False), "retract brakes")

		return NiFpga_IsNotError(fpga->status) ? IDLE_SID : NORMBRAKE_SID;
	} 
	else if (!fpga->cache.brake_state) {
		fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_True), "actuate brakes")

		return NiFpga_IsNotError(fpga->status) ? NORMBRAKE_SID : NORMBRAKE_SID;
	}

	return NORMBRAKE_SID;
}
