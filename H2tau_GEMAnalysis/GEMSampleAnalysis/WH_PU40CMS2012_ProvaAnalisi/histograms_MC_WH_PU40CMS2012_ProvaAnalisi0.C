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
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_1_1_EUG.root");
chain->AddFile("/lustre/cms/store/user/rosma/TauIsoUpgrade/WH_ZH_HToMuMu_M-125_13TeV_PU40bx25_2/tree_12_1_axt.root");
std::string histo_fname ="/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/WH_PU40CMS2012_ProvaAnalisi/histo_file_WH_PU40CMS2012_ProvaAnalisi0.root";
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
