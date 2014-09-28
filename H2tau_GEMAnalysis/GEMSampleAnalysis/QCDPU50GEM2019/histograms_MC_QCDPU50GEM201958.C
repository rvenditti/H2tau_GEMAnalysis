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
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_502_2_xE4.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_50_2_cXi.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_504_2_K0J.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_505_2_SZ3.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_506_1_rpG.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_509_2_T4G.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_510_1_lLn.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_51_1_4AW.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_516_1_W1c.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_518_1_aCS.root");
std::string histo_fname ="/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/QCDPU50GEM2019/histo_file_QCDPU50GEM201958.root";
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
