

#include "DataFormats/L1Trigger/interface/OutStub.h"

l1t::OutStub::OutStub( const LorentzVector& p4,
	       int pt,
	       int eta,
	       int phi,
	       int qual )
  : L1Candidate(p4, pt, eta, phi, qual, 0)
{

}

l1t::OutStub::OutStub( const PolarLorentzVector& p4,
	       int pt,
	       int eta,
	       int phi,
	       int qual )
  : L1Candidate(p4, pt, eta, phi, qual, 0)
{

}

l1t::OutStub::~OutStub()
{

}
