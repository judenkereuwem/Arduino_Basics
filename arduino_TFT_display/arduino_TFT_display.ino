

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>


#define TFT_CS         15
#define TFT_RST        4                                            
#define TFT_DC         2


// For 1.44" and 1.8" TFT with ST7735 use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


void setup(void) {
  // Use this initializer if using a 1.8" TFT screen:
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  

  // large block of text
  tft.fillScreen(ST7735_BLACK);
  tft.setRotation(1);
  tft.setTextWrap(false);
  tft.invertDisplay(false);

  tft.setTextSize(2);
  tft.setTextColor(ST7735_GREEN);
  tft.setCursor(10, 10);
  tft.print("ARDUINO");
  delay(1000);


}

void loop() {
  
}








