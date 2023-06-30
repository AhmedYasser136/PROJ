(Scribbled version of C:\Users\AHMEDY~1\AppData\Local\Temp\ink_ext_XXXXXX.svgWOTVX0 @ 3000.00)
( unicorn.py --tab="plotter_setup" --pen-up-angle=50 --pen-down-angle=30 --start-delay=160 --stop-delay=150 --xy-feedrate=3000 --z-feedrate=150 --z-height=0 --finished-height=0 --register-pen=true --x-home=0 --y-home=0 --num-copies=1 --continuous=false --pause-on-layer-change=false C:\Users\AHMEDY~1\AppData\Local\Temp\ink_ext_XXXXXX.svgWOTVX0 )
G21 (metric ftw)
G90 (absolute mode)
G92 X0.00 Y0.00 Z0.00 (you are here)

M300 S30 (pen down)
G4 P160 (wait 160ms)
M300 S50 (pen up)
G4 P150 (wait 150ms)
M18 (disengage drives)
M01 (Was registration test successful?)
M17 (engage drives if YES, and continue)

(Polyline consisting of 2 segments.)
G1 X0.95 Y-0.04 F3000.00
M300 S30.00 (pen down)
G4 P160 (wait 160ms)
G1 X16.58 Y37.67 F3000.00
G1 X22.39 Y37.67 F3000.00
G1 X39.05 Y-0.04 F3000.00
G1 X32.91 Y-0.04 F3000.00
G1 X28.16 Y11.38 F3000.00
G1 X11.14 Y11.38 F3000.00
G1 X6.67 Y-0.04 F3000.00
G1 X0.95 Y-0.04 F3000.00
M300 S50.00 (pen up)
G4 P150 (wait 150ms)

(Polyline consisting of 2 segments.)
G1 X12.70 Y15.44 F3000.00
M300 S30.00 (pen down)
G4 P160 (wait 160ms)
G1 X26.50 Y15.44 F3000.00
G1 X22.25 Y25.89 F3000.00
G1 X19.36 Y33.71 F3000.00
G1 X18.42 Y30.09 F3000.00
G1 X17.17 Y26.51 F3000.00
G1 X12.70 Y15.44 F3000.00
M300 S50.00 (pen up)
G4 P150 (wait 150ms)


(end of print job)
M300 S50.00 (pen up)
G4 P150 (wait 150ms)
M300 S255 (turn off servo)
G1 X0 Y0 F3000.00
G1 Z0.00 F150.00 (go up to finished level)
G1 X0.00 Y0.00 F3000.00 (go home)
M18 (drives off)
