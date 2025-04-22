#include <SoftwareSerial.h>

// The serial connection to the GPS device (TXPin, RXPin)
SoftwareSerial ss(3, 4);

void setup(){
  Serial.begin(9600);
  ss.begin(9600);
}

void loop(){
  while (ss.available() > 0){
    // get the byte data from the GPS
    byte gpsData = ss.read();
    Serial.write(gpsData);
  }
}

