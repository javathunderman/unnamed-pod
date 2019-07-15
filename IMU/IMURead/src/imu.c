#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

//#include "imu.h"

int open_port(void);

int main(){
  int i, n, fd, bytes_read;

  unsigned char buf[32];
  //IMUData data;

  //Opening a Serial Port
  fd = open_port();
  printf("Port File Descriptor: %d\n", fd);
  if (fd == -1) {
	  printf("Failed to open port");
	  return 0;
  }

  printf("Attempting to set baudrate...\n");
  //Setting baud rate...
  struct termios options;

  //Get the current options for the port...
  if (n = tcgetattr(fd, &options) == -1) {
	perror("tcgetattr failed");
	return 0;
  }

  //Set the baud rates to 19200...
  if (n = cfsetispeed(&options, B57600) == -1) {
	perror("cfsetispeed failed");
	return 0;
  }

  if (n = cfsetospeed(&options, B57600) == -1) {
	perror("cfsetispeed failed");
	return 0;
  }

  //Enable the receiver and set local mode...
  options.c_cflag |= (CLOCAL | CREAD);

  //Set the new options for the port...
  if (n = tcsetattr(fd, TCSANOW, &options) == -1) {
  	perror("tcsetattr failed");
  	return 0;
  }
  printf("Done setting baud rate\n");

  //Writing Data to the Port
  int ping = 0x0102;
  n = write(fd, &ping, 8);
  if (n < 0)
    fputs("ping: write() of 8 bytes failed!\n", stderr);
  else
	printf("ping: write() of %d bytes success!\n", n);


  printf("Attempting to read buffer...\n");
  int x = fcntl(fd, F_SETFL, FNDELAY);

  printf("Size of buf = %d\n", sizeof(buf));


  while(1) {
	//Reading Data from the Port
	  bytes_read = read(fd, &buf, sizeof(buf));
	  if (bytes_read > 0) {
	  	  printf("bytes_read=%d, buffer=[", bytes_read, buf);
	    for(i=0;i<bytes_read;i++)	 /*printing only the received characters*/
	    	printf("%x ",buf[i]);
	    printf("]\n[");
	    for(i=0;i<bytes_read;i++)	 /*printing only the received characters*/
	    	printf("%d ",buf[i]);
	    printf("]\n");
	  }


	/*//Table 4 https://www.memsense.com/assets/docs/uploads/ms-imu3020/MS-IMU3020_PSUG.pdf
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
	*/
  }
  close(fd);
}


/* 'open_port()' - Open serial port 1.
 * Returns the file descriptor on success or -1 on error.*/
int open_port(void) {
  int fd; /* File descriptor for the port */

  fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1) {
    //Could not open the port.
    perror("open_port: Unable to open /dev/ttyUSB0 - \n");
  }
  else {
    fcntl(fd, F_SETFL, 0);
    printf("opened port /dev/ttyUSB0 successfully\n");
  }

  return (fd);
}

