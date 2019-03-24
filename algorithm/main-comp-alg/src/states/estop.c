#ifndef __ESTOP__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ESTOP__
#endif

int estop_state(Thresholds thresholds) {
	printf("EMERGENCY STOP!\n");
	int pod_velocity = 0;

	if (pod_velocity < 2 && acknowledge_command) {
		return SUCCESS;
	}

	return REPEAT;
}