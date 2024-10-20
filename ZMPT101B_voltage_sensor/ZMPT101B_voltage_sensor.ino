
#include <ZMPT101B.h>

#define SENSITIVITY 500.0f

// ZMPT101B sensor output connected to analog pin A0
// and the voltage source frequency is 50 Hz.
ZMPT101B voltageSensor(A0, 50.0);

void setup() {
  Serial.begin(9600);
  voltageSensor.setSensitivity(SENSITIVITY);

}

void loop() {
  // read the voltage and then print via Serial
  float voltage = voltageSensor.getRmsVoltage();
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  delay(1000);
}