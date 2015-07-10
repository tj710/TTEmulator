///
/// Description: Firmware header Track Trigger
///
///
/// \author: Tom James
///

//
//

#ifndef Stage2Layer2TrackTriggerFirmware_H
#define Stage2Layer2TrackTriggerFirmware_H

#include "L1Trigger/L1TCalorimeter/interface/Stage2Layer2TrackTrigger.h"
#include "CondFormats/L1TObjects/interface/CaloParams.h"

namespace l1t {
  class Stage2Layer2TrackTriggerFirmware : public Stage2Layer2TrackTrigger {
  public:
    Stage2Layer2TrackTriggerFirmware(CaloParams* params);
    virtual ~Stage2Layer2TrackTriggerFirmware();
    virtual void processEvent(const std::vector<l1t::Stub> & stubs, 
    std::vector<l1t::OutStub> & outstubs);
  private:
    CaloParams* params_;
   /* int32_t etSumEtThresholdHwEt_;
    int32_t etSumEtThresholdHwMet_; 
    int32_t etSumEtaMinEt_;
    int32_t etSumEtaMaxEt_;
    int32_t etSumEtaMinMet_;
    int32_t etSumEtaMaxMet_;*/

  };
  
}

#endif
