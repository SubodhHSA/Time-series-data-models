#include "calc.h"

void get_features(float *x, float *y, float *z) {
  features[0] = calc_sdocpz(z);
  features[1] = calc_coryz(y, z);
  features[2] = calc_sdx(x);
  features[3] = calc_rangex(x);
  #ifdef PRINT_FEAT
    print_feat();  //print features to serial
  #endif
  #ifdef SAVE_FEAT_FILE_NAME
    save_feat();  //print features to SD card
  #endif
}

float get_g_value(float value) {
  return value * pow(2, FSR) / 16384;
}

float get_mean(float *value) {
  float sum = 0.0;
  for (int16_t i = 0; i < NUM_SAMPLES; i++) {
    sum += value[i];
  }
  return sum / NUM_SAMPLES;
}

float calculateSD(float *value, int16_t numData) {
  float sum = 0.0, mean = 0.0, standardDeviation = 0.0;
  for (int16_t i = 0; i < numData; i++) {
    sum += value[i];
  }
  mean = sum / numData;

  for (int16_t i = 0; i < numData; ++i) {
    standardDeviation += pow(value[i] - mean, 2);
  }

  return sqrt(standardDeviation / numData);
}

float calc_sdocpz(float *z) {
  float newZ[NUM_SAMPLES - 1];
  for (int16_t i = 0; i < NUM_SAMPLES - 1; i++) {
    newZ[i] = z[i + 1] - z[i];
  }
  return calculateSD(newZ, NUM_SAMPLES - 1);
}

float calc_coryz(float *y, float *z) {
  float sum_y = 0, sum_z = 0, sum_yz = 0, squareSum_y = 0, squareSum_z = 0;
  for (int16_t i = 0; i < NUM_SAMPLES; i++) {
    sum_y += y[i];
    sum_z += z[i];
    sum_yz += y[i] * z[i];
    squareSum_y += y[i] * y[i];
    squareSum_z += z[i] * z[i];
  }
  float d_z = NUM_SAMPLES * squareSum_z - sum_z * sum_z;
  float d_y = NUM_SAMPLES * squareSum_y - sum_y * sum_y;
  if (d_y == 0) d_y = 0.0001;  // avoid exception caused by division by zero
  if (d_z == 0) d_z = 0.0001;  // avoid exception caused by division by zero
  float denominator = sqrt(d_y * d_z);
  return (float)(NUM_SAMPLES * sum_yz - sum_y * sum_z) / denominator;
}

float calc_sdx(float *x) {
  return calculateSD(x, NUM_SAMPLES);
}

float calc_rangex(float *x) {
  float x_min = INT_MAX, x_max = INT_MIN;
  for (int16_t i = 0; i < NUM_SAMPLES; i++) {
    if (x[i] < x_min) x_min = x[i];
    if (x[i] > x_max) x_max = x[i];
  }
  return x_max - x_min;
}