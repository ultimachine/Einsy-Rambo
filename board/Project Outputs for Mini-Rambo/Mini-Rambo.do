# Template Do File For Protel 99 -> Specctra Autorouter
# Protel International Pty Ltd
# 25-Jun-1999
#
unit mil
bestsave on C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.bst
status_file C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.sts
grid smart (wire 1) (via 1)
smart_route
critic

#enable the spread and miter features if you have the DFM option
#spread
#miter

# If you have the DFM module use spread and miter instead of the following. 
# Comment these lines out
Center
Recorner Diagonal 2000 2000 2000
Recorner Diagonal 1000 1000 1000
Recorner Diagonal 500 500 500
Recorner Diagonal 250 250 250
Recorner Diagonal 125 125 125
Recorner Diagonal 100 100 100
Recorner Diagonal 50 50 50
Recorner Diagonal 25 25 25
Recorner Diagonal 10 10 10
# Stop commenting here if you have the DFM module


write  routes      C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.rte
write  wires       C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.w
report conflicts   C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.rcf
report corners     C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.rcn
report rules       C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.rrl
report status      C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.rst
report unconnect   C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.ruc
report vias        C:\Users\johnny\Documents\GitHub\Mini-Rambo\board\Project Outputs for Mini-Rambo\Mini-Rambo.rva
quit
