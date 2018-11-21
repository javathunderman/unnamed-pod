#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h> 
/*#include "./sensors/sensors.h"
#include "./states/states.h"*/

int testfun(int i) {
	printf("Printing integer: %d\n", i);
	return 0;
}

void *threadfun(void * i) {
	int *ii = (int *)i;
	printf("Printing integer: %d\n", *ii);
	return NULL;
}

int main() {
    void * (*fp_arr[6][6]) (void *);
	void (*testfun_ptr)(int) = &testfun;
	void * (*threadfun_ptr)(void *) = &threadfun;

	pthread_t thread_id;
	int *param = (int *)malloc(2*sizeof(int));

    fp_arr[1][1] = &threadfun;

	param[0] = 100;
	param[1] = 200;
    pthread_create(&thread_id, NULL, fp_arr[1][1], param); 
    pthread_join(thread_id, NULL); 
    free(param);

	return 0;
}