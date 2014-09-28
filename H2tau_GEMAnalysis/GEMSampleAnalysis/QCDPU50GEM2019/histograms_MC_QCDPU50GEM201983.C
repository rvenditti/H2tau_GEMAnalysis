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
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_966_1_8Jo.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_967_1_uno.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_968_1_8nW.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_970_2_kF9.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_97_2_0qN.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_972_2_BwF.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_973_2_XHN.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_974_2_vrM.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_976_2_nvh.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_977_2_gp1.root");
std::string histo_fname ="/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/QCDPU50GEM2019/histo_file_QCDPU50GEM201983.root";
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
