
int delta_x = 15;





void setup() {
   Serial1.begin(230400);
   Serial.begin(0);
}

void step(int dx, int dy){        
  int delta_1;
  int delta_2;
  uint8_t byte_1;
  uint8_t byte_2;
  uint8_t step_1_dir;
  uint8_t step_2_dir;
  
  delta_1=dx+dy;
  delta_2 =dx-dy;

  if (delta_1 >= 0) step_1_dir = 1;
  else step_1_dir = 0;

  if (delta_2 >= 0) step_2_dir = 1;
  else step_2_dir = 0;
  
  byte_1 = 128 * step_1_dir + 16 + abs(delta_1);
  byte_2 = 128 * step_2_dir+ 2*16 + abs(delta_2);
  Serial1.write(byte_1);
  Serial1.write(byte_2); 
}


void loop() {

  
  int step_delay = 50;
  int max_steps = 100;

  for (max_steps = 100; max_steps>0; max_steps -= 10){
    for (int i=0; i< max_steps; i++){
    step(5,0);
    delay(step_delay);
    }
  
    for (int i=0; i<max_steps; i++){
    step(0,5);
    delay(step_delay);
    }
  
    for (int i=0; i<max_steps-5; i++){
    step(-5,0);
    delay(step_delay);
    }
  
    for (int i=0; i<max_steps-5; i++){
    step(0,-5);
    delay(step_delay);
    }
    } 
  }
