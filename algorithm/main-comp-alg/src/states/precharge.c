#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

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
	else if (command == LAUNCH) {
		printf("LAUNCH COMMAND RECEIVED!\n");
		return NiFpga_IsNotError(fpga->status) ? ENABLEMOTOR_SID : STANDBY_SID;
	}

	return PRECHARGE_SID;
}
