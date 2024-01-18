#pragma once

#define NUM_SAMPLES 20    //number of samples/data measured for each calibration step
#define INTERVAL 50       //Intervals between sampels in ms. if changed, adjusting PWR_MGMT_2_VALUE should be considered
#define NUM_FEATURES 4    //number of features used
#define LOOP_DELAY 100    //delay betwenn calibrating different axes and between measurements by testing
#define EMPTY_LINES 20    //empty lines added instead of clearing the Terminal(not possible to clear).

//accelerometer constans needed in imu.h
#define MPU_ADDR 0x68                 //address of the MPU chip of the accel. to establish connection
#define PWR_MGMT_1 0x6B               //address of the first power management register to adjust power state to the value below
#define PWR_MGMT_1_VALUE 0b00001000   //SLEEP (bit 6) to 0 to wake up TEMP_DIS (bit 3) to 1 disable Temperature measurement
#define PWR_MGMT_2 0x6C               //address of the second power management register to adjust power state to the value below
#define PWR_MGMT_2_VALUE 0b00000111   //STBY_XG, _YG and _ZG (bit 2, 1 and 0) to 1 to set gyro sensor to standby)
#define ACCEL_FS 0x1C                 //address of the Configuration register to select the accelerometer full scale (AFS_SEL) to the value below
#define FSR         0                 //full scale range; 0 -> 2g, 1 -> 4g, 2 -> 8g, 3 -> 16g
#define AFS (FSR<<3)                  // bit 3 and 4 -> 3 ==> 16g
#define ACCEL_XOUT 0x3B               //address of the first register containing the measured data(first byte of x-accel.). the remain registers follow this rigister

//messurments
float m[3][NUM_SAMPLES];
char axes[] = {'x', 'y', 'z'};

//calibration parameter to calibrate the data measured
float offset[3];
float gain[3];


//SD card
#define CS_PIN 4
bool saveSD = false;

#include "print.h"    //includes functions to print data out onto Serial
#include <SPI.h>      //needed in saveSD.h
#include <SD.h>       //needed in saveSD.h
#include "saveSD.h"   //includes functions to save data out onto SD card
#include "Wire.h"     //for I2C connection needed in imu.h
#include "imu.h"      //includes functions for setting the accelerometer up and reading measurements of it#
