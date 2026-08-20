# DAC-LTC144X

A small KiCad breakout board and an Arduino driver for the **Linear Technology
LTC1446 / LTC1446L** — a dual 12-bit rail-to-rail DAC with an internal
reference and a 3-wire SPI interface in an 8-pin package.

<!-- Board render and schematic images go in docs/ and get embedded here. -->

## The part

| | LTC1446 | LTC1446L |
|---|---|---|
| Supply | 4.5V – 5.5V | 2.7V – 5.5V |
| Full-scale output | 4.095V (1mV per LSB) | 2.5V |
| Resolution | 12 bits, 2 channels | 12 bits, 2 channels |
| Interface | 3-wire SPI, 24-bit word | 3-wire SPI, 24-bit word |
| Settling time | 14µs to ±0.5 LSB | 14µs to ±0.5 LSB |

Both channels are written in a single 24-bit transfer: the first 12 bits set
DAC A, the second 12 set DAC B. Data is latched on the **rising** edge of CLK
(SPI mode 0, MSB first), and the outputs update when CS/LD returns high. The
DAC has a power-on reset that clears both channels to 0V.

## The board

Two-layer, 18 × 22 mm, through-hole headers, designed in KiCad 6.

| Ref | Value | Purpose |
|---|---|---|
| U1 | LTC1446 | Dual 12-bit DAC, SO-8 |
| R1 | 10k | Pull-up on CS/LD to VCC |
| C1 | 0.1µF | VCC bypass |
| J1 | 1x5 header | Control in — CLK, D_IN, CS, VCC, GND |
| J2 | 1x2 header | Analog out — Vout A, Vout B |

Open `LTC1446-BRD.kicad_pro` in KiCad 6 or newer.

### Wiring

| J1 pin | Signal | Arduino (Uno) |
|---|---|---|
| 1 | CLK | 13 (SCK) |
| 2 | D_IN | 11 (MOSI) |
| 3 | CS | 10 (or any digital pin) |
| 4 | VCC | 5V |
| 5 | GND | GND |

The DAC's D_OUT pin is brought to U1 only; it exists so multiple LTC1446s can
be daisy-chained, and is left unconnected on this board.

## The Arduino library

Copy this repository into your Arduino `libraries/` folder, or clone it there:

```bash
git clone https://github.com/stephf0716/DAC-LTC144X ~/Documents/Arduino/libraries/LTC1446
```

```cpp
#include <LTC1446.h>

LTC1446 dac(10);  // CS/LD wired to pin 10

void setup() {
  dac.begin();
  dac.setVoltage(2048, 0);  // A to mid-scale (~2.048V), B to 0V
}

void loop() {}
```

### API

- `LTC1446(uint8_t csPin)` — construct with the pin wired to CS/LD.
- `begin()` — configures the CS pin and starts SPI.
- `setVoltage(uint16_t voutA, uint16_t voutB)` — writes both channels in one
  transfer. Codes run `0` to `LTC1446_MAX_CODE` (4095) and are clamped, since
  a value wider than 12 bits would overflow into the other channel.

See [examples/BasicSweep](examples/BasicSweep/BasicSweep.ino) for a full sketch
that ramps both channels.

## Repository layout

```
src/                    Arduino library sources
examples/BasicSweep/    example sketch
datasheets/             LTC1446 datasheet
LTC1446-BRD.*           KiCad 6 project, schematic, and PCB layout
```

## License

MIT — see [LICENSE](LICENSE). The bundled datasheet is the property of Linear
Technology / Analog Devices and is included for convenience only.
