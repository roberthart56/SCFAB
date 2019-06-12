
int motor_pin = A1;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(motor_pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(motor_pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(motor_pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
