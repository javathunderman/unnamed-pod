#include "fpga_cache.h"

#include "NiFpga_FPGA_Main.h"
#include "NiFpga.h"

NiFpga_Status init_fpga(Fpga *fpga, uint32_t attr){
	NiFpga_IfIsNotError(fpga->status, NiFpga_Initialize());
	NiFpga_IfIsNotError(fpga->status, NiFpga_Open(fpga->bit_path, fpga->signature, 
                        fpga->resource, 
                        NiFpga_OpenAttribute_NoRun | attr, 
                        &(fpga->session)));
	
	return fpga->status;
}

NiFpga_Status run_fpga(Fpga *fpga, uint32_t attr){
	NiFpga_IfIsNotError(fpga->status, NiFpga_Run(fpga->session, attr));
	
	return fpga->status;
}

NiFpga_Status refresh_cache(Fpga *fpga){
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180BE, &(fpga->cache.BLRaw)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180B2, &(fpga->cache.BLTape)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180DA, &(fpga->cache.BRRaw)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180CE, &(fpga->cache.BRTape)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18032, &(fpga->cache.Downstream2PressureFault)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18016, &(fpga->cache.DownstreamPressureFault)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1801E, &(fpga->cache.DownstreamPressureLow)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180CA, &(fpga->cache.FLRaw)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180AE, &(fpga->cache.FRRaw)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1800A, &(fpga->cache.IRFault)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18092, &(fpga->cache.LeftLSFault)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18072, &(fpga->cache.Levitating)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18046, &(fpga->cache.PrimaryBattery1Critical)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18042, &(fpga->cache.PrimaryBattery1Low)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1804E, &(fpga->cache.PrimaryBattery2Critical)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1804A, &(fpga->cache.PrimaryBattery2Low)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1800E, &(fpga->cache.PusherConnected)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18056, &(fpga->cache.ReserveBatteryCritical)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18052, &(fpga->cache.ReserveBatteryLow)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18096, &(fpga->cache.RightLSFault)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1801A, &(fpga->cache.TankPressueLow)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18012, &(fpga->cache.TankPressureFault)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU8(fpga->session, 0x180BA, &(fpga->cache.BLCount)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU8(fpga->session, 0x180D6, &(fpga->cache.BRCount)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU8(fpga->session, 0x180C6, &(fpga->cache.FLCount)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU8(fpga->session, 0x180AA, &(fpga->cache.FRCount)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI16(fpga->session, 0x18076, &(fpga->cache.PCS1Position)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI16(fpga->session, 0x1807A, &(fpga->cache.PCS2Position)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI16(fpga->session, 0x1807E, &(fpga->cache.PCS3Position)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI16(fpga->session, 0x18082, &(fpga->cache.PCS4Position)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU32(fpga->session, 0x18088, &(fpga->cache.LeftTapeCount)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU32(fpga->session, 0x180E0, &(fpga->cache.RawmsDifferenceL)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU32(fpga->session, 0x180EC, &(fpga->cache.RawmsDifferenceR)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU32(fpga->session, 0x1808C, &(fpga->cache.RightTapeCount)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU32(fpga->session, 0x180A0, &(fpga->cache.TickCountuSec)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU32(fpga->session, 0x18084, &(fpga->cache.testtime)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x1802C, &(fpga->cache.AmbientPressure)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x18020, &(fpga->cache.DownstreamLeftPressure)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x18028, &(fpga->cache.DownstreamRightPressure)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x18000, &(fpga->cache.IR1RAW)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x18004, &(fpga->cache.IR2RAW)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x18098, &(fpga->cache.LeftVelocity)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x1806C, &(fpga->cache.LevitationHeight)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x18034, &(fpga->cache.PrimaryBattery1Voltage)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x18038, &(fpga->cache.PrimaryBattery2Voltage)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x1803C, &(fpga->cache.ReserveBatteryVoltage)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x1809C, &(fpga->cache.RightVelocity)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x18024, &(fpga->cache.TankPressure)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x180E4, &(fpga->cache.VelocityLeftms)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadSgl(fpga->session, 0x180F0, &(fpga->cache.VelocityRightms)));
	return fpga->status;
}

NiFpga_Status write_ResetBL(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteSgl(fpga->session, 0x180F0, v));
	return fpga->status;
}

NiFpga_Status write_ResetBR(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteSgl(fpga->session, 0x180F0, v));
	return fpga->status;
}

NiFpga_Status write_ResetFL(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteSgl(fpga->session, 0x180F0, v));
	return fpga->status;
}

NiFpga_Status write_ResetFR(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteSgl(fpga->session, 0x180F0, v));
	return fpga->status;
}

NiFpga_Status write_StopL(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteSgl(fpga->session, 0x180F0, v));
	return fpga->status;
}

NiFpga_Status write_StopR(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteSgl(fpga->session, 0x180F0, v));
	return fpga->status;
}

