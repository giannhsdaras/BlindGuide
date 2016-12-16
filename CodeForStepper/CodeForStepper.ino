#include <AccelStepper.h> //library for motor
#define HALFSTEP 8

// Motor pin definitions
#define motorPin1  0    // IN1 on the ULN2003 driver 1
#define motorPin2  1     // IN2 on the ULN2003 driver 1
#define motorPin3  2     // IN3 on the ULN2003 driver 1
#define motorPin4  3     // IN4 on the ULN2003 driver 1
//keypad initialization follows
#include <Keypad.h>
const byte rows = 4; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[rows] = {12,11,10,9}; //connect to the row pinouts of the keypad
byte colPins[cols] = {8,7,6,5}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
    

//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 200;  

boolean lockLow = true;
boolean takeLowTime;  


int ledPin = 13;
/////////////////////////// SPEAKER //////////////////////////////////////////////////

/////////////////////////////////

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
float initialPosition=stepper1.currentPosition();
char key=2;
  
void setup() {
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(1000);
  stepper1.setSpeed(3000);
 stepper1.moveTo(250);
 
//  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  //digitalWrite(pirPin, LOW);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  
  
  
  
 
 

}//--(end setup )---



void loop() {
   
  char key=keypad.getKey();
   
 if (key=='1') {
   stepper1.setSpeed(0);
   
  }
  if (key=='2') {
    stepper1.setSpeed(3000);
    stepper1.moveTo(250);
  }
  if (key=='3') {
    stepper1.moveTo(initialPosition);
   
   
   
    
  }
  stepper1.run();
  if (initialPosition==stepper1.currentPosition()) ;
  
  if (stepper1.distanceToGo()==0 ) {
    stepper1.moveTo(-stepper1.currentPosition());
    
  }
  //if (stepper1.distanceToGo()==0 && key=='3') stepper1.setSpeed(0);
  /* if (stepper1.currentPosition()==500 ) {
    stepper1.setSpeed(0);
    stepper1.stop();
    
    stepper1.setSpeed(3000);
    stepper1.moveTo(250); 
   
  } */
  
  
  

}
