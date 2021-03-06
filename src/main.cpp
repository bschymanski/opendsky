#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMPIXELS      18
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#include "LedControl.h"
LedControl lc=LedControl(12,10,11,4);

#include "RTClib.h"
RTC_DS1307 rtc;

#include<Wire.h>
const int MPU_addr=0x69;  // I2C address of the MPU-6050

// Timer funktion
#include <timer.h>
auto timer = timer_create_default();

#include <opendsky_global_variables.h>


#include <TinyGPS++.h>
TinyGPSPlus gps;

#include <opendsky_functions.h>

void setup() {
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A7, INPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  randomSeed(analogRead(A7));
  pixels.begin();

  for(int index = 0; index < 4; index++)
  {
    lc.shutdown(index,false); 
    lc.setIntensity(index,12);
    lc.clearDisplay(index); 
  }
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  
  rtc.begin();
  Serial.begin(9600);
  timer.every(1000, toggle_timer);

  //Light up PRO, NOUN, VERB and NO ATT
  startUp();
}

void loop() {
  // Default mode and action are 0, Program will only read the Keyboard
  // Verb 35 = mode4() - Lamptest
  if (prog == 62){jfk(1);}
  if (prog == 70){jfk(3);}
  if (prog == 69){jfk(2);}  
  if (mode == 0) {mode0();}
  if (mode == 1) {mode1();} //inputing the verb
  if (mode == 2) {mode2();} //inputing the noun
  if (mode == 3) {mode3();} //inputing the program
  if (mode == 4) {mode4();} // Init / Lamptest
 
  // Global Timer 1 Sec Toggle
  timer.tick();
  

 if(action == 1) {action1();} // V16N17 ReadIMU
 if(action == 2) {action2();} // V16N36 ReadTime
 if(action == 3) {action3();} // V16N43 Read GPS
 if(action == 5) {action5();} // V21N36 Set The Time
 if(action == 6) {action6();} // V21N37 Set The Date
 if(action == 9) {action9();} // V16N19 Read Temp Date & Time
 //Serial.print("verb :");
 //Serial.print(verb);
 //Serial.print(" noun: ");
 //Serial.print(noun);
 //Serial.print(" action: ");
 //Serial.println(action);

}




 
