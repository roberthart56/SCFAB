/*
Stepper program to control stepper board with digital IO control.  Ouput pins:  step_comm makes motor step on rise.
dir_comm determines motor direction.  Make sure these signals are , ~3.5 V for ATSAM motor driver boards.
*/



int step_comm = 8;      //pin 3 of the 2x2 header
int dir_comm = 9;       //pin 4 of the 2x2 header
uint16_t step_count = 0;
boolean dir = false;

void setup() {  
  Serial.begin(0);      //the USB serial, for monitoring the step number.

  pinMode(step_comm, OUTPUT);
  pinMode(dir_comm, OUTPUT);

}


void loop() {
  
    dir = !(dir);   //switch direction.
    digitalWrite(dir_comm,dir);
    
    for(int i = 0; i < 50; i++){ 
      digitalWrite(step_comm,HIGH);
      delay(1);
      digitalWrite(step_comm,LOW);
      delay(20);    //delay to allow motor to step and settle.
    }  //end i loop

 }   //end of loop function.
