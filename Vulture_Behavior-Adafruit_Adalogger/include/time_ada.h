#ifndef TIME_ADA_H
  #define TIME_ADA_H
  #include "Arduino.h"
  #ifdef GET_TIME
    #include <TimeLib.h>
    
    /*
    * setup time
    * sync time with pc
    * Serial monitor must remain closed and arduino_serial.py should run pc with correct port and baudrate
    * arduino_serial.py sends corrent time (in s from epoch) over serial
    */
    void time_setup();
    
    /**
    * makes sure that number has to digit by adding a 0 if 1 digit
    * param:
    *   digits: the number to transfer to tow digit number
    * return:
    *   the number as a tow digit number as a String
    */
    String get_digit(uint8_t digits);
  #endif
    
    /**
    * returns time in formate dd.mm.yyyy->hh:mm:ss as a String
    * to print time along the data to Serial and SD card
    * if GET_TIME not defined, in main.h, then we dont want time. so give nothing back to avoid errors of not defined methods
    */
    String get_time();
#endif