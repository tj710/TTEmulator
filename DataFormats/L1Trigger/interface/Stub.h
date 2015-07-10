#ifndef DataFormats_L1TCalorimeter_Stub_h
#define DataFormats_L1TCalorimeter_Stub_h


#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"

namespace l1t {
  
  class Stub;
  typedef BXVector<Stub> StubBxCollection;
  
	class Stub : public L1Candidate {

    
  public:
    
    Stub(){}

    
    Stub( 
    const LorentzVector& p4,
       int pt=0,
       int eta=0,
       int phi=0,
       int qual=0
    );
	    
	Stub( const PolarLorentzVector& p4,
       int pt=0,
       int eta=0,
       int phi=0,
       int qual=0);
    
    ~Stub();

    

  private:

    
  };
  
}

#endif
