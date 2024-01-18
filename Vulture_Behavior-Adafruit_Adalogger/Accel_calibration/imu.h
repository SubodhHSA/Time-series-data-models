#ifndef IMU_H
  #define IMU_H

  void imu_read(float*, float*, float*);

  /**
  * take numer of messurement from the accelerometer sensor
  * numer of messurments definded in NUM_SAMPLES in the main.h
  * delay between messurements (the rate) is defined in INTERVAL in the main.h
  * afterward calculate the features and save into the features array in main.h
  */
  void recordIMU() {
    for (int8_t i = 0; i < NUM_SAMPLES; i++) {
        imu_read(&m[0][i], &m[1][i], &m[2][i]);

        delay(INTERVAL);
    }
  }

  /**
  * calibarate readed values and limit the field of values up to TRUNCATE_AT in mani.h
  * Offset and factor of the calibration are defined in main.h
  * param:
  *   ax, ay, az: pointers of the measurements to be calibrated
  */
  void calibrate(float *ax, float *ay, float *az){
    *ax = gain[0] * (*ax - offset[0]);
    *ay = gain[1] * (*ay - offset[1]);
    *az = gain[2] * (*az - offset[2]);
  }

  /**
  * write to a register on the accelerometer sensor
  * needed to setup the accelerometer sensor
  * param:
  *   add:    address of the regiter to write on
  *   value:  the value to be written
  */
  void write_register(uint8_t add, int8_t value){
      Wire.beginTransmission(MPU_ADDR);
      Wire.write(add);
      Wire.write(value);
      Wire.endTransmission(true);
  }

  /**
  * setup the accelerometer sensor
  * seting up power mode measurment range
  * for more information see PWR_MGMT_1_VALUE, PWR_MGMT_2_VALUE and AFS in main.h
  */
  void imu_setup() {
      Wire.begin();                                   //begin for I2C connection
      write_register(PWR_MGMT_1, PWR_MGMT_1_VALUE);   //
      write_register(PWR_MGMT_2, PWR_MGMT_2_VALUE);
      write_register(ACCEL_FS, AFS);
  }

  /**
  * read the measurements of the accelerometer sensor
  * param:
  *   ax, ay, az: pointers to the variables where the reading would be saved
  *   ax, ay, az: acceleration in the x, y and z direction 
  */
  void imu_read(float *ax, float *ay, float *az) {
      int16_t _ax, _ay, _az;
  
      Wire.beginTransmission(MPU_ADDR);
      Wire.write(ACCEL_XOUT);            // starting with ACCEL_XOUT_H
      Wire.endTransmission(false);     // keep connection activ
      Wire.requestFrom(MPU_ADDR, 3*2, true);
    
      // "Wire.read()<<8 | Wire. read ();" means two registers are read and stored in the same variable
      _ax = Wire.read() <<8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
      _ay = Wire.read() <<8 | Wire.read(); // reading registers: 0x3D (ACCEL YOUT_H) and 0x3E (ACCEL_YOUT_L)
      _az = Wire.read() <<8 | Wire.read(); // reading registers: 0x3F (ACCEL ZOUT_H) and 0x40 (ACCEL_ZOUT_L)

      Wire.endTransmission();
  
      *ax = float(_ax);
      *ay = float(_ay);
      *az = float(_az);

      calibrate(ax, ay, az);
  }
#endif
