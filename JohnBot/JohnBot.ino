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
#define ROBOT_NAME "JohnBot"
#include <SoftwareSerial.h>

// Swap RX/TX connections on bluetooth chip
//   Pin 10 --> Bluetooth TX
//   Pin 11 --> Bluetooth RX
SoftwareSerial btSerial(10, 11); // RX, TX
#define BLUETOOTH_SPEED 9600 //57600 // 9600
void setup()
{
  Serial.begin(9600); 

  gyro = new MPU6050();
  
  deviceID = gyro->getDeviceID();
  if (deviceID) {
      scaleAcc = (1 << (gyro->getFullScaleAccelRange() + 1)) / (16384.0 * 2);
      scaleGyro = (1 << (gyro->getFullScaleGyroRange() + 1)) / (250.0 * 2);
  }
  
  Serial.println("Starting config");
  btSerial.begin(BLUETOOTH_SPEED);
  delay(1000);

  // Should respond with OK
  btSerial.print("AT");
  waitForResponse();

  // Should respond with its version
  btSerial.print("AT+VERSION");
  waitForResponse();

  // Set pin to 0000
  btSerial.print("AT+PIN0000");
  waitForResponse();

  // Set the name to ROBOT_NAME
  btSerial.print("AT+NAME");
  btSerial.print(ROBOT_NAME);
  waitForResponse();

  
  btSerial.print("AT+BAUD7"); // Set baudrate to 57600
  waitForResponse();

  Serial.println("Done!");
}
void waitForResponse() {
    delay(1000);
    while (btSerial.available()) {
      Serial.write(btSerial.read());
    }
    Serial.write("\n");
}

void loop()
{
//    gyro->getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
//    
//    mc.setSpeed(60,60);
    
    
    delay(50);
}
