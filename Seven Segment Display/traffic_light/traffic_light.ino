//Digital Clock using Seven Segment Display and 74HC595
//placidlearn

#define latch1  11  
#define clock1  13 
#define data1  12 

#define latch2  8  
#define clock2  10
#define data2  9 

#define latch3  5  
#define clock3  7
#define data3  6 

#define latch4  2  
#define clock4  4
#define data4  3

#define latch5  14  
#define clock5  1
#define data5  0

#define latch6  17
#define clock6  15
#define data6  16

int butt1State = 0;
int butt2State = 0;
int butt3State = 0;
int butt4State = 0;
int butt5State = 0;
int butt6State = 0;
int butt7State = 0;
int butt8State = 0;
int butt9State = 0;

int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;
int counter6 = 0;
int counter7 = 0;
int counter8 = 0;
int counter9 = 0;

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
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);

}

void loop() {
  butt1State = digitalRead(18);
  butt2State = digitalRead(19);
  butt3State = digitalRead(20);
  butt4State = digitalRead(21);
  butt5State = digitalRead(22);
  butt6State = digitalRead(23);
  butt7State = digitalRead(26);
  butt8State = digitalRead(25);
  butt9State = digitalRead(24);
  

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

  else if(butt4State == LOW){
    int d = counter4++;
    digitalWrite(latch4, LOW);
    shiftOut(data4, clock4, LSBFIRST, digits[d]);
    digitalWrite(latch4, HIGH);
    delay(250);
  }

  else if(butt5State == LOW){
    int e = counter5++;
    digitalWrite(latch5, LOW);
    shiftOut(data5, clock5, LSBFIRST, digits[e]);
    digitalWrite(latch5, HIGH);
    delay(250);
  }

  else if(butt6State == LOW){
    int f = counter6++;
    digitalWrite(latch6, LOW);
    shiftOut(data6, clock6, LSBFIRST, digits[f]);
    digitalWrite(latch6, HIGH);
    delay(250);
  }

  
  if(butt7State == LOW){
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
  }

    else if(butt8State == LOW){
    //Decrement SSD1 value to 0.
    for(int c = (counter3++-2); c>=0; c--){
      digitalWrite(latch3, LOW);
      shiftOut(data3, clock3, LSBFIRST, digits[c]);
      digitalWrite(latch3, HIGH);
      delay(200);
   }
    //Decrement SSD2 value to 0.
    for(int d = (counter4++-2); d>=0; d--){
      digitalWrite(latch4, LOW);
      shiftOut(data4, clock4, LSBFIRST, digits[d]);
      digitalWrite(latch4, HIGH);
      delay(200);
    }
  }

  
    else if(butt9State == LOW){
    //Decrement SSD1 value to 0.
    for(int e = (counter5++-2); e>=0; e--){
      digitalWrite(latch5, LOW);
      shiftOut(data5, clock5, LSBFIRST, digits[e]);
      digitalWrite(latch5, HIGH);
      delay(200);
   }
    //Decrement SSD2 value to 0.
    for(int f = (counter6++-2); f>=0; f--){
      digitalWrite(latch6, LOW);
      shiftOut(data6, clock6, LSBFIRST, digits[f]);
      digitalWrite(latch6, HIGH);
      delay(200);
    }
  }
}
