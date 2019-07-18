
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

#include <stdint.h>
#include <limits.h> /* for CHAR_BIT */

#include "imu.h"

void show_ieee754 (float f)
{
    union {
        float f;
        uint32_t u;
    } fu = { .f = f };
    int i = sizeof f * CHAR_BIT;

    printf ("  ");
    while (i--)
        printf ("%d ", (fu.u >> i) & 0x1);

    putchar ('\n');
    printf (" |s|      exp      |                  mantissa"
            "                   |\n\n");
}

char *int2bin(int n) {
    // determine the number of bits needed ("sizeof" returns bytes)
    int nbits = sizeof(n) * 8;
    char *s = malloc(nbits+1);  // +1 for '\0' terminator
    s[nbits] = '\0';
    // forcing evaluation as an unsigned value prevents complications
    // with negative numbers at the left-most bit
    unsigned int u = *(unsigned int*)&n;
    int i;
    unsigned int mask = 1 << (nbits-1); // fill in values right-to-left
    for (i = 0; i < nbits; i++, mask >>= 1)
        s[i] = ((u & mask) != 0) + '0';
    return s;
}


int main(){
  int i, n,
      cport_nr=16,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=230400;       /* 9600 baud */

  unsigned char buf[34];
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
    n = RS232_PollComport(cport_nr, buf, 34);

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

    }

    if (n > 0) {
    	/*printf("bytes_read=%d, buffer=[", n);
		for(i=0;i<n;i++)
			printf("%02x ",buf[i]);
		printf("]\n");*/
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
#ifdef _WIN32
    Sleep(1.25);
#else
    usleep(1250);  /* sleep for 100 milliSeconds 100000*/
#endif
  }

  return(0);
}

