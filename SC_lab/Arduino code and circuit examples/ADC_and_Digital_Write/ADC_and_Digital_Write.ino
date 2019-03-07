/*This is a very simple bit of code that can apply to a huge variety of inputs and outputs
 * We are reading a 10-bit (0-1023 aka 0 to 2^8-1) input on pin A0 and then, based on that value,
 * at an arbitrary middle of the road value of 500, setting a single output pin to the value of
 * "HIGH" or "LOW" corresponding (closely) to logic levels of a 5V (1) or 0V (0).  Also in the 
 * lines based on the Serial.XXX we are enabling raw data from the sensorPin, A0, to be communicated 
 * to the controlling PC via the serial port and viewed in the Arduino IDE serial monitor.*/
 
/*Read in a 10-bit value on pin A0, put a HIGH or LOW digital output on pin A1*/
int sensorPin = A0;
int outputPin = A1;

void setup()
{
  pinMode(outputPin, OUTPUT);                 //Pins are by default inputs, this sets it up to output
  Serial.begin(115200);                       //Enables serial communiction (baud rate may have to be changed in the serial monitor
}

void loop() {
  int sensorValue = analogRead(sensorPin);    //Reads in the 10-bit analog voltage on pin A0 as defined as 'sensorPin'
  Serial.print ("Sensor reading: ");          //This will print the text to the serial port and thus the serial monitor
  Serial.println (sensorValue);               //the *--ln will print out our A0 value and also 'hit a return' so it goes to the next line
  /*if (sensorValue < 500)
  {
    digitalWrite(outputPin, LOW);             //If our ADC (Analog to Digital) value is under 500 we put a logic 0 out ot the A1, outputPin
  }
    else if (sensorValue > 500)
    {
      digitalWrite(outputPin, HIGH);          //Otherwise if it's over 500 we output a logic 1 (5V) to the outputPin A1
    }   
  delay(200);*/
}
