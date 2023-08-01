#include <SPI.h>
#include <LoRa.h>

const int LED = 4;

char packet;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  pinMode(LED, OUTPUT);
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      packet = LoRa.read();
      Serial.print(packet);
      //Serial.print((char)LoRa.read());

      if(packet == '0'){
        digitalWrite(LED, HIGH);
      }else{
      digitalWrite(LED, LOW);
      }
   }

    

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
