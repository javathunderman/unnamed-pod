#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sensors.h"
#include "states.h"
#include "commands.h"
#include "spacex.h"
#include "udp.h"

typedef enum {STOPPING_DISTANCE, THRESHOLD1_LOW, THRESHOLD1_HIGH, THRESHOLD2_LOW, THRESHOLD2_HIGH, TEST1, TEST2, TEST3, TEST4} Config;

int main() {
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// INIT COMMAND BUFFER                                                                          //
	//////////////////////////////////////////////////////////////////////////////////////////////////
	CommandBuffer cb;
	volatile int buffer[50];

	if (init_cmd_buffer(&cb, buffer, 50) != 0) {
		perror("ERROR: Failed to initialize command buffer!");
		return 1;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// INIT SPACEX TELEMETRY                                                                        //
	//////////////////////////////////////////////////////////////////////////////////////////////////
	if (init_spacex() != 0) {
		return 2;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// CONFIG LOADING CODE                                                                          //
	//////////////////////////////////////////////////////////////////////////////////////////////////
	Thresholds thresholds;
	char filename[] = "config.csv";
	FILE *config_file = fopen(filename, "r");

	printf("################################################################\n");
	printf("#                       reading csv                            #\n");
	printf("################################################################\n");

	if ( config_file == NULL ) { /* error opening file */
		printf("ERROR: cannot open file: %s\n", filename);
		return 0;
	}
	else {
		char line [128]; /* or other suitable maximum line size */
		while (fgets ( line, sizeof line, config_file ) != NULL) { /* read a line */
			printf("%s", line); 
			char *token = strtok(line, ",");
			char *type = token;
			int i = 1;

			token = strtok(NULL, ",");
			
			while( token != NULL ) {
				char *curr_tok = token;
				
				if (strcmp("track_length", type) == 0) {
					if (i == 1) thresholds.track_length = atof(curr_tok);
					else {
					}
				}
				else if (strcmp("brake_distance", type) == 0) {
					if (i == 1) thresholds.brake_distance = atof(curr_tok);
					else {
					}
				}
				else if (strcmp("acceleration_distance", type) == 0) {
					if (i == 1) thresholds.acceleration_distance = atof(curr_tok);
					else {
					}
				}
				else if (strcmp("battery_temperature", type) == 0) {
					if (i == 1) thresholds.battery_temperature_low = atof(curr_tok);
					else if (i == 2) thresholds.battery_temperature_high = atof(curr_tok);
					else if (i == 3) thresholds.battery_temperature_pers = atof(curr_tok);
					else {
					}
				}
				else if (strcmp("motor_temperature", type) == 0) {
					if (i == 1) thresholds.motor_temperature_low = atof(curr_tok);
					else if (i == 2) thresholds.motor_temperature_high = atof(curr_tok);
					else if (i == 3) thresholds.motor_temperature_pers = atof(curr_tok);
					else {
					}
				}

				i++;
				token = strtok(NULL, ",");
			}	
		}
		fclose ( config_file );
	}

	//Edit for manual testing
	printf("threshold stuct values: bd:%f ad:%f %f %f %f\n", 
		thresholds.brake_distance, 
		thresholds.acceleration_distance, 
		thresholds.battery_temperature_low, 
		thresholds.battery_temperature_high, 
		thresholds.battery_temperature_pers);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// INIT UDP COMMUNICATION                                                                       //
	//////////////////////////////////////////////////////////////////////////////////////////////////
	if(udp_init(&cb) != 0) {
		return 3;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// REST OF STATE CODE STARTS HERE                                                               //
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int (*fp_arr[NUM_STATES]) (Thresholds *, int);   //state function calls

	//1D array of Function Pointers to state functions
	fp_arr[STARTUP_SID] = &startup_state;
	fp_arr[STANDBY_SID] = &standby_state;
	fp_arr[INITIALIZE_SID] = &initialize_state;
	fp_arr[SERVICE_SID] = &service_state;
	fp_arr[ACCELERATE_SID] = &accelerate_state;
	fp_arr[NORMBRAKE_SID] = &normbrake_state;
	fp_arr[ESTOP_SID] = &estop_state;
	fp_arr[IDLE_SID] = &idle_state;
	
	printf("################################################################\n");
	printf("#                     beginning of run                         #\n");
	printf("################################################################\n");

	//Initial values for state flow
	int command = 0;
	int next_state = startup_state(&thresholds, command);
	
	//main state loop
	while (1) {
		read_cmd(&cb, &command);
		next_state = (*fp_arr[next_state])(&thresholds, command);
	}

	return 0;
}
