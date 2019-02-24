/*
  AnalogReadSerial
  Reads an analog input on pin A0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  
  This example code is in the public domain.
*/
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}





void loop() {
  
  int sensorValue = analogRead(A0);   // read the input on analog pin 0
                                      // "sensorValue" is just a variable name I made up.
                                      
  Serial.println(sensorValue);        // send the result out to the computer.
 delay(100);                          // Delay 100 milliseconds  = 0.1 second.
                                      //slows it down so we can tell what's going on.
 
  
}
