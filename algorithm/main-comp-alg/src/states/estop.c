#ifndef __ESTOP__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ESTOP__
#endif

int estop_state() {
	printf("EMERGENCY STOP!\n");

	if (acknowledge_command) {
		return SUCCESS;
	}

	return REPEAT;
}