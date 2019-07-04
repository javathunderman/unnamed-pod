#ifndef __FPGA_CACHE__
#define __FPGA_CACHE__
#include "NiFpga_test_brake_actuation.h"
#include "NiFpga.h"

typedef struct {
	NiFpga_Bool current_brake_state;
	NiFpga_Bool current_drain_valve_state;
	int32_t fxp_pressure_14;
	int32_t fxp_pressure_15;
	int32_t fxp_pressure_16;
	int32_t fxp_pressure_17;
	int32_t fxp_pressure_18;
	int32_t fxp_pressure_19;
	int32_t fxp_pressure_20;
	int32_t fxp_pressure_21;
	int32_t fxp_pressure_22;
} Cache;

typedef struct {
	NiFpga_Status status;
	char *bit_path;
	char *signature;
	char *resource;
	NiFpga_Session session;
	Cache cache;
} Fpga;


void default_fpga(Fpga *fpga);

NiFpga_Status init_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status run_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status refresh_cache(Fpga *Fpga);

NiFpga_Status fpclose(Fpga *fpga, uint32_t attr);

NiFpga_Status fpfinalize(Fpga *fpga);

NiFpga_Status write_set_brakes(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_set_drain_valve(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v);

#endif
