#define samp_siz 4
#define rise_threshold 4

int sensorPin = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  float reads[samp_siz], sum;
  long int now, ptr;
  float last, reader, start;
  float first, second, third, before, print_value;
  bool rising;
  int rise_count;
  int n;
  long int last_beat;
  
  for(int i = 0; i< samp_siz; i++)
  reads[i] = 0;
  sum = 0;
  ptr = 0;
  
  while(1){
    n = 0;
    start = millis();
    reader = 0.;
    do{
      reader += analogRead(sensorPin);
      n++;
      now = millis();
    }
    while(now < start + 20);
    reader /= n;
    sum -= reads[ptr];
    sum += reader;
    reads[ptr] = reader;
    last = sum / samp_siz;

    if(last > before){
      rise_count++;
      if(!rising && rise_count > rise_threshold){
        rising = true;
        first = millis() - last_beat;
        last_beat = millis();
        print_value = 60000. / (0.4*first+0.3*second +0.3*third);
        
        Serial.print(print_value);
        Serial.print('\n');
        
        third = second;
        second = first;
      }
    }
    else{
        rising = false;
        rise_count = 0;
      }
      before = last;
      ptr++;
      ptr%=samp_siz;
    }
  }
