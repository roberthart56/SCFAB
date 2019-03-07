/*
  Read and save.
  This example shows how to save data into a variable and send it to a computer
  upon the pressing of a button.  Button on pin 7.
  This example code is in the public domain.
*/
int data_array[10];   // initialize an array of integers to store data

// the setup routine runs once when you press reset:
void setup() {
  pinMode(7, INPUT_PULLUP);     //button between pin7 and gnd.  
                                //Internal pullup resistor keeps level HIGH 
                                //until button in pushed.
  pinMode(13, OUTPUT); 
   
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  //for loop to take data.

  for (int i = 0; i < 10; i++){
    data_array[i] = analogRead(A0);
    digitalWrite(13, HIGH);
    delay(500);  //take data once per second.  Delay 500 ms before and 500 ms after.
    digitalWrite(13, LOW);
    delay(500);  //take data once per second.  Delay 500 ms before and 500 ms after.
    if (digitalRead(7) == LOW) break;  //this lets you exit loop with a button push
    }   //end of for loop
}     //end of setup function.

// the loop routine runs over and over again forever:
void loop() {
  while (digitalRead(7) == HIGH) {   //wait until button is pressed
    }   //end of while loop.
    
  digitalWrite(13, HIGH);         //turn on LED to indicate sending data.
     for (int i = 0; i < 10; i++){
  
     Serial.println(data_array[i]);    //send data, one integer at a time.
     }    //end of for loop.
   
  delay(1000);        // delay a second to let button be released.
  digitalWrite(13, LOW);     // indicate that sending of data is done.
}   // end of loop() function.
