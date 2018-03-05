#AltSoftSerial Library#

Improved software emulated serial, using hardware timers for precise signal
timing and availability of CPU time for other libraries to respond to interrupts
during data AltSoftSerial data transmission and reception.

[http://www.pjrc.com/teensy/td_libs_AltSoftSerial.html](http://www.pjrc.com/teensy/td_libs_AltSoftSerial.html)

![AltSoftSerial on Teensy 2.0](http://www.pjrc.com/teensy/td_libs_AltSoftSerial_2.jpg)

## Modified by AST to support the CAN485 board

[CAN485 Repository](https://github.com/Atlantis-Specialist-Technologies/CAN485) and [product page](https://www.sparkfun.com/products/14483)

Enables software serial on pins 9 (rx) and 5 (tx).

Note! Using software serial will disable pwm on pins 6 and 7.
