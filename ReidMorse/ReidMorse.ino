
unsigned long i;
char x;
int z;
void setup()
{
  i = 1;
  Serial.begin(9600);
  z = 2;
}

void loop()
{
  if (Serial.available()  )  {
    x = Serial.read();
    Serial.print("x = ");
    Serial.print(x);
    Serial.print("\n");
    if (x == 'r') {

      i = 1;

    }
    if (x == 'w') {
      z = z + 1;
    }
    if (x == 's') {
      z = z - 1;
    }
    if (x == 'd'){
      z = 0;
    }
    
    Serial.print("x = ");
    Serial.print(x);
    Serial.print("\n");
  }
  Serial.print("hi ");
  Serial.print(i);
  i = i + z;
  Serial.print(" \n");
  delay(200);
  if (i == 0) {
    i = 1;
  }
}

