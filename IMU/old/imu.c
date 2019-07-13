
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


int main()
{
  int i, n,
      cport_nr=0,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=9600;       /* 9600 baud */

  unsigned char buf[33];
  IMUData data;

  char mode[]={'8','N','1',0};


  if(RS232_OpenComport(cport_nr, bdrate, mode, 0))
  {
    printf("Can not open comport\n");

    return(0);
  }

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

      printf("received %i bytes: %s\n", n, (char *)buf);
    }

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
	data.x_gyro = (buf[26]<<4) ^ buf[25];
	data.x_gyro = (buf[30]<<4) ^ buf[29];

#ifdef _WIN32
    Sleep(100);
#else
    usleep(100000);  /* sleep for 100 milliSeconds */
#endif
  }

  return(0);
}

