#include "TimeOfFlightBranches.h"
#include "Exceptions.h"

#include "lcio.h"
#include "EVENT/LCCollection.h"
#include "EVENT/ReconstructedParticle.h"
#include "EVENT/Vertex.h"

#include <UTIL/LCRelationNavigator.h>
#include <UTIL/PIDHandler.h>
#include "TROOT.h"



#include <math.h>

#include "EVENT/Cluster.h"
#include "marlin/VerbosityLevels.h"


#include "TTree.h"

//PID
#include <UTIL/LCRelationNavigator.h>
#include <UTIL/PIDHandler.h>
#include "TROOT.h"

#include <math.h>

//#include "DDRec/Vector3D.h"
//PID



using namespace lcio ;





//TimeOfFlightBranches aTimeOfFlightBranches;

//TimeOfFlightBranches::TimeOfFlightBranches() : Processor("TimeOfFlightBranches") {

//}


void TimeOfFlightBranches::initBranches( TTree* tree, const std::string& pre){

 
  if( tree == 0 ){
    throw lcio::Exception("  TimeOfFlightBranches::initBranches - invalid tree pointer !!! " ) ;
  }

  if (_writeparameters) CollectionBranches::initBranches(tree, (pre+"tof").c_str());

  tree->Branch( (pre+"ntof").c_str() , &_ntof ,  (pre+"ntof/I").c_str() ) ;

 // tree->Branch( (pre+"likelihood").c_str() , &_likelihood , (pre+"likelihood["+pre+"ntof]/F").c_str() ) ;
 
  tree->Branch( (pre+"likeliPDG").c_str() , &_likeliPDG , (pre+"likeliPDG["+pre+"ntof]/F").c_str() ) ;

  tree->Branch( (pre+"likeliPID").c_str() , &_likeliPID , (pre+"likeliPID["+pre+"ntof]/F").c_str() ) ;

  tree->Branch( (pre+"TOF").c_str() , &_likeliPID , (pre+"TOF["+pre+"ntof]/F").c_str() ) ;


}
  

//void TimeOfFlightBranches::processEvent( LCEvent * evt ) 
//{

//}



void TimeOfFlightBranches::fill(const EVENT::LCCollection* rpcol, EVENT::LCEvent* evt ){

         if( !rpcol ) return ;
  
 	 if( rpcol->getTypeName() != lcio::LCIO::RECONSTRUCTEDPARTICLE ){
    
 	  std::string exStr("TimeOfFlightBranches::fill: invalid collection type : " ) ;
 	   
 	  throw EVENT::Exception( exStr + rpcol->getTypeName() ) ; 
  	}


   PIDHandler *pidh = new PIDHandler(rpcol);  

  if (_writeparameters) CollectionBranches::fill(rpcol, evt);
  
  _ntof  = rpcol->getNumberOfElements();


    for(int i=0;  i < _ntof ; ++i ){

    lcio::ReconstructedParticle* rcp = static_cast<lcio::ReconstructedParticle*>( rpcol->getElementAt( i) ) ;
  

    const ParticleID* likeliPID = &(pidh->getParticleID(rcp, pidh->getAlgorithmID("LikelihoodPID")));
    

    _likeliPDG.push_back(pidh->getParticleID(rcp, pidh->getAlgorithmID("LikelihoodPID")).getPDG()); 

 
 //   _likelihood [ i ] = likeliPID ->getParameters() [i];
  

	

    PIDHandler pidh( rpcol );
    int algoID       = pidh.getAlgorithmID( name() );
    int tof_firsthit = pidh.getParameterIndex(algoID,"TOFFirstHit") ;
    int tof_closest  = pidh.getParameterIndex(algoID,"TOFClosestHits") ;
    int tof_length   = pidh.getParameterIndex(algoID,"TOFFlightLength") ;
    int tof_trkhit   = pidh.getParameterIndex(algoID,"TOFLastTrkHit") ;
    int tof_trk_len  = pidh.getParameterIndex(algoID,"TOFLastTrkHitFlightLength") ;

      const ParticleID& tofPID = pidh.getParticleID( pfo , algoID ) ;
      
      const FloatVec& tofParams = tofPID.getParameters() ;


}
}

