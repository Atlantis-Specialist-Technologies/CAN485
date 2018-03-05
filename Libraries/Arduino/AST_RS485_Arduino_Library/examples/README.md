# RS485 Example
This example shows how to use the RS485 port on the CAN485 board.

## Description
Serial data is input to a node, it is then passed to the other node over the RS485 port which then passes it through to the other serial port.

## Setup
- Setup as shown:
![RS485 Example Setup](https://raw.githubusercontent.com/Atlantis-Specialist-Technologies/ast-arduino-boards/master/docs/_images/RS485-annotated.png)
- Flash both nodes with the example sketch: [Serial Passthrough](https://github.com/Atlantis-Specialist-Technologies/AST_RS485/blob/master/examples/RS485toSerialPassthrough/RS485toSerialPassthrough.ino "Example Sketch")
- Connect the FTDI port of each node to a PC

## Use
- Open a serial monitor for each CAN485 node.
- Anything sent to COM1 will be passed through to COM2 over the RS485 port.
- Anything sent to COM2 will be passed through to COM1 over the RS485 port.
