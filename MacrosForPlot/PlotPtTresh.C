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

void PlotPtTresh() {
	//  gROOT->ProcessLine(".L ./tdrstyle.C");
	//  setTDRStyle();
	Int_t r=1; 
	
//	TFile *f1 = new TFile("histo_file_VBFH2Tau_PU50GEM2019XX.root");
	TFile *f1 = new TFile("histo_file_VBFH2Tau_PU50GEM2019XX_noVBFTag.root");
	//TFile *f1 = new TFile("histo_file_QCDPU50GEM2019.root");
	
	char  histo[40], histo1[40], histo2[40], histoDC[40];
	
	TH1F *hInitialBarrel = (TH1F*)f1->Get("hInitialBarrel"); 
	TH1F *hInitialEndcap = (TH1F*)f1->Get("hInitialEndcap"); 	
	
	TH1F *hPtBarrel = (TH1F*)f1->Get("hMuonPtFinal_Barrel"); 
	TH1F *hPtHE = (TH1F*)f1->Get("hMuonPtFinal_HE"); 
	TH1F *hPtFull = (TH1F*)f1->Get("hMuonPtFinal_Full"); 
	TH1F *hInitial = (TH1F*)f1->Get("entries_after_vertex"); 
	TH1F *hWP2012Pt = (TH1F*)f1->Get("hMuonPtWP2012"); 
	TH1F *h_HTot = (TH1F*)f1->Get("H_tot"); 
	TH1F *initial_entries = (TH1F*)f1->Get("initial_entries"); 
	
	cout<<"Htot"<<h_HTot->Integral()<<"  initial entries  "<<initial_entries->Integral()<<endl;
	
	int  Ninitial=hInitial->Integral();    
	cout<<" initial  "<<Ninitial<<endl;
	cout<<" initial  barrel "<<hInitialBarrel->Integral()<<endl;
	cout<<" initial endcap"<<hInitialEndcap->Integral()<<endl;
	
	cout<<" after muon barrel  "<<hPtBarrel->Integral()<<endl;
	cout<<" after muon HE  "<<hPtHE->Integral()<<endl;
	
	float MuonEff2012[1] =0;
	MuonEff2012[0]= hWP2012Pt->Integral()/hInitial->Integral();
	float Err_MuonEff2012[1];
	Err_MuonEff2012[0]=(TMath::Sqrt(Err_MuonEff2012[0]*(1-Err_MuonEff2012[0])))/Ninitial;
	//cout<<"Muon Eff WP 2012 "<<hWP2012Pt->Integral()/hInitial->Integral()<<endl;
	
	/////////////////////////compute selection eff as a function of muon pt threshold/////////////////////////////
	int EvAfterPtCut_HE[100]; float EffSel[100], xgr[100], ex[100],ey[100], EffSelFull[100], eyfull[100], Eff_Barrel[100], Eff_Endcap[100], err_Eff_barrel[100],err_Eff_endcap[100];
	int EvAfterPtCut_Barrel[100]; 
	int EvAfterPtCut[100];
	int EvAfterPtCut_BB[100];	
	int EvAfterPtCut_EE[100];	
	
	//  std::cout<<" Muon Pt in |eta|<2.4 "<<hMuonTot->Integral(0,200)<<endl;
	
	for(int i=0;i<40;i++){
		EvAfterPtCut_Barrel[i]=hPtBarrel->Integral(10,100);
		EvAfterPtCut_HE[i]=hPtHE->Integral(i+1,100);
		
		EvAfterPtCut[i]=hPtFull->Integral(i+1,100); 
		EvAfterPtCut_BB[i] =hPtBarrel->Integral(i+1,100);
		EvAfterPtCut_EE[i] =hPtHE->Integral(i+1,100);
		
		EffSelFull[i] = EvAfterPtCut[i] / (hInitialBarrel->Integral() + hInitialEndcap->Integral() );		
		Eff_Barrel[i]= EvAfterPtCut_BB[i]/hInitialBarrel->Integral();  
		Eff_Endcap[i]=EvAfterPtCut_EE[i]/hInitialEndcap->Integral();  
		
		std::cout<<i*2<<" nev after pt cut barrel "<<EvAfterPtCut_BB[i]<<"  nev after pt cut endcap  "<<EvAfterPtCut_HE[i]<<"  eff sel  "<<endl;
		
		xgr[i]=i*2;
		ex[i]=0; 
		EffSel[i]=(EvAfterPtCut_Barrel[i]+EvAfterPtCut_HE[i])/(hInitial->Integral());
		
		ey[i]=TMath::Sqrt((EffSel[i]*(1-EffSel[i])))/hInitial->Integral();
		eyfull[i]=TMath::Sqrt((EffSelFull[i]*(1-EffSelFull[i])))/hInitial->Integral();
		//  std::cout<<i*2<<" nev after pt cut barrel || endcap "<<EvAfterPtCut_Barrel[i]+EvAfterPtCut_HE[i]<<" eff sel  "<<EffSel[i]<<" errore "<<ey[i]<<endl;
	}
	
	double xgr12[1]; xgr12[0]=13.0; 
	double ex12[1]; ex12[0]=0.; 
	TGraphErrors* gr = new TGraphErrors(26,xgr,EffSel,ex,ey);
	TGraphErrors* gr_full = new TGraphErrors(26,xgr,EffSelFull,ex,eyfull);
	TGraph* gr12 = new TGraph(1);
	gr12->SetPoint(0,20,MuonEff2012[0]);
	
	TGraphErrors* gr_BB = new TGraphErrors(26,xgr,Eff_Barrel,ex,ey);	
	TGraphErrors* gr_EE = new TGraphErrors(26,xgr,Eff_Endcap,ex,ey);	
	
	///////////////////////////////////////////************************************////////////////////////////////////////////
	TCanvas *Canv5 = new TCanvas("Canv5","Palle",800,700);
	gr->SetMarkerStyle(24);  
	gr12->SetMarkerStyle(23); 
	gr->SetMarkerColor(kRed);  
	gr12->SetMarkerColor(kBlue);  
	gr->SetTitle(" Selection Efficiency as a function of muon pt threshold ");
	gr->GetYaxis()->SetTitle("Selection Efficiency");
	gr->GetYaxis()->SetTitleOffset(1.4);
	gr->GetXaxis()->SetTitle("P_{T}^{#mu Endcap} Cut (GeV/c)");
	
	gr->SetMarkerSize(1.2);  
	gr12->SetMarkerSize(1.4); 
	
	gr->Draw("ACP");
	gr12->Draw("CP");
	gr->SetMinimum(0.5);
	TLegend* legend = new TLegend( 0.15, 0.5, 0.75, 0.7);
	legend->SetTextSize(0.025);
	legend->SetFillColor(0);
	legend->AddEntry(gr, "PU=50 wGEM (P_{T}^{#mu, barrel}>20, |#eta|<2.1)","p");
	legend->AddEntry(gr12, "PU=50 wGEM 2012 WP  (P_{T}^{#mu Full Accept}>24,|#eta|<2.1)","p");
	Canv5->cd();
	legend->Draw("same");
	Canv5->SaveAs("WHPtTresh.pdf");
	
	///////////////////////////////////////////************************************////////////////////////////////////////////
	
	TCanvas *Canv6 = new TCanvas("Canv6","StraPalle",800,700);
	gr_full->SetMarkerStyle(24);  
	gr_full->SetMarkerColor(kBlue);
	
	gr_BB->SetMarkerStyle(24);  
	gr_EE->SetMarkerStyle(24);  
	
	gr_BB->SetMarkerColor(kGreen);  
	gr_EE->SetMarkerColor(kMagenta);  
	
	gr_full->SetTitle(" Selection Efficiency as a function of muon pt threshold ");
	gr_full->GetYaxis()->SetTitle("Selection Efficiency");
	gr_full->GetYaxis()->SetTitleOffset(1.4);
	gr_full->GetXaxis()->SetTitle("P_{T}^{#mu Endcap} Cut (GeV/c)");
	gr_full->Draw("ACP");
	gr_BB->Draw("CP");
	gr_EE->Draw("CP");
	//gr12->Draw("CP");
	//gr_full->SetMinimum(0.1);
	gPad->SetGrid();
	gPad->Update();
	
	TLegend* legend = new TLegend( 0.65, 0.7, 0.85, 0.9);
	legend->SetTextSize(0.025);
	legend->SetFillColor(0);
	legend->AddEntry(gr_full, "full acceptance","p");
	legend->AddEntry(gr_BB, "|#eta|<1.6","p");
	legend->AddEntry(gr_EE, "1.6<|#eta|<2.1","p");
	Canv6->cd();
	legend->Draw("same");
	Canv6->SaveAs("threshold_fullAcc.pdf");
	
	
}


