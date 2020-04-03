/*
Stepper program.  Input pins for direction and step.  Steps when step-pin goes high.
 
*/
const int Aplus = 15;
const int Aminus = 14;
const int Bplus = 8;
const int Bminus = 5;

const int led1_pin = 2;
const int led2_pin = 4;
const int dig1_pin = 30;
const int dig2_pin = 31;

uint16_t step_count = 0;


void setup() {
  SerialUSB.begin(0);
  pinMode(Aplus, OUTPUT);
  pinMode(Aminus, OUTPUT);
  pinMode(Bplus, OUTPUT);
  pinMode(Bminus, OUTPUT);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(dig1_pin, INPUT);
  pinMode(dig2_pin, INPUT);

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
  int delay_time = 5000;  //microseconds

  if (digitalRead(dig1_pin)) delay_time = 20000;
  else delay_time = 3000;
  
  all_off();                          //turn off coils before sending new step.

 step_count++;
  
  
  step_count = step_count%4;
  SerialUSB.println(step_count); 
  
  if (step_count == 0) pulse_0();
  if (step_count == 1) pulse_1();
  if (step_count == 2) pulse_2();
  if (step_count == 3) pulse_3();  
  delayMicroseconds(delay_time);
  
 }
