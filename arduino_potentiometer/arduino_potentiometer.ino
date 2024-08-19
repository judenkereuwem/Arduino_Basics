
int sensorPin1 =  A0;    // select the input pin for the potentiometer
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorPin2 =  A1;    // select the input pin for the potentiometer
int sensorValue2 = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);     // initialize serial monitor
}

void loop() {
  sensorValue1 = analogRead(sensorPin1);    // read the value from the sensor:
  sensorValue2 = analogRead(sensorPin2);    // read the value from the sensor:
  //Serial.print("Sensor values: ");        // print values on serial monitor
  Serial.println(sensorValue1);
  Serial.println(sensorValue2);
  Serial.println("");
  delay(300);
}
