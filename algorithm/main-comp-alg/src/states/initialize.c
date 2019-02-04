#ifndef __INITIALIZE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __INITIALIZE__
#endif

int initialize_state() {
	printf("INITIALIZING...\n");
	//Do Initialization stuff here

	//Maybe a loop to wait for launch command

	return SUCCESS;
}
