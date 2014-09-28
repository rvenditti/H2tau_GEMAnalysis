#!/bin/csh

set i = 0
#for i in $(seq 1 20); do
#foreach i (seq 1 20) 
while ($i<4)
./new_script_WH.csh VBFH2Tau_PU50GEM2019_ProvaAnalisi$i
@ i++
end

#exit 0
