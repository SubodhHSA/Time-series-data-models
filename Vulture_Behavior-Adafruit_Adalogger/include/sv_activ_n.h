#ifndef SV_ACTIV_N_H
  #define SV_ACTIV_N_H
  #include "common.h"

  #define NUMSVEC_ACTIV_N 164         //number of support vectors
  #define THRESH_ACTIV_N 0.86744391   //threshold b; a machine learned parameter
  #define GAMMA_ACTIV_N 2.99          //gamma; the parameter used in the learning phase
  //decision < 0 ? 0 : 1

  //the support vectors; machine learned
  extern float svec_activ_n[NUMSVEC_ACTIV_N][NUM_FEATURES];
  //the alpha parameters; machine leared parameters
  extern float alpha_activ_n[NUMSVEC_ACTIV_N];
#endif