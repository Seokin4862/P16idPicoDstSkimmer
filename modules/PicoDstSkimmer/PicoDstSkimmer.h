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
	TH1D *hphicheck = 0;
	TH1D *hMatchFlag = 0;
	TH1D *hBeta = 0;
	TH1D *hInvBeta = 0;
	TH1D *hYLocal = 0;
	TH1D *hZLocal = 0;

	TH2D *hInvBetavsMom = 0;

	void makeHistograms(){

		hDedx = new TH1D( "dEdx", "dEdx of Various Tracks; x-axis; y-axis", 1000, 0, 30 );
		hphi = new TH1D( "phi", "phi of Various Tracks; x-axis; y-axis", 1000, -3.2, 3.2 );
		hRunN = new TH1D( "RunN", "Run Numbers", 2751, 1, 2751 );
		hphicheck = new TH1D( "phi check", "phi of Various Tracks; x-axis, y-axis", 1000, -3.2, 3.2 );

		hMatchFlag = new TH1D( "MatchFlag", "MatchFlag of Various Tracks; x-axis; y-axis", 3, 0, 2);
		hBeta = new TH1D( "Beta", "Beta of Various Tracks; x-axis; y-axis", 100, 0, 1);
		hInvBeta = new TH1D( "InvBeta", "1/Beta of Various Tracks; x-axis; y-axis", 1000, 1, 1000);
		hYLocal = new TH1D( "YLocal", "YLocal of Various Tracks; x-axis; y-axis", 100, -5, 5);
		hZLocal = new TH1D( "ZLocal", "XLocal of Various Tracks; x-axis; y-axis", 100, -5, 5);

		hInvBetavsMom = new TH2D( "InvBetavsMom", "1/Beta vs Momentum; x-axis; y-axis", 1000, 1, 1000);


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

			if ( track->bTofPidTraitsIndex() >= 0 )
				btofPidTraits = _rBTofPid.get( track->bTofPidTraitsIndex() );

//			if( track->pMom().mag() < .3 ) continue;
//			if( track->pMom().mag() > .4 ) continue;
//			if( track->pMom().phi() < 2.56 ) continue;
//			if( track->pMom().phi() > 2.60 ) continue;

			// hInvBeta->Fill( 1.0/btofPidTraits->btofBeta() )

			hDedx->Fill( track->dEdx() );
			hphi->Fill( track->pMom().phi() );
			hRunN->Fill( rmf.indexForRun( event->runId() ) );
			hMatchFlag->Fill( btofPidTraits->btofMatchFlag() );
			hBeta->Fill( btofPidTraits->btofBeta() );
			hInvBeta->Fill( 1.0/btofPidTraits->btofBeta() );
			hYLocal->Fill( btofPidTraits->btofYLocal() );
			hZLocal->Fill( btofPidTraits->btofZLocal() );

			hInvBetavsMom->Fill( btofPidTraits->btofBeta(), track->pMom().mag() );


	// 		if( track->pMom().phi() > 2.55 && track->pMom().phi() < 2.60 ){
	//
	// 			if( track->charge() > 0 ){
	// 				hdEdxvsRunN01->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
	// 				if( track->pMom().pseudoRapidity() < 0 ){
	// 				hdEdxvsRunN02->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
	// 				};
	// 				if( track->pMom().pseudoRapidity() > 0 ){
	// 				hdEdxvsRunN03->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
	// 				};
	// 			};
	// 			if( track->charge() < 0 ){
	// 				hdEdxvsRunN04->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
	// 				if( track->pMom().pseudoRapidity() < 0 ){
	// 				hdEdxvsRunN05->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
	// 				};
	// 				if( track->pMom().pseudoRapidity() > 0 ){
	// 				hdEdxvsRunN06->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
	// 				};
	// 			};
	// 					hdEdxvsRunN07->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
	// 				if( track->pMom().pseudoRapidity() < 0 ){
	// 					hdEdxvsRunN08->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
	// 				};
	// 				if( track->pMom().pseudoRapidity() > 0 ){
	// 					hdEdxvsRunN09->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
	// 				};
	// 	};
	//


	//		hdEdxvsRunN1->Fill( rmf.indexForRun( event->runId() ) , track->dEdx() );
	//		hdEdxvsRunN2->Fill( rmf.indexForRun( event->runId() ) , track->dEdx() );
				//hDedxphi1->Fill( track->pMom().phi() , track->dEdx() );

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
