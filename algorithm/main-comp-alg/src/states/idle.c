#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __STANDBY__
#endif

int idle_state(Thresholds thresholds, int command) { //keeps high power on, but forbids movement
	printf(">> IDLE STATE\n");

	if (command == EMERGENCY_BRAKE) {
		return ESTOP;
	}
	//Move to standby
	else if (command == ENTER_STANDBY) {
		printf("Command received - Entering standby\n");
		return SUCCESS;
	}

	return REPEAT;
}

