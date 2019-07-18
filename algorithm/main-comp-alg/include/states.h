#ifndef __STATES__
/* This is where our state includes will live */
#include "commands.h"
#include "fpga_cache.h"
#include "can_master.h"

typedef enum {STARTUP_SID, STANDBY_SID, INITIALIZE_SID, SERVICE_SID, PRECHARGE_SID, ENABLEMOTOR_SID, ACCELERATE_SID, NORMBRAKE_SID, ESTOP_SID, IDLE_SID, HVCUT_SID, DISCHARGE_SID, ENDRUN_SID, NUM_STATES} State;

typedef struct {
    pthread_t can_tid;
    pthread_t tlm_tid;
    pthread_t cmd_tid;
    Command last_cmd;
    time_t last_cmd_sec;
    long last_cmd_nsec;
    int pod_state;
} Software_Data;

typedef struct {
    FpgaCache fpga_cache;
    CAN_Data can_data;
    Software_Data software;
} UMData;

typedef struct {
    float track_length;
    float brake_distance;
    float acceleration_distance;
    float battery_temperature_low;
    float battery_temperature_high;
    float battery_temperature_pers;
    float motor_temperature_low;
    float motor_temperature_high;
    float motor_temperature_pers;
    float i_should_be_unassigned;
} Thresholds;

int startup_state(Fpga*, Thresholds*, int);
int standby_state(Fpga*, Thresholds*, int);
int initialize_state(Fpga*, Thresholds*, int);
int service_state(Fpga*, Thresholds*, int);
int precharge_state(Fpga*, Thresholds*, int);
int enablemotor_state(Fpga*, Thresholds*, int);
int accelerate_state(Fpga*, Thresholds*, int);
int normbrake_state(Fpga*, Thresholds*, int);
int estop_state(Fpga*, Thresholds*, int);
int idle_state(Fpga*, Thresholds*, int);
int hvcut_state(Fpga*, Thresholds*, int);
int discharge_state(Fpga*, Thresholds*, int);

//temporary thresholds, commands, and other values for transition logic
#define estop_command 0
#define acknowledge_command 1 //braking acknowledgement
//available in standby state:
#define prelaunch_command 1
#define enter_service_command 0
//available in initialize state:
#define launch_command 1
#define abort_launch_command 0
//available in service state:
#define enter_standby_command 0
#define start_service_propulsion_command 0
#define stop_service_propulsion_command 0
#define depressurize_command 0
#define slow_service_propulsion_command 0
#define medium_service_propulsion_command 0
#define fast_service_propulsion_command 0
#define forward_service_propulsion_command 0
#define backward_service_propulsion_command 0


#define __STATES__
#endif

    
