#include <IRremote.hpp> //v4.2.0

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop()
{
  if (IrReceiver.decode()){
     Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
     IrReceiver.resume(); // Receive the next value
     delay(100);
    }
}
