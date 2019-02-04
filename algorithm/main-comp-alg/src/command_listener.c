#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>

//typedef enum {STANDBY_SID = 0, INITIALIZE_SID = 1, SERVICE_SID = 2, ACCELERATE_SID = 3, NORMBRAKE_SID = 4, ESTOP_SID = 5} State; 
//typedef enum {SUCCESS = 0, REPEAT = 1, ERROR = 4, ESTOP = 5} State_Status; 
typedef enum {STOPPING_DISTANCE, THRESHOLD1_LOW, THRESHOLD1_HIGH, THRESHOLD2_LOW, THRESHOLD2_HIGH, TEST1, TEST2, TEST3, TEST4} Config;

int listen() {
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// COMMAND LISTENING LOOP                                                                       //
	//////////////////////////////////////////////////////////////////////////////////////////////////
	
	/*while (true) {
		printf("Listening for command...\n");

		int     result;
		char    ch='A';

		while (1) {
			result = write (fd[1], &ch,1);
			if (result != 1){
				perror ("write");
				exit (2);
			}

			printf ("Writer: %c\n", ch);
			if(ch == 'Z')
				ch = 'A'-1;

			ch++;
		}
	}*/


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
