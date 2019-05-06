#ifndef __SERVICE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __SERVICE__
#endif

int service_state(Thresholds thresholds, CommandBuffer *cb) {
	printf("SERVICE MODE BEEP BOOP!\n");

	return SUCCESS;
}

