#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(7,9);

void setup() {
  Serial.begin(9600);
}

void loop() {
  long sensorValue = Sensor.capacitiveSensor(1000);      //Change the number of samples to get the required timing and sensitivity.
  //delay(10);
  Serial.write(sensorValue/4);
}
