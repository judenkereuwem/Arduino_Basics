
const int ledPin = 7;

void setup() {
  // initialize digital pin 13 as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  digitalWrite(ledPin, HIGH);    // turn on LED  
  delay(3000);                   // pause for a second       
  digitalWrite(ledPin, LOW);     // turn LED off   
  delay(2000);                   // pause for a second           
}
