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
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_39_2_bI9.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_393_2_OMN.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_396_2_ZH8.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_397_1_f35.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_398_2_YZz.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_400_2_ZFW.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_402_2_cXL.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_408_2_xPr.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_410_1_Pt0.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_412_1_hoh.root");
std::string histo_fname ="/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/QCDPU50GEM2019/histo_file_QCDPU50GEM201952.root";
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
