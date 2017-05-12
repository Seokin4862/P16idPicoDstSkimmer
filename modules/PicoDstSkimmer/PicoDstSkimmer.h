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

	TH1D *hDedx = 0;
	TH1D *hphi = 0;

	TH2D *hDedxphi1 = 0;
	TH2D *hDedxphi2 = 0;
	TH2D *hDedxphi3 = 0;

	TH2D *hDedxphi4 = 0;
	TH2D *hDedxphi5 = 0;
	TH2D *hDedxphi6 = 0;

	TH2D *hDedxphi7 = 0;
	TH2D *hDedxphi8 = 0;
	TH2D *hDedxphi9 = 0;

	void makeHistograms(){

		hDedx = new TH1D( "dEdx", "dEdx of Various Tracks; x-axis; y-axis", 1000, 0, 30 );
		hphi = new TH1D( "phi", "phi of Various Tracks; x-axis; y-axis", 1000, -3.2, 3.2 );

		hDedxphi1 = new TH2D( "dEdxphi1", " dEdx vs phi for (+) tracks of #eta -1 to 1; dEdx; phi", 1000, -3.2, 3.2, 1000, 0, 15 );
		hDedxphi2 = new TH2D( "dEdxphi2", " dEdx vs phi for (+) tracks of #eta -1 to 0; dEdx; phi", 1000, -3.2, 3.2, 1000, 0, 15 );
		hDedxphi3 = new TH2D( "dEdxphi3", " dEdx vs phi for (+) tracks of #eta  0 to 1; dEdx; phi", 1000, -3.2, 3.2, 1000, 0, 15 );

		hDedxphi4 = new TH2D( "dEdxphi4", " dEdx vs phi for (-) tracks of #eta -1 to 1; dEdx; phi", 1000, -3.2, 3.2, 1000, 0, 15 );
		hDedxphi5 = new TH2D( "dEdxphi5", " dEdx vs phi for (-) tracks of #eta -1 to 0; dEdx; phi", 1000, -3.2, 3.2, 1000, 0, 15 );
		hDedxphi6 = new TH2D( "dEdxphi6", " dEdx vs phi for (-) tracks of #eta  0 to 1; dEdx; phi", 1000, -3.2, 3.2, 1000, 0, 15 );

		hDedxphi7 = new TH2D( "dEdxphi7", " dEdx vs phi for (+ and -) tracks of #eta -1 to 1; dEdx; phi", 1000, -3.2, 3.2, 1000, 0, 15 );
		hDedxphi8 = new TH2D( "dEdxphi8", " dEdx vs phi for (+ and -) tracks of #eta -1 to 0; dEdx; phi", 1000, -3.2, 3.2, 1000, 0, 15 );
		hDedxphi9 = new TH2D( "dEdxphi9", " dEdx vs phi for (+ and -) tracks of #eta  0 to 1; dEdx; phi", 1000, -3.2, 3.2, 1000, 0, 15 );

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

			hDedx->Fill( track->dEdx() );
			hphi->Fill( track->pMom().phi() );

			if( track->charge() > 0 ){

				hDedxphi1( track->dEdx() , track->pMom().phi() )

				if( track->eta() < 0 ){
					hDedxphi2( track->dEdx() , track->pMom().phi() )
				}

				if( track->eta() > 0 ){
					hDedxphi3( track->dEdx() , track->pMom().phi() )
				}

			}
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
