#include "DataFormats/L1Trigger/interface/Stub.h"




l1t::Stub::Stub(
                                int S,
                                int phiS,
                                int rT,
                                int z,
        int dphi,
        int rho,
        int dphi_reduced,
        int m,
        int c

                                )
  : 
    S_(S),
    phiS_(phiS),
    rT_(rT),
    z_(z),
    dphi_(dphi),
    rho_(rho),
    dphi_reduced_(dphi_reduced),
    m_(m),
    c_(c)

{
  
}

l1t::Stub::~Stub() 
{

}

 
