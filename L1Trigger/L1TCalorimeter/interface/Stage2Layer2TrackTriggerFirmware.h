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

class Stage2Layer2TrackTriggerFirmware;
  class Stage2Layer2TrackTriggerFirmware : public Stage2Layer2TrackTrigger {
  CaloParams* params_;
  
 std::vector<int> m_axis_max_;
 std::vector<int> m_axis_min_;
 std::vector<int> m_axis_av_;

 std::vector<int> c_axis_max_;
std::vector<int> c_axis_min_;
std::vector<int> c_axis_av_;

int T_;

  public:
    Stage2Layer2TrackTriggerFirmware(CaloParams* params);
    virtual ~Stage2Layer2TrackTriggerFirmware();
    virtual void processEvent(const std::vector<l1t::Stub> & stubs, 
    std::vector<l1t::Stub> outstubs);

void readout_cell(Cell cell, int x, int y, std::vector<l1t::Stub> outstubs){

if (cell.ram_stubs.size() > 4){

//Should be fixed to match firmware marking of cell
if(rbin_calc(cell.ram_stubs)){

std::cout << "candidate found at x = " <<  x << " y = " << y << std::endl;
std::cout << "stub list: phiS: dphi: z: rT" << std::endl;

for (unsigned int cand_stub=0; cand_stub < cell.ram_stubs.size(); ++cand_stub){
std::cout << cell.ram_stubs.back().phiS() << "\t" << cell.ram_stubs.back().dphi() << "\t" <<
cell.ram_stubs.back().z() << "\t" << cell.ram_stubs.back().rT() << std::endl;
}
}
}

for (unsigned int segment=0; segment<48; ++segment){
for (unsigned int int_stub=0; int_stub<cell.ram_stubs.size(); ++int_stub){

if(cell.ram_stubs.at(int_stub).S()==segment){
outstubs.push_back(cell.ram_stubs.at(int_stub));
}

}
}
}

bool bend_filter(Cell cell, Stub stub, const int T)
{
int test = (stub.rT()+T)*cell.mav();
if (std::abs(test) < stub.rho()){
return true;
}
return false;
}

bool ifstore(Cell cell, Stub stub)
{
int test_min = cell.fifo_nwest[0].phiS() - 
(stub.rT())*(cell.mmin());
int test_max = cell.fifo_nwest[0].phiS() -
 (stub.rT())*(cell.mmax());
if((test_min> int(cell.cmax()) || test_min< int(cell.cmax()))&&
(test_max>int(cell.cmin()) && test_max<int(cell.cmax()))){
return true;
}
return false;
}

bool rbin_calc(std::vector<Stub> stubs){
std::vector<int> r_register(16, 0);

for(unsigned int stub =0; stub<stubs.size(); ++stub){

if (stubs[stub].rT() < 33 ){r_register[0]=1; continue;}
if (stubs[stub].rT() < 65 ){r_register[1]=1; continue;}
if (stubs[stub].rT() < 96 ){r_register[2]=1; continue;}
if (stubs[stub].rT() < 129 ){r_register[3]=1; continue;}
if (stubs[stub].rT() < 161 ){r_register[4]=1; continue;}
if (stubs[stub].rT() < 193 ){r_register[5]=1; continue;}
if (stubs[stub].rT() < 225 ){r_register[6]=1; continue;}
if (stubs[stub].rT() < 257 ){r_register[7]=1; continue;}
if (stubs[stub].rT() < 289 ){r_register[8]=1; continue;}
if (stubs[stub].rT() < 321 ){r_register[9]=1; continue;}
if (stubs[stub].rT() < 353 ){r_register[10]=1; continue;}
if (stubs[stub].rT() < 385 ){r_register[11]=1; continue;}
if (stubs[stub].rT() < 417 ){r_register[12]=1; continue;}
if (stubs[stub].rT() < 449 ){r_register[13]=1; continue;}
if (stubs[stub].rT() < 481 ){r_register[14]=1; continue;}
if (stubs[stub].rT() < 513 ){r_register[15]=1; continue;}
std::cout << "ERROR: rT outside range" << std::endl;

}
if (std::accumulate(r_register.begin(), r_register.end(), 0) > 4){
return true;}
return false;
}
     
  };
  
}

#endif
