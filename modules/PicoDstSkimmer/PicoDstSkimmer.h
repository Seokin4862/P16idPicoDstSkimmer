#ifndef PICO_DST_SKIMMER_H
#define PICO_DST_SKIMMER_H

#include "TreeAnalyzer.h"

#include "FemtoDstFormat/BranchReader.h"
#include "FemtoDstFormat/TClonesArrayReader.h"


#include "PicoDstP16id/StPicoEvent.h"
#include "PicoDstP16id/StPicoMtdHit.h"
#include "PicoDstP16id/StPicoTrack.h"
#include "PicoDstP16id/StPicoMtdPidTraits.h"
#include "PicoDstP16id/StPicoBTofPidTraits.h"

#include "vendor/loguru.h"

class PicoDstSkimmer : public TreeAnalyzer
{
public:
	const int DEBUG = 1;
	PicoDstSkimmer() {}
	~PicoDstSkimmer() {}

	virtual void initialize(){
		TreeAnalyzer::initialize();

		_rEvent.setup( this->chain, "Event" );
		_rMtdHit.setup( this->chain, "MtdHit" );
		_rTrack.setup( this->chain, "Tracks" );
		_rMtdPid.setup( this->chain, "MtdPidTraits" );
		_rBTofPid.setup( this->chain, "BTofPidTraits" );

		book->cd();

		makeHistograms();
	}
protected:

	TClonesArrayReader < StPicoEvent        > _rEvent;
	TClonesArrayReader < StPicoMtdHit       > _rMtdHit;
	TClonesArrayReader < StPicoTrack        > _rTrack;
	TClonesArrayReader < StPicoMtdPidTraits > _rMtdPid;
	TClonesArrayReader < StPicoBTofPidTraits > _rBTofPid;

	TH1D *hdEdx = 0;
	TH1D *hphi = 0;

	TH1D

	void makeHistograms(){

		hdEdx = new TH1D( "dEdx", "dE/dx of Various Tracks; dE/dx; counts", 1000, 0, 30 );
		hphi = new TH1D( "phi", "phi of Various Tracks; x-axis; y-axis", 1000, -3.2, 3.2 );

		hDedxvsMom = new TH2D( "dE/dx vs Total Momentum of Various Tracks; Total Momentum; dE/dx", 1000, -100, 100, 1000, 0, 100 )

	}


	virtual void analyzeEvent() {
		StPicoEvent *event = _rEvent.get( 0 );

		if ( nullptr == event ){
			return;
		}

		size_t nTracks =  _rTrack.N();
		for ( size_t i = 0; i < nTracks; i++ ){
			StPicoTrack * track = _rTrack.get( i );

			if( track->pMom().mag() < .3 ) continue;
			if( track->pMom().mag() > .4 ) continue;

			hdEdx->Fill( track->dEdx() );
			hphi->Fill( track->pMom().phi() );

			hdEdx->Fill( track->pMom(), track->dEdx() );

			//if( track->charge() > 0 ){
				//hDedxphi01->Fill( track->pMom().phi() , track->dEdx() );
				//if( track->pMom().pseudoRapidity() < 0 ){
					//hDedxphi02->Fill( track->pMom().phi() , track->dEdx() );
				//}
				//if( track->pMom().pseudoRapidity() > 0 ){
					//hDedxphi03->Fill( track->pMom().phi() , track->dEdx() );
				//}
			//}
			//LOG_F( INFO, "dedx = %f", track->dEdx() );
			//LOG_F( INFO, "phi = %f", track->pMom().phi() );
		}

		// LOG_IF_F( INFO, DEBUG, "RunId: %d", event->runId() );
		// LOG_IF_F( INFO, DEBUG, "#Tracks: %u", _rTrack.N() );
		// LOG_IF_F( INFO, DEBUG, "#MtdHits: %u", _rMtdHit.N() );
		// LOG_IF_F( INFO, DEBUG, "#MtdPids: %u", _rMtdPid.N() );



	}

};


#endif
