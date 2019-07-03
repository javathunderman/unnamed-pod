
//Table 4 https://www.memsense.com/assets/docs/uploads/ms-imu3020/MS-IMU3020_PSUG.pdf
typedef struct {
	float sync1;
	float sync2;
	float message_type;
	float payload_size;
	float message_code_ac;
	float data_size_ac;
	float x_accel;
	float y_accel;
	float z_accel;
	float message_code_ar;
	float data_size_ar;
	float x_gyro;
	float y_gyro;
	float z_gyro;
	float checksum1;
	float checksum2;
} IMUData;