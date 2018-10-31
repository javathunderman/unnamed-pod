/*
 * Generated with the FPGA Interface C API Generator 17.0.0
 * for NI-RIO 17.0.0 or later.
 */

#ifndef __NiFpga_ExampleCompactRIO_h__
#define __NiFpga_ExampleCompactRIO_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1700
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_ExampleCompactRIO_Bitfile;
 */
#define NiFpga_ExampleCompactRIO_Bitfile "NiFpga_ExampleCompactRIO.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_ExampleCompactRIO_Signature = "312CCCF8D75C50256299740DF6AA3F71";

typedef enum
{
   NiFpga_ExampleCompactRIO_IndicatorI16_DeviceTemperature = 0x18006,
} NiFpga_ExampleCompactRIO_IndicatorI16;

typedef enum
{
   NiFpga_ExampleCompactRIO_ControlBool_Stop = 0x18002,
} NiFpga_ExampleCompactRIO_ControlBool;

#endif
