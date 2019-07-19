/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_imu_test_h__
#define __NiFpga_imu_test_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_imu_test_Bitfile;
 */
#define NiFpga_imu_test_Bitfile "NiFpga_imu_test.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_imu_test_Signature = "6C5E55B5EF71C4C7E8986A3B0B9219B9";

typedef enum
{
   NiFpga_imu_test_IndicatorI32_velocity = 0x18008,
} NiFpga_imu_test_IndicatorI32;

typedef enum
{
   NiFpga_imu_test_IndicatorI64_distance = 0x1800C,
} NiFpga_imu_test_IndicatorI64;

typedef enum
{
   NiFpga_imu_test_ControlBool_stop = 0x18012,
} NiFpga_imu_test_ControlBool;

typedef enum
{
   NiFpga_imu_test_ControlI32_imu_acc = 0x18000,
} NiFpga_imu_test_ControlI32;

typedef enum
{
   NiFpga_imu_test_ControlI64_timestamp = 0x18004,
} NiFpga_imu_test_ControlI64;

#endif
