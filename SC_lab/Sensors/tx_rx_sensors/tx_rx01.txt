
//rx_tx01  Robert Hart Mar 2019.
//  Program to use transmit-receive across space between two conductors.
//  One conductor attached to pin4, one to A0
//
//  Optionally, two resistors (1 MOhm or greater) can be placed between 5V and GND, with
//  the signal connected between them so that the steady-state voltage is 2.5 Volts.
//
//  Signal varies with electric field coupling between conductors, and can
//  be used to measure many things related to position, overlap, and intervening material
//  between the two conductors.
//



int read_high;
int read_low;
int diff;


void setup() {
pinMode(4,OUTPUT);      //Pin 4 provides the voltage step
Serial.begin(9600);
}

void loop() {


   digitalWrite(4,HIGH);              //Step the voltage high on conductor 1.
   read_high = analogRead(A0);        //Measure response of conductor 2.
   delayMicroseconds(100);            //Delay to reach steady state.
   digitalWrite(4,LOW);               //Step the voltage to zero on conductor 1.
   read_low = analogRead(A0);         //Measure response of conductor 2.
   diff = read_high - read_low;       //desired answer is the difference between high and low.

Serial.println(diff);
//delay(100);



}
