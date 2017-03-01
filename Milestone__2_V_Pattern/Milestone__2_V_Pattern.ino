
/* Megan Keeler and Alex Stein
 *  Milestone 2 :  Matthew Stein, Mechatronics, Fall 2015
 *  Task: The challenge this week is to program the robots to navigate the playfield.  To complete this task, the robot must touch both the left far side of the wall and the right far side of the wall.  
 */

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

void setup() {
  // set the digital pin as output:
  pinMode(leftA, OUTPUT);      
  pinMode(leftB, OUTPUT);      
  pinMode(rightA, OUTPUT);      
  pinMode(rightB, OUTPUT);      
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
    if (motorState == 0) {
      platformForward();
      motorState = 1;
      interval = 5000;
      
    } else if (motorState == 1){
      platformStop();
      motorState = 2; 
      interval = 1500;
        
    } else if (motorState == 2) {
     platformBackward();
     motorState = 3;   
     interval = 5000; 
    
    } else if (motorState == 3){
      platformStop();
      motorState = 4; 
      interval = 1500;
        
    } else if (motorState == 4) {
      platformSpinRight();
    motorState = 5;   
    interval = 550; 
    
    } else if (motorState == 5){
      platformStop();
      motorState = 6;
      interval = 1500; 
        
    } else if (motorState == 6) {
      platformForward();
    motorState = 7;   
    interval = 8000; 

    } else if (motorState == 7){
      platformStop();
      motorState = 8;
      interval = 1500; 

     } else if (motorState == 8){
      platformBackward();
      motorState = 9;
      interval = 6000;

     } else if (motorState == 9){
      platformStop();
      motorState = 10;
      interval = 1500;

     } else if (motorState == 10){
      platformSpinLeft();
      motorState = 11;
      interval = 2000;

     } else if (motorState == 11){
      platformStop();
      motorState = 12;
      interval = 1500;

     } else if (motorState == 12){
      platformForward();
      motorState = 13;
      interval = 1800;

     } else if (motorState == 13){
      platformStop();
      motorState = 14;
      interval = 1500;

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
