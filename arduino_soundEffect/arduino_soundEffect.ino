
const int buzzerPin = 8;
const int sensorPin = A0;  // pin that the sensor is attached to

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  // read the sensor:
  unsigned int sensorValue = analogRead(sensorPin);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, 0, 1023, 100, 2000);

  // fade the LED using the calibrated value:
  //analogWrite(ledPin, sensorValue);

  tone(buzzerPin, sensorValue);

  Serial.println(sensorValue);

  //noTone(buzzerPin);
  delay(200);


}