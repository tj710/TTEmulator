import FWCore.ParameterSet.Config as cms

l1tRawToDigi = cms.EDProducer(
    "L1TRawToDigi",
    Setup = cms.string("stage2::CaloSetup"),
    InputLabel = cms.InputTag("l1tDigiToRaw"),
    FedId = cms.int32(1352),
    FWId = cms.uint32(0x1),
    lenSlinkHeader = cms.untracked.int32(8),
    lenSlinkTrailer = cms.untracked.int32(8),
    lenAMCHeader = cms.untracked.int32(8),
    lenAMCTrailer = cms.untracked.int32(0),
    lenAMC13Header = cms.untracked.int32(8),
    lenAMC13Trailer = cms.untracked.int32(8)
)
