#include "fpga_cache.h"

#include "NiFpga_test_brake_actuation.h"
#include "NiFpga.h"

void default_fpga(Fpga *fpga) {
	fpga->status = NiFpga_Status_Success;
	fpga->bit_path = "./FPGA/" "NiFpga_test_brake_actuation_Bitfile";
	fpga->resource = "RIO0";
	fpga->signature = "NiFpga_test_brake_actuation_Signature";
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
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1800A, &(fpga->cache.current_brake_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadBool(fpga->session, 0x1800E, &(fpga->cache.current_drain_valve_state)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18014, &(fpga->cache.fxp_pressure_14)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18018, &(fpga->cache.fxp_pressure_15)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1801C, &(fpga->cache.fxp_pressure_16)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18020, &(fpga->cache.fxp_pressure_17)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18024, &(fpga->cache.fxp_pressure_18)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18028, &(fpga->cache.fxp_pressure_19)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x1802C, &(fpga->cache.fxp_pressure_20)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18030, &(fpga->cache.fxp_pressure_21)));
	NiFpga_IfIsNotError(fpga->status, NiFpga_ReadI32(fpga->session, 0x18034, &(fpga->cache.fxp_pressure_22)));

	if(fpga->status != NiFpga_Status_Success) {
		printf("Failure to refresh FPGA\n");
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

NiFpga_Status write_set_brakes(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x18034, v));
	return fpga->status;
}

NiFpga_Status write_set_drain_valve(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x18034, v));
	return fpga->status;
}

NiFpga_Status write_stop(Fpga *fpga, NiFpga_Bool v) {
	NiFpga_IfIsNotError(fpga->status, NiFpga_WriteI32(fpga->session, 0x18034, v));
	return fpga->status;
}

