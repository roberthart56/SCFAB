/*
Inplement identity and direction encoded in USART byte.
*/
int Aplus = 15;
int Aminus = 14;
int Bplus = 8;
int Bminus = 5;
int LED_G = 4;
int LED_R = 2;

int step_num = 1;
uint16_t step_count = 0;
uint8_t pulse_count = 0;
uint8_t rec_byte = 0;
boolean direction = true;
uint8_t address = 2;

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
  
  while (!Serial1.available()){
  }
  
  rec_byte =  Serial1.read();
  
  
  
  if ((rec_byte & 0b01110000) >> 4 == address){     //if I detect my address step motor.
    
    digitalWrite(LED_G, HIGH);
    
    direction = rec_byte & 0b10000000;
    if (direction) digitalWrite(LED_R, HIGH);
    else digitalWrite(LED_R, LOW);
    
    step_num = rec_byte & 0b00001111;      //strip off lower half-byte
    
    for(int i=0; i<step_num; i++){                  
      
      if (direction) step_count++;  
      else step_count--; 
      
      pulse_count = step_count%4;
      
      SerialUSB.println(step_count);    //keep track of overall step_count,  16 bit unsigned integer.
      
      all_off();
      delayMicroseconds(10);
      
      if (pulse_count == 0) pulse_0();
      if (pulse_count == 1) pulse_1();
      if (pulse_count == 2) pulse_2();
      if (pulse_count == 3) pulse_3(); 
  
      delayMicroseconds(5000);      //microseconds
    }
      }
       
  else digitalWrite(LED_G, LOW);    //in the case that I don't wee my address.
 
    
  
  
 }
