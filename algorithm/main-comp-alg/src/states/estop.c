#include "./states/states.h"

int estop_state() {
	active = 0;
	last_state = ESTOP_SID;
	printf("EMERGENCY STOP!\n");

	return SUCCESS;
}