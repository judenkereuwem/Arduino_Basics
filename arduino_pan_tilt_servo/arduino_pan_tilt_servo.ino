
#include <Servo.h>

// create servo object to control a servo
Servo base_servo;  
Servo top_servo;  

// variable to store the servo position
int base_pos;    
int top_pos;   

void setup() {
  // attaches the servo on pin 9 to the servo object
  base_servo.attach(6);  
  top_servo.attach(11);
}

void loop() {

  // pan from left to right
  for (base_pos = 0; base_pos <= 180; base_pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
    base_servo.write(base_pos);                 // tell servo to go to position in variable 'pos'
    delay(10);                          // waits 15ms for the servo to reach the position
  }
  delay(1000);

  // tilt backwards 
  for (top_pos = 90; top_pos <= 0; top_pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
    top_servo.write(top_pos);                 // tell servo to go to position in variable 'pos'
    delay(10);                          // waits 15ms for the servo to reach the position
  }
  delay(1000);


  // pan from right to left
  for (base_pos = 180; base_pos >= 0; base_pos -= 1) { // goes from 180 degrees to 0 degrees
    base_servo.write(base_pos);                 // tell servo to go to position in variable 'pos'
    delay(10);                          // waits 15ms for the servo to reach the position
  }
  delay(1000);


  // tilt upwards 
  for (top_pos = 0; top_pos >= 90; top_pos -= 1) { // goes from 180 degrees to 0 degrees
    top_servo.write(top_pos);                 // tell servo to go to position in variable 'pos'
    delay(10);                          // waits 15ms for the servo to reach the position
  }
  delay(1000);


}
