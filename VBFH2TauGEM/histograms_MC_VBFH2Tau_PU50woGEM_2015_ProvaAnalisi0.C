#if !defined(__CINT__) || defined(__MAKECINT__)
#include <TROOT.h>
#include <TSystem.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TObject.h>
#include <TCanvas.h>
#include <TKey.h>
#include <TStyle.h>
#include <TTree.h>
#include <TLegend.h>
#include "VHAnalyzer_WH_New.h"
#include <TString.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "TChain.h"
#include <stdlib.h>
#endif
using namespace std;
int main() {
   TChain* chain = new TChain("treeCreator/vhtree");
   //WH
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_10_1_1UL.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_11_1_Y82.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_1_1_SPM.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_12_1_S55.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_13_1_dqD.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_15_1_kNa.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_16_1_7i9.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_17_1_Dyf.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_18_1_hG4.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_19_1_zqE.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_21_1_1rs.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_2_1_qEC.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_22_1_gJl.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_24_1_R6z.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_27_1_3Bt.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_28_1_Ymb.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_30_1_cCb.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_3_1_0i2.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_31_1_z98.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_32_1_xpK.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_33_1_Bv9.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_34_1_Qph.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_35_1_LgG.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_36_1_822.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_37_1_GF2.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_38_1_UB7.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_39_1_skE.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_40_1_Pql.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_41_1_P5O.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_42_1_5Ld.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_43_1_0Nz.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_45_1_EcD.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_46_1_bA7.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_47_1_zdv.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_48_1_ozZ.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_49_1_SEZ.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_50_1_S4a.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_51_1_7hq.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_52_1_MIC.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_6_1_xBz.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_7_1_Rf6.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_8_1_fJr.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/tree_9_1_jj4.root");
std::string histo_fname ="/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/H2tau_VBF/VBFH2Tau_PU50woGEM_2015/histo_file_VBFH2Tau_PU50woGEM_2015XX.root";
  VHAnalyzer_WH_New* myanal = new VHAnalyzer_WH_New(chain, histo_fname);
  myanal->bookHistograms();
  myanal->Loop();
  myanal->saveHistograms();
  //file->Close();
//  delete chain;
//  delete myanal;
gSystem->Exit(0);
return 0;
}
