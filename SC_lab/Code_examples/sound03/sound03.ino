//sound03.  Robert Hart March 5, 2019.
//
//Program to measure sound energy by comparing pairs of Analog voltages
// when microphone output is connected to A0.
// This version includes a function, called in the loop.  
// be used to make other calculations.
// Notice that the intensity is frequency dependent.

void setup() {
  Serial.begin(115200);     // initialize serial communication at 115200 bits per second:
}

float sound_int() {     //function to measure sound energy by measuring adjacent time points.
  int Npts = 100;     //Number of points to sample. 
  int sound1, sound2;
  float diff_sq;
  float eps = 0.1;
  float accum= 0;
  
  for( int i = 0; i < Npts; i++){
    sound1= analogRead(A0);
    delayMicroseconds(1000);                  //delay.  Determines what frequencies are detected.  At 1 mS, detection is best at ~ 300 Hz.
    sound2= analogRead(A0);
    diff_sq = float((sound1 - sound2) * (sound1-sound2));   //difference squared.  Always positive.
    accum = accum + diff_sq;
    }
  return accum/Npts;
}

void loop() {             //Write code here to use the sound intensity data.
  Serial.println(sound_int()); 
}
