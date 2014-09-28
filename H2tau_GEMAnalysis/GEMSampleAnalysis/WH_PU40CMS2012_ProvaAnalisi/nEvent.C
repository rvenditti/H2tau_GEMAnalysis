using namespace std;
#include <iomanip>
#include <iostream> 
void nEvent(void){

std::cout << setiosflags(ios::fixed) << setprecision(3) << std::endl;
//cout.setf(ios :: right, ios :: adjustfield),
//std::cout<<setf(ios::right, ios::adjustfield )<<std::endl;



 TFile *f3 = TFile::Open("/lustre/cms/store/user/rvenditti/PostLS2/FullSim/AnalisiGEM/WH_PU50GEM2019_ProvaAnalisi/histo_file_WH_PU50GEM20196.root"); 

std::cout<<" Initial;"<<H_tot->Integral(0,32)<<std::endl;
std::cout<<" WH filter;"<<W_tot->Integral(0,32)<<std::endl;
std::cout<<" W-->mu ;"<<muonW->Integral(0,32)<<std::endl;
std::cout<<" FH ;"<<GTFHEvent->Integral(0,32)<<std::endl;
//std::cout<<" Trigger;"<<sizeAfterTrigger->Integral(0,32)<<std::endl;
std::cout<<"vertex cut;"<<entries_after_vertex_PU->Integral(0,3)<<std::endl;
  
std::cout<<" Muon Eta;"<<sizeMuonAccept->Integral(0,3)<<std::endl;
std::cout<<" Muon Pt;"<<sizeMuonPt->Integral(0,32)<<std::endl;
std::cout<<" Muon Tracker && Global;"<< sizeMuonTrackGlob->Integral(0,32)<<std::endl;
std::cout<<" Muon chambers=>2;"<<sizeMuonChambers->Integral(0,32)<<std::endl;
std::cout<<" Muon Match =>2;"<<sizeMuonMatchStat->Integral(0,32)<<std::endl;
  
std::cout<<" muon Tracker Hits;"<< sizeMuonTrackHits->Integral(0,32)<<std::endl;
std::cout<<" muon Pixel Hits;"<< sizeMuonPixHits->Integral(0,32)<<std::endl;

std::cout<<" muon Chi2;"<< sizeMuonChi2->Integral(0,32)<<std::endl;
std::cout<<" muon dB;"<< sizeMuondB->Integral(0,32)<<std::endl;
std::cout<<" muon Dist Z;"<< sizeMuonDistZ->Integral(0,32)<<std::endl;
std::cout<<" muon PFRel Iso;"<<sizeMuonISO->Integral(0,3)<<std::endl;    
  

std::cout<<" DR(Mu,tau1);"<<sizeTau1DR->Integral(0,31)<<std::endl;
std::cout<<" Tau1 pt;"<<sizeTauPt1->Integral(0,31)<<std::endl;
std::cout<<" tau1 Eta;"<<sizeTauAccept1->Integral(0,11)<<std::endl;
std::cout<<" tau1 ID;"<<sizeTauID1->Integral(0,11)<<std::endl;
std::cout<<" Muon Tight;"<<sizeTau1AgMu->Integral(0,31)<<std::endl;
std::cout<<" Electron Loose;"<<sizeTauAgainstLepton1->Integral(0,11)<<std::endl;
// std::cout<<" tau1 Delta Z;"<<sizeTauDeltaZ1->Integral(0,11)<<std::endl; 
  

std::cout<<" charge cut;"<<tagli_6->Integral(0,3)<<std::endl; 

std::cout<<" DR(tau1,tau2);"<<sizeTau2DRTau1->Integral(0,31)<<std::endl;
std::cout<<"  Tau OS Iso; "<<sizeTauOSIso->Integral(0,10)<<std::endl;
std::cout<<"  Tau SS Iso; "<<sizeTauSSIso->Integral(0,10)<<std::endl;
std::cout<<" PTlead>25;"<<MaxPtGreat25->Integral(0,31)<<std::endl;

        
std::cout<<"MT(mu,met) ;"<<sizeMtmumet->Integral(0,10)<<std::endl;  
        

std::cout<<" Extra Muons Veto;"<<NoExtraMuon->Integral(0,10)<<std::endl;
//std::cout<<" Electrons Veto;"<<sizeZeroEle->Integral(0,10)<<std::endl;
std::cout<<" BJet Veto;"<<sizeJetsMatch->Integral(0,10)<<std::endl;

}
