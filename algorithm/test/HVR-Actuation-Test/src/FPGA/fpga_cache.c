#include "fpga_cache.h"

#include "NiFpga_test_hvr.h"
#include "NiFpga.h"

void default_fpga(Fpga *fpga) {
	fpga->status = NiFpga_Status_Success;
	fpga->bit_path = "./FPGA/" NiFpga_test_hvr_Bitfile;
	fpga->resource = "RIO0";
	fpga->signature = NiFpga_test_hvr_Signature;
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
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18016, &(fpga->cache.HVR_1)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1801A, &(fpga->cache.HVR_2)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1801E, &(fpga->cache.HVR_3)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x18022, &(fpga->cache.HVR_4)));
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

NiFpga_Status write_hvr_1(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18006, v));
	return fpga->status;
}

NiFpga_Status write_hvr_2(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1800A, v));
	return fpga->status;
}

NiFpga_Status write_hvr_3(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x1800E, v));
	return fpga->status;
}

NiFpga_Status write_hvr_4(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18012, v));
	return fpga->status;
}

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteBool(fpga->session, 0x18002, v));
	return fpga->status;
}

