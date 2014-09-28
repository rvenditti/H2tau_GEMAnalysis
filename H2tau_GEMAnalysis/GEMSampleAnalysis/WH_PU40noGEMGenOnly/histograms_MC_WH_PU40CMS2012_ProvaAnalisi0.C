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
#include "VHAnalyzer.h"
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
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_1_1_EUG.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_12_1_axt.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_13_1_t8f.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_14_1_Nc4.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_15_1_6Wv.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_16_1_Jbr.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_17_1_aka.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_18_1_xHn.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_19_1_Wo8.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_21_1_BRW.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_2_1_Smo.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_22_1_eaH.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_3_1_Wg8.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_4_1_gnF.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_7_1_sF0.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_8_1_ZTx.root");
std::string histo_fname = "/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/WHmtt_GEM_GenOnly/histo_file_WHmtt_noGEMPU40_GenOnly.root";
  VHAnalyzer* myanal = new VHAnalyzer(chain, histo_fname);
  myanal->bookHistograms();
  myanal->Loop();
  myanal->saveHistograms();
  //file->Close();
//  delete chain;
//  delete myanal;
gSystem->Exit(0);
return 0;
}
