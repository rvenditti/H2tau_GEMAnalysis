#define VHAnalyzer_cxx
#include "VHAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <TLorentzVector.h>
#include <TMath.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;

TFile* f_puweights;
TH1D* puweights;

static float puweight(float npu) {
    if (npu<0) return 1.0;
    return puweights->GetBinContent(puweights->FindBin(npu));
}


void VHAnalyzer::Loop()
{

   if (fChain == 0) return;
   
    //reweighting pileup
    //f_puweights = TFile::Open("/lustre/cms/store/user/rvenditti/reweightFunctionFall11.root", "read");
    f_puweights = TFile::Open("/lustre/cms/store/user/rvenditti/reweightFunctionFall12.root", "read");
    puweights = (TH1D*)f_puweights->Get("plot_data_div_MC");
    
   Long64_t nentries = fChain->GetEntriesFast();
   
    Int_t loose=0;
    /////////////////CICLO SU TUTTI GLI EVENTI
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
//for (Long64_t jentry=0; jentry<2000; jentry++) { //for sui primi 100 eventi

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
       Int_t event_type = 0;
       Int_t muon_type = 0;
       Int_t tau_type = 0;
       Int_t rigaMotherW=-2;
       Int_t rigaMotherH=-2;
       bool WplusGOODmuon=false;
//       tagli[0]->Fill(1);
       
       /////////////////////////////////////////////////////////////
       /*for (unsigned int i = 0; i < trueNInt->size(); ++i) {
        if ((*bunchCrossing)[i] == 0) {
        //cout << " nPU = " << (*nPU)[i] << " bunchCrossing = " << (*bunchCrossing)[i] << endl;
        hNPU->Fill((*trueNInt)[i]);
        }
        }
        */
       //pileup
       /*double NPU = (*nPU)[0];
        cout << " nPU_0 = " << NPU << endl;*/
       double NPU_1 = (*trueNInt)[0];  //corrisponde al BX=0
       //cout << " nPU_1 = " << NPU_1 << endl;
       //	float puWeight = puweight(NPU_1);
       float puWeight =1;
       
       TLorentzVector HGen;HGen.SetPtEtaPhiM(1,0,0,0);
        for(Int_t r=0; r<nGenParticle; r++){
           if(GenParticle_pdgId[r] == 25 && GenParticle_status[r] == 3 ){
               H_tot->Fill(1);
               rigaMotherH=r;
	       HGen.SetPtEtaPhiM(GenParticle_pt[r], GenParticle_eta[r], GenParticle_phi[r], GenParticle_energy[r]    );
	       //  std::cout<<jentry<<" gen H vx  "<<GenParticle_vx[r]<<" gen H vy  "<<GenParticle_vy[r]<<" gen H vz  "<<GenParticle_vz[r]<<endl;
	   }  // fine if GenParticle = H
           if(TMath::Abs(GenParticle_pdgId[r]) == 13 && GenParticle_status[r] == 1){
               muon_type=1;}
           if(TMath::Abs(GenParticle_pdgId[r]) == 15 && GenParticle_status[r] == 3 && GenParticle_motherIndex[r] == rigaMotherH){
               if(TMath::Abs(GenParticle_pdgId[r+1]) == 15 && GenParticle_status[r+1] == 3 && GenParticle_motherIndex[r+1] == rigaMotherH){
                   tau_type=1;}}
       }  // fine for GenParticle
       
	//if(Vertex_isvalid[0]){
	//std::cout<<jentry<<" PV vx  "<<Vertex_x[0]<<" PV  vy  "<<Vertex_y[0]<<" PV vz  "<<Vertex_z[0]<<endl;}
       TLorentzVector muGen;
       muGen.SetPtEtaPhiM(1,0,0,0);
       ////////////////////////////////VEDO IL CANALE DI DECADIMANTO DEI TAU DA H
       bool Tau1jet=false;
       bool Tau2jet=false;
       bool Tau1electron=false;
       bool Tau2electron=false;
       bool Tau1muon=false;
       bool Tau2muon=false;
       bool FHevent=false;
       bool elejet=false;
       bool mujet=false;
       bool FLevent=false;
       bool GTFHevent=false;
       bool GTelejet=false;
       bool GTmujet=false;
       bool GTFLevent=false;
       TLorentzVector tau1Gen;
       TLorentzVector tau2Gen;
       tau1Gen.SetPtEtaPhiM(1,0,0,0);
       tau2Gen.SetPtEtaPhiM(1,0,0,0);
       TLorentzVector MHGen = tau1Gen + tau2Gen;

       Int_t rigaMu_tau=-2;
       TLorentzVector muGen_tau1,muGen_tau2, tauGen_had, muRecoMatch, tauRecoMatch, tau_tmp;
       muGen_tau1.SetPtEtaPhiM(1,0,0,0); muGen_tau2.SetPtEtaPhiM(1,0,0,0); tauGen_had.SetPtEtaPhiM(1,0,0,0); muRecoMatch.SetPtEtaPhiM(1,0,0,0);   tauRecoMatch.SetPtEtaPhiM(1,0,0,0); tau_tmp.SetPtEtaPhiM(1,0,0,0);  
       std::vector<int>       mutauIndex, tauMatchIndex, muMatchIndex;
       double genmu_vx=0;
       double genmu_vy=0;
       double genmu_vz=0;
       if(tau_type==1){
           Int_t rigaTau1=-2, tau1_rigaprova=-2, tau1_rigaCorretta=-2;
           Int_t rigaTau2=-2, tau2_rigaprova=-2, tau2_rigaCorretta=-2;
           
           for(Int_t r=0; r<nGenParticle; r++){
               
               if(TMath::Abs(GenParticle_pdgId[r]) == 15 && GenParticle_status[r] == 3 && GenParticle_motherIndex[r] == rigaMotherH){
                   if(TMath::Abs(GenParticle_pdgId[r+1]) == 15 && GenParticle_status[r+1] == 3 && GenParticle_motherIndex[r+1] == rigaMotherH){
                       controlloTauTau->Fill(1);
                       rigaTau1=r;
                       rigaTau2=r+1;}}
               
	       if(TMath::Abs(GenParticle_pdgId[r]) == 15  &&  GenParticle_status[r] == 2 &&  GenParticle_motherIndex[r] == rigaTau1){ rigaTau1=r;}
	       if(TMath::Abs(GenParticle_pdgId[r]) == 15  && GenParticle_status[r] == 2 && GenParticle_motherIndex[r] == rigaTau2){rigaTau2=r;}

                   
	       tau1_rigaCorretta=rigaTau1;tau2_rigaCorretta=rigaTau2;
                 
                   tau1Gen.SetPtEtaPhiE(GenParticle_pt[tau1_rigaCorretta], GenParticle_eta[tau1_rigaCorretta], GenParticle_phi[tau1_rigaCorretta], GenParticle_energy[tau1_rigaCorretta]);
                   tau2Gen.SetPtEtaPhiE(GenParticle_pt[tau2_rigaCorretta], GenParticle_eta[tau2_rigaCorretta], GenParticle_phi[tau2_rigaCorretta], GenParticle_energy[tau2_rigaCorretta]);
                   // chargeTauTau = Tau_charge[tau1_index]+Tau_charge[tau2_index];
                   MHGen = tau1Gen + tau2Gen;
                   // std::cout<<" evento "<<jentry<<" tau1 gen pt "<<tau1Gen.Pt()<<" tau1 gen eta  "<<tau1Gen.Eta()<<" tau1 gen phi  "<<tau1Gen.Phi()<<" tau1 gen en  "<<tau1Gen.E()<<std::endl;
                   //std::cout<<" evento "<<jentry<<" tau2 gen pt "<<tau2Gen.Pt()<<" tau2 gen eta  "<<tau2Gen.Eta()<<" tau2 gen phi  "<<tau2Gen.Phi()<<" tau2 gen en  "<<tau2Gen.E()<<std::endl;
              
               
               if (TMath::Abs(GenParticle_pdgId[r]) >22 && GenParticle_motherIndex[r] == rigaTau1){Tau1jet=true;}
               if (TMath::Abs(GenParticle_pdgId[r]) == 11 && GenParticle_motherIndex[r] == rigaTau1){Tau1electron=true;}
               if (TMath::Abs(GenParticle_pdgId[r]) ==13 && GenParticle_motherIndex[r] == rigaTau1){Tau1muon=true;
		 rigaMu_tau=r;
                 muGen_tau1.SetPtEtaPhiE(GenParticle_pt[r], GenParticle_eta[r], GenParticle_phi[r], GenParticle_energy[r]);
		 mutauIndex.push_back(rigaMu_tau);
		 tauGen_had.SetPtEtaPhiE(GenParticle_pt[rigaTau1], GenParticle_eta[rigaTau1], GenParticle_phi[rigaTau1], GenParticle_energy[rigaTau1]);
		 // std::cout<<jentry<<" gen mu vx  "<<GenParticle_vx[r]<<" gen mu vy  "<<GenParticle_vy[r]<<" gen mu vz  "<<GenParticle_vz[r]<<endl;
		  genmu_vx=GenParticle_vx[r];
		  genmu_vy=GenParticle_vy[r];
		  genmu_vz=GenParticle_vz[r];
                 //if(muGen_tau.Eta()>1.6 && muGen_tau.Eta()<2.4){
		   //                   mutauIndex_roi.push_back(rigaMu_tau);
                 //}

												   }
               if (TMath::Abs(GenParticle_pdgId[r]) >22 && GenParticle_motherIndex[r] == rigaTau2){Tau2jet=true;}
               if (TMath::Abs(GenParticle_pdgId[r]) == 11 && GenParticle_motherIndex[r] == rigaTau2){Tau2electron=true;}
               if (TMath::Abs(GenParticle_pdgId[r]) ==13 && GenParticle_motherIndex[r] == rigaTau2){
		 Tau2muon=true;
		 rigaMu_tau=r; mutauIndex.push_back(rigaMu_tau);  
		  genmu_vx=GenParticle_vx[r];
		  genmu_vy=GenParticle_vy[r];
		  genmu_vz=GenParticle_vz[r];     
		 //std::cout<<jentry<<" gen mu vx  "<<GenParticle_vx[r]<<" gen mu vy  "<<GenParticle_vy[r]<<" gen mu vz  "<<GenParticle_vz[r]<<endl; 
                 muGen_tau2.SetPtEtaPhiE(GenParticle_pt[r], GenParticle_eta[r], GenParticle_phi[r], GenParticle_energy[r]);
		 tauGen_had.SetPtEtaPhiE(GenParticle_pt[rigaTau2], GenParticle_eta[rigaTau2], GenParticle_phi[rigaTau2], GenParticle_energy[rigaTau2]);
		 //if(muGen_tau.Eta()>1.6 && muGen_tau.Eta()<2.4){
		   //		   mutauIndex_roi.push_back(rigaMu_tau); 
		 //}
		 
	       }
           }//end for gen part
       }// end if tau tau da H in evento
       
       //////////////////////////////////GUARDO IN FACCIA I CANALI DI DEC DEI TAU TAU E CONTO
       if(Tau1jet && Tau2jet){
           FHevent=true;
           FHEvent->Fill(1);
       }
       if((Tau1jet || Tau2jet) && (Tau1electron || Tau2electron)){
           elejet=true;
           elejetEvent->Fill(1);
       }
       if((Tau1jet || Tau2jet) && (Tau1muon || Tau2muon)){
           mujet=true;
           mujetEvent->Fill(1);
       }
       if((Tau1electron || Tau1muon) && (Tau2electron || Tau2muon)){
           FLevent=true;
           FLEvent->Fill(1);
       }
      
       ///////////////////////////////////////////Seleziono H-->mu+taujet/////////////////////////////////
       
       if(mujet==false)continue;
       
      
       // TLorentzVector tau_tmp, tauRecoMatch;tau_tmp.SetPtEtaPhiE(1,0,0,0);
       for (Int_t i=0 ; i<nTau ; i++){
	 tau_tmp.SetPtEtaPhiE(Tau_pt[i], Tau_eta[i], Tau_phi[i], Tau_energy[i]);
	 if(tauGen_had.DeltaR(tau_tmp)<0.03){
	   tauRecoMatch.SetPtEtaPhiE(Tau_pt[0], Tau_eta[0], Tau_phi[0], Tau_energy[0]);
	 }
       }

       TLorentzVector HCand;
       TLorentzVector mu_tmp;mu_tmp.SetPtEtaPhiE(1,0,0,0);
       for (Int_t i=0 ; i<nMuon ; i++){
         mu_tmp.SetPtEtaPhiE(Muon_pt[i], Muon_eta[i], Muon_phi[i], Muon_energy[i]);
	 //std::cout<<" evento "<<jentry<<" muon reco pt "<<mu_tmp.Pt()<<" muon gen eta  "<<mu_tmp.Eta()<<" muon gen phi  "<<mu_tmp.Phi()<<" muon gen en  "<<mu_tmp.E()<<std::endl;                                                      
         if(muGen_tau2.DeltaR(mu_tmp)<0.1 || muGen_tau1.DeltaR(mu_tmp)<0.1   ){
	   muRecoMatch.SetPtEtaPhiE(Muon_pt[i], Muon_eta[i], Muon_phi[i], Muon_energy[i]);
	   // hGenMuonPt->Fill(muGen_tau.Pt());         
	   //hGenMuonEta->Fill(muGen_tau.Eta());

	   hRecoMuonMatchPt->Fill(Muon_pt[i]);
	   hRecoMuonMatchEta->Fill(Muon_eta[i]);
	   HCand=muRecoMatch+tauRecoMatch;

	   hHCandMass->Fill(HCand.M());
	   hHCandPt->Fill(HCand.Pt());
	   hHCandEta->Fill(HCand.Eta());

	   hHGenMass->Fill(HGen.M());
	   hHGenPt->Fill(HGen.Pt());
	   hHGenEta->Fill(HGen.Eta());
	   
	   //	   std::cout<<jentry<<" muon index  "<<i<<std::endl;
	   double dB_err = Muon_dB[i]/Muon_edB[i];
	   double dB = Muon_dB[i];

	   // std::cout<<jentry<<" reco mu vx  "<<Muon_vx[i]<<" reco mu vy  "<<Muon_vy[i]<<" reco mu vz  "<<Muon_vz[i]<<endl;
	   //std::cout<<jentry<<"*********  db  "<<Muon_dB[i]<<" d0 track "<<Muon_trkD0[i]<<endl;
	   //std::cout<<jentry<<"*********  db  "<<Muon_dB[i]<<" d0 track "<<Muon_trkD0[i]<<endl;
	   ///Muon Impact Parameter in Barrel
	   if(TMath::Abs(Muon_eta[i]) < 1.5) {
	     hMuoPullX_Barrel->Fill(Muon_vx[i]-genmu_vx);
	     hMuoPullY_Barrel->Fill(Muon_vy[i]-genmu_vy);
	     hMuoPullZ_Barrel->Fill(Muon_vz[i]-genmu_vz);
	     hDB_Barrel->Fill(dB);  
	     hDBSig_Barrel->Fill(dB_err); 
	     hDZ_Barrel->Fill(Muon_trkDz[i]);
	     hChiSq_Barrel->Fill(Muon_globalChi2[i]);  
	     hDBerr_Barrel->Fill(Muon_edB[i]);
	     //  hPtRes_Barrel->Fill(muGen_tau.Pt()-muRecoMatch.Pt());
	   }

	   ///Muon Impact Parameter in High Eta
	   if(  ( (Muon_eta[i] >=  1.5) && (Muon_eta[i] <  2.2)) ||   (Muon_eta[i] <=  (-1.5)) && (Muon_eta[i] >  -(2.2))   ) {
	     hDB_HE->Fill(dB);  
	     hDBSig_HE->Fill(dB_err);
	     hDZ_HE->Fill(Muon_trkDz[i]);
	     hChiSq_HE->Fill(Muon_globalChi2[i]);
	     hMuoPullX_HE->Fill(Muon_vx[i]-genmu_vx);
	     hMuoPullY_HE->Fill(Muon_vy[i]-genmu_vy);
	     hMuoPullZ_HE->Fill(Muon_vz[i]-genmu_vz);
	     //   hPtRes_HE->Fill(muGen_tau.Pt()-muRecoMatch.Pt());
	     hDBerr_HE->Fill(Muon_edB[i]);
	   }

	   //	   if(Muon_pfRelIso[i]<0.25){
	     
	     hPtMuon->Fill(mu_tmp.Pt());
	     hEtaMuon->Fill(mu_tmp.Eta());
	     hAbsEtaMuon->Fill(TMath::Abs(mu_tmp.Eta()));
	     MuonEta_vs_Pt->Fill(TMath::Abs(mu_tmp.Eta()),mu_tmp.Pt());
	     
	     if(mu_tmp.Pt()>10){
	       hPtMuon_10->Fill(mu_tmp.Pt());
	       hEtaMuon_10->Fill(mu_tmp.Eta());
	       hAbsEtaMuon_10->Fill(TMath::Abs(mu_tmp.Eta()));
	       MuonEta_vs_Pt_10->Fill(TMath::Abs(mu_tmp.Eta()),mu_tmp.Pt());
	     }
	     
	     
	     if(mu_tmp.Pt()>15){
	       hPtMuon_15->Fill(mu_tmp.Pt());
	       hEtaMuon_15->Fill(mu_tmp.Eta());
	       hAbsEtaMuon_15->Fill(TMath::Abs(mu_tmp.Eta()));
	       MuonEta_vs_Pt_15->Fill(TMath::Abs(mu_tmp.Eta()),mu_tmp.Pt());
	     }
	     
	     if(mu_tmp.Pt()>20){
	       hPtMuon_20->Fill(mu_tmp.Pt());
	       hEtaMuon_20->Fill(mu_tmp.Eta());
	       hAbsEtaMuon_20->Fill(TMath::Abs(mu_tmp.Eta()));
	       MuonEta_vs_Pt_20->Fill(TMath::Abs(mu_tmp.Eta()),mu_tmp.Pt());
	     }
	     if(mu_tmp.Pt()>25){
	       hPtMuon_25->Fill(mu_tmp.Pt());
	       hEtaMuon_25->Fill(mu_tmp.Eta());
	       hAbsEtaMuon_25->Fill(TMath::Abs(mu_tmp.Eta()));
	       MuonEta_vs_Pt_25->Fill(TMath::Abs(mu_tmp.Eta()),mu_tmp.Pt());
	     }

	     if(mu_tmp.Pt()>30){
               hPtMuon_30->Fill(mu_tmp.Pt());
               hEtaMuon_30->Fill(mu_tmp.Eta());
               hAbsEtaMuon_30->Fill(TMath::Abs(mu_tmp.Eta()));
               MuonEta_vs_Pt_30->Fill(TMath::Abs(mu_tmp.Eta()),mu_tmp.Pt());
             }


	     if(mu_tmp.Pt()>35){
	       hPtMuon_35->Fill(mu_tmp.Pt());
	       hEtaMuon_35->Fill(mu_tmp.Eta());
	       hAbsEtaMuon_35->Fill(TMath::Abs(mu_tmp.Eta()));
	       MuonEta_vs_Pt_35->Fill(TMath::Abs(mu_tmp.Eta()),mu_tmp.Pt());
	     }
	     //}
	 }
       }
       
       //       TLorentzVector mu_tmp; mu_tmp.SetPtEtaPhiE(1,0,0,0);
       TLorentzVector muW_reco; muW_reco.SetPtEtaPhiE(1,0,0,0);
       TLorentzVector muTau_reco; muTau_reco.SetPtEtaPhiE(1,0,0,0);
       Int_t muonMatch=0;
       Int_t muonMatch_tau=0;
       std::vector<int> indice_mu;
       bool MuonW_Match=false;
       bool MuonTau_Match=false;
       
       for (Int_t i=0 ; i<nMuon ; i++){
	 mu_tmp.SetPtEtaPhiE(Muon_pt[i], Muon_eta[i], Muon_phi[i], Muon_energy[i]);
	 //     std::cout<<" evento "<<jentry<<" muon reco pt "<<mu_tmp.Pt()<<" muon gen eta  "<<mu_tmp.Eta()<<" muon gen phi  "<<mu_tmp.Phi()<<" muon gen en  "<<mu_tmp.E()<<std::endl;
	 
	 
	 if(muGen_tau1.DeltaR(mu_tmp)<0.1 || muGen_tau2.DeltaR(mu_tmp)<0.1){
	   muonMatch_tau ++;
	   MuonTau_Match=true;
	   muTau_reco.SetPtEtaPhiE(Muon_pt[i], Muon_eta[i], Muon_phi[i], Muon_energy[i]);
	   
	   // indice_mu.push_back(i);
	   if (muonMatch_tau>1) {std::cout<<"sei fottuto perche matchano ben n muoni da Tau con n= "<<muonMatch_tau<<std::endl;
	     std::cout<<" evento "<<jentry<<" muon reco pt "<<mu_tmp.Pt()<<" muon gen eta  "<<mu_tmp.Eta()<<" muon gen phi  "<<mu_tmp.Phi()<<" muon gen en "<<mu_tmp.E()<<std::endl;
	     std::cout<<" evento "<<jentry<<" muon reco pt "<<muGen.Pt()<<" muon gen eta  "<<muGen.Eta()<<" muon gen phi  "<<muGen.Phi()<<" muon gen en  "<<
	       muGen.E()<<std::endl;
	   }
	   
	 }
       }//for muoni
       
       
       if(MuonW_Match==false)continue;
       //if(MuonTau_Match==false)continue;
       
       for(Int_t k=0; k<indice_mu.size();k++){
	 
	 hPtMuonReco->Fill(Muon_pt[indice_mu[k]]);
	 hEtaMuonReco->Fill(Muon_eta[indice_mu[k]]);
	 hAbsEtaMuonReco->Fill(TMath::Abs(Muon_eta[indice_mu[k]]));
	 MuonRecoEta_vs_Pt->Fill(TMath::Abs(Muon_eta[indice_mu[k]]),Muon_pt[indice_mu[k]]);
	 
	 
	 RelIso->Fill(Muon_pfRelIso04v2[indice_mu[k]]);
	 RelIsoDB->Fill(Muon_pfRelIsoDB04v2[indice_mu[k]]);
	 RelIsoDB_pt->Fill(Muon_pfRelIsoDB04v2[indice_mu[k]]*Muon_pt[indice_mu[k]]);
	 MuonPt_vs_IsoxPt->Fill(Muon_pt[indice_mu[k]],Muon_pfRelIsoDB04v2[indice_mu[k]]*Muon_pt[indice_mu[k]]);
	 
	 if(Muon_isGlobalMuonPromptTight[indice_mu[k]]==1) {
	   
	   hPtMuon_Global->Fill(Muon_pt[indice_mu[k]]);
	   hEtaMuon_Global->Fill(Muon_eta[indice_mu[k]]);
	   hAbsEtaMuon_Global->Fill(TMath::Abs(Muon_eta[indice_mu[k]])); 
	   MuonEta_vs_Pt_Global->Fill(TMath::Abs(Muon_eta[indice_mu[k]]),Muon_pt[indice_mu[k]]);
	 }
	 if(Muon_isPFMuon[indice_mu[k]]==1) {

	   hPtMuon_PF->Fill(Muon_pt[indice_mu[k]]);
	   hEtaMuon_PF->Fill(Muon_eta[indice_mu[k]]);
	   hAbsEtaMuon_PF->Fill(TMath::Abs(Muon_eta[indice_mu[k]]));
	   MuonEta_vs_Pt_PF->Fill(TMath::Abs(Muon_eta[indice_mu[k]]),Muon_pt[indice_mu[k]]);
	 }
	 //if (Muon_pfRelIsoDB04v2[indice_mu[k]] < 0.1){
	 if (Muon_pfRelIsoDB04v2[indice_mu[k]] < 0.5){
	   hPtMuon_ISO->Fill(Muon_pt[indice_mu[k]]);
	   hEtaMuon_ISO->Fill(Muon_eta[indice_mu[k]]);
	   hAbsEtaMuon_ISO->Fill(TMath::Abs(Muon_eta[indice_mu[k]]));
	   MuonEta_vs_Pt_ISO->Fill(TMath::Abs(Muon_eta[indice_mu[k]]),Muon_pt[indice_mu[k]]);
	   
 }
	 
	 
	 if(muGen.Pt()>24) {
	   
	   hPtMuon_afterPt->Fill(Muon_pt[indice_mu[k]]);
	   hEtaMuon_afterPt->Fill(Muon_eta[indice_mu[k]]);
	   hAbsEtaMuon_afterPt->Fill(TMath::Abs(Muon_eta[indice_mu[k]]));
	   MuonEta_vs_Pt_afterPt->Fill(TMath::Abs(Muon_eta[indice_mu[k]]),Muon_pt[indice_mu[k]]);
	 }
	 
	 
       }//mu reco       
       
    


       // stampa qualcosa per vedere se gira...
       if (jentry % 10000 == 0 ){
           std::cout << "jentry = " << jentry << std::endl;}

   } //parentesi del ciclo su tutti gli eventi
    
    std::cout<<"Htot; "<<H_tot->GetEntries()<<std::endl;
    std::cout<<"H->tau tau; "<<tautauEvent->GetEntries()<<std::endl;
    std::cout<<"H->tau tau controllo; "<<controlloTauTau->GetEntries()<<std::endl;
    std::cout<<"Wtot; "<<W_tot->GetEntries()<<std::endl;
    std::cout<<"Ztot; "<<Z_tot->GetEntries()<<std::endl;
    std::cout<<"t tot; "<<t_tot->GetEntries()<<std::endl;
    std::cout<<"mu status 1 tot; "<<muonStatus1->GetEntries()<<std::endl;
    std::cout<<"CANALI DI DECADIMENTO DEL TAU TAU nel canale in analisi"<<std::endl;
    std::cout<<"eventi full hadronic; "<<FHEvent->GetEntries()<<std::endl;
    std::cout<<"eventi e + jet; "<<elejetEvent->GetEntries()<<std::endl;
    std::cout<<"eventi m + jet; "<<mujetEvent->GetEntries()<<std::endl;
    std::cout<<"eventi full leptonic; "<<FLEvent->GetEntries()<<std::endl;
    std::cout<<"TRIGGER PLUS DECADIMENTI DEL TAU DEGLI EVENTI TRIGGERATI"<<std::endl;
    std::cout<<"muon status 1 in eventi con W;  "<<WplusMuon->GetEntries()<<std::endl;
    std::cout<<"mu di status 3 da W tot; "<<muonWstatus3->GetEntries()<<std::endl;
    std::cout<<"mu di status 1 da W tot; "<<muonW->GetEntries()<<std::endl;
    std::cout<<"eventi full hadronic; "<<GTFHEvent->GetEntries()<<std::endl;
    std::cout<<"eventi e + jet; "<<GTelejetEvent->GetEntries()<<std::endl;
    std::cout<<"eventi m + jet; "<<GTmujetEvent->GetEntries()<<std::endl;
    std::cout<<"eventi full leptonic; "<<GTFLEvent->GetEntries()<<std::endl;


    std::cout<<"+++++++++++++++++ABOUT CUTS+++++++++++++++++++++++++++ "<<std::endl;
    
} //parentesi del void

