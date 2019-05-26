#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

int initialize_state(Thresholds *thresholds, int command) {

	printf(">> INITIALIZE STATE - Command: %d\n", command);
	//Do Initialization stuff here

	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	if (command == LAUNCH_INITIALIZE) {
		printf("LAUNCH COMMAND RECEIVED!\n");
		return ACCELERATE_SID;
	}
	else if (command == ENTER_STANDBY) {
		printf("ABORT LAUNCH COMMAND RECEIVED!\n");
		return STANDBY_SID;
	}

	return INITIALIZE_SID;
}
