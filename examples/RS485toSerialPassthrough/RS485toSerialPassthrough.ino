/*
 * RS 485 to serial passthrough example
 * passes data received on the RS485 port to the serial port
 * passes data received on the serial port to the RS485 port
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
  // Pass Serial to 485
  while(Serial.available()){
    Serial1.write(Serial.read());
  }
}
