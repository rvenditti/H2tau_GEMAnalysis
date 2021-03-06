## import skeleton process
from patTemplate_cfg import *

process.MessageLogger.cerr.FwkReport.reportEvery = 5000

from PhysicsTools.PatAlgos.tools.coreTools import *

process.load('Configuration.StandardSequences.Services_cff')
process.load("PhysicsTools.PatAlgos.patSequences_cff")

process.options.allowUnscheduled = cms.untracked.bool( True )

process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
from PhysicsTools.PatAlgos.tools.tauTools import *
switchToPFTauHPS(process)

#from vertexMultiplicityVsRhoPFNeutralReweight_cfi import *

#--------------------------------------------------------------------------------

################### Take inputs from crab.cfg file ##############
from FWCore.ParameterSet.VarParsing import VarParsing
options = VarParsing ('python')
options.register ('isMC',
                  True,
                VarParsing.multiplicity.singleton,
                  VarParsing.varType.bool,
                  "Sample Type: MC or data")

options.register ('channel',
                  'none',
                  VarParsing.multiplicity.singleton,
                  VarParsing.varType.string,
                  "Desired channel: mtt, ett or none")    

options.register ('globaltag',
                  'PH2_1K_FB_V5::All',
                  VarParsing.multiplicity.singleton,
                  VarParsing.varType.string,
                  "Global Tag to use. PH1_1K_FB_V1 per PU=140 per auto:upgrade2019 PU=40")

options.register ('includeSim',
                  True,
                  VarParsing.multiplicity.singleton,
                  VarParsing.varType.bool,
                  "Include Sim. Default: False")

options.register ('includePatTrig',
                  False,
                  VarParsing.multiplicity.singleton,
                  VarParsing.varType.bool,
                  "Include PatTrig. Default: False")

import sys
print sys.argv

if len(sys.argv) > 0:
    last = sys.argv.pop()
    sys.argv.extend(last.split(","))
    print sys.argv

if hasattr(sys, "argv") == True:
	options.parseArguments()
isMC = options.isMC
channel = options.channel
globaltag = options.globaltag
includeSim = options.includeSim
includePatTrig = options.includePatTrig
print 'Using channel: %s' % channel

#--------------------------------------------------------------------------------

from PhysicsTools.PatAlgos.tools.jetTools import *

#jec = [ 'L1FastJet', 'L2Relative', 'L3Absolute' ]
#if not isMC:
#        jec.extend([ 'L2L3Residual' ])

