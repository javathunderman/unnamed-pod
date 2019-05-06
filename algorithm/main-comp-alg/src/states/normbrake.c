#ifndef __NORMBRAKE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __NORMBRAKE__
#endif

int normbrake_state(Thresholds thresholds, CommandBuffer *cb) {
	static int pod_vel = 250;
	printf("NORMAL BRAKING! %d %d\n", pod_vel, acknowledge_command);

	//check speed, repeat until zero?

	if ((pod_vel <= 1) && acknowledge_command) {
		printf("Entering Idle state!");
		return SUCCESS;
	}
	else {
		pod_vel -= 25; //get pod speed from IMU and light sensors, logic goes here

		printf("CONTINUING: fake velocity: %d\n", pod_vel);
		//FULL THROTTLE!
		return REPEAT;
	}

	return REPEAT;
}
