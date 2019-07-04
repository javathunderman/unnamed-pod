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
#include "FPGA/fpga_cache.h"

#define TEST "Brake_Actuation" //Name of the test, must be under 50 characters
#define DT 100          //Timing interval for logging in millis
#define LEN 5           //Length of time to log in seconds.




char *greeting =     "########################################\n"
                     "###              UMDLOOP             ###\n"
                     "###       BRAKE ACTUATION TEST       ###\n"
                     "###              7/4/2019            ###\n"
                     "########################################\n"
                     "#    Press 'q'    #      Press 'b'     #\n"
                     "#                 #      to toggle     #\n"
                     "#     to quit     #   state of brakes  #\n"
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
    struct timeval start, cur;
    float time = 0;
    gettimeofday(&start, NULL);
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
                write_set_brakes(fpga, !(fpga->current_brake_state));
            }
        }
        
        // Update FPGA cache to fetch new values
        refresh_cache(fpga);
        //Measure values and log
        gettimeofday(&cur, NULL);
        time = cur.tv_sec - start.tv_sec;
        time += (0.000001f * (cur.tv_usec - start.tv_usec));
        fprintf(file, "%f, %f\n", time, 0.0);
        usleep(1000*DT);
        printf("Time: %f\n", time);
    }
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


