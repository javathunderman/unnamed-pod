#include "fpga_cache.h"

#include "NiFpga_main.h"
#include "atomics.h"


/* FXP Utilities */
#define TWO_TO_THE_16 65536
#define TWO_TO_THE_32 4294967296L

fxp32_16 ftofxp(float f) {
	return (fxp32_16)(TWO_TO_THE_16 * f);
}

fxp32_16 dtofxp(double d) {
	return (fxp32_16)(TWO_TO_THE_16 * d);
}

float fxptof(fxp32_16 fxp) {
	return ((float)fxp)/TWO_TO_THE_16;
}

double fxptod(fxp32_16 fxp) {
	return ((double)fxp)/TWO_TO_THE_16;
}

fxp64_32 ftofxpe(float f) {
	return (fxp64_32)(TWO_TO_THE_32 * f);
}

fxp64_32 dtofxpe(double d) {
	return (fxp64_32)(TWO_TO_THE_32 * d);
}

float fxpetof(fxp64_32 fxpe) {
	return ((float)fxpe)/TWO_TO_THE_32;
}

double fxpetod(fxp64_32 fxpe) {
	return ((double)fxpe)/TWO_TO_THE_32;
}
void default_fpga(Fpga *fpga) {
	fpga->status = NiFpga_Status_Success;
	fpga->bit_path = "/home/admin/ProjectFolder/FPGA/" NiFpga_main_Bitfile;
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
	NiFpga_Bool tempNiFpga_Bool;
	int8_t tempint8_t;
	uint8_t tempuint8_t;
	int16_t tempint16_t;
	uint16_t tempuint16_t;
	int32_t tempint32_t;
	uint32_t tempuint32_t;
	int64_t tempint64_t;
	uint64_t tempuint64_t;
	float tempfloat;
	double tempdouble;
	fxp32_16 tempfxp32_16;
	fxp64_32 tempfxp64_32;
	/* Atomically store HVR_1_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18066, &tempNiFpga_Bool))){
			STORE((fpga->cache.HVR_1_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store HVR_2_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1806A, &tempNiFpga_Bool))){
			STORE((fpga->cache.HVR_2_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store HVR_3_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1806E, &tempNiFpga_Bool))){
			STORE((fpga->cache.HVR_3_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store HVR_4_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18072, &tempNiFpga_Bool))){
			STORE((fpga->cache.HVR_4_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store avb_shutoff_p1_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1807E, &tempNiFpga_Bool))){
			STORE((fpga->cache.avb_shutoff_p1_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store avb_shutoff_p2_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18082, &tempNiFpga_Bool))){
			STORE((fpga->cache.avb_shutoff_p2_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store avb_shutoff_r_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18086, &tempNiFpga_Bool))){
			STORE((fpga->cache.avb_shutoff_r_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store brake_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1805E, &tempNiFpga_Bool))){
			STORE((fpga->cache.brake_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store drain_valve_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18062, &tempNiFpga_Bool))){
			STORE((fpga->cache.drain_valve_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store enable_checks_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x180E6, &tempNiFpga_Bool))){
			STORE((fpga->cache.enable_checks_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store frg_run_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18116, &tempNiFpga_Bool))){
			STORE((fpga->cache.frg_run_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store fuse_avb_p1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1811A, &tempNiFpga_Bool))){
			STORE((fpga->cache.fuse_avb_p1), tempNiFpga_Bool);
		}
	}
	/* Atomically store fuse_avb_p2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1811E, &tempNiFpga_Bool))){
			STORE((fpga->cache.fuse_avb_p2), tempNiFpga_Bool);
		}
	}
	/* Atomically store iso_led_1_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18076, &tempNiFpga_Bool))){
			STORE((fpga->cache.iso_led_1_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store iso_led_2_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1807A, &tempNiFpga_Bool))){
			STORE((fpga->cache.iso_led_2_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store cur_thresh_index */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x1810E, &tempuint8_t))){
			STORE((fpga->cache.cur_thresh_index), tempuint8_t);
		}
	}
	/* Atomically store light_BL_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180B2, &tempuint8_t))){
			STORE((fpga->cache.light_BL_count), tempuint8_t);
		}
	}
	/* Atomically store light_BR_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180B6, &tempuint8_t))){
			STORE((fpga->cache.light_BR_count), tempuint8_t);
		}
	}
	/* Atomically store light_FL_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180AE, &tempuint8_t))){
			STORE((fpga->cache.light_FL_count), tempuint8_t);
		}
	}
	/* Atomically store light_L_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180BA, &tempuint8_t))){
			STORE((fpga->cache.light_L_count), tempuint8_t);
		}
	}
	/* Atomically store light_R_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180BE, &tempuint8_t))){
			STORE((fpga->cache.light_R_count), tempuint8_t);
		}
	}
	/* Atomically store light_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x1815E, &tempuint8_t))){
			STORE((fpga->cache.light_count), tempuint8_t);
		}
	}
	/* Atomically store light_sensor_status */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180EA, &tempuint8_t))){
			STORE((fpga->cache.light_sensor_status), tempuint8_t);
		}
	}
	/* Atomically store P_hp1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180C8, &tempfxp32_16))){
			STORE((fpga->cache.P_hp1), tempfxp32_16);
		}
	}
	/* Atomically store P_hp2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180CC, &tempfxp32_16))){
			STORE((fpga->cache.P_hp2), tempfxp32_16);
		}
	}
	/* Atomically store P_lp1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180D0, &tempfxp32_16))){
			STORE((fpga->cache.P_lp1), tempfxp32_16);
		}
	}
	/* Atomically store P_lp2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180D4, &tempfxp32_16))){
			STORE((fpga->cache.P_lp2), tempfxp32_16);
		}
	}
	/* Atomically store T_avb_p1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18140, &tempfxp32_16))){
			STORE((fpga->cache.T_avb_p1), tempfxp32_16);
		}
	}
	/* Atomically store T_avb_p2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18144, &tempfxp32_16))){
			STORE((fpga->cache.T_avb_p2), tempfxp32_16);
		}
	}
	/* Atomically store T_avb_r */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18148, &tempfxp32_16))){
			STORE((fpga->cache.T_avb_r), tempfxp32_16);
		}
	}
	/* Atomically store T_cRIO */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180C4, &tempfxp32_16))){
			STORE((fpga->cache.T_cRIO), tempfxp32_16);
		}
	}
	/* Atomically store T_extra1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18154, &tempfxp32_16))){
			STORE((fpga->cache.T_extra1), tempfxp32_16);
		}
	}
	/* Atomically store T_extra2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18158, &tempfxp32_16))){
			STORE((fpga->cache.T_extra2), tempfxp32_16);
		}
	}
	/* Atomically store T_piston0 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18120, &tempfxp32_16))){
			STORE((fpga->cache.T_piston0), tempfxp32_16);
		}
	}
	/* Atomically store T_piston1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18124, &tempfxp32_16))){
			STORE((fpga->cache.T_piston1), tempfxp32_16);
		}
	}
	/* Atomically store T_piston2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18128, &tempfxp32_16))){
			STORE((fpga->cache.T_piston2), tempfxp32_16);
		}
	}
	/* Atomically store T_piston3 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1812C, &tempfxp32_16))){
			STORE((fpga->cache.T_piston3), tempfxp32_16);
		}
	}
	/* Atomically store T_piston4 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18130, &tempfxp32_16))){
			STORE((fpga->cache.T_piston4), tempfxp32_16);
		}
	}
	/* Atomically store T_piston5 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18134, &tempfxp32_16))){
			STORE((fpga->cache.T_piston5), tempfxp32_16);
		}
	}
	/* Atomically store T_piston6 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18138, &tempfxp32_16))){
			STORE((fpga->cache.T_piston6), tempfxp32_16);
		}
	}
	/* Atomically store T_piston7 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1813C, &tempfxp32_16))){
			STORE((fpga->cache.T_piston7), tempfxp32_16);
		}
	}
	/* Atomically store T_pneum */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18150, &tempfxp32_16))){
			STORE((fpga->cache.T_pneum), tempfxp32_16);
		}
	}
	/* Atomically store T_pod */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1814C, &tempfxp32_16))){
			STORE((fpga->cache.T_pod), tempfxp32_16);
		}
	}
	/* Atomically store brake_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180DC, &tempfxp32_16))){
			STORE((fpga->cache.brake_distance), tempfxp32_16);
		}
	}
	/* Atomically store cur_thresh_max */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18100, &tempfxp32_16))){
			STORE((fpga->cache.cur_thresh_max), tempfxp32_16);
		}
	}
	/* Atomically store cur_thresh_min */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180FC, &tempfxp32_16))){
			STORE((fpga->cache.cur_thresh_min), tempfxp32_16);
		}
	}
	/* Atomically store current_p1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18008, &tempfxp32_16))){
			STORE((fpga->cache.current_p1), tempfxp32_16);
		}
	}
	/* Atomically store current_p2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1800C, &tempfxp32_16))){
			STORE((fpga->cache.current_p2), tempfxp32_16);
		}
	}
	/* Atomically store current_r */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18010, &tempfxp32_16))){
			STORE((fpga->cache.current_r), tempfxp32_16);
		}
	}
	/* Atomically store fusion_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180F8, &tempfxp32_16))){
			STORE((fpga->cache.fusion_distance), tempfxp32_16);
		}
	}
	/* Atomically store imu_velocity */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18164, &tempfxp32_16))){
			STORE((fpga->cache.imu_velocity), tempfxp32_16);
		}
	}
	/* Atomically store mc_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180F0, &tempfxp32_16))){
			STORE((fpga->cache.mc_distance), tempfxp32_16);
		}
	}
	/* Atomically store tape_velocity */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180C0, &tempfxp32_16))){
			STORE((fpga->cache.tape_velocity), tempfxp32_16);
		}
	}
	/* Atomically store voltage_p1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18050, &tempfxp32_16))){
			STORE((fpga->cache.voltage_p1), tempfxp32_16);
		}
	}
	/* Atomically store voltage_p2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18054, &tempfxp32_16))){
			STORE((fpga->cache.voltage_p2), tempfxp32_16);
		}
	}
	/* Atomically store voltage_r */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18058, &tempfxp32_16))){
			STORE((fpga->cache.voltage_r), tempfxp32_16);
		}
	}
	/* Atomically store tape_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180D8, &tempint32_t))){
			STORE((fpga->cache.tape_distance), tempint32_t);
		}
	}
	/* Atomically store cur_thresh_persistence */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU32(fpga->session, 0x18108, &tempuint32_t))){
			STORE((fpga->cache.cur_thresh_persistence), tempuint32_t);
		}
	}
	/* Atomically store cur_thresh_ratio */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU32(fpga->session, 0x18104, &tempuint32_t))){
			STORE((fpga->cache.cur_thresh_ratio), tempuint32_t);
		}
	}
	/* Atomically store imu_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI64(fpga->session, 0x18160, &tempfxp64_32))){
			STORE((fpga->cache.imu_distance), tempfxp64_32);
		}
	}
	/* Atomically store fault_long_2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU64(fpga->session, 0x18048, &tempuint64_t))){
			STORE((fpga->cache.fault_long_2), tempuint64_t);
		}
	}
	/* Atomically store fault_long_3 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU64(fpga->session, 0x1804C, &tempuint64_t))){
			STORE((fpga->cache.fault_long_3), tempuint64_t);
		}
	}
	/* Atomically store hard_fault */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU64(fpga->session, 0x18040, &tempuint64_t))){
			STORE((fpga->cache.hard_fault), tempuint64_t);
		}
	}
	/* Atomically store soft_fault */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU64(fpga->session, 0x18044, &tempuint64_t))){
			STORE((fpga->cache.soft_fault), tempuint64_t);
		}
	}
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
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18092, v));
	return fpga->status;
}

