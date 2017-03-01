/* Skelaton Program to test platform motion
 
  Drives backward, forward, spin left, spin right on 2-second intervals.
 
 */

// constants won't change. Used here to 
// set pin numbers:
const int leftA =  3;      // Left Motor A pin
const int leftB =  4;      // Left Motor B pin
const int rightA =  6;      // Right Motor A pin
const int rightB =  7;      // Right Motor B pin
// Variables will change:
int motorState = 0;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

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
    } else if (motorState == 1){
      platformStop();
      motorState = 2;   
    } else if (motorState == 2) {
     platformSpinLeft();
    motorState = 3;   
    } else if (motorState == 3){
      platformStop();
      motorState = 4;   
    } else if (motorState == 4) {
      platformSpinRight();
    motorState = 5;   
    } else if (motorState == 5){
      platformStop();
      motorState = 6;  
    } else if (motorState == 6) {
      platformBackward();
    motorState = 7;   
    } else {
      platformStop();
      motorState = 0;  
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
