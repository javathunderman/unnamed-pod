#ifndef __FPGA_CACHE__
#define __FPGA_CACHE__
#include "NiFpga_imu_test.h"
#include "atomics.h"


#define fpgaRunAndUpdateIf(fpga, call, description) \
if(NiFpga_IsError(fpga->status)) {\
    printf("Attempting to perform action: '%s' while FPGA is in error state: %d. Trying anyway.\n",                #call, fpga->status);\
                }\
NiFpga_ifIsNotError(fpga->status, call);\
if(NiFpga_IsError(fpga->status)) {\
    printf("Failed to perform action: '%s' due to FPGA in error state: %d.\n",\
                #call, fpga->status);\
}

typedef int32_t fxp32_16;
typedef struct {
	int32_t velocity;
	int64_t distance;
} FpgaCache;

typedef struct {
	NiFpga_Status status;
	const char *bit_path;
	const char *signature;
	const char *resource;
	NiFpga_Session session;
	FpgaCache cache;
} Fpga;


/* fxp conversion utilities */
fxp32_16 ftofxp(float d);

fxp32_16 dtofxp(double d);

float fxptof(fxp32_16 fxp);

double fxptod(fxp32_16 fxp);

void default_fpga(Fpga *fpga);

/* FPGA session and library managerment */
/*
 * Loads the NiFpga library and establishes a connection to the FPGA, 0 for default arg.
 */
NiFpga_Status init_fpga(Fpga *fpga, uint32_t attr);

/*
 * Deploys the bitfile to the FPGA and begins execution.
 */
NiFpga_Status run_fpga(Fpga *fpga, uint32_t attr);

/*
 * Fetches new values for all FPGA cache methods.
 */
NiFpga_Status refresh_cache(Fpga *Fpga);

/*
 * Closes the connection to the FPGA. Set the stop bool to true before calling.
 */
NiFpga_Status fpclose(Fpga *fpga, uint32_t attr);

/*
 * Closes the NiFpga library
 */
NiFpga_Status fpfinalize(Fpga *fpga);

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_imu_acc(Fpga *fpga, int32_t v);

NiFpga_Status write_timestamp(Fpga *fpga, int64_t v);

#endif
