
const int ledPin = 9;     //led connected to pin 9 (PWM)
int brightness = 0;       //brightness level (0-255)
int fadeAmount = 5;       //fading levels

void setup() {
  const int ledPin = 3;   //led connected to pin 9 (PWM)
  int brightness = 0;     //brightness level (0-255)
  int fadeAmount = 5;     //fading levels
}

void loop() {
  //set brightness of ledPin
  analogWrite(ledPin, brightness);

  //increment brightness level by fadeAmount (5)
  brightness = brightness + fadeAmount;

  if((brightness >= 0)&&(brightness < 255)){
    fadeAmount = +fadeAmount;
  }
  else if((brightness <= 255)&&(brightness > 0)){
    fadeAmount = -fadeAmount;
  }
  delay(100);

}
