#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

int initialize_state() {
	active = 1;
	last_state = INITIALIZE_SID;
	printf("INITIALIZING\n");

	return SUCCESS;
}
