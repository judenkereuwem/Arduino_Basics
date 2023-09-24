
const int TrigPin = 2;//Trig attach to pin2
const int EchoPin = 3;//Echo attach to pin3
float cm;


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
 
   cm = pulseIn(EchoPin, HIGH)/58.0;  
   cm = (int(cm * 100.0))/100.0;

   Serial.print("Distance: ");
   Serial.print(cm);
   Serial.println(" cm");
}
