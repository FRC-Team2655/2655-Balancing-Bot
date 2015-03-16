/*
  This code is desinged to control a two wheeled robot and keep it upright.
 */
#include <ck1122.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69


MPU6050 *accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup()
{
  Serial.begin(9600);  
}

void loop()
{
  accelgyro->getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  Serial.print (ax); 
  
  Serial.print(ay);
  
  Serial.print(az);
  
  
  Serial.print(" ");
  
  delay(100);
}
