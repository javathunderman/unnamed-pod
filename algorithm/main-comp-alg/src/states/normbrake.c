#ifndef __NORMBRAKE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __NORMBRAKE__
#endif

int normbrake_state() {
	printf("NORMAL BRAKING!\n");

	//check speed, repeat until zero?

	if (acknowledge_command) {
		return SUCCESS;
	}

	return REPEAT;
}
