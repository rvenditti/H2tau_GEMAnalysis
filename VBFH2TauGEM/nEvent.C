using namespace std;
#include <iomanip>
#include <iostream> 
void nEvent(void){

std::cout << setiosflags(ios::fixed) << setprecision(3) << std::endl;
//cout.setf(ios :: right, ios :: adjustfield),
//std::cout<<setf(ios::right, ios::adjustfield )<<std::endl;


// TFile *f3 = new TFile("/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/H2tau_VBF/VBFH2Tau_PU50GEM2019/histo_file_VBFH2Tau_PU50GEM2019XX.root"); 
 TFile *f3 = new TFile("/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/H2tau_VBF/VBFH2Tau_PU50woGEM_2015/histo_file_VBFH2Tau_PU50woGEM_2015XX.root");
  Double_t xsect=;
  //  std::cout<<"scale factor;"<<(xsect*4562)/(nMET_PU->Integral(0,32))<<std::endl;

  std::cout<<"2jets;"<<initial_entries->Integral(0,3)<<std::endl;
  std::cout<<"2jets;"<<hOneJet->Integral(0,3)<<std::endl;
  std::cout<<"VBF cat;"<<hVBFTag->Integral(0,3)<<std::endl;
  std::cout<<"vertex cut;"<<entries_after_vertex->Integral(0,3)<<std::endl;
  std::cout<<" Muon Pt;"<<sizeMuonPt->Integral(0,32)<<std::endl;
  std::cout<<" Muon Eta;"<<sizeMuonAccept->Integral(0,3)<<std::endl;
  std::cout<<" Muon Tracker && Global;"<< sizeMuonTrackGlob->Integral(0,32)<<std::endl;
  std::cout<<" Muon chambers=>2;"<<sizeMuonChambers->Integral(0,32)<<std::endl;
  std::cout<<" Muon Match =>2;"<<sizeMuonMatchStat->Integral(0,32)<<std::endl;
  
  std::cout<<" muon Tracker Hits;"<< sizeMuonTrackHits->Integral(0,32)<<std::endl;
  std::cout<<" muon Pixel Hits;"<< sizeMuonPixHits->Integral(0,32)<<std::endl;

  std::cout<<" muon Chi2;"<< sizeMuonChi2->Integral(0,32)<<std::endl;
  std::cout<<" muon dB;"<< sizeMuondB->Integral(0,32)<<std::endl;
  std::cout<<" muon dZ;"<< sizeMuonDistZ->Integral(0,32)<<std::endl;
  std::cout<<" muon Iso;"<<sizeMuonISO->Integral(0,3)<<std::endl;    
  
  //std::cout<<" muon ID;"<<sizeMuonID->Integral(0,3)<<std::endl;
  //std::cout<<"Muon id;"<<tagli_7->Integral(0,3)<<std::endl;
  std::cout<<" DR(Mu,tau1);"<<sizeTau1DR->Integral(0,31)<<std::endl;
  std::cout<<" Tau1 pt;"<<sizeTauPt1->Integral(0,31)<<std::endl;
  std::cout<<" tau1 Eta;"<<sizeTauAccept1->Integral(0,11)<<std::endl;
    std::cout<<" tau1 ID;"<<sizeTauID1->Integral(0,11)<<std::endl;
    std::cout<<" tau1 Isolation ;"<<sizeTauISO1->Integral(0,11)<<std::endl;
    std::cout<<" Muon Tight;"<<sizeTau1AgMu->Integral(0,31)<<std::endl;
    std::cout<<" Electron Loose;"<<sizeTauAgainstLepton1->Integral(0,11)<<std::endl;
    // std::cout<<" tau1 Delta Z;"<<sizeTauDeltaZ1->Integral(0,11)<<std::endl; 
  
    std::cout<<" charge cut;"<<tagli_3->Integral(0,3)<<std::endl;
    std::cout<<" Mt(mu,MET)<30;"<<sizeMtmumet->Integral(0,3)<<std::endl;
    std::cout<<" Zmm veto;"<<hZmumuVeto->Integral(0,3)<<std::endl;
    std::cout<<" Extra Muons Veto;"<<NoExtraMuon->Integral(0,10)<<std::endl;
    std::cout<<" Electrons Veto;"<<sizeZeroEle->Integral(0,10)<<std::endl;
    std::cout<<" BJet Veto;"<<sizeJetsMatch->Integral(0,10)<<std::endl;


  
 



//f3->Close();
}
