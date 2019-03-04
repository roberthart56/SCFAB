/*Read in a 10-bit value on pin A0, put a HIGH or LOW digital output on pin A1*/
int sensorPin = A0;
int outputPin = A1;

void setup() {
    //serial
    pinMode(outputPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  //Reading
  int sensorValue = analogRead(sensorPin);
  //Display
  Serial.print ("Sensor reading: ");
  Serial.println (sensorValue);
  if (sensorValue < 500)
  {
    digitalWrite(outputPin, LOW);
  }
    else if (sensorValue > 500)
    {
    digitalWrite(outputPin, HIGH);
    }
  // Wait
  delay(200);

}
