#ifndef __ACCELERATE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ACCELERATE__
#endif

int accelerate_state() {
	static int pod_position = 0;
	int motor_temp = 200; //<- fake temp for logic

	printf("ACCELERATING: fake position: %d\n", pod_position);

	//Emergency brake
	if (estop_command || motor_temp > max_motor_temp) {
		return FAILURE;
	}
	//End of tube regular brake
	else if (track_length - pod_position <= min_distance_from_end) {
		return SUCCESS;
	}
	//Continue to accelerate
	else {
		//FULL THROTTLE!
		pod_position += 10;
		return REPEAT;
	}

	
}