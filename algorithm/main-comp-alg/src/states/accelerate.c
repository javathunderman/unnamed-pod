#ifndef __ACCELERATE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ACCELERATE__
#endif



int accelerate_state() {
	static int testaccel_counter = 0;

	printf("ACCELERATING: %d\n", testaccel_counter);

	if (testaccel_counter < 10) {
		testaccel_counter += 1;
		return REPEAT;
	}

	return SUCCESS;
}
