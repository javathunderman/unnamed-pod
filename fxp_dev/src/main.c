/*
 ============================================================================
 Name        : TestProject3.c
 Author      : Jerry Qian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "fxp.h"

/*
 * Simple test to verify FXP operations
 */
int main(void) {
	double a = 2.2;
	double b = 3.6;

	fxp32_16 sum = dtofxp(a) + dtofxp(b);
	fxp32_16 diff = dtofxp(a) - dtofxp(b);
	fxp32_16 prod = dtofxp(a) * dtofxp(b);
	fxp32_16 div = dtofxp(a) / dtofxp(b);

	printf("Test: %f %s %f = %f, expected = %f\n", a, "+", b, fxptod(sum), a+b);
	printf("Test: %f %s %f = %f, expected = %f\n", a, "-", b, fxptod(diff), a-b);
	printf("Test: %f %s %f = %f, expected = %f\n", a, "*", b, fxptod(prod), a*b);
	printf("Test: %f %s %f = %f, expected = %f\n", a, "/", b, fxptod(div), a/b);

	exit(0);
}
