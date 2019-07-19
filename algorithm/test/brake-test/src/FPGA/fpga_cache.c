#include "fpga_cache.h"

#include "NiFpga_brake_test.h"


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
	fpga->bit_path = "/home/admin/ProjectFolder/FPGA/" NiFpga_brake_test_Bitfile;
	fpga->resource = "RIO0";
	fpga->signature = NiFpga_brake_test_Signature;
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
	/* Atomically store FIFO_timeout */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x18002, &tempNiFpga_Bool))){
			STORE((fpga->cache.FIFO_timeout), tempNiFpga_Bool);
		}
	}
	/* Atomically store brake_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1800A, &tempNiFpga_Bool))){
			STORE((fpga->cache.brake_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store drain_valve_state */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadBool(fpga->session, 0x1800E, &tempNiFpga_Bool))){
			STORE((fpga->cache.drain_valve_state), tempNiFpga_Bool);
		}
	}
	/* Atomically store P_hp1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18010, &tempfxp32_16))){
			STORE((fpga->cache.P_hp1), tempfxp32_16);
		}
	}
	/* Atomically store P_hp2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18014, &tempfxp32_16))){
			STORE((fpga->cache.P_hp2), tempfxp32_16);
		}
	}
	/* Atomically store P_lp1 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18018, &tempfxp32_16))){
			STORE((fpga->cache.P_lp1), tempfxp32_16);
		}
	}
	/* Atomically store P_lp2 */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x1801C, &tempfxp32_16))){
			STORE((fpga->cache.P_lp2), tempfxp32_16);
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

NiFpga_Status write_brake_1(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18022, v));
	return fpga->status;
}

NiFpga_Status write_brake_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18026, v));
	return fpga->status;
}

NiFpga_Status write_drain(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1802A, v));
	return fpga->status;
}

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18006, v));
	return fpga->status;
}

