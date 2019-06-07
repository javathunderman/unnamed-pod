#ifndef COMMANDS_H
#define COMMANDS_H

#include <pthread.h>

#define ACK   0xF0


typedef enum {
    NONE = 0x00, 
    PRELAUNCH = 0x01, 
    ENTER_SERVICE = 0x02, 
    LAUNCH_INITIALIZE = 0x03, 
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
