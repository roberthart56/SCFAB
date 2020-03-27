void setup() {
pinMode(10,OUTPUT);  //set up pin 10 as output to transmit module
}

void loop() {
 digitalWrite(10, HIGH);
 delay (200);
 digitalWrite(10, LOW);
 delay (200);
 

}
