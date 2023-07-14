//Rev 1 Created on 6/29/2023 by Jonathan DeWitt.  This is the same code as the stargate version pretty much but with the Star Wars arrays in it for the notes.  On 7/14/2023 I came back and modified the original Rev 1 with speed factor in the note duration array songD.
#define qn 1000 //quarter note duration is 1000 ms
#define hn 2000 //half note duration is 2000 ms
#define wn 4000 //whole note duration is 4000 ms
#define dhn 3000 //dotted half note duration is 3000 ms
#define dqn 1500 //dotted quarter note duration is 1500 ms
#define den 650 //dotted eighth note duration is 650 ms
#define en 500 //eighth note duration is 500 ms
#define dsnp 375 //Just a name for a duration. Stands for dotted sixteenth note plus
#define dsn 350 //dotted sixteenth note is 350 ms
#define dsnm 325 //Just a name for a duration. Stands for dotted sixteenth note minus
#define snp 300 //Just a name for a duration. Stands for sixteenth note plus
#define sn 250 //sixteenth note duration is 250 ms
#define snm 175 //Just a name for a duration. Stands for sixteenth note minus
#define dtsn 150 //dotted thirty-second note duration is 150 ms
#define tsn 125 //thirty-second note duration is 125 ms
#define wnq 1250 //whole note tied to a quarter note duration is 1250 ms

enum Notes {
  N_D3SH = 155, 
  N_G3SH = 207, 
  N_A3SH = 233,
  N_C4 = 261,
  N_D4 = 294,
  N_E4 = 329,
  N_F4 = 349,
  N_F4SH = 369,
  N_G4 = 391,
  N_G4SH = 415,
  N_A5 = 440,
  N_A5SH = 455,
  N_B5 = 493,
  N_C5 = 523,
  N_D5 = 587,
  N_E5 = 659,
  N_F5 = 698,
  N_F5SH = 740,
  N_G5 = 784,
  N_G5SH = 830,
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

//const char *NoteName[]={"C4","D4","E4","F4","G4","A5","B5","C5","D5","E5","F5","G5","A6","A5F","B5F","C5SH","D5F","D5SH","E5F","G5F","SIL"}; //A note name lookup array - must have the same number of characters as enum Notes or it can crash
int bArr[73] = {N_A5, N_A5, N_A5, N_F4, N_C5, N_A5, N_F4, N_C5, N_A5, N_SIL, N_E5, N_E5, N_E5, N_F5, N_C5, N_G4SH, N_F4, N_C5, N_A5, N_SIL, N_A6, N_A5, N_A5, N_A6, N_G5SH, N_G5, N_F5SH, N_F5, N_F5SH, N_SIL, N_A5SH, N_D5SH, N_D5, N_C5SH, N_C5, N_B5F, N_C5, N_SIL, N_F4, N_G4SH, N_F4, N_A5, N_C5, N_A5, N_C5, N_E5, N_SIL, N_A6, N_A5, N_A5, N_A6, N_G5SH, N_G5, N_F5SH, N_F5, N_F5SH, N_SIL, N_A5SH, N_D5SH, N_D5, N_C5SH, N_C5, N_B5F, N_C5, N_SIL, N_F4, N_G4SH, N_F4, N_C5, N_A5, N_F4, N_C5, N_A5}; //Includes Section 1, Section 2, Variant 1 with Delay, Section 2, and Variant 2 with Delay
#define numArrayElements 73 //Define number of elements in song array Stargate Theme Song
float sF=1.05; //Speed Factor to Speed Up Song
//float songD[numArrayElements] = {500, 500, 500, 350, 150, 500, 350, 150, 650, 500, 500, 500, 500, 350, 150, 500, 350, 150, 650, 500, 500, 300, 150, 500, 325, 175, 125, 125, 250, 325, 250, 500, 325, 175, 125, 125, 250, 350, 250, 500, 350, 125, 500, 375, 125, 650, 500, 500, 300, 150, 500, 325, 175, 125, 125, 250, 325, 250, 500, 325, 175, 125, 125, 250, 350, 250, 500, 375, 125, 500, 375, 125, 650}; //This is the same song as the array below but without the speed factor
float songD[numArrayElements] = {en/sF,en/sF,en/sF,dsn/sF,dtsn/sF,en/sF,dsn/sF,dtsn/sF,den/sF,en/sF,en/sF,en/sF,en/sF,dsn/sF,dtsn/sF,en/sF,dsn/sF,dtsn/sF,den/sF,en/sF,en/sF,snp/sF,dtsn/sF,en/sF,dsnm/sF,snm/sF,tsn/sF,tsn/sF,sn/sF,dsnm/sF,sn/sF,en/sF,dsnm/sF,snm/sF,tsn/sF,tsn/sF,sn/sF,dsn/sF,sn/sF,en/sF,dsn/sF,tsn/sF,en/sF,dsnp/sF,tsn/sF,den/sF,en/sF,en/sF,snp/sF,dtsn/sF,en/sF,dsnm/sF,snm/sF,tsn/sF,tsn/sF,sn/sF,dsnm/sF,sn/sF,en/sF,dsnm/sF,snm/sF,tsn/sF,tsn/sF,sn/sF,dsn/sF,sn/sF,en/sF,dsnp/sF,tsn/sF,en/sF,dsnp/sF,tsn/sF,den/sF};
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
