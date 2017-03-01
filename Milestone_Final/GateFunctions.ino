//DUMPSTER FUNCTIONS
void Dumping(){
  if(dumpingWhiteBalls==true)
  {dumpWhiteBalls(millis()-startDumpingTime);} //Dump white balls
  else if(liftingWhiteBalls==true)
  {liftWhiteBalls(millis()-startLiftingTime);} //Lift white gate
  
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
  else if(s==2)
  {
    liftingWhiteBalls=true;
    startLiftingTime=millis();
  }
  else if(s==3) //Dump Black
  {
    dumpingBlackBalls=true;
    startDumpingTime=millis(); //Set start time
  }
  else if(s==4) //Lift Black
  {
    liftingBlackBalls=true;
    startLiftingTime=millis(); //Set start time
  }
}

//WHITE
void dumpWhiteBalls(long i){
  if(i<servoDumpInterval) // goes from 90 degrees to 0 degrees 
  {                              
    gateWhite.write(whiteCenter-i*(whiteCenter-5)/servoDumpInterval);   // tell servo to go to position by time divided by time interval 
  }
  else
  {
    dumpingWhiteBalls=false; //No longer dumping
  }
}

void liftWhiteBalls(long i){
  if(i<servoLiftInterval) // goes from 0 to 90 degrees
  {
    gateWhite.write(5+i*whiteCenter/servoLiftInterval);  // tell servo to go to position by time divided by time interval
  }
  else
  {
    liftingWhiteBalls=false; //No longer lifting
  }
}

//BLACK
void dumpBlackBalls(long i){
  if(i<servoDumpInterval) // goes from 90 degrees to 190 degrees 
  {                                  
    gateBlack.write(blackCenter+i*(180-blackCenter-15)/servoDumpInterval);  // tell servo to go to position by time divided by time interval 
  } 
  else
  {
    dumpingBlackBalls=false; //No longer dumping
  }
}

void liftBlackBalls(long i) // goes from 190 degrees to 90 degrees
{
  if(i<servoLiftInterval)
  {
    pos =(180-15)-i*blackCenter/servoLiftInterval;
    gateBlack.write(pos);  // tell servo to go to position by time divided by time interval
    //Serial.println(pos);
  }
  else
  {
    liftingBlackBalls=false; //No longer lifting
  }
}
