#ifndef __ACCELERATE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ACCELERATE__
#endif

int accelerate_state(Fpga *fpga, Thresholds *thresholds, int command) {
	int motor_temp = 998; //<- fake temp for logic
	printf(">> ACCELERATE STATE - fake position: %d\n", pod_position);

	//(H8) E-STOP
	if (command == EMERGENCY_BRAKE || motor_temp > (*thresholds).motor_temperature_high) {
		printf("ESTOP: fake position: %d\n", pod_position);
		return ESTOP_SID;
	}

	fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_False), "retract brakes");
	//TODO: Motor driving
	//TODO: Autonomy granted

	//(C7) Any Critical Fault
	if (0) {
		return HVCUT_SID;
	}
	//(C6) Any Fault
	if (0) {
		return ESTOP_SID;
	}
	//(C5) Any Distance or Time Threshold
	if ((*thresholds).track_length - pod_position <= (*thresholds).brake_distance
		|| 0) {
		printf("NORMAL BRAKE: fake position: %d\n", pod_position);
		return NORMBRAKE_SID;
	}
	//Continue to accelerate
	else {
		//get pod position from IMU and light sensors, logic goes here
		//FULL THROTTLE!
		return ACCELERATE_SID;
	}

	
}