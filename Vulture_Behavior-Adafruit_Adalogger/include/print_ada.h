#include "common.h"
#if !defined(PRINT_ADA_H) && defined(PRINT)
  #define PRINT_ADA_H
  #include "Arduino.h"
  #include "time_ada.h"
  
  #ifdef PRINT_PRES
    /**
    * @brief prints the pressure sensor values to serial.
    *
    * @param p pressure value to be printed.
    *
    * @return 
    */
    void print_pres_data(float p);
  #endif
  
  #ifdef PRINT_RAW
    /**
    * @brief prints the 3 accelerometer values to serial.
    *
    * @param ax acceleration value in x direction to be printed.
    * @param ay acceleration value in y direction to be printed.
    * @param az acceleration value in z direction to be printed.
    *
    * @return 
    */
    void printData(float ax, float ay, float az);
  #endif
  
  #ifdef PRINT_FEAT
    /**
    * @brief prints the latest calculated featurs.
    *
    * @return 
    */
    void print_feat();
  #endif
  
  #ifdef PRINT_PRED
    /**
    * @brief print results of last prediction.
    *
    * @return 
    */
    void print_pred();
  #endif
#endif