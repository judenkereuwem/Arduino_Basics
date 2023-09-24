

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRY pin
#define SW_PIN  3 // Arduino pin connected to SW pin

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int swValue = 0;

String joystickStatus = "";


void setup() {
  Serial.begin(9600) ;
  pinMode(SW_PIN, INPUT_PULLUP);
}


void loop() {
  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  swValue = digitalRead(SW_PIN);

  // UP
  if((xValue >  1020) && (yValue > 520)){
    joystickStatus = "UP";
  }

  // DOWN
  else if((xValue == 0) && (yValue > 520)){
    joystickStatus = "DOWN";
  }

  // RIGHT
  else if((xValue > 500) && (yValue > 1020)){
    joystickStatus = "RIGHT";
  }

  // LEFT
  else if((xValue > 500) && (yValue == 0)){
    joystickStatus = "LEFT";
  }

  // BUTTON PRESSED
  else if(swValue == 0){
    joystickStatus = "BUTTON PRESSED";
  }

  // NOTHING
  else if((xValue >= 519) && (yValue >= 523)){
    joystickStatus = "NOTHING";
  }

  Serial.print("Joystick: ");
  Serial.println(joystickStatus);
  delay(100);



  /*
  // print data to Serial Monitor on Arduino IDE
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.print(yValue);
  Serial.print(", sw = ");
  Serial.println(swValue);
  delay(200);
  */
}
