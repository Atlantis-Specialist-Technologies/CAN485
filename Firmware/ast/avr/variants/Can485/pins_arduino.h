/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

/*
  Modified by Atlantis Specialist Technologies
  by James Blakey-Milner, 1 Aug 2017.
  Added support for the AST CAN485 board
  Note! AST modifications are in early development (alpha)
  and are likely to change without notice.
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            24
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 14 : -1)


#define digitalPinHasPWM(p)         (((p) == 5 || (p) == 6 || (p) == 7 )


#define PIN_SPI_SS    (10)
#define PIN_SPI_MOSI  (11)
#define PIN_SPI_MISO  (12)
#define PIN_SPI_SCK   (13)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_WIRE_SDA        (3)
#define PIN_WIRE_SCL        (2)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define LED_BUILTIN 13

#define PIN_A0   (14)
#define PIN_A1   (15)
#define PIN_A2   (16)
#define PIN_A3   (17)
#define PIN_A4   (18)
#define PIN_A5   (19)
#define PIN_A6   (20)
#define PIN_A7   (21)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;

// pin change interrupts not supported
#define digitalPinToPCICR(p)    ((uint8_t *)0)
#define digitalPinToPCICRbit(p) (NO_PIN_CHANGE_INTERRUPT)
#define digitalPinToPCMSK(p)    ((uint8_t *)0)
#define digitalPinToPCMSKbit(p) (NO_PIN_CHANGE_INTERRUPT_MASK)

//#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))
#define digitalPinToInterrupt(p)  (((p) >= 6 && (p) <= 9) ? ((p) - 2) : (((p) == 2) ? 0 : (((p) == 3) ? 1 : NOT_AN_INTERRUPT)))         // AST done

#ifdef ARDUINO_MAIN

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.




// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)

/*
 * See Arduino.h for use of these
 * ports start with PA = 1 (not 0)
 */
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
	(uint16_t) &DDRF,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
	(uint16_t) &PINF,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PE, /*  0 */
	PE, /*  1 */
	PD, /*  2 */
	PD, /*  3 */
	PE, /*  4 */
	PE, /*  5 */
	PE, /*  6 */
	PE, /*  7 */
	PE, /*  8 */
	PE, /*  9 */
	PB, /* 10 */
	PB, /* 11 */
	PB, /* 12 */
	PB, /* 13 */
	PF, /* 14 */
	PF, /* 15 */
	PF, /* 16 */
	PF, /* 17 */
	PF, /* 18 */
	PF, /* 19 */
	PF, /* 20 */
	PF, /* 21 */
	PC, /* 22 */
	PC, /* 23 */
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(1), /*  0, PE1 				*/
	_BV(0), /*  1, PE0 				*/
	_BV(0), /*  2, PD0 				*/
	_BV(1), /*  3, PD1 				*/
	_BV(2), /*  4, PE2 				*/
	_BV(3), /*  5, PE3 				*/
	_BV(4), /*  6, PE4 				*/
	_BV(5), /*  7, PE5 				*/
	_BV(6), /*  8, PE6 				*/
	_BV(7), /*  9, PE7 				*/
	_BV(0), /* 10, PB0 				*/
	_BV(2), /* 11, PB2, MOSI 		*/
	_BV(3), /* 12, PB3, MISO 		*/
	_BV(1), /* 13, PB1, LED_BUILTIN */
	_BV(0), /* 14, PF0 				*/
	_BV(1), /* 15, PF1 				*/
	_BV(2), /* 16, PF2 				*/
	_BV(3), /* 17, PF3 				*/
	_BV(4), /* 18, PF4 				*/
	_BV(5), /* 19, PF5 				*/
	_BV(6), /* 20, PF6 				*/
	_BV(7), /* 21, PF7 				*/
	_BV(0), /* 22, PC0, RS485_RE	*/
	_BV(1), /* 23, PC1, RS485_SHDN	*/
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER3A, /*       5, PE3 */
	TIMER3B, /*       6, PE4 */
	TIMER3C, /*       7, PE5 */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif

/*
 * http://www.avrfreaks.net/forum/setting-jtd-bit-mcucr
 * include in library
 */
#define jtd_set(x) \
{ \
        __asm__ __volatile__ ( \
                "in __tmp_reg__,__SREG__" "\n\t" \
                "cli" "\n\t" \
                "out %1, %0" "\n\t" \
                "out __SREG__, __tmp_reg__" "\n\t"\
                "out %1, %0" "\n\t" \
                : /* no outputs */ \
                : "r" ((uint8_t)(x ? (1<<JTD) : 0)), \
                  "M" (_SFR_IO_ADDR(MCUCR)) \
                : "r0"); \
}

// RS485 control bits
#define RS485_RE 22
#define RS485_SHDN 23

