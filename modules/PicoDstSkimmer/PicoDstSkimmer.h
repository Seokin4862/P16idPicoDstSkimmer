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

	TH2D *hDedxphi01 = 0;
	TH2D *hDedxphi02 = 0;
	TH2D *hDedxphi03 = 0;

	TH2D *hDedxphi04 = 0;
	TH2D *hDedxphi05 = 0;
	TH2D *hDedxphi06 = 0;

	TH2D *hDedxphi07 = 0;
	TH2D *hDedxphi08 = 0;
	TH2D *hDedxphi09 = 0;


	TH2D *hDedxphi11 = 0;
	TH2D *hDedxphi12 = 0;
	TH2D *hDedxphi13 = 0;

	TH2D *hDedxphi14 = 0;
	TH2D *hDedxphi15 = 0;
	TH2D *hDedxphi16 = 0;

	TH2D *hDedxphi17 = 0;
	TH2D *hDedxphi18 = 0;
	TH2D *hDedxphi19 = 0;


	TH2D *hDedxphi21 = 0;
	TH2D *hDedxphi22 = 0;
	TH2D *hDedxphi23 = 0;

	TH2D *hDedxphi24 = 0;
	TH2D *hDedxphi25 = 0;
	TH2D *hDedxphi26 = 0;

	TH2D *hDedxphi27 = 0;
	TH2D *hDedxphi28 = 0;
	TH2D *hDedxphi29 = 0;


	TH2D *hDedxphi31 = 0;
	TH2D *hDedxphi32 = 0;
	TH2D *hDedxphi33 = 0;

	TH2D *hDedxphi34 = 0;
	TH2D *hDedxphi35 = 0;
	TH2D *hDedxphi36 = 0;

	TH2D *hDedxphi37 = 0;
	TH2D *hDedxphi38 = 0;
	TH2D *hDedxphi39 = 0;


	void makeHistograms(){

		hDedx = new TH1D( "dEdx", "dEdx of Various Tracks; x-axis; y-axis", 1000, 0, 30 );
		hphi = new TH1D( "phi", "phi of Various Tracks; x-axis; y-axis", 1000, -3.2, 3.2 );

		hDedxphi01 = new TH2D( "nSno01", " dEdx vs phi, total momentum .3 to .4, + charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 60 );
		hDedxphi02 = new TH2D( "nSno02", " dEdx vs phi, total momentum .3 to .4, + charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 60 );
		hDedxphi03 = new TH2D( "nSno03", " dEdx vs phi, total momentum .3 to .4, + charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 60 );

		hDedxphi04 = new TH2D( "nSno04", " dEdx vs phi, total momentum .3 to .4, - charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 60 );
		hDedxphi05 = new TH2D( "nSno05", " dEdx vs phi, total momentum .3 to .4, - charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 60 );
		hDedxphi06 = new TH2D( "nSno06", " dEdx vs phi, total momentum .3 to .4, - charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 60 );

		hDedxphi07 = new TH2D( "nSno07", " dEdx vs phi, total momentum .3 to .4, ± charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 60 );
		hDedxphi08 = new TH2D( "nSno08", " dEdx vs phi, total momentum .3 to .4, ± charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 60 );
		hDedxphi09 = new TH2D( "nSno09", " dEdx vs phi, total momentum .3 to .4, ± charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 60 );


		hDedxphi11 = new TH2D( "nSPi11", " dEdx vs phi for |nSigmaPion| < 2, total momentum .3 to .4, + charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 6 );
		hDedxphi12 = new TH2D( "nSPi12", " dEdx vs phi for |nSigmaPion| < 2, total momentum .3 to .4, + charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 6 );
		hDedxphi13 = new TH2D( "nSPi13", " dEdx vs phi for |nSigmaPion| < 2, total momentum .3 to .4, + charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 6 );

		hDedxphi14 = new TH2D( "nSPi14", " dEdx vs phi for |nSigmaPion| < 2, total momentum .3 to .4, - charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 6 );
		hDedxphi15 = new TH2D( "nSPi15", " dEdx vs phi for |nSigmaPion| < 2, total momentum .3 to .4, - charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 6 );
		hDedxphi16 = new TH2D( "nSPi16", " dEdx vs phi for |nSigmaPion| < 2, total momentum .3 to .4, - charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 6 );

		hDedxphi17 = new TH2D( "nSPi17", " dEdx vs phi for |nSigmaPion| < 2, total momentum .3 to .4, ± charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 6 );
		hDedxphi18 = new TH2D( "nSPi18", " dEdx vs phi for |nSigmaPion| < 2, total momentum .3 to .4, ± charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 6 );
		hDedxphi19 = new TH2D( "nSPi19", " dEdx vs phi for |nSigmaPion| < 2, total momentum .3 to .4, ± charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 0, 6 );


		hDedxphi21 = new TH2D( "nSKa21", " dEdx vs phi for |nSigmaKaon| < 2, total momentum .3 to .4, + charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 2, 10 );
		hDedxphi22 = new TH2D( "nSKa22", " dEdx vs phi for |nSigmaKaon| < 2, total momentum .3 to .4, + charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 2, 10 );
		hDedxphi23 = new TH2D( "nSKa23", " dEdx vs phi for |nSigmaKaon| < 2, total momentum .3 to .4, + charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 2, 10 );

		hDedxphi24 = new TH2D( "nSKa24", " dEdx vs phi for |nSigmaKaon| < 2, total momentum .3 to .4, - charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 2, 10 );
		hDedxphi25 = new TH2D( "nSKa25", " dEdx vs phi for |nSigmaKaon| < 2, total momentum .3 to .4, - charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 2, 10 );
		hDedxphi26 = new TH2D( "nSKa26", " dEdx vs phi for |nSigmaKaon| < 2, total momentum .3 to .4, - charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 2, 10 );

		hDedxphi27 = new TH2D( "nSKa27", " dEdx vs phi for |nSigmaKaon| < 2, total momentum .3 to .4, ± charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 2, 10 );
		hDedxphi28 = new TH2D( "nSKa28", " dEdx vs phi for |nSigmaKaon| < 2, total momentum .3 to .4, ± charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 2, 10 );
		hDedxphi29 = new TH2D( "nSKa29", " dEdx vs phi for |nSigmaKaon| < 2, total momentum .3 to .4, ± charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 2, 10 );


		hDedxphi31 = new TH2D( "nSPi31", " dEdx vs phi for |nSigmaProton| < 2, total momentum .3 to .4, + charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 10, 30 );
		hDedxphi32 = new TH2D( "nSPi32", " dEdx vs phi for |nSigmaProton| < 2, total momentum .3 to .4, + charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 10, 30 );
		hDedxphi33 = new TH2D( "nSPi33", " dEdx vs phi for |nSigmaProton| < 2, total momentum .3 to .4, + charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 10, 30 );

		hDedxphi34 = new TH2D( "nSPi34", " dEdx vs phi for |nSigmaProton| < 2, total momentum .3 to .4, - charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 10, 30 );
		hDedxphi35 = new TH2D( "nSPi35", " dEdx vs phi for |nSigmaProton| < 2, total momentum .3 to .4, - charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 10, 30 );
		hDedxphi36 = new TH2D( "nSPi36", " dEdx vs phi for |nSigmaProton| < 2, total momentum .3 to .4, - charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 10, 30 );

		hDedxphi37 = new TH2D( "nSPi37", " dEdx vs phi for |nSigmaProton| < 2, total momentum .3 to .4, ± charge, #eta -1 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 10, 30 );
		hDedxphi38 = new TH2D( "nSPi38", " dEdx vs phi for |nSigmaProton| < 2, total momentum .3 to .4, ± charge, #eta -1 to 0; phi; dEdx", 1000, -3.2, 3.2, 1000, 10, 30 );
		hDedxphi39 = new TH2D( "nSPi39", " dEdx vs phi for |nSigmaProton| < 2, total momentum .3 to .4, ± charge, #eta 0 to 1; phi; dEdx", 1000, -3.2, 3.2, 1000, 10, 30 );

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
				hDedxphi01->Fill( track->pMom().phi() , track->dEdx() );
				if( track->pMom().pseudoRapidity() < 0 ){
					hDedxphi02->Fill( track->pMom().phi() , track->dEdx() );
				}
				if( track->pMom().pseudoRapidity() > 0 ){
					hDedxphi03->Fill( track->pMom().phi() , track->dEdx() );
				}
			}

			if( track->charge() < 0 ){
				hDedxphi04->Fill( track->pMom().phi() , track->dEdx() );
				if( track->pMom().pseudoRapidity() < 0){
					hDedxphi05->Fill( track->pMom().phi() , track->dEdx() );
					}
				if( track->pMom().pseudoRapidity() > 0){
					hDedxphi06->Fill( track->pMom().phi() , track->dEdx() );
				}
			}
			hDedxphi07->Fill( track->pMom().phi(), track->dEdx() );
			if( track->pMom().pseudoRapidity() < 0){
				hDedxphi08->Fill( track->pMom().phi() , track->dEdx() );
			}
			if( track->pMom().pseudoRapidity() > 0){
				hDedxphi09->Fill( track->pMom().phi(), track->dEdx() );
			}

			if( track->nSigmaPion() > -2 && track->nSigmaPion() < 2){
				if( track->charge() > 0 ){
					hDedxphi11->Fill( track->pMom().phi() , track->dEdx() );
					if( track->pMom().pseudoRapidity() < 0 ){
						hDedxphi12->Fill( track->pMom().phi() , track->dEdx() );
					}
					if( track->pMom().pseudoRapidity() > 0 ){
						hDedxphi13->Fill( track->pMom().phi() , track->dEdx() );
					}
				}
				if( track->charge() < 0 ){
					hDedxphi14->Fill( track->pMom().phi() , track->dEdx() );
					if( track->pMom().pseudoRapidity() < 0){
						hDedxphi15->Fill( track->pMom().phi() , track->dEdx() );
						}
					if( track->pMom().pseudoRapidity() > 0){
						hDedxphi16->Fill( track->pMom().phi() , track->dEdx() );
					}
				}
				hDedxphi17->Fill( track->pMom().phi(), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 0){
					hDedxphi18->Fill( track->pMom().phi() , track->dEdx() );
				}
				if( track->pMom().pseudoRapidity() > 0){
					hDedxphi19->Fill( track->pMom().phi(), track->dEdx() );
				}
			}

			if( track->nSigmaKaon() > -2 && track->nSigmaKaon() < 2){
				if( track->charge() > 0 ){
					hDedxphi21->Fill( track->pMom().phi() , track->dEdx() );
					if( track->pMom().pseudoRapidity() < 0 ){
						hDedxphi22->Fill( track->pMom().phi() , track->dEdx() );
					}
					if( track->pMom().pseudoRapidity() > 0 ){
						hDedxphi23->Fill( track->pMom().phi() , track->dEdx() );
					}
				}
				if( track->charge() < 0 ){
					hDedxphi24->Fill( track->pMom().phi() , track->dEdx() );
					if( track->pMom().pseudoRapidity() < 0){
						hDedxphi25->Fill( track->pMom().phi() , track->dEdx() );
						}
					if( track->pMom().pseudoRapidity() > 0){
						hDedxphi26->Fill( track->pMom().phi() , track->dEdx() );
					}
				}
				hDedxphi27->Fill( track->pMom().phi(), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 0){
					hDedxphi28->Fill( track->pMom().phi() , track->dEdx() );
				}
				if( track->pMom().pseudoRapidity() > 0){
					hDedxphi29->Fill( track->pMom().phi(), track->dEdx() );
				}
			}

			if( track->nSigmaProton() > -2 && track->nSigmaProton() < 2){
				if( track->charge() > 0 ){
					hDedxphi31->Fill( track->pMom().phi() , track->dEdx() );
					if( track->pMom().pseudoRapidity() < 0 ){
						hDedxphi32->Fill( track->pMom().phi() , track->dEdx() );
					}
					if( track->pMom().pseudoRapidity() > 0 ){
						hDedxphi33->Fill( track->pMom().phi() , track->dEdx() );
					}
				}
				if( track->charge() < 0 ){
					hDedxphi34->Fill( track->pMom().phi() , track->dEdx() );
					if( track->pMom().pseudoRapidity() < 0){
						hDedxphi35->Fill( track->pMom().phi() , track->dEdx() );
						}
					if( track->pMom().pseudoRapidity() > 0){
						hDedxphi36->Fill( track->pMom().phi() , track->dEdx() );
					}
				}
				hDedxphi37->Fill( track->pMom().phi(), track->dEdx() );
				if( track->pMom().pseudoRapidity() < 0){
					hDedxphi38->Fill( track->pMom().phi() , track->dEdx() );
				}
				if( track->pMom().pseudoRapidity() > 0){
					hDedxphi39->Fill( track->pMom().phi(), track->dEdx() );
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
