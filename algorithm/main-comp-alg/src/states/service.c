#ifndef __SERVICE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __SERVICE__
#endif

int service_state(Thresholds thresholds, int command) {
	printf(">> SERVICE STATE - BEEP BOOP!\n");

	if (command == EMERGENCY_BRAKE) {
		return ESTOP;
	}
	else if (command == STOP_SERVICE_PROPULSION) {
		return SUCCESS;
	}
	else if (command == FORWARD_SERVICE_PROPULSION) {
	
	}
	else if (command == BACKWARD_SERVICE_PROPULSION) {
	
	}
	else if (command == SLOW_SERVICE_PROPULSION) {
	
	}
	else if (command == MEDIUM_SERVICE_PROPULSION) {
	
	}
	else if (command == FAST_SERVICE_PROPULSION) {
	
	}

	return REPEAT;
}

