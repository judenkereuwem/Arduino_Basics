#define LATCH  8  //Pin connected to ST_CP of 74HC595
#define CLOCK  12 //Pin connected to SH_CP of 74HC595
#define DATA  11 //Pin connected to DS of 74HC595

int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};

void displayNumber(int n){
  int left, right=0;
  if(n < 10){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[n]);
    shiftOut(DATA, CLOCK, LSBFIRST, 0);
    digitalWrite(LATCH, HIGH);
  }
  else if (n>=10){
    right = n % 10;
    left = n / 10;
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[right]);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[left]);
    digitalWrite(LATCH, HIGH);
  }
}

void setup() {
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

}

void loop() {
  int i;
  for(i = 0; i<100; i++){
    displayNumber(i);
    delay(100);
  }

}
