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

	TH2D *hdEdxvsRunN01 = 0;
	TH2D *hdEdxvsRunN02 = 0;
	TH2D *hdEdxvsRunN03 = 0;

	TH2D *hdEdxvsRunN04 = 0;
	TH2D *hdEdxvsRunN05 = 0;
	TH2D *hdEdxvsRunN06 = 0;

	TH2D *hdEdxvsRunN07 = 0;
	TH2D *hdEdxvsRunN08 = 0;
	TH2D *hdEdxvsRunN09 = 0;


	TH2D *hdEdxvsRunN11 = 0;
	TH2D *hdEdxvsRunN12 = 0;
	TH2D *hdEdxvsRunN13 = 0;

	TH2D *hdEdxvsRunN14 = 0;
	TH2D *hdEdxvsRunN15 = 0;
	TH2D *hdEdxvsRunN16 = 0;

	TH2D *hdEdxvsRunN17 = 0;
	TH2D *hdEdxvsRunN18 = 0;
	TH2D *hdEdxvsRunN19 = 0;

	void makeHistograms(){

		hDedx = new TH1D( "dEdx", "dEdx of Various Tracks; x-axis; y-axis", 1000, 0, 30 );
		hphi = new TH1D( "phi", "phi of Various Tracks; x-axis; y-axis", 1000, -3.2, 3.2 );
		hRunN = new TH1D( "RunN", "Run Numbers", 2751, 1, 2751 );
		hphicheck = new TH1D( "phi check", "phi of Various Tracks; x-axis, y-axis", 1000, -3.2, 3.2 );

		//this is all rather brute forced, it feelsto me.

		hdEdxvsRunN01 = new TH2D( "hdEdxvsRunN01" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge + eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN02 = new TH2D( "hdEdxvsRunN02" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge + eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN03 = new TH2D( "hdEdxvsRunN03" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge + eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hdEdxvsRunN04 = new TH2D( "hdEdxvsRunN04" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge - eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN05 = new TH2D( "hdEdxvsRunN05" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge - eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN06 = new TH2D( "hdEdxvsRunN06" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge - eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hdEdxvsRunN07 = new TH2D( "hdEdxvsRunN07" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge = eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN08 = new TH2D( "hdEdxvsRunN08" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge = eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN09 = new TH2D( "hdEdxvsRunN09" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge = eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );


		hdEdxvsRunN11 = new TH2D( "hdEdxvsRunN11" , " dEdx vs run number, Mom .3 to .4, phi -.55 to -.6 (less displacement), charge + eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN12 = new TH2D( "hdEdxvsRunN12" , " dEdx vs run number, Mom .3 to .4, phi -.55 to -.6 (less displacement), charge + eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN13 = new TH2D( "hdEdxvsRunN13" , " dEdx vs run number, Mom .3 to .4, phi -.55 to -.6 (less displacement), charge + eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hdEdxvsRunN14 = new TH2D( "hdEdxvsRunN14" , " dEdx vs run number, Mom .3 to .4, phi -.55 to -.6 (less displacement), charge - eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN15 = new TH2D( "hdEdxvsRunN15" , " dEdx vs run number, Mom .3 to .4, phi -.55 to -.6 (less displacement), charge - eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN16 = new TH2D( "hdEdxvsRunN16" , " dEdx vs run number, Mom .3 to .4, phi -.55 to -.6 (less displacement), charge - eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hdEdxvsRunN17 = new TH2D( "hdEdxvsRunN17" , " dEdx vs run number, Mom .3 to .4, phi -.55 to -.6 (less displacement), charge = eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN18 = new TH2D( "hdEdxvsRunN18" , " dEdx vs run number, Mom .3 to .4, phi -.55 to -.6 (less displacement), charge = eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hdEdxvsRunN19 = new TH2D( "hdEdxvsRunN19" , " dEdx vs run number, Mom .3 to .4, phi -.55 to -.6 (less displacement), charge = eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );


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
					hdEdxvsRunN01->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					if( track->pMom().pseudoRapidity() < 1 ){
					hdEdxvsRunN02->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
					if( track->pMom().pseudoRapidity() > 1 ){
					hdEdxvsRunN03->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
				};
				if( track->charge() < 0 ){
					hdEdxvsRunN04->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					if( track->pMom().pseudoRapidity() < 1 ){
					hdEdxvsRunN05->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
					if( track->pMom().pseudoRapidity() > 1 ){
					hdEdxvsRunN06->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
				};
						hdEdxvsRunN07->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					if( track->pMom().pseudoRapidity() < 1 ){
						hdEdxvsRunN08->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
					if( track->pMom().pseudoRapidity() > 1 ){
						hdEdxvsRunN09->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
		};

		if( track->pMom().phi() > -.6 && track->pMom().phi() < -.55 ){

			if( track->charge() > 0 ){
				hdEdxvsRunN11->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 1 ){
				hdEdxvsRunN12->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
				if( track->pMom().pseudoRapidity() > 1 ){
				hdEdxvsRunN13->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
			};
			if( track->charge() < 0 ){
				hdEdxvsRunN14->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 1 ){
				hdEdxvsRunN15->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
				if( track->pMom().pseudoRapidity() > 1 ){
				hdEdxvsRunN16->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
			};
					hdEdxvsRunN17->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 1 ){
					hdEdxvsRunN18->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
				if( track->pMom().pseudoRapidity() > 1 ){
					hdEdxvsRunN19->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
	};


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
