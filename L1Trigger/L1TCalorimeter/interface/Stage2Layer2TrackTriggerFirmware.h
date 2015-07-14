///
/// Description: Firmware header Track Trigger
///
///
/// \author: Tom James
///

//
//

#ifndef Stage2Layer2TrackTriggerFirmware_H
#define Stage2Layer2TrackTriggerFirmware_H

#include "L1Trigger/L1TCalorimeter/interface/Stage2Layer2TrackTrigger.h"
#include "CondFormats/L1TObjects/interface/CaloParams.h"

namespace l1t {
  class Stage2Layer2TrackTriggerFirmware : public Stage2Layer2TrackTrigger {
  public:
    Stage2Layer2TrackTriggerFirmware(CaloParams* params);
    virtual ~Stage2Layer2TrackTriggerFirmware();
    virtual void processEvent(const std::vector<l1t::Stub> & stubs, 
    std::vector<l1t::Stub> outstubs);
    
bool nwentry(int y, int x, Stub stub)
{
int test = (stub.phiS - c_axis_max_[y])/stub.rT;
if(test>m_axis_min_[x] && test<m_axis_max_[x]){
return true;
}
return false;
}
       
bool swentry(int y, int x, Stub stub)
{
int test = (stub.phiS - c_axis_min_[y])/stub.rT;
if(test>m_axis_min_[x] && test<m_axis_max_[x]){
return true;
}
return false;
}

bool wentry(int y, int x, Stub stub)
{
int test_min = stub.phiS - (stub.rT)*(m_axis_min_[x]);
int test_max = stub.phiS - (stub.rT)*(m_axis_max_[x]);
if((test_min>c_axis_min_[y] && test_min<c_axis_max_[y])&&
(test_max>c_axis_min_[y] && test_max<c_axis_max_[y])){
return true;
}
return false;
}

bool rbin_calc(std::vector<Stub> stubs){
std::vector<int> r_register(16, 0);

for(unsigned int stub =0; stub<stubs.size(); ++stub){

if (stubs[stub].rT < 33 ){r_register[0]=1; continue;}
if (stubs[stub].rT < 65 ){r_register[1]=1; continue;}
if (stubs[stub].rT < 96 ){r_register[2]=1; continue;}
if (stubs[stub].rT < 129 ){r_register[3]=1; continue;}
if (stubs[stub].rT < 161 ){r_register[4]=1; continue;}
if (stubs[stub].rT < 193 ){r_register[5]=1; continue;}
if (stubs[stub].rT < 225 ){r_register[6]=1; continue;}
if (stubs[stub].rT < 257 ){r_register[7]=1; continue;}
if (stubs[stub].rT < 289 ){r_register[8]=1; continue;}
if (stubs[stub].rT < 321 ){r_register[9]=1; continue;}
if (stubs[stub].rT < 353 ){r_register[10]=1; continue;}
if (stubs[stub].rT < 385 ){r_register[11]=1; continue;}
if (stubs[stub].rT < 417 ){r_register[12]=1; continue;}
if (stubs[stub].rT < 449 ){r_register[13]=1; continue;}
if (stubs[stub].rT < 481 ){r_register[14]=1; continue;}
if (stubs[stub].rT < 513 ){r_register[15]=1; continue;}
std::cout << "ERROR: rT outside range" << std::endl;

}
if (std::accumulate(r_register.begin(), r_register.end(), 0) > 4){
return true;}
return false;
}
 
private:
    CaloParams* params_;
    
struct Cell {

    std::vector<Stub> ram_stubs;
    std::vector<Stub> tmp_stubs;
    std::vector<Stub> fifo;

};

const std::vector<int> m_axis_max_;
const std::vector<int> m_axis_min_;

const std::vector<int> c_axis_max_;
const std::vector<int> c_axis_min_;

  };
  
}

#endif
