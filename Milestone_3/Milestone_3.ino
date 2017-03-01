
/* Megan Keeler and Alex Stein
 *  Milestone 3 :  Matthew Stein, Mechatronics, Fall 2015
 *  Task: The challenge this week is to program the robot to pick up one ball and deliver it to the other base. 
 */
 
#include <Servo.h> 

// constants won't change. Used here to 
// set pin numbers:
const int leftA =  3;      // Left Motor A pin
const int leftB =  4;      // Left Motor B pin
const int rightA =  6;      // Right Motor A pin
const int rightB =  7;      // Right Motor B pin
// Variables will change:
int motorState = 0;             //setting the motorState variable to 0. 
long previousMillis = 0;       //start time for each state 

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 2000;           // interval at which to change

Servo slothArm;  // create servo object to control sloth arm servo 
Servo gate;      // create servo object to control gate for balls          
 
int pos1 = 0;    // variable to store the servo position
int pos2 = 0;

void setup() {
  // set the digital pin as output:
  pinMode(leftA, OUTPUT);      
  pinMode(leftB, OUTPUT);      
  pinMode(rightA, OUTPUT);      
  pinMode(rightB, OUTPUT);
  slothArm.attach(8);
  gate.attach(9);  
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to change state; that is, if the 
  // difference between the current time and last time you changed 
  // state is bigger than the interval 
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time changed state 
    previousMillis = currentMillis;
     

    // Every interval change state
    if (motorState == 0) { //Go foward out of base
      platformForward();
      motorState = 1;
      interval = 2000;
      
    } else if (motorState == 1){ //Stop
      platformStop();
      motorState = 2; 
      interval = 1500;
        
    } else if (motorState == 2) { //Turn towards wall
     platformSpinLeft();
     motorState = 3;   
     interval = 1000; 
    
    } else if (motorState == 3){ //Stop
      platformStop();
      motorState = 4; 
      interval = 1500;
        
    } else if (motorState == 4) { //Forward into wall
      platformForward();
    motorState = 5;   
    interval = 3000; 
    
    } else if (motorState == 5){//Stop and Move Sloth Arm
      platformStop();
      motorState = 6;
      interval = 1500;
      
      for(pos1 = 180; pos1>=1; pos1-=1)     // goes from 180 degrees to 0 degrees 
      {                                
         slothArm.write(pos1);              // tell servo to go to position in variable 'pos' 
         delay(15);                       // waits 15ms for the servo to reach the position 
      }   
    } else if (motorState == 6) { //Back Up
      
      platformBackward();
      motorState = 7;   
      interval = 4000; 

    } else if (motorState == 7){ //Stop and Raise Sloth Arm
      platformStop();
      motorState = 8;
      interval = 1500; 
      for(pos1 = 0; pos1<180; pos1+=1)     // goes from 180 degrees to 0 degrees 
      {                                
         slothArm.write(pos1);              // tell servo to go to position in variable 'pos' 
         delay(15);                       // waits 15ms for the servo to reach the position 
      }

     } else if (motorState == 8){ //Back up back to start
      platformBackward();
      motorState = 9;
      interval = 6000;

     } else if (motorState == 9){ //Stop
      platformStop();
      motorState = 10;
      interval = 1500;

     } else if (motorState == 10){ //Spin left towards other base
      platformSpinLeft();
      motorState = 11;
      interval = 2000;

     } else if (motorState == 11){ //Stop
      platformStop();
      motorState = 12;
      interval = 1500;

     } else if (motorState == 12){//Drive towards base
      platformForward();
      motorState = 13;
      interval = 5000;

     } else if (motorState == 13){ //Stop and Raise Gate
      platformStop();
      motorState = 14;
      interval = 1500;
      
      for(pos2 = 0; pos2<90; pos2+=1)     // goes from 180 degrees to 0 degrees 
      {                                
         gate.write(pos2);              // tell servo to go to position in variable 'pos' 
         delay(15);                       // waits 15ms for the servo to reach the position 
      }
     }
     
    
  }
}
void platformForward()
{
  leftForward();
  rightForward();
}
void platformBackward()
{
  leftBackward();
  rightBackward();
}
void platformStop()
{
  leftStop();
  rightStop();
}
void platformSpinLeft()
{
  leftBackward();
  rightForward();
}
void platformSpinRight()
{
  rightBackward();
  leftForward();
}
//left
void leftForward()
{
      digitalWrite(leftA, HIGH);
      digitalWrite(leftB, LOW); 
}
void leftBackward()
{
      digitalWrite(leftA, LOW);
      digitalWrite(leftB, HIGH); 
}

void leftStop()
{
      digitalWrite(leftA, LOW);
      digitalWrite(leftB, LOW); 
}
//right
void rightForward()
{
      digitalWrite(rightA, HIGH);
      digitalWrite(rightB, LOW); 
}
void rightBackward()
{
      digitalWrite(rightA, LOW);
      digitalWrite(rightB, HIGH); 
}

void rightStop()
{
      digitalWrite(rightA, LOW);
      digitalWrite(rightB, LOW); 
}
