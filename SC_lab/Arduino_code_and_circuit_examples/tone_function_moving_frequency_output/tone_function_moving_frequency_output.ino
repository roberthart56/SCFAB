/*This is a fairly simple code to have the Arduino output a rising and falling set of sounds (NOISE!?) with the tone()function,
 * without any input.  If the code was more elegant (and not 10 lines) declaring more global variables - for example
 *  you might say max_frequency = "XXXX" in this case, and use that in place of the hard written 2000's. For a program
 *  of a larger scope, where you wished to have the frequency go to 5000 and had that number in more than than 2 places, 
 *  it would make sense to follow good programming practice and declare max_frequency as a variable. 
  */

int i=200;                //Counting variable in this case it will be used to set a 200Hz start to our loop
  
void setup() 
{
  pinMode(5, OUTPUT);     //Pins are by default input, this sets the pin to output a signal
  Serial.begin(115200);   //Rate of data transfer - may have to be adjusted to match in the serial monitor
}

void loop() 
{
      tone(5, i , 100);    //Arguments: (pin, our counting variable, and the milliseconds over which tone() will play)
      Serial.print (i);    //Prints the current 'i' to the serial port so you can see it with the serial monitor
      Serial.println ();   //Just a "carriage return" if anyone remebers typewriters - it just makes a space between .print outputs
      i = i+50;            //Incrementing the count by 50Hz
      delay(50);           //50 ms delay unil we get to ....
      if( i >= 2000)       //... the point where we have incremented 'i' to 2000Hz, this code won't happen until then
      {
       while(i <= 2000)    //Once we do get to 2000Hz with our counting variable we enter this loop and stay here for a bit
       {
          tone(5, i, 100);  //This is the same as the "main" part of the loop()
          Serial.print (i);
          Serial.println ();
          i = i - 50;       //The difference is now we are decrementing the frequency by 50Hz per iteration
          delay(50);
          if ( i == 200 )   //Once the counting variable reaches the low frequency of 200...
          {
            break;          //The break command will get us out of the loop and return to the start of the main loop
          }
        }
      }
}
