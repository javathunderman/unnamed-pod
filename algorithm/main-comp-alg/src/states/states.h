#ifndef __STATES__
/* This is where our state includes will live */
#include "../../../../Telemetry_Framework/Commanding/commands.h"
typedef enum {STARTUP_SID, STANDBY_SID, INITIALIZE_SID, SERVICE_SID, ACCELERATE_SID, NORMBRAKE_SID, ESTOP_SID, IDLE_SID, NUM_STATES} State; 
typedef enum {SUCCESS = 0, REPEAT = 1, SERVICE = 2, ERROR = 3, ESTOPP = 4, NUM_CODES} State_Status; 
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
	EMERGENCY_BRAKE = 0xFF
	} Command; 


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

typedef struct {
	Command command;
	//Mark struct
} Data;

int startup_state(Thresholds, int);
int standby_state(Thresholds, int);
int initialize_state(Thresholds, int);
int service_state(Thresholds, int);
int accelerate_state(Thresholds, int);
int normbrake_state(Thresholds, int);
int estop_state(Thresholds, int);
int idle_state(Thresholds, int);

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

	