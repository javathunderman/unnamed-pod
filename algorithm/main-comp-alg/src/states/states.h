#ifndef __STATES__
/* This is where our state includes will live */
#define NUM_STATES 6
#define NUM_CODES 6
typedef enum {STANDBY_SID = 0, INITIALIZE_SID = 1, SERVICE_SID = 2, ACCELERATE_SID = 3, NORMBRAKE_SID = 4, ESTOP_SID = 5} State; 
typedef enum {SUCCESS = 0, REPEAT = 1, ESTOP = 5} State_Status; 

#define __STATES__
#endif

