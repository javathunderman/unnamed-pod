#ifndef __STATES__
/* This is where our state includes will live */
typedef enum {STANDBY_SID = 0, INITIALIZE_SID = 1, SERVICE_SID = 2, ACCELERATE_SID = 3, NORMBRAKE_SID = 4, ESTOP_SID = 5, NUM_STATES} State; 
typedef enum {SUCCESS = 0, REPEAT = 1, ERROR = 2, ESTOP = 3, NUM_CODES} State_Status; 

#define __STATES__
#endif

