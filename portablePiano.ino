//#include <Tone32.h>
//#include "SoundData.h"
//#include "XT_DAC_Audio.h"
#include <ToneESP32.h>
//#include "pitches.h"



const int button0 = 25;
const int button1 = 26;
const int button2 = 27;
const int button3 = 21;
const int button4 = 22;
const int button5 = 17;
const int button6 = 2;
const int button7 = 15;
const int button8 = 13;
const int button9 = 12;

const int speaker1_pin = 33;

volatile int buttonRead0 = 1;
volatile int buttonRead1 = 1;
volatile int buttonRead2 = 1;
volatile int buttonRead3 = 1;
volatile int buttonRead4 = 1;
volatile int buttonRead5 = 1;
volatile int buttonRead6 = 1;
volatile int buttonRead7 = 1;
volatile int buttonRead8 = 1;
volatile int buttonRead9 = 1;

// The ESP32 has 16 channels which can generate 16 independent waveforms
// We'll just choose PWM channel 0 here
const int speaker1_channel = 0; 

ToneESP32 speaker1(speaker1_pin, speaker1_channel);
//
//XT_Wav_Class note1(c4);
//XT_DAC_Audio_Class DacAudio(speaker1_pin, speaker1_channel);

void noteZero(){
  buttonRead0 = digitalRead(button0);
}

void noteOne(){
  buttonRead1 = digitalRead(button1);
}

void noteTwo(){
  buttonRead2 = digitalRead(button2);
}

void noteThree(){
  buttonRead3 = digitalRead(button3);
}

void noteFour(){
  buttonRead4 = digitalRead(button4);
}

void noteFive(){
  buttonRead5 = digitalRead(button5);
}

void noteSix(){
  buttonRead6 = digitalRead(button6);
}

void noteSeven(){
  buttonRead7 = digitalRead(button7);
}

void noteEight(){
  buttonRead8 = digitalRead(button8);
}

void noteNine(){
  buttonRead9 = digitalRead(button9);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(button0, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button0), noteZero, CHANGE);
  pinMode(button1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button1), noteOne, CHANGE);
  pinMode(button2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button2), noteTwo, CHANGE);
  pinMode(button3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button3), noteThree, CHANGE);
  pinMode(button4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button4), noteFour, CHANGE);
  pinMode(button5, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button5), noteFive, CHANGE);
  pinMode(button6, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button6), noteSix, CHANGE);
  pinMode(button7, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button7), noteSeven, CHANGE);
  pinMode(button8, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button8), noteEight, CHANGE);
  pinMode(button9, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button9), noteNine, CHANGE);

//  pinMode(speaker1, OUTPUT);

//  ledcAttachPin(speaker1_pin, speaker1_channel);
}


//void tone(int note){
//  ledcSetup(speaker1_channel, note, 8);
//  ledcWrite(speaker1_channel, 127);
//}
//
//void noTone(){
//  ledcWrite(speaker1_channel, 0);
//}

void loop() {
//  DacAudio.FillBuffer();
  // put your main code here, to run repeatedly:

//  buttonRead1 = digitalRead(button1);
//  buttonRead2 = digitalRead(button2);
//  Serial.println(buttonRead1);

//Tone32
//  if(buttonRead0 == 1 and buttonRead1 == 1) noTone(speaker1_pin, speaker1_channel);
//  if(buttonRead0 == 0) tone(speaker1_pin, NOTE_C4, 100, speaker1_channel);
//  if(buttonRead1 == 0) tone(speaker1_pin, NOTE_D4, 100, speaker1_channel);
//  if(buttonRead2 == 0) speaker1.playNote(NOTE_E, 4);
//   Serial.printf("button0: %d\n", buttonRead0);


//ToneESP32
  if(buttonRead0 == 1 and buttonRead1 == 1 and buttonRead2 == 1 and
  buttonRead3 == 1 and buttonRead4 == 1 and buttonRead5 == 1 and buttonRead6 == 1
  and buttonRead7 == 1 and buttonRead8 == 1 and buttonRead9 == 1) {
    speaker1.noTone();
  }
  if(buttonRead0 == 0) speaker1.tone(NOTE_C4, 150);
  if(buttonRead1 == 0) speaker1.tone(NOTE_D4, 150);
  if(buttonRead2 == 0) speaker1.tone(NOTE_E4, 150);
  if(buttonRead3 == 0) speaker1.tone(NOTE_F4, 150);
  if(buttonRead4 == 0) speaker1.tone(NOTE_G4, 150);
  if(buttonRead5 == 0) speaker1.tone(NOTE_A4, 150);
  if(buttonRead6 == 0) speaker1.tone(NOTE_B4, 150);
  if(buttonRead7 == 0) speaker1.tone(NOTE_C5, 150);
  if(buttonRead8 == 0) speaker1.tone(NOTE_D5, 150);
  if(buttonRead9 == 0) speaker1.tone(NOTE_E5, 150);
   Serial.printf("button: %d\n", buttonRead5);

//Tone32.hpp
//  if(buttonRead0 == 1 and buttonRead1 == 1 and buttonRead2 == 1) speaker1.stopPlaying();
//  if(buttonRead0 == 0) speaker1.playNote(NOTE_C, 4);
//  if(buttonRead1 == 0) speaker1.playNote(NOTE_D, 4);
//  if(buttonRead2 == 0) ledcWriteTone(speaker1_channel, NOTE_E4);


//LEDC
//  if(buttonRead0 == 1 and buttonRead1 == 1 and buttonRead2 == 1) ledcWrite(speaker1_channel, 0);
//  if(buttonRead0 == 0) ledcWriteTone(speaker1_channel, NOTE_C4);
//  if(buttonRead1 == 0) ledcWriteTone(speaker1_channel, NOTE_D4);
//  if(buttonRead2 == 0) ledcWriteTone(speaker1_channel, NOTE_E4);


//
//  if(buttonRead0 == 1 and buttonRead1 == 1) noTone();
//  if(buttonRead0 == 0) tone(NOTE_C4);
//  if(buttonRead1 == 0) tone(NOTE_D4);
//
//
//   Serial.printf("button1: %d\n", buttonRead1);
   
   
//  delay(10);
  
}
