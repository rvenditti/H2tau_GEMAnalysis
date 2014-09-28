#include <TH1>
#include <vector>
void PlotSelection(){

	gROOT->ProcessLine(".L ./tdrstyle.C");
	setTDRStyle();
	gStyle->SetOptStat(0000000);  
	TFile *f3 = TFile::Open("histo_file_WH_PU50GEM2019_2012WP.root"); 
	TFile *f4 = TFile::Open("histo_file_WH_PU50GEM2019_2019WP.root"); 
	TFile *f5 = TFile::Open("histo_file_ZMMPU50GEM2019.root");

	std::vector<TString> histoName;
	histoName.push_back("nMET");  histoName.push_back("entries_after_vertex_PU"); histoName.push_back("sizeMuonAccept"); histoName.push_back("sizeMuonPt"); histoName.push_back("sizeMuonTrackGlob"); 
	 histoName.push_back("sizeMuonChambers"); histoName.push_back("sizeMuonMatchStat");  histoName.push_back("sizeMuonTrackHits");
	histoName.push_back("sizeMuonPixHits");
	histoName.push_back("sizeMuonChi2");
	histoName.push_back("sizeMuondB");
	histoName.push_back("sizeMuonISO");
	/*histoName.push_back("sizeTau1DR");
	histoName.push_back("sizeTauPt1");
	histoName.push_back("sizeTauAccept1");
	histoName.push_back("sizeTau1AgMu");
	histoName.push_back("sizeTauAgainstLepton1");
	histoName.push_back("tagli_6");
	histoName.push_back("sizeTau2DRTau1"); histoName.push_back("sizeTauOSIso"); histoName.push_back("sizeTauSSIso"); histoName.push_back("MaxPtGreat25"); histoName.push_back("NoExtraMuon"); histoName.push_back("sizeJetsMatch");*/
	
	
	std::vector<TString> histoTitle;
	histoTitle.push_back("Initial");  histoTitle.push_back("Vertex"); histoTitle.push_back("Muon Acceptance"); histoTitle.push_back("Muon Pt"); histoTitle.push_back("isTracker"); 
	 histoTitle.push_back("n Muon Chambers"); histoTitle.push_back("Muon Matched Statation");  histoTitle.push_back("TrackerLayers");
	histoTitle.push_back("Muon Pixel Hits");
	histoTitle.push_back("Muon Chi2");
	histoTitle.push_back("Muon dB");
	histoTitle.push_back("Muon ChIso");
	/*histoTitle.push_back("DR(Mu,Tau)");
	histoTitle.push_back("Tau Pt");
	histoTitle.push_back("Tau Acceptance");
	histoTitle.push_back("Mu-Tau Rejection");
	histoTitle.push_back("Mu-Electron Rejection");
	histoTitle.push_back("DiTau Charge");
	histoTitle.push_back("DR(Tau1,Tau2)"); histoTitle.push_back("TauOS Iso"); histoTitle.push_back("TauSS Iso"); histoTitle.push_back("Pt Tau Lead >25"); histoTitle.push_back("Muon Veto"); histoTitle.push_back("b-jet Veto");*/
	
	int numHisto = histoName.size();
	TH1F *histo; 
	histo = (TH1F) malloc(numHisto * sizeof(TH1F));
	
	TH1F *histoNew; 
	histoNew = (TH1F) malloc(numHisto * sizeof(TH1F));
	
	TH1F *histoZMM; 
	histoNew = (TH1F) malloc(numHisto * sizeof(TH1F));
	
	TH1F *hEntriesWP2012 = new TH1F("hEntriesWP2012", "hEntriesWP2012", numHisto, 0, numHisto);
	TH1F *hEntriesWPNew = new TH1F("hEntriesWPNew", "hEntriesWPNew", numHisto, 0, numHisto);
	TH1F *hEntriesZMM = new TH1F("hEntriesZMM", "hEntriesZMM", numHisto, 0, numHisto);
	cout<<" numHisto "<<numHisto<<endl;
	for(int i=0;i<numHisto; i++){
//	for(int i=0;i<12; i++){
		
        histo[i] = (TH1F*)f3->Get(histoName[i]);
		histoNew[i] = (TH1F*)f4->Get(histoName[i]);
		histoZMM[i] = (TH1F*)f5->Get(histoName[i]);
		
		//cout<<histoName[i]<<"  "<<histo[i].Integral()<<"   "<<histoNew[i].Integral()<<endl;
		hEntriesWP2012->SetBinContent(i,histo[i].Integral());
		hEntriesWP2012->GetXaxis()->SetBinLabel(i,histoTitle[i]);

		hEntriesZMM->SetBinContent(i,histoZMM[i].Integral()); 
		
		hEntriesWPNew->SetBinContent(i,histoNew[i].Integral());


	}
	TCanvas *c= new TCanvas("c","Entries",1400,600);
	c->cd();
	
	hEntriesWP2012->SetLineWidth(2);
	hEntriesWPNew->SetLineWidth(2);

	hEntriesWP2012->SetLineColor(kBlue);
	hEntriesWPNew->SetLineColor(kRed);
	hEntriesZMM->SetLineColor(kGreen);
	
	hEntriesWP2012->GetXaxis()->SetTitle("Selection");
	hEntriesWP2012->GetYaxis()->SetTitle("Yield");
	
	hEntriesWP2012->Draw();
	hEntriesWPNew->Draw("SAME");
	hEntriesZMM->Draw("SAME");
	
	TLegend* legend = new TLegend( 0.4, 0.65, 0.8, 0.9);
	legend->SetTextSize(0.035);
	legend->SetFillColor(0);
	legend->AddEntry(hEntriesWP2012 , "2012 WP: |#eta|<2.1 && pt^{Full Acceptance}>24", "l");
	legend->AddEntry(hEntriesWPNew , "2019 WP:  |#eta|<2.1 && (pt^{Barrel}>24 || pt^{Endcap}>10) ", "l");
	c->cd();
	legend->Draw("same");  
	c->SaveAs("SelectionComparisono.pdf");
}