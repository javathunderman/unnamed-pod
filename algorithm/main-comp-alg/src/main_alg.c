#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <yaml.h>
#include "./sensors/sensors.h"
#include "./states/states.h"

//typedef enum {STANDBY_SID = 0, INITIALIZE_SID = 1, SERVICE_SID = 2, ACCELERATE_SID = 3, NORMBRAKE_SID = 4, ESTOP_SID = 5} State; 
//typedef enum {SUCCESS = 0, REPEAT = 1, ERROR = 4, ESTOP = 5} State_Status; 
typedef enum {STOPPING_DISTANCE, THRESHOLD1_LOW, THRESHOLD1_HIGH, THRESHOLD2_LOW, THRESHOLD2_HIGH, TEST1, TEST2, TEST3, TEST4} Config;

int main() {
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
				
				if (strcmp("brake_distance", type) == 0) {
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

				i++;
				token = strtok(NULL, ",");
			}
			
		}
		fclose ( config_file );
	}

	printf("threshold stuct values: bd:%f ad:%f %f %f %f\n", 
		thresholds.brake_distance, 
		thresholds.acceleration_distance, 
		thresholds.battery_temperature_low, 
		thresholds.battery_temperature_high, 
		thresholds.battery_temperature_pers);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// REST OF STATE CODE STARTS HERE                                                               //
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int transitions[NUM_STATES][NUM_CODES]; //transitions
	int (*fp_arr[NUM_STATES]) (void);   //state function calls

	//1D array of Function Pointers to state functions
	fp_arr[STANDBY_SID] = &standby_state;
	fp_arr[INITIALIZE_SID] = &initialize_state;
	fp_arr[SERVICE_SID] = &service_state;
	fp_arr[ACCELERATE_SID] = &accelerate_state;
	fp_arr[NORMBRAKE_SID] = &normbrake_state;
	fp_arr[ESTOP_SID] = &estop_state;

	//2D Logic state array settings
	transitions[INITIALIZE_SID][SUCCESS] = ACCELERATE_SID;
	transitions[INITIALIZE_SID][ERROR] = STANDBY_SID;
	transitions[ACCELERATE_SID][REPEAT] = ACCELERATE_SID;
	transitions[ACCELERATE_SID][SUCCESS] = NORMBRAKE_SID;
	transitions[ACCELERATE_SID][ERROR] = ESTOP_SID;
	transitions[NORMBRAKE_SID][SUCCESS] = STANDBY_SID;
	transitions[NORMBRAKE_SID][ERROR] = ESTOP_SID;
	transitions[ESTOP_SID][SUCCESS] = STANDBY_SID;
	transitions[STANDBY_SID][REPEAT] = STANDBY_SID;
	transitions[STANDBY_SID][SUCCESS] = INITIALIZE_SID;
	
	printf("################################################################\n");
	printf("#                     beginning of run                         #\n");
	printf("################################################################\n");

	//Initial values for state flow
	int last_state = STANDBY_SID;
	int return_code = standby_state();
	
	//main state loop
	while (1) {
		last_state = transitions[last_state][return_code];
		return_code = (*fp_arr[last_state])();
		//state = transitions[state][(*functions[state])()]
	}

	return 0;
}



//REST OF COMMENTED CODE IS FOR FUTURE REFERENCE - Jerry

/*int testfun(int i) {
	printf("Printing integer: %d\n", i);
	return 0;
}

void *threadfun(void * i) {
	//pthread_mutex_lock(&state_mutex);
	int *ii = (int *)i;
	printf("Printing integer from thread: %d\n", *ii);
	//pthread_mutex_unlock(&state_mutex);
	return NULL;
}

 thread_ids[0] = State
	 * thread_ids[1] = FPGA read
	 * thread_ids[2] = Telem send
	 * thread_ids[3] = Read commands
	 */
	/*pthread_t thread_ids[NUM_THREADS];
	void (*testfun_ptr)(int) = &testfun;
	void * (*threadfun_ptr)(void *) = &threadfun;
	int *param = (int *)malloc(2*sizeof(int));
	int *params[NUM_THREADS];

	int i;
	for (i = 0; i < NUM_THREADS; i++) {
		params[i] = (int *)malloc(2*sizeof(int));
	}
	
	fp_arr[1][1] = &threadfun;

	param[0] = 100;
	param[1] = 200;

	for (i = 0; i < NUM_THREADS; i++) {
		pthread_create(&thread_ids[i], NULL, fp_arr[1][1], params[i]); 
	}

	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(thread_ids[i], NULL); 
	}
	pthread_join(thread_id, NULL); 
	free(param);*/
