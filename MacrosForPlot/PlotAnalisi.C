#include <TH1>
#include <string>
#include <vector>
#include <TString.h>

void PlotAnalisi(){
	
  gROOT->ProcessLine(".L ./tdrstyle.C");
  setTDRStyle();
  //gStyle->SetOptStat(00000001111);	
	gStyle->SetOptStat("nemr");
	
//   TFile *f = TFile::Open("histo_file_WH1250.root");  
	TFile *f = TFile::Open("histo_file_VBFH2Tau_PU50GEM2019XX.root");
	TFile *f1 = TFile::Open("histo_file_VBFH2Tau_PU50woGEM_2015XX.root");  
	std::vector<TString> histoName;
	
	

	histoName.push_back("hMuonPtReco");
	histoName.push_back("hMuonEtaReco");
	histoName.push_back("massainv_TauTau_taglio7");
	
	
	histoName.push_back("hRecoMuonPt");
	histoName.push_back("hRecoMuonEta"); 
	histoName.push_back("hRecoMuonPhi");
	histoName.push_back("hRecoMuonChi2");
	histoName.push_back("hMuonTrkLayer");
	histoName.push_back("hMuonDB"); 
	histoName.push_back("hMuonDZ"); 
	histoName.push_back("hNMuonBefSel");
	histoName.push_back("hNMuonAfterSel");
	
	histoName.push_back("hMuonEtaFinal_HE"); 
	histoName.push_back("hMuonPtFinal_HE"); 
	histoName.push_back("hMuonEtaFinal_Barrel");
	histoName.push_back("hMuonPtFinal_Barrel"); 
	histoName.push_back("hMuonEtaFinal_Full");  
	histoName.push_back("hMuonPtFinal_Full");  
	
	histoName.push_back("hPtHE");  
	histoName.push_back("hPtBarrel");  
	
	
	histoName.push_back("hDB_Barrel");  
	histoName.push_back("hDBSig_Barrel");
	histoName.push_back("hChiSq_Barrel");
	histoName.push_back("hDB_HE");
	histoName.push_back("hDBSig_HE");
	histoName.push_back("hChiSq_HE");
	histoName.push_back("hPtRes_HE");
	histoName.push_back("hDBerr_HE");
	histoName.push_back("hPtRes_Barrel");
	histoName.push_back("hDBerr_Barrel");
	
	
	std::string strPt ("Pt");
	std::string strEta ("Eta");
	cout<<"Size histoName="<<histoName.size()<<endl;

	int numHisto = histoName.size();
	TH1F *histo; 
	histo = (TH1F) malloc(numHisto * sizeof(TH1F));
	
	TH1F *histo_woGEM; 
	histo_woGEM = (TH1F) malloc(numHisto * sizeof(TH1F));
	
	//TCanvas* CanvVector; 
	//CanvVector= (TCanvas) malloc(numHisto * sizeof(CanvVector));
	TCanvas* CanvVector[30];
	
	for(int i=0;i<numHisto; i++){
		
	histo[i] = (TH1F*)f->Get(histoName[i]);
	histo_woGEM[i] = 	(TH1F*)f1->Get(histoName[i]);
		
	cout<<i<<" bin size num "<<histo[i].GetNbinsX()<<endl;
	
		histo[i]->Scale(1/histo[i].Integral());
		histo_woGEM[i]->Scale(1/histo_woGEM[i].Integral());
	
	if(histoName[i].Contains(strPt)) {histo[i].GetXaxis()->SetTitle("P_{T} [GeV/c]");  histo[i].Rebin(4); histo_woGEM[i].Rebin(4); }
	if(histoName[i].Contains(strEta)) histo[i].GetXaxis()->SetTitle("#eta");
	if(histoName[i].Contains("MET")){ histo[i].GetXaxis()->SetTitle("MET [GeV]"); histo[i].Rebin(4); histo_woGEM[i].Rebin(4);}
	if(histoName[i].Contains("massa")){ histo[i].GetXaxis()->SetTitle("m^{vis}_{#tau #tau} [GeV/c^{2}]"); histo[i].Rebin(10); histo_woGEM[i].Rebin(10);}
	if(histoName[i].Contains("hPtRes")){ histo[i].GetXaxis()->SetTitle("(P_{T}^{gen}-P_{T}^{reco})/P_{T}^{gen}"); }
	if(histoName[i].Contains("hDB_")){ histo[i].GetXaxis()->SetTitle("dxy [cm]"); histo[i].Rebin(10); histo_woGEM[i].Rebin(10); }
	if(histoName[i].Contains("hDBerr")){ histo[i].GetXaxis()->SetTitle("#sigma(dxy) [cm]");  histo[i].Rebin(10);   histo_woGEM[i].Rebin(10); }
		
	if(histoName[i].Contains("hPtRes")){ 
	
	int bin_min = -0.05;
	int bin_max = 0.05;	
		
	histo[i].Fit("gaus","N0","E",bin_min,bin_max);   
	histo_woGEM[i].Fit("gaus","N0","E",bin_min,bin_max);
		
	/*	
	TF1  *fun2 = new TF1("fun2"," [0]*exp(-0.5*((x-[1])/[2])^2)",bin_min,bin_max) ; 
	TF1  *fun1 = new TF1("fun1"," [0]*exp(-0.5*((x-[1])/[2])^2)",bin_min,bin_max) ; 
	histo[i].Fit("fun1","RN0","E",bin_min,bin_max);   
    histo_woGEM[i].Fit("fun2","RN0","E",bin_min,bin_max);

		fun1->SetParameter(0,fun1->GetParameter(0));
		fun1->SetParameter(1,fun1->GetParameter(1));
		fun1->SetParameter(2,fun1->GetParameter(2));
		fun1->SetLineColor(kBlue);   
		fun1->Draw();		
		

	fun2->SetParameter(0,fun2->GetParameter(0));
	fun2->SetParameter(1,fun2->GetParameter(1));
	fun2->SetParameter(2,fun2->GetParameter(2));
	fun2->SetLineColor(kRed);   
	fun2->Draw();	
	 */
	}	
		
		
		
	histo[i].SetLineColor(kBlue);	
	histo[i].SetLineWidth(2);	
		
	histo_woGEM[i].SetLineColor(kRed);	
	histo_woGEM[i].SetLineWidth(2);	
	
	histo[i].SetTitle("UpgradeGEM2019-PU50bx25");
	histo_woGEM[i].SetTitle("Fall13dr-PU40bx25 (w/oGEMs)");
		
			
		TString titleCanv ("CanvVector"); titleCanv+=(i+1);     
		CanvVector[i] = new TCanvas("titleCanv", "titleCanv", 500, 500);
		
		CanvVector[i]->cd();
		histo[i].Draw("histe");
		//if(histoName[i].Contains("hPtRes")) fun1->Draw("same");	 
		
		gPad->Update();
		TPaveStats* st20 = (TPaveStats*) histo[i].FindObject("stats");
		histo[i].SetTitle("UpgradeGEM2019-PU50bx25");
        st20->SetX1NDC(0.7);
        st20->SetX2NDC(0.9);
        st20->SetY1NDC(0.7);
        st20->SetY2NDC(0.9);
        st20->SetTextColor(kBlue);
        st20->Draw();
        gPad->Update();
		
		histo_woGEM[i].Draw("HISTESAMES");
		//if(histoName[i].Contains("hPtRes")) fun2->Draw("same");
        gPad->Update();
        TPaveStats* st21 = (TPaveStats*) histo_woGEM[i].FindObject("stats");
		histo_woGEM[i].SetTitle("Fall13dr-PU40bx25");
        st21->SetX1NDC(0.7);
        st21->SetX2NDC(0.9);
        st21->SetY1NDC(0.5);
        st21->SetY2NDC(0.7);
        st21->SetTextColor(kRed);
        st21->Draw();
        gPad->Update();
		
		
		
//	CanvVector[i]->cd();
//	histo[i]->Draw("histe");
//	histo_woGEM[i]->Draw("histesame");
	CanvVector[i]->SaveAs("./Plot/"+histoName[i]+".pdf");
		
	}
	
}
