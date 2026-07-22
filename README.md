# MCP2515-CAN-Bus-Module-Interfacing-with-Arduino-UNO

## Overview
This project demonstrates the interfacing of the MCP2515 CAN Bus Module with an Arduino UNO using the SPI communication protocol.

The project includes:
- 2D hardware schematic design
- Arduino UNO and MCP2515 hardware interfacing
- SPI communication setup
- Arduino code for MCP2515 initialization
- LED-based CAN Bus signal observation
- Hardware testing

## Hardware Used
- Arduino UNO
- MCP2515 CAN Bus Module (TJA1050)
- LED
- Jumper Wires
- USB Cable

## SPI Connections

| MCP2515 | Arduino UNO |
|---------|-------------|
| VCC | 5V |
| GND | GND |
| CS | D10 |
| SCK | D13 |
| MOSI | D11 |
| MISO | D12 |
| INT | D2 |

## Project Status
Hardware Tested Successfully

## Future Work
The next step is to connect the MCP2515 CAN Bus Module to a real vehicle for live CAN Bus communication and data analysis.
## Code:
#include <SPI.h>
#include <mcp_can.h>

MCP_CAN CAN(10);

byte data[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};

void setup()
{
  Serial.begin(9600);

  while (CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) != CAN_OK)
  {
    Serial.println("CAN Module Not Found");
    delay(1000);
  }

  Serial.println("CAN Module Connected");

  CAN.setMode(MCP_NORMAL);   // loopback ki jagah normal mode
}

void loop()
{
  byte result = CAN.sendMsgBuf(0x100, 0, 8, data);

  Serial.print("Result = ");
  Serial.println(result);

  if (result == CAN_OK)
  {
    Serial.println("Message Sent");
  }
  else
  {
    Serial.println("Send Error");
  }

  delay(1000);
}
## Author
**Haris Mustafa Awan**
