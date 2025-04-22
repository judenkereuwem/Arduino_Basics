#include <IRremote.hpp> //v4.2.0

int RECV_PIN = 9;
const int ledPin = 13;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the receiver

  digitalWrite(ledPin, LOW);
}

void loop(){

  if (IrReceiver.decode()){
     //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
     if (IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00){
      digitalWrite(ledPin, HIGH);
     }
     if (IrReceiver.decodedIRData.decodedRawData == 0xB946FF00){
      digitalWrite(ledPin, LOW);
     }
     IrReceiver.resume(); // Receive the next value
     delay(100);
    }
}
