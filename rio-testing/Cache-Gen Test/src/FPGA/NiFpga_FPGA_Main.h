/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_FPGA_Main_h__
#define __NiFpga_FPGA_Main_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_FPGA_Main_Bitfile;
 */
#define NiFpga_FPGA_Main_Bitfile "NiFpga_FPGA_Main.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_FPGA_Main_Signature = "5047CC6F3BB3696CE29F14EDFCE6994F";

typedef enum
{
   NiFpga_FPGA_Main_IndicatorBool_BLRaw = 0x180BE,
   NiFpga_FPGA_Main_IndicatorBool_BLTape = 0x180B2,
   NiFpga_FPGA_Main_IndicatorBool_BRRaw = 0x180DA,
   NiFpga_FPGA_Main_IndicatorBool_BRTape = 0x180CE,
   NiFpga_FPGA_Main_IndicatorBool_Downstream2PressureFault = 0x18032,
   NiFpga_FPGA_Main_IndicatorBool_DownstreamPressureFault = 0x18016,
   NiFpga_FPGA_Main_IndicatorBool_DownstreamPressureLow = 0x1801E,
   NiFpga_FPGA_Main_IndicatorBool_FLRaw = 0x180CA,
   NiFpga_FPGA_Main_IndicatorBool_FRRaw = 0x180AE,
   NiFpga_FPGA_Main_IndicatorBool_IRFault = 0x1800A,
   NiFpga_FPGA_Main_IndicatorBool_LeftLSFault = 0x18092,
   NiFpga_FPGA_Main_IndicatorBool_Levitating = 0x18072,
   NiFpga_FPGA_Main_IndicatorBool_PrimaryBattery1Critical = 0x18046,
   NiFpga_FPGA_Main_IndicatorBool_PrimaryBattery1Low = 0x18042,
   NiFpga_FPGA_Main_IndicatorBool_PrimaryBattery2Critical = 0x1804E,
   NiFpga_FPGA_Main_IndicatorBool_PrimaryBattery2Low = 0x1804A,
   NiFpga_FPGA_Main_IndicatorBool_PusherConnected = 0x1800E,
   NiFpga_FPGA_Main_IndicatorBool_ReserveBatteryCritical = 0x18056,
   NiFpga_FPGA_Main_IndicatorBool_ReserveBatteryLow = 0x18052,
   NiFpga_FPGA_Main_IndicatorBool_RightLSFault = 0x18096,
   NiFpga_FPGA_Main_IndicatorBool_TankPressueLow = 0x1801A,
   NiFpga_FPGA_Main_IndicatorBool_TankPressureFault = 0x18012,
} NiFpga_FPGA_Main_IndicatorBool;

typedef enum
{
   NiFpga_FPGA_Main_IndicatorU8_BLCount = 0x180BA,
   NiFpga_FPGA_Main_IndicatorU8_BRCount = 0x180D6,
   NiFpga_FPGA_Main_IndicatorU8_FLCount = 0x180C6,
   NiFpga_FPGA_Main_IndicatorU8_FRCount = 0x180AA,
} NiFpga_FPGA_Main_IndicatorU8;

typedef enum
{
   NiFpga_FPGA_Main_IndicatorI16_PCS1Position = 0x18076,
   NiFpga_FPGA_Main_IndicatorI16_PCS2Position = 0x1807A,
   NiFpga_FPGA_Main_IndicatorI16_PCS3Position = 0x1807E,
   NiFpga_FPGA_Main_IndicatorI16_PCS4Position = 0x18082,
} NiFpga_FPGA_Main_IndicatorI16;

typedef enum
{
   NiFpga_FPGA_Main_IndicatorU32_LeftTapeCount = 0x18088,
   NiFpga_FPGA_Main_IndicatorU32_RawmsDifferenceL = 0x180E0,
   NiFpga_FPGA_Main_IndicatorU32_RawmsDifferenceR = 0x180EC,
   NiFpga_FPGA_Main_IndicatorU32_RightTapeCount = 0x1808C,
   NiFpga_FPGA_Main_IndicatorU32_TickCountuSec = 0x180A0,
   NiFpga_FPGA_Main_IndicatorU32_testtime = 0x18084,
} NiFpga_FPGA_Main_IndicatorU32;

typedef enum
{
   NiFpga_FPGA_Main_IndicatorSgl_AmbientPressure = 0x1802C,
   NiFpga_FPGA_Main_IndicatorSgl_DownstreamLeftPressure = 0x18020,
   NiFpga_FPGA_Main_IndicatorSgl_DownstreamRightPressure = 0x18028,
   NiFpga_FPGA_Main_IndicatorSgl_IR1RAW = 0x18000,
   NiFpga_FPGA_Main_IndicatorSgl_IR2RAW = 0x18004,
   NiFpga_FPGA_Main_IndicatorSgl_LeftVelocity = 0x18098,
   NiFpga_FPGA_Main_IndicatorSgl_LevitationHeight = 0x1806C,
   NiFpga_FPGA_Main_IndicatorSgl_PrimaryBattery1Voltage = 0x18034,
   NiFpga_FPGA_Main_IndicatorSgl_PrimaryBattery2Voltage = 0x18038,
   NiFpga_FPGA_Main_IndicatorSgl_ReserveBatteryVoltage = 0x1803C,
   NiFpga_FPGA_Main_IndicatorSgl_RightVelocity = 0x1809C,
   NiFpga_FPGA_Main_IndicatorSgl_TankPressure = 0x18024,
   NiFpga_FPGA_Main_IndicatorSgl_VelocityLeftms = 0x180E4,
   NiFpga_FPGA_Main_IndicatorSgl_VelocityRightms = 0x180F0,
} NiFpga_FPGA_Main_IndicatorSgl;

typedef enum
{
   NiFpga_FPGA_Main_ControlBool_ResetBL = 0x180B6,
   NiFpga_FPGA_Main_ControlBool_ResetBR = 0x180D2,
   NiFpga_FPGA_Main_ControlBool_ResetFL = 0x180C2,
   NiFpga_FPGA_Main_ControlBool_ResetFR = 0x180A6,
   NiFpga_FPGA_Main_ControlBool_StopL = 0x180DE,
   NiFpga_FPGA_Main_ControlBool_StopR = 0x180EA,
} NiFpga_FPGA_Main_ControlBool;

#endif
