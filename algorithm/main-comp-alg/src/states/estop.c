#ifndef __ESTOP__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ESTOP__
#endif

int estop_state() {
	active = 0;
	last_state = ESTOP_SID;
	printf("EMERGENCY STOP!\n");

	return SUCCESS;
}