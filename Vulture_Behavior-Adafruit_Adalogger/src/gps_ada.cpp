#include "Arduino.h"
#include <Adafruit_GPS.h>
#include "common.h"

#define GPSSerial Serial1

Adafruit_GPS GPS(&GPSSerial);

#define GPSECHO false                                   // Set to 'true' if you want to debug and listen to the raw GPS sentences

void gps_setup(){
    GPS.begin(76800);

    GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);          // 1 Hz update rate
}

void get_location(int32_t *latitude, int32_t *longitude) {
    digitalWrite(GPS_EN_PIN, HIGH);
    gps_setup();
    while(!GPS.fix);
    *latitude = (int)(GPS.latitude*100000);
    if(GPS.lat == 'S'){
        *latitude *= -1;
    }
    *longitude = (int)(GPS.longitude*100000);
    if(GPS.lon == 'W'){
        *longitude *= -1;
    }
    digitalWrite(GPS_EN_PIN, LOW);
}

String get_digit(uint8_t digits){
    return digits < 10 ? "0" + String(digits) : String(digits);
}

String get_time(){
    gps_setup();
    while(!GPS.fix);
    String output =  get_digit(GPS.day) + "." + get_digit(GPS.month) + "." + String(GPS.year) + "->" + get_digit(GPS.hour) + ":" + get_digit(GPS.minute) + ":" + get_digit(GPS.seconds);
    digitalWrite(GPS_EN_PIN, LOW);
    return output;
}