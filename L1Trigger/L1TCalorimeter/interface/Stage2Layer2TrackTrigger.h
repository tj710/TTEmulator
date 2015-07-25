///
/// \class l1t::Stage2Layer2TrackTrigger
///
/// Description: interface for MP firmware - Track trigger
///
///
/// \author: Tom James
///

#ifndef Stage2Layer2TrackTrigger_h
#define Stage2Layer2TrackTrigger_h

#include "DataFormats/L1TCalorimeter/interface/CaloTower.h"

#include "DataFormats/L1Trigger/interface/EtSum.h"

//#include "DataFormats/L1Trigger/interface/Stub.h"

#include "DataFormats/L1Trigger/interface/Cell.h"




#include <vector>

namespace l1t {
    
  class Stage2Layer2TrackTrigger { 
  public:
    virtual void processEvent(const std::vector<l1t::Stub> & stubs, 
    std::vector<l1t::Stub> outstubs) = 0;    

    virtual ~Stage2Layer2TrackTrigger(){};
  }; 
  
} 

#endif
