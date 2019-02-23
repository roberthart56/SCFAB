

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  // read the input on analog pin 0:
  int phototrans = analogRead(A0);
  int pot = analogRead(A1);

  if (phototrans > pot) digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(200);              // wait for a second
}
