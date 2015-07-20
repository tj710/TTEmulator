#ifndef DataFormats_L1TCalorimeter_Stub_h
#define DataFormats_L1TCalorimeter_Stub_h

#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"

namespace l1t {
  
  class Stub;
  typedef BXVector<Stub> StubBxCollection;
    typedef BXVector<Stub> OutStubBxCollection;
    
    //class Stub : public L1Candidate {
        class Stub{


    
 public:    

  
    
  Stub(
               int S=0,
               int phiS=0,
               int rT=0,
               int z=0,
         int dphi=0,
         int rho=0,
         int dphi_reduced=0,
         int m=0,
         int c=0

         );
    
  ~Stub();

    void setS(int et) { S_ = et;}
  void setphiS( int et) { phiS_ = et;}
  void setrT( int et ) { rT_ = et;}
  void setz( int et ) { z_ = et;}
  void setdphi( int et ) { dphi_ = et;}
  void setrho(int et) { rho_ = et;}
void setdphi_reduced(int et) { dphi_reduced_ = et;}
  void setm(int et) { m_ = et;}
  void setc(int et) { c_ = et;}


    int S()            const{   return S_;     }
  int phiS()           const{   return phiS_;    }
  int rT()              const{   return rT_;       }
  int z()           const{   return z_;    }
  int dphi()             const{   return dphi_;      }
  int rho()           const{   return rho_;     }
  int dphi_reduced()        const{   return dphi_reduced_; }
  int m()            const{   return m_;     }
int c()            const{   return c_;     }




 private:
  
    int S_;

  int phiS_;
  int rT_;
  int z_; 
  int dphi_;
  int rho_;
  int dphi_reduced_;
  int m_;
  int c_;

  
};
  }


#endif
 
