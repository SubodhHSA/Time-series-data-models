/*
* continues sensor measuring and prediction of state using
* the SVM ML algorithm on the adafruit feather M0 (adalogger)
* and saving to sd card
* possible configuration of code could be done in common.h
*/
#include "main.h"

int8_t volatile signal_max = 0;

void setup(){
  digitalWrite(GPS_EN_PIN, LOW);
  #if defined(PRINT_ADA_H) || defined(SYNC_PC_TIME)
    Serial.begin(9600);
    while (!Serial);    // wait for serial port to connect. to not miss any output
  #endif
  #if defined(GET_TIME) && defined(SYNC_PC_TIME)
    time_setup();
  #endif
  imu_setup();          //setup the accelerometer sensor
  #ifdef SAVE_SD_ADA_H
    sd_setup();         //setup the SD card to save data into it
  #endif
  mioty_setup();
  pinMode(LED_BUILTIN, OUTPUT);
  //set up pin to send signal to esp
  pinMode(SIGNAL_PIN_ESP, OUTPUT);
  digitalWrite(SIGNAL_PIN_ESP, HIGH);
  //set pins to recive signals from max
  pinMode(SIGNAL_PIN_MAX_NOALARM, INPUT_PULLDOWN);
  pinMode(SIGNAL_PIN_MAX_ALARM, INPUT_PULLDOWN);
  
  print_debug("\n");
}

void ISR_NOALARM(){
  signal_max = SIGNAL_NOALARM;
}

void ISR_ALARM(){
  signal_max = SIGNAL_ALARM;
}

void activate_int(){
  signal_max = -1;
  attachInterrupt(digitalPinToInterrupt(SIGNAL_PIN_MAX_NOALARM), ISR_NOALARM, RISING);
  attachInterrupt(digitalPinToInterrupt(SIGNAL_PIN_MAX_ALARM), ISR_ALARM, RISING);
}

void deactivate_int(){
  detachInterrupt(digitalPinToInterrupt(SIGNAL_PIN_MAX_NOALARM));
  detachInterrupt(digitalPinToInterrupt(SIGNAL_PIN_MAX_ALARM));
}

void wait_for_max(){
  activate_int();

  while(signal_max == -1);

  deactivate_int();
}

void loop() {
  recordIMU();                                //measure number of values (NUM_SAMPLES in main.h) and calculate the featues out of
  predict();                                  //predict state //31ms
  if(classId == FEEDING){                     //if Feeding predicted
    digitalWrite(LED_BUILTIN, HIGH);
    print_debugln("signal sent!\n");          
    digitalWrite(SIGNAL_PIN_ESP, LOW);        //send signal to esp32_cam to take a picture
    delay(50);
    digitalWrite(SIGNAL_PIN_ESP, HIGH);
    wait_for_max();                           //wait for signal from max after it analysed picture
    send_data(signal_max);                     //send message through mioty according to signal form max
    print_debug("recieved: ");
    print_debugln(signal_max);
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(LOOP_DELAY);                          //delay between loops. duration LOOP_DELAY adjustable in main.h
}
