
#include <Servo.h>

// Create a Servo object
Servo myServo;

// Variable to store the servo position
int pos = 0;

void setup() {
  // Attach the servo to a pin
  myServo.attach(13);

  // Begin Serial communication to print the position
  Serial.begin(9600);
}

void loop() {
  // Sweep the servo from 0 to 180 degrees
  for (pos = 10; pos <= 150; pos += 1) {  // Move from 0 to 180 degrees
    myServo.write(pos);                  // Tell servo to go to 'pos' position
    delay(50);                           // Wait for the servo to reach the position
    int currentPos = myServo.read();     // Get the last written position
    Serial.print("Servo position: ");    // Print the position
    Serial.println(currentPos);          // Print the value
  }

  // Sweep the servo back from 180 to 0 degrees
  for (pos = 150; pos >= 10; pos -= 1) {  // Move from 180 to 0 degrees
    myServo.write(pos);                  // Tell servo to go to 'pos' position
    delay(50);                           // Wait for the servo to reach the position
    int currentPos = myServo.read();     // Get the last written position
    Serial.print("Servo position: ");
    Serial.println(currentPos);          // Print the value
  }
}