void VHAnalyzer::bookHistograms() {
    if (!bookedHistos) {
        // Open Output File
        std::string root_file = fileName;
        outputFile = new TFile(root_file.c_str(), "RECREATE");
        outputFile->cd();
        TH1::SetDefaultSumw2();


	hPtRes_HE= new TH1F("hPtRes_HE","hPtRes_HE",500,-10,10);
	hDBerr_HE= new TH1F("hDBerr_HE","hDBerr_HE",1000,-0.01,0.01);

	hPtRes_Barrel= new TH1F("hPtRes_Barrel","hPtRes_Barrel",500,-10,10);
	hDBerr_Barrel= new TH1F("hDBerr_Barrel","hDBerr_Barrel",1000,-0.01,0.01);

	hHCandMass = new TH1F("hHCandMass","hHCandMass",100,0,200);
	hHCandPt=new TH1F("hHCandPt","hHCandPt",100,0,100);
	hHCandEta = new  TH1F("hHCandEta","hHCandEta",100,-3,3);

	hHGenMass  = new TH1F("hHGenMass","hHGenMass",100,0,200);
	hHGenPt = new TH1F("hHGenPt","hHGenPt",100,0,100);
	hHGenEta = new  TH1F("hHGenEta","hHGenEta",100,-3,3);


        //////////////////////////////////////// H per conteggi /////////////////////////////////////////////
        H_tot = new TH1F("H_tot","H tot",3,0,3);
        W_tot = new TH1F("W_tot","W tot",3,0,3);
        Z_tot = new TH1F("Z_tot","Z tot",3,0,3);
        t_tot = new TH1F("t_tot","t tot",3,0,3);
        muonStatus1 = new TH1F("muonStatus1","muonStatus1",3,0,3);
        WplusMuon = new TH1F("WplusMuon","WplusMuon",3,0,3);
        muonW = new TH1F("muonW","",3,0,3);
        muonWstatus3 = new TH1F("muonWstatus3","",3,0,3);
        tautauEvent = new TH1F("tautauEvent","",3,0,3);
        controlloTauTau = new TH1F("controlloTauTau","",3,0,3);
        FHEvent= new TH1F("FHEvent","",3,0,3);
        GTFHEvent=new TH1F("GTFHEvent","",3,0,3);
        elejetEvent=new TH1F("elejetEvent","",3,0,3);
        GTelejetEvent=new TH1F("GTelejetEvent","",3,0,3);
        mujetEvent=new TH1F("mujetEvent","",3,0,3);
        GTmujetEvent=new TH1F("GTmujetEvent","",3,0,3);
        FLEvent=new TH1F("FLEvent","",3,0,3);
        GTFLEvent=new TH1F("GTFLEvent","",3,0,3);

        RelIso = new TH1F("RelIso","relIso of muon",66,-0.3,3);
        RelIsoDB = new TH1F("RelIsoDB","relIso of muon DB",66,-0.3,3);
        RelIsoDB_pt = new TH1F("RelIsoDB_pt","relIso of muon",200,0,100);
        MuonPt_vs_IsoxPt = new TH2F("MuonPt_vs_IsoxPt","Muon iso vs Pt", 200,0,200,200,0,100);
        
        hEtaMuon = new TH1F("EtaMuon","Eta of muon generator level ", 100, -5, 5);
        hAbsEtaMuon = new TH1F("AbsEtaMuon","Eta of muon generator level", 50, 0, 5);
        hPtMuon = new TH1F("PtMuon","Pt of muon generator level", 200, 0, 200);
        MuonEta_vs_Pt= new TH2F("MuonEta_vs_Pt","Muon Eta vs Pt", 50,0,5,200,0,200);


	hPtMuon_10= new TH1F("PtMuon_10","Pt of muon generator level (pt>10)", 200, 0, 200);
	hEtaMuon_10= new TH1F("EtaMuon_10","Eta of muon generator level (pt>10)", 100, -5, 5);
	hAbsEtaMuon_10= new TH1F("AbsEtaMuon_10","Eta of muon generator level (pt>10)", 50, 0, 5);
	MuonEta_vs_Pt_10=new TH2F("MuonEta_vs_Pt_10","Muon Eta vs Pt (pt>10)", 50,0,5,200,0,200);


        hEtaMuon_15 = new TH1F("EtaMuon_15","Eta of muon generator level (pt>15)", 100, -5, 5);
        hAbsEtaMuon_15 = new TH1F("AbsEtaMuon_15","Eta of muon generator level (pt>15)", 50, 0, 5);
        hPtMuon_15 = new TH1F("PtMuon_15","Pt of muon generator level (pt>15)", 200, 0, 200);
        MuonEta_vs_Pt_15= new TH2F("MuonEta_vs_Pt_15","Muon Eta vs Pt (pt>15)", 50,0,5,200,0,200);

	hEtaMuon_20 = new TH1F("EtaMuon_20","Eta of muon generator level (pt>20)", 100, -5, 5);
        hAbsEtaMuon_20 = new TH1F("AbsEtaMuon_20","Eta of muon generator level (pt>20)", 50, 0, 5);
        hPtMuon_20 = new TH1F("PtMuon_20","Pt of muon generator level (pt>20)", 200, 0, 200);
        MuonEta_vs_Pt_20= new TH2F("MuonEta_vs_Pt_20","Muon Eta vs Pt (pt>20)", 50,0,5,200,0,200);

	hEtaMuon_25 = new TH1F("EtaMuon_25","Eta of muon generator level (pt>25)", 100, -5, 5);
        hAbsEtaMuon_25 = new TH1F("AbsEtaMuon_25","Eta of muon generator level (pt>25)", 50, 0, 5);
        hPtMuon_25 = new TH1F("PtMuon_25","Pt of muon generator level (pt>25)", 200, 0, 200);
        MuonEta_vs_Pt_25= new TH2F("MuonEta_vs_Pt_25","Muon Eta vs Pt (pt>25)", 50,0,5,200,0,200);

	hEtaMuon_35 = new TH1F("EtaMuon_35","Eta of muon generator level (pt>35)", 100, -5, 5);
        hAbsEtaMuon_35 = new TH1F("AbsEtaMuon_35","Eta of muon generator level (pt>35)", 50, 0, 5);
        hPtMuon_35 = new TH1F("PtMuon_35","Pt of muon generator level (pt>35)", 200, 0, 200);
        MuonEta_vs_Pt_35= new TH2F("MuonEta_vs_Pt_35","Muon Eta vs Pt (pt>35)", 50,0,5,200,0,200);

	hEtaMuon_30 = new TH1F("EtaMuon_30","Eta of muon generator level (pt>30)", 100, -5, 5);
        hAbsEtaMuon_30 = new TH1F("AbsEtaMuon_30","Eta of muon generator level (pt>30)", 50, 0, 5);
        hPtMuon_30 = new TH1F("PtMuon_30","Pt of muon generator level (pt>30)", 200, 0, 200);
        MuonEta_vs_Pt_30= new TH2F("MuonEta_vs_Pt_30","Muon Eta vs Pt (pt>30)", 50,0,5,200,0,200);


        hEtaMuonReco = new TH1F("EtaMuonReco","Eta of muon generator level", 100, -5, 5); 
        hAbsEtaMuonReco = new TH1F("AbsEtaMuonReco","Eta of muon generator level", 50, 0, 5);
        hPtMuonReco = new TH1F("PtMuonReco","Pt of muon generator level", 200, 0, 200);
        MuonRecoEta_vs_Pt= new TH2F("MuonRecoEta_vs_Pt","MuonReco Eta vs Pt", 50,0,5,200,0,200);

        hEtaMuon_eta1624 = new TH1F("EtaMuon_eta1624","Eta of muon generator level", 100, -5, 5);
        hAbsEtaMuon_eta1624 = new TH1F("AbsEtaMuon_eta1624","Eta of muon generator level", 50, 0, 5);
        hPtMuon_eta1624 = new TH1F("PtMuon_eta1624","Pt of muon generator level", 200, 0, 200);

        hEtaMuon_afterPt = new TH1F("EtaMuon_afterPt","Eta of muon generator level after Pt > 24", 100, -5, 5); 
        hAbsEtaMuon_afterPt = new TH1F("AbsEtaMuon_afterPt","Eta of muon generator level after Pt > 24", 50, 0, 5);
        hPtMuon_afterPt = new TH1F("PtMuon_afterPt","Pt of muon generator level after Pt > 24", 200, 0, 200);
        MuonEta_vs_Pt_afterPt= new TH2F("MuonEta_vs_Pt_afterPt","Muon Eta vs Pt after Pt > 24", 50,0,5,200,0,200);

        hEtaMuon_Global = new TH1F("EtaMuon_Global","Eta of muon generator level after Pt > 24", 100, -5, 5);
        hAbsEtaMuon_Global = new TH1F("AbsEtaMuon_Global","Eta of muon generator level after Pt > 24", 50, 0, 5);
        hPtMuon_Global = new TH1F("PtMuon_Global","Pt of muon generator level after Pt > 24", 200, 0, 200);
        MuonEta_vs_Pt_Global= new TH2F("MuonEta_vs_Pt_Global","Muon Eta vs Pt after Pt > 24", 50,0,5,200,0,200);

        hEtaMuon_PF = new TH1F("EtaMuon_PF","Eta of muon generator level after Pt > 24", 100, -5, 5);
        hAbsEtaMuon_PF = new TH1F("AbsEtaMuon_PF","Eta of muon generator level after Pt > 24", 50, 0, 5);
        hPtMuon_PF = new TH1F("PtMuon_PF","Pt of muon generator level after Pt > 24", 200, 0, 200);
        MuonEta_vs_Pt_PF= new TH2F("MuonEta_vs_Pt_PF","Muon Eta vs Pt after Pt > 24", 50,0,5,200,0,200);

        hEtaMuon_ISO = new TH1F("EtaMuon_ISO","Eta of muon generator level after Pt > 24", 100, -5, 5);
        hAbsEtaMuon_ISO = new TH1F("AbsEtaMuon_ISO","Eta of muon generator level after Pt > 24", 50, 0, 5);
        hPtMuon_ISO = new TH1F("PtMuon_ISO","Pt of muon generator level after Pt > 24", 200, 0, 200);
        MuonEta_vs_Pt_ISO= new TH2F("MuonEta_vs_Pt_ISO","Muon Eta vs Pt after Pt > 24", 50,0,5,200,0,200);


        hEtaMuon_afterTrigger = new TH1F("EtaMuon_afterTrigger","Eta of muon generator level afterTrigger", 100, -5, 5);
        hAbsEtaMuon_afterTrigger = new TH1F("AbsEtaMuon_afterTrigger","Eta of muon generator level afterTrigger", 50, 0, 5);
        hPtMuon_afterTrigger = new TH1F("PtMuon_afterTrigger","Pt of muon generator level afterTrigger", 200, 0, 200);
	MuonEta_vs_Pt_afterTrigger= new TH2F("MuonEta_vs_Pt_afterTrigger","Muon Eta vs Pt", 50,0,5,200,0,200);

	hDB_Barrel= new TH1F("hDB_Barrel","hDB_Barrel",1000,-1,1);
	hDBSig_Barrel= new TH1F("hDBSig_Barrel","hDBSig_Barrel",100,-5,5);
	hChiSq_Barrel=new TH1F("hChiSq_Barrel","hChiSq_Barrel",100,0,100);

	hDB_HE= new TH1F("hDB_HE","hDB_Barrel",1000,-1,1);
	hDBSig_HE= new TH1F("hDBSig_HE","hDBSig_HE",100,-5,5);
	hChiSq_HE=new TH1F("hChiSq_HE","hChiSq_HE",100,0,100);

	HiggsVisMassHE= new TH1F("HiggsVisMassHE","HiggsVisMassHE",300,0,300);
	HiggsVisMassBarrel=new TH1F("HiggsVisMassBarrel","HiggsVisMassBarrel",300,0,300);

	hGenMuonPt= new TH1F("hGenMuonPt","hGenMuonPt",200,0,200);
	hGenMuonEta= new TH1F("hGenMuonEta","hGenMuonEta",100,-5,5);
	hRecoMuonMatchPt=new TH1F("hRecoMuonMatchPt","hRecoMuonMatchPt",200,0,200);
	hRecoMuonMatchEta= new TH1F("hRecoMuonMatchEta","hRecoMuonMatchEta",100,-5,5);
       
	hMuoPullX_HE=new TH1F("hMuoPullX_HE","hMuoPullX_HE",100,-1,1);
	hMuoPullY_HE=new TH1F("hMuoPullY_HE","hMuoPullY_HE",100,-1,1);
	hMuoPullZ_HE=new TH1F("hMuoPullZ_HE","hMuoPullZ_HE",100,-10,10);

	hMuoPullX_Barrel=new TH1F("hMuoPullX_Barrel","hMuoPullX_Barrel",100,-1,1);
	hMuoPullY_Barrel=new TH1F("hMuoPullY_Barrel","hMuoPullY_Barrel",100,-1,1);
	hMuoPullZ_Barrel=new TH1F("hMuoPullZ_Barrel","hMuoPullZ_Barrel",100,-10,10);

	hDZ_HE =new TH1F("hDZ_HE","hDZ_HE",100,-10,10);
	hDZ_Barrel=new TH1F("hDZ_Barrel","hDZ_Barrel",100,-10,10);
    }
}


