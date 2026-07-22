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