switchJetCollection(
   process,
   jetSource = cms.InputTag('ak5PFJets'),
   jetCorrections = ('AK5PF', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute']), 'Type-2'),
   btagDiscriminators = [
       'jetBProbabilityBJetTags'
     , 'jetProbabilityBJetTags'
     , 'trackCountingHighPurBJetTags'
     , 'trackCountingHighEffBJetTags'
     , 'simpleSecondaryVertexHighEffBJetTags'
     , 'simpleSecondaryVertexHighPurBJetTags'
     , 'combinedSecondaryVertexBJetTags'
     ],
   )

#--------------------------------------------------------------------------------

process.patTaus.embedLeadPFCand = cms.bool(True)
process.patTaus.embedSignalPFCands = cms.bool(True)
process.patTaus.embedIsolationPFCands = cms.bool(True)
process.patTaus.embedLeadTrack = cms.bool(True)
process.patTaus.embedSignalTracks = cms.bool(True)
process.patTaus.embedIsolationTracks = cms.bool(True)
process.patTaus.embedIsolationPFChargedHadrCands = cms.bool(True)
process.patTaus.embedIsolationPFNeutralHadrCands = cms.bool(True)
process.patTaus.embedIsolationPFGammaCands = cms.bool(True)
process.patTaus.embedSignalPFChargedHadrCands = cms.bool(True)
process.patTaus.embedSignalPFNeutralHadrCands = cms.bool(True)
process.patTaus.embedSignalPFGammaCands = cms.bool(True)
process.patTaus.embedLeadPFChargedHadrCand = cms.bool(True)
process.patTaus.embedLeadPFNeutralCand = cms.bool(True)

#--------------------------------------------------------------------------------

process.load("CommonTools.ParticleFlow.Isolation.pfMuonIsolation_cff")
process.load("CommonTools.ParticleFlow.Isolation.pfElectronIsolation_cff")

from CommonTools.ParticleFlow.Tools.pfIsolation import setupPFMuonIso
from CommonTools.ParticleFlow.Tools.pfIsolation import setupPFElectronIso

process.stdMuonSequencePFIso = setupPFMuonIso(process,'muons')
process.stdElectronSequencePFIso = setupPFElectronIso(process,'gsfElectrons')

from CommonTools.ParticleFlow.pfParticleSelection_cff import pfParticleSelectionSequence
process.pfParticleSelectionSequence = pfParticleSelectionSequence

process.patMuons.isoDeposits = cms.PSet(
    pfAllParticles = cms.InputTag("muPFIsoDepositPUPFIso"), # all PU CH+MU+E
    pfChargedHadrons = cms.InputTag("muPFIsoDepositChargedPFIso"), # all noPU CH

    pfNeutralHadrons = cms.InputTag("muPFIsoDepositNeutralPFIso"), # all NH
    pfPhotons = cms.InputTag("muPFIsoDepositGammaPFIso"), # all PH

    user = cms.VInputTag(
    cms.InputTag("muPFIsoDepositChargedAllPFIso"), # all noPU CH+MU+E
    )
    )

process.patMuons.isolationValues = cms.PSet(
    pfAllParticles = cms.InputTag("muPFIsoValuePU04PFIso"),
    pfChargedHadrons = cms.InputTag("muPFIsoValueCharged04PFIso"),

    pfNeutralHadrons = cms.InputTag("muPFIsoValueNeutral04PFIso"),
    pfPhotons = cms.InputTag("muPFIsoValueGamma04PFIso"),

    user = cms.VInputTag(
    cms.InputTag("muPFIsoValueChargedAll04PFIso"),
    )
    )

process.patElectrons.isoDeposits = cms.PSet(
    pfAllParticles = cms.InputTag("elPFIsoDepositPUPFIso"), # all PU CH+MU+E

    pfChargedHadrons = cms.InputTag("elPFIsoDepositChargedPFIso"), # all noPU CH
    pfNeutralHadrons = cms.InputTag("elPFIsoDepositNeutralPFIso"), # all NH

    pfPhotons = cms.InputTag("elPFIsoDepositGammaPFIso"), # all PH
    user = cms.VInputTag(
    cms.InputTag("elPFIsoDepositChargedAllPFIso"), # all noPU CH+MU+E

    )
    )
process.patElectrons.isolationValues = cms.PSet(
    pfAllParticles = cms.InputTag("elPFIsoValuePU04PFIdPFIso"),
    pfChargedHadrons = cms.InputTag("elPFIsoValueCharged04PFIdPFIso"),

    pfNeutralHadrons = cms.InputTag("elPFIsoValueNeutral04PFIdPFIso"),
    pfPhotons = cms.InputTag("elPFIsoValueGamma04PFIdPFIso"),

    user = cms.VInputTag(
    cms.InputTag("elPFIsoValueChargedAll04PFIdPFIso"),
    cms.InputTag("elPFIsoValueChargedAll04NoPFIdPFIso"),

    cms.InputTag("elPFIsoValuePU04NoPFIdPFIso"),
    cms.InputTag("elPFIsoValueCharged04NoPFIdPFIso"),
    cms.InputTag("elPFIsoValueGamma04NoPFIdPFIso"),

    cms.InputTag("elPFIsoValueNeutral04NoPFIdPFIso")
    )

    )

#--------------------------------------------------------------------------------

# require scraping filter
process.scrapingVeto = cms.EDFilter("FilterOutScraping",
	applyfilter = cms.untracked.bool(True),
	debugOn = cms.untracked.bool(False),
	numtrack = cms.untracked.uint32(10),
	thresh = cms.untracked.double(0.2)
	)

process.tauVariables = cms.EDProducer('TausUserEmbedded',
	tauTag = cms.InputTag("patTausTriggerMatch"),
	vertexTag = cms.InputTag("offlinePrimaryVerticesWithBS")
)

print 'Using isMC: %s' % isMC
if isMC:
    targetString = "Fall11MC"
else:
    targetString = "2012Data"
                        
process.muonVariables = cms.EDProducer('MuonsUserEmbedded',
                                       muonTag = cms.InputTag("patMuonsTriggerMatch"),
                                       vertexTag = cms.InputTag("offlinePrimaryVerticesWithBS"),
                                       doMuIdMVA = cms.bool(False),
                                       doMuIsoMVA = cms.bool(False),
                                       doMuIsoRingsRadMVA = cms.bool(False),
                                       doMuIdIsoCombMVA = cms.bool(False),
                                       target = cms.string(targetString),
                                       
)

process.electronVariables = cms.EDProducer('ElectronsUserEmbedder',
                                           electronTag = cms.InputTag("patElectronsTriggerMatch"),
                                           vertexTag = cms.InputTag("offlinePrimaryVerticesWithBS"),
                                           isMC = cms.bool(isMC),
                                           doMVAPOG = cms.bool(False),
                                           doMVAMIT = cms.bool(False),
                                           doMVAIso = cms.bool(False),
                                         
                                           )

#--------------------------------------------------------------------------------

# PAT Muons
process.patMuons.embedTrack = cms.bool(True) # Embed tracks for muon ID cuts to be done offline

# PAT Electrons
process.patElectrons.embedTrack = cms.bool(True)
process.patElectrons.embedGsfTrack = cms.bool(True)

#process.load('EGamma.EGammaAnalysisTools.electronIdMVAProducer_cfi')
#process.patElectrons.electronIDSources = cms.PSet(mvaNonTrigV0 = cms.InputTag("mvaNonTrigV0"))

#--------------------------------------------------------------------------------

# Trigger and Trigger matching
from PhysicsTools.PatAlgos.tools.trigTools import *
switchOnTrigger(process)

process.patMuonTriggerMatchHLTIsoMu24 = cms.EDProducer('PATTriggerMatcherDRDPtLessByR',
        src = cms.InputTag("patMuons"),
        matched = cms.InputTag("patTrigger"),
        matchedCuts = cms.string('path("HLT_IsoMu24_v*")'),
        maxDPtRel = cms.double(0.5),
        maxDeltaR = cms.double(0.5),
        resolveAmbiguities = cms.bool(True),
        resolveByMatchQuality = cms.bool(True))
process.patMuonTriggerMatchHLTIsoMu24eta2p1 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patMuons"),
        matchedCuts = cms.string('path("HLT_IsoMu24_eta2p1_v*")'))
