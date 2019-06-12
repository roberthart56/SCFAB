
int motor_pin = A1;   //motor is controlled through A1 pin.
int sensor_pin = A0;  // light sensor (phototransistor) signal on A0.

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(motor_pin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input
  int sensorValue = analogRead(sensor_pin);
  // print out the value, for diagnostic purposes.
  Serial.println(sensorValue);
  if (sensorValue < 50) {digitalWrite(motor_pin, HIGH);}
  else{digitalWrite(motor_pin, LOW);}
}
