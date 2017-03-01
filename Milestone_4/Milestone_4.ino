#include <Servo.h>
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
                
//Constants(things that won't be changing)
const int leftA =  3;      // Left Motor A pin
const int leftB =  4;      // Left Motor B pin
const int rightA =  6;      // Right Motor A pin
const int rightB =  7;      // Right Motor B pin
const int colorSensor = A0;
int avgRead =0;
int pos = 0;
int numOfReads =3;

void setup() {
  // set the digital pin as output:
  pinMode(leftA, OUTPUT);      
  pinMode(leftB, OUTPUT);      
  pinMode(rightA, OUTPUT);      
  pinMode(rightB, OUTPUT); 
  
//PreState1
for (int i =0;i<11;i++){
  platformBackward();
  delay (300);
  platformStop();
  delay (200);
}


//PreState2
  platformStop();
  delay (2000);
  platformForward();
  delay (3000);
  platformStop();
 
pinMode (colorSensor, INPUT);
Serial.begin(9600);
myservo.attach(12);// attaches the servo on pin 12 to the servo object 
myservo.write(90); 
} 

void loop() {
  // State1 is the state where the servo will be waiting for the signal from the sensor. 
  State1();
  Serial.println(analogRead(colorSensor));
}

void State1(){
  //This state is the waiting and identifying state. 
  //If black then State2.
  for (int i=0; i<numOfReads; i++){
    avgRead+= analogRead (colorSensor);
   delay (500);
  }
  avgRead= avgRead/numOfReads;
  
  if (avgRead<=40){ 
    Serial.println ("White Ball");
    State3();
  }
  //If white then State3.
  if (avgRead>40 && avgRead<=600){
    Serial.println("BlackBall"); 
    State2();  
  }
  //If no ball, wait for ball.
  if(avgRead>600){
    Serial.println("No Ball");
    platformWiggle();
  }
  avgRead=0;
  
}

void State2(){
  //This is the black ball state.  If the ball is black, this state will be signalled and then it will sweep the servo to the right. 
 for(pos = 90; pos >= 0; pos -= 1) // goes from 90 degrees to 0 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 0; pos<=90; pos+=1)     // goes from 0 degrees to 90 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
}


void State3(){
  //This is the white ball state.  If the ball is white, this state will be signalled and then it will sweep the servo to the left. 
  for(pos = 90; pos <= 180; pos += 1) // goes from 90 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=90; pos-=1)     // goes from 180 degrees to 90 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }  

}




//Motor control functions...do not change!!
void platformWiggle()
{
  leftForward();
  rightForward();
  delay(1000);
  platformStop();
  delay (20);
  leftBackward();
  rightBackward();
  delay(800);
  platformStop();
  delay(20);
}  
  
void platformStop() 
{
  leftStop();
  rightStop();
}
//State2
void platformBackward ()
{
  leftBackward();
  rightBackward();
}

void platformForward(){
  leftForward();
  rightForward();
}
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
