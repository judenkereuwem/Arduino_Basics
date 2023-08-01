
const int buttonPin = 4;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);    // set LED pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);  // set pushbutton pin as an input:
}

void loop() {
  // read the state of the pushbutton value:
  byte buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  delay(100);

  // if pushbutton is pressed, turn on LED.
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    
  // if pushbutton is releaased, turn off LED.  
  } else {
    digitalWrite(ledPin, LOW);
  }
}
