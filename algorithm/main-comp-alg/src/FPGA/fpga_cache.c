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
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180DA, &(fpga->cache.FIFO_timeout_analog)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180D6, &(fpga->cache.FIFO_timeout_laser)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180D2, &(fpga->cache.FIFO_timeout_retro)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1808A, &(fpga->cache.HVR_1_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1808E, &(fpga->cache.HVR_2_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18092, &(fpga->cache.HVR_3_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18096, &(fpga->cache.HVR_4_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180A2, &(fpga->cache.avb_shutoff_p1_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180A6, &(fpga->cache.avb_shutoff_p2_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x180AA, &(fpga->cache.avb_shutoff_r_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18082, &(fpga->cache.brake_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18086, &(fpga->cache.drain_valve_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1809A, &(fpga->cache.iso_led_1_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1809E, &(fpga->cache.iso_led_2_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU8(fpga->session, 0x180E2, &(fpga->cache.light_BL_count)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU8(fpga->session, 0x180E6, &(fpga->cache.light_BR_count)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU8(fpga->session, 0x180DE, &(fpga->cache.light_FL_count)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU8(fpga->session, 0x180EA, &(fpga->cache.light_L_count)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU8(fpga->session, 0x180EE, &(fpga->cache.light_R_count)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x1802A, &(fpga->cache.count_laser_l)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x18026, &(fpga->cache.count_laser_r)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x18022, &(fpga->cache.count_light_bl)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x1801E, &(fpga->cache.count_light_br)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x1801A, &(fpga->cache.count_light_fl)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU16(fpga->session, 0x18016, &(fpga->cache.count_light_fr)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18114, &(fpga->cache.fxp_P_hp1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18118, &(fpga->cache.fxp_P_hp2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1811C, &(fpga->cache.fxp_P_lp1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18120, &(fpga->cache.fxp_P_lp2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18108, &(fpga->cache.fxp_T_cRIO)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1810C, &(fpga->cache.fxp_T_extra1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18110, &(fpga->cache.fxp_T_extra2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x180F4, &(fpga->cache.fxp_T_p1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x180F8, &(fpga->cache.fxp_T_p2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18124, &(fpga->cache.fxp_T_piston0)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18128, &(fpga->cache.fxp_T_piston1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1812C, &(fpga->cache.fxp_T_piston2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18130, &(fpga->cache.fxp_T_piston3)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18134, &(fpga->cache.fxp_T_piston4)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18138, &(fpga->cache.fxp_T_piston5)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1813C, &(fpga->cache.fxp_T_piston6)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18140, &(fpga->cache.fxp_T_piston7)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18104, &(fpga->cache.fxp_T_pneum)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18100, &(fpga->cache.fxp_T_pod)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x180FC, &(fpga->cache.fxp_T_r)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18008, &(fpga->cache.fxp_current_p1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1800C, &(fpga->cache.fxp_current_p2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18010, &(fpga->cache.fxp_current_r)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x180F0, &(fpga->cache.fxp_tape_velocity)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18074, &(fpga->cache.fxp_voltage_p1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18078, &(fpga->cache.fxp_voltage_p2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1807C, &(fpga->cache.fxp_voltage_r)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU64(fpga->session, 0x18064, &(fpga->cache.fault_long_0)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU64(fpga->session, 0x18068, &(fpga->cache.fault_long_1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU64(fpga->session, 0x1806C, &(fpga->cache.fault_long_2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadU64(fpga->session, 0x18070, &(fpga->cache.fault_long_3)));
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

NiFpga_Status write_actuate_brakes(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18002, v));
	return fpga->status;
}

NiFpga_Status write_actuate_drain(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18006, v));
	return fpga->status;
}

NiFpga_Status write_avb_shutoff_prim_1(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180B6, v));
	return fpga->status;
}

NiFpga_Status write_avb_shutoff_prim_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180BA, v));
	return fpga->status;
}

NiFpga_Status write_avb_shutoff_res(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180BE, v));
	return fpga->status;
}

NiFpga_Status write_hvr_1(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180C2, v));
	return fpga->status;
}

NiFpga_Status write_hvr_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180C6, v));
	return fpga->status;
}

NiFpga_Status write_hvr_3(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180CA, v));
	return fpga->status;
}

NiFpga_Status write_hvr_4(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180CE, v));
	return fpga->status;
}

NiFpga_Status write_iso_led_1(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180AE, v));
	return fpga->status;
}

NiFpga_Status write_iso_led_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180B2, v));
	return fpga->status;
}

NiFpga_Status write_prim_bat_1(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1802E, v));
	return fpga->status;
}

NiFpga_Status write_prim_bat_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18032, v));
	return fpga->status;
}

NiFpga_Status write_prim_bat_3(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18036, v));
	return fpga->status;
}

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1803A, v));
	return fpga->status;
}

NiFpga_Status write_thresh_latch_new(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18052, v));
	return fpga->status;
}

NiFpga_Status write_thresh_reset(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1805A, v));
	return fpga->status;
}

NiFpga_Status write_thresh_read_index(Fpga *fpga, uint8_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU8(fpga->session, 0x1805E, v));
	return fpga->status;
}

NiFpga_Status write_thresh_reset_index(Fpga *fpga, uint8_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU8(fpga->session, 0x18056, v));
	return fpga->status;
}

NiFpga_Status write_thresh_write_index(Fpga *fpga, uint8_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU8(fpga->session, 0x1803E, v));
	return fpga->status;
}

NiFpga_Status write_thresh_f_ratio(Fpga *fpga, uint32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU32(fpga->session, 0x1804C, v));
	return fpga->status;
}

NiFpga_Status write_thresh_persistence(Fpga *fpga, uint32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU32(fpga->session, 0x18048, v));
	return fpga->status;
}

