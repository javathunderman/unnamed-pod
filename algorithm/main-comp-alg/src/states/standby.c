#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __STANDBY__
#endif

int standby_state(Thresholds thresholds) {
	printf("STANDBY!\n");
	printf("threshold stuct values: bd:%f ad:%f %f %f %f\n", 
		thresholds.brake_distance, 
		thresholds.acceleration_distance, 
		thresholds.battery_temperature_low, 
		thresholds.battery_temperature_high, 
		thresholds.battery_temperature_pers);

	//Emergency brake
	if (estop_command) {
		return ESTOP;
	}
	else if (prelaunch_command) {
		printf("PRELAUNCH COMMAND RECEIVED!\n");
		return SUCCESS;
	}
	else if (enter_service_command) {
		printf("ENTER SERVICE COMMAND RECEIVED!\n");
		return SUCCESS;
	}

	return REPEAT;
}