NiFpga_Status write_avb_shutoff_prim_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18096, v));
	return fpga->status;
}

NiFpga_Status write_avb_shutoff_res(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1809A, v));
	return fpga->status;
}

NiFpga_Status write_enable_checks(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180E2, v));
	return fpga->status;
}

NiFpga_Status write_frg_run(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18112, v));
	return fpga->status;
}

NiFpga_Status write_hvr_1(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1809E, v));
	return fpga->status;
}

NiFpga_Status write_hvr_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180A2, v));
	return fpga->status;
}

NiFpga_Status write_hvr_3(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180A6, v));
	return fpga->status;
}

NiFpga_Status write_hvr_4(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180AA, v));
	return fpga->status;
}

NiFpga_Status write_iso_led_1(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1808A, v));
	return fpga->status;
}

NiFpga_Status write_iso_led_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1808E, v));
	return fpga->status;
}

NiFpga_Status write_reset_tape_count(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18172, v));
	return fpga->status;
}

NiFpga_Status write_reset_tape_status(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x180EE, v));
	return fpga->status;
}

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18016, v));
	return fpga->status;
}

NiFpga_Status write_thresh_latch_new(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1802E, v));
	return fpga->status;
}

NiFpga_Status write_thresh_reset(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18036, v));
	return fpga->status;
}

