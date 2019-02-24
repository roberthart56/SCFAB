// Pins
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
