/*
 ============================================================================
 Name        : main.c
 Author      : Mark Thiergartner
 Version     : 0.1
 Description : Template file for bootstrapping tests.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include "FPGA/NiFpga.h" //Replace with header from cache-gen if using it

#define TEST "Template" //Name of the test, must be under 50 characters
#define DT 100			//Timing interval for logging in millis
#define LEN 10			//Length of time to log in seconds.


/*
 * Automatically increments test number to avoid overwriting files.
 */
int test_num(const char* test_name){
	char fname[80];
	int num = -1;

	if(strlen(test_name) > 50){
		puts("Input test name is too long");
		exit(EXIT_FAILURE);
	}

	sprintf(fname, "test_%s_%d", test_name, ++num);
	while(access(fname, F_OK) != -1);

	return num;
}

/*
 * Basic file writing on intervals. Due to function calls taking time, the timings
 * are not exac
 */
void test(FILE * const file){
	struct timeval start, cur;
	float time = 0;
	gettimeofday(&start, NULL);

	//Perform your test and log it to the CSV.
	while(time < LEN){
		//Measure values and log
		gettimeofday(&cur, NULL);
		time = (cur.tv_usec - start.tv_usec)/1000000.0f;
		fprintf(file, "%f, %f\n", time, 0.0);
		usleep(1000*DT);

	}

}
int main(void) {
	char fname[80];
	puts("Test Initialization..."); /* prints !!!Hello World!!! */
	sprintf(fname, "test_%s_%d.csv", TEST, test_num(TEST));
	FILE *file = fopen(fname, "w");

	if(!file){
		puts("Unable to create log file");
		exit(EXIT_FAILURE);
	}

	test(file);
	fclose(file);

	return EXIT_SUCCESS;
}


