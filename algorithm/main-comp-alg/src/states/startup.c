#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

int startup_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> STARTUP STATE\n");

	//Do startup stuff here

	

	return STANDBY_SID;
}
