
//Set analog pin the LM35 Vout pin will be connected to
const int sensorPin = A0;

//Create variable to store various values
float sensor_value;
float voltage;
float temperatureC;
float temperatureF;

void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Get voltage reading from the LM35
  sensor_value = analogRead(sensorPin);

  // Convert sensor reading to voltage
  voltage = sensor_value * (5.0 / 1024.0);

  // Convert voltage reading to temperature in Celisius
  temperatureC = voltage * 100;

  // Convert voltage reading to temperature in Fahrenheit
  temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  //Print temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("\xC2\xB0"); // print degree symbol
  Serial.print("C  ");

  //Print temperature in Fahrenheit
  Serial.print(temperatureF);
  Serial.print("\xC2\xB0"); // print degree symbol
  Serial.println("F");
  
  delay(1000); // Wat for one second before next reading
}
