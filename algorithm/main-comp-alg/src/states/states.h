#ifndef __STATES__
/* This is where our state includes will live */
typedef enum {STANDBY_SID = 0, INITIALIZE_SID = 1, SERVICE_SID = 2, ACCELERATE_SID = 3, NORMBRAKE_SID = 4, ESTOP_SID = 5, IDLE_SID = 6, NUM_STATES} State; 
typedef enum {SUCCESS = 0, REPEAT = 1, ERROR = 2, ESTOP = 3, NUM_CODES} State_Status; 
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

int standby_state(Thresholds);
int initialize_state(Thresholds);
int service_state(Thresholds);
int accelerate_state(Thresholds);
int normbrake_state(Thresholds);
int estop_state(Thresholds);
int idle_state(Thresholds);

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

	