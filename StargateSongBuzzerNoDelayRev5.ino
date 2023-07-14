//Created on 6/27/2023 to play the stargate song without delay on a 5 V buzzer without using the delay function.  It works somewhat.  There are frequent interruptions.  But it is recognizable as the stargate song.
//Rev 3 Created on 6/28/2023.  This version partially works. It is currently experiencing a difficulty where in several places the note that should be played on the buzzer is not the high note I should be hearing but a lower note.  It starts in element 34 of the bArr and last for 3 notes.  I do hear it other places in the song.  I am suspicious it might be because of the duration of the notes being so short.
//Rev 4 Created on 6/28/2023.  The introduction of the noTone function back into the code fixed the issue I was seeing in the previous code
//Rev 5 Created on 6/28/2023 by Jonathan DeWitt.  This version introduces back in the pause at the end of the song for 3 seconds before looping.  I also cleaned up the code a bit of commented out code and some of the naming of the variables (I removed references to song 2 that carried over from reference code where I could).
#define qn 1000 //quarter note duration is 1000 ms
#define hn 2000 //half note duration is 2000 ms
#define wn 4000 //whole note duration is 4000 ms
#define dhn 3000 //dotted half note duration is 3000 ms
#define dqn 1500 //dotted quarter note duration is 1500 ms
#define en 500 //eighth note duration is 500 ms
#define sn 250 //sixteenth note duration is 250 ms
#define tsn 125 //thirty-second note duration is 125 ms
#define wnq 1250 //whole note tied to a quarter note duration is 1250 ms

enum Notes {
  N_C4 = 261,
  N_D4 = 294,
  N_E4 = 329,
  N_F4 = 349,
  N_G4 = 391,
  N_A5 = 440,
  N_B5 = 493,
  N_C5 = 523,
  N_D5 = 587,
  N_E5 = 659,
  N_F5 = 698,
  N_G5 = 784,
  N_A6 = 880,
  N_A5F = 415,
  N_B5F = 466,
  N_C5SH = 554,
  N_D5F = 554,
  N_D5SH = 622,
  N_E5F = 622,
  N_G5F = 739,
  N_SIL = 10
};

const char *NoteName[]={"C4","D4","E4","F4","G4","A5","B5","C5","D5","E5","F5","G5","A6","A5F","B5F","C5SH","D5F","D5SH","E5F","G5F","SIL"}; //A note name lookup array - must have the same number of characters as enum Notes or it can crash
Notes bArr[93]={N_C4,N_G4,N_G4,N_C5,N_B5F,N_A5F,N_G4,N_A5F,N_G4,N_SIL,N_G4,N_E5,N_D5,N_E5,N_F5,N_D5,N_E5,N_E5,N_F5,N_D5,N_E5,N_E5,N_F5,N_D5,N_E5,N_G5,N_F5,N_E5,N_D5,N_E5,N_D5,N_C5,N_A5F,N_C5,N_A5,N_G4,N_A5,N_B5F,N_G4,N_A5,N_A5,N_B5F,N_G4,N_A5,N_A5,N_B5F,N_G4,N_A5,N_C5,N_B5F,N_A5,N_G4,N_A5,N_C5,N_D5F,N_F5,N_G5F,N_F5,N_D5,N_E5F,N_E5,N_C5SH,N_D5SH,N_E5,N_G5F,N_F5,N_D5,N_E5F,N_E5,N_C5SH,N_D5SH,N_E5,N_D5,N_G5F,N_D5,N_G5F,N_A6,N_A6,N_A6,N_SIL,N_A6,N_A6,N_A6,N_SIL,N_A6,N_A6,N_A6,N_SIL,N_A6,N_A6,N_A6,N_SIL,N_A6}; //Up to section 29 Stargate SG-1 Theme Song - Incorporates firstSectionSG and secondSectionSG and thirdSectionSG and fourthSectionSG from Stargate_Song.ino - Note: In sections 25 & 27 of the Stargate SG-1 Main Theme Song Arranged by Frank Bernaerts there are sixteenth notes which I changed to eighth notes because I don't think the DFPlayer handles sixteenth notes well at the speed I'm running the music at 
#define numArrayElements 92 //Define number of elements in song array Stargate Theme Song
float sF=2.5; //Speed Factor to Speed Up Song
float songD[]={qn/sF,dhn/sF,qn/sF,qn/sF,hn/sF,en/sF,en/sF,en/sF,dhn/sF,hn/sF,hn/sF,dhn/sF,en/sF,en/sF,qn/sF,qn/sF,wnq/sF,en/sF,qn/sF,qn/sF,dqn/sF,en/sF,qn/sF,qn/sF,qn/sF,qn/sF,qn/sF,en/sF,en/sF,wnq/sF,qn/sF,qn/sF,qn/sF,hn/sF,dhn/sF,en/sF,en/sF,qn/sF,qn/sF,wnq/sF,en/sF,qn/sF,qn/sF,dqn/sF,en/sF,qn/sF,qn/sF,qn/sF,qn/sF,qn/sF,en/sF,en/sF,qn/sF,qn/sF,qn/sF,qn/sF,qn/sF,hn/sF,en/sF,en/sF,qn/sF,qn/sF,qn/sF,qn/sF,qn/sF,hn/sF,en/sF,en/sF,qn/sF,qn/sF,qn/sF,qn/sF,hn/sF,hn/sF,hn/sF,hn/sF,qn/sF,qn/sF,qn/sF,en/sF,qn/sF,qn/sF,qn/sF,en/sF,en/sF,en/sF,en/sF,en/sF,en/sF,en/sF,en/sF,en/sF,qn/sF};
int voidLoopCnt=0; //Keeps track of iterations of void loop
unsigned long previousMillis = 0;
unsigned long arrayEndMillis = 0; //A variable to store what time the array end was reached
long interval = 0;
const long songEndPause = 3000; 

#define buzzerPin 8 //Arduino Digital Pin the 5 V Buzzer is Connected To

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() 
{ //Start of void loop
  unsigned long currentMillis = millis();

  for (int i = 0; i<=numArrayElements; i++)
  { //Start of for loop to run through notes
    beep(bArr[i], songD[i]);
    previousMillis = currentMillis; //Set the previousMillis equal to the time you last triggered the note
    interval = songD[i]; //Set the interval equal to the duration of the current note
    while(currentMillis - previousMillis < interval)
    {
      //Serial.println("Waiting.");
      currentMillis = millis(); //Update the currentMillis so that the while loop can keep checking to see if the note's duration has elapsed
      if(currentMillis - previousMillis >= interval)
      { //Start of if statement to check if the end of interval has been reached
        noTone(buzzerPin); //Turn off the square wave that generates the tone at the end of the interval so that the next notes can start properly
      } //End of if statement to check if the end of interval has been reached
    }
    //Serial.print("i = "); //For debugging purposes only to see what iteration of the for loop the song is on. Note this also allows us to see how long each note is lasting by when i appears in the serial monitor.
    //Serial.println(i);

    if(i==numArrayElements)
    { //Beginning of if statement when the i variable reaches the end of the array numArrayElements
      arrayEndMillis = millis();
      while(currentMillis - arrayEndMillis < songEndPause)
      {
        //Serial.println("Pausing at end of song."); //For debugging only
        currentMillis = millis(); //Update the currentMillis so that the while loop can keep checking to see if the songEndPause duration has elapsed
      }
    } //End of if statement when the i variable reaches the end of the array numArrayElements
    
  } //end of for loop to run through notes

} //End of void loop

//Function Definitions
void beep(int note, int duration)
{ //Start of beep function definition
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
} //End of beep function definition
