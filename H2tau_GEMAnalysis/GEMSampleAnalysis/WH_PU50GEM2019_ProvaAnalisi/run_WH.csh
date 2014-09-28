#!/bin/csh

set i = 0
#for i in $(seq 1 20); do
#foreach i (seq 1 20) 
while ($i<19)
./new_script_WH.csh ZTTPU50GEM2019$i
@ i++
end

#exit 0
