#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

int startup_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> STARTUP STATE\n");

	if (NiFpga_IsNotError(write_actuate_brakes(fpga, NiFpga_False))) {
		printf("ERROR: fpga failed to actuate brakes!");
	}

	return STANDBY_SID;
}
