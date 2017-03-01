/*
  Task II 
  Testing the motors to see if they work and are in the right orientation 
  Alex Stein and Megan Keeler
  Mechatronics Fall 2015 Matthew Stein
  
*/

const int APin = 2;  //first bit output bit
const int BPin = 3;  //second bit output bit
const int CPin = 4;  //third bit output bit
const int DPin = 5;  //fourth bit output bit
  
//Setup routine to establish motors
void setup(){
  pinMode(APin, OUTPUT);
  pinMode(BPin, OUTPUT);
  pinMode(CPin, OUTPUT);
  pinMode(DPin, OUTPUT);
  
}

//Loop routine to run test motors. 
void loop(){
  digitalWrite(DPin, LOW);
  digitalWrite(APin, HIGH);
  digitalWrite(BPin, LOW);
  delay(2000);
  digitalWrite(APin, LOW);
  digitalWrite(BPin, HIGH);
  delay(2000);
  digitalWrite(BPin, LOW);
  digitalWrite(CPin, HIGH);
  digitalWrite(DPin, LOW);
  delay(2000);
  digitalWrite(CPin, LOW);
  digitalWrite(DPin, HIGH);
  delay(2000);
}

