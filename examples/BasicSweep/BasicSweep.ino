/*
  LTC1446 BasicSweep

  Ramps both channels of a Linear Technology LTC1446 dual 12-bit DAC:
  channel A sweeps up while channel B sweeps down.

  The LTC1446 is SPI-compatible. Data is loaded as a single 24-bit word,
  MSB first: the first 12 bits are for DAC A, the second 12 for DAC B.
  Codes run 0..4095. On the LTC1446 full scale is 4.095V (1mV per LSB);
  on the LTC1446L it is 2.5V.

  Connections to the microcontroller (LTC1446 pin numbers):
  1 - CLK    -> SCK
  2 - D_IN   -> MOSI
  3 - CS/LD  -> CS_PIN below
  4 - D_OUT  -> not connected
  5 - Vout A -> your load
  6 - GND    -> ground
  7 - Vcc    -> 5V (bypass with 0.1uF)
  8 - Vout B -> your load

  created 29 Jul 2017
  by Stephanie Fung
*/

#include <LTC1446.h>

// the pin wired to the DAC's CS/LD input:
const uint8_t CS_PIN = 10;

LTC1446 dac(CS_PIN);

void setup() {
  dac.begin();
}

void loop() {
  // walk channel A up through all 4096 levels while B walks down:
  for (uint16_t code = 0; code <= LTC1446_MAX_CODE; code++) {
    dac.setVoltage(code, LTC1446_MAX_CODE - code);
    delay(2);
  }
  // hold at the endpoints for half a second before repeating:
  delay(500);
}
