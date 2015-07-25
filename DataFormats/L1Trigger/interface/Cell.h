#ifndef DataFormats_L1TCalorimeter_Cell_h
#define DataFormats_L1TCalorimeter_Cell_h

#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"
#include "DataFormats/L1Trigger/interface/Stub.h"


namespace l1t {
class Stub;

class Cell{

     int mmax_;
     int mmin_;
     int mav_;
    unsigned int cmax_; 
    unsigned int cmin_; 
    unsigned int cav_;
    unsigned int c_coord_; 
    unsigned int m_coord_;
    
 public:    

  /*Cell(
     std::vector<Stub> ram_stubs,
      std::vector<Stub> fifo_entry, 
      std::vector<Stub> fifo_west, 
      std::vector<Stub> fifo_nwest, 
      std::vector<Stub> fifo_swest,
     int mmax, 
     int mmin,
     int mav, 
    unsigned int cmax, 
    unsigned int cmin, 
    unsigned int cav,
    unsigned int m_coord, 
    unsigned int c_coord
         );*/
    
  ~Cell();

      std::vector<Stub> ram_stubs;
      std::vector<Stub> fifo_entry; 
      std::vector<Stub> fifo_west; 
      std::vector<Stub> fifo_nwest; 
      std::vector<Stub> fifo_swest;
      
void setmmax( int et) { mmax_ = et;}
  void setmmin( int et) { mmin_ = et;}
  void setmav( int et ) { mav_ = et;}
  void setcmax( unsigned int et ) { cmax_ = et;}
  void setcmin( unsigned int et ) { cmin_ = et;}
  void setcav(unsigned int et) { cav_ = et;}
    void setm_coord( unsigned int et ) { c_coord_ = et;}
  void setc_coord(unsigned int et) { m_coord_ = et;}

    int mmax()            const{   return mmax_;     }
   int mmin()           const{   return mmin_;    }
   int mav()              const{   return mav_;       }
  unsigned int cmax()           const{   return cmax_;    }
  unsigned int cmin()             const{   return cmin_;      }
  unsigned int cav()             const{   return cav_;      }
  unsigned int c_coord()             const{   return c_coord_;      }
  unsigned int m_coord()             const{   return m_coord_;      }


        


  
};
  }


#endif
 
