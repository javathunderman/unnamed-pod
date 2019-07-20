#ifndef COMMANDS_H
#define COMMANDS_H

#include <pthread.h>

#define ACK   0xF0


typedef enum {
    NONE = 0x00,
    PRELAUNCH = 0x01,
    ENTER_SERVICE = 0x02,
    LAUNCH = 0x03,
    ABORT_LAUNCH = 0x04,
    ENTER_STANDBY = 0x05,
    START_SERVICE_PROPULSION = 0x06,
    STOP_SERVICE_PROPULSION = 0x07,
    DEPRESSURIZE = 0x08,
    SLOW_SERVICE_PROPULSION = 0x09,
    MEDIUM_SERVICE_PROPULSION = 0x0A,
    FAST_SERVICE_PROPULSION = 0x0B,
    FORWARD_SERVICE_PROPULSION = 0x0C,
    BACKWARD_SERVICE_PROPULSION = 0x0D,
    ENTER_STATE_MACHINE = 0x0E,
    PRECHARGE = 0x0F,
    DISCHARGE = 0x10,
    SHUTDOWN = 0x11,
    ACTUATE_BRAKES = 0x12,
    OPEN_ELECTRONIC_DRAIN_VALVE = 0x13,
    FIRST_LOW_VOLTAGE_SHUTOFF = 0x14,
    SECOND_LOW_VOLTAGE_SHUTOFF = 0x15,
    FIRST_BATTERY_ON = 0x16, 
    SECOND_BATTERY_ON = 0x17,
    CLOSE_FIRST_RELAY = 0x18,
    OPEN_FIRST_RELAY = 0x19,
    CLOSE_SECOND_RELAY = 0x1A,
    OPEN_SECOND_RELAY = 0x1B,
    CLOSE_THIRD_RELAY = 0x1C,
    OPEN_THIRD_RELAY = 0x1D,
    CLOSE_FOURTH_RELAY = 0x1E,
    OPEN_FOURTH_RELAY = 0x1F,
    ENTER_PRE_CHARGE = 0x20,
    ENTER_ENABLE_MOTOR = 0x22,
    RUN_ABORT = 0x23,
    SLEEP = 0x24,//remove sleep command?
    ENTER_SERVICE_PROPULSION = 0x25,
    BEGIN_MOTOR_CONTROLLER_STARTUP = 0x26,
    SET_MOTOR_CONTROLLER_ACTIVE = 0x27,
    FREE_SPIN_MOTOR = 0x28,
    
    
    
    NUM_COMMANDS,
    EMERGENCY_BRAKE = 0xFF
} Command; 

typedef struct {
    volatile int *buffer;
    volatile int size;
    volatile int head;
    volatile int tail;
    volatile int estop;
    pthread_mutex_t mutex;
} CommandBuffer;


int init_cmd_buffer(CommandBuffer *cb, volatile int *buff, int max_length);
int read_cmd(CommandBuffer *cb, int *cmd);
int write_cmd(CommandBuffer *cb, int cmd);
int ack_estop(CommandBuffer *cb);

#endif
