#pragma once

#include "sv_activ_n.h"
#include "sv_fly_eat.h"

/**
* Compute kernel between feature vector and support vector.
* Kernel type: rbf
*/
float compute_kernel(float *x, float gamma, float f1, float f2, float f3, float f4) {
	float f[4] = {f1, f2, f3, f4};
	float kernel = 0.0;

	for (uint8_t i = 0; i < 4; i++) {
		kernel += pow(x[i] - f[i], 2);
	}

	return exp(-gamma * kernel);
}

float soft_max(float a, float b){
  return exp(a)/(exp(a)+exp(b));
}
				
/**
* Predict class for features vector
*/
uint8_t predict(float *x, float *prob) {
  //activ or not 
  float decision = -THRESH_AN;
  for(uint8_t i = 0; i < NUMSVEC_AN; i++){
    decision += compute_kernel(x, GAMMA_AN, svec_an[i][0], svec_an[i][1], svec_an[i][2], svec_an[i][3]) * alpha_an[i];
  }
  //low_activity => +1
  if(decision > 0){
    *prob = 1 - soft_max(decision-1, -1-decision);
    return 1;
  }
  //if not -> flying or feeding 
  *prob = soft_max(-1-decision, decision-1);
  
  decision = -THRESH_FE;
  for(uint8_t i = 0; i < NUMSVEC_FE; i++){
    decision += compute_kernel(x, GAMMA_FE, svec_fe[i][0], svec_fe[i][1], svec_fe[i][2], svec_fe[i][3]) * alpha_fe[i];
  }
  //feeding => +1
  if(decision > 0){
    *prob = *prob * soft_max(decision-1, -1-decision);
    return 2;
  }
  //if not -> flying
  *prob = *prob * soft_max(-1-decision, decision-1);
  return 0;
}

/**
* Convert class idx to readable name
*/
const char* idxToLabel(uint8_t classIdx) {
	switch (classIdx) {
		case 0:
		return "flying";
		case 1:
		return "low_activity";
    case 2:
		return "feeding";
		default:
		return "Houston we have a problem";
	}
}

/**
* Predict readable class name
*/
const char* predictLabel(float *x, float *prob) {
	return idxToLabel(predict(x, prob));
}
