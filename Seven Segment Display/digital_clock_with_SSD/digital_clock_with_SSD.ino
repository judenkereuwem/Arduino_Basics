//Digital Clock using Seven Segment Display and 74HC595

#define latch1  11  
#define clock1  13 
#define data1  12 

#define latch2  8  
#define clock2  10
#define data2  9 

#define latch3  5  
#define clock3  7
#define data3  6 

int butt1State = 0;
int butt2State = 0;
int butt3State = 0;
int butt4State = 0;

int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;

int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);

}

void loop() {
  butt1State = digitalRead(4);
  butt2State = digitalRead(3);
  butt3State = digitalRead(2);
  butt4State = digitalRead(1);

  //Disply digits on SSD1 when button1 is pressed. 
  if(butt1State == LOW){
    int a = counter1++;
    digitalWrite(latch1, LOW);
    shiftOut(data1, clock1, LSBFIRST, digits[a]);
    digitalWrite(latch1, HIGH);
    delay(250);
  }
    //Disply digits on SSD2 when button2 is pressed. 
    else if(butt2State == LOW){
    int b = counter2++;
    digitalWrite(latch2, LOW);
    shiftOut(data2, clock2, LSBFIRST, digits[b]);
    digitalWrite(latch2, HIGH);
    delay(250);
  }
    //Disply digits on SSD3 when button3 is pressed. 
    else if(butt3State == LOW){
    int c = counter3++;
    digitalWrite(latch3, LOW);
    shiftOut(data3, clock3, LSBFIRST, digits[c]);
    digitalWrite(latch3, HIGH);
    delay(250);
  }
  
  if(butt4State == LOW){
    //Decrement SSD1 value to 0.
    for(int a = (counter1++-2); a>=0; a--){
      digitalWrite(latch1, LOW);
      shiftOut(data1, clock1, LSBFIRST, digits[a]);
      digitalWrite(latch1, HIGH);
      delay(200);
   }
    //Decrement SSD2 value to 0.
    for(int b = (counter2++-2); b>=0; b--){
      digitalWrite(latch2, LOW);
      shiftOut(data2, clock2, LSBFIRST, digits[b]);
      digitalWrite(latch2, HIGH);
      delay(200);
    }
     //Decrement SSD3 value to 0.
     for(int c = (counter3++-2); c>=0; c--){
       digitalWrite(latch3, LOW);
       shiftOut(data3, clock3, LSBFIRST, digits[c]);
       digitalWrite(latch3, HIGH);
       delay(200);
    }
  }
}
