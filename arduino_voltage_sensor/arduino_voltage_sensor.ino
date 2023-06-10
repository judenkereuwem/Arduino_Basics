/*
 * This progam uses B25 Voltage sensor connected 
 * to Arduino board to read voltage in a circuit 
 * and display results on Serial monitor.
*/

const int voltgeSensor = A0;

float vOUT = 0.0;
float vIN = 0.0;

float R1 = 30000.0;
float R2 = 7500.0;

int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  value = analogRead(A0);
  
  vOUT = (value * 5.0)/1024.0;
  vIN = vOUT / (R2/(R1+R2));

  //display on serial monitor
  Serial.print("Voltage = ");
  Serial.print(vIN, 3);
  Serial.println(" volts DC");

  delay(1000);
}
