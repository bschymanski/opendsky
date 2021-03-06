#include <Arduino.h>

byte audioTrack = 1;

void jfk(byte jfk){
 if(audioTrack > 3) {audioTrack = 1;} 
   
    
  
  while(audioTrack != jfk){
     pinMode(9, OUTPUT);
    delay(100);
    pinMode(9, INPUT);
    delay(100);
    audioTrack++;
    if(audioTrack > 3) {audioTrack = 1;}
  }
   pinMode(9, OUTPUT);
    delay(100);
    pinMode(9, INPUT);
    audioTrack++;
    prog = 0;
}
// End jfk()


void validateAct()
{
 if(verb == 35) {mode = 4; newAct = 0;}// Lamp Test
 else if((verb == 16) && (noun == 17)) {action = 1;newAct = 0;}//Display IMU Attitude
 else if((verb == 16) && (noun == 36)) {action = 2;newAct = 0;}//Display RTC Time 
 else if((verb == 16) && (noun == 19)) {action = 9;newAct = 0;}//Display RTC Time & Temp
 else if((verb == 16) && (noun == 43)) {action = 3;newAct = 0;}//Display current GPS
 else if((verb == 16) && (noun == 68)) {action = 4;newAct = 0;}//Display Range With 1202 ERROR
 else if((verb == 21) && (noun == 36)) {action = 5;newAct = 0;}//set time
 else if((verb == 21) && (noun == 37)) {action = 6;newAct = 0;}//set date
 
 else{newAct = 0;action = 0;}
}
// End validateAct()

void turnOffLamp(int lampNumber)
{
  pixels.setPixelColor(lampNumber, pixels.Color(0,0,0));
  pixels.show();
}

void turnONLamp(int lampcolor, int lampnumber)
{
  switch (lampcolor)
  {
  case GREEN:
    // white (r=0, g=100, b=0)
    pixels.setPixelColor(lampnumber, pixels.Color(0,100,0));
    pixels.show();
    break;
  case WHITE:
    // white (r=100, g=100, b=100)
    pixels.setPixelColor(lampnumber, pixels.Color(0,100,0));
    pixels.show();
    break;
  case YELLOW:
    // yellow (r=100, g=100, b=0)
    pixels.setPixelColor(lampnumber, pixels.Color(100,100,0));
    pixels.show();
    break;
  case RED:
    // red (r=100, g=0, b=0)
    pixels.setPixelColor(lampnumber, pixels.Color(100,0,0));
    pixels.show();
    break;
  case BLUE:
    // red (r=100, g=0, b=0)
    pixels.setPixelColor(lampnumber, pixels.Color(0,0,100));
    pixels.show();
    break;
  default:
    // Statement(s)
    break; // Wird nicht benötigt, wenn Statement(s) vorhanden sind
  }
}

