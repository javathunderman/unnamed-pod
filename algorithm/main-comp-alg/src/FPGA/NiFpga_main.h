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
static const char* const NiFpga_main_Signature = "B5141D4160260B69326D2721B1EB6911";

typedef enum
{
   NiFpga_main_IndicatorBool_FIFO_timeout_analog = 0x180DA,
   NiFpga_main_IndicatorBool_FIFO_timeout_laser = 0x180D6,
   NiFpga_main_IndicatorBool_FIFO_timeout_retro = 0x180D2,
   NiFpga_main_IndicatorBool_HVR_1_state = 0x1808A,
   NiFpga_main_IndicatorBool_HVR_2_state = 0x1808E,
   NiFpga_main_IndicatorBool_HVR_3_state = 0x18092,
   NiFpga_main_IndicatorBool_HVR_4_state = 0x18096,
   NiFpga_main_IndicatorBool_avb_shutoff_p1_state = 0x180A2,
   NiFpga_main_IndicatorBool_avb_shutoff_p2_state = 0x180A6,
   NiFpga_main_IndicatorBool_avb_shutoff_r_state = 0x180AA,
   NiFpga_main_IndicatorBool_brake_state = 0x18082,
   NiFpga_main_IndicatorBool_drain_valve_state = 0x18086,
   NiFpga_main_IndicatorBool_iso_led_1_state = 0x1809A,
   NiFpga_main_IndicatorBool_iso_led_2_state = 0x1809E,
} NiFpga_main_IndicatorBool;

typedef enum
{
   NiFpga_main_IndicatorU8_light_BL_count = 0x180E2,
   NiFpga_main_IndicatorU8_light_BR_count = 0x180E6,
   NiFpga_main_IndicatorU8_light_FL_count = 0x180DE,
   NiFpga_main_IndicatorU8_light_L_count = 0x180EA,
   NiFpga_main_IndicatorU8_light_R_count = 0x180EE,
} NiFpga_main_IndicatorU8;

typedef enum
{
   NiFpga_main_IndicatorU16_count_laser_l = 0x1802A,
   NiFpga_main_IndicatorU16_count_laser_r = 0x18026,
   NiFpga_main_IndicatorU16_count_light_bl = 0x18022,
   NiFpga_main_IndicatorU16_count_light_br = 0x1801E,
   NiFpga_main_IndicatorU16_count_light_fl = 0x1801A,
   NiFpga_main_IndicatorU16_count_light_fr = 0x18016,
} NiFpga_main_IndicatorU16;

typedef enum
{
   NiFpga_main_IndicatorI32_fxp_P_hp1 = 0x18114,
   NiFpga_main_IndicatorI32_fxp_P_hp2 = 0x18118,
   NiFpga_main_IndicatorI32_fxp_P_lp1 = 0x1811C,
   NiFpga_main_IndicatorI32_fxp_P_lp2 = 0x18120,
   NiFpga_main_IndicatorI32_fxp_T_cRIO = 0x18108,
   NiFpga_main_IndicatorI32_fxp_T_extra1 = 0x1810C,
   NiFpga_main_IndicatorI32_fxp_T_extra2 = 0x18110,
   NiFpga_main_IndicatorI32_fxp_T_p1 = 0x180F4,
   NiFpga_main_IndicatorI32_fxp_T_p2 = 0x180F8,
   NiFpga_main_IndicatorI32_fxp_T_piston0 = 0x18124,
   NiFpga_main_IndicatorI32_fxp_T_piston1 = 0x18128,
   NiFpga_main_IndicatorI32_fxp_T_piston2 = 0x1812C,
   NiFpga_main_IndicatorI32_fxp_T_piston3 = 0x18130,
   NiFpga_main_IndicatorI32_fxp_T_piston4 = 0x18134,
   NiFpga_main_IndicatorI32_fxp_T_piston5 = 0x18138,
   NiFpga_main_IndicatorI32_fxp_T_piston6 = 0x1813C,
   NiFpga_main_IndicatorI32_fxp_T_piston7 = 0x18140,
   NiFpga_main_IndicatorI32_fxp_T_pneum = 0x18104,
   NiFpga_main_IndicatorI32_fxp_T_pod = 0x18100,
   NiFpga_main_IndicatorI32_fxp_T_r = 0x180FC,
   NiFpga_main_IndicatorI32_fxp_current_p1 = 0x18008,
   NiFpga_main_IndicatorI32_fxp_current_p2 = 0x1800C,
   NiFpga_main_IndicatorI32_fxp_current_r = 0x18010,
   NiFpga_main_IndicatorI32_fxp_tape_velocity = 0x180F0,
   NiFpga_main_IndicatorI32_fxp_voltage_p1 = 0x18074,
   NiFpga_main_IndicatorI32_fxp_voltage_p2 = 0x18078,
   NiFpga_main_IndicatorI32_fxp_voltage_r = 0x1807C,
} NiFpga_main_IndicatorI32;

typedef enum
{
   NiFpga_main_IndicatorU64_fault_long_0 = 0x18064,
   NiFpga_main_IndicatorU64_fault_long_1 = 0x18068,
   NiFpga_main_IndicatorU64_fault_long_2 = 0x1806C,
   NiFpga_main_IndicatorU64_fault_long_3 = 0x18070,
} NiFpga_main_IndicatorU64;

typedef enum
{
   NiFpga_main_ControlBool_actuate_brakes = 0x18002,
   NiFpga_main_ControlBool_actuate_drain = 0x18006,
   NiFpga_main_ControlBool_avb_shutoff_prim_1 = 0x180B6,
   NiFpga_main_ControlBool_avb_shutoff_prim_2 = 0x180BA,
   NiFpga_main_ControlBool_avb_shutoff_res = 0x180BE,
   NiFpga_main_ControlBool_hvr_1 = 0x180C2,
   NiFpga_main_ControlBool_hvr_2 = 0x180C6,
   NiFpga_main_ControlBool_hvr_3 = 0x180CA,
   NiFpga_main_ControlBool_hvr_4 = 0x180CE,
   NiFpga_main_ControlBool_iso_led_1 = 0x180AE,
   NiFpga_main_ControlBool_iso_led_2 = 0x180B2,
   NiFpga_main_ControlBool_prim_bat_1 = 0x1802E,
   NiFpga_main_ControlBool_prim_bat_2 = 0x18032,
   NiFpga_main_ControlBool_prim_bat_3 = 0x18036,
   NiFpga_main_ControlBool_stop = 0x1803A,
   NiFpga_main_ControlBool_thresh_latch_new = 0x18052,
   NiFpga_main_ControlBool_thresh_reset = 0x1805A,
} NiFpga_main_ControlBool;

typedef enum
{
   NiFpga_main_ControlU8_thresh_read_index = 0x1805E,
   NiFpga_main_ControlU8_thresh_reset_index = 0x18056,
   NiFpga_main_ControlU8_thresh_write_index = 0x1803E,
} NiFpga_main_ControlU8;

typedef enum
{
   NiFpga_main_ControlU32_thresh_f_ratio = 0x1804C,
   NiFpga_main_ControlU32_thresh_persistence = 0x18048,
} NiFpga_main_ControlU32;

#endif
