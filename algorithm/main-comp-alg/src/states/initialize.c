#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

int initialize_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> INITIALIZE STATE - Command: %d\n", command);

	//(H8) E-STOP
	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}

	//TODO: fault/distance reset
	fpgaRunAndUpdateIf(fpga, write_reset_tape_count(fpga, NiFpga_True), "reset tape count");
	fpgaRunAndUpdateIf(fpga, write_reset_tape_status(fpga, NiFpga_True), "reset tape status");

	fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_False), "retract brakes");
	//TODO: motor disabled

	//(C2) Initialization fault
	if (0) {
		return STANDBY_SID;
	}
	//(H1) Revert to Standby
	if (command == ENTER_STANDBY) {
		printf("ABORT LAUNCH COMMAND RECEIVED!\n");
		return NiFpga_IsNotError(fpga->status) ? STANDBY_SID : STANDBY_SID;
	}
	//(H4) Pre-charge
	else if (command == PRECHARGE) {
		printf("PRECHARGE COMMAND RECEIVED!\n");
		return NiFpga_IsNotError(fpga->status) ? ENABLEMOTOR_SID : STANDBY_SID;
	}

	return INITIALIZE_SID;
}
