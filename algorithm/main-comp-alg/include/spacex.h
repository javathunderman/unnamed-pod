#ifndef SPACEX_H
#define SPACEX_H

#include "telemetry.h"

#define SPACEX_IP "192.168.0.1"
#define SPACEX_PORT 3000


typedef enum {
    Fault,
    SafeToApproach,
    ReadyToLaunch,
    Launching,
    Coasting,
    Braking,
    Crawling
} SpaceXState;

typedef struct {
    unsigned int team_id : 8;
    unsigned int status : 8;
    int acceleration : 32;
    int position : 32;
    int velocity : 32;
    int unused_1 : 32;            /* Previously battery voltage */
    int unused_2 : 32;            /* Previously battery current */
    int unused_3 : 32;            /* Previously battery temp    */
    int unused_4 : 32;            /* Previously pod temp        */
    unsigned int unused_5 : 32;   /* Previously tape count      */
} SpaceXFrame;


int init_spacex(void);
int send_spacex(int socket, Telemetry *tlm, UMData *data);
SpaceXState convert_state(int pod_state);


#endif