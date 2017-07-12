//
//   SDL_Arduino_SunControl WatchDog Library Test Code
//   Version 1.1
//   SwitchDoc Labs   July 2017
//
//
// This was designed for the SwitchDoc Labs SunControl Solar Power Board
//
// uses two Grove cables
// Standard Grove to Grove Cable from Grove WatchDog Plub on SunControl to D6/D7 on Arduino Grove Sheild
// Female Pin Header to Grove Cable Adaptor Cable (for WatchDog Out Pulse High Pin on SunControl Board) plugged into D2/D3 (we are using D2 to connect to Pulse High - this )

#include <Wire.h>
#include "SDL_Arduino_SunControl.h"
                
SDL_Arduino_SunControl SunControl;

#define PULSEHIGHINTERRUPTLINE 2

void pulsehigh_callback()
{

    Serial.println("-----WatchDog Triggered----");
    Serial.println(millis()/1000.0);
    Serial.println("---------------------------");

};




void setup()
{
  Serial.begin(115200);

  Serial.println("SDL_SunControl_WatchDog_Test");

  SunControl.begin();
  SunControl.useWatchDog();

  attachInterrupt (digitalPinToInterrupt (PULSEHIGHINTERRUPTLINE), pulsehigh_callback, RISING);

};


void loop()
{

  while (true)
  {

    // uncomment the patTheDog lines to stop the WatchDog from Triggering
    delay(30000);  // delay 30 seconds
    //SunControl.patTheWatchDog();
    delay(30000);  // delay 30 seconds   
    //SunControl.patTheWatchDog(); 
    Serial.println("--minute tick--");
    
  }

 


};

