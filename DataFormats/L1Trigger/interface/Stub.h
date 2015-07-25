#ifndef DataFormats_L1TCalorimeter_Stub_h
#define DataFormats_L1TCalorimeter_Stub_h

#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"

namespace l1t {
  class Cell;
  class Stub;
  typedef BXVector<Stub> StubBxCollection;
    typedef BXVector<Stub> OutStubBxCollection;
    
    //class Stub : public L1Candidate {
        class Stub{


    
 public:    

  
    
  Stub(
               unsigned int S=0,
               int phiS=0,
               int rT=0,
               int z=0,
         int dphi=0,
        unsigned int rho=0,
         int dphi_reduced=0,
         unsigned int m_coordinate=0,
         unsigned int c_coordinate=0

         );
    
  ~Stub();

    void setS(unsigned int et) { S_ = et;}
  void setphiS( int et) { phiS_ = et;}
  void setrT( int et ) { rT_ = et;}
  void setz( int et ) { z_ = et;}
  void setdphi( int et ) { dphi_ = et;}
  void setrho(unsigned int et) { rho_ = et;}
void setdphi_reduced(int et) { dphi_reduced_ = et;}
  void setm_coordinate(unsigned int et) { m_coordinate_ = et;}
  void setc_coordinate(unsigned int et) { c_coordinate_ = et;}


  unsigned  int S()            const{   return S_;     }
  int phiS()           const{   return phiS_;    }
  int rT()              const{   return rT_;       }
  int z()           const{   return z_;    }
  int dphi()             const{   return dphi_;      }
 unsigned int rho()           const{   return rho_;     }
  int dphi_reduced()        const{   return dphi_reduced_; }
 unsigned int m_coordinate()            const{   return m_coordinate_;     }
unsigned int c_coordinate()            const{   return c_coordinate_;     }




 private:
  
    unsigned S_;
  int phiS_;
  int rT_;
  int z_; 
  int dphi_;
  unsigned rho_;
  int dphi_reduced_;
  unsigned m_coordinate_;
  unsigned c_coordinate_;

  
};
  }


#endif
 
