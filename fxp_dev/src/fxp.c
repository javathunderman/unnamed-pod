#include "fxp.h"
#include <math.h>


/*
 * Reinterpret long int as FXP32
 */
int ltofxp32(fxp32 * fxp ,long bytes, unsigned short iwl) {
	if(iwl > 32){
		return 1;
	}
	fxp->word = bytes;
	fxp->intw_l = iwl;

	return 0;
}

double fxp32tod(fxp32 fxp){
	return 0;
}

