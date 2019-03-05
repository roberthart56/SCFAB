int read_high;
int read_low;
int diff;
int sum;
int N_samples = 100;

void setup() {
pinMode(4,OUTPUT);
Serial.begin(9600);
}

void loop() {
 
 sum = 0;

 for (int i = 0; i < N_samples; i++){
   digitalWrite(4,HIGH);
   read_high = analogRead(A0);
   digitalWrite(4,LOW);
   read_low = analogRead(A0);
   diff = read_high - read_low;
   sum += diff;
 }
Serial.println(sum);
//delay(100);

  
 
}
