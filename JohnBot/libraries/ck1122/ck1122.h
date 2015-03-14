#ifndef CK1122
#define CK1122

#include "Arduino.h"

class ck1122 {
    private:
        int mpwmA, min1, min2;
        int mpwmB, min3, min4;
        
    public:
		ck1122();
        ck1122( int pwmA, int in1, int in2
               ,int pwmB, int in3, int in4);
            
        ~ck1122() {};
        
        void setSpeed(int speeda, int speedb);
};
#endif // CK1122
