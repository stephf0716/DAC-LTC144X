/*
  LTC1446.cpp - Library for the LTC1446 / LTC1446L dual 12-bit SPI DAC.
  Created by Stephanie Fung, July 31, 2017.
  Released under the MIT License.
*/

#include "Arduino.h"
#include <SPI.h>

#include "LTC1446.h"

// The DAC latches D_IN on the rising edge of CLK, MSB first, so SPI mode 0.
// The datasheet specifies a 60ns minimum CLK high and low time (~8MHz
// ceiling); 4MHz leaves comfortable margin over the full temperature range.
static const SPISettings LTC1446_SPI(4000000, MSBFIRST, SPI_MODE0);

/**************************************************************************/
/*!
    @brief  Instantiates a new LTC1446 class
    @param[in]  csPin
                The pin wired to the DAC's CS/LD input.
*/
/**************************************************************************/
LTC1446::LTC1446(uint8_t csPin) {
  _cspin = csPin;
}

/**************************************************************************/
/*!
    @brief  Sets up the HW. Idles CS/LD high so the first transfer is clean.
*/
/**************************************************************************/
void LTC1446::begin() {
  pinMode(_cspin, OUTPUT);
  digitalWrite(_cspin, HIGH);
  SPI.begin();
}

/**************************************************************************/
/*!
    @brief  Sets the output voltages to a fraction of the internal vref.
            (Values can be 0..4095, and are clamped to that range: a code
            wider than 12 bits would overflow into the other channel.)
    @param[in]  voutA, voutB
                The 12-bit values representing the relationship between
                the DAC's reference voltage and each output voltage.
*/
/**************************************************************************/
void LTC1446::setVoltage( uint16_t voutA, uint16_t voutB )
{
    if (voutA > LTC1446_MAX_CODE) voutA = LTC1446_MAX_CODE;
    if (voutB > LTC1446_MAX_CODE) voutB = LTC1446_MAX_CODE;

    // pack the two 12-bit codes into the DAC's 24-bit word, A first
    uint16_t shifted_a = voutA << 4;
    byte byte_1, byte_2, byte_3;
    byte_1 = highByte(shifted_a);                       // A[11:4]
    byte_2 = lowByte(shifted_a) | highByte(voutB);      // A[3:0], B[11:8]
    byte_3 = lowByte(voutB);                            // B[7:0]

    SPI.beginTransaction(LTC1446_SPI);
    // take the CS pin low to select the chip:
    digitalWrite(_cspin, LOW);
    // send in the value via SPI:
    SPI.transfer(byte_1);
    SPI.transfer(byte_2);
    SPI.transfer(byte_3);
    // take the CS pin high to load the DACs from the shift register:
    digitalWrite(_cspin, HIGH);
    SPI.endTransaction();
}
