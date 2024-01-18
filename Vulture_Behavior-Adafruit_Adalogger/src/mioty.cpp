#include "mioty.h"

void miotyAtClientWrite(uint8_t *msg, uint16_t len) {
  Serial1.write(msg, len);
}

bool miotyAtClientRead(uint8_t *buf, uint8_t *p_len) {
  int i = 0;
  while (Serial1.available() > 0) {
    buf[i] = Serial1.read();
    i++;
  }
  *p_len = i;
  return true;
}

void mioty_setup() {
  Serial1.begin(9600);
  randomSeed(analogRead(0));  //for reshuffling the random generator
}

void get_location(int32_t *latitude, int32_t *longitude) {
  *latitude = 495469850 + random(-19000, +19000);
  *longitude = 110191200 + random(-34000, +34000);
}

void send_data(uint8_t signal) {
  int32_t latitude, longitude;
  uint8_t accuracy = 100;

  get_location(&latitude, &longitude);
  uint8_t sent_data[10] = {
    (uint8_t)((latitude >> 24) & 0xff),
    (uint8_t)((latitude >> 16) & 0xff),
    (uint8_t)((latitude >>  8) & 0xff),
    (uint8_t)((latitude >>  0) & 0xff),

    (uint8_t)((longitude >> 24) & 0xff),
    (uint8_t)((longitude >> 16) & 0xff),
    (uint8_t)((longitude >>  8) & 0xff),
    (uint8_t)((longitude >>  0) & 0xff),

    accuracy,
    signal,
  };

  uint32_t packet_counter = 0;
  print_debugln("Sending data...");
  miotyAtClient_sendMessageUni(sent_data, sizeof(sent_data) / sizeof(uint8_t), &packet_counter);
  print_debug("Data sent. Counter:");
  print_debugln((packet_counter, DEC));
}