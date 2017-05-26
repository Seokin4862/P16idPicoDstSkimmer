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

	TH2D *hMeanRunN01 = 0;
	TH2D *hMeanRunN02 = 0;
	TH2D *hMeanRunN03 = 0;

	TH2D *hMeanRunN04 = 0;
	TH2D *hMeanRunN05 = 0;
	TH2D *hMeanRunN06 = 0;

	TH2D *hMeanRunN07 = 0;
	TH2D *hMeanRunN08 = 0;
	TH2D *hMeanRunN09 = 0;


	TH2D *hMeanRunN11 = 0;
	TH2D *hMeanRunN12 = 0;
	TH2D *hMeanRunN13 = 0;

	TH2D *hMeanRunN14 = 0;
	TH2D *hMeanRunN15 = 0;
	TH2D *hMeanRunN16 = 0;

	TH2D *hMeanRunN17 = 0;
	TH2D *hMeanRunN18 = 0;
	TH2D *hMeanRunN19 = 0;


	TH2D *hMeanRunN21 = 0;
	TH2D *hMeanRunN22 = 0;
	TH2D *hMeanRunN23 = 0;

	TH2D *hMeanRunN24 = 0;
	TH2D *hMeanRunN25 = 0;
	TH2D *hMeanRunN26 = 0;

	TH2D *hMeanRunN27 = 0;
	TH2D *hMeanRunN28 = 0;
	TH2D *hMeanRunN29 = 0;


	TH2D *hMeanRunN31 = 0;
	TH2D *hMeanRunN32 = 0;
	TH2D *hMeanRunN33 = 0;

	TH2D *hMeanRunN34 = 0;
	TH2D *hMeanRunN35 = 0;
	TH2D *hMeanRunN36 = 0;

	TH2D *hMeanRunN37 = 0;
	TH2D *hMeanRunN38 = 0;
	TH2D *hMeanRunN39 = 0;

	void makeHistograms(){

		hDedx = new TH1D( "dEdx", "dEdx of Various Tracks; x-axis; y-axis", 1000, 0, 30 );
		hphi = new TH1D( "phi", "phi of Various Tracks; x-axis; y-axis", 1000, -3.2, 3.2 );
		hRunN = new TH1D( "RunN", "Run Numbers", 2751, 1, 2751 );
		hphicheck = new TH1D( "phi check", "phi of Various Tracks; x-axis, y-axis", 1000, -3.2, 3.2 );

		//add stuff here. like, a lot of stuff

		hMeanRunN01 = new TH2D( "hMeanRunN01" , " dEdx vs run number, Mom .3-.4, phi 2.56-2.60, charge + eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN02 = new TH2D( "hMeanRunN02" , " dEdx vs run number, Mom .3-.4, phi 2.56-2.60, charge + eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN03 = new TH2d( "hMeanRunN03" , " dEdx vs run number, Mom .3-.4, phi 2.56-2.60, charge + eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN04 = new TH2D( "hMeanRunN04" , " dEdx vs run number, Mom .3-.4, phi 2.56-2.60, charge - eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN05 = new TH2D( "hMeanRunN05" , " dEdx vs run number, Mom .3-.4, phi 2.56-2.60, charge - eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN06 = new TH2d( "hMeanRunN06" , " dEdx vs run number, Mom .3-.4, phi 2.56-2.60, charge - eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN07 = new TH2D( "hMeanRunN07" , " dEdx vs run number, Mom .3-.4, phi 2.56-2.60, charge = eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN08 = new TH2D( "hMeanRunN08" , " dEdx vs run number, Mom .3-.4, phi 2.56-2.60, charge = eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN09 = new TH2d( "hMeanRunN09" , " dEdx vs run number, Mom .3-.4, phi 2.56-2.60, charge = eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );



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
//			if( track->pMom().phi() < 2.56 ) continue;
//			if( track->pMom().phi() > 2.60 ) continue;

			hDedx->Fill( track->dEdx() );
			hphi->Fill( track->pMom().phi() );
			hRunN->Fill( rmf.indexForRun( event->runId() ) );

			if( track->pMom().phi() > 2.55 && track->pMom().phi() < 2.60 ){

				if( track->charge() > 0 ){
					hMeaRunN01->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					if( track->pMom().pseudoRapidity() < 1 ){
					hMeaRunN02->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
					if( track->pMom().pseudoRapidity() > 1 ){
					hMeaRunN03->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
				};
				if( track->charge() < 0 ){
					hMeaRunN04->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					if( track->pMom().pseudoRapidity() < 1 ){
					hMeaRunN05->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
					if( track->pMom().pseudoRapidity() > 1 ){
					hMeaRunN06->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
				};
						hMeaRunN07->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					if( track->pMom().pseudoRapidity() < 1 ){
						hMeaRunN08->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
					if( track->pMom().pseudoRapidity() > 1 ){
						hMeaRunN09->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};

		};

	//		hMeanRunN1->Fill( rmf.indexForRun( event->runId() ) , track->dEdx() );
	//		hMeanRunN2->Fill( rmf.indexForRun( event->runId() ) , track->dEdx() );



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
