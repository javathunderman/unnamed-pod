#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

int initialize_state(Thresholds thresholds, CommandBuffer *cb) {
	int command;
	read_cmd(cb, &command);

	printf("INITIALIZING... Command: %d\n", command);
	//Do Initialization stuff here

	if (command == LAUNCH_INITIALIZE) {
		printf("LAUNCH COMMAND RECEIVED!\n");
		return SUCCESS;
	}
	else if (command == ENTER_STANDBY) {
		printf("ABORT LAUNCH COMMAND RECEIVED!\n");
		return SUCCESS;
	}

	return REPEAT;
}
