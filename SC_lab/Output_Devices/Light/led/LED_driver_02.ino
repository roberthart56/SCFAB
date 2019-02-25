/*
  LED driver.  
  LED from pin9 to GND.
  analogWrite controls output from pin 9.
  0 is full off.
  255 is fully on.
  
  This example code is in the public domain.
*/
void setup() {         //Nothing needs to be set up!
}





void loop() {
 analogWrite(9,0);   // Turn off LeD on pin 9.
  delay(1000);  
 analogWrite(9,130);   // Turn on LeD on pin 9 at medium intensity.
  delay(1000);                      
 analogWrite(9,255);       // Turn on LeD on pin 9 at highest intensity.                
  delay(1000);
  
}
