#!/bin/tcsh

set dirin = $*
    foreach i (`ls -1 "$dirin" | grep GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot | awk '{print $NF}'`)

echo  ''$dirin$i','

end

