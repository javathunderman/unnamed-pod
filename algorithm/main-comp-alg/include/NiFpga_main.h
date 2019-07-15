/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_main_h__
#define __NiFpga_main_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_main_Bitfile;
 */
#define NiFpga_main_Bitfile "NiFpga_main.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_main_Signature = "3FA2AEAAEA0578CC75500438EE87CA57";

typedef enum
{
   NiFpga_main_IndicatorBool_HVR_1_state = 0x18066,
   NiFpga_main_IndicatorBool_HVR_2_state = 0x1806A,
   NiFpga_main_IndicatorBool_HVR_3_state = 0x1806E,
   NiFpga_main_IndicatorBool_HVR_4_state = 0x18072,
   NiFpga_main_IndicatorBool_avb_shutoff_p1_state = 0x1807E,
   NiFpga_main_IndicatorBool_avb_shutoff_p2_state = 0x18082,
   NiFpga_main_IndicatorBool_avb_shutoff_r_state = 0x18086,
   NiFpga_main_IndicatorBool_brake_state = 0x1805E,
   NiFpga_main_IndicatorBool_drain_valve_state = 0x18062,
   NiFpga_main_IndicatorBool_enable_checks_state = 0x18126,
   NiFpga_main_IndicatorBool_frg_run_state = 0x18162,
   NiFpga_main_IndicatorBool_fuse_avb_p1 = 0x18166,
   NiFpga_main_IndicatorBool_fuse_avb_p2 = 0x1816A,
   NiFpga_main_IndicatorBool_iso_led_1_state = 0x18076,
   NiFpga_main_IndicatorBool_iso_led_2_state = 0x1807A,
} NiFpga_main_IndicatorBool;

typedef enum
{
   NiFpga_main_IndicatorU8_cur_thresh_index = 0x1815A,
   NiFpga_main_IndicatorU8_light_BL_count = 0x180B2,
   NiFpga_main_IndicatorU8_light_BR_count = 0x180B6,
   NiFpga_main_IndicatorU8_light_FL_count = 0x180AE,
   NiFpga_main_IndicatorU8_light_L_count = 0x180BA,
   NiFpga_main_IndicatorU8_light_R_count = 0x180BE,
   NiFpga_main_IndicatorU8_light_sensor_status = 0x1812A,
} NiFpga_main_IndicatorU8;

typedef enum
{
   NiFpga_main_IndicatorI32_fxp_P_hp1 = 0x180E4,
   NiFpga_main_IndicatorI32_fxp_P_hp2 = 0x180E8,
   NiFpga_main_IndicatorI32_fxp_P_lp1 = 0x180EC,
   NiFpga_main_IndicatorI32_fxp_P_lp2 = 0x180F0,
   NiFpga_main_IndicatorI32_fxp_T_avb_p1 = 0x180C4,
   NiFpga_main_IndicatorI32_fxp_T_avb_p2 = 0x180C8,
   NiFpga_main_IndicatorI32_fxp_T_avb_r = 0x180CC,
   NiFpga_main_IndicatorI32_fxp_T_cRIO = 0x180D8,
   NiFpga_main_IndicatorI32_fxp_T_extra1 = 0x180DC,
   NiFpga_main_IndicatorI32_fxp_T_extra2 = 0x180E0,
   NiFpga_main_IndicatorI32_fxp_T_piston0 = 0x180F4,
   NiFpga_main_IndicatorI32_fxp_T_piston1 = 0x180F8,
   NiFpga_main_IndicatorI32_fxp_T_piston2 = 0x180FC,
   NiFpga_main_IndicatorI32_fxp_T_piston3 = 0x18100,
   NiFpga_main_IndicatorI32_fxp_T_piston4 = 0x18104,
   NiFpga_main_IndicatorI32_fxp_T_piston5 = 0x18108,
   NiFpga_main_IndicatorI32_fxp_T_piston6 = 0x1810C,
   NiFpga_main_IndicatorI32_fxp_T_piston7 = 0x18110,
   NiFpga_main_IndicatorI32_fxp_T_pneum = 0x180D4,
   NiFpga_main_IndicatorI32_fxp_T_pod = 0x180D0,
   NiFpga_main_IndicatorI32_fxp_brake_distance = 0x1811C,
   NiFpga_main_IndicatorI32_fxp_brake_force = 0x18114,
   NiFpga_main_IndicatorI32_fxp_cur_thresh_max = 0x1814C,
   NiFpga_main_IndicatorI32_fxp_cur_thresh_min = 0x18148,
   NiFpga_main_IndicatorI32_fxp_current_p1 = 0x18008,
   NiFpga_main_IndicatorI32_fxp_current_p2 = 0x1800C,
   NiFpga_main_IndicatorI32_fxp_current_r = 0x18010,
   NiFpga_main_IndicatorI32_fxp_fusion_distance = 0x18144,
   NiFpga_main_IndicatorI32_fxp_imu_distance = 0x18138,
   NiFpga_main_IndicatorI32_fxp_mc_distance = 0x1813C,
   NiFpga_main_IndicatorI32_fxp_tape_distance = 0x18118,
   NiFpga_main_IndicatorI32_fxp_tape_velocity = 0x180C0,
   NiFpga_main_IndicatorI32_fxp_voltage_p1 = 0x18050,
   NiFpga_main_IndicatorI32_fxp_voltage_p2 = 0x18054,
   NiFpga_main_IndicatorI32_fxp_voltage_r = 0x18058,
} NiFpga_main_IndicatorI32;

