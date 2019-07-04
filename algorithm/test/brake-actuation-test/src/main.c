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

float fxptof(int32_t fxp);



char *greeting =     "########################################\n"
                     "###              UMDLOOP             ###\n"
                     "###       BRAKE ACTUATION TEST       ###\n"
                     "###              7/4/2019            ###\n"
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
	refresh_cache(fpga);
    float time = 0;
    char c;
    struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };

    printf("%s", greeting);

    //Perform your test and log it to the CSV.
    while(1){
        if (poll(&mypoll, 1, 100)) {
            scanf("%c", &c);
            if (c == 'q') {
                printf("EXITING"); 
                break;
            } else if (c == 'b') {
                printf("TOGGLING BRAKES\n");
                write_set_brakes(fpga, !(fpga->cache.current_brake_state));
            } else if (c == 'd') {
            	printf("TOGGLING DRAIN VALVE\n");
            	write_set_drain_valve(fpga, !(fpga->cache.current_drain_valve_state));
            }
        }
        
        // Update FPGA cache to fetch new values

        fprintf(file, "%f, %f, %f, %f, %f\n", time,
        		fxptof(fpga->cache.fxp_pressure_14), fxptof(fpga->cache.fxp_pressure_15),
        		fxptof(fpga->cache.fxp_pressure_16), fxptof(fpga->cache.fxp_pressure_17));
        refresh_cache(fpga);
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
    init_fpga(fpga, 0);

    test(file, fpga);
    fclose(file);
    fpclose(fpga, default_attr);
    fpfinalize(fpga);
    puts("Test Complete!");
    return EXIT_SUCCESS;
}


