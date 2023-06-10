
// Arduino with WS2812B LED Ring Light
// June 2023

#include <FastLED.h>
#define LEDPIN 7 
#define NUMOFLEDS 16 

CRGB leds[NUMOFLEDS]; 

 void setup() { 
  FastLED.addLeds<WS2812, LEDPIN, GRB>(leds, NUMOFLEDS); 
}

 void loop() { 
  // Blue
  for (int i = 0; i <= 15; i++) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(40);
  }

  // Red
  for (int i = 15; i >= 0; i--) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(60);
  }

  // Green
  for (int i = 0; i <= 15; i++) {
    leds[i] = CRGB ( 0, 255, 0);
    FastLED.show();
    delay(40);
  }

  // Purple
  for (int i = 15; i >= 0; i--) {
    leds[i] = CRGB ( 128, 0, 128);
    FastLED.show();
    delay(70);
  }
} 
