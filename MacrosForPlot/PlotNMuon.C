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

void PlotNMuon() {
  gROOT->ProcessLine(".L ./tdrstyle.C");
  setTDRStyle();
  Int_t r=1; 
  TFile *f =new TFile("histo_file_VBFHTT_GEM_GenOnlyXX.root");
  TFile *f1 = new TFile("histo_file_VBFHTT_GEM_GenOnlyXX.root");
  // TFile *f =new TFile("histo_PU0_GEM4feb.root");
  //  TFile *f = new TFile("histo_file_GluGluToHToTauTau_PU50_GEN.root");
  TH1F *heta10 = (TH1F*)f->Get("AbsEtaMuon_10");
  TH1F *heta15 = (TH1F*)f->Get("AbsEtaMuon_15");
  TH1F *heta20 = (TH1F*)f->Get("AbsEtaMuon_20");  
  TH1F *heta25 = (TH1F*)f->Get("AbsEtaMuon_25"); 
  TH1F *heta30 = (TH1F*)f->Get("AbsEtaMuon_30"); 
  TH1F *heta35 = (TH1F*)f->Get("AbsEtaMuon_35");

  TH1F *heta = (TH1F*)f->Get("AbsEtaMuon");

  std::cout<<" pt>10;  "<<heta10->Integral()<<" ;Ratio in 0<eta<1.6=; "<<100*(heta10->Integral(0,15))/heta10->Integral()<<" ;Ratio in 1.6<eta<2.1=;"<<100*(heta10->Integral(16,23))/heta10->Integral()<<" ;Ratio in 2.1<eta<2.4=;"<<100*(heta10->Integral(24,51))/heta10->Integral()<<endl;
        
  std::cout<<" pt>15;  "<<heta15->Integral()<<" ;Ratio in 0<eta<1.6=; "<<100*(heta15->Integral(0,15))/heta15->Integral()<<" ;Ratio in 1.6<eta<2.1=;"<<100*(heta15->Integral(16,23))/heta15->Integral()<<" ;Ratio in 2.1<eta<2.4=;"<<100*(heta15->Integral(24,51))/heta15->Integral()<<endl;

  std::cout<<" pt>20;  "<<heta20->Integral()<<" ;Ratio in 0<eta<1.6=; "<<100*(heta20->Integral(0,15))/heta20->Integral()<<" ;Ratio in 1.6<eta<2.1=;"<<100*(heta20->Integral(16,23))/heta20->Integral()<<" ;Ratio in 2.1<eta<2.4=;"<<100*(heta20->Integral(24,51))/heta20->Integral()<<endl;

  std::cout<<" pt>25;  "<<heta25->Integral()<<" ;Ratio in 0<eta<1.6=; "<<100*(heta25->Integral(0,15))/heta25->Integral()<<" ;Ratio in 1.6<eta<2.1=;"<<100*(heta25->Integral(16,23))/heta25->Integral()<<" ;Ratio in 2.1<eta<2.4=;"<<100*(heta25->Integral(24,51))/heta25->Integral()<<endl;

  std::cout<<" pt>30;  "<<heta30->Integral()<<" ;Ratio in 0<eta<1.6=; "<<100*(heta30->Integral(0,15))/heta30->Integral()<<" ;Ratio in 1.6<eta<2.1=;"<<100*(heta30->Integral(16,23))/heta30->Integral()<<" ;Ratio in 2.1<eta<2.4=;"<<100*(heta30->Integral(24,51))/heta30->Integral()<<endl;

  std::cout<<" pt>35;  "<<heta35->Integral()<<" ;Ratio in 0<eta<1.6=; "<<100*(heta35->Integral(0,15))/heta35->Integral()<<" ;Ratio in 1.6<eta<2.1=;"<<100*(heta35->Integral(16,23))/heta35->Integral()<<" ;Ratio in 2.1<eta<2.4=;"<<100*(heta35->Integral(24,51))/heta35->Integral()<<endl;

  std::cout<<"  ****eta in (0,1.6)*****     "<<endl;     
  std::cout<<" pt>10;  "<<(heta10->Integral(0,16))<<endl;
  std::cout<<" pt>15;  "<<(heta15->Integral(0,16))<<endl;
  std::cout<<" pt>20;  "<<(heta20->Integral(0,16))<<endl;
  std::cout<<" pt>25;  "<<(heta25->Integral(0,16))<<endl;
  std::cout<<" pt>30;  "<<(heta30->Integral(0,16))<<endl;
  std::cout<<" pt>35;  "<<(heta35->Integral(0,16))<<endl;
  std::cout<<"  ****eta in (1.6,2.4)*****     "<<endl;


  std::cout<<"  ****eta in (1.6,2.1)*****     "<<endl;
  std::cout<<" pt>10;  "<<(heta10->Integral(17,21))<<endl;
  std::cout<<" pt>15;  "<<(heta15->Integral(17,21))<<endl;
  std::cout<<" pt>20;  "<<(heta20->Integral(17,21))<<endl;
  std::cout<<" pt>25;  "<<(heta25->Integral(17,21))<<endl;
  std::cout<<" pt>30;  "<<(heta30->Integral(17,21))<<endl;
  std::cout<<" pt>35;  "<<(heta35->Integral(17,21))<<endl;
  std::cout<<"  ****eta in (1.6,2.1)*****     "<<endl;


  std::cout<<"  ****eta in (2.1,2.4)*****     "<<endl;
  std::cout<<" pt>10;  "<<(heta10->Integral(22,24))<<endl;
  std::cout<<" pt>15;  "<<(heta15->Integral(22,24))<<endl;
  std::cout<<" pt>20;  "<<(heta20->Integral(22,24))<<endl;
  std::cout<<" pt>25;  "<<(heta25->Integral(22,24))<<endl;
  std::cout<<" pt>30;  "<<(heta30->Integral(22,24))<<endl;
  std::cout<<" pt>35;  "<<(heta35->Integral(22,24))<<endl;
  std::cout<<"  ****eta in (2.1,2.4)*****     "<<endl;
cout<<" pt>10  "<<	heta10->Integral()<<endl;
cout<<" pt>35  "<<	heta35->Integral()<<endl;



  TH2F *ptvseta_gen = (TH2F*)f->Get("MuonEta_vs_Pt");
  TCanvas *Canv2 = new TCanvas("Canv2","",700,600);
  Canv2->cd();
	ptvseta_gen->GetXaxis()->SetTitle("#eta_{#mu}^{reco}");
	ptvseta_gen->GetYaxis()->SetTitle("Pt_{#mu}^{reco}");

  ptvseta_gen->Draw("COLZ");	
  ptvseta_gen->GetXaxis()->SetRange(0,30);	
	
	Canv2->SaveAs("etaVSpt.pdf");	
	
  cout<<" Nbin x  "<<ptvseta_gen->GetNbinsX()<<" N bin y "<<ptvseta_gen->GetNbinsY()<<endl;
  double sum, sum_roi, sum2, sum_roi2;
  // std::vector<double> 
  heta10->SetTitle("Reco Muon Pseudorapidity");
  heta10->Rebin(r); heta15->Rebin(r);  heta25->Rebin(r);  heta35->Rebin(r);
  heta10->SetStats(kFALSE);  heta15->SetStats(kFALSE);   heta25->SetStats(kFALSE);   heta35->SetStats(kFALSE); heta20->SetStats(kFALSE);  heta30->SetStats(kFALSE);
  heta10->SetAxisRange(0,3);  heta15->SetAxisRange(0,3); heta20->SetAxisRange(0,3);heta25->SetAxisRange(0,3); heta30->SetAxisRange(0,3); heta35->SetAxisRange(0,3); 
  heta10->GetXaxis()->SetTitle("#eta_{#mu}^{Reco}"); 
  heta10->GetYaxis()->SetTitleOffset(1.5); 
  heta10->GetYaxis()->SetTitle("Events"); 
  heta10->SetLineColor(kGreen);
  heta15->SetLineColor(kAzure);
  heta20->SetLineColor(kMagenta);
  heta25->SetLineColor(kRed);
  heta30->SetLineColor(kOrange);
  heta35->SetLineColor(kTeal+5);
	
	/////////////////////////// canvas 3///////////////////////////                                                                                                                                            
	TCanvas *Canv1 = new TCanvas("Canv1","Pt Resolution ",700,600);
	Canv1->cd();
	heta35->GetYaxis()->SetTitle("Events");
	heta35->GetXaxis()->SetTitle("#eta(#mu_reco)");
	heta10->Draw("histe");
	heta15->Draw("histeSAME");
	heta20->Draw("histeSAMES");
	heta25->Draw("histeSAMES");
	heta30->Draw("histeSAMES");
	heta35->Draw("histeSAMES");
	
	gPad->Update();
	
	TLegend* legend = new TLegend( 0.77, 0.6, 0.87, 0.92);
	legend->SetTextSize(0.035);
	legend->SetFillColor(0);
	legend->AddEntry(heta10, "pt>10 ","f");
	legend->AddEntry(heta15, "pt>15 ","f");
	legend->AddEntry(heta20, "pt>20","f");
	legend->AddEntry(heta25, "pt>25","f");
	legend->AddEntry(heta30, "pt>30","f");
	legend->AddEntry(heta35, "pt>35","f");
	Canv1->cd();
	legend->Draw("same");
	
	Canv1->SaveAs("EtaVSEvt.pdf");
	
	
 
}
