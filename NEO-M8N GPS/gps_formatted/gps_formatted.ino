// Download "TinyGPSPlus" library
 
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device (TXPin, RXPin)
SoftwareSerial ss(3, 4);

void setup(){
  Serial.begin(9600);
  ss.begin(9600);
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude = "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude = "); 
      Serial.println(gps.location.lng(), 6);
    }
  }
}
