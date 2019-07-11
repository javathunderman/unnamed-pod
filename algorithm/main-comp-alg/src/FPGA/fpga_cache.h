#ifndef __FPGA_CACHE__
#define __FPGA_CACHE__
#include "NiFpga_main.h"
#include "NiFpga.h"

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
	int32_t fxp_P_hp1;
	int32_t fxp_P_hp2;
	int32_t fxp_P_lp1;
	int32_t fxp_P_lp2;
	int32_t fxp_T_cRIO;
	int32_t fxp_T_extra1;
	int32_t fxp_T_extra2;
	int32_t fxp_T_p1;
	int32_t fxp_T_p2;
	int32_t fxp_T_piston0;
	int32_t fxp_T_piston1;
	int32_t fxp_T_piston2;
	int32_t fxp_T_piston3;
	int32_t fxp_T_piston4;
	int32_t fxp_T_piston5;
	int32_t fxp_T_piston6;
	int32_t fxp_T_piston7;
	int32_t fxp_T_pneum;
	int32_t fxp_T_pod;
	int32_t fxp_T_r;
	int32_t fxp_current_p1;
	int32_t fxp_current_p2;
	int32_t fxp_current_r;
	int32_t fxp_tape_velocity;
	int32_t fxp_voltage_p1;
	int32_t fxp_voltage_p2;
	int32_t fxp_voltage_r;
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


void default_fpga(Fpga *fpga);

NiFpga_Status init_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status run_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status refresh_cache(Fpga *Fpga);

NiFpga_Status fpclose(Fpga *fpga, uint32_t attr);

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
