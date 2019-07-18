#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(7,5);



void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop() {
  long sensorValue = Sensor.capacitiveSensor(300);
  Serial.println(sensorValue);
 // if (sensorValue > 100) analogWrite(11,100);
  //else analogWrite(11,0);
  delay(10);




}
