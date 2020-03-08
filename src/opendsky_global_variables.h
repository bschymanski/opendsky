#include <Arduino.h>

long imuval[7];
byte digitval[7][7];
byte keyVal = 20;
byte oldkey = 20;
bool fresh = 0;
byte action = 0;
byte currentaction = 0;
byte verb = 0;
byte verbnew[2];
byte verbold[2];
byte noun = 0;
byte nounnew[2];
byte nounold[2];
byte prog = 0;
byte prognew[2];
byte progold[2];
byte count = 0;
byte mode = 0;
byte oldmode = 0;
bool toggle = 0;
byte togcount = 0;
bool error = 0;
bool newAct = 0;

byte minus = B00100100;
byte plus = B01110100;
byte ohne_vz = B00000000;  // kein Vorzeichen
