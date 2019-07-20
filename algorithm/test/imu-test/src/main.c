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
#include "FPGA/fpga_cache.h" //Replace with header from cache-gen if using it
#include "FPGA/imu.h"

#define TEST "IMU-Test" //Name of the test, must be under 50 characters
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

	sprintf(fname, "test_%s_%d.csv", test_name, ++num);
	while(access(fname, F_OK) != -1){
		sprintf(fname, "test_%s_%d.csv", test_name, ++num);
	}

	return num;
}

/*
 * Basic file writing on intervals. Due to function calls taking time, the timings
 * are not exac
 */
void test(FILE * const file, Fpga *fpga){
	struct timeval start, cur;
	float time = 0;
	gettimeofday(&start, NULL);

	//Perform your test and log it to the CSV.
	fprintf(file, "Time, a_x, a_y, a_z, v, d, p, status\n");
	while(time < LEN){
		refresh_cache(fpga);
		//Measure values and log

		gettimeofday(&cur, NULL);
		time = cur.tv_sec - start.tv_sec;
		time += (0.000001f * (cur.tv_usec - start.tv_usec));

		fprintf(file, "%f, %f, %f, %f, %f, %d,\n",
				time, fxptod(fpga->imu_dat.x_accel),
				fxptod(fpga->imu_dat.y_accel), fxptod(fpga->imu_dat.z_accel),
				fxptod(fpga->imu_dat.pressure), fpga->status);
		printf("%f, %f, %f, %f, %f, %d,\n",
				time, fxptod(fpga->imu_dat.x_accel),
				fxptod(fpga->imu_dat.y_accel), fxptod(fpga->imu_dat.z_accel),
				fxptod(fpga->imu_dat.pressure), fpga->status);
		usleep(1000*DT);

	}

}
int main(void) {
	Fpga fpga_dat;
	Fpga *fpga = &fpga_dat;
	default_fpga(fpga);

	init_fpga(fpga, 0);
	run_fpga(fpga, 0);

	char fname[128];
	puts("Test Initialization..."); /* prints !!!Hello World!!! */
	sprintf(fname, "test_%s_%d.csv", TEST, test_num(TEST));
	printf("Output File: %s\n", fname);
	FILE *file = fopen(fname, "w");


	if(!file){
		puts("Unable to create log file");
		exit(EXIT_FAILURE);
	}

	test(file, fpga);
	fclose(file);
	fpclose(fpga, 0);
	fpfinalize(fpga);
	puts("Test Complete!");
	return EXIT_SUCCESS;
}


