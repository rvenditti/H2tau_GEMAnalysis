#!/bin/csh
setenv QUI $PWD
setenv VO_CMS_SW_DIR /opt/exp_soft/cms
source $VO_CMS_SW_DIR/cmsset_default.csh
setenv CASA /cmshome/venditti/AnalisiGEMSample_SHLC12_2/CMSSW_6_2_0_SLHC12/src/GEMSampleAnalysis/WH_PU40CMS2012_ProvaAnalisi
echo $CASA
cd $CASA
setenv SCRAM_ARCH slc5_amd64_gcc472
eval `scramv1 runtime -csh`
#cd $QUI
#cp $CASA/eseguibile_WH_PU40CMS2012_ProvaAnalisi1 .
./eseguibile_WH_PU40CMS2012_ProvaAnalisi1 >& /lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/WH_PU40CMS2012_ProvaAnalisi/WH_PU40CMS2012_ProvaAnalisi1.txt


