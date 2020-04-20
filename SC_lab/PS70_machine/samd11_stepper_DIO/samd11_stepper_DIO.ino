/*
Stepper program.  Input pins for direction and step.  Steps when step-pin goes high.
Make sure that the incoming digital signal is < 3.5 volts to protect ATSAM chip.
*/


int Aplus = 15;
int Aminus = 14;
int Bplus = 8;
int Bminus = 5;
int led1_pin = 2;
int led2_pin = 4;

int step_pin = 30;      //pin 3 of the 2x2 header
int dir_pin = 31;       //pin 4 of the 2x2 header
uint16_t step_count = 0;

void setup() {  
  Serial.begin(0);      //the USB serial, for monitoring the step number.
  pinMode(Aplus, OUTPUT);
  pinMode(Aminus, OUTPUT);
  pinMode(Bplus, OUTPUT);
  pinMode(Bminus, OUTPUT);
  pinMode(step_pin, INPUT_PULLDOWN);
  pinMode(dir_pin, INPUT_PULLDOWN);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);

//
//Following are the functions that energize the coils for driving.  They are executed in positive or negative sequence
//
    
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
  
  while(!digitalRead(step_pin)){      //wait for step pin to go high.
    ;} 
    
  digitalWrite(led1_pin,HIGH);
  all_off();                          //turn off coils before sending new step.

  if (digitalRead(dir_pin)){      //check direction.
  digitalWrite(led2_pin,HIGH);
  step_count --;
  }
  else{
    step_count ++;
    digitalWrite(led2_pin,LOW);
  }
  
  
  step_count = step_count%4;
  Serial.println(step_count); 
  
  if (step_count == 0) pulse_0();
  if (step_count == 1) pulse_1();
  if (step_count == 2) pulse_2();
  if (step_count == 3) pulse_3();  
  delay(2);
  digitalWrite(led1_pin,LOW);
  
 }
