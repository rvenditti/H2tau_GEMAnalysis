#include "TCanvas.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TProfile.h"
#include "TBenchmark.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TFrame.h"
#include "TF1.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TTree.h"
#include "TH1.h"
#include "TPaveStats.h"
using namespace std;

void macroScema(){
	
	gROOT->ProcessLine(".L ./tdrstyle.C");
	setTDRStyle();
	
	TFile *_file0 = new TFile("histo_file_QCDPU50GEM2019.root");
	TFile *_file1 = new TFile("histo_file_VBFH2Tau_PU50GEM2019XX_noVBFTag.root");
	
	
	TH1F *hQCD = (TH1F*)_file0->Get("hMuonPtReco"); 
	TH1F *hH2tau = (TH1F*)_file1->Get("hMuonPtReco"); 
	hH2tau->SetLineColor(kRed);
	hQCD->SetLineColor(kMagenta);
	
	hH2tau->SetLineWidth(2);
	hQCD->SetLineWidth(2);
	
	hQCD->Scale(1/hQCD->Integral());
	hH2tau->Scale(1/hH2tau->Integral());
	
	hQCD->GetXaxis()->SetRangeUser(0,100);
	hH2tau->GetXaxis()->SetRangeUser(0,100);
	
	
	hQCD->Draw("histe");
	hH2tau->Draw("histesame");
	hQCD->GetXaxis()->SetTitle("P_{T}^{#mu}");
	hQCD->GetYaxis()->SetTitle("Relative Yield");
	TLegend* legend = new TLegend( 0.65, 0.7, 0.8, 0.9);
	legend->SetTextSize(0.035);
	legend->SetFillColor(0);
	legend->AddEntry(hH2tau, "H #rightarrow #tau_{#mu}  #tau_{h} ","l");
	legend->AddEntry(hQCD, "QCD","l");
	legend->Draw("same");
}
