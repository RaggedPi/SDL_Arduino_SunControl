//
//   SDL_Arduino_SunControl Library Test Code
//   Version 1.1
//   SwitchDoc Labs   July 2017
//
//
// This was designed for the SwitchDoc Labs SunControl Solar Power Board
//

// the three channels of the INA3221 named for SunControl Solar Power Controller channels (www.switchdoc.com)
#define LIPO_BATTERY_CHANNEL 1
#define SOLAR_CELL_CHANNEL 2
#define OUTPUT_CHANNEL 3

#include <Wire.h>
#include "SDL_Arduino_SunControl.h"

SDL_Arduino_SunControl SunControl;


void setup()
{
  Serial.begin(115200);

  Serial.println("SDL_SunControl_Test");

  SunControl.begin();

};

void printSunControlVoltagesAndCurrents()
{


  Serial.println( "------------------------------");
  Serial.println( "SunControl Voltages and Currents");
  Serial.println( "------------------------------");

  float current_mA1 = 0;
  float loadvoltage1 = 0;



  current_mA1 = SunControl.readChannelCurrent(LIPO_BATTERY_CHANNEL);
  loadvoltage1 = SunControl.readChannelVoltage(LIPO_BATTERY_CHANNEL);


  Serial.print("LIPO_Battery Load Voltage:  "); Serial.print(loadvoltage1); Serial.println(" V");
  Serial.print("LIPO_Battery Current 1:       "); Serial.print(current_mA1); Serial.println(" mA");
  Serial.println("");

  float current_mA2 = 0;
  float loadvoltage2 = 0;

  current_mA2 = -SunControl.readChannelCurrent(SOLAR_CELL_CHANNEL);
  loadvoltage2 = SunControl.readChannelVoltage(SOLAR_CELL_CHANNEL);

  Serial.print("Solar Cell Load Voltage 2:  "); Serial.print(loadvoltage2); Serial.println(" V");
  Serial.print("Solar Cell Current 2:       "); Serial.print(current_mA2); Serial.println(" mA");
  Serial.println("");


  float current_mA3 = 0;
  float loadvoltage3 = 0;

  current_mA3 = SunControl.readChannelCurrent(OUTPUT_CHANNEL);
  loadvoltage3 = SunControl.readChannelVoltage(OUTPUT_CHANNEL);


  Serial.print("Output Load Voltage 3:  "); Serial.print(loadvoltage3); Serial.println(" V");
  Serial.print("Output Current 3:       "); Serial.print(current_mA3); Serial.println(" mA");
  Serial.println("");



}

void loop()
{

  printSunControlVoltagesAndCurrents();
  delay(2000);


  // Turn the USB Power Off
  SunControl.setUSBControl(true);
  SunControl.setUSBEnable(true);
  SunControl.setUSBControl(false);
  Serial.println ("------");
  Serial.println ("USB Power turned OFF");
  Serial.println ("------");

  printSunControlVoltagesAndCurrents();
  delay(2000);

  // Turn the USB Power On


  SunControl.setUSBControl(true);

  delay(2000);
  Serial.println ("------");
  Serial.println ("USB Power turned ON");
  Serial.println ("------");


};

