#ifndef __NORMBRAKE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __NORMBRAKE__
#endif

int normbrake_state(Thresholds thresholds, int command) {
	static int pod_vel = 250;
	printf(">> NORMAL BRAKE STATE - %d %d\n", pod_vel, acknowledge_command);

	//check speed, repeat until zero?

	if (command == EMERGENCY_BRAKE) {
		return ESTOP;
	}
	else if ((pod_vel <= 1) && acknowledge_command) {
		printf("Entering Idle state!");
		return SUCCESS;
	}
	else {
		pod_vel -= 25; //get pod speed from IMU and light sensors, logic goes here

		printf("CONTINUING: fake velocity: %d\n", pod_vel);
		//HIT DA BRAKES!
		return REPEAT;
	}

	return REPEAT;
}
