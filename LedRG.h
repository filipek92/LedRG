/*
  LedRG.h - Library for control of led
  Created by Filip Richter,11.08.2016.
  Released into the public domain.
*/

#ifndef LedRG_h
#define LedRG_h

#define LED_OFF 0
#define LED_MANUAL 0

#define LED_ON_R 1
#define LED_ON_G 2
#define LED_ON_Y 3
#define LED_ON_RG 3

#define LED_BL_R 4
#define LED_BL_G 5
#define LED_BL_Y 6

#define LED_BL_RG 7
#define LED_BL_GY 8
#define LED_BL_YR 9

#include "Arduino.h"
#include "stdint.h"

class LedRG
{
  public:
    LedRG(byte pinR, byte pinG);
    byte status();
    void set(byte state);
    void setRed(bool state);
    void setGreen(bool state);
    void doWork();
  private:
    void set(bool red, bool green);

    byte _pinR;
    byte _pinG;
    
    byte ledStatus = LED_OFF;
    bool blink = false;
};
#endif
