#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
//#include <yaml.h>
#include "./sensors/sensors.h"
#include "./states/states.h"

//typedef enum {STANDBY_SID = 0, INITIALIZE_SID = 1, SERVICE_SID = 2, ACCELERATE_SID = 3, NORMBRAKE_SID = 4, ESTOP_SID = 5} State; 
//typedef enum {SUCCESS = 0, REPEAT = 1, ERROR = 4, ESTOP = 5} State_Status; 
typedef enum {STOPPING_DISTANCE, THRESHOLD1_LOW, THRESHOLD1_HIGH, THRESHOLD2_LOW, THRESHOLD2_HIGH, TEST1, TEST2, TEST3, TEST4} Config;

int main() {
	//Do it in python, pyyaml
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// CONFIG LOADING CODE                                                                          //
	//////////////////////////////////////////////////////////////////////////////////////////////////
	/*Thresholds thresholds;

	FILE *fh = fopen("config.yaml", "r");
	yaml_parser_t parser;
	yaml_token_t  token;

	/* Initialize parser */
	/*if(!yaml_parser_initialize(&parser))
		fputs("Failed to initialize parser!\n", stderr);
	if(fh == NULL)
		fputs("Failed to open file!\n", stderr);

	/* Set input file */
	/*yaml_parser_set_input_file(&parser, fh);

	int token_id = -1;
	/* CODE HERE */
	/*do {
		yaml_parser_scan(&parser, &token);
		switch(token.type) {
			/* Stream start/end */
			/*case YAML_STREAM_START_TOKEN: puts("STREAM START: LOADING FROM CONFIG..."); break;
			case YAML_STREAM_END_TOKEN:   puts("STREAM END");   break;
			/* Token types (read before actual token) */
			/*case YAML_KEY_TOKEN:   token_id += 1; printf("(Key token)   id:%d ", token_id); break;
			case YAML_VALUE_TOKEN: printf("(Value token) id:%d ", token_id); break;
			/* Block delimeters */
			/*case YAML_BLOCK_SEQUENCE_START_TOKEN: puts("<b>Start Block (Sequence)</b>"); break;
			case YAML_BLOCK_ENTRY_TOKEN:          puts("<b>Start Block (Entry)</b>");    break;
			case YAML_BLOCK_END_TOKEN:            puts("<b>End block</b>");              break;
			/* Data */
			/*case YAML_BLOCK_MAPPING_START_TOKEN:  puts("[Block mapping]");            break;
			case YAML_SCALAR_TOKEN:  printf("scalar %s \n", token.data.scalar.value); 
				switch(token_id) {
					case STOPPING_DISTANCE: thresholds.stopping_distance = atoi(token.data.scalar.value); break;
					case THRESHOLD1_LOW: thresholds.threshold1_low = atoi(token.data.scalar.value); break;
					case THRESHOLD1_HIGH: thresholds.threshold1_high = atoi(token.data.scalar.value); break;
					case THRESHOLD2_LOW: thresholds.threshold2_low = atoi(token.data.scalar.value); break;
					case THRESHOLD2_HIGH: thresholds.threshold2_high = atoi(token.data.scalar.value); break;
					case TEST1: thresholds.test1 = atoi(token.data.scalar.value); break;
					case TEST2: thresholds.test2 = atoi(token.data.scalar.value); break;
					case TEST3: thresholds.test3 = atoi(token.data.scalar.value); break;
					case TEST4: thresholds.test4 = atoi(token.data.scalar.value); break;
					default: printf("token_id error! %d\n", token_id); break;
				}
			break;
			/* Others */
			/*default:
				printf("Got token of type %d\n", token.type);
		}
		if(token.type != YAML_STREAM_END_TOKEN)
			yaml_token_delete(&token);
		} while(token.type != YAML_STREAM_END_TOKEN);
		yaml_token_delete(&token);
	/* END new code */

	/* Cleanup */
	/*yaml_parser_delete(&parser);
	/*fclose(fh);

	printf("threshold stuct values: %d %d %d %d %d %d %d %d %d\n", thresholds.stopping_distance, thresholds.threshold1_low, thresholds.threshold1_high, thresholds.threshold2_low, thresholds.threshold2_high, thresholds.test1, thresholds.test2, thresholds.test3, thresholds.test4);
	*/

	Thresholds thresholds;
	char filename[] = "config.csv";
	FILE *config_file = fopen(filename, "r");

	if ( config_file == NULL ) { /* error opening file */
		printf("Cannot open file: %s\n", filename);
		return 0;
	}
	else {
		char line [128]; /* or other suitable maximum line size */
		while (fgets ( line, sizeof line, config_file ) != NULL) { /* read a line */
			fputs (line, stdout); /* write the line */

			char *token = strtok(line, ",");
			
			char *type = token;
			int i = 1;

			printf("Type: %s \n", type);
			token = strtok(NULL, ",");
			
			while( token != NULL ) {
				char *curr_tok = token;
				printf("> %s \n", curr_tok);
				printf("STRING %s %f\n", curr_tok, atof(curr_tok));
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

	printf("threshold stuct values: %d %d %d %d %d\n", 
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
