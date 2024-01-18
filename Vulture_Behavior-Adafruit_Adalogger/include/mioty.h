#ifndef MIOTY_H
  #define MIOTY_H
  #include "Arduino.h"
  #include "common.h"
  #include "miotyAtClient.h"

  /**
  * @brief send the image buffer over UART. send the value UART_SIGNAL defined in main.h to signal incomming data.
  *
  * @param data     image buffer to be sent.
  * @param len      length of the image buffer.
  *
  * @return 
  */
  void mioty_setup();

  /**
  * @brief  send message over UART to the mioty module.
  *         used by the miotyAtClient to sens data.
  *         needed for miotyAtClient_sendMessageUni().
  * 
  * @param msg  message to be sent to the mioty module.
  * @param len  length of the msg.
  *
  * @return 
  */
  void miotyAtClientWrite(uint8_t *msg, uint16_t len);

  /**
  * @brief  receive message over UART from the mioty module.
  *         used by the miotyAtClient to receive data.
  *         needed for miotyAtClient_sendMessageUni().
  * 
  * @param data     pointer to buffer to save the received message inside.
  * @param len      length of the msg buffer.
  *
  * @return true on success
  */
  bool miotyAtClientRead(uint8_t *buf, uint8_t *p_len);

  /**
  * @brief temporary get location method. for now get random location. later get location from GPS module
  *
  * @param latitude   pointer to the variable where latitude is gonna be saved (*10^7).
  * @param longitude  pointer to the variable where longitude is gonna be saved (*10^7).
  *
  * @return 
  */
  void get_location(int32_t *latitude, int32_t *longitude);

  /**
  * @brief  send message through mioty according to received signal of the AI-Model with a gps location from get_location().
  *
  * @param signal signal of AI-prediction; 0: NOALARM (other), 1: ALARM (Elephant/Rhino).
  *
  * @return 
  */
  void send_data(uint8_t signal);
#endif