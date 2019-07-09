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
static const char* const NiFpga_main_Signature = "8C8EB345027561D47C47677FEE5ED760";

typedef enum
{
   NiFpga_main_IndicatorBool_FIFO_timeout = 0x180AA,
   NiFpga_main_IndicatorBool_TO_daq_av_fuses = 0x1809E,
   NiFpga_main_IndicatorBool_TO_daq_pressure = 0x180B6,
   NiFpga_main_IndicatorBool_TO_daq_vol_cur = 0x18096,
   NiFpga_main_IndicatorBool_TO_dat_pressure = 0x1809A,
   NiFpga_main_IndicatorBool_TO_dat_vol_cur = 0x18082,
   NiFpga_main_IndicatorBool_brake_state = 0x180AE,
   NiFpga_main_IndicatorBool_drain_valve_state = 0x180B2,
   NiFpga_main_IndicatorBool_fuse_av_1 = 0x180A2,
   NiFpga_main_IndicatorBool_fuse_av_2 = 0x180A6,
} NiFpga_main_IndicatorBool;

typedef enum
{
   NiFpga_main_IndicatorU16_count_laser_l = 0x18036,
   NiFpga_main_IndicatorU16_count_laser_r = 0x18032,
   NiFpga_main_IndicatorU16_count_light_bl = 0x1802E,
   NiFpga_main_IndicatorU16_count_light_br = 0x1802A,
   NiFpga_main_IndicatorU16_count_light_fl = 0x18026,
   NiFpga_main_IndicatorU16_count_light_fr = 0x18022,
} NiFpga_main_IndicatorU16;

typedef enum
{
   NiFpga_main_IndicatorI32_I_av_pb_1 = 0x18008,
   NiFpga_main_IndicatorI32_I_av_pb_2 = 0x1800C,
   NiFpga_main_IndicatorI32_I_av_rb = 0x18010,
   NiFpga_main_IndicatorI32_V_av_pb_1 = 0x18014,
   NiFpga_main_IndicatorI32_V_av_pb_2 = 0x18018,
   NiFpga_main_IndicatorI32_V_av_rb = 0x1801C,
} NiFpga_main_IndicatorI32;

typedef enum
{
   NiFpga_main_IndicatorU64_fault_long_0 = 0x18070,
   NiFpga_main_IndicatorU64_fault_long_1 = 0x18074,
   NiFpga_main_IndicatorU64_fault_long_2 = 0x18078,
   NiFpga_main_IndicatorU64_fault_long_3 = 0x1807C,
} NiFpga_main_IndicatorU64;

typedef enum
{
   NiFpga_main_ControlBool_brakes = 0x18002,
   NiFpga_main_ControlBool_drain_valve = 0x18006,
   NiFpga_main_ControlBool_prim_bat_1 = 0x1803A,
   NiFpga_main_ControlBool_prim_bat_2 = 0x1803E,
   NiFpga_main_ControlBool_prim_bat_3 = 0x18042,
   NiFpga_main_ControlBool_stop = 0x18046,
   NiFpga_main_ControlBool_thresh_latch_new = 0x1805E,
   NiFpga_main_ControlBool_thresh_reset = 0x18066,
} NiFpga_main_ControlBool;

typedef enum
{
   NiFpga_main_ControlU8_thresh_read_index = 0x1806A,
   NiFpga_main_ControlU8_thresh_reset_index = 0x18062,
   NiFpga_main_ControlU8_thresh_write_index = 0x1804A,
} NiFpga_main_ControlU8;

typedef enum
{
   NiFpga_main_ControlU32_thresh_f_ratio = 0x18058,
   NiFpga_main_ControlU32_thresh_persistence = 0x18054,
} NiFpga_main_ControlU32;

#endif
