
int sensorPin = A3;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);     // initialize serial monitor
}

void loop() {
  sensorValue = analogRead(sensorPin);    // read the value from the sensor:
  Serial.print("Sensor values: ");        // print values on serial monitor
  Serial.println(sensorValue);
  delay(100);
}
