#include "commands.h"
#include <errno.h>
#include <pthread.h>


/* This function initializes the specified command buffer.
 * This needs to be called before read/write on a CommandBuffer.
 * The underlying int[] should be declared volatile for safe
 * multi-threaded manipulation.
 *
 * Params:
 *     CommandBuffer *cb -> should point to an uninitialized CommandBuffer
 *     int *buff         -> should point an int[]
 *     int max_length    -> should be the size of buff
 *
 * Returns:
 *     0 on success
 *     non-zero error code on failure
 *
 * WARNING: pthread_mutex_init has undefined behavior when called
 * more than once on a mutex
 * */
int init_cmd_buffer(CommandBuffer *cb, volatile int *buff, int max_length) {
    cb->head = 0;
    cb->tail = 0;
    cb->estop = NONE;
    cb->size = max_length;
    cb->buffer = buff;
    int retval = pthread_mutex_init(&(cb->mutex), NULL);
    return retval;
}

/* This function writes one command to the buffer.
 * This function blocks until the buffer is available for writing.
 *
 * Params:
 *     CommandBuffer *cb -> pointer to initialized CommandBuffer
 *     int cmd           -> the command to be written to the buffer
 *
 * Returns:
 *     0      -> success
 *     ENOMEM -> buffer is full
 *     else   -> mutex failure
 */
int write_cmd(CommandBuffer *cb, int cmd) {
    int error = pthread_mutex_lock(&(cb->mutex));
    
    if (!error) {
        if (cmd == EMERGENCY_BRAKE) {
            if (cb->estop == ACK) {
                cb->estop = NONE;
            } else {
                cb->estop = EMERGENCY_BRAKE;
            }
        } else if ((cb->tail + 1 == cb->head) || ((cb->tail + 1 == cb->size) && cb->head == 0)) {
            /* Buffer is full */
            error = ENOMEM;
        } else {
            /* Write command to next slot in buffer, increment tail */
            (cb->buffer)[cb->tail] = cmd;
            cb->tail = (cb->tail == (cb->size - 1)) ? 0 : cb->tail + 1;
        }
        error |= pthread_mutex_unlock(&(cb->mutex));
    }
    
    return error;
}

/* This function reads one command from the buffer.
 * Commands will be read from the buffer in FIFO fashion.
 * This function is non-blocking, see pthread_mutex_trylock().
 * If EMERGENCY_BRAKE is received, no other commands can be read until
 * appropriate action is taken and ack_estop() is called.
 *
 * Params:
 *     CommandBuffer *cb -> the CommandBuffer to read from
 *     int *cmd          -> location to put the read cmd
 *
 * Returns:
 *     0     -> success, int *cmd will be populated with oldest unread cmd
 *                       or 0 if there are no new commands to be read
 *     EBUSY -> CommandBuffer is in use, try again
 *     else  -> failure, int *cmd should be ignored
 */
int read_cmd(CommandBuffer *cb, int *cmd) {
    int error = pthread_mutex_trylock(&(cb->mutex));
    
    if (!error) {
        if (cb->estop == EMERGENCY_BRAKE) {
            /* Need to ack_estop() to clear */
            *cmd = EMERGENCY_BRAKE;
        } else if (cb->head == cb->tail) {
            /* Buffer empty */
            *cmd = NONE;
        } else {
            /* Read command, increment head */
            *cmd = (cb->buffer)[(cb->head)];
            cb->head = (cb->head == (cb->size - 1)) ? 0 : cb->head + 1;
        }
        error = pthread_mutex_unlock(&(cb->mutex));
    }
    
    return error;
}

/* This function acknowledges EMERGENCY_BRAKE.
 * This function is non-blocking, see pthread_mutex_trylock().
 * This should be called after reading EMERGENCY_BRAKE from the buffer and taking 
 * appropriate action.
 *
 * Params:
 *     CommandBuffer *cb -> the CommandBuffer to ack
 *
 * Returns:
 *     0 -> success
 *     EBUSY -> CommandBuffer is in use, try again
 *     else  -> mutex failure
 */
int ack_estop(CommandBuffer *cb) {
    /* TODO: Figure out how to tell control to stop spamming EMERGENCY_BRAKE */
    
    int error = pthread_mutex_trylock(&(cb->mutex));
    
    if (!error) {
        cb->estop = ACK;
        error = pthread_mutex_unlock(&(cb->mutex));
    }
    
    return error;
}
