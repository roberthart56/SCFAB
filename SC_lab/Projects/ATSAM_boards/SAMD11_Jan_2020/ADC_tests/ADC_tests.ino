void setup() {
  SerialUSB.begin(0);

}

void loop() {
  int value = analogRead(5);
  SerialUSB.println(value);
  delay(100);
}
