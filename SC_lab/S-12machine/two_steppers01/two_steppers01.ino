
/*
 Stepper Motor Control - one step at a time  

 Uses stepper.h library.

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor will step one step at a time, very slowly.  You can use this to
 test that you've got the four wires of your stepper wired to the correct
 pins. If wired correctly, all steps should be in the same direction.

 Use this also to count the number of steps per revolution of your motor,
 if you don't know it.  Then plug that number into the oneRevolution
 example to see if you got it right.

 Created 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper Stepper1(stepsPerRevolution, 11, 10, 9, 8);
Stepper Stepper2(stepsPerRevolution, 7, 6, 5, 4);



void setup() {
  //Serial.begin(9600);    // initialize the serial port:
}

void loop() {
int N = 400;      //number of steps

  for(int i=0; i<N; i++){
  // step one step:
  Stepper1.step(1);
  Stepper2.step(1);
  delay(10);
  }

  for(int i=0; i<N; i++){
  // step one step:
  Stepper1.step(-1);
  Stepper2.step(1);
  delay(10);
  }

  for(int i=0; i<N; i++){
  // step one step:
  Stepper1.step(-1);
  Stepper2.step(-1);
  delay(10);
  }

  for(int i=0; i<N; i++){
  // step one step:
  Stepper1.step(1);
  Stepper2.step(-1);
  delay(10);
  }
}
