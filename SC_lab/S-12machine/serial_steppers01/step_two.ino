void step_two(int num_steps, int steps_1, int steps_2){

for(int i=0; i<num_steps; i++){
  // step one step:
  Stepper1.step(steps_1);
  Stepper2.step(steps_2);
  delay(10);
  }

}
