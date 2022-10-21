
const int potPin = A0;
const int ledPin = 6;
int led_value;
int pot_value;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // reading from potentiometer
  pot_value = analogRead(potPin);

  // Mapping the Values between 0 to 255 
  led_value = map(pot_value, 0, 1023, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPin, led_value);
}
