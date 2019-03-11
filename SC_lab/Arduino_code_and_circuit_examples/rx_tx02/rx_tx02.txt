
//rx_tx02  Robert Hart Mar 2019.
//  Program to use transmit-receive across space between two conductors.
//  One conductor attached to pin4, one to A0
//  Signal varies with electric field coupling between conductors, and can
//  be used to measure many things related to position, overlap, and intervening material
//  between the two conductors.
//  



int read_high;
int read_low;
int diff;
long int sum;
int N_samples = 100;    //Number of samples to take.  Larger number slows it down, but reduces scatter.

void setup() {
pinMode(4,OUTPUT);      //Pin 4 provides the voltage step
Serial.begin(9600);
}

void loop() {
 
 sum = 0;

 for (int i = 0; i < N_samples; i++){
   digitalWrite(4,HIGH);              //Step the voltage high on conductor 1.
   read_high = analogRead(A0);        //Measure response of conductor 2.
   delayMicroseconds(100);            //Delay to reach steady state.
   digitalWrite(4,LOW);               //Step the voltage to zero on conductor 1.
   read_low = analogRead(A0);         //Measure response of conductor 2.
   diff = read_high - read_low;       //desired answer is the difference between high and low.
   sum += diff;                       //Sums up N_samples of these measurements.
 }
Serial.println(sum);
//delay(100);

  
 
}
