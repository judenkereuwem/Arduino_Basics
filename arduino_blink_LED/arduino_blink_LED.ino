
const int ledPin = 26;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);    // turn on LED  
  delay(1000);                   // pause for a second       
  digitalWrite(ledPin, LOW);     // turn LED off   
  delay(100);                   // pause for a second           
}
