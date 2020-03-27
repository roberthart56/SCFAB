
int ledPin = 11;  //Put LED between pin 11 and GND
int signalPin = 8;   //Signal from recieve module goes to signalPin


void setup() {
pinMode(signalPin, INPUT);  //setup signalPin to read high or low.
}

void loop() {  
  if (digitalRead(signalPin) == LOW) analogWrite(ledPin,0);
  else analogWrite(ledPin,50);
}
