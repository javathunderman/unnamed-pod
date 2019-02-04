#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __STANDBY__
#endif

int standby_state() {
	printf("STANDBY!\n");

	//Emergency brake
	if (estop_command || motor_temp > max_motor_temp) {
		return FAILURE;
	}
	else if (prelaunch_command) {
		printf("PRELAUNCH COMMAND RECEIVED!\n");
		return SUCCESS;
	}
	else if (enter_service_command) {
		printf("ENTER SERVICE COMMAND RECEIVED!\n");
		return SUCCESS;
	}

	return REPEAT;
}

