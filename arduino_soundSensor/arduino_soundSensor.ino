
const int sensorPin = A0;

void setup() {
  pinMode(sensorPin, INPUT);  // Set sensor pin as an INPUT
  Serial.begin(9600);
}

void loop() {
  // Read Sound sensor
  int sensorData = analogRead(sensorPin);
  Serial.print("sensor: ");
  Serial.println(sensorData);
  delay(100);
   
}
