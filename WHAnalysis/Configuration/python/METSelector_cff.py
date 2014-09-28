import FWCore.ParameterSet.Config as cms

selectedMETMax = cms.EDFilter("PATMETSelector",
     src = cms.InputTag("patMETsPF"),
     cut = cms.string('et > 20'),
     filter = cms.bool(True)
)
