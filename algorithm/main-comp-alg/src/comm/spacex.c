#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h> 
#include <string.h>
#include "telemetry.h"
#include "spacex.h"
#include "states.h"


/* Static variables for SpaceX communication */
static struct sockaddr_in spacex_addr;
static SpaceXFrame msg;

/* This function initializes variables for communication to SpaceX.
 * This function needs to be called before send_spacex().
 * This function should only be called once during startup.
 *
 * Params:
 *     None
 *
 * Returns:
 *      0 -> success
 *     -1 -> socket creation failure
 */
int init_spacex(void) {
    
    /* Configure SpaceX address */
    bzero(&spacex_addr, sizeof(spacex_addr));
    spacex_addr.sin_family = AF_INET;
    spacex_addr.sin_addr.s_addr = inet_addr(SPACEX_IP);
    spacex_addr.sin_port = htons(SPACEX_PORT);
    
    /* Zero message frame */
    bzero(&msg, sizeof(msg));
    
    /* Return success */
    return 0;
}

/* This function sends one packet to SpaceX.
 * This function must be called after init_spacex() has succeeded.
 *
 * Params:
 *     Telemetry *tlm -> pointer to most recent pod telemetry packet
 *
 * Returns:
 *      0 -> success
 *     -1 -> error
 */
int send_spacex(int socket, Telemetry *tlm, UMData *data) {
    
    /* Update message frame */
    //TODO waiting for data from Mark
    
    /* Send message frame */
    if(sendto(socket, &msg, sizeof(msg), 0, (SA *) &spacex_addr, sizeof(spacex_addr)) == -1) {
            printf("SpaceX telemetry send failure...\n");
            printf("%s\n", strerror(errno));
            return -1;
    }
    
    /* Return success */
    return 0;
}

/* This function converts internal pod states to SpaceX states for telemetry.
 *
 * Params:
 *     int pod_state -> pod's current internal state
 *
 * Returns:
 *     SpaceXState corresponding to current state
 */
SpaceXState convert_state(int pod_state) {
    SpaceXState state;
    
    //TODO Update with veclocity checks, etc.
    switch (pod_state) {
        case STARTUP_SID    : state = SafeToApproach; break;
        case STANDBY_SID    : state = SafeToApproach; break;
        case INITIALIZE_SID : state = ReadyToLaunch;  break;
        case SERVICE_SID    : state = Crawling;       break;
        case ACCELERATE_SID : state = Launching;      break;
        case NORMBRAKE_SID  : state = Braking;        break;
        case ESTOP_SID      : state = Fault;          break;
        case IDLE_SID       : state = SafeToApproach; break;
        default             : state = Fault;          break;
    }
    
    return state;
}

