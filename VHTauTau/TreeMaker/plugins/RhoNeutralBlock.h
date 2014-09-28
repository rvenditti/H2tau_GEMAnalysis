#ifndef __VHTauTau_TreeMaker_RhoNeutralBlock_h
#define __VHTauTau_TreeMaker_RhoNeutralBlock_h

#include <string>
#include <vector>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "VHTauTau/TreeMaker/interface/PhysicsObjects.h"

class TClonesArray;
class RhoNeutral;

class RhoNeutralBlock : public edm::EDAnalyzer 
{
private:
  virtual void beginJob();
  virtual void beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup) {}
  virtual void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);
  virtual void endJob() {}

public:
  explicit RhoNeutralBlock(const edm::ParameterSet& iConfig);
  virtual ~RhoNeutralBlock() {}

  enum {
    kMaxRho = 5
  };

  void fillRho(const edm::Event& iEvent, 
               const edm::EventSetup& iSetup,
               TClonesArray* cloneRhoNeutral,
               int fnRhoNeutral,
               edm::InputTag iTag,
               vhtm::RhoNeutral* rhoNeutralB);

private:
  TClonesArray* cloneRhoNeutral; 
  int  fnRhoNeutral;

  int _verbosity;
  edm::InputTag _pfinputTag;


  vhtm::RhoNeutral* rhoNeutralB;
  //  vhtm::Rho* rhoNB;

};
#endif
