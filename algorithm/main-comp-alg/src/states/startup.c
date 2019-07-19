#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"
#include "fpga_cache.h"

#define __INITIALIZE__
#endif

int startup_state(Fpga *fpga, Thresholds *thresholds, int command) {
	printf(">> STARTUP STATE\n");

	fpgaRunAndUpdateIf(fpga, write_actuate_brakes(fpga, NiFpga_False), "retract brakes");

	//TODO: Deploy run configs

	return NiFpga_IsNotError(fpga->status) ? STANDBY_SID : ENDRUN_SID;
}
