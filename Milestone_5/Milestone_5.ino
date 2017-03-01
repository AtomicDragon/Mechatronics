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
const int leftA =  3;      // Left Motor A pin
const int leftB =  4;      // Left Motor B pin
const int rightA =  6;      // Right Motor A pin
const int rightB =  7;      // Right Motor B pin

//Motor State Variables
int motorState=0; //Controls the plan for the robot to follow
unsigned long startTime=0; //When a state begins
long wiggleTimer=0; //when the wiggle begins
int numberOfWiggles=0; //counts how many wiggles have happened

//Sorting Hat Variables
const int colorSensor = A0;
long avgRead =0; //Average reading from color sensor
int numOfReads=3; //How many reads color sensor will take before determining a ball color
int currentReads=1; //What read it is currently on
unsigned long readingInterval=1000; //Time interval between reads
unsigned long startReadTime=0; //Millis purposes

//Sorting Hat Turning Variables
const int sortingCenter=70; // Center position for the sorter
boolean blackBallSensed=false;//black ball is being moved to black dumpster
boolean whiteBallSensed=false;//white ball is being moved to white dumpster
unsigned long servoTurnInterval = 1000;//milliseconds it takes to rotate 90 degrees
unsigned long startTurnTime=0; //start of when ball starts turning

//Dumpster Switches
const int whiteCenter =90; //Center position of white servo
const int blackCenter =90; //Center position of black servo
boolean dumpingWhiteBalls = false; //White gate is currently going down
boolean dumpingBlackBalls = false; //Black gate is currently going down
boolean liftingWhiteBalls = false; //White gate is currently going up
boolean liftingBlackBalls = false; //Black gate is currently going up
unsigned long servoDumpInterval = 1000; //Time it takes to dump or lift
unsigned long startDumpingTime=0; //start time for dumping
unsigned long startLiftingTime=0; //start time for lifting



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
  //gateWhite.write(whiteCenter); //moves servo to center pos
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

void Moving(){ //Linear order of the Robot Steps. Place to change timing for each direction.
  switch(motorState){
    case 0://Spin Right
      checkTimeOut(millis(),600); break;
    case 1://Stop
      checkTimeOut(millis(),1500); break;
    case 2://Go Forward
      checkTimeOut(millis(),1900); break;
    case 3://Stop
      checkTimeOut(millis(),1500); break;
    case 4://Turn Left
      checkTimeOut(millis(),650); break;
    case 5://Stop
      checkTimeOut(millis(),1500); break;
    case 6://Forward
      checkTimeOut(millis(),4000); break;
    case 7://Stop
      checkTimeOut(millis(),1500); break;
    case 8://Spin Right
      checkTimeOut(millis(),200); break;
    case 9://Stop
      checkTimeOut(millis(),1500); break;
    case 10://Backward
      checkTimeOut(millis(),4000); break;
    case 11://Stop
      checkTimeOut(millis(),1500); break;
    case 12://Spin Right
      checkTimeOut(millis(),2000); break;
    case 13://Stop
      checkTimeOut(millis(),1500); break;
    case 14://Forward
      checkTimeOut(millis(),4000); break;
    case 15://Stop
      checkTimeOut(millis(),1000); break;
    case 16:
      if(numberOfWiggles<10)
      {
        wiggleTime();
      }
      break;
    case 17:
      checkTimeOut(millis(),1000); break;
    case 18:
      checkTimeOut(millis(),100); break;
  }
}

void changeMotorState(){//Used to Change motorState. This setup is used so program isnt constantly calling motorControlFunctions. Should reflect actions in Moving().
  switch(motorState){
    case 0: platformSpinRight();break;
    case 1: platformStop();break;
    case 2: platformForward();break; 
    case 3: platformStop();break;
    case 4: platformSpinLeft();break;
    case 5: platformStop();break;
    case 6: platformForward();break;
    case 7: platformStop(); dumpBalls(2); break; //DumpBlackBalls
    case 8: platformSpinRight(); break;
    case 9: platformStop(); break;
    case 10: platformBackward();break;
    case 11: platformStop(); dumpBalls(3); break; //Lift Black Gate
    case 12: platformSpinRight(); break;
    case 13: platformStop(); break;
    case 14: platformForward(); break;
    case 15: platformStop(); break;
    case 16: break; //ITS WIGGLE TIME!!!
    case 17: platformForward(); break;
    case 18: dumpBalls(2); break; //DumpBlackBalls
  }
}

void checkTimeOut(int currentTime,int interval){
  if(currentTime-startTime>interval) //checks to see if it has passed the time interval
  {
    motorState++;
    changeMotorState(); //changes movement
    startTime=millis(); //resets timer
  }
}

