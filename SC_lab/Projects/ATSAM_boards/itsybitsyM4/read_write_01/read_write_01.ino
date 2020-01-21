int read_value;
void setup() {
 Serial.begin(0);
}

void loop() {
  read_value = analogRead(A0);
  analogWrite(A1, read_value);
}