process.patMuonTriggerMatchHLTMu40 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patMuons"),
        matchedCuts = cms.string('path("HLT_Mu40_v*")'))


process.patTauTriggerMatchHLTEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTLooseIsoPFTau15 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patTaus"),
        matchedCuts = cms.string('path("HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_LooseIsoPFTau15_v*")'))
process.patTauTriggerMatchHLTEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTLooseIsoPFTau20 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patTaus"),
        matchedCuts = cms.string('path("HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_LooseIsoPFTau20_v*")'))
process.patTauTriggerMatchHLTEle18CaloIdVTCaloIsoTTrkIdTTrkIsoTLooseIsoPFTau20 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patTaus"),
        matchedCuts = cms.string('path("HLT_Ele18_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_LooseIsoPFTau20_v*")'))
process.patTauTriggerMatchHLTEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTTightIsoPFTau20 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patTaus"),
        matchedCuts = cms.string('path("HLT_Ele15_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_TightIsoPFTau20_v*")'))
process.patTauTriggerMatchHLTEle18CaloIdVTCaloIsoTTrkIdTTrkIsoTMediumIsoPFTau20 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patTaus"),
        matchedCuts = cms.string('path("HLT_Ele18_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_MediumIsoPFTau20_v*")'))
process.patTauTriggerMatchHLTEle20CaloIdVTCaloIsoTTrkIdTTrkIsoTMediumIsoPFTau20 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patTaus"),
        matchedCuts = cms.string('path("HLT_Ele20_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_MediumIsoPFTau20_v*")'))
process.patTauTriggerMatchHLTEle20CaloIdVTCaloIsoRhoTTrkIdTTrkIsoTLooseIsoPFTau20 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patTaus"),
        matchedCuts = cms.string('path("HLT_Ele20_CaloIdVT_CaloIsoRhoT_TrkIdT_TrkIsoT_LooseIsoPFTau20_v*")'))
