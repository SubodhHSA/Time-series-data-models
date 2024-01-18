/*
* continues sernsor measuring and prediction of state using
* the SVM ML algorithm on the adafruit feather M0 (adalogger)
* and saving to sd card
* posible configuration of code could be done in common.h
*/
#include <Arduino.h>
#include "common.h"
#include "time_ada.h"               //for time matters
#include "print_ada.h"              //includes functions to print data out onto Serial
#include "save_sd_ada.h"            //includes functions to save data out onto SD card
#include "calc.h"                   //includes the necessary functions to for calculations (features calculation)
#include "imu_ada.h"                //includes functions for setting the accelerometer up and reading measurements out of it
#include "mioty.h"
#include "model_ada.h"              //machine learning algorithm

void setup();

/*
* interrrupt regarding no Elephant/Rhyno detection; no alarm
* resived from max after prediction
*/
void ISR_NOALARM();
/*
* interrrupt regarding Elephant/Rhyno detection; alarm
* resived from max after prediction
*/
void ISR_ALARM();

/*
* activate interrrupts to recive signals regarding detection
* resived from max after prediction
*/
void activate_int();

/*
* deactivate interrrupts to recive signals regarding detection
* after resiving signal from max after prediction
*/
void deactivate_int();

/*
* activate interrrupts to recive signals regarding detection
* waits for signals from max after prediction
* deativates interrupts afterwards
*/
void wait_for_max();

void loop();