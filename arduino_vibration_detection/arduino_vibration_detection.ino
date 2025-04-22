const int motorPin = 3;
const int buttonPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 

}

void loop() {
  byte buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  digitalWrite(motorPin, HIGH);
  delay(1000);
  digitalWrite(motorPin, LOW);
  delay(1000);

}
