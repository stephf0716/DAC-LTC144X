/*
  LTC1446.h - Library for LTC1446 DAC.
  Created by Stephanie Fung, July 31, 2017.
*/

#ifndef LTC1446_h
#define LTC1446_h

#include "Arduino.h"
#include <SPI.h>

class LTC1446
{
  public:
    LTC1446(int pin);
    void begin(uint8_t a);
    void setVoltage( uint16_t VOUTA, uint16_t VOUTB );
  private:
    uint8_t _cspin;
};

#endif
