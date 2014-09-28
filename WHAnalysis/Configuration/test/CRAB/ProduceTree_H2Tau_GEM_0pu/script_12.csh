#!/bin/csh
setenv QUI $PWD
setenv VO_CMS_SW_DIR /opt/exp_soft/cms
source $VO_CMS_SW_DIR/cmsset_default.csh
setenv CASA /cmshome/venditti/Prova/CMSSW_5_3_12/src/VHTauTau/TreeMaker/test/ProduceTree_DY_8tev
echo $CASA
cd $CASA
setenv SCRAM_ARCH slc5_amd64_gcc472
eval `scramv1 runtime -csh`


cmsRun test_data12.py >& /lustre/cms/store/user/rosma/UpgradePh1_FullSim_16July/DYJetsToLL_M-50_13TeV_Fall13_PU20bx25_Tree/12.txt


