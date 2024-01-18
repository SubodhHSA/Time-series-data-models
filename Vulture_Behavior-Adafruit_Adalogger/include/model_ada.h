#ifndef MODEL_ADA_H
  #define MODEL_ADA_H
  #include "Arduino.h"
  #include "common.h"
  #include "print_ada.h"
  #include "save_sd_ada.h"
  //support vectors and parameter of the tow trained mdoel
  #include "sv_activ_n.h"
  #include "sv_fly_eat.h"

  /**
  * @brief Convert class idx (index) to readable name.
  *
  * @param classIdx the predicted class idx via the predict method to be converted to readable label.
  *
  * @return readable class name
  */
  const char* idxToLabel(uint8_t classIdx);
  
  /**
  * @brief Convert saved class idx (classId in main.h) to readable name.
  *
  * @return readable class name
  */
  const char* idxToLabel();

  /**
  * @brief Compute kernel between feature vector and support vector.
  *        Kernel type: rbf
  *
  * @param x      feature vector of the state to be predicted
  * @param gamma  gamma parameter of the trained model
  * @param sv     support vector
  *
  * @return kernel value for this specific feature vector and this specific support vector
  */
  float compute_kernel(float *x, float gamma, float *sv);

  /**
  * @brief Compute softmax funktion to get probability of the accuracy of a prediction.
  *
  * @param decision   the distance from the boundary calculated via the kernel and the parameter.
  * @param reference  -1 or 1. the class the probability should be calculated for.
  *
  * @return the probability in decimals; between 0 and 1
  */
  float get_prob(float decision, int8_t reference);
          
  /**
  * @brief Predict class idx for features vector.
  *        Probaility and class idx would be also saved to prob and classId in main.h
  *
  * @param x feature vector of the state to be predicted.
  *
  * @return the class index which can be convert to readable name via idxToLabel method
  */
  uint8_t predict(float *x);

  /**
  * @brief Predict class idx for saved features vector (features in main.h).
  *        Probaility and class idx would be also saved to prob and classId in main.h
  *
  * @return the class index which can be convert to readable name via idxToLabel method
  */
  uint8_t predict();

  /**
  * @brief Predict readable class name.
  *
  * @param x feature vector of the state to be predicted.
  *
  * @return prediction with a readable class name
  */
  const char* predictLabel(float *x);
#endif