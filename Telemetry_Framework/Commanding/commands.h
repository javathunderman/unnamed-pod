#ifndef COMMANDS_H
#define COMMANDS_H

#include <pthread.h>

#define NOOP  0x00
#define ESTOP 0xFF
#define ACK   0xF0

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
