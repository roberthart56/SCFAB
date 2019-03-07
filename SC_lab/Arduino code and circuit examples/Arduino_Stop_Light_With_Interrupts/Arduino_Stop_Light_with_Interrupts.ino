void setup() 
{
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), ALL_ON_ISR, RISING);
}
void loop() 
{
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A0, HIGH);
  delay(750);
  digitalWrite(A0, LOW);
  digitalWrite(A2, HIGH);
  delay(750);
  digitalWrite(A2, LOW);
  digitalWrite(A1, HIGH);
  delay(750);
  digitalWrite(A1, LOW);
}

void ALL_ON_ISR()
{
 digitalWrite(A0, HIGH);
 digitalWrite(A1, HIGH);
 digitalWrite(A2, HIGH);
 delay(500000);
}
