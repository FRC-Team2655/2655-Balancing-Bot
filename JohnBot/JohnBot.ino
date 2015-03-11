#include <ck1122.h>


#include <I2Cdev.h>

#include <Wire.h>

#include <helper_3dmath.h>
#include <MPU6050.h>

//#include <MPU6050_6Axis_MotionApps20.h>
//#include <MPU6050_9Axis_MotionApps41.h>





const int MotorAPWM = 13;
const int MotorBPWM = 12;

const int groundpin = 52;             // analog input pin 4 -- ground
const int powerpin = 53;              // analog input pin 5 -- voltage

ck1122 mc(1,2,3,4,5,6);

MPU6050 *gyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;


void setup()
{
  Serial.begin(9600); 

/*
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
*/
  gyro = new MPU6050();
  gyro->initialize();
}

void loop()
{
    gyro->getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
    Serial.print("ax="); Serial.print(ax);
    Serial.print("   ay="); Serial.print(ay);
    Serial.print("   az="); Serial.print(az);
    Serial.print("   gx="); Serial.print(gx);
    Serial.print("   gy="); Serial.print(gy);
    Serial.print("   gz="); Serial.print(gz);
    Serial.print("\n");    
    //mc.setSpeed(1,2);

}