process.patTauTriggerMatchHLTEle22eta2p1WP90RhoLooseIsoPFTau20 = process.patMuonTriggerMatchHLTIsoMu24.clone(
        src = cms.InputTag("patTaus"),
        matchedCuts = cms.string('path("HLT_Ele22_eta2p1_WP90Rho_LooseIsoPFTau20_v*")'))

switchOnTriggerMatchEmbedding(process, [
                'patMuonTriggerMatchHLTIsoMu24',
                'patMuonTriggerMatchHLTIsoMu24eta2p1',
                'patMuonTriggerMatchHLTMu40',


                'patTauTriggerMatchHLTEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTLooseIsoPFTau15',
                'patTauTriggerMatchHLTEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTLooseIsoPFTau20',
                'patTauTriggerMatchHLTEle18CaloIdVTCaloIsoTTrkIdTTrkIsoTLooseIsoPFTau20',
                'patTauTriggerMatchHLTEle15CaloIdVTCaloIsoTTrkIdTTrkIsoTTightIsoPFTau20',
                'patTauTriggerMatchHLTEle18CaloIdVTCaloIsoTTrkIdTTrkIsoTMediumIsoPFTau20',
                'patTauTriggerMatchHLTEle20CaloIdVTCaloIsoTTrkIdTTrkIsoTMediumIsoPFTau20',
                'patTauTriggerMatchHLTEle20CaloIdVTCaloIsoRhoTTrkIdTTrkIsoTLooseIsoPFTau20',
                'patTauTriggerMatchHLTEle22eta2p1WP90RhoLooseIsoPFTau20',
        ])

#--------------------------------------------------------------------------------

process.goodOfflinePrimaryVertices2 = cms.EDFilter("VertexSelector",
    	src = cms.InputTag("offlinePrimaryVertices"),
    	cut = cms.string("!isFake && ndof > 4 && abs(z) <= 24 && position.Rho <= 2"),
    	filter = cms.bool(True)
    	)


if(channel == "none"):
  	process.theSkim = cms.Sequence(
  	)

#--------------------------------------------------------------------------------

process.load("JetMETCorrections.Type1MET.pfMETCorrections_cff")
process.pfJetMETcorr.offsetCorrLabel = cms.string("ak5PFL1Fastjet")
if isMC:
	process.pfJetMETcorr.jetCorrLabel = cms.string("ak5PFL1FastL2L3")
else:
	process.pfJetMETcorr.jetCorrLabel = cms.string("ak5PFL1FastL2L3Residual")

# load the coreTools of PAT
from PhysicsTools.PatAlgos.tools.metTools import *
AddMETCollection()

process.load("JetMETCorrections.Type1MET.pfMETCorrectionType0_cfi")
process.pfType1CorrectedMet.applyType0Corrections = cms.bool(False)
process.pfType1CorrectedMet.srcType1Corrections = cms.VInputTag(
    	cms.InputTag('pfMETcorrType0'),
    	cms.InputTag('pfJetMETcorr', 'type1')        
)

process.patPFMETsTypeIcorrected = process.patMETs.clone(
	metSource = cms.InputTag('pfType1CorrectedMet'),
	addMuonCorrections = cms.bool(False),
	genMETSource = cms.InputTag('genMetTrue'),
	addGenMET = cms.bool(False)
)

# apply type I/type I + II PFMEt corrections to pat::MET object
# and estimate systematic uncertainties on MET
#from PhysicsTools.PatUtils.tools.metUncertaintyTools import runMEtUncertainties
#runMEtUncertainties(process)



#--------------------------------------------------------------------------------
process.TFileService = cms.Service("TFileService", fileName = cms.string('tree.root'))

process.load("VHTauTau.TreeMaker.TreeCreator_cfi")
process.load("VHTauTau.TreeMaker.TreeWriter_cfi")
process.load("VHTauTau.TreeMaker.TreeContentConfig_cff")     

#------------------------------------------------------------------------------------------



from CommonTools.ParticleFlow.pfNoPileUp_cff import *
pfPileUpForRhoNeutral = pfPileUp.clone(
        PFCandidates = cms.InputTag("particleFlow")
        )
pfNoPileUpForRhoNeutral = pfNoPileUp.clone(
        bottomCollection = cms.InputTag("particleFlow"),
            topCollection = cms.InputTag("pfPileUpForRhoNeutral")
        )
