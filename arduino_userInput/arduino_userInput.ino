
void setup() {
  Serial.begin(9600);  
}

void loop() {
  Serial.print("first number: ");
  while (Serial.available() == 0){}
  int first_number = Serial.parseInt();
  Serial.println(first_number);
    
  Serial.print("second number: ");
  while (Serial.available() == 0){}
  int second_number = Serial.parseInt();
  Serial.println(second_number);

  Serial.print("Total = ");
  int total = first_number + second_number;
  Serial.println(total);
  
}
