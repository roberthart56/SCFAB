/*
  LED driver.  
  LED from pin9 to GND.
  digitalWrite controls output from pin 9.
   
  This example code is in the public domain.
*/
void setup() {
  pinMode(9, OUTPUT); //set pin 9 as an output pin.
 
}





void loop() {
 digitalWrite(9, HIGH);   // Turn off LeD on pin 9.
  delay(500);  
 digitalWrite(9, LOW);   // Turn on LeD on pin 9.
  delay(500);
}
