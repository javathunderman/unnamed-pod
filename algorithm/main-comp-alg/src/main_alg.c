s#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 
/*#include "./sensors/sensors.h"
#include "./states/states.h"*/

#define NUM_THREADS 4

int testfun(int i) {
	printf("Printing integer: %d\n", i);
	return 0;
}

void *threadfun(void * i) {
	int *ii = (int *)i;
	printf("Printing integer from thread: %d\n", *ii);
	return NULL;
}

int main() {
	void * (*fp_arr[6][6]) (void *);
	void (*testfun_ptr)(int) = &testfun;
	void * (*threadfun_ptr)(void *) = &threadfun;

	/* thread_ids[0] = States
	 * thread_ids[1] = FPGA read
	 * thread_ids[2] = Telem send
	 * thread_ids[3] = Read commands
	 */
	pthread_t thread_id;
	pthread_t thread_ids[NUM_THREADS];
	//int *param = (int *)malloc(2*sizeof(int));
	int *params[NUM_THREADS];

	int i;
	for (i = 0; i < NUM_THREADS; i++) {
		params[i] = (int *)malloc(2*sizeof(int));
	}
	
	fp_arr[1][1] = &threadfun;

	//param[0] = 100;
	//param[1] = 200;

	for (i = 0; i < NUM_THREADS; i++) {
		pthread_create(&thread_ids[i], NULL, fp_arr[1][1], params[i]); 
	}

	//pthread_create(&thread_id, NULL, fp_arr[1][1], param); 

	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(thread_ids[i], NULL); 
	}

	pthread_join(thread_id, NULL); 
	free(param);

	return 0;
}