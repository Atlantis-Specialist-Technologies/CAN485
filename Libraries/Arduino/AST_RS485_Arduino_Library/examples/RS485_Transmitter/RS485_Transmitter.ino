/*
 * RS485 Transmitter example
 * Sends a message over the RS485 port repeatedly
 */

// Include library
#include <AST_RS485.h>

// Define constants
#define RS485_BAUDRATE 115200

// Variables
String testMsg = "RS485 Test Message";

void setup() {
  rsInit();                           // Initialise rs485 port
  Serial1.begin(RS485_BAUDRATE);      // 485 Port
}

void loop() {
  Serial1.println(testMsg);           // Send test message
  delay(500);                         // Delay before resending
}
