#!/bin/csh

set i = 0
while ($i<10)
./script.csh $i
@ i++
end

#exit 0