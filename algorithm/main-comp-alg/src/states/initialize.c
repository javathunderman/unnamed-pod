#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

int initialize_state() {
	printf("INITIALIZING...\n");
	//Do Initialization stuff here

	if (launch_command) {
		printf("LAUNCH COMMAND RECEIVED!\n");
		return SUCCESS;
	}
	else if (abort_launch_command) {
		printf("LAUNCH COMMAND RECEIVED!\n");
		return SUCCESS;
	}

	return SUCCESS;
}
