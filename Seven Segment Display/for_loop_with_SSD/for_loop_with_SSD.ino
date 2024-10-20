#define LATCH  8  //Pin connected to ST_CP of 74HC595
#define CLOCK  12 //Pin connected to SH_CP of 74HC595
#define DATA  11 //Pin connected to DS of 74HC595

int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, };//238, 62, 156, 122, 158, 142};

void setup() {
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

}

void loop() {
  
/*for(int j = 0; j<9; j++){
  for(int i = 0; i<9; i++){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[i]);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[j]);
    digitalWrite(LATCH, HIGH);
    delay(100);
  }
}*/

for(int j = 9; j>0; j--){
  for(int i = 9; i>0; i--){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, digits[i]);
    shiftOut(DATA, CLOCK, MSBFIRST, digits[j]);
    digitalWrite(LATCH, HIGH);
    delay(100);
  }
}

}
