#ifndef __IMU_H__
#define __IMU_H__
#include <time.h>
#include "rs232.h"


typedef struct {
	float x_accel;
	float y_accel;
	float z_accel;
	float pressure;
	struct timespec timestamp;
} ImuData;

#define CompTimespecMillis(t1, t2) ((t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_nsec - t1.tv_nsec) / 1000000.0)
#define timespectom(t) (t.tv_sec * 1000 + t.tv_nsec / 1000000.0)

//use 16 for ttyUSB0 or 0 for ttyS0, 230400 baudrate for now
// Call this once to setup imu connection
int imu_setup(int cport_nr, int bdrate);

// Returns the latest reading from IMU
ImuData imu_read(int cport_nr);

#endif
