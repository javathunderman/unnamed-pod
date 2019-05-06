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
		return ESTOP_SID;
	}
	else if (pod_vel < 1) {
		printf("Pod stopped: Entering Idle state\n");
		return IDLE_SID;
	}
	else {
		pod_vel -= 100; //get pod speed from IMU and light sensors, logic goes here

		//printf("CONTINUING: fake velocity: %d\n", pod_vel);
		//HIT DA BRAKES!
		return NORMBRAKE_SID;
	}

}