void lampit(byte r, byte g, byte b , int lamp)
{
  pixels.setPixelColor(lamp, pixels.Color(r,g,b)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
// end lampit()

void verb_light_on()
{
  pixels.setPixelColor(2, pixels.Color(0,150,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void verb_light_yellow()
{
  pixels.setPixelColor(2, pixels.Color(150,150,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void verb_light_orange()
{
  pixels.setPixelColor(2, pixels.Color(150,0,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void verb_light_off()
{
  pixels.setPixelColor(2, pixels.Color(0,0,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}

void noun_light_on()
{
  pixels.setPixelColor(0, pixels.Color(0,150,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void noun_light_yellow()
{
  pixels.setPixelColor(0, pixels.Color(150,150,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void noun_light_orange()
{
  pixels.setPixelColor(0, pixels.Color(150,0,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void noun_light_off()
{
  pixels.setPixelColor(0, pixels.Color(0,0,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}

void tracker_light_on()
{
  pixels.setPixelColor(8, pixels.Color(70,70,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void tracker_light_yellow()
{
  pixels.setPixelColor(8, pixels.Color(70,70,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void tracker_light_orange()
{
  pixels.setPixelColor(8, pixels.Color(100,70,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void tracker_light_off()
{
  pixels.setPixelColor(8, pixels.Color(0,0,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
// end lampit()
void ALT_light_on()
{
  pixels.setPixelColor(9, pixels.Color(70,70,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void ALT_light_yellow()
{
  pixels.setPixelColor(9, pixels.Color(70,70,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void ALT_light_orange()
{
  pixels.setPixelColor(9, pixels.Color(100,70,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}
void ALT_light_off()
{
  pixels.setPixelColor(9, pixels.Color(0,0,0)); // Set it the way we like it.
  pixels.show(); // This sends the updated pixel color to the hardware.
}

bool toggle_timer(void *)
{
  if(global_state_1sec==false){
    global_state_1sec=true;
    toggle2 = true;
    toggle = true;
    turnONLamp(GREEN, lampCompActy);
  }
  else
  {
    global_state_1sec=false;
    toggle2 = false;
    toggle = false;
    turnOffLamp(lampCompActy);
  }
  return true; // repeat? true
}

void flashkr()
{
  if(toggle == 0)
  {
    lampit(100,100,100, 14);
  }
  else
  {
    lampit(0,0,0, 14);
  }
}
// End flashkr

void flasher()
{
  if(toggle == 0)
  {
     lampit(100,100,100, 13);
  }
  else
  {
    lampit(0,0,0, 13);
  }
}
// End flasher

void setdigits(byte maxim, byte digit, byte value){
 
   lc.setDigit(maxim,digit,value,false);
}
// setdigits()

void PrintMode(){
  // lc.setDigit(0,2,mode,false);
}
// PrintMode()
void PrintAction(){
  // lc.setDigit(0,3,action,false);
}
// PrintAction()

void processkey0()
{
  // Check if a new key has been pressed, if yes, store the key value in oldkey
  if(keyVal != oldkey)
  {
    fresh = 1;
    oldkey = keyVal;
  }
  // Check if Verb Key (10) has been entered
  if((keyVal == 10) && (fresh == 1))
  {
    mode = 1; // A verb is going to be entered, so program mode1 will be startet
    fresh = 0; 
    byte keeper = verb; // now lets save the verb in keeper
    //Serial.println(" ");
    //Serial.print("Processkey0 keeper: ");
    //Serial.println(keeper);
    // we are going to save the old verb in the variable verbold first.
    for(int index = 0; keeper >= 10; keeper = (keeper - 10))
    { 
      index ++; verbold[0] = index; 
    }
    for(int index = 0;keeper >= 1; keeper = (keeper - 1)) {
      index ++; verbold[1] = index; 
     }
  }//verb
   
  if((keyVal == 11) && (fresh == 1)){
    mode = 2;
    fresh = 0; 
    byte keeper = noun;
    for(int index = 0; keeper >= 10; keeper = (keeper - 10)) {
      index ++;
      nounold[0] = index;
    }
    for(int index = 0;keeper >= 1; keeper = (keeper - 1)) {
      index ++;
      nounold[1] = index;
    }
  }//noun
  
  if((keyVal == 14) && (fresh == 1)){
    mode = 3;
    fresh = 0;
  }//program
  if((keyVal == 17) && (fresh == 1)){
    error = 0;
    lampit(0,0,0, 13);
    fresh = 0;
  } //resrt reeor
}
// end processkey0()

void processkey1() // Process the Verb
{
  if(keyVal == oldkey){
    fresh = 0;
  } 
  else 
  { 
    fresh = 1; 
    oldkey = keyVal; 
    if((error == 1) && (keyVal == 17) && (fresh == 1))
    {
      error = 0;
      lampit(0,0,0, 13);
      lc.setRow(0,0,digit_off); 
      lc.setRow(0,1,digit_off); 
      fresh = 0;
    } //resrt reeor
    if((keyVal == 15) && (fresh == 1)) {
      fresh = 0;
      verb = ((verbnew[0] * 10) + (verbnew[1]));
      if((verb != 16) && (verb != 21) && (verb != 35) && (verb != 0)) {
        error = 1;
        verb = ((verbold[0] * 10) + verbold[1]);
      }
      else {
        lampit(0,0,0, 13);
        mode = 0;
        lampit(0,0,0, 14);
        //lampit(0,0,0, 2);
        verb_light_on();
        count = 0;
        fresh = 0; 
        error = 0; 
        newAct = 1;
      } 
    }
    if((keyVal == 16) && (fresh == 1))
    {
      mode = oldmode;
      lampit(0,0,0, 14);
      //lampit(0,0,0, 2);
      verb_light_on();
      count = 0; fresh = 0;
      if (verb == 0) {
        lc.setRow(0,0,0);
        lc.setRow(0,1,0);
      } 
      else {
        setdigits(0, 0,verbold[0]);
        setdigits(0, 1,verbold[1]);
      }
    }//verb 
    if((keyVal == 11) && (fresh == 1))
    {
      mode = 2;
      //lampit(0,0,0, 2);
      verb_light_off();
      count = 0; 
      fresh = 0;
    }//noun
    if((keyVal == 14) && (fresh == 1))
    {
      mode = 3;
      //lampit(0,0,0, 2);
      verb_light_off();
      count = 0; 
      fresh = 0;
    }//program
    if((keyVal < 10)&&(count < 2))
    { 
      verbnew[count] = keyVal;
      setdigits(0, count, keyVal);
      count++;
      fresh = 0;
    }
  }
}
// End processkey1

void processkey2() // Process the Noun
{
  if(keyVal == oldkey){
    fresh = 0;
  } 
  else 
  { 
    fresh = 1; 
    oldkey = keyVal; 
    if((error == 1) && (keyVal == 17) && (fresh == 1))
    {
      error = 0;
      lampit(0,0,0, 13);
      lc.setRow(0,4,digit_off); 
      lc.setRow(0,5,digit_off); 
      fresh = 0;
    } //resrt reeor
    if((keyVal == 15) && (fresh == 1))
    {
      fresh = 0;
      noun = ((nounnew[0] * 10) + (nounnew[1]));
      fresh = 0;
      if((noun != 17) && (noun != 36) && (noun != 19) && (noun != 43) && (noun != 68) && (noun != 0))
      {
        error = 1; noun = ((nounold[0] * 10) + nounold[1]);
      }
      else
      {
        lampit(0,0,0, 13);
        mode = 0;
        lampit(0,0,0, 14);
        noun_light_on();
        count = 0;
        fresh = 0;
        error = 0;
        newAct = 1;
      }
    }
    if((keyVal == 16) && (fresh == 1))
    {
      mode = oldmode;
      lampit(0,0,0, 14);
      noun_light_on();
      count = 0; 
      fresh = 0;
      if (noun == 0) {
        lc.setRow(0,4,0);
        lc.setRow(0,5,0);
      } 
      else
      {
        setdigits(0, 4,nounold[0]);
        setdigits(0, 5,nounold[1]);
      }
    }//verb 
    if((keyVal == 10) && (fresh == 1))
    {
      mode = 1;
      noun_light_on();
      count = 0;
      fresh = 0;
    }//verb
    if((keyVal == 14) && (fresh == 1))
    {
      mode = 3;
      noun_light_on();
      count = 0;
      fresh = 0;
    }//program
    if((keyVal < 10)&&(count < 2))
    {
      nounnew[count] = keyVal;
      setdigits(0, (count + 4), keyVal);count++;
    }
  }
}
// End processkey2


void processkey3()
{
  if(keyVal == oldkey){
    fresh = 0;
  } 
  else 
  {
    if((error == 1) && (keyVal == 17) && (fresh == 1))
    {
      error = 0;
      lampit(0,0,0, 13);
      lc.setRow(0,2,digit_off); 
      lc.setRow(0,3,digit_off); 
      fresh = 0;
    } //resrt reeor
    if((keyVal == 15) && (fresh == 1))
    {
      fresh = 0;
      prog = ((prognew[0] * 10) + (prognew[1]));
      fresh = 0;
      if((prog != 16) && (prog != 21) && (prog != 35) && (prog != 62) && (prog != 69) &&(prog != 70) && (prog != 0))
      {
        error = 1; noun = ((progold[0] * 10) + progold[1]);
      }
      else
      {
        progold[0] = prognew[0];
        progold[1] = prognew[1];
        lampit(0,0,0, 13);
        mode = 0;
        lampit(0,0,0, 14);
        lampit(0,0,0, 1);
        count = 0;
        fresh = 0;
        error = 0;
        newAct = 1;
      }
    }
    if(keyVal != oldkey)
    {
      fresh = 1;
      oldkey = keyVal;
    }
    if((keyVal == 16) && (fresh == 1))
    {
      mode = oldmode;
      lampit(0,0,0, 14);
      lampit(0,0,0, 1);
      count = 0;
      fresh = 0;
    }//verb 
    if((keyVal == 11) && (fresh == 1))
    {
      mode = 2;
      lampit(0,0,0, 1);
      count = 0;
      fresh = 0;
    }//noun
    if((keyVal == 10) && (fresh == 1))
    {
      mode = 1;
      lampit(0,0,0, 1);
      count = 0;
      fresh = 0;
    }//verb
    if((keyVal < 10)&&(count < 2))
    {
      prognew[count] = keyVal;
      setdigits(0, (count + 2), keyVal);
      count++;
    }
  }
}
// End processkey3

void processkeytime()
{
  
}
// End processkeytime

int readkb()
{ 
  int value_row1 = analogRead(A0);
  int value_row2 = analogRead(A1);
  //Serial.println(value_row2);
  int value_row3 = analogRead(A2);
  if ((value_row1 > 930)&&(value_row2 > 930)&&(value_row3 > 930))
  {
    return 20 ;
  }// no key
  else if (value_row1 < 225) return 10 ; // Verb
  else if (value_row1 < 370) return 12 ; // +
  else if (value_row1 < 510) return 7 ;
  else if (value_row1 < 650) return 8 ;
  else if (value_row1 < 790) return 9 ;
  else if (value_row1 < 930) return 18 ;  // Clear
 
  else if (value_row2 < 200) return 11 ;  // Noun
  else if (value_row2 < 330) return 13 ;  // -
  else if (value_row2 < 455) return 4 ;
  else if (value_row2 < 577) return 5 ;
  else if (value_row2 < 700) return 6 ;
  else if (value_row2 < 823) return 14 ;  // Program
  else if (value_row2 < 930) return 15 ;  // Enter
  
  else if (value_row3 < 225) return 0 ; 
  else if (value_row3 < 370) return 1 ;
  else if (value_row3 < 510) return 2 ;
  else if (value_row3 < 650) return 3 ;
  else if (value_row3 < 790) return 16 ; // Key Rel
  else if (value_row3 < 930) return 17 ; // Reset
}
// End readkb

void setDigits()
{
  for (int indexa = 0; indexa < 8; indexa ++){
    for (int index = 0; index < 7; index++) {
      digitval[indexa][index]=0;      
    }
  }
  for (int indexa = 0; indexa < 7; indexa ++){
    if (imuval[indexa] < 0) {
      imuval[indexa] = (imuval[indexa] - (imuval[indexa] + imuval[indexa])); 
      digitval[indexa][0] = 1;
    }
    else {
      digitval[indexa][0] = 0;
    }
    for(int index = 0; imuval[indexa] >= 100000; imuval[indexa] = (imuval[indexa] - 100000)) {
      index++;
    }
    for(int index = 0; imuval[indexa] >= 10000; imuval[indexa] = (imuval[indexa] - 10000)) {
      index ++;
      digitval[indexa][1] = index;
    }
    for(int index = 0; imuval[indexa] >= 1000; imuval[indexa] = (imuval[indexa] - 1000)) {
      index ++; 
      digitval[indexa][2] = index;
    }
    for(int index = 0; imuval[indexa] >= 100; imuval[indexa] = (imuval[indexa] - 100)) {
      index ++;
      digitval[indexa][3] = index;
    }
    for(int index = 0; imuval[indexa] >= 10; imuval[indexa] = (imuval[indexa] - 10)) {
      index ++;
      digitval[indexa][4] = index;
    }
    for(int index = 0; imuval[indexa] >= 1; imuval[indexa] = (imuval[indexa] - 1)) {
      index ++;
      digitval[indexa][5] = index;
    }
  } 
  for(int index = 0; index < 3; index ++){
    // lc.clearDisplay(index+1);  
    for(int i=0;i<6;i++) {
      if (i == 0){
        if (digitval[(index +4)][i] == 1) {
          lc.setRow(index+1,i,B00100100);
        }
        else {
          lc.setRow(index+1,i,ohne_vz);
        }
      }
      else {
        lc.setDigit(index+1,i,digitval[index + 4][i],false);
      }
    } 
  }
}
// End setDigits() 

void compAct()
{
  int randNumb = random(10, 30); 
  if ((randNumb == 15) || (randNumb == 25))
  {
    lampit(0,150,0,3);
  }
  else
  {
    lampit(0,0,0,3);
  }
  if ((randNumb == 17) || (randNumb == 25))
  {
    lampit(90,90,90,17);
  }
  else
  {
    lampit(0,0,0,17);
  }
}
// End compAct


void readimu()
{
  compAct();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  imuval[0]=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  imuval[1]=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  imuval[2]=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  imuval[3]=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  imuval[4]=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  imuval[5]=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  imuval[6]=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  imuval[3] = (imuval[3]/340.00+36.53);//equation for temperature in degrees C from datasheet
  /* Serial.print("AcX = "); Serial.print(imuval[0]);
  Serial.print(" | AcY = "); Serial.print(imuval[1]);
  Serial.print(" | AcZ = "); Serial.print(imuval[2]);
  Serial.print(" | Tmp = "); Serial.print(imuval[3]);  
  Serial.print(" | GyX = "); Serial.print(imuval[4]);
  Serial.print(" | GyY = "); Serial.print(imuval[5]);
  Serial.print(" | GyZ = "); Serial.println(imuval[6]);
  */ 
  setDigits();      
}
// End readimu()


void mode0() //no action set just reading the kb
{
  //PrintMode();
  //PrintAction();
  if (newAct == 1)
  {
    validateAct();
  } 
  else
  {
    if(error == 1)
    {
      flasher();
    }
    keyVal = readkb();
    processkey0();  
  }
}
// End mode0

void mode1() //inputing the verb
{
  //PrintMode();
  flashkr();
  if(error == 1)
  {
    flasher();
    verb_light_orange();
  } 
  else
  {
    //verb_light_on(); //Verb Light ON
    verb_light_yellow();
  }
  keyVal = readkb();
  processkey1(); 
}

void mode2() //inputing the noun
{
  //PrintMode();
  //lampit(0,150,0, 0);
  flashkr();
  if(error == 1)
  {
    flasher();
    noun_light_orange();
  }
  else
  {
    noun_light_yellow();
  }
  
 keyVal = readkb();
 processkey2(); 
}

void mode3() //inputing the program
{
  //PrintMode();
  lampit(0,150,0, 1);
  flashkr();
  if(error == 1){flasher();}
  keyVal = readkb();
  processkey3();
}

void startUp()
{
  for (int index = 0; index < 4; index++)
  {
    lampit(0,0,0, index);
    delay(200);
    lampit(0,150,0, index);
  }
  for (int index = 4; index < 18; index++)
  {
    if(index < 11)
    {
      lampit(100,100,0, index);
    }
    if(index <= 12)
    {
      lampit(100,100,100, 23-index);
    }
    delay(50);
  }
  for (int index = 0; index < 4; index++)
  {
    for (int indexb = 0; indexb < 6; indexb++)
    {
      setdigits(index,indexb,8);
      delay(25);
    }
  }
  delay(1000); 
  for (int index = 3; index < 11; index++)
  {
    lampit(0,0,0, index);
  }
  for (int index = 11; index < 18; index++)
  {
    if(index != 16)
    {
      lampit(0,0,0, index);
    }
  }
  for (int index = 0; index < 4; index++)
  {
    lc.clearDisplay(index);
  }
  verbnew[0] = verbold[0];
  verbnew[1] = verbold[1];
  verb = ((verbold[0] * 10) + verbold[1]);
  if (verb == 0)
  {
    lc.setRow(0,0,0);
    lc.setRow(0,1,0);
  }
  else
  {
    setdigits(0, 0,verbold[0]);
    setdigits(0, 1,verbold[1]);
  }
  if (prog == 0)
  {
    lc.setRow(0,2,0);
    lc.setRow(0,3,0);
  }
  else
  {
    setdigits(0, 0,prognew[0]);
    setdigits(0, 1,prognew[1]);
  }
  if (noun == 0)
  {
    lc.setRow(0,4,0);
    lc.setRow(0,5,0);
  }
  else
  {
    setdigits(0, 4,nounnew[0]);
    setdigits(0, 5,nounnew[1]);
  }
  keyVal = 20;
  mode = 0;
  //PrintMode();
  //PrintAction();
  validateAct(); 
}
// End startUp

void mode4() // Init / Lamptest
{
  //PrintMode();
  // Light ON for: Noun, Prog, Verb and CompAct LEDs
  for (int index = 0; index < 4; index++)
  {
    lampit(0,150,0, index);
    delay(500); // wait a bit after each LED, just for the effect
  }
  // Light ON for: LR Velocity Data, LR Altitude Data, Tracker, Program Condition, Gimbal Lock, Temperature LEDs
  for (int index = 4; index < 11; index++)
  {
    lampit(100,100,0, index);
    delay(500); // wait a bit after each LED, just for the effect
  }
  // Light ON for: 11, 12, Operator Error, Key Release, Standby Status, NO Attitude, Uplink Activity LEDs
  for (int index = 11; index < 18; index++)
  {
    lampit(100,100,100, index);
    delay(500); // wait a bit after each LED, just for the effect
  }
  // Light ON for all 3 Register Lines
  for (int index = 0; index < 4; index++)
  {
    for (int indexb = 0; indexb < 6; indexb++)
    {
      setdigits(index,indexb,8);
      delay(500); // wait a bit after each LED, just for the effect
    }
  }
  delay(5000); // wait 5 Seconds, then turn the LEDs off
  // Light OFF for: Noun, Prog, Verb and CompAct LEDs
  for (int index = 0; index < 4; index++)
  {
    lampit(0,0,0, index);
    delay(500); // wait a bit after each LED, just for the effect
  }
  // Light OFF for: LR Velocity Data, LR Altitude Data, Tracker, Program Condition, Gimbal Lock, Temperature LEDs
  for (int index = 4; index < 11; index++)
  {
    lampit(0,0,0, index);
    delay(500); // wait a bit after each LED, just for the effect
  }
  // Light OFF for: 11, 12, Operator Error, Key Release, Standby Status, NO Attitude, Uplink Activity LEDs
  for (int index = 11; index < 18; index++)
  {
    lampit(0,0,0, index);
    delay(500); // wait a bit after each LED, just for the effect
  }
  // Light ON for all 3 Register Lines
  for (int index = 0; index < 4; index++)
  {
    lc.clearDisplay(index);
    delay(500); // wait a bit after each LED, just for the effect
  }
  verbnew[0] = verbold[0]; verbnew[1] = verbold[1];
  verb = ((verbold[0] * 10) + verbold[1]);
  if (verb == 0) {lc.setRow(0,0,0);lc.setRow(0,1,0);}
  else{setdigits(0, 0,verbold[0]);setdigits(0, 1,verbold[1]);}
  if (prog == 0) {lc.setRow(0,2,0);lc.setRow(0,3,0);}
  else{setdigits(0, 0,prognew[0]);setdigits(0, 1,prognew[1]);}
   if (noun == 0) {lc.setRow(0,4,0);lc.setRow(0,5,0);}
  else{setdigits(0, 4,nounnew[0]);setdigits(0, 5,nounnew[1]);}
  keyVal = 20;
  mode = 0;
  validateAct();
  startUp();
}
// End mode4

void action1() {
 //PrintMode();
 //PrintAction();
 readimu(); 
}

void action2() { // Reads Time from RTC
  //PrintMode();
  //PrintAction();
  DateTime now = rtc.now();
  // hundrets of seconds
  if( oldSecond < now.second() )
  {
    oldSecond = now.second();
    previousMillis = millis();
  }
  int hundreds = ( ( millis()-previousMillis )/10 )%100;
  int subhundreds = hundreds - (hundreds % 10);
  imuval[4] = (now.hour());
  imuval[5] = (now.minute());
  imuval[6] = ((now.second() *100 ) + subhundreds);
  setDigits();  
}





void action3() //Read GPS
{ 
  //PrintMode();
  //PrintAction();
  if (toggle2 == true && gpsread == true)
  {
    ALT_light_on();
    digitalWrite(7,HIGH);
    //Serial.begin(9600);
    delay(20);
    gpsread = false;
    delay(6);
    // int index = 0;
    while((Serial.available()) && (GPS_READ_STARTED == true))
    {
      ALT_light_on();
      if (gps.encode(Serial.read()))
      {
         ALT_light_orange();
         GPS_READ_STARTED = false;
      }
    }
    digitalWrite(7,LOW);
    ALT_light_off();
    Serial.println(gps.location.lat());
    Serial.println(gps.location.lng());
    Serial.println(gps.altitude.meters());
    imuval[4] = gps.location.lat()*100;
    imuval[5] = gps.location.lng()*100;
    imuval[6] = gps.altitude.meters();

    setDigits();
  }
  if (toggle2 == false)
  {
     gpsread = true;
     GPS_READ_STARTED = true;
  }

}

void action5()  // Sets Time To RTC
{
  //PrintMode();
  //PrintAction();
  DateTime now = rtc.now();
  int NYR = now.year();
  int NMO = now.month();
  int NDY = now.day();
  int NHR = now.hour();
  int NMI = now.minute();
  int NSE = now.second();
  while(keyVal == 15){ keyVal = readkb();}
  
  while(keyVal != 15){
    Serial.println(keyVal);
   keyVal = readkb();
   if(keyVal != oldkey) {
    oldkey = keyVal;
   if(keyVal == 12) {NHR++;}
   if(keyVal == 13) {NHR--;}
   if( NHR > 23) {NHR = 0;}
   if(NHR < 0) {NHR = 23;}
   }
   imuval[4] = NHR; imuval[5] =  NMI; imuval[6] = (NSE *100);
   setDigits();
   delay(200);
   lc.clearDisplay(1);
   delay(50); 
  }
  while(keyVal == 15){ keyVal = readkb();}
  while(keyVal != 15){
   keyVal = readkb();
   if(keyVal != oldkey) {
    oldkey = keyVal;
   if(keyVal == 12) {NMI++;}
   if(keyVal == 13) {NMI--;}
   if( NMI > 59) {NMI = 0;}
   if(NMI < 0) {NMI = 59;} 
   }
   imuval[4] = NHR; imuval[5] =  NMI; imuval[6] = (NSE *100);
   setDigits(); 
   delay(200);
   lc.clearDisplay(2);
   delay(50); 
  }
  while(keyVal == 15){ keyVal = readkb();}
  while(keyVal != 15){
   keyVal = readkb();
   if(keyVal != oldkey) {
    oldkey = keyVal;
   if(keyVal == 12) {NSE++;}
   if(keyVal == 13) {NSE--;} 
   if( NSE > 59) {NSE = 0;}
   if(NSE < 0) {NSE = 59;}
   }
   imuval[4] = NHR; imuval[5] =  NMI; imuval[6] = (NSE *100);
   setDigits();
   delay(200);
   lc.clearDisplay(3);
   delay(50);  
  }
 rtc.adjust(DateTime(NYR,NMO,NDY,NHR , NMI , NSE));
 action = 2; setdigits(0, 0, 1);setdigits(0, 1, 6);verbold[0] = 1; verbold[1] = 6; verb = 16; 
}

void action6()
{
  //PrintMode();
  //PrintAction();
  byte setyear[4];
  byte setmonth[2];
  byte setday[2];
  byte sethour[2];
  byte setminiut[2];
  byte setsecond[2];
  DateTime now = rtc.now();
  int NYR = now.year();
  int NMO = now.month();
  int NDY = now.day();
  int NHR = now.hour();
  int NMI = now.minute();
  int NSE = now.second();
  
 rtc.adjust(DateTime(((setyear[0] * 1000) + (setyear[1] * 100) + (setyear[2] * 10) + (setyear[3])), ((setmonth[0] * 10) + (setmonth[1])),((setday[0] * 10) + (setday[1])), NHR,NMI,NSE)); 
}



void action7() // Print GPS
{
  /* */
}
void mode11() {
 compAct();
 //PrintMode();
 //PrintAction(); 
}

void tempDateTime()
{
  //PrintMode();
  //PrintAction();
  compAct();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  imuval[0]=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  imuval[1]=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  imuval[2]=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  imuval[3]=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  imuval[4]=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  imuval[5]=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  imuval[6]=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  //imuval[3] = (imuval[3]/340.00+36.53);//equation for temperature in degrees C from datasheet
  DateTime now = rtc.now();
  byte MM[2];
  byte DD[2];
  byte HH[2];
  byte mm[2];
  //temp = (temp/340.00+36.53) * 2;
  Serial.print("IMUval3: ");
  Serial.println(imuval[3]);
  float temp = (float(imuval[3])/340.0 + 36.53); // Temp in Celsius
  
  Serial.print("temp   : ");
  Serial.println(temp);
  MM[0] = now.month() / 10;
  MM[1] = now.month() % 10;
  DD[0] = now.day() / 10;
  DD[1] = now.day() % 10;
  HH[0] = now.hour() / 10;
  HH[1] = now.hour() % 10;
  mm[0] = now.minute() / 10;
  mm[1] = now.minute() % 10;
  lc.setRow(1,0,B00000000);
  setdigits(1,1,DD[0]);      
  setdigits(1,2,DD[1]);      
  lc.setRow(1,3,B00000000);
  setdigits(1,4,(MM[0]));      
  setdigits(1,5,MM[1]);
  
  lc.setRow(2,0,B00000000);
  setdigits(2,1,0);
  setdigits(2,2,HH[0]);      
  setdigits(2,3,HH[1]);      
  setdigits(2,4,(mm[0]));      
  setdigits(2,5,mm[1]);
  
  setdigits(3,0,0);
  setdigits(3,1,0);
  setdigits(3,2,0);      
  setdigits(3,3,0);      
  setdigits(3,4,(int(temp) / 10));      
  setdigits(3,5,(int(temp) % 10));
}
void action9(){
  //PrintMode();
  //PrintAction();
  tempDateTime();
}