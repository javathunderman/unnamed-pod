#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "./sensors/sensors.h"
#include "./states/states.h"


#define MAX_SOMETHING_GOES_HERE 10
//typedef enum {STANDBY_SID = 0, INITIALIZE_SID = 1, SERVICE_SID = 2, ACCELERATE_SID = 3, NORMBRAKE_SID = 4, ESTOP_SID = 5} State; 
//typedef enum {SUCCESS = 0, REPEAT = 1, ERROR = 4, ESTOP = 5} State_Status; 

int active = 1;

int standby_state();
int initialize_state();
int service_state();
int accelerate_state();
int normbrake_state();
int estop_state();

int main() {
	int sid_arr[NUM_STATES][NUM_CODES];
	int (*fp_arr[NUM_STATES]) (void);

	//1D array of Function Pointers to state functions
	fp_arr[STANDBY_SID] = &standby_state;
	fp_arr[INITIALIZE_SID] = &initialize_state;
	fp_arr[SERVICE_SID] = &service_state;
	fp_arr[ACCELERATE_SID] = &accelerate_state;
	fp_arr[NORMBRAKE_SID] = &normbrake_state;
	fp_arr[ESTOP_SID] = &estop_state;

	//2D Logic state array settings
	sid_arr[INITIALIZE_SID][SUCCESS] = ACCELERATE_SID;
	sid_arr[INITIALIZE_SID][ERROR] = STANDBY_SID;
	sid_arr[ACCELERATE_SID][REPEAT] = ACCELERATE_SID;
	sid_arr[ACCELERATE_SID][SUCCESS] = NORMBRAKE_SID;
	sid_arr[ACCELERATE_SID][ERROR] = ESTOP_SID;
	sid_arr[NORMBRAKE_SID][SUCCESS] = STANDBY_SID;
	sid_arr[NORMBRAKE_SID][ERROR] = ESTOP_SID;
	sid_arr[ESTOP_SID][SUCCESS] = STANDBY_SID;
	sid_arr[STANDBY_SID][REPEAT] = STANDBY_SID;
	sid_arr[STANDBY_SID][SUCCESS] = INITIALIZE_SID;
	
	//Initial values for state flow
	int last_state = INITIALIZE_SID;
	int return_code = initialize_state();

	//main state loop
	while (active) {
		int last_state = sid_arr[last_state][return_code];
		return_code = (*fp_arr[last_state])();
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
