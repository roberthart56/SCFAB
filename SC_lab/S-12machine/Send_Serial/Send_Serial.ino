byte count=0;

void setup() {
    Serial.begin(115200);              //This is the USB serial.
  }

void loop() {
   Serial.write(count);
   delay(500);
   count++;
}
