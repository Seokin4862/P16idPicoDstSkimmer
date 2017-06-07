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

#include "ProductionUtils/RunMapFactory.h"

#include "vendor/loguru.h"

class PicoDstSkimmer : public TreeAnalyzer
{
public:
	const int DEBUG = 1;
	StPicoEvent _event;
	RunMapFactory rmf;

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
	TH1D *hRunN = 0;
	TH1D *hMatchFlag = 0;
	TH1D *hBeta = 0;
	TH1D *hInvBeta = 0;
	TH1D *hYLocal = 0;
	TH1D *hZLocal = 0;
	TH1D *hChargePt = 0;
	TH1D *hPMom = 0;
	TH1D *hChargePMom = 0;

	TH2D *hInvBetavsMom = 0;



	void makeHistograms(){

		// hDedx = new TH1D( "dEdx", "dEdx of Various Tracks; x-axis; y-axis", 1000, 0, 30 );
		// hphi = new TH1D( "phi", "phi of Various Tracks; x-axis; y-axis", 1000, -3.2, 3.2 );
		// hRunN = new TH1D( "RunN", "Run Numbers", 2751, 1, 2751 );

		hMatchFlag = new TH1D( "MatchFlag", "MatchFlag of Various Tracks; Match Flag Numer (0, 1, 2); number of tracks", 3, -.5, 2.5);
		hBeta = new TH1D( "Beta", "Beta of Various Tracks; Beta; number of tracks", 1000, 0, 1);
		hInvBeta = new TH1D( "InvBeta", "1/Beta of Various Tracks; 1/Beta; number of tracks", 1000, 0, 1.5);
		hYLocal = new TH1D( "YLocal", "YLocal of Various Tracks; YLocal; number of tracks", 100, -5, 5);
		hZLocal = new TH1D( "ZLocal", "XLocal of Various Tracks; ZLocal; number of tracks", 100, -5, 5);
		hChargePt = new TH1D( "ChargePt", " Charge times Pt of Various tracks; Charge times Pt; number of tracks", 100, -10, 10 );
		hPMom = new TH1D( "PMom", "Magnitude of Momentum of Various tracks; Magnitude of Momentum; number of tracks", 100, -10, 10 );
		hChargePMom = new TH1D( "ChargePMom", "Charge times Momentum of Various tracks; Magnitude of Momentum; number of trakcs", 100, -10, 10 );

		hInvBetavsMom = new TH2D( "InvBetavsMom", "1/Beta vs Momentum; 1/Beta; Total Momentum", 1000, .8, 2, 1000, 0, 10);


	}

	virtual void analyzeEvent() {
		StPicoEvent *event = _rEvent.get( 0 );

		if ( nullptr == event ){
			return;
		}

		size_t nTracks =  _rTrack.N();
		for ( size_t i = 0; i < nTracks; i++ ){
			StPicoTrack * track = _rTrack.get( i );

			StPicoBTofPidTraits *btofPidTraits = nullptr;
			if ( track->bTofPidTraitsIndex() >= 0 ){
				btofPidTraits = _rBTofPid.get( track->bTofPidTraitsIndex() );
			};

			// hDedx->Fill( track->dEdx() );
			// hphi->Fill( track->pMom().phi() );
			// hRunN->Fill( rmf.indexForRun( event->runId() ) );


				if ( nullptr != btofPidTraits ){
					hChargePt->Fill( (track->charge())*(track->gPt()) );
					hPMom->Fill( track->pMom().mag() );
					hChargePMom->Fill( (track->charge())*(track->pMom().mag()) );
					hInvBetavsMom->Fill( 1.0/btofPidTraits->btofBeta(), track->pMom().mag() );
					hMatchFlag->Fill( btofPidTraits->btofMatchFlag() );
					hBeta->Fill( btofPidTraits->btofBeta() );
					hInvBeta->Fill( 1.0/(btofPidTraits->btofBeta()) );
					hYLocal->Fill( btofPidTraits->btofYLocal() );
					hZLocal->Fill( btofPidTraits->btofZLocal() );
				}


			}


			//LOG_F( INFO, "dedx = %f", track->dEdx() );
			//LOG_F( INFO, "phi = %f", track->pMom().phi() );
		}

		// LOG_IF_F( INFO, DEBUG, "RunId: %d", event->runId() );
		// LOG_IF_F( INFO, DEBUG, "#Tracks: %u", _rTrack.N() );
		// LOG_IF_F( INFO, DEBUG, "#MtdHits: %u", _rMtdHit.N() );
		// LOG_IF_F( INFO, DEBUG, "#MtdPids: %u", _rMtdPid.N() );
};

#endif
