#include "common.h"
#if !defined(SAVE_SD_ADA_H) && (defined(SAVE_PRED_FILE_NAME) || defined(SAVE_RAW_FILE_NAME) || defined(SAVE_PRES_FILE_NAME) || defined(SAVE_FEAT_FILE_NAME)) 
  #define SAVE_SD_ADA_H
  #include "Arduino.h"
  #include "time_ada.h"
  #include <SPI.h>
  #include <SD.h>

  /**
  * @brief  prepare the SD to be used. if DELET_OLD is defined (in the main.h) old files will be removed
  *         if went well set saveSD variabel to true to indicate that SD card is useable
  *
  * @return true if setup went well otherwise false
  */
  bool sd_setup();

  /**
  * @brief  prints the headers - first line - of the files to SD.
  *
  * @return 
  */
  bool save_head();

  /**
  * @brief float to string. replace "." with ",".
  *
  * @param f the floating point number to invert to string
  *
  * @return the String of the float number
  */
  String point_to_coma(float f);

  #ifdef SAVE_FEAT_FILE_NAME
    /**
    * @brief  prints out the latest featurs to SD.
    *         name of the file saved can be changed by changing the value of SAVE_FEAT_FILE_NAME in the main.h.
    *
    * @return 
    */
    bool save_feat();
  #endif

  #ifdef SAVE_PRED_FILE_NAME
    /**
    * @brief  predicts state out of the latest calculated features and prints out the results to SD
    *         name of the file saved can be changed by changing the value of SAVE_RAW_FILE_NAME in the main.h.
    *
    * @return 
    */
    bool save_pred();
  #endif

  #ifdef SAVE_RAW_FILE_NAME
    /**
    * @brief  prints the 3 accelerometer values to SD.
    *         name of the file saved can be changed by changing the value of SAVE_RAW_FILE_NAME in the main.h.
    *
    * @param ax acceleration value in x direction to be saved to the SD.
    * @param ay acceleration value in y direction to be saved to the SD.
    * @param az acceleration value in z direction to be saved to the SD.
    *
    * @return 
    */
    bool save_raw_data(float ax, float ay, float az);
  #endif

  #ifdef SAVE_PRES_FILE_NAME
    /**
    * @brief  prints the pressure sensor values to SD.
    *         name of the file saved can be changed by changing the value of SAVE_PRES_FILE_NAME in the main.h.
    *
    * @param p pressure value to be saved to SD.
    *
    * @return 
    */
    bool save_pres_data(float p);
  #endif

  #ifndef DELET_OLD
    /**
    * @brief gets the number to append on filename to not override existing files.
    *
    * @param f_name the filename to get the number to append to
    *
    * @return the number to append to filename
    */
    uint8_t check_exist(String f_name);
  #endif
#endif
