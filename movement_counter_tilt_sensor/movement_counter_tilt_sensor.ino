const int tiltSwitchPin = 4;  // Change to the pin where your tilt switch is connected
int previousTiltSwitchState = 0;  // Initial state of the tilt switch
int moveCount = 0;  // Counter for movements

void setup() {
  Serial.begin(9600);
  pinMode(tiltSwitchPin, INPUT_PULLUP);
}

void loop() {
  // Read the current state of the tilt switch
  int currentTiltSwitchState = digitalRead(tiltSwitchPin);

  // Check if the tilt switch state has changed
  if (currentTiltSwitchState != previousTiltSwitchState) {
    // Delay to debounce the tilt switch (adjust as needed)
    delay(50);

    // Read the state again to avoid false positives
    currentTiltSwitchState = digitalRead(tiltSwitchPin);

    // Check if the tilt switch moved to the other side
    if (currentTiltSwitchState == 1) {
      // Increment the move count
      moveCount++;

      // Print the move count to the Serial Monitor
      Serial.print("Move Count: ");
      Serial.println(moveCount);
    }
  }

  // // Update the previous state for the next iteration
  previousTiltSwitchState = currentTiltSwitchState;

  // // Your additional code can go here, if needed

  delay(100);
}