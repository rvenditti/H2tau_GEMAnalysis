#include "TTree.h"
#include "TClonesArray.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
//#include "DataFormats/PatCandidates/interface/Rho.h"

#include "VHTauTau/TreeMaker/plugins/RhoNeutralBlock.h"
#include "VHTauTau/TreeMaker/interface/Utility.h"

RhoNeutralBlock::RhoNeutralBlock(const edm::ParameterSet& iConfig) :
  _verbosity(iConfig.getParameter<int>("verbosity")),
  _pfinputTag(iConfig.getParameter<edm::InputTag>("RhoNeutralSrc"))

{
}
void RhoNeutralBlock::beginJob() 
{
  // Get TTree pointer
  TTree* tree = vhtm::Utility::getTree("vhtree");

  cloneRhoNeutral = new TClonesArray("vhtm::RhoNeutral");
  tree->Branch("RhoNeutral", &cloneRhoNeutral, 32000, 2);
  tree->Branch("nRhoNeutral", &fnRhoNeutral,  "fnRhoNeutral/I");

 

}
void RhoNeutralBlock::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  fillRho(iEvent, iSetup, cloneRhoNeutral, fnRhoNeutral, _pfinputTag, rhoNeutralB);

}
void RhoNeutralBlock::fillRho(const edm::Event& iEvent, 
                       const edm::EventSetup& iSetup,
                       TClonesArray*  cloneRhoNeutral,
                       int nRhoNeutral,
                       edm::InputTag iTag,
                       vhtm::RhoNeutral* rhoNeutralB)
{
  // Reset the TClonesArray and the nObj variables
  cloneRhoNeutral->Clear();
   nRhoNeutral= 0;

  edm::Handle<double> rhoNeutral;
  iEvent.getByLabel(iTag, rhoNeutral);

  

  if (rhoNeutral.isValid()) {
    //  edm::LogInfo("RhoNeutralBlock") << "Total # PAT Rhos: " << rho->size();

    // for (double::const_iterator it = rho->begin(); 
    //                                        it != rho->end(); ++it) {
    //if (nRho == kMaxRho) {
    //edm::LogInfo("RhoNeutralBlock") << "Too many PAT Rho, nRho = " << nRho 
    //                           << ", label: " << iTag; 
    //break;
    //}
      rhoNeutralB = new ((* cloneRhoNeutral)[nRhoNeutral++]) vhtm::RhoNeutral();
      rhoNeutralB->rhoNeutral     = *(rhoNeutral);
      std::cout<<"rho   "<<*(rhoNeutral)<<std::endl;
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
    edm::LogError("RhoNeutralBlock") << "Error >> Failed to get pat::Rho collection for label: " 
                              << iTag;
  }
}
#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(RhoNeutralBlock);
