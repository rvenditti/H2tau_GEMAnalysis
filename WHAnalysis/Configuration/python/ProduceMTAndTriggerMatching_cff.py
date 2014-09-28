import FWCore.ParameterSet.Config as cms

producesUserDefinedVarsEle = cms.EDProducer('ElectronAddUserVariables',
    			objects = cms.InputTag("electronVariables"),
     			genParticles = cms.untracked.InputTag("genParticles"),
			isMC = cms.bool(False),
			particleId = cms.int32(11),
    			met = cms.InputTag("patMETsPF"),
    			triggerResults = cms.InputTag("patTriggerEvent"),
  			triggerPaths = cms.vstring("HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_LooseIsoPFTau15_v",
					    	   "HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_LooseIsoPFTau20_v",
					           "HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TightIsoPFTau20_v",
					    	   "HLT_Ele18_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_MediumIsoPFTau20_v",
					    	   "HLT_Ele20_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_MediumIsoPFTau20_v"), 
  			triggerObjNamesLeg1 =cms.vstring("hltEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilter",
							 "hltEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilter",
							 "hltEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilter",
							 "hltEle18CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilter",
							 "hltEle20CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilterL1SingleEG18orL1SingleEG20",
							 "hltEle20CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilterL1SingleEG18orL1SingleEG20"), 
  			triggerObjNamesLeg2 = cms.vstring("hltOverlapFilterIsoEle15IsoPFTau15",
							  "hltOverlapFilterIsoEle15IsoPFTau20",
							  "hltOverlapFilterIsoEle15TightIsoPFTau20",
							  "hltOverlapFilterIsoEle18MediumIsoPFTau20",
							  "hltOverlapFilterIsoEle20MediumIsoPFTau20"),
  			hltEventRanges = cms.VEventRange("160404:MIN-163869:MAX",
						      	 "165088:MIN-167913:MAX",
						      	 "170249:MIN-173198:MAX",
						      	 "173236:MIN-173692:MAX",
						      	 "175860:MIN-180252:MAX")
			)

producesUserDefinedVarsTau = cms.EDProducer('TauAddUserVariables',
    			objects = cms.InputTag("tauVariables"),
     			genParticles = cms.untracked.InputTag("genParticles"),
			isMC = cms.bool(False),
			particleId = cms.int32(15),
    			met = cms.InputTag("patMETsPF"),
    			triggerResults = cms.InputTag("patTriggerEvent"),
  			triggerPaths = cms.vstring("HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_LooseIsoPFTau15_v",
					    	   "HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_LooseIsoPFTau20_v",
					           "HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TightIsoPFTau20_v",
					    	   "HLT_Ele18_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_MediumIsoPFTau20_v",
					    	   "HLT_Ele20_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_MediumIsoPFTau20_v"), 
  			triggerObjNamesLeg1 =cms.vstring("hltEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilter",
							 "hltEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilter",
							 "hltEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilter",
							 "hltEle18CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilter",
							 "hltEle20CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilterL1SingleEG18orL1SingleEG20",
							 "hltEle20CaloIdVTCaloIsoTTrkIdTTrkIsoTTrackIsoFilterL1SingleEG18orL1SingleEG20"), 
  			triggerObjNamesLeg2 = cms.vstring("hltOverlapFilterIsoEle15IsoPFTau15",
							  "hltOverlapFilterIsoEle15IsoPFTau20",
							  "hltOverlapFilterIsoEle15TightIsoPFTau20",
							  "hltOverlapFilterIsoEle18MediumIsoPFTau20",
							  "hltOverlapFilterIsoEle20MediumIsoPFTau20"),
  			hltEventRanges = cms.VEventRange("160404:MIN-163869:MAX",
						      	 "165088:MIN-167913:MAX",
						      	 "170249:MIN-173198:MAX",
						      	 "173236:MIN-173692:MAX",
						      	 "175860:MIN-180252:MAX")
			)

producesUserDefinedVarsMu = cms.EDProducer('MuonAddUserVariables',
    			objects = cms.InputTag("muonVariables"),
    			met = cms.InputTag("patMETsPF"),
    			triggerResults = cms.InputTag("patTriggerEvent"),
  			triggerPaths = cms.vstring("HLT_DoubleMu7_v","HLT_Mu13_Mu8_v","HLT_Mu17_Mu8_v"), 
  			triggerObjNamesLeg1 =cms.vstring("hltDiMuonL3PreFiltered7","hltSingleMu13L3Filtered13","hltL1Mu3EG5L3Filtered17"), 
  			triggerObjNamesLeg2 = cms.vstring("hltDiMuonL3PreFiltered7","hltDiMuonL3PreFiltered8","hltDiMuonL3PreFiltered8"), 
  			hltEventRanges = cms.VEventRange("160431:MIN-163869:MAX","165088:MIN-178380:MAX","178420:MIN-180252:MAX")
			)
