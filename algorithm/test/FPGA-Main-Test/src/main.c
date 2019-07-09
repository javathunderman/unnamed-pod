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
#include <poll.h>
#include "FPGA/fpga_cache.h"


#define TEST "Brake_Actuation" //Name of the test, must be under 50 characters
#define DT 100          //Timing interval for logging in millis
#define LEN 5           //Length of time to log in seconds.
#define NOT(x) x==NiFpga_False ? NiFpga_True : NiFpga_False
#define booltos(x) x==NiFpga_False ? "False" : "True"

float fxptof(int32_t fxp);



char *greeting =     "########################################\n"
                     "###              UMDLOOP             ###\n"
                     "###           FPGA MAIN TEST         ###\n"
                     "########################################\n"
                     "#    Press 'd'    #      Press 'b'     #\n"
                     "#    to toggle    #      to toggle     #\n"
                     "# state of drain  #   state of brakes  #\n"
                     "########################################\n"
					 "# Press 'q' to quit and stop execution #\n"
					 "########################################\n";


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
void test(FILE * const file, Fpga * fpga){
	run_fpga(fpga, 0);
	refresh_cache(fpga);

	struct timeval start, cur;
	float time = 0;
	gettimeofday(&start, NULL);

    char c;
    struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };

    printf("%s", greeting);
    fprintf(file, "Time, Brake State, Drain State, I_1, I_2, FUSE_1, FUSE_2");
    //Perform your test and log it to the CSV.
    while(1){
    	refresh_cache(fpga);
        if (poll(&mypoll, 1, 100)) {
            scanf("%c", &c);
            if (c == 'q') {
                printf("EXITING\n");
                break;
            } else if (c == 'b') {
                printf("TOGGLING BRAKES\n");

                write_brakes(fpga, NOT(fpga->cache.brake_state));
            } else if (c == 'd') {
            	printf("TOGGLING DRAIN VALVE\n");
            	write_drain_valve(fpga, NOT(fpga->cache.drain_valve_state));
            }
        }
        // Get timing for data logging
        gettimeofday(&cur, NULL);
		time = cur.tv_sec - start.tv_sec;
		time += (0.000001f * (cur.tv_usec - start.tv_usec));

        // Update FPGA cache to fetch new values

        fprintf(file, "%f, %s, %s, %f, %f, %f, %f\n", time,
        		booltos(fpga->cache.brake_state), booltos(fpga->cache.drain_valve_state),
        		fxptof(fpga->cache.I_av_pb_1), fxptof(fpga->cache.I_av_pb_2),
        		booltos(fpga->cache.fuse_av_1), booltos(fpga->cache.fuse_av_2));

    }
}
float fxptof(int32_t fxp) {
	return fxp / 65536.0f;
}
int main(void) {
    uint32_t default_attr = 0;
    char fname[128];
    puts("Test Initialization...");
    sprintf(fname, "test_%s_%d.csv", TEST, test_num(TEST));
    printf("Output File: %s\n", fname);
    FILE *file = fopen(fname, "w");

    if(!file){
        puts("Unable to create log file");
        exit(EXIT_FAILURE);
    }

    Fpga fpga_dat;
    Fpga * fpga = &fpga_dat;
    default_fpga(fpga);
    init_fpga(fpga, 0);

    test(file, fpga);
    fclose(file);
    write_stop(fpga, 1);
    fpclose(fpga, default_attr);
    fpfinalize(fpga);
    puts("Test Complete!");
    return EXIT_SUCCESS;
}


