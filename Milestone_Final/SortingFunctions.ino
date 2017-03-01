//SORTING FUNCTIONS
void Sorting(){
  if(blackBallSensed) //Currently sorting a black ball
  {
    BlackBallSorting(millis()-startTurnTime); 
  }
  else if (whiteBallSensed) //Currently sorting a white ball
  {
    WhiteBallSorting(millis()-startTurnTime);
  }
  else if (millis()-startReadTime>readingInterval*currentReads) //Checks number of times before having a final read
  {
    avgRead += analogRead(colorSensor);
    if(currentReads==numOfReads)//Last read?
    {
      avgRead=avgRead/(numOfReads); //get actual read value
      if(analogRead(colorSensor)<=30 && avgRead>30)//This is the case in which a white ball arrives late to sorting.
      {                                            //Instead of reading nothing for the first two readings and then reading white
        currentReads=0;                            //at the end and getting an average value of black, it just does another reading.
        avgRead=0;
        startReadTime=millis();
      }
      else if (avgRead<=30){ //Reads White Ball.
        Serial.print("White Ball");
        Serial.print(", ");
        Serial.println(avgRead);
        whiteBallSensed=true;
        startTurnTime =millis();
      }
      else if (avgRead>30 && avgRead<=200){ //Black Ball Sensed
        Serial.print("BlackBall");
        Serial.print(", ");
        Serial.println(avgRead); 
        blackBallSensed=true;
        startTurnTime = millis();  
      }
      else if(avgRead>200){ //No Ball Sensed
        Serial.print("No Ball");
        Serial.print(", ");
        Serial.println(avgRead);
      }
      currentReads=0; //reset number of reads, time, and average
      avgRead=0;
      startReadTime=millis();
    }
    currentReads++;
  }
}

void BlackBallSorting(long i){
  //This is the black ball state.  If the ball is black, this state will be signalled and then it will sweep the servo to the right. 
  if(i<servoTurnInterval) // goes from 90 degrees to 0 degrees 
  {                                 
    sortingHat.write(sortingCenter-i*sortingCenter/servoTurnInterval);              // tell servo to go to position by time divided by time interval
  } 
  else if(i<servoTurnInterval*2)    // goes from 0 degrees to 90 degrees 
  {                                
    sortingHat.write((i-servoTurnInterval)*sortingCenter/servoTurnInterval);              // tell servo to go to position by time divided by time interval
  }
  else
  {
    startReadTime=millis();
    blackBallSensed=false; //No longer sorting
  }
}

void WhiteBallSorting(long i){
  //This is the white ball state.  If the ball is white, this state will be signalled and then it will sweep the servo to the left. 
  if(i<servoTurnInterval) // goes from 90 degrees to 180 degrees 
  {                                 
    sortingHat.write(sortingCenter+i*sortingCenter/servoTurnInterval);              // tell servo to go to position by time divided by time interval
  } 
  else if(i<servoTurnInterval*2)    // goes from 180 degrees to 90 degrees 
  {                                
    sortingHat.write(sortingCenter*2-(i-servoTurnInterval)*sortingCenter/servoTurnInterval);              // tell servo to go to position by time divided by time interval
  }
  else
  {
    startReadTime=millis(); 
    whiteBallSensed=false; //No longer sorting
  }
}

