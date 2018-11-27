#ifndef __STANDBY__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __STANDBY__
#endif

int standby_state() {
	printf("STANDBY!\n");

	return REPEAT;
}

