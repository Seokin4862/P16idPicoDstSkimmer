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
	TH1D *heta = 0;
	TH2D *hetaphi = 0;


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
		heta = new TH1D( "eta", "eta of Various Tracks; x-axis; y-axis", 1000, -1.5, 1.5 );
		hetaphi = new TH2D( "etavsphi", "eta vs phi; phi; eta", 1000, -3.2, 3.2, 1000, -1.5, 1.5 );
		//this is all rather brute forced, it feelsto me.

		hMeanRunN01 = new TH2D( "hMeanRunN01" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge + eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN02 = new TH2D( "hMeanRunN02" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge + eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN03 = new TH2D( "hMeanRunN03" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge + eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN04 = new TH2D( "hMeanRunN04" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge - eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN05 = new TH2D( "hMeanRunN05" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge - eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN06 = new TH2D( "hMeanRunN06" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge - eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN07 = new TH2D( "hMeanRunN07" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge = eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN08 = new TH2D( "hMeanRunN08" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge = eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN09 = new TH2D( "hMeanRunN09" , " dEdx vs run number, Mom .3 to .4, phi 2.55 to 2.60, charge = eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );


		hMeanRunN11 = new TH2D( "hMeanRunN11" , " dEdx vs run number, Mom .3 to .4, phi 1.55 to 1.60, charge + eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN12 = new TH2D( "hMeanRunN12" , " dEdx vs run number, Mom .3 to .4, phi 1.55 to 1.60, charge + eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN13 = new TH2D( "hMeanRunN13" , " dEdx vs run number, Mom .3 to .4, phi 1.55 to 1.60, charge + eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN14 = new TH2D( "hMeanRunN14" , " dEdx vs run number, Mom .3 to .4, phi 1.55 to 1.60, charge - eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN15 = new TH2D( "hMeanRunN15" , " dEdx vs run number, Mom .3 to .4, phi 1.55 to 1.60, charge - eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN16 = new TH2D( "hMeanRunN16" , " dEdx vs run number, Mom .3 to .4, phi 1.55 to 1.60, charge - eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN17 = new TH2D( "hMeanRunN17" , " dEdx vs run number, Mom .3 to .4, phi 1.55 to 1.60, charge = eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN18 = new TH2D( "hMeanRunN18" , " dEdx vs run number, Mom .3 to .4, phi 1.55 to 1.60, charge = eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN19 = new TH2D( "hMeanRunN19" , " dEdx vs run number, Mom .3 to .4, phi 1.55 to 1.60, charge = eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );


		hMeanRunN21 = new TH2D( "hMeanRunN21" , " dEdx vs run number, Mom .3 to .4, phi -1.90 to -1.85, charge + eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN22 = new TH2D( "hMeanRunN22" , " dEdx vs run number, Mom .3 to .4, phi -1.90 to -1.85, charge + eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN23 = new TH2D( "hMeanRunN23" , " dEdx vs run number, Mom .3 to .4, phi -1.90 to -1.85, charge + eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN24 = new TH2D( "hMeanRunN24" , " dEdx vs run number, Mom .3 to .4, phi -1.90 to -1.85, charge - eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN25 = new TH2D( "hMeanRunN25" , " dEdx vs run number, Mom .3 to .4, phi -1.90 to -1.85, charge - eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN26 = new TH2D( "hMeanRunN26" , " dEdx vs run number, Mom .3 to .4, phi -1.90 to -1.85, charge - eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN27 = new TH2D( "hMeanRunN27" , " dEdx vs run number, Mom .3 to .4, phi -1.90 to -1.85, charge = eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN28 = new TH2D( "hMeanRunN28" , " dEdx vs run number, Mom .3 to .4, phi -1.90 to -1.85, charge = eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN29 = new TH2D( "hMeanRunN29" , " dEdx vs run number, Mom .3 to .4, phi -1.90 to -1.85, charge = eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );


		hMeanRunN31 = new TH2D( "hMeanRunN31" , " dEdx vs run number, Mom .3 to .4, phi -3.00 to -2.95, charge + eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN32 = new TH2D( "hMeanRunN32" , " dEdx vs run number, Mom .3 to .4, phi -3.00 to -2.95, charge + eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN33 = new TH2D( "hMeanRunN33" , " dEdx vs run number, Mom .3 to .4, phi -3.00 to -2.95, charge + eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN34 = new TH2D( "hMeanRunN34" , " dEdx vs run number, Mom .3 to .4, phi -3.00 to -2.95, charge - eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN35 = new TH2D( "hMeanRunN35" , " dEdx vs run number, Mom .3 to .4, phi -3.00 to -2.95, charge - eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN36 = new TH2D( "hMeanRunN36" , " dEdx vs run number, Mom .3 to .4, phi -3.00 to -2.95, charge - eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

		hMeanRunN37 = new TH2D( "hMeanRunN37" , " dEdx vs run number, Mom .3 to .4, phi -3.00 to -2.95, charge = eta = ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN38 = new TH2D( "hMeanRunN38" , " dEdx vs run number, Mom .3 to .4, phi -3.00 to -2.95, charge = eta + ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );
		hMeanRunN39 = new TH2D( "hMeanRunN39" , " dEdx vs run number, Mom .3 to .4, phi -3.00 to -2.95, charge = eta - ; run number ; dE/dx ", 2751, 1, 2751, 1000, 0, 20 );

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
			heta->Fill( track->pMom().pseudoRapidity() );
			hetaphi->Fill( track->phi(), track->pMom().pseudoRapidity() );

			if( track->pMom().phi() > 2.55 && track->pMom().phi() < 2.60 ){

				if( track->charge() > 0 ){
					hMeanRunN01->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					if( track->pMom().pseudoRapidity() < 1 ){
					hMeanRunN02->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
					if( track->pMom().pseudoRapidity() > 1 ){
					hMeanRunN03->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
				};
				if( track->charge() < 0 ){
					hMeanRunN04->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					if( track->pMom().pseudoRapidity() < 1 ){
					hMeanRunN05->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
					if( track->pMom().pseudoRapidity() > 1 ){
					hMeanRunN06->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
				};
						hMeanRunN07->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					if( track->pMom().pseudoRapidity() < 1 ){
						hMeanRunN08->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
					if( track->pMom().pseudoRapidity() > 1 ){
						hMeanRunN09->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
					};
		};

		if( track->pMom().phi() > 1.15 && track->pMom().phi() < 1.20 ){

			if( track->charge() > 0 ){
				hMeanRunN11->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 1 ){
				hMeanRunN12->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
				if( track->pMom().pseudoRapidity() > 1 ){
				hMeanRunN13->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
			};
			if( track->charge() < 0 ){
				hMeanRunN14->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 1 ){
				hMeanRunN15->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
				if( track->pMom().pseudoRapidity() > 1 ){
				hMeanRunN16->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
			};
					hMeanRunN17->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 1 ){
					hMeanRunN18->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
				if( track->pMom().pseudoRapidity() > 1 ){
					hMeanRunN19->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
	};

		if( track->pMom().phi() > -1.90 && track->pMom().phi() < -1.85 ){

			if( track->charge() > 0 ){
				hMeanRunN21->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 1 ){
				hMeanRunN22->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
				if( track->pMom().pseudoRapidity() > 1 ){
				hMeanRunN23->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
			};
			if( track->charge() < 0 ){
				hMeanRunN24->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 1 ){
				hMeanRunN25->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
				if( track->pMom().pseudoRapidity() > 1 ){
				hMeanRunN26->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
			};
					hMeanRunN27->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 1 ){
					hMeanRunN28->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
				if( track->pMom().pseudoRapidity() > 1 ){
					hMeanRunN29->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
				};
	};

	if( track->pMom().phi() > -3.00 && track->pMom().phi() < -2.95 ){

		if( track->charge() > 0 ){
			hMeanRunN31->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
			if( track->pMom().pseudoRapidity() < 1 ){
			hMeanRunN32->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
			};
			if( track->pMom().pseudoRapidity() > 1 ){
			hMeanRunN33->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
			};
		};
		if( track->charge() < 0 ){
			hMeanRunN34->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
			if( track->pMom().pseudoRapidity() < 1 ){
			hMeanRunN35->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
			};
			if( track->pMom().pseudoRapidity() > 1 ){
			hMeanRunN36->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
			};
		};
				hMeanRunN37->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
			if( track->pMom().pseudoRapidity() < 1 ){
				hMeanRunN38->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
			};
			if( track->pMom().pseudoRapidity() > 1 ){
				hMeanRunN39->Fill( rmf.indexForRun( event->runId() ), track->dEdx() );
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
