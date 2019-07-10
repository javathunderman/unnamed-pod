#include <stdio.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "commands.h"
#include "receiver.h"
#include "priority.h"
#include "abort_run.h"

#define RECV_LEN 100


/* This function runs as a thread continuously to receive commands.
 * Commands are written to a command buffer used by the state machine.
 * Invalid commands and timeout trigger comm loss condition.
 * 
 * Params:
 *     int sock -> socket (timeout already configured: see udp.c)
 * 
 * Returns:
 *     Never
 *     TODO Comm loss will trigger signal
 */
void *recv_cmds(void *args) {
    int sock = ((ReceiverArgs *)args)->sock;
    CommandBuffer *cb = ((ReceiverArgs *)args)->cb;
    char buffer[RECV_LEN];
    int cmd, len;
    const struct sched_param priority = {CMD_RECEIVE_PRIO};
    
    /* Set thread priority */
    if (pthread_setschedparam(pthread_self(), SCHED_FIFO, &priority) != 0) {
        printf("Failed to set CMD thread priority\n");
        return NULL;
    }
    
    while (1) {
        /* Receive 1 command, failures and timeout trigger comm loss condition */
        len = recvfrom(sock, &buffer, RECV_LEN, 0, NULL, NULL);
        if (len == -1) {
            ABORT_RUN;
            printf("Receiver Error: recvfrom returned -1: %s\n", strerror(errno));
            //TODO: return, rebuild socket, relaunch only if != ETIMEDOUT
        }

        /* Verify magic word, pass command to state machine */
        if (len == 8 && *((int *)&buffer) == 0xC0DE) {
            cmd = *(((int *)&buffer) + 1); 
            if (verify_cmd(cmd) && (write_cmd(cb, cmd) == 0)) {
                printf("Received: %d\n", cmd);
                //TODO Telemeter success
            } else {
                if (cmd != NONE) {
                    ABORT_RUN;
                    printf("Invalid Command: %d\n", cmd);
                }
            }
        }
    }
}

/* This function checks the validity of a received command.
 * 
 * Params:
 *     int cmd -> received from host
 * 
 * Returns:
 *     true  -> valid command
 *     false -> invalid command
 */
int verify_cmd(int cmd) {
    if (cmd == EMERGENCY_BRAKE || (cmd > 0 && cmd < NUM_COMMANDS)) {
        return true;
    }
    
    return false;
}
