#!/bin/tcsh

set dirin = $*
foreach i (`ls -1 "$dirin" | awk '{print $NF}'`)

echo  'chain->AddFile("'$dirin$i'");'
end

