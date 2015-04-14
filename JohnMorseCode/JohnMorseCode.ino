
int i;

void setup()
{
  i = 1;
  Serial.begin(9600);
}

char x;

#define CR "\n"

char v = 0;

void loop()
{
  if (Serial.available() ) {
    x = Serial.read();
    Serial.print("x = ");
    Serial.print(x);
    Serial.print("\n");
    if (x == 'r') {
      i = 1;
      v = 0;
    }
    if (x == '1') v = 1;

    if (x == '2') v = 2;
  }

  Serial.print("hi ");

  Serial.print( i );

  Serial.print("\n");

  i = i + v;

  delay(200);
}

