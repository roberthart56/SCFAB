/*
Stepper program.  Input pins for direction and step.  Steps when step-pin goes high.
Make sure that the incoming digital signal is < 3.5 volts to protect ATSAM chip.
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
  
  digitalWrite(dir_comm,dir);


for(int i = 0; i < 100; i++){ 
  digitalWrite(step_comm,HIGH);
  delay(1);
  digitalWrite(step_comm,LOW);
  delay(30);
}

dir = !(dir);   //switch direction.


 }   //end of loop.
