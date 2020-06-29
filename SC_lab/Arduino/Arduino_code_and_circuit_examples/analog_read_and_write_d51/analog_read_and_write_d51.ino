
/*  Simple program to read 10k points, store in RAM
 * and play back using analogWrite. records about a second.
 * RAM is 192KByte,so there should be room for about
 * ten seconds at this rate!
 * 
 * Use the Flash memory for storage of more data.  See Arduino
 * library for use of Flash.
 */



int data_array[10000];
int output_pin = 7;

void setup() {
  Serial.begin(0);
  pinMode(output_pin, OUTPUT);
}

void loop() {
  digitalWrite(output_pin, HIGH);     //to indicate start of recording.
  for (int i=0; i<10000; i++){
    data_array[i]= analogRead(A0);    //record voltage
    delayMicroseconds(75);            //since read takes ~25 microseconds,should be about 100 microseconds per point.
  }

  digitalWrite(output_pin, LOW);      //to indicate end of recording.
  
  for (int i=0; i<10000; i++){
    analogWrite (A1,data_array[i]);     //playback
    delayMicroseconds(100);
  }
delay(1000);
}
