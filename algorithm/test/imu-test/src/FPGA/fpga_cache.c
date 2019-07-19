#include "fpga_cache.h"

#include "NiFpga_imu_test.h"


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
	fpga->bit_path = "/home/admin/ProjectFolder/FPGA/" NiFpga_imu_test_Bitfile;
	fpga->resource = "RIO0";
	fpga->signature = NiFpga_imu_test_Signature;
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
	/* Atomically store velocity */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI32(fpga->session, 0x18008, &tempint32_t))){
			STORE((fpga->cache.velocity), tempint32_t);
		}
	}
	/* Atomically store distance */
	if(NiFpga_IsNotError(fpga->status)){
		if(NiFpga_MergeStatus(&(fpga->status),  NiFpga_ReadI64(fpga->session, 0x1800C, &tempint64_t))){
			STORE((fpga->cache.distance), tempint64_t);
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

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18012, v));
	return fpga->status;
}

NiFpga_Status write_imu_acc(Fpga *fpga, int32_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x18000, v));
	return fpga->status;
}

NiFpga_Status write_timestamp(Fpga *fpga, int64_t v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI64(fpga->session, 0x18004, v));
	return fpga->status;
}

