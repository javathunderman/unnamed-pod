#ifndef __FPGA_CACHE__
#define __FPGA_CACHE__
#include "NiFpga_main.h"
#include "atomics.h"


#define fpgaRunAndUpdateIf(fpga, call, description) \
if(NiFpga_IsError(fpga->status)) {\
    printf("Attempting to perform action: '%s' while FPGA is in error state: %d. Trying anyway.\n",                #call, fpga->status);\
                }\
NiFpga_IfIsNotError(fpga->status, call);\
if(NiFpga_IsError(fpga->status)) {\
    printf("Failed to perform action: '%s' due to FPGA in error state: %d.\n",\
                #call, fpga->status);}

typedef int32_t fxp32_16;
typedef int64_t fxp64_32;
typedef struct {
	NiFpga_Bool HVR_1_state;
	NiFpga_Bool HVR_2_state;
	NiFpga_Bool HVR_3_state;
	NiFpga_Bool HVR_4_state;
	NiFpga_Bool avb_shutoff_p1_state;
	NiFpga_Bool avb_shutoff_p2_state;
	NiFpga_Bool avb_shutoff_r_state;
	NiFpga_Bool brake_state;
	NiFpga_Bool drain_valve_state;
	NiFpga_Bool enable_checks_state;
	NiFpga_Bool frg_run_state;
	NiFpga_Bool fuse_avb_p1;
	NiFpga_Bool fuse_avb_p2;
	NiFpga_Bool iso_led_1_state;
	NiFpga_Bool iso_led_2_state;
	uint8_t cur_thresh_index;
	uint8_t light_BL_count;
	uint8_t light_BR_count;
	uint8_t light_L_count;
	uint8_t light_R_count;
	uint8_t light_count;
	uint8_t light_sensor_status;
	int16_t T_cRIO;
	fxp32_16 P_hp1;
	fxp32_16 P_hp2;
	fxp32_16 P_lp1;
	fxp32_16 P_lp2;
	fxp32_16 T_avb_p1;
	fxp32_16 T_avb_p2;
	fxp32_16 T_avb_r;
	fxp32_16 T_extra1;
	fxp32_16 T_extra2;
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
	fxp32_16 brake_distance;
	fxp32_16 cur_thresh_max;
	fxp32_16 cur_thresh_min;
	fxp32_16 current_p1;
	fxp32_16 current_p2;
	fxp32_16 current_r;
	fxp32_16 fusion_distance;
	fxp32_16 imu_velocity;
	fxp32_16 mc_distance;
	fxp32_16 tape_velocity;
	fxp32_16 voltage_p1;
	fxp32_16 voltage_p2;
	fxp32_16 voltage_r;
	int32_t tape_distance;
	uint32_t cur_thresh_persistence;
	uint32_t cur_thresh_ratio;
	fxp64_32 imu_distance;
	uint64_t fault_long_2;
	uint64_t fault_long_3;
	uint64_t hard_fault;
	uint64_t soft_fault;
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

fxp64_32 ftofxpe(float d);

fxp64_32 dtofxpe(double d);

float fxpetof(fxp64_32 fxpe);

double fxpetod(fxp64_32 fxpe);

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

NiFpga_Status write_enable_checks(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_frg_run(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_1(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_2(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_3(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_hvr_4(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_iso_led_1(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_iso_led_2(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_reset_tape_count(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_reset_tape_status(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_thresh_latch_new(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_thresh_reset(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_thresh_read_index(Fpga *fpga, uint8_t v);

NiFpga_Status write_thresh_reset_index(Fpga *fpga, uint8_t v);

NiFpga_Status write_thresh_write_index(Fpga *fpga, uint8_t v);

NiFpga_Status write_imu_acc(Fpga *fpga, fxp32_16 v);

NiFpga_Status write_mc_velocity(Fpga *fpga, fxp32_16 v);

NiFpga_Status write_thresh_new_max(Fpga *fpga, fxp32_16 v);

NiFpga_Status write_thresh_new_min(Fpga *fpga, fxp32_16 v);

NiFpga_Status write_thresh_f_ratio(Fpga *fpga, uint32_t v);

NiFpga_Status write_thresh_persistence(Fpga *fpga, uint32_t v);

NiFpga_Status write_imu_timestamp(Fpga *fpga, fxp64_32 v);

#endif
