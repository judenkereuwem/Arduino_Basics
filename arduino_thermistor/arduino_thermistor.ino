
//reading temp. using thermistor and Arduino in real time.
#define analogPin A0 //the thermistor attach to 
#define beta 3950 //the beta of the thermistor

void setup() {
  Serial.begin(9600);
}

void loop() {
  long a = analogRead(analogPin);
  //the calculating formula of temperature
  double resistance = 10.0 * (4096.0 / a - 1.0);
  double tempC = beta / (log((resistance * 10 / a - 1.0) / 10) + beta / 298.0) - 273.0;

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" °");
  Serial.println("C");

  delay(500);
}
