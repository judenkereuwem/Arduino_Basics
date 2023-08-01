#include <SPI.h>
#include <LoRa.h>

const int buttonPin = 4;
//byte button = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int button = digitalRead(buttonPin);
  
  Serial.print("Sending packet: ");
  Serial.println(button);
  //delay(100);

  // send packet
  LoRa.beginPacket();
  LoRa.print("Button ");
  LoRa.print(button);
  LoRa.endPacket();

  delay(500);
}
