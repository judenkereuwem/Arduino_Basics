#include <Keypad.h>

const byte ROWS = 5;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'*','#','f','F'},
  {'U','3','2','1'},
  {'D','6','5','4'},
  {'E','9','8','7'},
  {'R','G','0','B'}
};

byte rowPins[ROWS] = {10,9,8,7,6};
byte colPins[COLS] = {5,4,3,2};


Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey){
    Serial.println(customKey);
    if(customKey == 'R'){
      Serial.print("Enter");
    }
  } 
}
