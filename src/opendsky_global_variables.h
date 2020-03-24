#include <Arduino.h>

enum Action {
    none                        = 0,
    displayIMUAttitude          = 1,
    displayRealTimeClock        = 2,
    displayGPS                  = 3,
    displayRangeWith1202Error   = 4,
    setTime                     = 5,
    setDate                     = 6,
};

enum Mode {
    modeIdle                = 0,
    modeInputVerb           = 1,
    modeInputNoun           = 2,
    modeInputProgram        = 3,
    modeLampTest            = 4
};

enum programNumber {
    programNone             = 0,
    programJFKAudio         = 62,
    programApollo11Audio    = 69,
    programApollo13Audio    = 70
};

enum lampcolor {
    GREEN                   = 0,
    WHITE                   = 1,
    YELLOW                  = 2,
    RED                     = 3,
    BLUE                    = 4
};

enum lampNumber {
    lampNoun                = 0,
    lampProg                = 1,
    lampVerb                = 2,
    lampCompActy            = 3,
    lampOprErr              = 13,   // ?
    lampKeyRelease          = 14,
    lampUplinkActy          = 17,    // ?
    lampNOATT               = 16,
    lampSTBY                = 15,
    lampPOSITION            = 12,
    lampCLK                 = 11,
    lampTEMP                = 4,
    lampGIMBALLOCK          = 5,
    lampPROGCONDTION        = 6,
    lampRESTART             = 7,
    lampTRACKER             = 8,
    lampALT                 = 9,
    lampVEL                 = 10
};

enum keyValues {
    // symbolic references to individual keys
    keyNone                 = 20,
    keyVerb                 = 10,
    keyNoun                 = 11,
    keyPlus                 = 12,
    keyMinus                = 13,
    keyNumber0              = 0,
    keyNumber1              = 1,
    keyNumber2              = 2,
    keyNumber3              = 3,
    keyNumber4              = 4,
    keyNumber5              = 5,
    keyNumber6              = 6,
    keyNumber7              = 7,
    keyNumber8              = 8,
    keyNumber9              = 9,
    keyClear                = 18,
    keyProceed              = 14,
    keyRelease              = 16,
    keyEnter                = 15,
    keyReset                = 17
};

enum verbValues {
    verbNone                = 0,
    verbLampTest            = 35,
    verbDisplayDecimal      = 16,
    verbSetComponent        = 21
};

enum nounValues {
    nounNone                = 0,
    nounIMUAttitude         = 17,
    nounClockTime           = 36,
    nounDate                = 37,
    nounLatLongAltitude     = 43,
    nounRangeTgoVelocity    = 68
};

enum registerDisplayPositions {
    register1Position       = 4,
    register2Position       = 5,
    register3Position       = 6
};

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
bool gpsread = true;

byte minus = B00100100;
byte plus = B01110100;
byte digit_off = B00000000;  // kein Vorzeichen
byte ohne_vz = B00000000;  // kein Vorzeichen

int lat = 1;
int lon = 1;
int alt = 1;


int globaltimer=0;
bool global_state_1sec=false;
bool toggle2 = false;

bool GPS_READ_STARTED = true;

unsigned long previousMillis = 0;
int oldSecond = 0;