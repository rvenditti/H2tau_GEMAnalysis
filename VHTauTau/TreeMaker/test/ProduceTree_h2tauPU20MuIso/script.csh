#!/bin/csh

cat > script_$1.csh << EOF
#!/bin/csh
setenv QUI \$PWD
setenv VO_CMS_SW_DIR /opt/exp_soft/cms
source \$VO_CMS_SW_DIR/cmsset_default.csh
setenv CASA `pwd`
echo \$CASA
cd \$CASA
setenv SCRAM_ARCH slc6_amd64_gcc462
eval \`scramv1 runtime -csh\`

cmsRun test_data$1.py >& /lustre/cms/store/user/rosma/UpgradePh1_FullSim_16July/GluGluToHToTauTau_Fall13_Tree_v2/$1.txt


EOF

chmod 777 script_$1.csh
qsub -q local script_$1.csh
