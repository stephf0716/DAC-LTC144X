/*
  LTC1446.h - Library for the LTC1446 / LTC1446L dual 12-bit SPI DAC.
  Created by Stephanie Fung, July 31, 2017.
  Released under the MIT License.
*/

#ifndef LTC1446_h
#define LTC1446_h

#include "Arduino.h"
#include <SPI.h>

// Highest code the 12-bit DACs accept. Full-scale output is 4.095V on the
// LTC1446 (1mV per LSB) and 2.5V on the LTC1446L.
#define LTC1446_MAX_CODE 4095

class LTC1446
{
  public:
    explicit LTC1446(uint8_t csPin);
    void begin();
    void setVoltage(uint16_t voutA, uint16_t voutB);
  private:
    uint8_t _cspin;
};

#endif
