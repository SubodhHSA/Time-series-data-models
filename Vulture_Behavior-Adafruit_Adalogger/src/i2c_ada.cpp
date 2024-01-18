#include "i2c_ada.h"

void i2c_setup(){
  Wire.begin();
}

bool write_register(uint8_t add, uint8_t reg, int8_t value){
  Wire.beginTransmission(add);
  Wire.write(reg);
  Wire.write(value);
  return !Wire.endTransmission(true);
}

uint32_t read_bytes(uint8_t add, uint8_t reg, uint8_t bytes){
  uint32_t value = 0;

  Wire.beginTransmission(add);
  Wire.write(reg);
  Wire.endTransmission(false);
  if(Wire.requestFrom(add, bytes, true) != bytes){
    Wire.endTransmission();
    return 0;
  }

  for(uint8_t i = 0; i < bytes; i++){
    value = (value << 8) | Wire.read();
  }

  Wire.endTransmission();

  return value;
}

bool burst_read(uint8_t add, uint8_t reg, uint32_t *value, uint8_t n, uint8_t bytes){
  Wire.beginTransmission(add);
  Wire.write(reg);
  Wire.endTransmission(false);   
    
  if(Wire.requestFrom(add, n*bytes, true) != n*bytes){
    Wire.endTransmission();
    return false;
  }

  for(uint8_t i = 0; i < n; i++){
    value[i] = 0;
    for(uint8_t j = 0; j < bytes; j++){
      value[i] = (value[i] << 8) | Wire.read();
    }
  }

  Wire.endTransmission();
  return true;
}