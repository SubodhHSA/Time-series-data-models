#ifndef CALC_H
  #define CALC_H
  #include "Arduino.h"
  #include "common.h"
  #include "print_ada.h"
  #include "save_sd_ada.h"
  #include <math.h>

  /**
  * @brief  get the features out of the measurements from accelerometer sensor to apply to the model.
  *         save features to features in main.h.
  *
  * @param x arrays of the raw acceleration measurments in x direction out of the features should be calculated.
  * @param y arrays of the raw acceleration measurments in y direction out of the features should be calculated.
  * @param z arrays of the raw acceleration measurments in z direction out of the features should be calculated.
  * 
  * @returns
  */
  void get_features(float *x, float *y, float *z);

  /**
  * @brief get the g value to normalize the value of an accelerometer messured value.
  *
  * @param value an accelerometer messured value.
  * 
  * @returns the normalized g value.
  */
  float get_g_value(float value);

  /**
  * @brief calculate the mean out of a set of data.
  *
  * @param value an array of a set of data to claculate the mean out of. with NUM_SAMPLES elements (defined in main.h).
  * 
  * @returns the calculated mean.
  */
  float get_mean(float *value);

  /**
  * @brief calculate the standard deviation out of a set of data.
  *
  * @param value    an array of a set of data to claculate the standard deviation out of.
  * @param numData  number of elements in the array.
  * 
  * @returns the calculated standard deviation.
  */
  float calculateSD(float* value, int16_t numData);

  /**
  * @brief  calculate the  sdocpz feature out of a set of z acceleration values.
  *         sdocpz is the standard deviation of the change of the z acceleration values (𝒛_𝑖−𝒛_(𝑖−1)).
  *
  * @param z an array of a set of z acceleration values to claculate the sdocpz out of. with NUM_SAMPLES elements (defined in main.h).
  * 
  * @returns the calculated sdocpz.
  */
  float calc_sdocpz(float* z);

  /**
  * @brief  calculate the  coryz feature out of a set of z and y acceleration values.
  *         coryz is the correlation (dependency) between y and z acceleration values.
  *
  * @param y an array of a set of y acceleration values to claculate the coryz out of. with NUM_SAMPLES elements (defined in main.h).
  * @param z an array of a set of z acceleration values to claculate the coryz out of. with NUM_SAMPLES elements (defined in main.h).
  * 
  * @returns the calculated coryz.
  */
  float calc_coryz(float *y, float *z);

  /**
  * @brief  calculate the  sdx feature out of a set of x acceleration values.
  *         sdx is the standard deviation of the x acceleration values.
  *
  * @param x an array of a set of x acceleration values to claculate the sdx out of. with NUM_SAMPLES elements (defined in main.h).
  * 
  * @returns the calculated sdx.
  */
  float calc_sdx(float *x);

  /**
  * @brief  calculate the  rangex feature out of a set of x acceleration values.
  *         rangex is the range of the x values (max-min)
  *
  * @param x an array of a set of x acceleration values to claculate the rangex out of. with NUM_SAMPLES elements (defined in main.h).
  * 
  * @returns the calculated rangex.
  */
  float calc_rangex(float *x);
#endif
