// Arduino with WS2812B LED Ring Light
// Control LED brightness and number of LED to turn on with potentiomeyter
// October 2023

#include <FastLED.h>
#define LEDPIN 3 
#define NUMOFLEDS 16 

CRGB leds[NUMOFLEDS]; 

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LEDPIN, GRB>(leds, NUMOFLEDS);
}

void loop() {

  int potB_value = analogRead(A4);
  int mapPotB_value = map(potB_value, 0, 1023, 0, 255);

  int potN_value = analogRead(A5);
  int mapPotN_value = map(potN_value, 0, 1023, 0, NUMOFLEDS);
  
  Serial.println(potN_value); 
    FastLED.setBrightness(mapPotB_value);
    
    FastLED.clear();
    for (int led = 0; led < mapPotN_value; led++){
      leds[led] = CRGB::Blue;
    }
    for (int led = mapPotN_value; led > 0; led--){
      leds[led] = CRGB::Blue;
    }
  //}
  FastLED.show();
}
