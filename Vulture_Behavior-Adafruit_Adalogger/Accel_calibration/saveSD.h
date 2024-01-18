#ifndef SAVESD_H 
  #define SAVESD_H

  /**
  * prepare the SD to be used
  * if DELET_OLD is defined (in the main.h) old files will be removed
  * saveSD will be true if the setup went well pointing out the capability of saving files
  */
  bool sd_setup(){
    if (!SD.begin(CS_PIN)) {
      saveSD = false;
      return false;
    }
    #ifdef DELET_OLD
      #ifdef SAVE_PRED_FILE_NAME
        SD.remove(SAVE_PRED_FILE_NAME);
      #endif
      #ifdef SAVE_RAW_FILE_NAME
        SD.remove(SAVE_RAW_FILE_NAME);
      #endif
    #endif
    saveSD = true;
    return true;
  }

  /**
  * save final calibration results
  * get file name from user
  * retrun true by completion
  */
  bool save_final_res(){
    if(!saveSD)return false;

    File f;
    do{
      empty_serial();
      Serial.println("enter desired file name:");
      while(Serial.available() == 0);
      String name = Serial.readStringUntil('\n'); 
      f = SD.open(name, FILE_WRITE);
      if(!f){
        empty_serial();
        Serial.println("file name cannot be accepted!\n to retry press enter. to return to the option menu type 9.");
        while(Serial.available() == 0);
        if(Serial.read()==9)return false;
      }
    }while(!f);
    
    for (int8_t i = 0; i < 3; i++) {
      f.println("calibration of " + String(axes[i]) + " axes:");
      f.print("\toffset: ");f.println(offset[i]);
      f.print("\tgain: ");f.println(gain[i]);
      f.println();
    }
    f.close();
    empty_serial();
    Serial.println("file saved!\nto return to the option menu press enter");
    while(Serial.available() == 0);
    return true;
  }
#endif
