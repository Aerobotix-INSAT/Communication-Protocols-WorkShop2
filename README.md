# Introduction to Communication Protocols for Embedded Devices

This repository contains Arduino implementations of various communication protocols: **SPI, I2C, and UART**.

## Folder Structure
```
- SPI/
  - SPIMaster.ino
  - SPISlave.ino
- I2C/
  - I2CMaster.ino
  - I2CSlave.ino
- UART/
  - SimpleWaveGenerator.ino
  - SingleCommandReceiver.ino
```

## Communication Protocols Overview

### 1. SPI (Serial Peripheral Interface)
SPI is a high-speed, full-duplex communication protocol commonly used for short-distance communication between microcontrollers and peripheral devices.
- **SPIMaster.ino**: Sends and receives data to/from the slave device.
- **SPISlave.ino**: Responds to the master by receiving and transmitting data.

**Connections (Arduino Uno):**
| Signal | Master Pin | Slave Pin |
|--------|-----------|-----------|
| MOSI   | 11        | 11        |
| MISO   | 12        | 12        |
| SCK    | 13        | 13        |
| SS     | 10        | 10        |

### 2. I2C (Inter-Integrated Circuit)
I2C is a synchronous, multi-device communication protocol using only two wires.
- **I2CMaster.ino**: Sends and requests data from the slave device.
- **I2CSlave.ino**: Responds to the master’s requests and sends back data when requested.

**Connections (Arduino Uno):**
| Signal | Pin |
|--------|-----|
| SDA    | A4  |
| SCL    | A5  |

### 3. UART (Universal Asynchronous Receiver-Transmitter)
UART is a simple, asynchronous communication protocol using two data lines: TX (transmit) and RX (receive).
- **SimpleWaveGenerator.ino**: Generates a continuous wave signal.
- **SingleCommandReceiver.ino**: Receives and processes single-character commands from serial input.

**Connections (Arduino Uno):**
| Signal | Pin |
|--------|-----|
| TX     | 1   |
| RX     | 0   |

## How to Use
1. Open the desired `.ino` file in the Arduino IDE.
2. Connect the required hardware as per the pin configurations.
3. Upload the code to your Arduino board.
4. Use the Serial Monitor (for UART) or logic analyzer (for SPI/I2C) to verify communication.