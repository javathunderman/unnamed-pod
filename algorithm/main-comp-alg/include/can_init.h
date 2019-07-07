#ifndef CAN_INIT_H
#define CAN_INIT_H

#include "can_master.h"

/* CAN initialization */
int can_init(CAN_Data *data);
void init_can_requests(void);
void init_can_responses(void);
void init_can_data(CAN_Data *data);

#endif
