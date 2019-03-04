/*Simple program to put a looped tone to a speaker and data to the serial port*/
int i=0;
  
void setup() 
{
  pinMode(5, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
      tone(5, i , 100);
      Serial.print (i);
      Serial.println ();
      i = i+50;
      delay(100);
      if( i > 2000)
      {
        i = 0;
      }
}
