
int i;
char t;
void setup()
{
  i = 9600;
  Serial.begin(9600);
  t = 1;
  
  
}

char x;
void loop()
{
#define CR " n"

  if (Serial.available() )  {
    x = Serial.read();
    Serial.print("x = ");
    Serial.print(x);
    Serial.print("\n");
    if (x == 'r') {
      i = 9600;
    }
   if (x == '1') t = 1;
   
   if (x == '2') t = 2;
   }

  Serial.print("hi ");

  Serial.print(i);

  Serial.print("\n");

  i = i + t;

  delay(200);
}

