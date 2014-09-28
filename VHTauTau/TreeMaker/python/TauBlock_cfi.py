import FWCore.ParameterSet.Config as cms

tauBlock = cms.EDAnalyzer("TauBlock",
  verbosity = cms.int32(0),
  patTauSrc = cms.InputTag('tauVariables'),
  vertexSrc = cms.InputTag('offlinePrimaryVertices')
)
