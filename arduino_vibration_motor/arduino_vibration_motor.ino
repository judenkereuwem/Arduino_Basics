const int motorPin = 3;

void setup() {
  pinMode(motorPin, OUTPUT);

}

void loop() {
  digitalWrite(motorPin, HIGH);
  delay(1000);
  digitalWrite(motorPin, LOW);
  delay(2000);

}
