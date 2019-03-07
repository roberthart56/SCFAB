void setup() 
{
  DDRD = 255; //Set the entire D register to output pin mode
}

void loop() 
{
  PORTD=random(0,255); //Random byte output to LED's on port D
  delay(250);
}
