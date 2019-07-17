#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __STANDBY__
#endif

int standby_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> STANDBY STATE - Command: %d\n", command);
	/*printf("threshold stuct values: bd:%f ad:%f %f %f %f\n", 
		thresholds.brake_distance, 
		thresholds.acceleration_distance, 
		thresholds.battery_temperature_low, 
		thresholds.battery_temperature_high, 
		thresholds.battery_temperature_pers);*/

	//(H8) E-STOP
	if (command == EMERGENCY_BRAKE) {
		return ESTOP_SID;
	}
	
	//(H7) Shutdown
	if (command == SHUTDOWN) {
		//Power off
	}
	
	if (command == PRELAUNCH) {
		printf("PRELAUNCH COMMAND RECEIVED!\n");
		return INITIALIZE_SID;
	}
	else if (command == ENTER_SERVICE) {
		printf("ENTER SERVICE COMMAND RECEIVED!\n");
		return SERVICE_SID;
	}

	return STANDBY_SID;
}

