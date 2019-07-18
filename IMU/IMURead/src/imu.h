#include "rs232.h"

typedef struct {
	float x_accel;
	float y_accel;
	float z_accel;
	float pressure;
} IMUData;

//use 16 for ttyUSB0 or 0 for ttyS0, 230400 baudrate for now
// Call this once to setup imu connection
int imu_setup(int cport_nr, int bdrate);

// Returns the latest reading from IMU
IMUData imu_read(int cport_nr);
