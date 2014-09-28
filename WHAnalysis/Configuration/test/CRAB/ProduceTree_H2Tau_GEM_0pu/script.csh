#!/bin/csh

cat > script_$1.csh << EOF
#!/bin/csh
setenv QUI \$PWD
setenv VO_CMS_SW_DIR /opt/exp_soft/cms
source \$VO_CMS_SW_DIR/cmsset_default.csh
setenv CASA `pwd`
echo \$CASA
cd \$CASA
setenv SCRAM_ARCH slc5_amd64_gcc472
eval \`scramv1 runtime -csh\`


cmsRun test_data$1.py >& /lustre/cms/store/user/rosma/UpgradePh1_FullSim_16July/DYJetsToLL_M-50_13TeV_Fall13_PU20bx25_Tree/$1.txt


EOF

chmod 777 script_$1.csh
qsub -q local script_$1.csh
