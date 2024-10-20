
#include "DHT.h"

#define DHTTYPE DHT22

uint8_t DHTPin = 2;
DHT dht(DHTPin, DHTTYPE);

float Temperature;
float Humidity;
float Temp_Fahrenheit;

void setup() {
  Serial.begin(9600);
  pinMode(DHTPin, INPUT);
  dht.begin();
}

void loop(){

  Humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  Temperature = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  Temp_Fahrenheit = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(Humidity) || isnan(Temperature) || isnan(Temp_Fahrenheit)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(Humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(Temperature);
  Serial.print(F("°C "));
  Serial.print(Temp_Fahrenheit);
  Serial.println(F("°F "));

  delay(100);
}