pfNoPileUpForRhoNeutralSequence = (
    pfPileUpForRhoNeutral
    + pfNoPileUpForRhoNeutral
    )

from CommonTools.ParticleFlow.ParticleSelectors.pfAllNeutralHadronsAndPhotons_cfi import *
pfAllNeutralHadronsAndPhotonsForRhoNeutral = pfAllNeutralHadronsAndPhotons.clone(
        src = cms.InputTag("pfNoPileUpForRhoNeutral")
        )

from RecoJets.Configuration.RecoPFJets_cff import *
kt6PFNeutralHadronAndPhotonJetsForRhoNeutral = kt6PFJets.clone(
        src = cms.InputTag('pfAllNeutralHadronsAndPhotonsForRhoNeutral')
        )


# Rho corrections
applyRhoCorrection = cms.bool(False),
rhoProducer = cms.InputTag("fixedGridRhoFastjetAll"),
rhoConeSize = cms.double(0.5),
rhoUEOffsetCorrection = cms.double(1.0)

from CommonTools.ParticleFlow.pfNoPileUpIso_cff import *
from CommonTools.ParticleFlow.pfNoPileUp_cff import *


from CommonTools.ParticleFlow.pfNoPileUp_cff import *

from RecoJets.JetProducers.kt4PFJets_cfi import kt4PFJets

process.rhoCorr = kt6PFJets.clone(
    src = cms.InputTag('particleFlow'),
    rParam = cms.double(0.6),
    doRhoFastjet = cms.bool(True),
    Rho_EtaMax = cms.double(2.5)
)

from CommonTools.ParticleFlow.ParticleSelectors.pfAllNeutralHadrons_cfi import pfAllNeutralHadrons
from CommonTools.ParticleFlow.ParticleSelectors.pfAllPhotons_cfi import pfAllPhotons
pfNeutralCandPdgIds = []
pfNeutralCandPdgIds.extend(pfAllNeutralHadrons.pdgId.value())
pfNeutralCandPdgIds.extend(pfAllPhotons.pdgId.value())
 
process.pfNeutralCands = cms.EDFilter("PdgIdPFCandidateSelector",
    src = cms.InputTag('particleFlow'),
    pdgId = cms.vint32(pfNeutralCandPdgIds)
)


process.rhoNeutral = kt6PFJets.clone(
    src = cms.InputTag('pfNeutralCands'),
    rParam = cms.double(0.6),
    doRhoFastjet = cms.bool(True),
    Rho_EtaMax = cms.double(2.5)
)


process.rhoNeutralMuon = kt6PFJets.clone(
    src = cms.InputTag("pfAllNeutralHadronsAndPhotons"),
    Ghost_EtaMax = cms.double(3.1),
    Rho_EtaMax = cms.double(2.5),
    inputEtMin = cms.double(0.5),
    doRhoFastjet = cms.bool(True),
    )

process.rhoMuon = kt6PFJets.clone(
    Ghost_EtaMax = cms.double(2.5),
    Rho_EtaMax = cms.double(2.5),
    doRhoFastjet = cms.bool(True),
    )

##------------------------------------------------------------------

#rho=process.kt6PFJets.clone( Rho_EtaMax = cms.double(2.5), Ghost_EtaMax = cms.double(2.5) ) 

## let it run
process.p = cms.Path(
	#process.counter *
	process.scrapingVeto *
	process.pfParticleSelectionSequence *
        process.stdMuonSequencePFIso *
        process.stdElectronSequencePFIso *
	process.type0PFMEtCorrection *
  	process.producePFMETCorrections *
        process.PFTau*
        process.makePatMuons +
        process.makePatTaus +
        process.makePatJets +
        process.makePatElectrons +
        process.makePatMETs +
	process.muonVariables *
	process.tauVariables *
	process.patPFMETsTypeIcorrected *
        process.rhoCorr *
        process.pfNeutralCands *
        process.rhoNeutral *
        process.rhoMuon*
        process.rhoNeutralMuon *
        process.treeCreator *
        process.treeContentSequence *
        process.treeWriter           
)

#--------------------------------------------------------------------------------

