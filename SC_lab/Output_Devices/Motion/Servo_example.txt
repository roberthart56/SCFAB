/* Servo_example
 
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {

    myservo.write(0);              // tell servo to go to zero degrees.
    delay(1000);                       // waits 1 second for the servo to reach the position.

    myservo.write(180);              // tell servo to go to 180 degrees.
    delay(1000);                       // waits 1 second for the servo to reach the position.
}
