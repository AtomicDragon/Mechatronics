
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
  }   

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
     platformSpinLeft();
     motorState = 3;   
     interval = 2000; 
    
    } else if (motorState == 3){
      platformStop();
      motorState = 4; 
      interval = 1500;
        
    } else if (motorState == 4) {
      platformForward();
    motorState = 5;   
    interval = 10000; 
    
    } else if (motorState == 5){
      platformStop();
      motorState = 6;
      interval = 1500; 
        
    } else if (motorState == 6) {
      platformSpinLeft();
    motorState = 7;   
    interval = 4000; 

    } else if (motorState == 7){
      platformStop();
      motorState = 8;
      interval = 1500; 

     } else if (motorState == 8){
      platformForward();
      motorState = 9;
      interval = 10000;

     } else if (motorState == 9){
      platformStop();
      motorState = 10;
      interval = 1500;

     } else if (motorState == 10){
      platformSpinLeft();
      motorState = 11;
      interval = 3000;
   
     } else if (motorState == 11){
      platformStop();
      motorState = 12;
      interval = 1500;
    
     } else if (motorState == 12){
      platformForward();
      motorState = 13;
      interval = 7000;
      
     } else if (motorState == 13){
      platformStop();
      motorState = 14;
      interval = 1500;
      
     } else if (motorState == 14){
      platformSpinRight();
      motorState = 15;
      interval = 3000;
      
      } else if (motorState == 15){
      platformStop();
      motorState = 16;
      interval = 1500;
      
      } else if (motorState == 16){
      platformForward();
      motorState = 17;
      interval = 10000;
      
      } else if (motorState == 17){
      platformStop();
      motorState = 18;
      interval = 1500;
      
      } else if (motorState == 18){
      platformSpinRight();
      motorState = 19;
      interval = 3000;

      } else if (motorState == 19){
      platformStop();
      motorState = 20;
      interval = 1500;

      } else if (motorState == 20){
      platformForward();
      motorState = 21;
      interval = 10000;

      } else if (motorState == 21){
      platformStop();
      motorState = 22;
      interval = 1500;

      } else if (motorState == 22){
      platformSpinLeft();
      motorState = 23;
      interval = 3000;

      } else if (motorState == 23){
      platformStop();
      motorState = 24;
      interval = 1500;

      } else if (motorState == 24){
      platformForward();
      motorState = 25;
      interval = 5000;

      } else if (motorState == 25){
      platformStop();
      motorState = 26;
      interval = 1500;  
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
