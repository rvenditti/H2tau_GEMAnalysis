#include "TTree.h"
#include "TClonesArray.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
//#include "DataFormats/PatCandidates/interface/Rho.h"

#include "VHTauTau/TreeMaker/plugins/RhoBlock.h"
#include "VHTauTau/TreeMaker/interface/Utility.h"

RhoBlock::RhoBlock(const edm::ParameterSet& iConfig) :
  _verbosity(iConfig.getParameter<int>("verbosity")),
  _pfinputTag(iConfig.getParameter<edm::InputTag>("RhoSrc"))
  //  _mvainputTag(iConfig.getParameter<edm::InputTag>("RhoNeutralSrc"))

{
}
void RhoBlock::beginJob() 
{
  // Get TTree pointer
  TTree* tree = vhtm::Utility::getTree("vhtree");

  cloneRho = new TClonesArray("vhtm::Rho");
  tree->Branch("Rho", &cloneRho, 32000, 2);
  tree->Branch("nRho", &fnRho,  "fnRho/I");

  //  cloneRhoNeutral = new TClonesArray("vhtm::Rho");
  //  tree->Branch("RhoN", &cloneRhoNeutral, 32000, 2);
  //  tree->Branch("nRhoN", &fnRhoN,  "fnRhoN/I");

}
void RhoBlock::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  fillRho(iEvent, iSetup, cloneRho, fnRho, _pfinputTag, rhoB);
  //  fillRho(iEvent, iSetup, cloneRho, fnRhoN, _mvainputTag, rhoNB);

}
void RhoBlock::fillRho(const edm::Event& iEvent, 
                       const edm::EventSetup& iSetup,
                       TClonesArray* cloneRho,
                       int nRho,
                       edm::InputTag iTag,
                       vhtm::Rho* rhoB)
{
  // Reset the TClonesArray and the nObj variables
  cloneRho->Clear();
  nRho = 0;

  edm::Handle<double> rho;
  iEvent.getByLabel(iTag, rho);

  //  edm::Handle<double> srcRho;
  //  if(iEvent.getByLabel(srcRho_,srcRho))
  // rho = *srcRho;

  if (rho.isValid()) {
    //  edm::LogInfo("RhoBlock") << "Total # PAT Rhos: " << rho->size();

    // for (double::const_iterator it = rho->begin(); 
    //                                        it != rho->end(); ++it) {
    //if (nRho == kMaxRho) {
    //edm::LogInfo("RhoBlock") << "Too many PAT Rho, nRho = " << nRho 
    //                           << ", label: " << iTag; 
    //break;
    //}
      rhoB = new ((*cloneRho)[nRho++]) vhtm::Rho();
      rhoB->rho      = *(rho);
      std::cout<<"rho   "<<*(rho)<<std::endl;
      // fill in all the vectors
      /*     rhoB->met          = it->pt();
      rhoB->metphi       = it->phi();
      rhoB->sumet        = it->sumEt();
      rhoB->metuncorr    = it->uncorrectedPt(pat::Rho::uncorrALL);
      rhoB->metphiuncorr = it->uncorrectedPhi(pat::Rho::uncorrALL);
      rhoB->sumetuncorr  = it->sumEt() - it->corSumEt(pat::Rho::uncorrALL);*/
      //}
} 
  else {
    edm::LogError("RhoBlock") << "Error >> Failed to get pat::Rho collection for label: " 
                              << iTag;
  }
}
#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(RhoBlock);
