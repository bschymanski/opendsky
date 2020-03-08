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

#include <opendsky_global_variables.h>
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

for(int index = 0; index < 4; index++){
  lc.shutdown(index,false); 
  lc.setIntensity(index,3);
  lc.clearDisplay(index); 
  }
  
 Wire.begin();
      Wire.beginTransmission(MPU_addr);
      Wire.write(0x6B);  // PWR_MGMT_1 register
      Wire.write(0);     // set to zero (wakes up the MPU-6050)
      Wire.endTransmission(true);

rtc.begin();
      
 Serial.begin(9600);
 
 //  Serial.println("Read Value from Analog pin & Print value");
}

void loop() {
 // Default mode and action are 0, Program will only read the Keyboard
 if (prog == 62){jfk(1);}
 if (prog == 70){jfk(3);}
 if (prog == 69){jfk(2);}  
 if (mode == 0) {mode0();}
 if (mode == 1) {mode1();}
 if (mode == 2) {mode2();}
 if (mode == 3) {mode3();}
 if (mode == 4) {mode4();}
 

 if (togcount == 4) {togcount = 0;if (toggle == 0) {toggle = 1;}else{toggle = 0;}}
 togcount++;
 if (action == 3){ togcount = 4;delay(200);} else {delay(100);}
 
 delay(100);

 if(action == 1) {action1();} // V16N17 ReadIMU
 if(action == 2) {action2();} // V16N36 ReadTime
 if(action == 3) {action3();} // V16N43 Read GPS
 if(action == 5) {action5();} // V21N36 Set The Time
 if(action == 6) {action6();} // V21N37 Set The Date
 Serial.print(verb);
 Serial.print("  ");
 Serial.print(noun);
 Serial.print("  ");
 Serial.println(action);
}




 
