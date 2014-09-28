import FWCore.ParameterSet.Config as cms

rhoNeutralBlock = cms.EDAnalyzer("RhoNeutralBlock",
                          verbosity = cms.int32(1),
                          RhoNeutralSrc    = cms.InputTag('rhoNeutral','rho','PAT'),                           
                          
)
