#ifndef PRINT_H
  #define PRINT_H

  /*
   * read all user inputs (before asking for new input) to delete all saved inputs for new input be saved in first place
   */
  void read_all(){
    while(Serial.available() > 0) {
      Serial.read();
    }
  }

  /*
   * read all user inputs (before asking for new input) to delete all saved inputs for new input be saved in first place
   * add n (EMPTY_LINES) new empty lines instead of clearing the Terminal(not possible to clear).
   */
  void empty_serial(){
    read_all();
    for(uint8_t i = 0; i < EMPTY_LINES; i++){
      Serial.println();
    }
  }

  /*
   * print final results to Serial and wait for user input before contintuing 
   */
  void show_final_res(){
    empty_serial();
    for (int8_t i = 0; i < 3; i++) {
      Serial.print("calibration of ");Serial.print(axes[i]);Serial.println(" axes:");
      Serial.print("\toffset: ");Serial.println(offset[i]);
      Serial.print("\tgain: ");Serial.println(gain[i]);
      Serial.println();
    }
    Serial.println("\nto return to the option menu press enter");
    while(Serial.available() == 0);
  }

  /*
   * print options to Serial and wait for user input before contintuing 
   */
  void print_options(){
    empty_serial();
    Serial.println("type an option to continue:");
    Serial.println("1:save results to SD card");
    Serial.println("2:show results");
    Serial.println("3:run test");
    Serial.println("4:close");
    Serial.println("9:restart");
    while(Serial.available() == 0);
  }

  /*
   * print results of one calibration step to Serial and wait for user input before contintuing 
   */
  void print_res(char axes, float val_h, float val_l, float offs, float gain){
    empty_serial();
    Serial.print("calibration of ");Serial.print(axes);Serial.println(" axes is finished. final results are:");
    Serial.print("Offset: ");Serial.println(offs);
    Serial.print("Gain: ");Serial.println(gain);
    Serial.println("using this measured values:");
    Serial.print("+1g: ");Serial.println(val_h > val_l ? val_h : val_l);
    Serial.print("-1g: ");Serial.println(val_h < val_l ? val_h : val_l);
    Serial.println("\nto continue press enter to restart type 9.");
    while(Serial.available() == 0);
  }

  /**
  * prints the 3 accelerometer values
  * ax, ay, az: acceleration in the x, y and z direction 
  */
  void printData(float ax, float ay, float az){
    Serial.print("aX = ");      Serial.print(ax);
    Serial.print(" | aY = ");   Serial.print(ay);
    Serial.print(" | aZ = ");   Serial.print(az);
    Serial.println();
  }
#endif
