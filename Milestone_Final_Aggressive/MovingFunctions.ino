//MOVING FUNCTION
//Linear order of the Robot Steps. Place to change timing for each direction.
//Goes to right side of wall, lowers arm, and collects balls. Then turns to right and goes to black base and sorts balls.
//Dumps balls, turns 180 degress, and then goes to white base and dumps white balls. Does manuvur to turn 90 degress, then
//turns slightly to go to left side of divider. Collects balls, and then sorts and distributes to white then black base. 
void Moving(){ 
  switch(motorState){
    case 0://Spin Right
      checkTimeOut(millis(),300); break;
    case 1://Stop
      checkTimeOut(millis(),500); break;
    case 2://Go Forward
      checkTimeOut(millis(),1100); break;
    case 3://Stop
      checkTimeOut(millis(),500); break;
    case 4://Turn Left
      checkTimeOut(millis(),350); break;
    case 5://Stop
      checkTimeOut(millis(),500); break;
    case 6://Forward
      checkTimeOut(millis(),3000); break;
    case 7://Stop
      checkTimeOut(millis(),200); break;
    case 8://Spin Right
      checkTimeOut(millis(),70); break;
    case 9://Stop, Lower Gate
      checkTimeOut(millis(),1000); break;
    case 10://Backward
      if(beepBeeps<30)
      {
        beepBeep();
      }
      else //Changes to next Motor State
      {
        beepBeeps=0;//Reset Beeps
        checkTimeOut(millis(),0);
      }
      break;
    case 11://Stop, Lift Arm
      checkTimeOut(millis(),1000); break;
    case 12://Continue Backwards
      checkTimeOut(millis(),3000); break;
    case 13://Stop
      checkTimeOut(millis(),250); break;
    case 14://Quick Forward
      checkTimeOut(millis(),100); break;
    case 15://Stop
      checkTimeOut(millis(),500); break;
    case 16://Spin Right
      checkTimeOut(millis(),2000); break;
    case 17://Stop
      checkTimeOut(millis(),1000); break;
    case 18://Forward
      checkTimeOut(millis(),3000); break;
    case 19://Stop
      checkTimeOut(millis(),1000); break;
    case 20: //Wiggly
      if(numberOfWiggles<50)
      {
        wiggleTime1();
      }
      else //Change to next Motor State
      {
        numberOfWiggles=0;//Reset Wiggles
        checkTimeOut(millis(),0);
      }
      break;
    case 21://Dump Black Balls
      checkTimeOut(millis(),2000); break;
    case 22://Back up for Running Start
      checkTimeOut(millis(),300); break;
    case 23://Forward to slam
      checkTimeOut(millis(),2000); break;
    case 24://Backwards
      checkTimeOut(millis(),1000); break;
    case 25://Stop
      checkTimeOut(millis(),500); break;
    case 26:
      if(numberOfSpinLefts<25)
      {
        wallSpinLeft();
      }
      else //Change to next Motor State
      {
        numberOfSpinLefts=0;//Reset Wiggles
        checkTimeOut(millis(),0);
      }
      break;
    case 27://Forward to White Base
      checkTimeOut(millis(),5000); break;
    case 28://Stop, Lower White Gate
      checkTimeOut(millis(),3000); break;
    case 29://Back up for Running Start
      checkTimeOut(millis(),300); break;
    case 30://Forward to Slam
      checkTimeOut(millis(),700); break;
    case 31://Stop
      checkTimeOut(millis(),2400); break;
    case 32://Backup to attempt next wall side
      checkTimeOut(millis(),700); break;
    case 33://Stop
      checkTimeOut(millis(),500); break;
    case 34://Spin Right
      if(numberOfSpinRights<15)
      {
        wallSpinRight();
      }
      else //Change to next Motor State
      {
        numberOfSpinRights=0;//Reset Wiggles
        checkTimeOut(millis(),0);
      }
      break;
    case 35://Stop
      checkTimeOut(millis(),500); break;
    case 36://Forward
      checkTimeOut(millis(),4000); break;
    case 37://Stop
      checkTimeOut(millis(),500); break;
    case 38://Back Up
      checkTimeOut(millis(),5000); break;
    case 39://Stop
      checkTimeOut(millis(),300); break;
    case 40://Forward a Little Bit
      checkTimeOut(millis(),300); break;
    case 41://Stop
      checkTimeOut(millis(),500); break;
    case 42://Turn to face wall
      if(numberOfSpinRights<13)
      
      {
        wallSpinRight();
      }
      else //Change to next Motor State
      {
        numberOfSpinRights=0;//Reset Wiggles
        checkTimeOut(millis(),0);
      }
      break;
    case 43://Forward to corner
      checkTimeOut(millis(),4500); break;
    case 44://Spin Left
      checkTimeOut(millis(),200); break;
    case 45://Backward
      checkTimeOut(millis(),1000); break;
    case 46://Forward
      checkTimeOut(millis(),1500); break;
    case 47://Stop
      checkTimeOut(millis(),500); break;
    case 48://Spin Left
      checkTimeOut(millis(),120); break;
    case 49://Stop. Lower Gate
      checkTimeOut(millis(),1500); break;
    case 50://BeepBeep
      if(beepBeeps<20)
      {
        beepBeep2();
      }
      else if (beepBeeps<35)
      {
        beepBeep();
      }
      else //Changes to next Motor State
      {
        beepBeeps=0;//Reset Beeps
        checkTimeOut(millis(),0);
      }
      break;
    case 51://Raise Arm
      checkTimeOut(millis(),800); break;
    case 52://Back Up
      checkTimeOut(millis(),2000); break;
    case 53://Stop
      checkTimeOut(millis(),250); break;
    case 54://Quick Forward
      checkTimeOut(millis(),200); break;
    case 55://Stop
      checkTimeOut(millis(),500); break;
    case 56://Spin Left
      checkTimeOut(millis(),1400); break;
    case 57://Stop
      checkTimeOut(millis(),1000); break;
    case 58://Forward
      checkTimeOut(millis(),3000); break;
    case 59://Stop
      checkTimeOut(millis(),1000); break;
    case 60: //Wiggly
      if(numberOfWiggles<50)
      {
        wiggleTime2();
      }
      else //Change to next Motor State
      {
        numberOfWiggles=0;//Reset Wiggles
        checkTimeOut(millis(),0);
      }
      break;
    case 61://Stop
      checkTimeOut(millis(),2000); break;
    case 62://Back up for Running Start
      checkTimeOut(millis(),300); break;
    case 63://Forward to slam
      checkTimeOut(millis(),1000); break;
    case 64://Stop
      checkTimeOut(millis(),500); break;
    case 65://Backwards
      checkTimeOut(millis(),1000); break;
    case 66://Stop
      checkTimeOut(millis(),500); break;
    case 67:
      if(numberOfSpinRights<34)
      {
        wallSpinRight();
      }
      else //Change to next Motor State
      {
        numberOfSpinRights=0;//Reset Wiggles
        checkTimeOut(millis(),0);
      }
      break;
    case 68://Forward to Black Base
      checkTimeOut(millis(),5000); break;
    case 69://Stop, Lower Black Gate
      checkTimeOut(millis(),3000); break;
    case 70://Back up for Running Start
      checkTimeOut(millis(),300); break;
    case 71://Forward to Slam
      checkTimeOut(millis(),700); break;
    case 72://Stop
      checkTimeOut(millis(),5000); break;
    
    
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
    case 7: platformStop(); break; 
    case 8: platformSpinRight(); break;
    case 9: platformStop(); dumpBalls(3); break; //Lower Black Gate
    case 10: break; //Beep Beep
    case 11: platformStop(); dumpBalls(4); break; //Lift Black Gate
    case 12: platformBackward();break;
    case 13: platformStop(); break;
    case 14: platformForward();break;
    case 15: platformStop(); break;
    case 16: platformSpinRight(); break;
    case 17: platformStop(); break;
    case 18: platformForward(); break;
    case 19: platformStop(); dumpBalls(3);break;//Dump Black Balls
    case 20: break; //ITS WIGGLE TIME!!!
    case 21: platformStop(); break; 
    case 22: platformBackward(); break;
    case 23: platformForward(); break;
    case 24: platformBackward(); dumpBalls(4); break;
    case 25: platformStop(); break;
    case 26: break; //Spin Left
    case 27: platformForward(); break;
    case 28: platformStop(); dumpBalls(1);break; 
    case 29: platformBackward(); break;
    case 30: platformForward();break;
    case 31: platformStop(); break;
    case 32: platformBackward();dumpBalls(2);break;
    case 33: platformStop(); break;
    case 34: break;//Spin Right
    case 35: platformStop(); break;
    case 36: platformForward(); break;
    case 37: platformStop(); break;
    case 38: platformBackward(); break;
    case 39: platformStop(); break;
    case 40: platformForward(); break;
    case 41: platformStop(); break;
    case 42: break; //Spin Right
    case 43: platformForward(); break;
    case 44: platformSpinLeft(); break;
    case 45: platformBackward(); break;
    case 46: platformForward(); break;
    case 47: platformStop(); break;
    case 48: platformSpinLeft(); break;
    case 49: platformStop();dumpBalls(1); break;
    case 50: break; // Beep Beep
    case 51: platformStop(); dumpBalls(2); break;
    case 52: platformBackward(); break;
    case 53: platformStop(); break;
    case 54: platformForward(); break;
    case 55: platformStop(); break;
    case 56: platformSpinLeft(); break;
    case 57: platformStop(); break;
    case 58: platformForward(); break;
    case 59: platformStop(); dumpBalls(1); break;
    case 60: break; //SECOND WIGGLE TIME!!!
    case 61: platformStop(); break;
    case 62: platformBackward(); break;
    case 63: platformForward(); break;
    case 64: platformStop(); break;
    case 65: platformBackward(); dumpBalls(2); break;
    case 66: platformStop(); break;
    case 67: break; //Spin Right
    case 68: platformForward(); break;
    case 69: platformStop(); dumpBalls(3); break;
    case 70: platformBackward(); break;
    case 71: platformForward(); break;
    case 72: platformStop(); break;
    case 73: motorState=58; break;
    
  }
}

