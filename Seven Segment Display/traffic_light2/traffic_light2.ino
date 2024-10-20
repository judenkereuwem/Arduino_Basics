//Traffic using Seven Segment Display and 74HC595
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

int LED1R = 18;
int LED1Y = 19;
int LED1G = 20;
int LED2R = 21;
int LED2Y = 22;
int LED2G = 23;
int LED3R = 24;
int LED3Y = 25;
int LED3G = 26;

int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;
int counter6 = 0;

int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246};

void setup() {
  //Shift registers
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

  //LEDs
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);

}

void loop() {

  delay(300);

    //First display
    for(int a = 5; a>=0; a--){
      for(int b = 9; b>=0; b--){
        digitalWrite(latch1, LOW);
        digitalWrite(latch2, LOW);
        shiftOut(data1, clock1, LSBFIRST, digits[a]);
        shiftOut(data2, clock2, LSBFIRST, digits[b]);
        digitalWrite(latch1, HIGH);
        digitalWrite(latch2, HIGH);
        delay(100);
        if((a <= 5)&&(a >= 1)&&(b >=0)){
          digitalWrite(LED1G, HIGH);
          digitalWrite(LED1Y, LOW);
          digitalWrite(LED1R, LOW);
        }
        else if((a <= 0)&&(a <=1)&&(b <=9)){
          digitalWrite(LED1Y, HIGH);
          digitalWrite(LED1G, LOW);
          digitalWrite(LED1R, LOW);
        }
        else if((a = 0)&& (b <=0)){
          digitalWrite(LED1R, HIGH);
          digitalWrite(LED1G, LOW);
          digitalWrite(LED1Y, LOW);

        }
      } 
    }

    //Second display
    for(int c = 5; c>=0; c--){
      for(int d = 9; d>=0; d--){
        digitalWrite(latch3, LOW);
        digitalWrite(latch4, LOW);
        shiftOut(data3, clock3, LSBFIRST, digits[c]);
        shiftOut(data4, clock4, LSBFIRST, digits[d]);
        digitalWrite(latch3, HIGH);
        digitalWrite(latch4, HIGH);
        delay(100);
        if((c <= 5)&&(c >= 1)&&(d >=0)){
          digitalWrite(LED2G, HIGH);
          digitalWrite(LED2Y, LOW);
          digitalWrite(LED2R, LOW);
        }
        else if((c <= 0)&&(c <=1)&&(d <=9)){
          digitalWrite(LED2Y, HIGH);
          digitalWrite(LED2G, LOW);
          digitalWrite(LED2R, LOW);
        }
        else{ //if((c <= 0)&&(c <=0)&&(d <= 0)){
          digitalWrite(LED2R, HIGH);
          digitalWrite(LED2G, LOW);
          digitalWrite(LED2Y, LOW);
        }
      }
   }

    //Third display
    for(int e = 5; e >=0; e--){
      for(int f = 9; f>=0; f--){
      digitalWrite(latch5, LOW);
      digitalWrite(latch6, LOW);
      shiftOut(data5, clock5, LSBFIRST, digits[e]);
      shiftOut(data6, clock6, LSBFIRST, digits[f]);
      digitalWrite(latch5, HIGH);
      digitalWrite(latch6, HIGH);
      delay(100);
      if((e <= 5)&&(e >= 1)&&(f >=0)){
          digitalWrite(LED3G, HIGH);
          digitalWrite(LED3Y, LOW);
          digitalWrite(LED3R, LOW);
        }
        else if((e <= 0)&&(e <=1)&&(f <=9)){
          digitalWrite(LED3Y, HIGH);
          digitalWrite(LED3G, LOW);
          digitalWrite(LED3R, LOW);
        }
        else{ //if((c <= 0)&&(c <=0)&&(d <= 0)){
          digitalWrite(LED3R, HIGH);
          digitalWrite(LED3G, LOW);
          digitalWrite(LED3Y, LOW);
        }
      }
    }
  }
