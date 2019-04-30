/*
 ============================================================================
 Name        : fxp.c
 Author      : Mark Thiergartner
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Simple module for FXP manipulation
 ============================================================================
 */

typedef struct{
	long word; // Total word length
	unsigned short intw_l; // Integer word length
} fxp32;

int ltofxp32(fxp32 * fxp,long bytes, unsigned short iwl);
