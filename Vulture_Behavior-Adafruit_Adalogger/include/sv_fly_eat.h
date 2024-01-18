#ifndef SV_FLY_EAT_H
  #define SV_FLY_EAT_H
  #include "common.h"

  #define NUMSVEC_FLY_EAT 232           //number of support vectors
  #define THRESH_FLY_EAT -0.82866286    //threshold b; a machine learned parameter
  #define GAMMA_FLY_EAT 9.99            //gamma; the parameter used in the learning phase
  //decision < 0 ? 0 : 1

  //the support vectors; machine learned
  extern float svec_fly_eat[NUMSVEC_FLY_EAT][NUM_FEATURES];
  //the alpha parameters; machine leared parameters
  extern float alpha_fly_eat[NUMSVEC_FLY_EAT];
#endif