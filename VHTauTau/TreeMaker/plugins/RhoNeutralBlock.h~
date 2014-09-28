#ifndef __VHTauTau_TreeMaker_RhoBlock_h
#define __VHTauTau_TreeMaker_RhoBlock_h

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
class Rho;

class RhoBlock : public edm::EDAnalyzer 
{
private:
  virtual void beginJob();
  virtual void beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup) {}
  virtual void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);
  virtual void endJob() {}

public:
  explicit RhoBlock(const edm::ParameterSet& iConfig);
  virtual ~RhoBlock() {}

  enum {
    kMaxRho = 5
  };

  void fillRho(const edm::Event& iEvent, 
               const edm::EventSetup& iSetup,
               TClonesArray* cloneRho,
               int fnRho,
               edm::InputTag iTag,
               vhtm::Rho* rhoB);

private:
  TClonesArray* cloneRho; 
  int  fnRho;

  TClonesArray* cloneRhoNeutral; 
  int  fnRhoN;


  int _verbosity;
  edm::InputTag _pfinputTag;
  //  edm::InputTag _mvainputTag;

  vhtm::Rho* rhoB;
  //  vhtm::Rho* rhoNB;

};
#endif
