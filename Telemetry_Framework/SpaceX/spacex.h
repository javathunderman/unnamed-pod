#ifndef SPACEX_H
#define SPACEX_H

#define SPACEX_IP "192.168.0.1"
#define SPACEX_PORT 3000


typedef struct {
    Fault,
    SafeToApproach,
    ReadyToLaunch,
    Launching,
    Coasting,
    Braking,
    Crawling
} SpaceXState;

typdef struct {
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
int send_spacex(Telemetry *tlm);
SpaceXState convert_state(Telemetry *tlm);


#endif