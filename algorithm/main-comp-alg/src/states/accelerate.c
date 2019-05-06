#ifndef __ACCELERATE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ACCELERATE__
#endif

int accelerate_state(Thresholds thresholds, int command) {
	static int pod_position = 0;
	int motor_temp = 998; //<- fake temp for logic

	printf(">> ACCELERATING - fake position: %d\n", pod_position);

	//Emergency brake
	if (command == EMERGENCY_BRAKE || motor_temp > thresholds.motor_temperature_high) {
		printf("ESTOP: fake position: %d\n", pod_position);
		return ESTOP;
	}
	//End of tube regular brake
	else if (thresholds.track_length - pod_position <= thresholds.brake_distance) {
		printf("NORMAL BRAKE: fake position: %d\n", pod_position);
		pod_position = 0; //temporary
		return SUCCESS;
	}
	//Continue to accelerate
	else {
		pod_position += 500; //get pod position from IMU and light sensors, logic goes here

		printf("CONTINUING: fake position: %d\n", pod_position);
		//FULL THROTTLE!
		return REPEAT;
	}

	
}