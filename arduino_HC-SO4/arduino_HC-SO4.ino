
//Arduino
const int TrigPin = 3;//Trig attach to pin2
const int EchoPin = 5;//Echo attach to pin3

//ESP32
//const int TrigPin = 5;//Trig attach to pin5
//const int EchoPin = 18;//Echo attach to pin18

void setup() {
   pinMode(TrigPin,OUTPUT);
   pinMode(EchoPin,INPUT);
   Serial.begin(9600);
}


void loop(){
   digitalWrite(TrigPin,LOW);
   delayMicroseconds(2);
   digitalWrite(TrigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(TrigPin,LOW);
 
   long duration = pulseIn(EchoPin, HIGH); 
   int distance = (duration/2)/29.1;

   Serial.print("Distance: ");
   Serial.print(distance);
   Serial.println(" cm");

   delay(200);
}
