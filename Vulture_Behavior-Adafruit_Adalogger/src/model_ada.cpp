#include "model_ada.h"

//support vectors and parameter of the tow trained mdoel
#define THRESH_PRES 30
#define DELAY_PRES  500
float features[NUM_FEATURES];
uint8_t classId;
float prob;
String label;


const char* idxToLabel(uint8_t classIdx) {
  switch (classIdx) {
    case FLYING:
    return "flying";
    case LOW_ACTIVITY:
    return "low_activity";
    case FEEDING:
    return "feeding";
    case UNDEFINED:
    return "undefined";
    default:
    return "Houston we have a problem";
  }
}

const char* idxToLabel() {
  return idxToLabel(classId);
}

float compute_kernel(float *x, float gamma, float *sv) {
	float kernel = 0.0;

	for (uint8_t i = 0; i < NUM_FEATURES; i++) {
		kernel += pow(x[i] - sv[i], 2);
	}

	return exp(-gamma * kernel);
}

float get_prob(float decision, int8_t reference){
  float a = decision - reference;             //*calculate the distances to the reference and the opposite reference
  float b = -(decision + reference);          //*positive distance if in the label area negative if not
  if(reference < 0){
    a *= -1;
    b *= -1;
  }else if(reference != 1)return -1;          //reference should be 1 or -1 if not return -1 as prob
  return exp(a)/(exp(a)+exp(b));              //apply the Softmax funktion-
}

uint8_t predict(float *x) {
  //activ or not 
  float decision = -THRESH_ACTIV_N;
  for(uint8_t i = 0; i < NUMSVEC_ACTIV_N; i++){
    decision += compute_kernel(x, GAMMA_ACTIV_N, svec_activ_n[i]) * alpha_activ_n[i];
  }

  //low_activity => +1
  if(decision > 0){
    prob = get_prob(decision, 1);
    classId = LOW_ACTIVITY;
  }else{
    //if not low_activity -> flying or feeding 
    prob = get_prob(decision, -1);
    
    decision = -THRESH_FLY_EAT;
    for(uint8_t i = 0; i < NUMSVEC_FLY_EAT; i++){
      decision += compute_kernel(x, GAMMA_FLY_EAT, svec_fly_eat[i]) * alpha_fly_eat[i];
    }
    //feeding => +1
    if(decision > 0){
      prob = prob * get_prob(decision, 1);
      classId = FEEDING;
    }else{
      //if not feeding -> flying
      prob = prob * get_prob(decision, -1);
      classId = FLYING;
    }
  }
  
  if(prob < PROB_THRESH){
    classId = UNDEFINED;
  }

  #if defined(PRINT_PRED) || defined(SAVE_PRED_FILE_NAME)
    label = idxToLabel();
  #endif
  #ifdef PRINT_PRED
    print_pred();           //print prediction and probility to serial
  #endif
  #ifdef SAVE_PRED_FILE_NAME
    save_pred();            //print prediction and probility to SD card
  #endif

  return classId;
}

uint8_t predict() {
  return predict(features);
}

const char* predictLabel(float *x) {
	return idxToLabel(predict(x));
}