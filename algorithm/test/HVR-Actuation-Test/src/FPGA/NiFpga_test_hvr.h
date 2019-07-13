/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_test_hvr_h__
#define __NiFpga_test_hvr_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_test_hvr_Bitfile;
 */
#define NiFpga_test_hvr_Bitfile "NiFpga_test_hvr.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_test_hvr_Signature = "49B344D1F73C608B2BE809F814BC64FD";

typedef enum
{
   NiFpga_test_hvr_IndicatorBool_HVR_1 = 0x18016,
   NiFpga_test_hvr_IndicatorBool_HVR_2 = 0x1801A,
   NiFpga_test_hvr_IndicatorBool_HVR_3 = 0x1801E,
   NiFpga_test_hvr_IndicatorBool_HVR_4 = 0x18022,
} NiFpga_test_hvr_IndicatorBool;

typedef enum
{
   NiFpga_test_hvr_ControlBool_hvr_1 = 0x18006,
   NiFpga_test_hvr_ControlBool_hvr_2 = 0x1800A,
   NiFpga_test_hvr_ControlBool_hvr_3 = 0x1800E,
   NiFpga_test_hvr_ControlBool_hvr_4 = 0x18012,
   NiFpga_test_hvr_ControlBool_stop = 0x18002,
} NiFpga_test_hvr_ControlBool;

#endif
