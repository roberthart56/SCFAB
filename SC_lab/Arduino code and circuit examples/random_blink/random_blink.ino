void setup() 
{
  DDRD=255;
}

void loop() 
{
  PORTD=random(0,255);
  delay(100);
}
