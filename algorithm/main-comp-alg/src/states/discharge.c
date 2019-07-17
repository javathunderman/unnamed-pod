#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __STANDBY__
#endif

int discharge_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> IDLE STATE - Command: %d\n", command);

	//(H8) E-STOP
	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	
	fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_True), "actuate brakes");
	//TODO: Motor Idle

	//(H1) Revert to Standby + (C1) Discharged
	if (command == ENTER_STANDBY && 1) { //TODO: discharged bool		
		printf("Command received - Entering standby\n");
		return STANDBY_SID;
	}

	return IDLE_SID;
}

