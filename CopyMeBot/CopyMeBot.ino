
#include <ck1122.h>
#include "I2Cdev.h"
#include "MPU6050.h"

#include "Wire.h"

MPU6050 *accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;


void setup()
{
  Serial.begin(9600); 
}

void loop()
{
  static int i = 0;
  Serial.print("hi "); Serial.print(i++); Serial.print("\n");  
  delay(200);
}

