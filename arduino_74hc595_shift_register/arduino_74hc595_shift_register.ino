// 74HC595 shift register 

int latchPin = 11;
int clockPin = 13;
int dataPin  = 12;

byte leds = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

void loop() {
  leds = 0;
  updateShiftRegister();
  delay(100);
  for(int i = 0; i<8; i++){
    bitSet(leds, i);
    updateShiftRegister();
    delay(100);
  }
}

void updateShiftRegister(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
