/*This code and circuit demonstrate several concepts of Arduino programming coming together:
 * ADC input with analogRead(), then taking the ADC 10-bit input and mapping it into a range of frequencies 
 * using the map() function to drive a speaker at a variable frequency with the tone() function. We will be using 
 * the LiquidCrystal.h library for outputting to a 16x2 LCD with examples of how to use some of the 
 * functions supplied by the LiquidCrystal.h library. The input in this example board is a potentiometer tied 
 * between Vcc and GND varing the ADC input from 0-1023 (0-2^10-1). The concept of using analogRead() and map() 
 * is extensible to other inputs such as light or sound in terms of actuating some output based on an input.
  
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground - This sets the LCD into WRITE mode
 * LCD VSS pin to ground - Need to use the GND pin on the PORTD side (maybe)
 * LCD VCC pin to 5V*/

//#include the Arduino library to easily interface with the LCD display
#include <LiquidCrystal.h>

//Initialize the library by associating any needed LCD interface pins with the Arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //Decleration relating pins to a variable
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                  //Function from the LiquidCrystal.h library to set pins

void setup() 
{       
  //Set up the LCD's number of columns and rows, in the case of the 1602A this is a 16 column LCD with 2 rows
  lcd.begin(16, 2);
}

void loop() 
{
  lcd.setCursor(0, 0);                         //row 1, column 1 of the LCD (zero based indexing)
  lcd.print(analogRead(A0));                   //Analog Value on pin A0 written to the LCD
  delay(20);                                   //The 20ms delay makes the display more readable
  lcd.setCursor(0 , 1);                        //row 2 of the LCD, again with 0 zero based indexing (0,1,2,3...etc)
  lcd.print(random(0,5000000000));             //Random number printed to the second row of the lcd (just for kicks!)
  delay(20);
  int val_in = analogRead(A0);                   //Analog value read from pin A0 which we intend to map to a frequency value
  int map_val = map(val_in, 0, 1023, 0, 2000);  //Value from the A0 pin mapped to a frequency number from 0-2000Hz for tone()
  tone(A1, map_val , 100);                      //Output of a frequencey to pin A1 based on the input from the analog pin A0
  lcd.setCursor (8, 0);                         //This will set the cursor to column 8 of the first row of the LCD display 
  lcd.print(map_val);                           //This will print out the mapped value halfway across the LCD row one
  delay(75);
  lcd.clear();                                  //Clears both rows of the LCD to avoid artifacting (leaving certain characters for the next loop
}
/*This example code and circuit represent a more intermediate level of programming and wiring.
 * The portion of the code involving the potentiometer input and variable frequency output can be written in a single line of code
 * It's terrible in terms of readability and bad programming practice, but it is instructive to understand what is going on here. 
 * The tone() function takes 3 arguments - (pin , value, duration).  So in the following line we are putting an output to A1, mapping 
 * the analog value from pin A0 into the 0 - 2000Hz frequency range for 200 milliseconds.
 * void loop()
 * {
 *    tone(A1, map(analogRead(A0), 0, 1023, 0, 2000), 200);
 * }
 */
