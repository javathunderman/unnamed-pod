/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_test_brake_actuation_h__
#define __NiFpga_test_brake_actuation_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_test_brake_actuation_Bitfile;
 */
#define NiFpga_test_brake_actuation_Bitfile "NiFpga_test_brake_actuation.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_test_brake_actuation_Signature = "A5182F62CC291198A79066D819063177";

typedef enum
{
   NiFpga_test_brake_actuation_IndicatorBool_current_brake_state = 0x1800A,
   NiFpga_test_brake_actuation_IndicatorBool_current_drain_valve_state = 0x1800E,
} NiFpga_test_brake_actuation_IndicatorBool;

typedef enum
{
   NiFpga_test_brake_actuation_IndicatorI32_fxp_pressure_14 = 0x18014,
   NiFpga_test_brake_actuation_IndicatorI32_fxp_pressure_15 = 0x18018,
   NiFpga_test_brake_actuation_IndicatorI32_fxp_pressure_16 = 0x1801C,
   NiFpga_test_brake_actuation_IndicatorI32_fxp_pressure_17 = 0x18020,
   NiFpga_test_brake_actuation_IndicatorI32_fxp_pressure_18 = 0x18024,
   NiFpga_test_brake_actuation_IndicatorI32_fxp_pressure_19 = 0x18028,
   NiFpga_test_brake_actuation_IndicatorI32_fxp_pressure_20 = 0x1802C,
   NiFpga_test_brake_actuation_IndicatorI32_fxp_pressure_21 = 0x18030,
   NiFpga_test_brake_actuation_IndicatorI32_fxp_pressure_22 = 0x18034,
} NiFpga_test_brake_actuation_IndicatorI32;

typedef enum
{
   NiFpga_test_brake_actuation_ControlBool_set_brakes = 0x18002,
   NiFpga_test_brake_actuation_ControlBool_set_drain_valve = 0x18006,
   NiFpga_test_brake_actuation_ControlBool_stop = 0x18012,
} NiFpga_test_brake_actuation_ControlBool;

#endif
