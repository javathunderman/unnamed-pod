#ifndef __SERVICE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __SERVICE__
#endif

int service_state(Thresholds *thresholds, int command) {
	printf(">> SERVICE STATE\n");

	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	else if (command == ENTER_STANDBY) { //&&velocity == 0
		printf("Exiting service -> Standby\n");
		return STANDBY_SID;
	}
	else if (command == STOP_SERVICE_PROPULSION) {
		//stop motor
	}
	else if (command == FORWARD_SERVICE_PROPULSION) {
		//motor forward
		printf("Forward Command Received\n");
	}
	else if (command == BACKWARD_SERVICE_PROPULSION) {
		//motor backward
		printf("Backward Command Received\n");
	}
	else if (command == SLOW_SERVICE_PROPULSION) {
		//motor speed slow
		printf("Slow Command Received\n");
	}
	else if (command == MEDIUM_SERVICE_PROPULSION) {
		//motor speed medium
	}
	else if (command == FAST_SERVICE_PROPULSION) {
		//motor speed fast
	}

	//repeat
	return SERVICE_SID;
}

