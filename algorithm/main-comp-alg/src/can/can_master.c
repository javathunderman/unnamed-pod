#include <stdio.h>
#include <time.h>
#include "can_master.h"
#include "can_handlers.h"
#include "vs_can_api.h"


/* Global variables */
VSCAN_MSG request_lookup[NUM_CAN_REQUESTS];
VSCAN_MSG response_lookup[NUM_CAN_RESPONSES];
VSCAN_HANDLE handle;


void *can_master(void *args) {
    
}
