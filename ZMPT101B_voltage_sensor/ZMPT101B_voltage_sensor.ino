
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







//int adc_max = 0;       // Variable to store the maximum sensor value
//int adc_min = 1023;    // Variable to store the minimum sensor value
//long tiempo_init;      // Variable to store the initial time
//
//void setup() {
//  Serial.begin(9600);   // Initialize the serial communication
//  tiempo_init = millis(); // Get the current time in milliseconds
//}
//
//void loop() {
//  if ((millis() - tiempo_init) > 500) { // Check if 500 milliseconds have passed
//    adc_max = 0;         // Reset the maximum sensor value
//    adc_min = 1023;      // Reset the minimum sensor value
//    tiempo_init = millis(); // Update the initial time
//  }
//
//  int sensorValue = analogRead(A0); // Read the analog input from pin A0
//
//  if (sensorValue > adc_max) {
//    adc_max = sensorValue; // Update the maximum value if a new maximum is found
//  } else if (sensorValue < adc_min) {
//    adc_min = sensorValue; // Update the minimum value if a new minimum is found
//  }
//
//  // Print the maximum and minimum values to the serial monitor
//  Serial.print("adc_max: ");
//  Serial.print(adc_max);
//  Serial.print("   adc_min: ");
//  Serial.println(adc_min);
//
//  delay(1); // Small delay for stability between each iteration
//}









// Calibration values obtained from the sketch: volt_ac_cal
int adc_max = 660;                // Maximum sensor value during calibration
int adc_min = 351;                // Minimum sensor value during calibration

float volt_multi = 250;           // RMS voltage obtained from a multimeter
float volt_multi_p;               // Peak voltage
float volt_multi_n;               // Negative peak voltage

void setup() {
  Serial.begin(9600);

  volt_multi_p = volt_multi * 1.4142;   // Peak voltage = RMS voltage * 1.4142 (Single-phase current)
  volt_multi_n = -volt_multi_p;         // Negative peak voltage
}

void loop() {
  float volt_rms = get_voltage();       // Root Mean Square voltage (V-RMS)

  Serial.print("Vrms: ");
  Serial.print(volt_rms, 3);
  Serial.println(" VAC");

  // Delay for a certain interval if needed
  //delay(100);
}

float get_voltage() {
  float adc_sample;
  float volt_inst = 0;
  float sum = 0;
  float volt;
  long init_time = millis();
  int N = 0;

  while ((millis() - init_time) < 500) {   // Duration of 0.5 seconds (Approximately 30 cycles of 60Hz)
    adc_sample = analogRead(A0);            // Sensor voltage
    volt_inst = map(adc_sample, adc_min, adc_max, volt_multi_n, volt_multi_p);
    sum += sq(volt_inst);                    // Sum of Squares
    N++;
    delay(1);
  }

  //Serial.print("N: ");
  //Serial.println(N);

  volt = sqrt(sum / N);                     // RMS equation
  return volt;
}
