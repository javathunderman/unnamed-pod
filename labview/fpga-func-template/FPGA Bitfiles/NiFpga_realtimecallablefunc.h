/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_realtimecallablefunc_h__
#define __NiFpga_realtimecallablefunc_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_realtimecallablefunc_Bitfile;
 */
#define NiFpga_realtimecallablefunc_Bitfile "NiFpga_realtimecallablefunc.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_realtimecallablefunc_Signature = "B840A2EB19DE5DB071B6E40FD0A960CC";

typedef enum
{
   NiFpga_realtimecallablefunc_IndicatorBool_readyforinput = 0x18006,
} NiFpga_realtimecallablefunc_IndicatorBool;

typedef enum
{
   NiFpga_realtimecallablefunc_ControlBool_readyforoutputT = 0x1800A,
   NiFpga_realtimecallablefunc_ControlBool_stop = 0x18012,
} NiFpga_realtimecallablefunc_ControlBool;

#endif
