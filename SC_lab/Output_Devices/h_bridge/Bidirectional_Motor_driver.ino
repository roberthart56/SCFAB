/*
 Bidirectional motor driver uses the dual H-bridge driver module.
 Inputs to the module on pins 9 and 10.
 VCC on the driver module connected to Vin on the Arduino board.
 GND on the module to GND on the Arduino.

 Driver channels are fully on when inputs are LOW.
 Use AnalogWrite to control motor speed. 
 0 is full on.  255 is full off.
 
 
  This example code is in the public domain.
*/
void setup() {
  pinMode(9, OUTPUT); //set pin 9 as an output pin.
  pinMode(10, OUTPUT); //set pin 10 as an output pin.

}





void loop() {
  
digitalWrite(10,HIGH);  //  Turn off Counterclockwise input.
analogWrite(9, 100);   // Turn on motor clockwise.
 delay(500);

 digitalWrite(9,HIGH);  //  Turn off Clockwise input.
analogWrite(10, 100);   // Turn on motor counterclockwise.
 delay(500);

  
}
