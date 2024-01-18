#ifndef IMU_ADA_H
  #define IMU_ADA_H
  #include "Arduino.h"
  #include "common.h"
  #include "print_ada.h"
  #include "save_sd_ada.h"
  #include "i2c_ada.h"          //for read write through I2C connection needed for accelerometer and pressure senor
  #include "calc.h"

  /**
  * @brief  setup the accelerometer sensor.
  *         seting up power mode and measurment range.
  *         to adjust look in main.h under //imu.
  *         if went well set imu variabel to true to know that sensor is useable
  *
  * @return true if setup went well otherwise false
  */
  bool imu_setup();

  /**
  * @brief  take numer of messurement from the accelerometer sensor.
  *         numer of messurments definded in NUM_SAMPLES in the main.h.
  *         delay between messurements (the rate) is defined in INTERVAL in the main.h.
  *         afterward calculate the features and save into the features array in main.h.
  *         using get_features() from calc.h.
  *
  * @return 
  */
  void recordIMU();

  /**
  * @brief calibarate readed values using calibration values defined in main.h.
  *
  * @param ax pointer to the measurment value in x direction to be calibrated.
  * @param ay pointer to the measurment value in y direction to be calibrated.
  * @param az pointer to the measurment value in z direction to be calibrated.
  *
  * @return 
  */
  void calibrate(float *ax, float *ay, float *az);
  
  /**
  * @brief read the measurements of the accelerometer sensor.
  *
  * @param ax pointer to the variable where the measurment value in x direction should be saved.
  * @param ay pointer to the variable where the measurment value in y direction should be saved.
  * @param az pointer to the variable where the measurment value in z direction should be saved.
  *
  * @return 
  */
  void imu_read(float *ax, float *ay, float *az);
#endif