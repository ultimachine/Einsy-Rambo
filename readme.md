Mini-Rambo

3D Printer controller.

This board is based of RAMBo based off the Arduino MEGA design and work of RepRap community. It has 4 stepper drivers and 4 mosfet switched outputs.

There is no warantee for these files in any way. There may have been some undocumented tweaks by various designers, engineers, manufacturers, suppliers, and assemblers to make this a functional product.

#Version History
Note: This design was previously known as "Mini-RAMBo"  Previous versions of this design can be found at https://github.com/ultimachine/Mini-Rambo

v0.3a:
- Changed name from "Mini-Rambo" to "Einsy-Rambo".
- Uses the Trinamics TMC2130 motor driver in a 5x6mm QFN36 package.
- Added series resistance and TVS to selected signals.
- Overvoltage protection added to thermistors.
- Corrected and added testpoints
- Added GPIO connection "XTRA0" (currently unused) from 32U2, through the galvanic isolator, and into the Mega2560
- Added ferrite to AVdd pin of the 32U2
- Moved the XTAL of the 32U2
- Fixed the soldermask under the 5V buck regulator
- Removed via tenting underneath QFN packages, as well as all other packages with an SMT heat slug/tab
- Added pin1 marking to silkscreen
- Added teardrops to vias
- Changed via sizes to 10/22 and 15/30 (mils).
- Added GND polygon to XTAL of Mega2560
- Changes 5V inductor footprint for the 5V buck converter to fit two differing inductor package mechanicals
- Added I2C pullups (currently set to "Do Not Stuff")
- Adjustments to fuse holder footprint
- Decreased t-hole size of main power connector
- Fan connectors now have a third pin for reading fan tach pulses.
- Adjusted stackup to be more "standard"
- Added 100R to the gate of each FET