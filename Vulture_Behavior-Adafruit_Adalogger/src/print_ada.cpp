#include "print_ada.h"

#ifdef PRINT_PRES
  void print_pres_data(float p){
    Serial.print(get_time());Serial.print(":\t");
    Serial.print("p = ");Serial.print(p);Serial.println(" Pa");
  }
#endif

#ifdef PRINT_RAW
  void printData(float ax, float ay, float az){
    Serial.print(get_time());Serial.print(":\t");
    Serial.print("aX = ");      Serial.print(ax);
    Serial.print(" | aY = ");   Serial.print(ay);
    Serial.print(" | aZ = ");   Serial.print(az);
    Serial.println();
  }
#endif

#ifdef PRINT_FEAT
  void print_feat() {
    Serial.print(get_time());Serial.print(":\t");
    for (int i = 0; i < NUM_FEATURES; i++) {
        Serial.print(feature_names[i] + ": ");
        Serial.print(features[i]);
        Serial.print(i == NUM_FEATURES - 1 ? "\n" : ", ");
    }
  }
#endif

#ifdef PRINT_PRED
  void print_pred() {
    Serial.print(get_time());Serial.print(":\t");
    Serial.print("Detected gesture: ");
    Serial.print(label);
    Serial.print(",\tprob: ");
    Serial.println(prob);
    Serial.println();
  }
#endif