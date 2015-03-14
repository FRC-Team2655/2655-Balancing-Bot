
#include "ck1122.h"

ck1122::ck1122( int pwmA, int in1, int in2
        , int pwmB, int in3, int in4)
        : mpwmA(pwmA), min1(in1), min2(in2)
        , mpwmB(pwmB), min3(in3), min4(in4)
{
    pinMode(mpwmA, OUTPUT); digitalWrite(mpwmA, LOW);
    pinMode(mpwmB, OUTPUT); digitalWrite(mpwmB, LOW);
    pinMode(min1, OUTPUT); digitalWrite(min1, LOW);
    pinMode(min2, OUTPUT); digitalWrite(min2, LOW);
    pinMode(min3, OUTPUT); digitalWrite(min3, LOW);
    pinMode(min4, OUTPUT); digitalWrite(min3, LOW);
}


void ck1122::setSpeed(int speeda, int speedb)
{
    if (speeda > 0) {
        digitalWrite(min1, HIGH);
        digitalWrite(min2, LOW);
    } else {
        digitalWrite(min1, LOW);
        digitalWrite(min2, HIGH);
    }
    
    if (speedb > 0) {
        digitalWrite(min3, HIGH);
        digitalWrite(min4, LOW);
    } else {
        digitalWrite(min3, LOW);
        digitalWrite(min4, HIGH);
    }
	
    analogWrite(mpwmA, abs(speeda));
    analogWrite(mpwmB, abs(speedb));
}
