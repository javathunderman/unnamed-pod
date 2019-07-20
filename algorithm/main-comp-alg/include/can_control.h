#ifndef CAN_CONTROL_H
#define CAN_CONTROL_H

#include "utils.h"

#define MAX_CAN_RETRIES 3

/* Called by master CAN thread */
void control_cycle(CAN_Data *data, int cycle_num);

/* Called by state machine */
FSM_Status can_motor_ready(CAN_Data *data);
FSM_Status can_motor_enable(CAN_Data *data);
FSM_Status can_motor_constants(CAN_Data *data);
FSM_Status can_motor_precharge(CAN_Data *data);
FSM_Status can_motor_start_highrate(CAN_Data *data);
FSM_Status can_motor_stop_highrate(CAN_Data *data);
FSM_Status can_motor_end_run(CAN_Data *data);
FSM_Status can_reset_precharge(CAN_Data *data);

#endif
