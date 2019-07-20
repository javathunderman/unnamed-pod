#ifndef __FPGA_CACHE__
#define __FPGA_CACHE__
#include "NiFpga_FPGA_Main.h"
#include "NiFpga.h"

typedef struct {
	NiFpga_Bool BLRaw;
	NiFpga_Bool BLTape;
	NiFpga_Bool BRRaw;
	NiFpga_Bool BRTape;
	NiFpga_Bool Downstream2PressureFault;
	NiFpga_Bool DownstreamPressureFault;
	NiFpga_Bool DownstreamPressureLow;
	NiFpga_Bool FLRaw;
	NiFpga_Bool FRRaw;
	NiFpga_Bool IRFault;
	NiFpga_Bool LeftLSFault;
	NiFpga_Bool Levitating;
	NiFpga_Bool PrimaryBattery1Critical;
	NiFpga_Bool PrimaryBattery1Low;
	NiFpga_Bool PrimaryBattery2Critical;
	NiFpga_Bool PrimaryBattery2Low;
	NiFpga_Bool PusherConnected;
	NiFpga_Bool ReserveBatteryCritical;
	NiFpga_Bool ReserveBatteryLow;
	NiFpga_Bool RightLSFault;
	NiFpga_Bool TankPressueLow;
	NiFpga_Bool TankPressureFault;
	uint8_t BLCount;
	uint8_t BRCount;
	uint8_t FLCount;
	uint8_t FRCount;
	int16_t PCS1Position;
	int16_t PCS2Position;
	int16_t PCS3Position;
	int16_t PCS4Position;
	uint32_t LeftTapeCount;
	uint32_t RawmsDifferenceL;
	uint32_t RawmsDifferenceR;
	uint32_t RightTapeCount;
	uint32_t TickCountuSec;
	uint32_t testtime;
	float AmbientPressure;
	float DownstreamLeftPressure;
	float DownstreamRightPressure;
	float IR1RAW;
	float IR2RAW;
	float LeftVelocity;
	float LevitationHeight;
	float PrimaryBattery1Voltage;
	float PrimaryBattery2Voltage;
	float ReserveBatteryVoltage;
	float RightVelocity;
	float TankPressure;
	float VelocityLeftms;
	float VelocityRightms;
} Cache;

typedef struct {
	NiFpga_Status status;
	char *bit_path;
	char *signature;
	char *resource;
	NiFpga_Session session;
	Cache cache;
} Fpga;



void default_fpga(Fpga *fpga);

NiFpga_Status init_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status run_fpga(Fpga *fpga, uint32_t attr);

NiFpga_Status refresh_cache(Fpga *Fpga);

NiFpga_Status fpclose(Fpga *fpga, uint32_t attr);

NiFpga_Status fpfinalize(Fpga *fpga);

NiFpga_Status write_ResetBL(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_ResetBR(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_ResetFL(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_ResetFR(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_StopL(Fpga *fpga, NiFpga_Bool v);

NiFpga_Status write_StopR(Fpga *fpga, NiFpga_Bool v);

#endif
