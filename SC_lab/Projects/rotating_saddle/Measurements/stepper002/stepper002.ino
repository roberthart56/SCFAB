/*
Stepper program.  Functions are all self-contained.
Feb 1, 2021.  Modify to use l298 stepper driver and potentiometer input (A0,A2,A4)
to vary speed from 0 to 4 RPS for saddle measurements.
*/

int Aplus = 11;
int Aminus = 10;
int Bplus = 9;
int Bminus = 8;

//int led1_pin = 2;
//int led2_pin = 4;
uint16_t step_count = 0;

void setup() {
  //Serial.begin(9600);
  pinMode(Aplus, OUTPUT);
  pinMode(Aminus, OUTPUT);
  pinMode(Bplus, OUTPUT);
  pinMode(Bminus, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A4, OUTPUT);
  //pinMode(led1_pin, OUTPUT);
  //pinMode(led2_pin, OUTPUT);

  //digitalWrite(led1_pin, 0);
  //digitalWrite(led2_pin, 0);
  digitalWrite (A0, 0);  //low end of pot
  digitalWrite (A4, 1);   //high end of pot.
  
}

void pulse_0(){
  digitalWrite(Aplus,1);
  digitalWrite(Bplus,1);
}

void pulse_1(){
  digitalWrite(Aminus,1);
  digitalWrite(Bplus,1);
}

void pulse_2(){
  digitalWrite(Aminus,1);
  digitalWrite(Bminus,1);
}

void pulse_3(){
  digitalWrite(Aplus,1);
  digitalWrite(Bminus,1);
}

void all_off() {
  digitalWrite(Aplus,0);
  digitalWrite(Aminus,0);
  digitalWrite(Bplus,0);
  digitalWrite(Bminus,0);
}

void loop() {
  int int_val = analogRead(A2);
  int freq = map (int_val,0,1023, 1000, 6000);  //freq in rpsX1000
  int delay_time = 5000000/freq;
  all_off();                          //turn off coils before sending new step.

 step_count++;
  
  
  step_count = step_count%4;
  //Serial.println(step_count); 
  
  if (step_count == 0) pulse_0();
  if (step_count == 1) pulse_1();
  if (step_count == 2) pulse_2();
  if (step_count == 3) pulse_3(); 
   
  delayMicroseconds(delay_time);
  
 }
