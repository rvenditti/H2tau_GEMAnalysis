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
#cd \$QUI
#cp \$CASA/eseguibile_$1 .
./eseguibile_$1 >& /lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/WH_PU40CMS2012_ProvaAnalisi/$1.txt


EOF

g++ -I $ROOTSYS/include  histograms_MC_$1.C VHAnalyser_Jan13.C `root-config --glibs` `root-config --libs` `root-config --cflags` -o eseguibile_$1

chmod 777 script_$1.csh
qsub -q local script_$1.csh
#qsub -q short script_$1.csh
