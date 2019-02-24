int i=200;
  
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
      delay(50);
      if( i >= 2000)
      {
       while(i <= 2000)
       {
          tone(5, i, 100);
          Serial.print (i);
          Serial.println ();
          i = i - 50;
          delay(50);
          if ( i == 200 )
          {
            break;
          }
        }
      }
}
