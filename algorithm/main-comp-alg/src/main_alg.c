#include <stdio.h>
#include "./sensors/sensors.h"
#include "./states/states.h"

int testfun(int i) {
	printf("Printing integer: %d\n", i);
}

int main() {
    int (*fp_arr[6][6]) (int x);
	//void (*fun_ptr)(int) = &testfun;

    fp_arr[1][1] = &testfun;
	fp_arr[1][2] = &estoptestfun;
    
	(*fp_arr[1][1])(10);
	(*fp_arr[1][2])(5);

	return 0;
}