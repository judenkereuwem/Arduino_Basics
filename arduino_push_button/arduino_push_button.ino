
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

void setup() {
  pinMode(ledPin, OUTPUT);    // set LED pin as an input:
  pinMode(buttonPin, INPUT);  // set pushbutton pin as an input:
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // if pushbutton is pressed, turn on LED.
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    
  // if pushbutton is releaased, turn off LED.  
  } else {
    digitalWrite(ledPin, LOW);
  }
}