## remove MC matching from the default sequence
if not isMC:
	removeMCMatching(process, ['All'])
	removeMCMatching(process, ['METs'], "TC")
	removeMCMatching(process, ['METs'], "PF")
	process.patDefaultSequence.remove(process.patJetPartonMatch)
	process.patDefaultSequence.remove(process.patJetFlavourId)
	process.patDefaultSequence.remove(process.patJetPartons)
        process.patDefaultSequence.remove(process.patJetPartonAssociation)
	process.patDefaultSequence.remove(process.patJetFlavourAssociation)
	runOnData(process)

if not isMC:
	process.patTriggerEvent.processName = '*'
	if hasattr(process,"patTrigger"):
    		process.patTrigger.processName = '*'

#--------------------------------------------------------------------------------

#



process.source.fileNames = [   ##
    #'file:./8EE3C01B-3F6F-E311-B7B6-008CFA008CC8.root '
    #'file:/afs/cern.ch/work/r/rosma/private/Prova4/CMSSW_6_2_5/src/WHAnalysis/Configuration/test/CRAB/8EE3C01B-3F6F-E311-B7B6-008CFA008CC8.root'
    #'root://xrootd.unl.edu//store/mc/Fall13dr/GluGluToHToTauTau_M-125_13TeV-powheg-pythia6/AODSIM/tsg_PU20bx25_POSTLS162_V2-v1/00000/0432219B-2C6F-E311-9D68-001D09FDD80D.root'
    #'root://xrootd.unl.edu//store/mc/GEM2019Upg14DR/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6/AODSIM/age1k_PU140bx25_PH1_1K_FB_V1-v1/00000/08493AF9-D5E2-E311-AABD-002618943800.root'
    'root://xrootd.unl.edu//store/mc/Muon2023Upg14DR/DYToTauTau_M-20_TuneZ2star_14TeV-pythia6-tauola/AODSIM/PU140bx25_PH2_1K_FB_V2-v1/00000/00B02E1E-1BE4-E311-A1BA-003048679162.root'

    
    
    ]                                           ##  (e.g. 'file:AOD.root')
#                                               ##
process.maxEvents.input = 100                   ##  (e.g. -1 to run on all events)

print ' sono alla fine  '

process.out.outputCommands = [ #'keep *'
    'keep patMuons_muonVariables_*_*',
    'keep patElectrons_patElectrons_*_*', 
    'keep patTaus_tauVariables_*_*', 
    'keep patJets_patJets_*_*',
    'keep patMETs_patType1CorrectedPFMet_*_*',
    'keep patMETs_patType1p2CorrectedPFMet_*_*',
    'keep patMETs_patMETsPF_*_*',
    'keep patMETs_patPFMETsTypeIcorrected_*_*',
    'keep patMETs_patPFMetByMVA_*_*',
    'keep recoVertexs_offlinePrimaryVertices_*_*',
    'keep recoVertexs_offlinePrimaryVerticesWithBS_*_*',
    'keep recoVertexs_goodOfflinePrimaryVertices2_*_*',
    'keep double_rhoCorr_*_*',
    'keep double_rhoNeutral_*_*',
    'keep double_pfjets_rho_*',
    'keep double_rho_*_*',
    'keep double_rhoMuon_*_*',
    'keep double_rhoNeutralMuon_*_*',
    'keep *_TriggerResults_*_HLT',
    'keep PileupSummaryInfos_*_*_*',
    'keep *_offlineBeamSpot_*_*',
    'keep L1GlobalTriggerReadoutRecord_*_*_*',
    'keep recoPFJets_ak5PFJets_*_*',
    ]                  ##  (e.g. taken from PhysicsTools/PatAlgos/python/patEventContent_cff.py)          
if includeSim:
	process.out.outputCommands.extend(['keep *_genParticles_*_*'])
if includePatTrig:
	process.out.outputCommands.extend(['keep *_patTrigger_*_*',
					   'keep patTriggerEvent_*_*_*'])
#                                               ##
process.out.fileName = 'patTuple.root'          ##  (e.g. 'myTuple.root')
#                                               ##
process.options.wantSummary = False             ##  (to suppress the long output at the end of the job)    

#processDumpFile = open('patTuple_standard_allInOne_2013_rho_cfg.dump', 'w')
#print >> processDumpFile, process.dumpPython()
