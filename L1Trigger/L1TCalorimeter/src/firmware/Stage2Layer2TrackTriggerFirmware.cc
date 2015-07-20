///
/// \class l1t::Stage2Layer2TrackTriggerFirmware
///
/// \author: Tom James
///
/// Description: TrackFinder with Hough Transform

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "L1Trigger/L1TCalorimeter/interface/Stage2Layer2TrackTriggerFirmware.h"
#include "L1Trigger/L1TCalorimeter/interface/CaloTools.h"
#include "CondFormats/L1TObjects/interface/CaloParams.h"
#include "DataFormats/L1Trigger/interface/Stub.h"


l1t::Stage2Layer2TrackTriggerFirmware::Stage2Layer2TrackTriggerFirmware(CaloParams* 
params) :
  params_(params)
{
const std::vector<int> m_axis_min_= params_->MAxisMin;
const std::vector<int> m_axis_max_= params_->MAxisMax;
const std::vector<int> c_axis_min_= params_->CAxisMin;
const std::vector<int> c_axis_max_= params_->CAxisMax;
}


l1t::Stage2Layer2TrackTriggerFirmware::~Stage2Layer2TrackTriggerFirmware() {}


void l1t::Stage2Layer2TrackTriggerFirmware::processEvent(const std::vector<l1t::Stub>
 &stubs, std::vector<l1t::Stub> outstubs) 
{        

int m_size=m_axis_max_.size();
int c_size=c_axis_max_.size();
m_size=m_axis_max_.size();
c_size=c_axis_max_.size();

std::cout << "m size = " << m_size << std::endl;
std::cout << "c size = " << c_size << std::endl;

//Cell hough_array[m_size][c_size];
Cell hough_array[24][24];

for (unsigned int clk=0; clk<stubs.size();++clk){
    
for(unsigned int x=0;x<=m_axis_min_.size();++x){
for(unsigned int y=0;y<=c_axis_min_.size();++y){

std::vector<int> fifosize;
fifosize.push_back(hough_array[x-1][y+1].fifo.size());
fifosize.push_back(hough_array[x-1][y].fifo.size());
fifosize.push_back(hough_array[x-1][y-1].fifo.size());

switch (std::distance(fifosize.begin(), std::max_element(fifosize.begin(), fifosize.end())))
{
case 0:
if(hough_array[x-1][y+1].fifo.size() ==! 0){
if (nwentry(y, x, hough_array[x-1][y+1].tmp_stubs[0])){
hough_array[x][y].ram_stubs.push_back(hough_array[x-1][y+1].fifo[0]);
hough_array[x][y].fifo.push_back(hough_array[x][y].ram_stubs.back());
hough_array[x-1][y+1].fifo.erase(hough_array[x-1][y+1].fifo.begin());
}
}
break;

case 1:
if(hough_array[x-1][y].fifo.size() ==! 0){
if (wentry(y, x, hough_array[x-1][y].tmp_stubs[0])){
hough_array[x][y].ram_stubs.push_back(hough_array[x-1][y].fifo[0]);
hough_array[x][y].fifo.push_back(hough_array[x][y].ram_stubs.back());
hough_array[x-1][y].fifo.erase(hough_array[x-1][y].fifo.begin());
}
}
break;

case 2:
if(hough_array[x-1][y-1].fifo.size() ==! 0){
if (swentry(y, x, hough_array[x-1][y-1].tmp_stubs[0])){
hough_array[x][y].ram_stubs.push_back(hough_array[x-1][y-1].fifo[0]);
hough_array[x][y].fifo.push_back(hough_array[x][y].ram_stubs.back());
hough_array[x-1][y-1].fifo.erase(hough_array[x-1][y-1].fifo.begin());
}
}
break;

default:
std::cout << "ERROR FINDING FULLEST FIFO" << std::endl;
}

fifosize.clear();

//calc_c(m_array[x-1], hough_array[x][y].tmpstub.rT, hough_array[x][y].tmpstub.phiS);    

}
}
}

for(unsigned int x=1;x<=m_axis_min_.size();++x){
for(unsigned int y=1;y<=c_axis_min_.size()+1;++y){

if (hough_array[x][y].ram_stubs.size() > 4){

if(rbin_calc(hough_array[x][y].ram_stubs)){

std::cout << "candidate found at x = " <<  x << " y = " << y << std::endl;
std::cout << "stub list: phiS: dphi: z: rT" << std::endl;

for (unsigned int cand_stub=0; cand_stub < hough_array[x][y].ram_stubs.size(); ++cand_stub){
outstubs.push_back(hough_array[x][y].ram_stubs[cand_stub]);
outstubs.back().setdphi_reduced(outstubs.back().dphi() >> 3);

std::cout << outstubs.back().phiS() << "\t" << outstubs.back().dphi() << "\t" <<
outstubs.back().z() << "\t" << outstubs.back().rT() << std::endl;
}
}
}
}
}
}


