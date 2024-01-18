#ifndef I2C_ADA_H
  #define I2C_ADA_H
  #include "Arduino.h"
  #include "Wire.h"         //for I2C connection needed for accelerometer and pressuresenor
  
  /**
  * @brief setup the i2c connection.
  *
  * @return 
  */
  void i2c_setup();
  
  /**
  * @brief write to a register.
  *
  * @param add    address of the device to write on.
  * @param reg    address of the regiter to write on.
  * @param value  the value to be written.
  *
  * @return true if writing succeed otherwise false.
  */
  bool write_register(uint8_t add, uint8_t reg, int8_t value);
  
  /**
  * @brief read from a multile bytes out of a register and combined them to one value.
  *
  * @param add    address of the device to read of.
  * @param reg    address of the regiter to read of.
  * @param bytes  number of bytes to be read and combined.
  *
  * @return the read value.
  */
  uint32_t read_bytes(uint8_t add, uint8_t reg, uint8_t bytes);
  
  /**
  * @brief burst read from a register.
  *
  * @param add    address of the device to read of.
  * @param reg    address of the regiter to read of.
  * @param value  array to save read values to.
  * @param n      number of values to read.
  * @param bytes  number of bytes for each value.
  *
  * @return true if reading succeed otherwise false.
  */
  bool burst_read(uint8_t add, uint8_t reg, uint32_t *value, uint8_t n, uint8_t bytes);
#endif
