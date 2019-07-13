#ifndef __FPGA_CACHE__
#define __FPGA_CACHE__
#include "NiFpga_main.h"
#include "NiFpga.h"

typedef struct {
	NiFpga_Bool FIFO_timeout;
	NiFpga_Bool TO_daq_av_fuses;
	NiFpga_Bool TO_daq_pressure;
	NiFpga_Bool TO_daq_vol_cur;
	NiFpga_Bool TO_dat_pressure;
	NiFpga_Bool TO_dat_vol_cur;
	NiFpga_Bool brake_state;
	NiFpga_Bool drain_valve_state;
	NiFpga_Bool fuse_av_1;
	NiFpga_Bool fuse_av_2;
	uint16_t count_laser_l;
	uint16_t count_laser_r;
	uint16_t count_light_bl;
	uint16_t count_light_br;
	uint16_t count_light_fl;
	uint16_t count_light_fr;
	int32_t I_av_pb_1;
	int32_t I_av_pb_2;
	int32_t I_av_rb;
	int32_t V_av_pb_1;
	int32_t V_av_pb_2;
	int32_t V_av_rb;
	uint64_t fault_long_0;
	uint64_t fault_long_1;
	uint64_t fault_long_2;
	uint64_t fault_long_3;
	uint8_t thresh_index;
	int32_t thresh_minimum;
	int32_t thresh_maximum;
	uint32_t thresh_persistence;
	uint32_t thresh_ratio;
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

NiFpga_Status write_brakes(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_drain_valve(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_prim_bat_1(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_prim_bat_2(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_prim_bat_3(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_thresh_latch_new(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_thresh_reset(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_thresh_minimum(Fpga *fpga, int32_t minimum);

NiFpga_Status write_thresh_maximum(Fpga *fpga, int32_t maximum);

NiFpga_Status write_thresh_read_index(Fpga *fpga, uint8_t v);

NiFpga_Status write_thresh_reset_index(Fpga *fpga, uint8_t v);

NiFpga_Status write_thresh_write_index(Fpga *fpga, uint8_t v);

NiFpga_Status write_thresh_ratio(Fpga *fpga, uint32_t v);

NiFpga_Status write_thresh_persistence(Fpga *fpga, uint32_t v);

#endif
