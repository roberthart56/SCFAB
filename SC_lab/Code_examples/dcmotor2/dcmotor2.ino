void setup() 
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
  int i=0;
  
  while(i < 150)
  {
    Serial.print(i);
    Serial.println();
    analogWrite(5,i);
    digitalWrite(6,HIGH);
    i++;
    delay(15);
  }

  while(i > 0)
  {
    Serial.print(i);
    Serial.println();
    analogWrite(5,i);
    digitalWrite(6,HIGH);
    i--;
    delay(15);
  }

  i=150;

  while(i > 0)
  {
    Serial.print(i);
    Serial.println();
    digitalWrite(5,HIGH);
    analogWrite(6,i);
    i--;
    delay(15);
  }

  while(i < 150)
  {
    Serial.print(i);
    Serial.println();
    digitalWrite(5,HIGH);
    analogWrite(6,i);
    i++;
    delay(15);
  }

}
