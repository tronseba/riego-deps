#ifndef _Menu_H
#define _Menu_H

#include "Arduino.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"


//SETUP MODES

#define TIMEDATEEDIT 0
#define TRIGGERSEDIT 1
#define PAUSE 2


//edition states
#define SETSECONDS 5
#define SETMINUTES 6
#define SETHOURS 7
#define SETDAYS 8
#define SETMONTH 9
#define SETYEAR 10



class Menu {

public:

// Software SPI (slower updates, more flexible pin options):
// pin 13 - Serial clock out (SCLK)
// pin 11 - Serial data out (DIN)
// pin 12 - Data/Command select (D/C)
// no pin - LCD chip select (CS)
// pin 10 - LCD reset (RST)
static const int NokiaSCLKpin = 13; // compatible with hardware ISP
static const int NokiaDNpin = 11; // compatible with hardware ISP
static const int NokiaDCpin = 12; 
static const int NokiaRESETpin = 10;
static const int button1Pin = 2;  //MODE button ping
static const int button2Pin = 3;  //SELECT button ping
static const int button3Pin = 4;  //MOVE button ping
int button1;
int button2;
int button3; 
int dtState;
int menuState;


Menu();

void processKeys();
 
void setMode(int state);

void setEditionState(int state);

void drawMenu();

};

#endif
