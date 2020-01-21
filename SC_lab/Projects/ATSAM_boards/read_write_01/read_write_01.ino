int read_value;
void setup() {
 
}

void loop() {
  read_value = analogRead(A0);
  analogWrite(A1, read_value);
}
