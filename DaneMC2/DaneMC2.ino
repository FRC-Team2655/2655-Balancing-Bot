byte i;

void setup()
{
  i = 50;
  Serial.begin(9600); 
}

char x;

#define CR "\n"

void loop()
{
   
  if (Serial.available () ) {
    x = Serial.read();
  Serial.print("x = ");
  Serial.print(x); 
  Serial.print("\n"); 
  }
  Serial.print("hi
 
 
  i = i - 1; 
  
  delay(200);
}

