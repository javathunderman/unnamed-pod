/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_brake_test_h__
#define __NiFpga_brake_test_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_brake_test_Bitfile;
 */
#define NiFpga_brake_test_Bitfile "NiFpga_brake_test.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_brake_test_Signature = "BA9A0066DF553608521000818FA7C825";

typedef enum
{
   NiFpga_brake_test_IndicatorBool_FIFO_timeout = 0x18002,
   NiFpga_brake_test_IndicatorBool_brake_state = 0x1800A,
   NiFpga_brake_test_IndicatorBool_drain_valve_state = 0x1800E,
} NiFpga_brake_test_IndicatorBool;

typedef enum
{
   NiFpga_brake_test_IndicatorI32_fxp_P_hp1 = 0x18010,
   NiFpga_brake_test_IndicatorI32_fxp_P_hp2 = 0x18014,
   NiFpga_brake_test_IndicatorI32_fxp_P_lp1 = 0x18018,
   NiFpga_brake_test_IndicatorI32_fxp_P_lp2 = 0x1801C,
} NiFpga_brake_test_IndicatorI32;

typedef enum
{
   NiFpga_brake_test_ControlBool_brake_1 = 0x18022,
   NiFpga_brake_test_ControlBool_brake_2 = 0x18026,
   NiFpga_brake_test_ControlBool_drain = 0x1802A,
   NiFpga_brake_test_ControlBool_stop = 0x18006,
} NiFpga_brake_test_ControlBool;

#endif