NiFpga_Status write_thresh_read_index(Fpga *fpga, uint8_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU8(fpga->session, 0x1803A, v));
	return fpga->status;
}

NiFpga_Status write_thresh_reset_index(Fpga *fpga, uint8_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU8(fpga->session, 0x18032, v));
	return fpga->status;
}

NiFpga_Status write_thresh_write_index(Fpga *fpga, uint8_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU8(fpga->session, 0x1801A, v));
	return fpga->status;
}

NiFpga_Status write_imu_acc(Fpga *fpga, fxp32_16 v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x18168, v));
	return fpga->status;
}

NiFpga_Status write_mc_velocity(Fpga *fpga, fxp32_16 v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x180F4, v));
	return fpga->status;
}

NiFpga_Status write_thresh_new_max(Fpga *fpga, fxp32_16 v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x18020, v));
	return fpga->status;
}

NiFpga_Status write_thresh_new_min(Fpga *fpga, fxp32_16 v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x1801C, v));
	return fpga->status;
}

NiFpga_Status write_thresh_f_ratio(Fpga *fpga, uint32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU32(fpga->session, 0x18028, v));
	return fpga->status;
}

NiFpga_Status write_thresh_persistence(Fpga *fpga, uint32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU32(fpga->session, 0x18024, v));
	return fpga->status;
}

NiFpga_Status write_imu_timestamp(Fpga *fpga, fxp64_32 v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI64(fpga->session, 0x1816C, v));
	return fpga->status;
}

