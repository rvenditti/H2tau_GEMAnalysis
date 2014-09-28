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
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_1488_2_TQz.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_1491_2_ugN.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_1493_2_cjC.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_1495_2_vsd.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_1496_2_vNh.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_1497_1_IZu.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_1499_2_9Fj.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_1500_2_UIP.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_150_2_9TT.root");
chain->AddFile("/lustre/cms/store/user/rosma/SamplePh2/QCD_Pt-15to3000_Tune4C_Flat_14TeV_GEM2019Upg14DR-PU50bx25/tree_1505_2_QV3.root");
std::string histo_fname ="/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/QCDPU50GEM2019/histo_file_QCDPU50GEM201934.root";
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
