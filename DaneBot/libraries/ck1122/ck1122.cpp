
#include "ck1122.h"

ck1122::ck1122( int ena, int in1, int in2
        , int enb, int in3, int in4)
        : mena(ena), min1(in1), min2(in2)
        ,menb(enb), min3(in3), min4(in4)
{
    pinMode(mena, OUTPUT);
    pinMode(menb, OUTPUT); 
    pinMode(min1, OUTPUT);
    pinMode(min2, OUTPUT); 
    pinMode(min3, OUTPUT);    
    pinMode(min4, OUTPUT);
}


void ck1122::setSpeed(int speeda, int speedb)
{
    if (speeda > 0) {
        digitalWrite(min1, HIGH);
        digitalWrite(min2,LOW);
    } else {
        digitalWrite(min1, LOW);
        digitalWrite(min2,HIGH);
    }
    analogWrite(mena, abs(speeda));
    
    if (speedb > 0) {
        digitalWrite(min3, HIGH);
        digitalWrite(min4,LOW);
    } else {
        digitalWrite(min3, LOW);
        digitalWrite(min4,HIGH);
    }
    analogWrite(menb, abs(speedb));
}
