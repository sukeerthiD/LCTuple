#ifndef TimeOfFlightBranches_h
#define TimeOfFlightBranches_h 1


#include "LCTupleConf.h" 

#include "CollectionBranches.h"

#include <marlin/Processor.h>

//PID
#include <EVENT/LCCollection.h>
#include <EVENT/Track.h>
#include <EVENT/LCRelation.h>
#include <EVENT/MCParticle.h>
#include <IMPL/LCCollectionVec.h>
#include "UTIL/LCRelationNavigator.h"
#include "UTIL/LCIterator.h"
#include "UTIL/Operators.h"
#include <UTIL/BitField64.h>
#include "UTIL/LCTrackerConf.h"
#include <UTIL/BitSet32.h>

#include <TTree.h>
//PID



class TTree ;

namespace EVENT{
  class LCCollection ;
  class LCCEvent ;
}


class TimeOfFlightBranches : public CollectionBranches {
  
public:
  
  //TimeOfFlightBranches() {} ;
  
  virtual void initBranches( TTree* tree, const std::string& prefix="" ) ; //const char*  prefix=0) ;

  virtual void fill(const EVENT::LCCollection* col, EVENT::LCEvent* evt ) ;
  
  virtual ~TimeOfFlightBranches() {} ;

  

private:
  
  int   _ntof ;



 // std::vector<float> _likelihood [ LCT_TIMEOFFLIGHT_MAX ] ;

 // std::vector<float> _likelihood{};
  std::vector<int> _likeliPDG{};
  std::vector<int> _likeliPID{};

} ;

#endif





//#ifndef TimeOfFlightBranches_h
//#define TimeOfFlightBranches_h 1

//#include "LCTupleConf.h" 

//#include "CollectionBranches.h"


//class TTree ;

//namespace EVENT{
//  class LCCollection ;
//  class LCCEvent ;
//}



//class TimeOfFlightBranches : public CollectionBranches {
  
//public:
//  TimeOfFlightBranches() {} ;
//  virtual void initBranches( TTree* tree, const std::string& prefix="" ) ; //const char*  prefix=0) ;
//    virtual void fill(const EVENT::LCCollection* col, EVENT::LCEvent* evt ) ;
//  virtual ~TimeOfFlightBranches() {} ;

//private:
//  int    _ntof   ;
//  int    _tofori[ LCT_TIMEOFFLIGHT_MAX ] ;
//} ;

//#endif
