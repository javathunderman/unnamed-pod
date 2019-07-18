#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "imu.h"

//use 16 for ttyUSB0 or 0 for ttyS0, 230400 baudrate for now
int imu_setup(int cport_nr, int bdrate) {
	char mode[]={'8','N','1',0};

	printf("Attempting to open com port cport=%d, bdrate=%d\n", cport_nr, bdrate);
	if(RS232_OpenComport(cport_nr, bdrate, mode, 0)) {
		printf("Can not open comport\n");
		return(0);
	}
	printf("Successfully opened com port\n");

	return 0;
}

IMUData imu_read(int cport_nr) {
	int i, n;
	unsigned char buf[34];
	IMUData data;

	n = RS232_PollComport(cport_nr, buf, 34);

	if(n > 0) {
	  buf[n] = 0;   /* always put a "null" at the end of a string! */

	  for(i=0; i < n; i++) {
		if(buf[i] < 32) {  /* replace unreadable control-codes by dots */
		  buf[i] = '.';
		}
	  }
	}

	if (n > 0) {
		unsigned char bx[] = {buf[9], buf[8], buf[7], buf[6]};
		unsigned char by[] = {buf[13], buf[12], buf[11], buf[10]};
		unsigned char bz[] = {buf[17], buf[16], buf[15], buf[14]};
		unsigned char bp[] = {buf[23], buf[22], buf[21], buf[20]};
		memcpy(&data.x_accel, &bx, sizeof(float));
		memcpy(&data.y_accel, &by, sizeof(float));
		memcpy(&data.z_accel, &bz, sizeof(float));
		memcpy(&data.pressure, &bp, sizeof(float));

		printf("x_accel=%.5f, y_accel=%.5f, z_accel=%.5f, pressure=%.5f\n",
				data.x_accel, data.y_accel, data.z_accel, data.pressure);
	}

	return data;
}

