Readme File for Printed Circuit Board 'Einsy_Rambo_1.2c'

Board Specification
Part Number            Einsy_Rambo
Revision               1.2c
Board size             105 x 71mm
Board Thickness        1.524mm (0.06")
Board type             Rigid
Number of layers       6
P.C.B material         RoHS TG170
Finished Copper        2oz, 1oz (See Stackup)
Finish                 ENIG (Gold) (Lead free) (RoHS)
Mask type              See special requirement below
Mask color             Orange -See special requirement below
Silk screen color      Black -See special requirement below
Silk screen Sides      BOTH 
Min trace width        0.006"
Min clearance          0.008"
Min Hole Diameter >=   10mil
Gold Edge Connectors   No
Internal slots/routes  0
Blind Vias             No
Buried Vias            No
No of Boards/Panel     3
Routing                V-Score
Panel Size     116.8 X 226.1mm

Drill format           Leading zero suppression 2.4

Special Requirements
1. Fabricate PCB in accordiance with IPC-A-600 CLASS 2 (LATEST REVISION)
2. The PCB must be lead free assembly process compatible.
  Must handle minimum 6 cycles - 260C for 10 seconds.
3. Please ship panels including rails with tooling holes and fiducials in gerber files.
4.UL LOGO + ID and ROHS logo to be placed on solder side (bottom silk screen) by board fab in 
    regions in Einsy_Rambo_Panel.GM29.
  Do not add any marking to bottom areas marked in GM9. We require this area blank for production 
    laser marking.
5. We wish to have an orange soldermask with a black soldermask on top. Print soldermask Orange as 
  provided. Print silk screen layer Einsy_Rambo_Panel.GTO INVERTED (negative) in black.
  The end result should be a black surface with orange silkscreen legend showing from beneath. 
  See image Black-Orange.png
6. Please note that extra top silkscreen has been poured around several QFN packages.
  Please do not remove this silkscreen... the silkscreen fixes an anomaly where black
  and orange soldermask stack up and raise the QFN package off of the land pattern.
  Placing the extra silckscreen causes the black soldermask to be removed in these areas,
  which fixes the problem.

Critical Tolerances: None

Layer Description
(Note: Inner layers are counted from the top downwards)
Top Paste                     Einsy_Rambo_Panel.GTP
Top Silk Screen               Einsy_Rambo_Panel.GTO
Top Solder Mask               Einsy_Rambo_Panel.GTS
Top Copper                    Einsy_Rambo_Panel.GTL
Inner Plane 1                 Einsy_Rambo_Panel.GP1
Inner Signal 1                Einsy_Rambo_Panel.G1
Inner Signal 2                Einsy_Rambo_Panel.G2
Inner Signal 3                Einsy_Rambo_Panel.G3
Bottom Copper                 Einsy_Rambo_Panel.GBL
Bottom Solder Mask            Einsy_Rambo_Panel.GBS
Bottom Silk Screen            Einsy_Rambo_Panel.GBO
NC Drill File                 Einsy_Rambo_Panel.TXT
Board Dimensions              Einsy_Rambo_Panel.GM8
Panel Dimensions              Einsy_Rambo_Panel.GM30
Panel                         Einsy_Rambo_Panel.GM1
Fabrication Notes             Einsy_Rambo_Panel.GM2
UL Logo Placement             Einsy_Rambo_Panel.GM29
Panel Dimension               Einsy_Rambo_Panel.GM30
V-Score                       Einsy_Rambo_Panel.GM31
Panel Outline                 Einsy_Rambo_Panel.GM32
IPC-D-356 Netlist             Einsy_Rambo_Panel IPC-D-356.net
Stackup                       Stack up.jpg

Contact Information
Company        UltiMachine
Address        200 12th St. N.
City           South Pittsburg
State          TN
PostCode       37380
Country        USA
Email          info@ultimachine.com
Phone          423-228-0005
