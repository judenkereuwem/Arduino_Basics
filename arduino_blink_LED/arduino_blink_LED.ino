
ledPin = 13;

void setup() {
  // initialize digital pin 13 as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // turn on LED, pause for a second, turn LED off, pause for a second, repeat.
  digitalWrite(ledPin, HIGH);   
  delay(1000);                       
  digitalWrite(ledPin, LOW);    
  delay(1000);                       
}
