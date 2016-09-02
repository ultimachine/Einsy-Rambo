send motors to trinamic for calibration.
DNI: DCIN can be used as emergency stop. Also step gating
Sense resistor selection
barrier block hole size
DIAG1

DONE
Replace pth caps with smt
change stackup to improve impedance. add power plane capacitor to adum
Keep existing test point locations.
change extension headers to accept housings
terminating resistors to spi?


TODO
measure back emf from spun motors.
test clamping diode sizes

fix silks

add stitching capacitor between 5v and 12 rail? And to gnd?

rename motor rail vmot. find other wires that should be renamed vmot!

Extruder heater TP17, HB TP18, TP69, 

add series resistors to endstops and other pins where possible

switch x and y dir pins

idc ? http://www.digikey.com/product-search/en?keywords=302-s101



DONT DO
Add break away power connector label / panel rails
Use label to mark pins on power connector?

Change TVS diode on motor input to cheaper part? replace tvs back on if off?

remove third resistor from vref.

UNKNOWN STATUS
add angle mask stop slots under driver?

add vcc polygon back to supply layer

FIRST PROTO DISCOVERIES
Solder apertures ratio for tmc is 7. AGI changed it to a 10.


NEW TASK LIST
Check thermal connection to ground, etc.
move endstop protection resistor to connector side of MLV ? This will make it less of a noise filter. We probably want to leave it the way it is and over voltage blowing MLV will be??

michal's fan request
clean up motor ip

ADC to extensions