#include "time_ada.h"

#ifdef GET_TIME
  #include <TimeLib.h>
  
  #ifdef SYNC_PC_TIME
    #define DEFAULT_TIME 1640995200 //Jan 1 2022

    void time_setup()  {
      unsigned long pctime;
      print_debugln("Waiting for sync message\nSerial monitor must remain closed and arduino_serial.py should run pc with correct port and baudrate!");
      while(timeStatus()== timeNotSet && !Serial.available())delay(1000);
      pctime = atol(Serial.readString().c_str());
      if(pctime >= DEFAULT_TIME) {                  // check the integer is a valid time (greater than Jan 1 2013)
        setTime(pctime);                             // Sync Arduino clock to the time received on the serial port
      }
    }
  #endif

  String get_digit(uint8_t digits){
    return digits < 10 ? "0" + String(digits) : String(digits);
  }

  String get_time(){
    return get_digit(day()) + "." + get_digit(month()) + "." + String(year()) + "->" + get_digit(hour()) + ":" + get_digit(minute()) + ":" + get_digit(second());
  }
#else
  String get_time(){return "";}   //if GET_TIME not defined, in main.h, then we dont want time. so give nothing back to avoid errors of not defined methods
#endif