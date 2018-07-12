/*
  LTC1446.cpp - Library for LTC1446 DAC.
  Created by Stephanie Fung, July 31, 2017.
*/

#include "Arduino.h"
#include <SPI.h>

#include "LTC1446.h"

/**************************************************************************/
/*!
    @brief  Instantiates a new LTC1446 class
*/
/**************************************************************************/
LTC1446::LTC1446() {
}

/**************************************************************************/
/*!
    @brief  Setups the HW
*/
/**************************************************************************/
void LTC1446::begin(uint8_t addr) {
  _cspin = addr;
  SPI.begin();
}

/**************************************************************************/
/*!
    @brief  Sets the output voltages to a fraction of source vref.  (Value
            can be 0..4095)
    @param[in]  VOUTA, VOUTB
                The 12-bit value representing the relationship between
                the DAC's input voltage and its output voltage.
*/
/**************************************************************************/
void LTC1446::setVoltage( uint16_t VOUTA, uint16_t VOUTB )
{
    // take the CS pin low to select the chip:
    digitalWrite(_cspin, LOW);
    DAC_A = DAC_A << 4; // shift DAC_A
    // put the bits in 24-bit word order for DAC
    byte byte_1, byte_2, byte_3;
    byte_1 = highByte(DAC_A);
    byte_2 = lowByte(DAC_A) | highByte(DAC_B);
    byte_3 = lowByte(DAC_B);
    // send in the address and value via SPI:
    SPI.transfer(byte_1);
    SPI.transfer(byte_2);
    SPI.transfer(byte_3);
    // take the CS pin high to de-select the chip:
    digitalWrite(_cspin, HIGH);
}
