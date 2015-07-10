#ifndef DataFormats_L1TCalorimeter_OutStub_h
#define DataFormats_L1TCalorimeter_OutStub_h


#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"

namespace l1t {
  
  class OutStub;
  typedef BXVector<OutStub> OutStubBxCollection;
  
	class OutStub : public L1Candidate {

    
  public:
    
    OutStub(){}

    
    OutStub( 
    const LorentzVector& p4,
       int pt=0,
       int eta=0,
       int phi=0,
       int qual=0
    );
	    
	OutStub( const PolarLorentzVector& p4,
       int pt=0,
       int eta=0,
       int phi=0,
       int qual=0);
    
    ~OutStub();

    

  private:

    
  };
  
}

#endif