typedef enum
{
   NiFpga_main_IndicatorU32_cur_thresh_persistence = 0x18154,
   NiFpga_main_IndicatorU32_cur_thresh_ratio = 0x18150,
} NiFpga_main_IndicatorU32;

typedef enum
{
   NiFpga_main_IndicatorU64_fault_long_2 = 0x18048,
   NiFpga_main_IndicatorU64_fault_long_3 = 0x1804C,
   NiFpga_main_IndicatorU64_hard_fault = 0x18040,
   NiFpga_main_IndicatorU64_soft_fault = 0x18044,
} NiFpga_main_IndicatorU64;

typedef enum
{
   NiFpga_main_ControlBool_actuate_brakes = 0x18002,
   NiFpga_main_ControlBool_actuate_drain = 0x18006,
   NiFpga_main_ControlBool_avb_shutoff_prim_1 = 0x18092,
   NiFpga_main_ControlBool_avb_shutoff_prim_2 = 0x18096,
   NiFpga_main_ControlBool_avb_shutoff_res = 0x1809A,
   NiFpga_main_ControlBool_enable_checks = 0x18122,
   NiFpga_main_ControlBool_frg_run = 0x1815E,
   NiFpga_main_ControlBool_hvr_1 = 0x1809E,
   NiFpga_main_ControlBool_hvr_2 = 0x180A2,
   NiFpga_main_ControlBool_hvr_3 = 0x180A6,
   NiFpga_main_ControlBool_hvr_4 = 0x180AA,
   NiFpga_main_ControlBool_iso_led_1 = 0x1808A,
   NiFpga_main_ControlBool_iso_led_2 = 0x1808E,
   NiFpga_main_ControlBool_reset_tape_count = 0x1812E,
   NiFpga_main_ControlBool_reset_tape_status = 0x18132,
   NiFpga_main_ControlBool_stop = 0x18016,
   NiFpga_main_ControlBool_thresh_latch_new = 0x1802E,
   NiFpga_main_ControlBool_thresh_reset = 0x18036,
} NiFpga_main_ControlBool;

typedef enum
{
   NiFpga_main_ControlU8_thresh_read_index = 0x1803A,
   NiFpga_main_ControlU8_thresh_reset_index = 0x18032,
   NiFpga_main_ControlU8_thresh_write_index = 0x1801A,
} NiFpga_main_ControlU8;

typedef enum
{
   NiFpga_main_ControlI32_fxp_imu_acc = 0x18134,
   NiFpga_main_ControlI32_fxp_mc_linear_v = 0x18140,
   NiFpga_main_ControlI32_fxp_thresh_new_max = 0x18020,
   NiFpga_main_ControlI32_fxp_thresh_new_min = 0x1801C,
} NiFpga_main_ControlI32;

typedef enum
{
   NiFpga_main_ControlU32_thresh_f_ratio = 0x18028,
   NiFpga_main_ControlU32_thresh_persistence = 0x18024,
} NiFpga_main_ControlU32;

#endif
