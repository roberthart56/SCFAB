/*
 LED driver with for loop

*/
void setup() {
}





void loop() {
  for (int intensity = 0; intensity<100; ++intensity){
 analogWrite(9, intensity);
 delay(20);
  }
  
}
