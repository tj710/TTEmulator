#include "DataFormats/L1Trigger/interface/Stub.h"




l1t::Stub::Stub(
                               unsigned int S,
                                int phiS,
                                int rT,
                                int z,
        int dphi,
        unsigned int rho,
        int dphi_reduced,
       unsigned int m_coordinate,
       unsigned int c_coordinate

                                )
  : 
    S_(S),
    phiS_(phiS),
    rT_(rT),
    z_(z),
    dphi_(dphi),
    rho_(rho),
    dphi_reduced_(dphi_reduced),
    m_coordinate_(m_coordinate),
    c_coordinate_(c_coordinate)

{
  
}

l1t::Stub::~Stub() 
{

}

 
