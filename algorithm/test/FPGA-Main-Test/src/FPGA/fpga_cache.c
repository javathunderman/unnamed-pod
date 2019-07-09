#include "fpga_cache.h"

#include "NiFpga_main.h"
#include "NiFpga.h"

void default_fpga(Fpga *fpga) {
	fpga->status = NiFpga_Status_Success;
	fpga->bit_path = "./FPGA/" NiFpga_main_Bitfile;
	fpga->resource = "RIO0";
	fpga->signature = NiFpga_main_Signature;
}

NiFpga_Status init_fpga(Fpga *fpga, uint32_t attr) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_Initialize());
	NiFpga_IfIsNotError(fpga->status, NiFpga_Open(fpga->bit_path, fpga->signature, 
                        fpga->resource, 
                        NiFpga_OpenAttribute_NoRun | attr, 
                        &(fpga->session)));
	
	return fpga->status;
}

NiFpga_Status run_fpga(Fpga *fpga, uint32_t attr) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_Run(fpga->session, attr));
	
	return fpga->status;
}

NiFpga_Status refresh_cache(Fpga *fpga) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180AA, &(fpga->cache.FIFO_timeout)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1809E, &(fpga->cache.TO_daq_av_fuses)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180B6, &(fpga->cache.TO_daq_pressure)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18096, &(fpga->cache.TO_daq_vol_cur)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1809A, &(fpga->cache.TO_dat_pressure)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18082, &(fpga->cache.TO_dat_vol_cur)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180AE, &(fpga->cache.brake_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180B2, &(fpga->cache.drain_valve_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180A2, &(fpga->cache.fuse_av_1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180A6, &(fpga->cache.fuse_av_2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x18036, &(fpga->cache.count_laser_l)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x18032, &(fpga->cache.count_laser_r)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x1802E, &(fpga->cache.count_light_bl)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x1802A, &(fpga->cache.count_light_br)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x18026, &(fpga->cache.count_light_fl)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x18022, &(fpga->cache.count_light_fr)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18008, &(fpga->cache.I_av_pb_1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1800C, &(fpga->cache.I_av_pb_2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18010, &(fpga->cache.I_av_rb)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18014, &(fpga->cache.V_av_pb_1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18018, &(fpga->cache.V_av_pb_2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1801C, &(fpga->cache.V_av_rb)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU64(fpga->session, 0x18070, &(fpga->cache.fault_long_0)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU64(fpga->session, 0x18074, &(fpga->cache.fault_long_1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU64(fpga->session, 0x18078, &(fpga->cache.fault_long_2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU64(fpga->session, 0x1807C, &(fpga->cache.fault_long_3)));
	return fpga->status;
}

NiFpga_Status fpclose(Fpga *fpga, uint32_t attr) {
	NiFpga_MergeStatus(&(fpga->status), NiFpga_Close(fpga->session, attr));
	
	return fpga->status;
}

NiFpga_Status fpfinalize(Fpga *fpga) {
	NiFpga_MergeStatus(&(fpga->status), NiFpga_Finalize());
	
	return fpga->status;
}

NiFpga_Status write_brakes(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18002, v));
	return fpga->status;
}

NiFpga_Status write_drain_valve(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18006, v));
	return fpga->status;
}

NiFpga_Status write_prim_bat_1(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1803A, v));
	return fpga->status;
}

NiFpga_Status write_prim_bat_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1803E, v));
	return fpga->status;
}

NiFpga_Status write_prim_bat_3(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18042, v));
	return fpga->status;
}

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18046, v));
	return fpga->status;
}

NiFpga_Status write_thresh_latch_new(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1805E, v));
	return fpga->status;
}

NiFpga_Status write_thresh_reset(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18066, v));
	return fpga->status;
}

NiFpga_Status write_thresh_read_index(Fpga *fpga, uint8_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU8(fpga->session, 0x1806A, v));
	return fpga->status;
}

NiFpga_Status write_thresh_reset_index(Fpga *fpga, uint8_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU8(fpga->session, 0x18062, v));
	return fpga->status;
}

NiFpga_Status write_thresh_write_index(Fpga *fpga, uint8_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU8(fpga->session, 0x1804A, v));
	return fpga->status;
}

NiFpga_Status write_thresh_f_ratio(Fpga *fpga, uint32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU32(fpga->session, 0x18058, v));
	return fpga->status;
}

NiFpga_Status write_thresh_persistence(Fpga *fpga, uint32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU32(fpga->session, 0x18054, v));
	return fpga->status;
}

