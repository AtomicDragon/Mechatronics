/*
  Alex Stein and Megan Keeler
  Mechatronics Milestone 5
  Matthew Stein
  
  This program uses three Finite State Machines: Sorting, Driving, and Dumping. This is done using millis, so a lot of the code is
  meant for setting start times and checking what state something is in. 
  Sorter: Detects color and sorts between black, white, and no ball
  Driving: Moves the robot around the playing feild in a set order
  Dumping: When it gets a dump command from the Driver, lifts or lowers one of the two gates to dump balls or reset gate
  
*/

#include <Servo.h>

Servo sortingHat; //Pin 12
Servo gateBlack; //Pin 10
Servo gateWhite; //Pin 11
                
//Motor Wire Constants(things that won't be changing)
const int leftA =  6;      // Left Motor A pin
const int leftB =  7;      // Left Motor B pin
const int rightA =  3;      // Right Motor A pin
const int rightB =  4;      // Right Motor B pin

//Motor State Variables
int motorState=31; //Controls the plan for the robot to follow
unsigned long startTime=0; //When a state begins
long wiggleTimer=0; //when the wiggle begins
int numberOfWiggles=0; //counts how many wiggles have happened
long beepBeepTimer=0;
int beepBeeps=0;
long wallSpinLeftTimer=0;
int numberOfSpinLefts=0;
long wallSpinRightTimer=0;
int numberOfSpinRights=0;

//Sorting Hat Variables
const int colorSensor = A0;
long avgRead =0; //Average reading from color sensor
int numOfReads=4; //How many reads color sensor will take before determining a ball color
int currentReads=1; //What read it is currently on
unsigned long readingInterval=500; //Time interval between reads
unsigned long startReadTime=0; //Millis purposes

//Sorting Hat Turning Variables
const int sortingCenter=80; // Center position for the sorter
boolean blackBallSensed=false;//black ball is being moved to black dumpster
boolean whiteBallSensed=false;//white ball is being moved to white dumpster
unsigned long servoTurnInterval = 250;//milliseconds it takes to rotate 90 degrees
unsigned long startTurnTime=0; //start of when ball starts turning

//Dumpster Switches
const int whiteCenter =90; //Center position of white servo
const int blackCenter =80; //Center position of black servo
boolean dumpingWhiteBalls = false; //White gate is currently going down
boolean dumpingBlackBalls = false; //Black gate is currently going down
boolean liftingWhiteBalls = false; //White gate is currently going up
boolean liftingBlackBalls = false; //Black gate is currently going up
unsigned long servoDumpInterval = 1000; //Time it takes to dump or lift
unsigned long servoLiftInterval = 1000;
unsigned long startDumpingTime=0; //start time for dumping
unsigned long startLiftingTime=0; //start time for lifting
int pos=0;



void setup() {
  // set the digital pin as output:
  pinMode(leftA, OUTPUT);      
  pinMode(leftB, OUTPUT);      
  pinMode(rightA, OUTPUT);      
  pinMode(rightB, OUTPUT); 
 
  pinMode (colorSensor, INPUT);
  Serial.begin(9600);
  
  gateWhite.attach(10);// attaches the servo on pin 11 to the White Gate Servo
  gateBlack.attach(11);// attaches the servo on pin 10 to the Black Gate Servo
  sortingHat.attach(12);// attaches the servo on pin 12 to the Sorting Hat Servo
  sortingHat.write(sortingCenter); //moves servo to center pos
  gateWhite.write(whiteCenter); //moves servo to center pos
  gateBlack.write(blackCenter);//moves servo to center pos

  
  changeMotorState(); //Start movement
} 

void loop() { 
  Sorting();
  Moving();
  Dumping();
  Serial.print(analogRead(colorSensor));
  Serial.print(", ");
  Serial.println(currentReads);
  
}




