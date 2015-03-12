
/*
  This code is desinged to control a two wheeled robot and keep it upright.
 */

#include "I2Cdev.h"
#include "MPU6050.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 accelgyro;
//MPU6050 accelgyro(0x69); // <-- use for AD0 high
int16_t ax, ay, az;
int16_t gx, gy, gz;


const int MotorA1 = 13;
const int MotorA2 = 12;
const int MotorB1 = 11;
const int MotorB2 = 10;
const int groundpin = 52;             // analog input pin 4 -- ground
const int powerpin = 53;              // analog input pin 5 -- voltage

double convX;
double convY;
double convZ;
double PWMFval;
double PWMRval;

void setup()
{
  // initialize the serial communications:
  Serial.begin(9600); 
  // Provide ground and power by using the analog inputs as normal
  // digital pins.  This makes it possible to directly connect the
  // breakout board to the Arduino.  If you use the normal 5V and
  // GND pins on the Arduino, you can remove these lines.
  pinMode(groundpin, OUTPUT);

  pinMode(powerpin, OUTPUT);
  pinMode(MotorA1, OUTPUT); 
  pinMode(MotorA2, OUTPUT);
  pinMode(MotorB1, OUTPUT); 
  pinMode(MotorB2, OUTPUT);

  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
}

void loop()
{
  setMotorValues();
  
  moveMotors();

  serialOutput();

  delay(200);
}

void setMotorValues(){
    // read raw accel/gyro measurements from device
    // the value we want is ax
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    convX = (ax/6.275) - (14399.875/6.275);
}

void moveMotors(){
	analogWrite(MotorA1, PWMFval);  
	analogWrite(MotorA2, PWMRval);
	analogWrite(MotorB1, PWMFval);  
	analogWrite(MotorB2, PWMRval);
}

void serialOutput(){
  // print the sensor values:
  Serial.print("X=");
  Serial.print(convX);
  // print a tab between values:
  Serial.print("\tY=");
  Serial.print(convY);
  // print a tab between values:
  Serial.print("\tZ=");
  Serial.print(convZ);
  // Serial.print("\t");
// 6.275
// x = y/m - b/m
  // Serial.print(PWMFval);
  // Serial.print("\t");

  // Serial.print(PWMRval);
  Serial.println();  
}
