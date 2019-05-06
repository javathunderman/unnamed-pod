#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __STANDBY__
#endif

int idle_state(Thresholds thresholds, CommandBuffer *cb) { //keeps high power on, but forbids movement
	//printf("Idle state!");

	//Move to standby
	if (!acknowledge_command) {
		return SUCCESS;
	}

	return REPEAT;
}

