/***
	InputCapture.ino

	Timer 1 high-resolution timing facility.

	Copyright (C) 2008-2012 Bill Roy

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

***/
#include "Arduino.h"
#include <avr/interrupt.h>

/*
TO DO
	analog threshold-based tick timer
	set comparator to use internal reference
*/

// rising/falling edge tracking
// per '168 data sheet page 121, must clear ICF1 after edge direction change
//
volatile uint8_t rising;
//#define catchRisingEdge() 	(TCCR1B |= (1<<ICES1); TIFR1 |= (1<<ICF1); rising = 1;);
//#define catchFallingEdge() 	(TCCR1B &= ~(1<<ICES1); TIFR1 |= (1<<ICF1); rising = 0;);


// Event queue
#define MAX_EVENT_BUFF 32
unsigned long long last_event;
volatile byte event_buffer_head;
byte event_buffer_tail;
unsigned long long event_buffer[MAX_EVENT_BUFF];

unsigned long long eventRead(void) {
unsigned long long event;
	if (event_buffer_tail == event_buffer_head) {
		Serial.println("Event buffer underrun");
		return -1;
	}
 	event = event_buffer[event_buffer_tail] - last_event;
 	last_event = event_buffer[event_buffer_tail];
	byte oldsreg = SREG;
	cli();
	if (++event_buffer_tail >= MAX_EVENT_BUFF) event_buffer_tail = 0;
	SREG = oldsreg;
	return event;
}

byte eventAvailable(void) {
	byte head;
	byte oldsreg = SREG;
	cli();
	head = event_buffer_head;
	SREG = oldsreg;
	return event_buffer_tail != head;
}

// Our virtual timer counts 2^64 clocks (provided sizeof(unsigned long long) == 8)
// The low order 16 bits are maintained by timer1 and are snapshotted by the
// TIMER1_CAPT input capture interrupt below.
//
// We maintain the high order 48 bits here by incrementing the virtual timer.
// 
volatile unsigned long long t1_virtual_count;
ISR(TIMER1_OVF_vect) {
	t1_virtual_count += 0x10000ULL;
}


unsigned long lost_event_count;

// Interrupt capture handler
//
ISR(TIMER1_CAPT_vect) {

	byte l = ICR1L;		// grab captured timer value
	byte h = ICR1H;

	// watch for the other edge to catch the half-pulse width
	//rising ? catchFallingEdge() : catchRisingEdge();
	if (rising) { TCCR1B &= ~(1<<ICES1); TIFR1 |= (1<<ICF1); rising = 0; }
	else {TCCR1B |= (1<<ICES1); TIFR1 |= (1<<ICF1); rising = 1;}
	
	// push the timestamp into the buffer
	byte newhead = event_buffer_head + 1;
	if (newhead >= MAX_EVENT_BUFF) newhead = 0;
	if (newhead != event_buffer_tail) {
		event_buffer[event_buffer_head] = t1_virtual_count + (h << 8) + l;
		event_buffer_head = newhead;
	}
	else ++lost_event_count;
}


void printEvent(unsigned long long n, unsigned long base) {
	char buf[32];		// stack for the digits
	char *ptr = buf;
	if (n == 0ULL) {
		Serial.write('0');
		return;
	} 
	while (n > 0) {
		*ptr++ = n % base;
		n /= base;
	}
	while (--ptr >= buf) Serial.write((*ptr < 10) ? (*ptr + '0') : (*ptr - 10 + 'A'));
}


void initTimer(void) { 

	// Input Capture setup
	// ICNC1: Enable Input Capture Noise Canceler
	// ICES1: =1 for trigger on rising edge
	// CS10: =1 set prescaler to 1x system clock (F_CPU)
	TCCR1A = 0;
	TCCR1B = (0<<ICNC1) | (0<<ICES1) | (1<<CS10);
	TCCR1C = 0;

	//catchFallingEdge();	// initialize to catch
	{ TCCR1B &= ~(1<<ICES1); TIFR1 |= (1<<ICF1); rising = 0; }

	// Interrupt setup
	// ICIE1: Input capture 
	// TOIE1: Timer1 overflow
	TIFR1 = (1<<ICF1) | (1<<TOV1);		// clear pending
	TIMSK1 = (1<<ICIE1) | (1<<TOIE1);	// and enable

	// Set up the Input Capture pin, ICP1, which corresponds to Arduino D8
	pinMode(8, INPUT);
	digitalWrite(8, 0);		// leave floating to count 60 Hz etc.
	//digitalWrite(8, 1);			// or enable the pullup
}


void setup(void) {
	pinMode(13, OUTPUT);

	// Power up the light sensor
	//pinMode(9, OUTPUT); digitalWrite(9, 0);
	//pinMode(10, OUTPUT); digitalWrite(10, 1);

	Serial.begin(57600);
	initTimer();
	Serial.println("timing...");
}

long count, sumt, bogon_count;
unsigned long updatetime;

void loop60hz(void) {
long t;
long dt;

	while (eventAvailable()) {
		t = (long) eventRead();
		dt = t - (F_CPU/60);
		if (abs(dt) < 2000L) {
			count = count + 1;
			sumt += dt;
		}
		else ++bogon_count;

		if (millis() > updatetime) {
			Serial.println("");
			Serial.print("t="); 	Serial.print(t); 
			//Serial.print(" dt=");	Serial.print(dt);
			Serial.print(" sdt="); 	Serial.print(sumt);
			Serial.print(" n="); 	Serial.print(count);
			Serial.print(" a="); 	Serial.print(sumt/count);
			Serial.print(" e=");	Serial.print(lost_event_count);
			Serial.print(" b=");	Serial.print(bogon_count);
			updatetime = millis() + 1000L;
		}
		Serial.print(" ");		Serial.print(dt);
	}
}


void loop(void) {
	while (eventAvailable()) {
		Serial.print(count++); Serial.write(':');
		printEvent(eventRead(), 10); Serial.write(' '); Serial.println(lost_event_count);
	}
}


