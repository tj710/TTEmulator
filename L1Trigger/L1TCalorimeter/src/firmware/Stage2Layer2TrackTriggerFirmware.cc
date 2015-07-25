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


l1t::Stage2Layer2TrackTriggerFirmware::Stage2Layer2TrackTriggerFirmware(CaloParams* 
params) :
  params_(params)
{

m_axis_min_= params_->MAxisMin;
m_axis_max_= params_->MAxisMax;
m_axis_av_= params_->MAxisMav;

c_axis_min_= params_->CAxisMin;
c_axis_max_= params_->CAxisMax;
c_axis_av_= params_->CAxisMav;
T_ = params_->T;

}


l1t::Stage2Layer2TrackTriggerFirmware::~Stage2Layer2TrackTriggerFirmware() {}


void l1t::Stage2Layer2TrackTriggerFirmware::processEvent(const std::vector<l1t::Stub>
 &stubs, std::vector<l1t::Stub> outstubs) 
{     

//for(unsigned int nboards; nboards<nboards_; ++nboards){

//l1t::HoughArrayAxis axis;

/*axis.set_values(m_axis_max_, m_axis_min_, m_axis_mav_,
c_axis_max_, c_axis_min_, c_axis_mav_);*/

/*////set array size variables////*/
unsigned int m_size=m_axis_min_.size();
unsigned int c_size=c_axis_min_.size();
std::cout << "m size = " << m_size << std::endl;
std::cout << "c size = " << c_size << std::endl;

/*///initialise array///*/
//x vector first, then y vector second
std::vector<std::vector<Cell>> hough_array(m_size,
 std::vector<Cell>(c_size));

/*///initialise cell variable///*/
Cell cell;
   
/*///set m, c and m_coord, c_coord for all cells in array//*/
for(unsigned int y=0; y<c_size; ++y){
for(unsigned int x=0; x<m_size; ++x){
hough_array.at(x).at(y).setcmin(c_axis_min_.at(y));
hough_array.at(x).at(y).setcmax(c_axis_max_.at(y));
hough_array.at(x).at(y).setcav(c_axis_av_.at(y));
hough_array.at(x).at(y).setmmin(m_axis_min_.at(x));
hough_array.at(x).at(y).setmmax(m_axis_max_.at(x));
hough_array.at(x).at(y).setmav(m_axis_av_.at(x));
hough_array.at(x).at(y).setm_coord(x);
hough_array.at(x).at(y).setc_coord(y);
}
}
   
/***initialise stub iterator****/
std::vector<l1t::Stub>::const_iterator stub;

for (stub=stubs.begin(); stub!=stubs.end(); stub++){

/*****************************/
/*Now begin input to array*/
/*****************************/

////west cntrl

for (unsigned int y=0; y< c_size; ++y){
Cell cell = hough_array.at(0).at(y);
int c_max_stub = stub->phiS() - (stub->rT()*cell.mmax());
int c_min_stub = stub->phiS() - (stub->rT()*cell.mmin());
if((c_max_stub < int(cell.cmax())
 && c_max_stub > int(cell.cmin())) ||
(c_min_stub < int(cell.cmax()) && c_min_stub > 
int(cell.cmin())) || stub->S()>47){
hough_array.at(0).at(y).fifo_entry.push_back(*stub);
}
}

////north cntrl
if (stub->S() <48){
for (unsigned int x=0; x< m_size; ++x){
//int inv_r(stub->rT());
int m_stub = (stub->phiS() - hough_array.at(0).back().cmax())
/(stub->rT()); //need to fix to make like lut
if(m_stub < hough_array.at(x).at(0).mmax() && m_stub > hough_array.at(x).at(0).mmin()){
hough_array.at(0).at(c_size).fifo_entry.push_back(*stub);
}
}
}

////south cntrl
if (stub->S() <48){
for (unsigned int x=0; x< m_size; ++x){
//int inv_r(stub->rT());
int m_stub = (stub->phiS() - hough_array.at(0).front().cmax())
/(stub->rT()); //need to fix to make like lut
if(m_stub < hough_array.at(x).at(0).mmax() && 
m_stub > hough_array.at(x).at(0).mmin()){
hough_array.at(0).at(0).fifo_entry.push_back(*stub);
}
}
}
    
for(unsigned int x=0;x<m_size;++x){
for(unsigned int y=0;y<c_size;++y){

if(x==0 && hough_array[x][y].fifo_entry.size()!=0){
hough_array.at(x).at(y).ram_stubs.push_back(hough_array.at(x).at(y).fifo_entry.front());
hough_array.at(x+1).at(y+1).fifo_swest.push_back(hough_array.at(x).at(y).ram_stubs.back());
hough_array.at(x+1).at(y).fifo_west.push_back(hough_array.at(x).at(y).ram_stubs.back());
hough_array.at(x+1).at(y-1).fifo_nwest.push_back(hough_array.at(x).at(y).ram_stubs.back());
}
if((y+1)==c_size && hough_array[x][y].fifo_entry.size()!=0){
hough_array[x][y].ram_stubs.push_back(hough_array[x][y].fifo_entry.front());
hough_array[x+1][y].fifo_west.push_back(hough_array[x][y].ram_stubs.back());
hough_array[x+1][y-1].fifo_nwest.push_back(hough_array[x][y].ram_stubs.back());
}
if(y==0 && hough_array[x][y].fifo_entry.size()!=0){
hough_array[x][y].ram_stubs.push_back(hough_array[x][y].fifo_entry.front());
hough_array[x+1][y+1].fifo_swest.push_back(hough_array[x][y].ram_stubs.back());
hough_array[x+1][y].fifo_west.push_back(hough_array[x][y].ram_stubs.back());
hough_array[x][y].fifo_entry.erase(hough_array[x][y].fifo_entry.begin());
}

/*****************************/
/*Now begin inside array loop*/
/*****************************/

/***** Need vector of fifo sizes to calculate fullest fifo **/
/*** If draw go in NorthW, West, SouthW order ******/
std::vector<int> fifosize;
fifosize.push_back(hough_array[x][y].fifo_nwest.size());
fifosize.push_back(hough_array[x][y].fifo_west.size());
fifosize.push_back(hough_array[x][y].fifo_swest.size());

//make priority of fake stub last
/*if(hough_array[x][y].fifo_nwest[0].S()>47){
hough_array[x][y].fifo_nwest.push_back(hough_array[x][y].fifo_nwest[0]);
hough_array[x][y].fifo_nwest.erase(hough_array[x][y].fifo_nwest.begin());
}*/
if(hough_array[x][y].fifo_west[0].S()>47){
hough_array[x][y].fifo_west.push_back(hough_array[x][y].fifo_west[0]);
hough_array[x][y].fifo_west.erase(hough_array[x][y].fifo_west.begin());
}
/*if(hough_array[x][y].fifo_swest[0].S()>47){
hough_array[x][y].fifo_swest.push_back(hough_array[x][y].fifo_swest[0]);
hough_array[x][y].fifo_swest.erase(hough_array[x][y].fifo_swest.begin());
}*/
//max element returns iterator to first such element if they are equivalent greatest
//this is equivalent to choosing nwest first, then west, then swest
//returns last element if empty, fine because it is 0 so will do nothing
switch (std::distance(fifosize.begin(), std::max_element(fifosize.begin(), 
fifosize.end())))
{
case 0:
if(hough_array[x][y].fifo_nwest.size() > 0){
if (ifstore(hough_array[x][y], hough_array[x][y].fifo_nwest[0])){
if(bend_filter(hough_array[x][y], hough_array[x][y].fifo_nwest[0], T_)){
hough_array[x][y].ram_stubs.push_back(hough_array[x][y].fifo_nwest[0]);}
hough_array[x+1][y].fifo_west.push_back(hough_array[x][y].ram_stubs.back());
if(y!=0){
hough_array[x+1][y-1].fifo_nwest.push_back(hough_array[x][y].ram_stubs.back());}
}
hough_array[x][y].fifo_nwest.erase(hough_array[x][y].fifo_nwest.begin());
}
break;

case 1:
if(hough_array[x][y].fifo_swest.at(0).S()>47){
readout_cell(hough_array[x][y], x, y, outstubs);
break;}

if(hough_array[x][y].fifo_west.size() > 0){
if (ifstore(hough_array[x][y], hough_array[x][y].fifo_west[0])){
if(bend_filter(hough_array[x][y], hough_array[x][y].fifo_west[0], T_)){
hough_array[x][y].ram_stubs.push_back(hough_array[x][y].fifo_west[0]);}
if((y+1)!=c_size){
hough_array[x+1][y+1].fifo_swest.push_back(hough_array[x][y].ram_stubs.back());}
hough_array[x+1][y].fifo_west.push_back(hough_array[x][y].ram_stubs.back());
if(y!=0){
hough_array[x+1][y-1].fifo_nwest.push_back(hough_array[x][y].ram_stubs.back());}
}
hough_array[x][y].fifo_west.erase(hough_array[x][y].fifo_west.begin());
}
break;

case 2:
if(hough_array[x][y].fifo_swest.size() > 0){
if (ifstore(hough_array[x][y], hough_array[x][y].fifo_swest[0])){
if(bend_filter(hough_array[x][y], hough_array[x][y].fifo_swest[0], T_)){
hough_array[x][y].ram_stubs.push_back(hough_array[x][y].fifo_swest[0]);}
hough_array[x+1][y].fifo_west.push_back(hough_array[x][y].ram_stubs.back());
if((y+1)!=c_size){
hough_array[x+1][y+1].fifo_swest.push_back(hough_array[x][y].ram_stubs.back());}
}
hough_array[x][y].fifo_swest.erase(hough_array[x][y].fifo_swest.begin());
}
break;

default:
std::cout << "ERROR FINDING FULLEST FIFO" << std::endl;
}

fifosize.clear();

}
}
}
}


