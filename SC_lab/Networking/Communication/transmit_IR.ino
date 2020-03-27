void setup() {
 pinMode(12, OUTPUT);
}

void loop() {
 digitalWrite(12, HIGH);
 delay(250);   //keep on for .25 sec.
 digitalWrite(12, LOW);
 delay(250);   //keep off for .25 sec.

}