void checkTimeOut(unsigned long currentTime,unsigned long interval){
  if(currentTime-startTime>interval) //checks to see if it has passed the time interval
  {
    motorState++;
    Serial.println(motorState);
    changeMotorState(); //changes movement
    startTime=millis(); //resets timer
  }
}

void wiggleTime1() //Wiggle to shake balls up in ball pen (this one goes more to the right)
{
  if(millis()-wiggleTimer<250) //Spin left (more than right)
  {
    platformSpinLeft();
  }
  else if(millis()-wiggleTimer<300) //Stop
  {
    platformBackward();
  }
  else if(millis()-wiggleTimer<500) //Go right
  {
    platformSpinRight();
  }
  else if(millis()-wiggleTimer<550) //Stop
  {
    platformForward();
  }
   else if(millis()-wiggleTimer<1000) //Stop
  {
    platformStop();
  }
  else
  {
    wiggleTimer=millis(); //Reset
    numberOfWiggles++; //Count a wiggle
  }
}

void wiggleTime2() //Wiggle to shake balls up in ball pen (white side)
{
  if(millis()-wiggleTimer<250) //Go right (more than left)
  {
    platformSpinRight();
  }
  else if(millis()-wiggleTimer<300) //Stop
  {
    platformBackward();
  }
  else if(millis()-wiggleTimer<550) //Go left
  {
    platformSpinLeft();
  }
  else if(millis()-wiggleTimer<650) //Stop
  {
    platformForward();
  }
   else if(millis()-wiggleTimer<1000) //Stop
  {
    platformStop();
  }
  else
  {
    wiggleTimer=millis(); //Reset
    numberOfWiggles++; //Count a wiggle
  }
}

