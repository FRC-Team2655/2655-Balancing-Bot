#ifndef CK1122
#define CK1122

#include "Arduino.h"

class ck1122 {
    private:
        int mena, min1, min2;
        int menb, min3, min4;
        
    public:
		ck1122();
        ck1122( int ena, int in1, int in2
               ,int enb, int in3, int in4);
            
        ~ck1122() {};
        
        void setSpeed(int speeda, int speedb);
};
#endif // CK1122
