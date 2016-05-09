Mini-Rambo readme

Part Changes
C40 0402 > 0603
C25 0603 > 0402
C49 0603 > 0402, 10nf > 1uF
F5 1210 > 1812
C1 0603 > 0402
C16 0603 > 0402

C30 change part to C1206C475K5PACTU - same values, worse tolerance, better supply chain, better price

Temporary use WSL2010R0600FEA18 for sense resistor on smps
Change R13 sense resistor to RL2512FK-070R06L

Proposed part changes
56R > 0R > REMOVED
0R > REMOVED

Extension connectors

Tasks
 Firmware
  Pins
  motor current by PWM
  
0.1 errata
PS_ON not connected 
LEDs placed 180 out
atmega2560, A4982 placed 270 out
PSMN70 placed offset in Y
USB fuse too close to USB connector. Remove?
No ESD path for USB, TVS diode added to bottom
No polarity indicator on connectors


0.2 errata
fuse holder hole too small, verify hole size is as spec'd
stencil sucks
No ESD path for USB, TVS diode added to bottom
 
Tests - Start up, Steady state, Transient states
EM
 voltage regulator
 motors
Temperatures
 Bed Fet
  V= 11 - 25, A= 15+
 Extruder Fet
  V= 11 - 25, A= 5+
 Fan Fets
 Motor Drivers
 Power traces
 Voltage regulator
ESD
 USB
Voltage
 Reverse voltage Input
 Min/Max voltage

Induced noise / interference
 ADC
 SMPS onto other lines
 
Stepper current circuit
 700mV P-P, ~40ns period. Saved #1 
 
 
Concerns
Fan connector selection.
Must be actively cooled.
motor output filters removed. necessity will need to be evalutated again for new design
see errata for individual versions above

Silk screen on QFN32
icsp typo

power from 5vsb leaves on with power off - jumper select

Fuse hole size

ATX testpoints 

clock too close to buzzer?

Change to smt connector? CNC tech has no button?

is clamping diode on motor power rail?

more pins broke out!!? 5v,tx,rx,gnd,reset  , i2c

tighten smps to allow shield

SMT extension headers? 

Shrink annular ring on usb 2x4

ATX
trace on D10 out jack

clean up polygons (bed)+
traces
silk screens

qfn and fets
no tent on vias
thermal pad print too small


ATX no option to force psu on with vcc set to 5V rail

1.0a //////////////////////////////////////////////////////////////////

add tp for vref & ? on top
xy e ref pins switched in firmware
label testpoints, bottom silk

1.1a////////////////////////////////////////////////
tent mosfet vias

1.3a errata
"Therm" silk screen too far right
T2 silk too far right.
via in F3 pads top right and bottom left
fuse hole size?


