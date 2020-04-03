/*
Stepper program.  Input pins for direction and step.  Steps when step-pin goes high.
 
*/
int delay_time=10000;
int Aplus = 15;
int Aminus = 14;
int Bplus = 8;
int Bminus = 5;

int led1_pin = 2;
int led2_pin = 4;
uint16_t step_count = 0;

void setup() {
  SerialUSB.begin(0);
  Serial1.begin(115200);
  
  pinMode(Aplus, OUTPUT);
  pinMode(Aminus, OUTPUT);
  pinMode(Bplus, OUTPUT);
  pinMode(Bminus, OUTPUT);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);

  digitalWrite(led1_pin, HIGH);
  digitalWrite(led2_pin, HIGH);
}

void pulse_0(){
  digitalWrite(Aplus,HIGH);
  digitalWrite(Bplus,HIGH);
}

void pulse_1(){
  digitalWrite(Aminus,HIGH);
  digitalWrite(Bplus,HIGH);
}

void pulse_2(){
  digitalWrite(Aminus,HIGH);
  digitalWrite(Bminus,HIGH);
}

void pulse_3(){
  digitalWrite(Aplus,HIGH);
  digitalWrite(Bminus,HIGH);
}

void all_off() {
  digitalWrite(Aplus,LOW);
  digitalWrite(Aminus,LOW);
  digitalWrite(Bplus,LOW);
  digitalWrite(Bminus,LOW);
}

void loop() {
  
  while (!Serial1.available()){
  }
   int rec_byte =  Serial1.read();
   
  all_off();                          //turn off coils before sending new step.

 step_count++;
  
 
  SerialUSB.println(rec_byte);

  delay_time = map(rec_byte, 0,255,100000,0);
  step_count = step_count%4;
   
  
  if (step_count == 0) pulse_0();
  if (step_count == 1) pulse_1();
  if (step_count == 2) pulse_2();
  if (step_count == 3) pulse_3();  
  delayMicroseconds(delay_time);
  
 }
