/*
    Milestone 1
    Have buttons play two different melodies, but have the arduino be able to detect another input while doing an output. 
    Alex Stein (author #1) with Megan Keeler (author #2)
    Mechatronics Matthew Stein Fall 2015
*/

#include "pitches.h" 

const int button1Pin = 2; //Button 1 Pin (ToneMelody)
const int button2Pin = 3; //Button 2 Pin (JingleBell Rock)
const int buzzerPin = 8;  //Buzzer for playing
const int ledPin = 13;    //led for debugging

unsigned long currentTime = 0; //Current time of program
unsigned long startTime = 0;   //Inital time of song
unsigned long buttonTimer = 0; //Add delay to prevent spamming of songs

//Used to detect if song is currently playing or not.
boolean tone1Playing = false;
boolean tone2Playing = false;

//Used to prevent multiple button presses being stored up when only pressing once.
boolean button1WasPressed = false;
boolean button2WasPressed = false;

//Used to store songs 
int songStorage[50];
int currentIndex = 0;
int storageIndex = 0;

// note durations: 4 = quarter note, 8 = eighth note, etc.:
//ToneMelody+
int melody1[] = {0,NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4, NOTE_F4, NOTE_G5, NOTE_A2, NOTE_B3, NOTE_C1 }; 
int noteDurations1[] = {4,4,8,8,4,4,4,4,4,2,8,4,4,8};
//JingleBell Rock (kinda)
int melody2[] = {0,NOTE_C4, NOTE_C4,NOTE_C4,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_A4, NOTE_B4, NOTE_A4, NOTE_E3, NOTE_E3,NOTE_A4,NOTE_B4,NOTE_A4, NOTE_E3}; 
int noteDurations2[] = {4,8,8,4,8,8,4,8,8,8,1,8,8,4,4,4};
int noteCount = 0;

//Setup pins for buttons and buzzer
void setup(){
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);  
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);                    //Serial used for debugging
}

//
void loop()
{
  currentTime = millis();                 //Get current time
  detectIfButtonPressed();                //See if either button is being pressed
  if (tone1Playing || tone2Playing)       //If song is currently playing, keep playing it.
  {
      playMusic(currentTime-startTime);   //Play the song
  }
  else
  {
      tryToPlay();                        //See if we have a song queued up
  }
}

void playMusic(int elapsedTime)
{
  if(tone1Playing) //Playing Melody 1
  {
    long totalNoteTime = 0;
    for(int i=0; i<noteCount+1;i++) //Count note duration as well as gap between notes
    {
      totalNoteTime = totalNoteTime + 1000/noteDurations1[i]*1.5;
    }
    if(totalNoteTime < elapsedTime) //Check if we need to move to new note.
    {
      noteCount++;
      if(noteCount == 15) // See if song has ended.
      {
         noTone(8);
         tone1Playing = false;
         noteCount = 0;
      }
      else                //If it hasnt ended, play next note
      {
         int noteDuration = 1000/noteDurations1[noteCount];
         tone(buzzerPin, melody1[noteCount],noteDuration);
      }
    }
  }
  else //Playing Melody 2
  {
    long totalNoteTime = 0;
    for(int i=0; i<noteCount+1;i++) //Count note duration as well as gap between notes 
    {
      totalNoteTime = totalNoteTime + 1000/noteDurations2[i]*1.5;
    }
    if(totalNoteTime < elapsedTime) //Check if we need to move to new note.
    {
      noteCount++;
      if(noteCount == 17)  //See if song has ended.
      {
         noTone(8);
         tone2Playing = false;
         noteCount = 0;
      }
      else                //If it hasnt ended, play next note
      {  
        int noteDuration = 1000/noteDurations2[noteCount];
        tone(buzzerPin, melody2[noteCount],noteDuration);
      }
    }
  }
}

void detectIfButtonPressed()
{
  Serial.println(digitalRead(button1Pin));
  if(button1WasPressed)            //check to see if a button was pressed down
  {
    if(digitalRead(button1Pin)==LOW) //check to see that button was released before adding song
    {
      songStorage[storageIndex] = 1;
      storageIndex++;
      button1WasPressed = false;
    }
  }
  else if(button2WasPressed)            //check to see if a button was pressed down
  {
    if(digitalRead(button2Pin)==LOW) //check to see that button was released before adding song
    {
      songStorage[storageIndex] = 2;
      storageIndex++;
      button2WasPressed = false;
    }
  }
  else        //Read if button was pressed
  {
    if(digitalRead(button1Pin) == HIGH)
    {
      button1WasPressed = true;
    }
    if(digitalRead(button2Pin) == HIGH)
    {
      button2WasPressed = true;
    }
  }
}

void tryToPlay()     //Check if song is in storage
{
  if(songStorage[currentIndex]==1) //Play first song
  {
    tone1Playing=true;
    currentIndex++;
    startTime = millis();
  }
  else if(songStorage[currentIndex]==2) //Play second song
  {
    tone2Playing=true;
    currentIndex++;
    startTime = millis();
  }
  else //If no song in storage do nothing.
  {
    
  }
  
}
