//Alex Stein and Megan Keeler
//Set Motor control functions for robot. 
//Motor control functions...do not change!!
void platformStop() //Stop robot
{
  leftStop();
  rightStop();
}
void platformBackward () //Robot moves backwards
{
  leftBackward();
  rightBackward();
}
void platformSpinRight(){ //Robot turns to the right
  leftForward();
  rightBackward();
}
void platformSpinLeft(){ //Robot turns to the left
  leftBackward();
  rightForward();
}
void platformForward(){ //Robot goes forward
  leftForward();
  rightForward();
}

//Individual Wheel Functions
//Left Wheel
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

void leftForward()
{
      digitalWrite (leftA, HIGH);
      digitalWrite (leftB, LOW);
}

//Right Wheel
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

void rightForward()
{
      digitalWrite (rightA, HIGH);
      digitalWrite (rightB, LOW);
}  
