#ifndef __ACCELERATE__
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "states.h"

#define __ACCELERATE__
#endif

int testaccel_counter = 0;

int accelerate_state() {
	printf("ACCELERATING: %d\n", testaccel_counter);

	while (testaccel_counter < 10) {
		testaccel_counter += 1;
		return REPEAT;
	}
	return SUCCESS;
}
