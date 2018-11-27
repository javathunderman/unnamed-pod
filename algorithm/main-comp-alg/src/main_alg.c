#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "./sensors/sensors.h"
#include "./states/states.h"

#define NUM_STATES 6

int active = 0;
int last_state = 0;

int testaccel_counter = 0;

int main() {
	int (*fp_arr[NUM_STATES][6]) (void);
	fp_arr[INITIALIZE_SID][SUCCESS] = &accelerate_state;
	fp_arr[ACCELERATE_SID][CONTINUE] = &accelerate_state;
	fp_arr[ACCELERATE_SID][SUCCESS] = &estop_state;
	
	int status = initialize_state();

	while (active) {
		status = (*fp_arr[last_state][status])();
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