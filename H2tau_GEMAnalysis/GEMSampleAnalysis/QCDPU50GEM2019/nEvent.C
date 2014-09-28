using namespace std;
#include <iomanip>
#include <iostream> 
void nEvent(void){

std::cout << setiosflags(ios::fixed) << setprecision(3) << std::endl;
//cout.setf(ios :: right, ios :: adjustfield),
//std::cout<<setf(ios::right, ios::adjustfield )<<std::endl;


 TFile *f3 = new TFile("./histo_file_WH125.root"); 
  Double_t xsect=;
  //  std::cout<<"scale factor;"<<(xsect*4562)/(nMET_PU->Integral(0,32))<<std::endl;


  //  std::cout<<"before filter;"<<taglio_0->Integral(0,3)<<std::endl;
  std::cout<<" WH filter;"<<nMET->Integral(0,32)<<std::endl;
  std::cout<<" Trigger;"<<sizeAfterTrigger->Integral(0,32)<<std::endl;
  std::cout<<"vertex cut;"<<entries_after_vertex_PU->Integral(0,3)<<std::endl;
  std::cout<<" Muon Pt;"<<sizeMuonPt->Integral(0,32)<<std::endl;
  
  std::cout<<" Muon Eta;"<<sizeMuonAccept->Integral(0,3)<<std::endl;
  std::cout<<" Muon Tracker && Global;"<< sizeMuonTrackGlob->Integral(0,32)<<std::endl;
  std::cout<<" Muon chambers=>2;"<<sizeMuonChambers->Integral(0,32)<<std::endl;
  std::cout<<" Muon Match =>2;"<<sizeMuonMatchStat->Integral(0,32)<<std::endl;
  
  std::cout<<" muon Tracker Hits;"<< sizeMuonTrackHits->Integral(0,32)<<std::endl;
  std::cout<<" muon Pixel Hits;"<< sizeMuonPixHits->Integral(0,32)<<std::endl;

  std::cout<<" muon Chi2;"<< sizeMuonChi2->Integral(0,32)<<std::endl;
  std::cout<<" muon dB;"<< sizeMuondB->Integral(0,32)<<std::endl;
  std::cout<<" muon Dist Z;"<< sizeMuonDistZ->Integral(0,32)<<std::endl;
  std::cout<<" muon PFRel Iso;"<<sizeMuonISO->Integral(0,3)<<std::endl;    
  
  //std::cout<<" muon ID;"<<sizeMuonID->Integral(0,3)<<std::endl;
  //std::cout<<"Muon id;"<<tagli_7->Integral(0,3)<<std::endl;
  std::cout<<" DR(Mu,tau1);"<<sizeTau1DR->Integral(0,31)<<std::endl;
  std::cout<<" Tau1 pt;"<<sizeTauPt1->Integral(0,31)<<std::endl;
  std::cout<<" tau1 Eta;"<<sizeTauAccept1->Integral(0,11)<<std::endl;
    std::cout<<" tau1 ID;"<<sizeTauID1->Integral(0,11)<<std::endl;
    std::cout<<" tau1 LC Isolation DB;"<<sizeTauISO1->Integral(0,11)<<std::endl;
    std::cout<<" Muon Tight;"<<sizeTau1AgMu->Integral(0,31)<<std::endl;
    std::cout<<" Electron Loose;"<<sizeTauAgainstLepton1->Integral(0,11)<<std::endl;
    // std::cout<<" tau1 Delta Z;"<<sizeTauDeltaZ1->Integral(0,11)<<std::endl; 
  
    std::cout<<" DR(Mu,tau2);"<<sizeTau2DRMu->Integral(0,31)<<std::endl;
 
    std::cout<<" tau2 Pt;"<<sizeTauPt2->Integral(0,11)<<std::endl;
    std::cout<<" tau2 Eta;"<<sizeTauAccept2->Integral(0,11)<<std::endl;
    std::cout<<" tau2 ID;"<<sizeTauID2->Integral(0,11)<<std::endl;
    std::cout<<" tau2 CM Isoltion DB;"<<sizeTauISO2->Integral(0,11)<<std::endl;
    std::cout<<" Muon Tight ;"<<sizeTau2AgMu->Integral(0,10)<<std::endl;
    std::cout<<" Electron Medium ;"<<sizeTauAgainstLepton2->Integral(0,11)<<std::endl;
    // std::cout<<" tau2 Delta Z;"<<sizeTauDeltaZ2->Integral(0,11)<<std::endl;

    std::cout<<" Extra Muons Veto;"<<NoExtraMuon->Integral(0,10)<<std::endl;
    std::cout<<" Electrons Veto;"<<sizeZeroEle->Integral(0,10)<<std::endl;
    std::cout<<" BJet Veto;"<<sizeJetsMatch->Integral(0,10)<<std::endl;

 
    std::cout<<" DR(tau1,tau2);"<<sizeTau2DRTau1->Integral(0,31)<<std::endl;
    std::cout<<" Dist ZVertex (Tau1,Tau2);"<< sizeTauZDist->Integral(0,10)<<std::endl;
    std::cout<<" Dist ZVertex (Tau1,Mu);"<< sizeMuTau1Z->Integral(0,10)<<std::endl;
    std::cout<<" Zeta(Mu,Tau_h) Veto;"<<ZCut->Integral(0,10)<<std::endl;
    //std::cout<<"TAU SUBLEAD pt MAX;"<<tagli_5->Integral(0,3)<<std::endl;
    std::cout<<" charge cut;"<<tagli_6->Integral(0,3)<<std::endl;
  
 



//f3->Close();
}
