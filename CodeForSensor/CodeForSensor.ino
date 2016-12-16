


// Set up speaker on a PWM pin (digital 9, 10 or 11)
int speakerOut = 9;
int trigPin=5;
int echoPin=4;
float speedofSound=776.5;
float pingTime;
float targetDistance;
//the time when the sensor outputs a low impulse



void setup() { 
  pinMode(speakerOut, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT );
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  
}


 
  void loop() {  
     digitalWrite(speakerOut,LOW);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delay(15);
  digitalWrite(trigPin, LOW);
  pingTime=pulseIn(echoPin,HIGH);
  pingTime=(pingTime/1000000)/3600;
  targetDistance=((speedofSound * pingTime)/2 ) * 63360;
  targetDistance= targetDistance * 0.0254;
  Serial.println(targetDistance);
   if (targetDistance < 1.5) {
    tone(speakerOut, 1000, 300);
   }
  delay(1000); 
}
