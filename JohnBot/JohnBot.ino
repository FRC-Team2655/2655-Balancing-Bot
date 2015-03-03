#include "ck1122.h"




const int MotorAPWM = 13;
const int MotorBPWM = 12;

const int groundpin = 52;             // analog input pin 4 -- ground
const int powerpin = 53;              // analog input pin 5 -- voltage

ck1122 mc(1,2,3,4,5,6);

void setup()
{
  Serial.begin(9600); 

  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
}

void loop()
{
    mc.setSpeed(1,2);

}

