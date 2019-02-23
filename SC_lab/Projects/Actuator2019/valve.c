//Valve driver.
//
//valve.c
//
// Buttons  PB3 and PB4.
// N-MOSFET gates on PB2 and PB1 to drive soleoid valves.
//
#include <avr/io.h>

#define output(directions,pin) (directions |= pin) 		// macro used to set port direction for output
#define input(directions,pin) (directions &= (~pin)) 	// macro used to set port direction for input
#define set(port,pin) (port |= pin) 					// macro used to set port pin
#define clear(port,pin) (port &= (~pin)) 				// macro used to clear port pin
#define pin_test(pins,pin) (pins & pin) 				// macro used to test for port pin
#define bit_test(byte,bit) (byte & (1 << bit)) 			// macro used to test for bit set
//
//  The following definitions are specific to the particular configuration of LEDs and buttons on pins.
//  These are the only things that need to change when you move to other pins or add devices.
//
#define input_port PORTB		// The button is on portB
#define input_direction DDRB
#define input_1_pin (1 << PB3)	//  button 1
#define input_2_pin (1 << PB4)	//  button 2
#define input_pins PINB			//  for reading button state
#define output_port PORTB		//  port B will be used for the LED
#define output_direction DDRB	//  DDRB defines input/output direction for port B
#define output_1_pin (1 << PB2)	//  valve 1
#define output_2_pin (1 << PB1)	//  valve 2



int main(void) {							//  This is the main function
	//
   	// initialize pins
   	//
   output(output_direction, output_1_pin);
   output(output_direction, output_2_pin);
   set(input_port, input_1_pin);				// turn on pull-up resistor on the input (button) pin
   set(input_port, input_2_pin);				// turn on pull-up resistor on the input (button) pin
   input(input_direction, input_1_pin);		// sets the appropriate bit to enable input on the input pin.
   input(input_direction, input_2_pin);		// sets the appropriate bit to enable input on the input pin.
   //
   // main loop
   //
   while (1) {								// loops forever
      if (pin_test(input_pins,input_1_pin))	// test to detect button push.  Result is true if button is up.
      	clear(output_port,output_1_pin);		// set output low if button is up.
	    else									// otherwise...
		    set(output_port,output_1_pin);  	// set output high.

      if (pin_test(input_pins,input_2_pin))	// test to detect button push.  Result is true if button is up.
          clear(output_port,output_2_pin);		// set output low if button is up.
      else									// otherwise...
          set(output_port,output_2_pin);  	// set output high.
      }
   }
