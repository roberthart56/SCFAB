/*
  Program to capture the intensity of sound input from a microphone.  Uses an exponential running average.

*/
int sound1, sound2;
float diff_sq;
float eps = 0.1;      //This constant determines the amount that each data point changes the running average.  A smaller
                      // value makes the response slower.
float accum;          // The number that accumulates the running average.

void setup() {
  Serial.begin(115200);     // initialize serial communication at 115200 bits per second:
}


void loop() {
   sound1= analogRead(A0);

   delay(1);                  //delay.  Determines what frequencies are detected.  At 1 mS, detection is best at ~ 300 Hz.

   sound2= analogRead(A0);

   diff_sq = float((sound1 - sound2) * (sound1-sound2));    //Take the difference between two points on the waveform.
                                                            //Then square, to make it positive.
   accum = accum*(1-eps)+ diff_sq * eps;

   Serial.println(accum);

}
