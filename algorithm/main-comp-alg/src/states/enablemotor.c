#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

int enablemotor_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> ENABLE MOTOR STATE - Command: %d\n", command);

	//(H8) E-STOP
	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}

	fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_False), "retract brakes");
	//TODO: Motor enabled
	//TODO: Autonomy granted
	
	//(C4) Motor Initialized
	if (1) { //TODO: check C4 Motor initialized
		printf("MOTOR INITIALIZED!\n");
		return NiFpga_IsNotError(fpga->status) ? ACCELERATE_SID : DISCHARGE_SID;
	}
	else if (command == DISCHARGE) {
		printf("DISCHARGE COMMAND RECEIVED!\n");
		return NiFpga_IsNotError(fpga->status) ? DISCHARGE_SID : DISCHARGE_SID;
	}

	return ENABLEMOTOR_SID;
}
