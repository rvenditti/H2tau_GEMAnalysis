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
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_10_1_rul.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_10_2_3kU.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_11_2_7l7.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_1_1_eE0.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_12_1_3nm.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_12_2_ttv.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_1_2_4yb.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_13_1_Phg.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_13_2_xmk.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_14_1_Tq6.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_14_2_qg9.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_15_1_z5n.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_15_2_ele.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_16_1_13z.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_16_2_DQE.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_17_1_T75.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_17_2_4ba.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_18_1_eDo.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_18_2_wCl.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_19_1_vX1.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_19_2_UvQ.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_20_1_Wb3.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_20_2_O8x.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_2_2_yVk.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_3_1_IhD.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_3_2_XOn.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_4_1_bPz.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_4_2_b9i.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_5_1_JWw.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_5_2_b3k.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_6_1_1hg.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_6_2_RXG.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_7_1_9XG.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_7_2_8VA.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_8_1_kZQ.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_8_2_w9R.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_9_1_eZZ.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/VBF_HToTauTau_M-125_14TeV_GEM2019Upg14DR-PU50/tree_9_2_wRT.root");
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
