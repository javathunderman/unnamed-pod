#include "fpga_cache.h"

#include "NiFpga_main.h"
#include "NiFpga.h"


/* FXP Utilities */
#define TWO_TO_THE_16 65536

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
	/* Atomically store FIFO_timeout_analog */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x180DA, tempNiFpga_Bool))){
			STORE((fpga->cache.FIFO_timeout_analog), tempNiFpga_Bool);
		}
	}
	/* Atomically store FIFO_timeout_laser */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x180D6, tempNiFpga_Bool))){
			STORE((fpga->cache.FIFO_timeout_laser), tempNiFpga_Bool);
		}
	}
	/* Atomically store FIFO_timeout_retro */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x180D2, tempNiFpga_Bool))){
			STORE((fpga->cache.FIFO_timeout_retro), tempNiFpga_Bool);
		}
	}
	/* Atomically store HVR_1_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1808A, tempNiFpga_Bool))){
			STORE((fpga->cache.HVR_1_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store HVR_2_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1808E, tempNiFpga_Bool))){
			STORE((fpga->cache.HVR_2_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store HVR_3_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18092, tempNiFpga_Bool))){
			STORE((fpga->cache.HVR_3_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store HVR_4_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18096, tempNiFpga_Bool))){
			STORE((fpga->cache.HVR_4_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store avb_shutoff_p1_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x180A2, tempNiFpga_Bool))){
			STORE((fpga->cache.avb_shutoff_p1_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store avb_shutoff_p2_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x180A6, tempNiFpga_Bool))){
			STORE((fpga->cache.avb_shutoff_p2_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store avb_shutoff_r_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x180AA, tempNiFpga_Bool))){
			STORE((fpga->cache.avb_shutoff_r_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store brake_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18082, tempNiFpga_Bool))){
			STORE((fpga->cache.brake_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store drain_valve_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18086, tempNiFpga_Bool))){
			STORE((fpga->cache.drain_valve_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store enable_checks_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1815E, tempNiFpga_Bool))){
			STORE((fpga->cache.enable_checks_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store iso_led_1_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1809A, tempNiFpga_Bool))){
			STORE((fpga->cache.iso_led_1_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store iso_led_2_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1809E, tempNiFpga_Bool))){
			STORE((fpga->cache.iso_led_2_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store cur_thresh_index */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x18192, tempuint8_t))){
			STORE((fpga->cache.cur_thresh_index), tempuint8_t);
		}
	}
	/* Atomically store light_BL_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180E2, tempuint8_t))){
			STORE((fpga->cache.light_BL_count), tempuint8_t);
		}
	}
	/* Atomically store light_BR_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180E6, tempuint8_t))){
			STORE((fpga->cache.light_BR_count), tempuint8_t);
		}
	}
	/* Atomically store light_FL_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180DE, tempuint8_t))){
			STORE((fpga->cache.light_FL_count), tempuint8_t);
		}
	}
	/* Atomically store light_L_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180EA, tempuint8_t))){
			STORE((fpga->cache.light_L_count), tempuint8_t);
		}
	}
	/* Atomically store light_R_count */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x180EE, tempuint8_t))){
			STORE((fpga->cache.light_R_count), tempuint8_t);
		}
	}
	/* Atomically store light_sensor_status */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU8(fpga->session, 0x18162, tempuint8_t))){
			STORE((fpga->cache.light_sensor_status), tempuint8_t);
		}
	}
	/* Atomically store count_laser_l */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU16(fpga->session, 0x1802A, tempuint16_t))){
			STORE((fpga->cache.count_laser_l), tempuint16_t);
		}
	}
	/* Atomically store count_laser_r */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU16(fpga->session, 0x18026, tempuint16_t))){
			STORE((fpga->cache.count_laser_r), tempuint16_t);
		}
	}
	/* Atomically store count_light_bl */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU16(fpga->session, 0x18022, tempuint16_t))){
			STORE((fpga->cache.count_light_bl), tempuint16_t);
		}
	}
	/* Atomically store count_light_br */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU16(fpga->session, 0x1801E, tempuint16_t))){
			STORE((fpga->cache.count_light_br), tempuint16_t);
		}
	}
	/* Atomically store count_light_fl */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU16(fpga->session, 0x1801A, tempuint16_t))){
			STORE((fpga->cache.count_light_fl), tempuint16_t);
		}
	}
	/* Atomically store count_light_fr */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU16(fpga->session, 0x18016, tempuint16_t))){
			STORE((fpga->cache.count_light_fr), tempuint16_t);
		}
	}
	/* Atomically store P_hp1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18114, tempfxp32_16))){
			STORE((fpga->cache.P_hp1), tempfxp32_16);
		}
	}
	/* Atomically store P_hp2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18118, tempfxp32_16))){
			STORE((fpga->cache.P_hp2), tempfxp32_16);
		}
	}
	/* Atomically store P_lp1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1811C, tempfxp32_16))){
			STORE((fpga->cache.P_lp1), tempfxp32_16);
		}
	}
	/* Atomically store P_lp2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18120, tempfxp32_16))){
			STORE((fpga->cache.P_lp2), tempfxp32_16);
		}
	}
	/* Atomically store T_cRIO */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18108, tempfxp32_16))){
			STORE((fpga->cache.T_cRIO), tempfxp32_16);
		}
	}
	/* Atomically store T_extra1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1810C, tempfxp32_16))){
			STORE((fpga->cache.T_extra1), tempfxp32_16);
		}
	}
	/* Atomically store T_extra2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18110, tempfxp32_16))){
			STORE((fpga->cache.T_extra2), tempfxp32_16);
		}
	}
	/* Atomically store T_p1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180F4, tempfxp32_16))){
			STORE((fpga->cache.T_p1), tempfxp32_16);
		}
	}
	/* Atomically store T_p2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180F8, tempfxp32_16))){
			STORE((fpga->cache.T_p2), tempfxp32_16);
		}
	}
	/* Atomically store T_piston0 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18124, tempfxp32_16))){
			STORE((fpga->cache.T_piston0), tempfxp32_16);
		}
	}
	/* Atomically store T_piston1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18128, tempfxp32_16))){
			STORE((fpga->cache.T_piston1), tempfxp32_16);
		}
	}
	/* Atomically store T_piston2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1812C, tempfxp32_16))){
			STORE((fpga->cache.T_piston2), tempfxp32_16);
		}
	}
	/* Atomically store T_piston3 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18130, tempfxp32_16))){
			STORE((fpga->cache.T_piston3), tempfxp32_16);
		}
	}
	/* Atomically store T_piston4 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18134, tempfxp32_16))){
			STORE((fpga->cache.T_piston4), tempfxp32_16);
		}
	}
	/* Atomically store T_piston5 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18138, tempfxp32_16))){
			STORE((fpga->cache.T_piston5), tempfxp32_16);
		}
	}
	/* Atomically store T_piston6 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1813C, tempfxp32_16))){
			STORE((fpga->cache.T_piston6), tempfxp32_16);
		}
	}
	/* Atomically store T_piston7 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18140, tempfxp32_16))){
			STORE((fpga->cache.T_piston7), tempfxp32_16);
		}
	}
	/* Atomically store T_pneum */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18104, tempfxp32_16))){
			STORE((fpga->cache.T_pneum), tempfxp32_16);
		}
	}
	/* Atomically store T_pod */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18100, tempfxp32_16))){
			STORE((fpga->cache.T_pod), tempfxp32_16);
		}
	}
	/* Atomically store T_r */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180FC, tempfxp32_16))){
			STORE((fpga->cache.T_r), tempfxp32_16);
		}
	}
	/* Atomically store brake_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1814C, tempfxp32_16))){
			STORE((fpga->cache.brake_distance), tempfxp32_16);
		}
	}
	/* Atomically store brake_force */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18144, tempfxp32_16))){
			STORE((fpga->cache.brake_force), tempfxp32_16);
		}
	}
	/* Atomically store cur_thresh_max */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18184, tempfxp32_16))){
			STORE((fpga->cache.cur_thresh_max), tempfxp32_16);
		}
	}
	/* Atomically store cur_thresh_min */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18180, tempfxp32_16))){
			STORE((fpga->cache.cur_thresh_min), tempfxp32_16);
		}
	}
	/* Atomically store current_p1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18008, tempfxp32_16))){
			STORE((fpga->cache.current_p1), tempfxp32_16);
		}
	}
	/* Atomically store current_p2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1800C, tempfxp32_16))){
			STORE((fpga->cache.current_p2), tempfxp32_16);
		}
	}
	/* Atomically store current_r */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18010, tempfxp32_16))){
			STORE((fpga->cache.current_r), tempfxp32_16);
		}
	}
	/* Atomically store fusion_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1817C, tempfxp32_16))){
			STORE((fpga->cache.fusion_distance), tempfxp32_16);
		}
	}
	/* Atomically store imu_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18170, tempfxp32_16))){
			STORE((fpga->cache.imu_distance), tempfxp32_16);
		}
	}
	/* Atomically store mc_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18174, tempfxp32_16))){
			STORE((fpga->cache.mc_distance), tempfxp32_16);
		}
	}
	/* Atomically store tape_distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18148, tempfxp32_16))){
			STORE((fpga->cache.tape_distance), tempfxp32_16);
		}
	}
	/* Atomically store tape_velocity */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x180F0, tempfxp32_16))){
			STORE((fpga->cache.tape_velocity), tempfxp32_16);
		}
	}
	/* Atomically store voltage_p1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18074, tempfxp32_16))){
			STORE((fpga->cache.voltage_p1), tempfxp32_16);
		}
	}
	/* Atomically store voltage_p2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18078, tempfxp32_16))){
			STORE((fpga->cache.voltage_p2), tempfxp32_16);
		}
	}
	/* Atomically store voltage_r */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1807C, tempfxp32_16))){
			STORE((fpga->cache.voltage_r), tempfxp32_16);
		}
	}
	/* Atomically store cur_thresh_persistence */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU32(fpga->session, 0x1818C, tempuint32_t))){
			STORE((fpga->cache.cur_thresh_persistence), tempuint32_t);
		}
	}
	/* Atomically store cur_thresh_ratio */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU32(fpga->session, 0x18188, tempuint32_t))){
			STORE((fpga->cache.cur_thresh_ratio), tempuint32_t);
		}
	}
	/* Atomically store fault_long_0 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU64(fpga->session, 0x18064, tempuint64_t))){
			STORE((fpga->cache.fault_long_0), tempuint64_t);
		}
	}
	/* Atomically store fault_long_1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU64(fpga->session, 0x18068, tempuint64_t))){
			STORE((fpga->cache.fault_long_1), tempuint64_t);
		}
	}
	/* Atomically store fault_long_2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU64(fpga->session, 0x1806C, tempuint64_t))){
			STORE((fpga->cache.fault_long_2), tempuint64_t);
		}
	}
	/* Atomically store fault_long_3 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadU64(fpga->session, 0x18070, tempuint64_t))){
			STORE((fpga->cache.fault_long_3), tempuint64_t);
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

NiFpga_Status write_enable_checks(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1815A, v));
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

NiFpga_Status write_reset_tape_count(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18166, v));
	return fpga->status;
}

NiFpga_Status write_reset_tape_state(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1816A, v));
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

NiFpga_Status write_DAQ_timeout(Fpga *fpga, uint16_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU16(fpga->session, 0x18152, v));
	return fpga->status;
}

NiFpga_Status write_fxp_imu_acc(Fpga *fpga, int32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x1816C, v));
	return fpga->status;
}

NiFpga_Status write_fxp_mc_linear_v(Fpga *fpga, int32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x18178, v));
	return fpga->status;
}

NiFpga_Status write_fxp_thresh_new_max(Fpga *fpga, int32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x18044, v));
	return fpga->status;
}

NiFpga_Status write_fxp_thresh_new_min(Fpga *fpga, int32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x18040, v));
	return fpga->status;
}

NiFpga_Status write_FIFO_timeout(Fpga *fpga, uint32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteU32(fpga->session, 0x18154, v));
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

