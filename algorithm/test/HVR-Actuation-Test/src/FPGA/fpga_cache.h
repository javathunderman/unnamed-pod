#ifndef __FPGA_CACHE__
#define __FPGA_CACHE__
#include "NiFpga_test_hvr.h"
#include "NiFpga.h"

typedef struct {
	NiFpga_Bool HVR_1;
	NiFpga_Bool HVR_2;
	NiFpga_Bool HVR_3;
	NiFpga_Bool HVR_4;
} Cache;

typedef struct {
	NiFpga_Status status;
	const char *bit_path;
	const char *signature;
	const char *resource;
	NiFpga_Session session;
	Cache cache;
} Fpga;


void default_fpga(Fpga *fpga);

NiFpga_Status init_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status run_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status refresh_cache(Fpga *Fpga);

NiFpga_Status fpclose(Fpga *fpga, uint32_t attr);

NiFpga_Status fpfinalize(Fpga *fpga);

NiFpga_Status write_hvr_1(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_2(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_3(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_4(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v);

#endif
