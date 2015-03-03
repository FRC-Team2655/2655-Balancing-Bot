

const int MotorAPWM = 13;
const int MotorBPWM = 12;

const int groundpin = 52;             // analog input pin 4 -- ground
const int powerpin = 53;              // analog input pin 5 -- voltage

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


}



class CK1122 {
    private:
        int mena, min1, min2;
        int menb, min3, min4;
        
    public:
        CK1122( int ena, int in1, int in2
               ,int enb, int in3, int in4);
            
        ~CK1122() {};
        
        void setSpeed(int speeda, int speedb);
};

CK1122::CK1122( int ena, int in1, int in2
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


void CK1122::setSpeed(int speeda, int speedb)
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
