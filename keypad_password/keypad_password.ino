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

// Create a string to store the key presses
String password = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = customKeypad.getKey();

if (key) { // Check if a key is pressed
    if ((key == 'R') && (password == "1234")) { // Assuming 'R' is the end of input
      Serial.println("Final input: " + password); // Print the final string
      Serial.println("Correct password");
      Serial.println(" ");
      password = ""; // Reset the string for next input
    } 
    
    else if ((key == 'R') && (password != "1234")) {
      Serial.println("Final input: " + password);
      Serial.println("Incorrect password");
      Serial.println(" ");
      password = ""; // Clear the current input
    } 
    
    else {
      password += key; // Append the pressed key to the string
      Serial.println("input: " + password); // Print the updated string
    }
  } 
}
