/*
 Variable_Motor_driver uses the dual H-bridge driver module.
 Inputs to the module on pin 9.
 VCC on the driver module connected to Vin on the Arduino board.
 GND on the module to GND on the Arduino.

 Driver channel is fully on when inputs are LOW.
 Use AnalogWrite to control motor speed. 
 0 is full on.  255 is full off.
  
This example code is in the public domain.
*/
void setup() {
                //Nothing to set up.
}





void loop() {
 int sensVal = analogRead(A0);
 int pwm_var = sensVal/4;
  
 analogWrite(9, pwm_var);   // Turn motor on according to value read from A0.
 delay(100);

  
}
