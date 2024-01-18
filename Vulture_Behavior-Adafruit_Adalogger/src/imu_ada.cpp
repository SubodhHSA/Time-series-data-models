#include "imu_ada.h"

#define MPU_ADDR 0x68                 //address of the MPU chip of the accel. to establish connection
#define PWR_MGMT_1 0x6B               //address of the first power management register to adjust power state to the value below
#ifdef SLEEP_CYCLE                    //SLEEP (bit 6) to 0 and CYCLE (bit 5) to 1 to cycle between sleep mode and waking up to take a single sample and TEMP_DIS (bit 3) to 1 disable Temperature measurement
  #ifdef TEMP_DIS
    #define PWR_MGMT_1_VALUE 0b00101000
  #else
    #define PWR_MGMT_1_VALUE 0b00100000
  #endif
#else
  #ifdef TEMP_DIS
    #define PWR_MGMT_1_VALUE 0b00001000
  #else
    #define PWR_MGMT_1_VALUE 0b00000000
  #endif
#endif  
#define PWR_MGMT_2 0x6C               //address of the second power management register to adjust power state to the value below
#ifdef GYRO_DIS                       //LP_WAKE_CTRL (bit 6 and 7) to 2 => 20Hz. STBY_XG, _YG and _ZG (bit 2, 1 and 0) to 1 to set gyro sensor to standby)
  #define PWR_MGMT_2_VALUE (WAKE_CTRL<<6 | 7)
#else
  #define PWR_MGMT_2_VALUE (WAKE_CTRL<<6)
#endif
#define ACCEL_FS 0x1C                 //address of the Configuration register to select the accelerometer full scale (AFS_SEL) to the value below
#define AFS (FSR<<3)                  // bit 3 and 4 -> 3 ==> 16g
#define ACCEL_XOUT 0x3B               //address of the first register containing the measured data(first byte of x-accel.). the remain registers follow this rigister
//Intervals between sampels in ms
#if WAKE_CTRL == 0                    //1.25Hz
  #define INTERVAL 800
#elif WAKE_CTRL == 1                  //5Hz
  #define INTERVAL 200
#elif WAKE_CTRL == 2                  //20Hz
  #define INTERVAL 50
#elif WAKE_CTRL == 3                  //40Hz
  #define INTERVAL 25
#endif

bool imu;                             //can measure accelerometer data (accelerometer sensor setup went well or not)

void recordIMU() {
  if(!imu){
    print_debugln("Unable to measure acceleration; Sensor not connected");
    return;
  }
  
  float x[NUM_SAMPLES], y[NUM_SAMPLES], z[NUM_SAMPLES];
  for (int8_t i = 0; i < NUM_SAMPLES; i++) {
      imu_read(&x[i], &y[i], &z[i]);

      delay(INTERVAL);
  }

  get_features(x, y, z);
}

void calibrate(float *ax, float *ay, float *az){
  *ax = GAIN_X * (*ax - OFFSET_X);
  *ay = GAIN_Y * (*ay - OFFSET_Y);
  *az = GAIN_Z * (*az) - OFFSET_Z;
}

void imu_read(float *ax, float *ay, float *az) {
  if(!imu){
    print_debugln("Unable to measure acceleration; Sensor not connected");
    return;
  }
  
  uint32_t value[3];

  if(!burst_read(MPU_ADDR, ACCEL_XOUT, value, 3, 2))return;

  *ax = float(int16_t(value[0]));
  *ay = float(int16_t(value[1]));
  *az = float(int16_t(value[2]));

  calibrate(ax, ay, az);
  
  #ifdef PRINT_RAW
    printData(*ax, *ay, *az);
  #endif
  *ax = get_g_value(*ax);
  *ay = get_g_value(*ay);
  *az = get_g_value(*az);
  #ifdef PRINT_G_VAL
    printData(*ax, *ay, *az);
  #endif
  #ifdef SAVE_RAW_FILE_NAME
    save_raw_data(*ax, *ay, *az);
  #endif
}

bool imu_setup() {
  i2c_setup();
  imu = write_register(MPU_ADDR, PWR_MGMT_1, 0b00001000) && write_register(MPU_ADDR, PWR_MGMT_2, PWR_MGMT_2_VALUE) && write_register(MPU_ADDR, ACCEL_FS, AFS) && write_register(MPU_ADDR, PWR_MGMT_1, PWR_MGMT_1_VALUE);
  print_debugln(imu?("accelerometer connencted"):("failed to connect accelerometer at " + String(MPU_ADDR) + "\ntry running i2c_scan to scan for addresses of contected devices and adjust the address \"MPU_ADDR\" in imu.h"));
  return imu;
}
