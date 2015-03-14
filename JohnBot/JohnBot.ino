#include <ck1122.h>


#include <I2Cdev.h>

#include <Wire.h>

#include <helper_3dmath.h>
#include <MPU6050.h>

const int M1IN1 = 8;
const int M1IN2 = 7;
const int M1PWM = 6;

const int M2PWM = 5;
const int M2IN1 = 4;
const int M2IN2 = 3;

ck1122 mc(M1PWM,M1IN1,M1IN2,M2PWM,M2IN1,M2IN2);

MPU6050 *gyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t temp;
double scaleAcc = 16384.0; // 2g, 8196.0 = 4g, 8g, 16g
double scaleGyro = 250.0;

uint8_t deviceID = 0;
void setup()
{
  Serial.begin(9600); 

  gyro = new MPU6050();
  
  deviceID = gyro->getDeviceID();
  if (deviceID) {
      scaleAcc = (1 << (gyro->getFullScaleAccelRange() + 1)) / (16384.0 * 2);
      scaleGyro = (1 << (gyro->getFullScaleGyroRange() + 1)) / (250.0 * 2);
  }
}
double i = 0.0;
int j;

void loop()
{
//    if (deviceID) {
//        gyro->getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
//        dumpGyro(ax,ay,az,gx,gy,gz);
//    } else {
//        Serial.print("Gyro not working: Device ID="); Serial.print(gyro->getDeviceID());
//        Serial.print("\n");
//    }

    j = sin(i) * 100;
    
    Serial.print("\nj = "); Serial.print((double)j);
            
    mc.setSpeed(j,j);
    
    i += 0.01;

    delay(50);
}

void dumpGyro(int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz)
{
    Serial.print("ax=");   Serial.print((double)ax*scaleAcc);
    Serial.print("\tay="); Serial.print((double)ay*scaleAcc);
    Serial.print("\taz="); Serial.print((double)az*scaleAcc);
    //Serial.print("\ta scale="); Serial.print(gyro->getFullScaleAccelRange());
    
    Serial.print("\tgx="); Serial.print((double)gx*scaleGyro);
    Serial.print("\tgy="); Serial.print((double)gy*scaleGyro);
    Serial.print("\tgz="); Serial.print((double)gz*scaleGyro);
    //Serial.print("\tg scale="); Serial.print(gyro->getFullScaleGyroRange());

    //Serial.print("\ttemp="); Serial.print(temp);
    Serial.print("\tDevice="); Serial.print(gyro->getDeviceID());
    Serial.print("\n");    
}
