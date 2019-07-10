
/**************************************************

file: imu.c
purpose: simple demo that receives characters from
the serial port and print them on the screen,
exit the program by pressing Ctrl-C

compile with the command: gcc demo_rx.c rs232.c -Wall -Wextra -o2 -o test_rx

**************************************************/

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"
#include "imu.h"


int main(){
  int i, n,
      cport_nr=1,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=460800;       /* 9600 baud */

  unsigned char buf[33];
  IMUData data;

  char mode[]={'8','N','1',0};

  printf("Attempting to open com port cport=%d, bdrate=%d\n", cport_nr, bdrate);
  if(RS232_OpenComport(cport_nr, bdrate, mode, 0))
  {
    printf("Can not open comport\n");

    return(0);
  }
  printf("Successfully opened com port\n");
  while(1)
  {
    n = RS232_PollComport(cport_nr, buf, 32);

    if(n > 0)
    {
      buf[n] = 0;   /* always put a "null" at the end of a string! */

      for(i=0; i < n; i++)
      {
        if(buf[i] < 32)  /* replace unreadable control-codes by dots */
        {
          buf[i] = '.';
        }
      }

      printf("cleaned: received %i bytes: %s\n", n, (char *)buf);
    }
    printf("received %i bytes: %s\n", n, (char *)buf);
	//Table 4 https://www.memsense.com/assets/docs/uploads/ms-imu3020/MS-IMU3020_PSUG.pdf
	//data.sync1 = buff[0];
	//data.sync2 = buff[1];
	//data.message_type = buff[2];
	//data.payload_size = buff[3];

	//unsure how MSB and LSB are used here
	//data. = buff[];
	//data. = buff[];
	data.x_accel = (buf[8]<<4) ^ buf[7];
	data.y_accel = (buf[12]<<4) ^ buf[11];
	data.z_accel = (buf[16]<<4) ^ buf[15];

	//data. = buff[];
	//data. = buff[];
	data.x_gyro = (buf[22]<<4) ^ buf[21];
	data.y_gyro = (buf[26]<<4) ^ buf[25];
	data.z_gyro = (buf[30]<<4) ^ buf[29];
	printf("x_accel=%.3f, y_accel=%.3f, z_accel=%.3f, gyro=%.3f\n", data.x_accel, data.y_accel, data.z_accel, data.x_gyro);

#ifdef _WIN32
    Sleep(100);
#else
    usleep(100000);  /* sleep for 100 milliSeconds */
#endif
  }

  return(0);
}

