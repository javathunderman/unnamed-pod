#ifndef __FPGA_CACHE__
#define __FPGA_CACHE__
#include "NiFpga_brake_test.h"

#define STORE(var, val) (__atomic_store_n(&(var), (val), __ATOMIC_RELAXED))
#define LOAD(var) (__atomic_load_n(&(var), __ATOMIC_RELAXED))

#define SEQ_STORE(var, val) (__atomic_store_n(&(var), (val), __ATOMIC_SEQ_CST))
#define SEQ_LOAD(var) (__atomic_load_n(&(var), __ATOMIC_SEQ_CST))


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
	NiFpga_Bool FIFO_timeout;
	NiFpga_Bool brake_state;
	NiFpga_Bool drain_valve_state;
	fxp32_16 P_hp1;
	fxp32_16 P_hp2;
	fxp32_16 P_lp1;
	fxp32_16 P_lp2;
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

NiFpga_Status write_brake_1(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_brake_2(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_drain(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v);

#endif
