
/*
 * xy_sketcher.ino  Rob Hart 1/8/20.  Code to create byte packets for stepper motor boards
 *to control an h-bot drawing machine as an "etch-a-sketch"
 */

int current_x = 0;    //calculated on the basis of steps sent.
int current_y = 0;    //calculated on the basis of steps sent.

void setup() {
   Serial1.begin(230400);     //uses USART on rx/tx pins.
   Serial.begin(0);           //USB serial
}
/*
 * Function to send stepper motor bytes based on requested x and y increments.
 */
void step(int dx, int dy){
  int delta_1;
  int delta_2;
  uint8_t byte_1;
  uint8_t byte_2;
  uint8_t step_1_dir;
  uint8_t step_2_dir;

  delta_1=dx+dy;        //This is the increment for motor 1, defined this way for h-bot geometry
  delta_2 =dx-dy;       //This is the increment for motor 2, defined this way for h-bot geometry

  //add more motors, or add code to send a command to another board, such as an 'end effector'.

  if (delta_1 >= 0) step_1_dir = 1;   //determine sign of steps for 1
  else step_1_dir = 0;

  if (delta_2 >= 0) step_2_dir = 1;   //determine sign of steps for 2
  else step_2_dir = 0;

  byte_1 = 128 * step_1_dir + 16 + abs(delta_1);    //this packs direction, address and step number into one byte. address = 1
  byte_2 = 128 * step_2_dir+ 2*16 + abs(delta_2);   //this packs direction, address and step number into one byte. address = 2
  Serial1.write(byte_1);
  Serial1.write(byte_2);
}


void loop() {
  int input_x;      //reading of ADC
  int setpoint_x;   //derived from ADC reading
  int deficit_x;   // difference between setpoint and calculated x

  int input_y;      //reading of ADC
  int setpoint_y;   //derived from ADC reading
  int deficit_y;   // difference between setpoint and calculated x

/*
 *Check x potentiometer, and calculate needed steps to match pen with requested x.
 */

input_x = analogRead(A0);
  setpoint_x = 1023 - input_x;
  deficit_x = setpoint_x - current_x;

  if (deficit_x > 7) deficit_x = 7;
  if (deficit_x < -7) deficit_x = -7;
  if ((deficit_x <= 2) & (deficit_x  >= -2)) deficit_x = 0;
/*
 *Check y potentiometer, and calculate needed steps to match pen with requested y.
 */
  input_y = analogRead(A1);
  setpoint_y = 1023 - input_y;
  deficit_y = setpoint_y - current_y;

/*
 *Keep number of steps less than 7 and more than 2 (for noise reduction).
 */
  if (deficit_y > 7) deficit_y = 7;
  if (deficit_y < -7) deficit_y = -7;
  if ((deficit_y <= 2) & (deficit_y  >= -2)) deficit_y = 0;

  step(deficit_x , deficit_y);          //step requested amounts
  current_x = current_x + deficit_x;    //update x
  current_y = current_y + deficit_y;    //update y

   delay(20);
   Serial.print(current_x);               //print out current values.
   Serial.print(", ");
   Serial.println(current_y);
  }
