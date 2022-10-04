
/*This code will turn on led when button is pressed, 
 *then turn it off when button is pressed again.
*/

const int Button = 2;
const int Led = 3;

int ledState = LOW;
int lastButtonState;
int currentButtonState;

void setup() {
  Serial.begin(9600);
  pinMode(Button, INPUT_PULLUP);
  pinMode(Led, OUTPUT);

  currentButtonState = digitalRead(Button);
}

void loop() {
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(Button);

  if (lastButtonState == HIGH && currentButtonState == LOW){
    Serial.println("Button pressed");

    ledState = !ledState;

    digitalWrite(Led, ledState);
  }
}