void Sorting(){
  if(blackBallSensed) //Currently sorting a black ball
  {
    BlackBallSorting(millis()-startTurnTime); 
  }
  else if (whiteBallSensed) //Currently sorting a white ball
  {
    WhiteBallSorting(millis()-startTurnTime);
  }
  else if (millis()-startReadTime>readingInterval*currentReads) //Checks number of times before having a final read
  {
    avgRead += analogRead(colorSensor);
    if(currentReads==numOfReads)//Last read?
    {
      avgRead=avgRead/(numOfReads); //get actual read value
      if (avgRead<=40){ //Reads White Ball.
        Serial.print("White Ball");
        Serial.print(", ");
        Serial.println(avgRead);
        whiteBallSensed=true;
        startTurnTime =millis();
      }
        if (avgRead>40 && avgRead<=600){ //Black Ball Sensed
        Serial.print("BlackBall");
        Serial.print(", ");
        Serial.println(avgRead); 
        blackBallSensed=true;
        startTurnTime = millis();  
      }
      if(avgRead>600){ //No Ball Sensed
        Serial.print("No Ball");
        Serial.print(", ");
        Serial.println(avgRead);
      }
      currentReads=0; //reset number of reads, time, and average
      avgRead=0;
      startReadTime=millis();
    }
    currentReads++;
  }
}

void BlackBallSorting(long i){
  //This is the black ball state.  If the ball is black, this state will be signalled and then it will sweep the servo to the right. 
  if(i<servoTurnInterval) // goes from 90 degrees to 0 degrees 
  {                                 
    sortingHat.write(sortingCenter-i*sortingCenter/servoTurnInterval);              // tell servo to go to position by time divided by time interval
  } 
  else if(i<servoTurnInterval*2)    // goes from 0 degrees to 90 degrees 
  {                                
    sortingHat.write((i-servoTurnInterval)*sortingCenter/servoTurnInterval);              // tell servo to go to position by time divided by time interval
  }
  else
  {
    startReadTime=millis();
    blackBallSensed=false; //No longer sorting
  }
}


void WhiteBallSorting(long i){
  //This is the white ball state.  If the ball is white, this state will be signalled and then it will sweep the servo to the left. 
  if(i<servoTurnInterval) // goes from 90 degrees to 180 degrees 
  {                                 
    sortingHat.write(sortingCenter+i*sortingCenter/servoTurnInterval);              // tell servo to go to position by time divided by time interval
  } 
  else if(i<servoTurnInterval*2)    // goes from 180 degrees to 90 degrees 
  {                                
    sortingHat.write(sortingCenter*2-(i-servoTurnInterval)*sortingCenter/servoTurnInterval);              // tell servo to go to position by time divided by time interval
  }
  else
  {
    startReadTime=millis(); 
    whiteBallSensed=false; //No longer sorting
  }
}

void Dumping(){
  /*if(dumpingWhiteBalls==true)
  {dumpWhiteBalls(millis()-startDumpingTime);}
  else if(liftingWhiteBalls==true)
  {liftWhiteBalls(millis()-startLiftingTime);} took out white ball for milestone 5*/
  if (dumpingBlackBalls==true)
  {dumpBlackBalls(millis()-startDumpingTime);} //Dump black balls
  else if(liftingBlackBalls==true)
  {liftBlackBalls(millis()-startLiftingTime);} //Lift black gate
}

void dumpBalls(int s){
  if(s==1)//Dump White
  {
    dumpingWhiteBalls=true;
    startDumpingTime=millis(); //Set start time
  }
  else if(s==2) //Dump Black
  {
    dumpingBlackBalls=true;
    startDumpingTime=millis(); //Set start time
  }
  else if(s==3) //Lift Black
  {
    liftingBlackBalls=true;
    startLiftingTime=millis(); //Set start time
  }
}

void dumpWhiteBalls(long i){
  if(i<servoDumpInterval) // goes from 90 degrees to 0 degrees 
  {                              
    gateWhite.write(whiteCenter-i*whiteCenter/servoDumpInterval);   // tell servo to go to position by time divided by time interval 
  }
  else if(i<servoDumpInterval*5)     
  {} //wait
  else if(i<servoDumpInterval*6)  // goes from 0 degrees to 90 degrees
  {
    gateWhite.write((i-servoDumpInterval*5)*whiteCenter/servoDumpInterval);  // tell servo to go to position by time divided by time interval
  }
  else
  {
    dumpingWhiteBalls=false; //No longer dumping
  }
}

void dumpBlackBalls(long i){
  if(i<servoDumpInterval) // goes from 90 degrees to 180 degrees 
  {                                  
    gateBlack.write(blackCenter+i*blackCenter/servoDumpInterval);  // tell servo to go to position by time divided by time interval 
  } 
  else
  {
    dumpingBlackBalls=false; //No longer dumping
  }
}

void liftBlackBalls(long i)
{
  if(i<servoDumpInterval)
  {
    gateBlack.write(blackCenter*2-i*blackCenter/servoDumpInterval);  // tell servo to go to position by time divided by time interval
  }
  else
  {
    liftingBlackBalls=false; //No longer lifting
  }
}

void wiggleTime() //Wiggle to shake balls up in ball pen
{
  if(millis()-wiggleTimer<1000) //Go forward
  {
    leftForward();
    rightForward();
  }
  else if(millis()-wiggleTimer<2050) //Stop
  {
    platformStop();
  }
  else if(millis()-wiggleTimer<2600) //Go backwards (less than forward)
  {
    leftBackward();
    rightBackward();
  }
  else if(millis()-wiggleTimer<2640) //Stop
  {
    platformStop();
  }
  else
  {
    wiggleTimer=millis(); //Reset
    numberOfWiggles++; //Count a wiggle
  }
}


