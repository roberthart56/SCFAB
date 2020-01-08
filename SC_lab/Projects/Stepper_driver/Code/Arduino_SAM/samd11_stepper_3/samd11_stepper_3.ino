/*
Jan 7, 2020.  Rob Hart.  samd11_stepper_3
Program to drive stepper in response to one byte transferred into USART NO. 1.
MSB(7): direction.
6-4: address.
3-0: number of steps to take.
In this program, step time is fixed.

*/
int Aplus = 15;   //corresponds to h-bridge input pin +
int Aminus = 14;   //corresponds to h-bridge input pin -
int Bplus = 8;   //corresponds to h-bridge input pin +
int Bminus = 5;   //corresponds to h-bridge input pin -
int LED_G = 4;    //LEDs are attached to pins to give a visual indication of direction and step
int LED_R = 2;

int step_num = 1;
uint16_t step_count = 0;      //number of steps since program began.
uint8_t pulse_count = 0;     //The variable with range 0-3 that determines which motor state to
uint8_t rec_byte = 0;         //The byte received from USART
bool direction = true;        //True corresponds to incrementing pulse count.
uint8_t address = 2;      //This value is unique to a given board. Ranges 0-7.
//uint8_t address = 1;      //This value is unique to a given board. Ranges 0-7.

void setup() {
  Serial1.begin(230400);
  SerialUSB.begin(0);
  pinMode(Aplus, OUTPUT);
  pinMode(Aminus, OUTPUT);
  pinMode(Bplus, OUTPUT);
  pinMode(Bminus, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);

}
/*
The following functions energise the windings, in order defined as positive stepping
*/
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
/*
The following function turns off all windings.
*/
void all_off() {
  digitalWrite(Aplus,LOW);
  digitalWrite(Aminus,LOW);
  digitalWrite(Bplus,LOW);
  digitalWrite(Bminus,LOW);
}

void loop() {

  while (!Serial1.available()){       //wait until serial is available.
  }

  rec_byte =  Serial1.read();



  if ((rec_byte & 0b01110000) >> 4 == address){     //Bitwise detection of address using three-digit mask and shifting.
                                                    //If address is detected, step the motor. Otherwise, go back and wait for another byte.
    digitalWrite(LED_G, HIGH);                      //Green LED indicates start of stepping.

    direction = rec_byte & 0b10000000;        //set the boolean direction to be true or false using only the most significant bit.
    if (direction) digitalWrite(LED_R, HIGH);     //use LED as a visual indicator of + direction.
    else digitalWrite(LED_R, LOW);

    step_num = rec_byte & 0b00001111;      //strip off lower half-byte

    /*
    The following loop steps the motor for 'step_num' steps.
    */
    for(int i=0; i<step_num; i++){

      if (direction) step_count++;
      else step_count--;

      pulse_count = step_count%4;       //use the modulo function to keep track of which motor state to use.

      SerialUSB.println(step_count);    //print out overall step count.

      all_off();
      delayMicroseconds(10);

      if (pulse_count == 0) pulse_0();
      if (pulse_count == 1) pulse_1();
      if (pulse_count == 2) pulse_2();
      if (pulse_count == 3) pulse_3();

      delayMicroseconds(5000);      //microseconds.  This, together with unknown overhead, defines the step time.
    }
    digitalWrite(LED_G, LOW);    //done with stepping.
      }


 }
