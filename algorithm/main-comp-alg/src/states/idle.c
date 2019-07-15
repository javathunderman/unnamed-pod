#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __STANDBY__
#endif

int idle_state(Fpga *fpga, Thresholds *thresholds, int command) { //keeps high power on, but forbids movement
	printf(">> IDLE STATE - Command: %d\n", command);

	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	//Move to standby
	else if (command == ENTER_STANDBY) {
		if (fpga->cache.brake_state == NiFpga_False) {

		}
		
		printf("Command received - Entering standby\n");
		return STANDBY_SID;
	}

	return IDLE_SID;
}

