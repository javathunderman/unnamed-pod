#ifndef COMMANDS_H
#define COMMANDS_H

#include <pthread.h>

#define ACK   0xF0


typedef enum {
    NONE = 0x00, 
    ENTER_STANDBY = 0x01, 
    PRELAUNCH = 0x02, 
    ENTER_SERVICE = 0x03, 
    PRECHARGE = 0x04, 
    LAUNCH = 0x05, 
    DISCHARGE = 0x06, 
    SHUTDOWN = 0x07, 
    LAUNCH_INITIALIZE = 0x08, 
    ABORT_LAUNCH = 0x09, 
    START_SERVICE_PROPULSION = 0x0A,
    STOP_SERVICE_PROPULSION = 0x0B,
    DEPRESSURIZE = 0x0C,
    SLOW_SERVICE_PROPULSION = 0x0D,
    MEDIUM_SERVICE_PROPULSION = 0x0E,
    FAST_SERVICE_PROPULSION = 0x0F,
    FORWARD_SERVICE_PROPULSION = 0x10,
    BACKWARD_SERVICE_PROPULSION = 0x11,
    
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
