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
#include "VHAnalyser_Jan13.h"
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
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_10_2_ydJ.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_11_2_JJm.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_12_2_nYB.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_1_2_L1N.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_13_2_WYs.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_14_2_qwK.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_15_2_AdW.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_16_2_F9j.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_17_2_x5s.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_18_2_Pbr.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_19_2_nyq.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_20_2_22m.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_21_1_W4n.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_2_2_79Z.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_3_2_Zve.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_4_2_fyB.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_5_2_KV3.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_6_2_rNj.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_7_2_S8w.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_8_2_v0o.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6_GEM2019Upg14DR-PU50bx25/tree_9_2_ivs.root");
std::string histo_fname ="/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/WH_PU50GEM2019/histo_file_WH_PU50GEM20190.root";
  VHAnalyser_Jan13* myanal = new VHAnalyser_Jan13(chain, histo_fname);
  myanal->bookHistograms();
  myanal->Loop();
  myanal->saveHistograms();
  //file->Close();
//  delete chain;
//  delete myanal;
gSystem->Exit(0);
return 0;
}
