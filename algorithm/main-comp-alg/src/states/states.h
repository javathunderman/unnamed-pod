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
enum State {STANDBY_SID = 0, INITIALIZE_SID = 1, SERVICE_SID = 2, ACCELERATE_SID = 3, NORMBRAKE_SID = 4, ESTOP_SID = 5}; 
enum State_Status {SUCCESS = 0, SOMETHING = 1, ESTOP = 5}; 

