int i = 0; //counting variable

void setup() 
{
  DDRD = 255; //Set the entire D register to output pin mode
}

void loop() 
{
  while(i <= 8)
  {
      PORTD = (1 << i); //Output a 1 (HIGH) to pin at 'i'
      i = i + 1;        //Increment the counting variable
      delay(150);
  } 
  while(i >= 0)
    {
      PORTD = (1 << i); //Output a 1 (HIGH) to pin at 'i'
      i = i - 1;        //Decrement the counting variable
      delay(150);
    }
}
