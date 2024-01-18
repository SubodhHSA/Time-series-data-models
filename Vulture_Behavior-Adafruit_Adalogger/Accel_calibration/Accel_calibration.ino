#include "main.h"

void setup(){
  Serial.begin(9600);
  while (!Serial);  // wait for serial port to connect. to not miss any output
  imu_setup();      //setup the accelerometer sensor
  sd_setup();       //setup the SD card to save data into it
}

/**
* calculate the mean out of a set of data
* param:
*   value: the array of values to calculate the mean out of
* reaturn:
*   the calculated mean
*/
float get_mean(float *value){
  float sum = 0.0;
  for(int16_t i = 0; i < NUM_SAMPLES; i++){
    sum += value[i];
  }
  return sum/NUM_SAMPLES;
}

/**
* reset offset and gain
* set all offsets to 0 and all gains to 1
*/
void reset_offset(){
  for(uint8_t i = 0; i < 3; i++){
    offset[i] = 0;
    gain[i] = 1;
  }
}

/**
* calibrate axes
* param:
*   axe: index of axe to calibrate. 0, 1 or 2 for x, y or z
* reaturn:
*   false if user wants to restart calibration
*/
bool run_calib(uint8_t axe){
  read_all();   
  Serial.println("put the accelerometer so that the " + String(axes[axe]) + " aches is pointing away from the ground and press enter to start. or type 9 to restart.");
  while(Serial.available() == 0);
  if(Serial.read()=='9')return false;

  recordIMU();            
  float first_val = get_mean(m[axe]);

  empty_serial();
  Serial.println("\nnow put the accelerometer in the other direction - " + String(axes[axe]) + " should be pointing to ground now - and press enter. or type 9 to restart.");
  while(Serial.available() == 0);
  if(Serial.read()=='9')return false;

  recordIMU();            
  float second_val = get_mean(m[axe]);
  offset[axe] = (second_val+first_val)/2;  
  gain[axe] = 16384 / (abs(first_val - offset[axe]) * pow(2, FSR));

  print_res(axes[axe], first_val, second_val, offset[axe], gain[axe]);
  if(Serial.read()=='9')return false;

  return true;
}

/**
* run test which consists of 100 measurements to see if calibration was good enough
* test can be stoped by the user by pressing enter
*/
void run_test(){
  empty_serial();
  Serial.println("PS: press enter to stop or wait for 100 measurments!");
  delay(2000);
  for(uint8_t i  = 0; i < 100 && Serial.available()==0; i++){
    float ax, ay, az; 
    imu_read(&ax, &ay, &az);
    printData(ax, ay, az);
    delay(LOOP_DELAY);
  }
  read_all();
  Serial.println("\nto return to the option menu press enter");
  while(Serial.available() == 0);
}

void loop() {   
  reset_offset();
  for(uint8_t i = 0; i < 3; i++){
    empty_serial();
    Serial.println(i==0 ? "starting calibration!" : "now switching to the " + String(axes[i]) + " axes");
    if(!run_calib(i))return;
    delay(LOOP_DELAY);
  }

  empty_serial();
  Serial.println("calibration finished!");

  while(true){
    print_options();

    switch(Serial.read()){
      case '1':
        save_final_res();
        break;
      case '2':
        show_final_res();
        break;
      case '3':
        run_test();
        break;
      case '4':
        empty_serial();
        Serial.println("calibration terminated!");
        while(true);
        break;
      case '9':
        return;
      default:
        Serial.println("unnkown command. please try again!");
        delay(2000);
        break;
    }
    empty_serial();
  }
}
