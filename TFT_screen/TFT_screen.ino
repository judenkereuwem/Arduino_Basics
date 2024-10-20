// include TFT and SPI libraries
#include <TFT.h>  
#include <SPI.h>
#include <Adafruit_GFX.h>

#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif

// pin definition for Arduino UNO
#define cs   15
#define dc   2
#define rst  4


// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);

void setup() {

  //initialize the library
  TFTscreen.begin();

  // clear the screen with a black background
  TFTscreen.background(0, 0, 0);
  //set the text size
  TFTscreen.setTextSize(2);
}

void loop() {

  //generate a random color
  int redRandom = random(0, 255);
  int greenRandom = random (0, 255);
  int blueRandom = random (0, 255);
  
  // set a random font color
  TFTscreen.stroke(redRandom, greenRandom, blueRandom);
  
  // print Hello, World! in the middle of the screen
  TFTscreen.text("Hello, World!", 6, 57);
  
  // wait 200 miliseconds until change to next color
  delay(200);
}