#ifndef COMMON_H
  #define COMMON_H
  #include "Arduino.h"

  #define PRINT               //define to print result on Serial Monitor. uncomment define PRINT_RAW / PRINT_FEATURES / PRINT_PRED to print raw data / features / prediction
  #define SAVE_SD             //define to save results to SD card -> gonna save raw data and features with classification. if not both wanted SAVE_PRED_FILE_NAME or SAVE_RAW_FILE_NAME should be commented
  // #define GET_TIME            //define to print time along to information printed to consol and saved to SD Card. NEEDS THE TIME LIB!!! Time by Michael Margolis v 1.6.1
  // #define SYNC_PC_TIME        //define to syce PC time; Serial must remain closed and arduino_serial.py should run on PC with the correct Port and baudrate

  #define GPS_EN_PIN              12  //pin to turn on/off the GPS module. HIGH is on, LOW is off
  #define SIGNAL_PIN_ESP          6   //pin to send signal to esp32_cam to take a picture
  #define SIGNAL_PIN_MAX_NOALARM  10  //pin to receive signal from max when no Elephant/Rhino detected; no alarm
  #define SIGNAL_PIN_MAX_ALARM    9   //pin to receive signal from max when Elephant/Rhino detected; alarm
  #define SIGNAL_NOALARM          0   //idx of signal to send through mioty if no Elephant/Rhino detected; no alarm
  #define SIGNAL_ALARM            1   //idx of signal to send through mioty if Elephant/Rhino detected; alarm

  #define NUM_FEATURES 4      //number of features used
  #define NUM_SAMPLES 20      //number of samples/data measured befor calculation features and classifying. if changed WAKE_CTRL should be looked at
  #define LOOP_DELAY 100      //delay between single loops in ms

  //imu
  #define SLEEP_CYCLE         //define to make sensor swich between sleep and measuring and back in a defined frequency (in WAKE_CTRL)
  #define TEMP_DIS            //define to disable temperature measurement
  #define GYRO_DIS            //define to gyro measurement
  #define WAKE_CTRL   2       //wake up frequency; 0 -> 1.25Hz, 1 -> 5Hz, 2 -> 20Hz, 3 -> 40Hz
  #define FSR         0       //full scale range; 0 -> 2g, 1 -> 4g, 2 -> 8g, 3 -> 16g

  //imu calibration parameter to calibrate the data measured via accelerometer
  #define OFFSET_X  284.30 //53.25
  #define GAIN_X    1.0
  #define OFFSET_Y  -94.40 //-33.67
  #define GAIN_Y    1.0
  #define OFFSET_Z  2349.10 //247.77
  #define GAIN_Z    0.9710763394973921228

  //calculated features would be saved here
  extern float features[NUM_FEATURES];


  //GPS
  

  #if defined(PRINT) || defined(SAVE_SD)
    //features names for printing and saving onto the SD card
    const String feature_names[NUM_FEATURES] = {"sdocpz", "coryz", "sdx", "rangex"};
  #endif

  #ifdef SAVE_SD
    //SD card
    #define CS_PIN 4
    // #define DELET_OLD                         //if def old saved data would be removed
    #define SAVE_FEAT_FILE_NAME "feat.csv"      //if def features would be saved onto the SD card as the specified file name
    #define SAVE_PRED_FILE_NAME "pred.csv"      //if def prediction would be saved onto the SD card as the specified file name
    #define SAVE_RAW_FILE_NAME  "raw.csv"       //if def all raw accel. sensor data would be saved onto the SD card as the specified file name
    #define SAVE_PRES_FILE_NAME "pres.csv"      //if def all pressure sensor data would be saved onto the SD card as the specified file name
  #endif

  #ifdef PRINT
    //printing
    // #define PRINT_RAW           //define to print raw data
    // #define PRINT_G_VAL         //define to print G-Values of the data
    #define PRINT_FEAT          //define to print features
    #define PRINT_PRED          //define to print prediction
    #define DEBUG               //define to print debug info
  #endif
  #ifdef DEBUG
    #define print_debugln(msg) Serial.println(msg)
    #define print_debug(msg) Serial.print(msg)
  #else
    #define print_debugln(msg)
    #define print_debug(msg)
  #endif

  //svm model
  extern uint8_t classId;   //class index of the last predicted state. saved by predict in model.h
  extern float prob;        //probability of the last predicted state. saved by predict in model.h
  #if defined(PRINT_PRED) || defined(SAVE_PRED_FILE_NAME)
    extern String label;           //readable classname of the last predicted state. saved by predict in model.h
  #endif
  #define PROB_THRESH 0.70  //threshold of the prediction probability in decimal. if probability of prediction is lower than this threshold the prediction is getting discarded
  //prediction ids
  #define FLYING        0
  #define LOW_ACTIVITY  1
  #define FEEDING       2
  #define UNDEFINED     99
#endif