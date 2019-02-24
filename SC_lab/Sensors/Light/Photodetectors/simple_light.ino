void setup() {
  pinMode(14, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  int value = analogRead(A0);
  Serial.println(value);

}
