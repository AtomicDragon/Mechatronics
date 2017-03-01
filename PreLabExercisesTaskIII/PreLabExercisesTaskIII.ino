/*
  Task III 
  Counts in binary and then outputs it to the four different outputs. 
  Alex Stein and Megan Keeler
  Mechatronics Fall 2015 Matthew Stein
  
*/
  const int bit0Pin = 4;  //first bit output pin
  const int bit1Pin = 5;  //second bit output pin
  const int bit2Pin = 6;  //third bit output pin
  const int bit3Pin = 7;  //fourth bit output pin
  int count = 0;
  
//Setup routine to establish bits
void setup(){
  pinMode(bit0Pin, OUTPUT);
  pinMode(bit1Pin, OUTPUT);
  pinMode(bit2Pin, OUTPUT);
  pinMode(bit3Pin, OUTPUT);
}

//Loop routine to run bit output over and over again.
void loop(){
  digitalWrite(bit0Pin, HIGH && (count & B00000001)); //Checks to see if there is a 1 in bit0. If there is it writes to it.
  digitalWrite(bit0Pin, HIGH && (count & B00000010)); //Checks to see if there is a 1 in bit1. If there is it writes to it.
  digitalWrite(bit0Pin, HIGH && (count & B00000100)); //Checks to see if there is a 1 in bit2. If there is it writes to it.
  digitalWrite(bit0Pin, HIGH && (count & B00001000)); //Checks to see if there is a 1 in bit3. If there is it writes to it.
  
  if (count == 15){                                    //If count equals max 4 bit number it resets to 015
     count =0;
  }
  else{
     count++;                                         //Adds 1 to the count.
  }
}

