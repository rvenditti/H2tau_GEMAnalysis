#!/bin/tcsh

set dirin = $*
foreach i (`ls -1 "$dirin" | grep tree | awk '{print $NF}'`)

echo  'chain->AddFile("'$dirin$i'");'

end

