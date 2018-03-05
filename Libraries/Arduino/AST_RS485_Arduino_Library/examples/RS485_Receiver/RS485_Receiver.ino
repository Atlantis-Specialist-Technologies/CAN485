/*
 * RS 485 receiver example
 * Passes data received on the RS485 port to the serial port
 */

// include library
#include <AST_RS485.h>

// define constants
#define SERIAL_BAUDRATE 115200
#define RS485_BAUDRATE 115200

void setup() {
  rsInit();                           // Initialise rs485 port
  Serial.begin(SERIAL_BAUDRATE);      // Serial Port
  Serial1.begin(RS485_BAUDRATE);      // 485 Port
}

void loop() {
  // Pass 485 to Serial
  while(Serial1.available()){
    Serial.write(Serial1.read());
  }
}
