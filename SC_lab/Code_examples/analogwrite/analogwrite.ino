// Pins
int sensorPin = A0;
int outputPin = 3;

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
    analogWrite(outputPin, 10);
  }
  else if (sensorValue > 500)
  {
    analogWrite(outputPin, 40);
  }
  // Wait
  delay(200);

}