void VHAnalyzer::saveHistograms() {
    if (outputFile) {
        f_puweights->Close();
        std::string root_file = fileName;
        outputFile = new TFile(root_file.c_str(), "RECREATE");
        outputFile->cd();
        
	hPtRes_HE->Write();
	  hDBerr_HE->Write();

	  hPtRes_Barrel->Write();
	  hDBerr_Barrel->Write();

        H_tot->Write();
        W_tot->Write();
        Z_tot->Write();
        t_tot->Write();
        muonStatus1->Write();
        WplusMuon->Write();
        muonW->Write();
        muonWstatus3->Write();
        tautauEvent->Write();
        controlloTauTau->Write();
        FHEvent->Write();
        GTFHEvent->Write();
        elejetEvent->Write();
        GTelejetEvent->Write();
        mujetEvent->Write();
        GTmujetEvent->Write();
        FLEvent->Write();
        GTFLEvent->Write();

	RelIso->Write();
	RelIsoDB->Write();

        hPtMuon->Write();
        hEtaMuon->Write();
        hAbsEtaMuon->Write();
        MuonEta_vs_Pt->Write();
        hPtMuonReco->Write();
        hEtaMuonReco->Write();
        hAbsEtaMuonReco->Write();
        MuonRecoEta_vs_Pt->Write();
        hPtMuon_eta1624->Write();
        hEtaMuon_eta1624->Write();
        hAbsEtaMuon_eta1624->Write();
        hPtMuon_afterTrigger->Write();
        hEtaMuon_afterTrigger->Write();
        hAbsEtaMuon_afterTrigger->Write();
        MuonEta_vs_Pt_afterTrigger->Write();
        hPtMuon_afterPt->Write();
        hEtaMuon_afterPt->Write();
        hAbsEtaMuon_afterPt->Write();
        MuonEta_vs_Pt_afterPt->Write();
        hPtMuon_Global->Write();
        hEtaMuon_Global->Write();
        hAbsEtaMuon_Global->Write();
        MuonEta_vs_Pt_Global->Write();
        hPtMuon_PF->Write();
        hEtaMuon_PF->Write();
        hAbsEtaMuon_PF->Write();
        MuonEta_vs_Pt_PF->Write();
        hPtMuon_ISO->Write();
        hEtaMuon_ISO->Write();
        hAbsEtaMuon_ISO->Write();
        MuonEta_vs_Pt_ISO->Write();
RelIsoDB_pt->Write();
MuonPt_vs_IsoxPt->Write();
  
 hPtMuon_25->Write();
 hEtaMuon_25->Write();
 hAbsEtaMuon_25->Write();
 MuonEta_vs_Pt_25->Write();

 hPtMuon_30->Write();
 hEtaMuon_30->Write();
 hAbsEtaMuon_30->Write();
 MuonEta_vs_Pt_30->Write();


 hPtMuon_20->Write();
 hEtaMuon_20->Write();
 hAbsEtaMuon_20->Write();
 MuonEta_vs_Pt_20->Write();


 
 hPtMuon_35->Write();
 hEtaMuon_35->Write();
 hAbsEtaMuon_35->Write();
 MuonEta_vs_Pt_35->Write();
 
 hEtaMuon_15->Write();
 hAbsEtaMuon_15->Write();
 hPtMuon_15->Write();
 MuonEta_vs_Pt_15->Write();
 

 hPtMuon_10->Write();
 hEtaMuon_10->Write();
 hAbsEtaMuon_10->Write();
 MuonEta_vs_Pt_10->Write();

	hDB_Barrel->Write();
	hDBSig_Barrel->Write();
	hChiSq_Barrel->Write();

	hDB_HE->Write();
	hDBSig_HE->Write();
	hChiSq_HE->Write();

	HiggsVisMassHE->Write();
	HiggsVisMassBarrel->Write();

	hRecoMuonMatchPt->Write();
	hRecoMuonMatchEta->Write();
	hGenMuonPt->Write();
	hGenMuonEta->Write();

	hMuoPullX_HE->Write();
	hMuoPullY_HE->Write();
	hMuoPullZ_HE->Write();

	hMuoPullX_Barrel->Write();
	hMuoPullY_Barrel->Write();
	hMuoPullZ_Barrel->Write();

	hDZ_HE->Write();
	hDZ_Barrel->Write();
        //delete outputFile;

	hHCandMass->Write(); 
	hHCandPt->Write();
	hHCandEta->Write(); 

	hHGenMass->Write(); 
	hHGenPt->Write(); 
	hHGenEta->Write();


    }
}
