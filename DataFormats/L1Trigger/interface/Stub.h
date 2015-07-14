#ifndef DataFormats_L1TCalorimeter_Stub_h
#define DataFormats_L1TCalorimeter_Stub_h


#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"

namespace l1t {
  
  class Stub;
  typedef BXVector<Stub> StubBxCollection;
    typedef BXVector<Stub> OutStubBxCollection;

  
	class Stub : public L1Candidate {

    
  public:
    
        int S, phiS, rT, z, dphi, rho, dphi_reduced, m, c;

   // void set_values(int, int, int, int, int, int);
    
    
    Stub(){}
    
    ~Stub();
    
/*void set_values(int S_, int phiS_, int rT_, int z_, int dphi_, int rho_){
S=S_;
phiS=phiS_;
rT=rT_;
z=z_;
dphi=dphi_;
rho=rho_;
}  */
    

  private:

    
  };
  

}

#endif
