/*
  LedRG.cpp - Library for control of led
  Created by Filip Richter,11.08.2016.
  Released into the public domain.
*/
#include "LedRG.h"

LedRG::LedRG(byte pinR, byte pinG){
  _pinR = pinR;
  _pinG = pinG;

  pinMode(_pinR, OUTPUT);
  pinMode(_pinG, OUTPUT);
  set(false, false);
}

byte LedRG::status(){
  return ledStatus;
}
void LedRG::set(byte state){
  if(state > 9) state = 0;
  switch(state){
    case LED_OFF:
      set(false, false);
      break;
    case LED_ON_R:
    case LED_BL_R:
    case LED_BL_RG:
      set(true, false);
      break;
    case LED_ON_G:
    case LED_BL_G:
    case LED_BL_GY:
      set(false, true);
      break;
    case LED_ON_Y:
    case LED_BL_Y:
    case LED_BL_YR:
      set(true, true);
      break;
  }
  ledStatus = state;  
}

void LedRG::set(bool red, bool green){
  digitalWrite(_pinR, red);
  digitalWrite(_pinG, green);  
}
void LedRG::setRed(bool state){
  if(ledStatus!=LED_MANUAL) return;
  digitalWrite(_pinR, state);
}
void LedRG::setGreen(bool state){
  if(ledStatus!=LED_MANUAL) return;
  digitalWrite(_pinG, state);  
}

void LedRG::doWork(){
  if(ledStatus>LED_ON_Y){
    switch(ledStatus){
      case LED_BL_R:  set(blink,      0); break;
      case LED_BL_RG: set(blink, !blink); break;
      case LED_BL_G:  set(    0,  blink); break;
      case LED_BL_GY: set(blink,      1); break;
      case LED_BL_Y:  set(blink,  blink); break;
      case LED_BL_YR: set(    1,  blink); break;     
    }
    blink=!blink;
  }
}
