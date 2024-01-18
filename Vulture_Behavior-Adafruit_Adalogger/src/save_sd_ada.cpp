#include "save_sd_ada.h"

#define get_name(f_name_, f_num_) (f_num_?(String(f_num_) + "_" + f_name_):(f_name_))   //append number at the end of filename. if number is 0 do nothing
#define get_max_num(a, b) (a>b?a:b)                                               //get max number between tow
uint8_t f_num = 0;                                                                //number to append at the end of file name to avoid overwriting. to extend number range - file number - change to int
bool saveSD = false;                                                              //can save files to SD card (SD card setup went well or not)

String point_to_coma(float f){
  String comma = String(f-int(f));
  return String(int(f)) + "," + comma.substring(comma.indexOf('.')+1);
}

#ifdef SAVE_FEAT_FILE_NAME
  bool save_feat(){
    if(!saveSD)print_debugln("Unable to save features; SD card not connected");return false;
    
    File f = SD.open(get_name(SAVE_FEAT_FILE_NAME, f_num), FILE_WRITE);
    if(!f){
      print_debugln("Unable to open file: " + get_name(SAVE_FEAT_FILE_NAME, f_num));
      return false;
    }
    
    f.print(get_time());f.print(";");
    for (int8_t i = 0; i < NUM_FEATURES; i++) {
        f.print(point_to_coma(features[i]));
        f.print(i == NUM_FEATURES - 1 ? "\n" : ";");
    }
    f.close();
    return true;
  }
#endif

#ifdef SAVE_PRED_FILE_NAME
  bool save_pred(){
    if(!saveSD){
      print_debugln("Unable to save prediction; SD card not connected");
      return false;
    }
    
    File f = SD.open(get_name(SAVE_PRED_FILE_NAME, f_num), FILE_WRITE);
    if(!f){
      print_debugln("Unable to open file: " + get_name(SAVE_PRED_FILE_NAME, f_num));
      return false;
    }
    
    f.print(get_time());f.print(";");
    f.print(label);
    f.print(";");
    f.println(point_to_coma(prob));
    f.close();
    return true;
  }
#endif

#ifdef SAVE_RAW_FILE_NAME
  bool save_raw_data(float ax, float ay, float az){
    if(!saveSD){
      print_debugln("Unable to save raw data; SD card not connected");
      return false;
    }
    
    File f = SD.open(get_name(SAVE_RAW_FILE_NAME, f_num), FILE_WRITE);
    if(!f){
      print_debugln("Unable to open file: " + get_name(SAVE_RAW_FILE_NAME, f_num));
      return false;
    }
    
    f.print(get_time());f.print(";");
    f.print(point_to_coma(ax));f.print(";");
    f.print(point_to_coma(ay));f.print(";");
    f.println(point_to_coma(az));
    f.close();
    return true;
  }
#endif

#ifdef SAVE_PRES_FILE_NAME
  bool save_pres_data(float p){
    if(!saveSD){
      print_debugln("Unable to save pressure; SD card not connected");
      return false;
    }
    
    File f = SD.open(get_name(SAVE_PRES_FILE_NAME, f_num), FILE_WRITE);
    if(!f){
      print_debugln("Unable to open file: " + get_name(SAVE_PRES_FILE_NAME, f_num));
      return false;
    }
    
    f.print(get_time());f.print(";");
    f.println(point_to_coma(p));
    f.close();
    return true;
  }
#endif

bool save_head(){
  if(!saveSD)return false;

  #ifdef SAVE_PRES_FILE_NAME
    File f = SD.open(get_name(SAVE_PRES_FILE_NAME, f_num), FILE_WRITE);
    if(!f){
      print_debugln("Unable to open file: " + get_name(SAVE_PRES_FILE_NAME, f_num));
      return false;
    }
    f.print(get_time());f.print(";");f.println("p in Pa");
    f.close();
  #endif
  #ifdef SAVE_RAW_FILE_NAME
    f = SD.open(get_name(SAVE_RAW_FILE_NAME, f_num), FILE_WRITE);
    if(!f){
      print_debugln("Unable to open file: " + get_name(SAVE_RAW_FILE_NAME, f_num));
      return false;
    }
    f.print(get_time());f.print(";");f.println("x(1g=2048); y(1g=2048); z(1g=2048)");
    f.close();
  #endif
  #ifdef SAVE_FEAT_FILE_NAME
    f = SD.open(get_name(SAVE_FEAT_FILE_NAME, f_num), FILE_WRITE);
    if(!f){
      print_debugln("Unable to open file: " + get_name(SAVE_FEAT_FILE_NAME, f_num));
      return false;
    }
    f.print(get_time());f.print(";");
    for (int8_t i = 0; i < NUM_FEATURES; i++) {
        f.print(feature_names[i]);
        f.print(i == NUM_FEATURES - 1 ? "\n" : ";");
    }
    f.close();
  #endif
  #ifdef SAVE_PRED_FILE_NAME
    f = SD.open(get_name(SAVE_PRED_FILE_NAME, f_num), FILE_WRITE);
    if(!f){
      print_debugln("Unable to open file: " + get_name(SAVE_PRED_FILE_NAME, f_num));
      return false;
    }
    f.print(get_time());f.print(";");f.println("pred;prob");
    f.close();
  #endif

  return true;
}

#ifndef DELET_OLD
  uint8_t check_exist(String f_name){
    uint8_t num;
    for(num = 0; SD.exists(get_name(f_name, num)); num++);
    return num;
  }
#endif

bool sd_setup(){
  if (!SD.begin(CS_PIN)) {
    print_debugln("could not setup SD card");
    saveSD = false;
    return false;
  }
  #ifdef DELET_OLD
    #ifdef SAVE_FEAT_FILE_NAME
      SD.remove(SAVE_FEAT_FILE_NAME);
    #endif
    #ifdef SAVE_PRED_FILE_NAME
      SD.remove(SAVE_PRED_FILE_NAME);
    #endif
    #ifdef SAVE_RAW_FILE_NAME
      SD.remove(SAVE_RAW_FILE_NAME);
    #endif
    #ifdef SAVE_PRES_FILE_NAME
      SD.remove(SAVE_PRES_FILE_NAME);
    #endif
  #else
    #ifdef SAVE_FEAT_FILE_NAME
      f_num = get_max_num(check_exist(SAVE_FEAT_FILE_NAME), f_num);
    #endif
    #ifdef SAVE_PRED_FILE_NAME
      f_num = get_max_num(check_exist(SAVE_PRED_FILE_NAME), f_num);
    #endif
    #ifdef SAVE_RAW_FILE_NAME
      f_num = get_max_num(check_exist(SAVE_RAW_FILE_NAME), f_num);
    #endif
    #ifdef SAVE_PRES_FILE_NAME
      f_num = get_max_num(check_exist(SAVE_PRES_FILE_NAME), f_num);
    #endif
  #endif
  saveSD = true;
  saveSD = save_head();
  print_debugln(saveSD?("SD card setup succeed"):("could not setup SD card"));
  return saveSD;
}