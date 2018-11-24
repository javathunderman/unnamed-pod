#ifndef __STATES__
/* This is where our state includes will live */
#include "standby.c"
#include "service.c"
#include "initialize.c"
#include "accelerate.c"
#include "normbrake.c"
#include "estop.c"

#define __STATES__
#endif

#define NUM_STATES 6
enum State_Status {SUCCESS = 0, SOMETHING = 1, ESTOP = 5}; 
