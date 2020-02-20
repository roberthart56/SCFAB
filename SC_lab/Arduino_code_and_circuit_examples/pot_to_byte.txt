int i=200;
  
void setup() 
{
  Serial.begin(115200);
  DDRD=255;
}

void loop() 
{
      int input = analogRead(A0);
      int val = map(input, 0, 1023, 0, 255);
      Serial.print (val);
      Serial.println ();
      PORTD=val;
}

/*
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

}*/
