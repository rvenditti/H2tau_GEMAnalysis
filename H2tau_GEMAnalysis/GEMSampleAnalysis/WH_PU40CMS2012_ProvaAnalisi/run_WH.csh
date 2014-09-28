#!/bin/csh

set i = 0
#for i in $(seq 1 20); do
#foreach i (seq 1 20) 
while ($i<7)
./new_script_WH.csh WH_PU40CMS2012_ProvaAnalisi$i
@ i++
end

#exit 0
