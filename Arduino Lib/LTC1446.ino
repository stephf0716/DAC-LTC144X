/*
  LTC1446
  This example controls a Linear Technology LTC1446 Dual 12-bit DAC.
  The connections to the uController
  1 - CLK
  2 - Din
  3 - *CS
  4 - Dout(NC)
  5 - Vout A
  6 - ground
  7 - Vcc (bypass w/ 0.1uF)
  8 - Vout B

  The LTC1446 is SPI-compatible, and data is loaded with a 24-bit word:
  first 12-bits are for DAC A, and second 12-bits are for DAC B
  The values should be (0 - 4095)

  created 29 Jul 2017
  by Stephanie Fung
*/

// include the SPI library:
#include <SPI.h>

// set pin 10 as the slave select for LTC1446:
#define SS_PIN 10

void setup() {
  // set the SS_PIN as an output:
  pinMode(SS_PIN, OUTPUT);
  // initialize SPI:
  SPI.begin();
}

void loop() {
  // go through the 4095 levels of voltage:
  for (unsigned int voltage = 0; voltage < 4095; voltage++) {
    // change the resistance on this channel from min to max:
    DAC_write(voltage, voltage);
    // wait half a second at the top:
    delay(500);
  }
}

void DAC_write(unsigned int DAC_A, unsigned int DAC_B) {
  // take the SS pin low to select the chip:
  digitalWrite(SS_PIN, LOW);
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
  // take the SS pin high to de-select the chip:
  digitalWrite(SS_PIN, HIGH);
}
