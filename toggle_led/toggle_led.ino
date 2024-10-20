
const int button_1 = 8;
int button_1_state;
const int led_1 = 13;
int led_1_state = 0;

void setup() {
    Serial.begin(9600);
    pinMode(led_1, OUTPUT);
    pinMode(button_1, INPUT_PULLUP);

}

void loop() {
  button_1_state = digitalRead(button_1);

  if ((button_1_state == 0) && (led_1_state == 0)){
    led_1_state = 1;
    if (led_1_state == 1){
      digitalWrite(led_1, HIGH);
    }

  }

  else if((button_1_state == 0) && (led_1_state == 1)){
    led_1_state = 0;
    if (led_1_state == 0){
    digitalWrite(led_1, LOW);
  }
  }

  Serial.println(led_1_state);
  delay(200);

}
