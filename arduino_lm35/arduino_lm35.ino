
//Set analog pin the LM35 Vout pin will be connected to
#define lm35Pin 28 //A5


void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {

  // Get voltage reading from the LM35
  int sensor_value = analogRead(lm35Pin);

  // Convert sensor reading to voltage
  //float voltage = sensor_value * (5.0 / 1024.0);
  float voltage = sensor_value * (3.3 / 4096.0);

  // Convert voltage reading to temperature in Celisius
  float temperatureC = voltage * 100;


  // Convert voltage reading to temperature in Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;


  //Print temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("\xC2\xB0"); // print degree symbol
  Serial.print("C  ");

  //Print temperature in Fahrenheit
  Serial.print(temperatureF);
  Serial.print("\xC2\xB0"); // print degree symbol
  Serial.println("F");
  
  delay(500); // Wat for one second before next reading
}