void beepBeep() //Backs up in intervals
{
  if(millis()-beepBeepTimer<150) //Go backwards 
  {
    leftBackward();
    rightBackward();
  }
  else if(millis()-beepBeepTimer<350) //Stop
  {
    platformStop();
  }
  else
  {
    //Serial.println("BeeP");
    beepBeepTimer=millis(); //Reset
    beepBeeps++; //Count a beep
  }
}
void beepBeep2() //Backs up in intervals with slight curve towards the right
{
  if(beepBeeps%3==0)
  {
    if(millis()-beepBeepTimer<150) //Go right backwards
    {
      leftBackward();
      rightStop();
    }
    else if(millis()-beepBeepTimer<350) //Stop
    {
      platformStop();
    }
    else
    {
      //Serial.println("BeeP");
      beepBeepTimer=millis(); //Reset
      beepBeeps++; //Count a beep
    }
  }
  else
  {
    if(millis()-beepBeepTimer<150) //Go backwards 
    {
      leftBackward();
      rightBackward();
    }
    else if(millis()-beepBeepTimer<350) //Stop
    {
      platformStop();
    }
    else
    {
      //Serial.println("BeeP");
      beepBeepTimer=millis(); //Reset
      beepBeeps++; //Count a beep
    }
  }
}

void wallSpinLeft() //Spin to the left in intervals
{
  if(millis()-wallSpinLeftTimer<40) //Go forward
  {
    platformForward();
  }
  else if(millis()-wallSpinLeftTimer<150) //Stop
  {
    platformStop();
  }
  else if(millis()-wallSpinLeftTimer<350) //Spin
  {
    platformSpinLeft();
  }
  else if(millis()-wallSpinLeftTimer<450) //Stop
  {
    platformStop();
  }
  else
  {
    wallSpinLeftTimer=millis(); //Reset
    numberOfSpinLefts++; //Count a spin
  }
}

void wallSpinRight() //Spin to the right in intervals
{
  if(millis()-wallSpinRightTimer<50) //Go forward
  {
    platformForward();
  }
  else if(millis()-wallSpinRightTimer<150) //Stop
  {
    platformStop();
  }
  else if(millis()-wallSpinRightTimer<350) //Spin
  {
    platformSpinRight();
  }
  else if(millis()-wallSpinRightTimer<450) //Stop
  {
    platformStop();
  }
  else
  {
    wallSpinRightTimer=millis(); //Reset
    numberOfSpinRights++; //Count a spin
  }
}
