///
/// \class l1t::Stage2Layer2TrackTriggerFirmware
///
/// \author: Tom James
///
/// Description: TrackFinder with Hough Transform

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "L1Trigger/L1TCalorimeter/interface/Stage2Layer2TrackTriggerFirmware.h"
#include "L1Trigger/L1TCalorimeter/interface/CaloTools.h"

l1t::Stage2Layer2TrackTriggerFirmware::Stage2Layer2TrackTriggerFirmware(CaloParams* 
params) :
  params_(params)
{
 /* etSumEtThresholdHwEt_ = floor(params_->etSumEtThreshold(0)/params_->jetLsb());
  etSumEtThresholdHwMet_ = floor(params_->etSumEtThreshold(2)/params_->jetLsb());

  etSumEtaMinEt_ = params_->etSumEtaMin(0);
  etSumEtaMaxEt_ = params_->etSumEtaMax(0);
 
  etSumEtaMinMet_ = params_->etSumEtaMin(2);
  etSumEtaMaxMet_ = params_->etSumEtaMax(2);*/
}


l1t::Stage2Layer2TrackTriggerFirmware::~Stage2Layer2TrackTriggerFirmware() {}


void l1t::Stage2Layer2TrackTriggerFirmware::processEvent(const std::vector<l1t::Stub>
 & stubs, std::vector<l1t::OutStub> & outstubs) 
{    
    //outstubs.push_back(outstub);
    

}
