/*
 ============================================================================
 Name        : fxp.c
 Author      : Mark Thiergartner
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Simple module for FXP manipulation
 ============================================================================
 */
#include<stdint.h>

/*
 * Addition and subtraction work, to make multiplication and division work,
 * methods need to be written.
 */
typedef int32_t fxp32_16;

fxp32_16 ftofxp(float d);
fxp32_16 dtofxp(double d);
float fxptof(fxp32_16 fxp);
double fxptod(fxp32_16 fxp);


