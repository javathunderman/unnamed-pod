#ifndef __ESTOP__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ESTOP__
#endif

int estop_state(Thresholds thresholds, int command) {
	printf("EMERGENCY STOP!\n");
	int pod_velocity = 0;

	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	else if (pod_velocity < 1) {
		printf("Entering Idle state!");
		return IDLE_SID;
	}

	return ESTOP_SID;
}