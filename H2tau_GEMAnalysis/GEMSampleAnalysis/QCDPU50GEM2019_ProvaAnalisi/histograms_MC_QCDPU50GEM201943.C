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
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_205_2_5sx.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_206_2_JTf.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_207_2_79d.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_208_2_DoC.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_210_2_rRV.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_21_2_2B1.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_212_2_Cyw.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_213_2_tLF.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_215_2_luH.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_220_2_8ne.root");
std::string histo_fname ="/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/QCDPU50GEM2019/histo_file_QCDPU50GEM201943.root";
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
