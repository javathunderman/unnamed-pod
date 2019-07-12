#ifndef __FPGA_CACHE__
#define __FPGA_CACHE__
#include "NiFpga_main.h"
#include "NiFpga.h"

typedef int32_t fxp32_16;
typedef struct {
	NiFpga_Bool FIFO_timeout_analog;
	NiFpga_Bool FIFO_timeout_laser;
	NiFpga_Bool FIFO_timeout_retro;
	NiFpga_Bool HVR_1_state;
	NiFpga_Bool HVR_2_state;
	NiFpga_Bool HVR_3_state;
	NiFpga_Bool HVR_4_state;
	NiFpga_Bool avb_shutoff_p1_state;
	NiFpga_Bool avb_shutoff_p2_state;
	NiFpga_Bool avb_shutoff_r_state;
	NiFpga_Bool brake_state;
	NiFpga_Bool drain_valve_state;
	NiFpga_Bool iso_led_1_state;
	NiFpga_Bool iso_led_2_state;
	uint8_t light_BL_count;
	uint8_t light_BR_count;
	uint8_t light_FL_count;
	uint8_t light_L_count;
	uint8_t light_R_count;
	uint16_t count_laser_l;
	uint16_t count_laser_r;
	uint16_t count_light_bl;
	uint16_t count_light_br;
	uint16_t count_light_fl;
	uint16_t count_light_fr;
	fxp32_16 P_hp1;
	fxp32_16 P_hp2;
	fxp32_16 P_lp1;
	fxp32_16 P_lp2;
	fxp32_16 T_cRIO;
	fxp32_16 T_extra1;
	fxp32_16 T_extra2;
	fxp32_16 T_p1;
	fxp32_16 T_p2;
	fxp32_16 T_piston0;
	fxp32_16 T_piston1;
	fxp32_16 T_piston2;
	fxp32_16 T_piston3;
	fxp32_16 T_piston4;
	fxp32_16 T_piston5;
	fxp32_16 T_piston6;
	fxp32_16 T_piston7;
	fxp32_16 T_pneum;
	fxp32_16 T_pod;
	fxp32_16 T_r;
	fxp32_16 current_p1;
	fxp32_16 current_p2;
	fxp32_16 current_r;
	fxp32_16 tape_velocity;
	fxp32_16 voltage_p1;
	fxp32_16 voltage_p2;
	fxp32_16 voltage_r;
	uint64_t fault_long_0;
	uint64_t fault_long_1;
	uint64_t fault_long_2;
	uint64_t fault_long_3;
} Cache;

typedef struct {
	NiFpga_Status status;
	const char *bit_path;
	const char *signature;
	const char *resource;
	NiFpga_Session session;
	Cache cache;
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

NiFpga_Status write_actuate_brakes(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_actuate_drain(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_avb_shutoff_prim_1(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_avb_shutoff_prim_2(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_avb_shutoff_res(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_1(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_2(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_3(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_4(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_iso_led_1(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_iso_led_2(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_prim_bat_1(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_prim_bat_2(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_prim_bat_3(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_thresh_latch_new(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_thresh_reset(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_thresh_read_index(Fpga *fpga, uint8_t v);

NiFpga_Status write_thresh_reset_index(Fpga *fpga, uint8_t v);

NiFpga_Status write_thresh_write_index(Fpga *fpga, uint8_t v);

NiFpga_Status write_thresh_f_ratio(Fpga *fpga, uint32_t v);

NiFpga_Status write_thresh_persistence(Fpga *fpga, uint32_t v);

#endif
