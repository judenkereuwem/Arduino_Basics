/*Mapping 74HC595 pins Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7 to a,b,c,d,e,f,g of 
a common-cathode Seven-Segment LED*/
/*byte seven_seg_digits[10] = { B11111100,  // = 0
                              B01100000,  // = 1
                              B11011010,  // = 2
                              B11110010,  // = 3
                              B01100110,  // = 4
                              B10110110,  // = 5
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B11111110,  // = 8
                              B11100110   // = 9
                             };

/*unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};//Display digital data*/

int digits[]

int latchPin = 8;  //Pin connected to ST_CP of 74HC595
int clockPin = 12; //Pin connected to SH_CP of 74HC595
int dataPin = 11;  //Pin connected to DS of 74HC595

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  //count up routine
  for (int j = 0; j < 256; j++) {
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, j);//seven_seg_digits[4]);  
    digitalWrite(latchPin, HIGH);
    
   delay(1000);
 }
}
