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

// add include dEdx mapper

#include "mapping/Mapper_dEdx.h"

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

		// mapper.load_maps( ..., ... );

		mapper.load_maps( "/home/fs26/dedx_ana/quantile_dedx.root", "/home/fs26/dedx_ana/quantile_nsigmae.root" );

	}
protected:

	// Mapper_dEdx mapper;

	Mapper_dEdx mapper;

	TClonesArrayReader < StPicoEvent        > _rEvent;
	TClonesArrayReader < StPicoMtdHit       > _rMtdHit;
	TClonesArrayReader < StPicoTrack        > _rTrack;
	TClonesArrayReader < StPicoMtdPidTraits > _rMtdPid;
	TClonesArrayReader < StPicoBTofPidTraits > _rBTofPid;

	TH1D *hDedx = 0;
	TH1D *hcorrDedx = 0;

	TH2D *hDedxvsPhi1 = 0;
	TH2D *hDedxvsPhi2 = 0;
	TH2D *hDedxvsPhi3 = 0;

	TH2D *hDedxvsPhi4 = 0;
	TH2D *hDedxvsPhi5 = 0;
	TH2D *hDedxvsPhi6 = 0;

	TH2D *hDedxvsPhi7 = 0;
	TH2D *hDedxvsPhi8 = 0;
	TH2D *hDedxvsPhi9 = 0;


	TH2D *hcorrDedxvsPhi1 = 0;
	TH2D *hcorrDedxvsPhi2 = 0;
	TH2D *hcorrDedxvsPhi3 = 0;

	TH2D *hcorrDedxvsPhi4 = 0;
	TH2D *hcorrDedxvsPhi5 = 0;
	TH2D *hcorrDedxvsPhi6 = 0;

	TH2D *hcorrDedxvsPhi7 = 0;
	TH2D *hcorrDedxvsPhi8 = 0;
	TH2D *hcorrDedxvsPhi9 = 0;

	// TH2D *hDedxvsMom = 0;
	// TH2D *hInvBetavsMom = 0;

	void makeHistograms(){

		hDedx = new TH1D( "dEdx", "dEdx; dEdx; number of tracks", 100, 0, 10 );
		hcorrDedx = new TH1D( "corrDedx", "corrected dEdx; corrected dEdx; number of tracks", 100, 0, 10 );
		// hDedxvsMom = new TH2D( "DedxvsMom", "dEdx vs Momentum; Total Momentum; dEdx", 300, 0, 3, 1000, 0, 60 );
		// hInvBetavsMom = new TH2D( "InvBetavsMom", "1/Beta vs Momentum; Total Momentum; 1/Beta", 300, 0, 3, 1000, .8, 2);

		hDedxvsPhi1 = new TH2D( "DedxvsPhi1", "dEdx vs Phi, total momentum .3 to .4, = charge, = #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10 );
		hDedxvsPhi2 = new TH2D( "DedxvsPhi2", "dEdx vs Phi, total momentum .3 to .4, = charge, + #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10 );
		hDedxvsPhi3 = new TH2D( "DedxvsPhi3", "dEdx vs Phi, total momentum .3 to .4, = charge, - #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10 );

		hDedxvsPhi4 = new TH2D( "DedxvsPhi4", "dEdx vs Phi, total momentum .3 to .4, + charge, = #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10 );
		hDedxvsPhi5 = new TH2D( "DedxvsPhi5", "dEdx vs Phi, total momentum .3 to .4, + charge, + #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10 );
		hDedxvsPhi6 = new TH2D( "DedxvsPhi6", "dEdx vs Phi, total momentum .3 to .4, + charge, - #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10 );

		hDedxvsPhi7 = new TH2D( "DedxvsPhi7", "dEdx vs Phi, total momentum .3 to .4, - charge, = #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10 );
		hDedxvsPhi8 = new TH2D( "DedxvsPhi8", "dEdx vs Phi, total momentum .3 to .4, - charge, + #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10 );
		hDedxvsPhi9 = new TH2D( "DedxvsPhi9", "dEdx vs Phi, total momentum .3 to .4, - charge, - #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10 );


		hcorrDedxvsPhi1 = new TH2D( "corrDedxvsPhi1", "corrected dEdx vs Phi, total momentum .3 to .4, = charge, = #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10);
		hcorrDedxvsPhi2 = new TH2D( "corrDedxvsPhi2", "corrected dEdx vs Phi, total momentum .3 to .4, = charge, + #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10);
		hcorrDedxvsPhi3 = new TH2D( "corrDedxvsPhi3", "corrected dEdx vs Phi, total momentum .3 to .4, = charge, - #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10);

		hcorrDedxvsPhi4 = new TH2D( "corrDedxvsPhi4", "corrected dEdx vs Phi, total momentum .3 to .4, + charge, = #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10);
		hcorrDedxvsPhi5 = new TH2D( "corrDedxvsPhi5", "corrected dEdx vs Phi, total momentum .3 to .4, + charge, + #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10);
		hcorrDedxvsPhi6 = new TH2D( "corrDedxvsPhi6", "corrected dEdx vs Phi, total momentum .3 to .4, + charge, - #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10);

		hcorrDedxvsPhi7 = new TH2D( "corrDedxvsPhi7", "corrected dEdx vs Phi, total momentum .3 to .4, - charge, = #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10);
		hcorrDedxvsPhi8 = new TH2D( "corrDedxvsPhi8", "corrected dEdx vs Phi, total momentum .3 to .4, - charge, + #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10);
		hcorrDedxvsPhi9 = new TH2D( "corrDedxvsPhi9", "corrected dEdx vs Phi, total momentum .3 to .4, - charge, - #eta; #phi; dEdx", 500, -3.2, 3.2, 500, 0, 10);

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

			float corr_dEdx = 0;
			float corr_nSigmaE = 0;
			mapper.apply_map_dEdx_nsigmaE( track->pMom().phi(), track->pMom().pseudoRapidity(), track->charge(), track->gPt(), track->dEdx(), track->nSigmaElectron(), corr_dEdx, corr_nSigmaE );



			hDedx->Fill( track->dEdx() );
			hcorrDedx->Fill( corr_dEdx );

			hDedxvsPhi1->Fill( track->pMom().phi(), track->dEdx() );
			if( track->pMom().pseudoRapidity() > 0 ){
				hDedxvsPhi2->Fill( track->pMom().phi(), track->dEdx() );
			}
			if( track->pMom().pseudoRapidity() < 0 ){
				hDedxvsPhi3->Fill( track->pMom().phi(), track->dEdx() );
			}

			if( track->charge() > 0 ){
				hDedxvsPhi4->Fill( track->pMom().phi(), track->dEdx() );
				if( track->pMom().pseudoRapidity() > 0 ){
					hDedxvsPhi5->Fill( track->pMom().phi(), track->dEdx() );
				}
				if( track->pMom().pseudoRapidity() < 0 ){
					hDedxvsPhi6->Fill( track->pMom().phi(), track->dEdx() );
				}
			}

			if( track->charge() < 0 ){
				hDedxvsPhi7->Fill( track->pMom().phi(), track->dEdx() );
				if( track->pMom().pseudoRapidity() > 0 ){
					hDedxvsPhi8->Fill( track->pMom().phi(), track->dEdx() );
				}
				if( track->pMom().pseudoRapidity() < 0 ){
					hDedxvsPhi9->Fill( track->pMom().phi(), track->dEdx() );
				}
			}

			hcorrDedxvsPhi1->Fill( track->pMom().phi(), corr_dEdx );
			if( track->pMom().pseudoRapidity() > 0 ){
				hcorrDedxvsPhi2->Fill( track->pMom().phi(), corr_dEdx );
			}
			if( track->pMom().pseudoRapidity() < 0 ){
				hcorrDedxvsPhi3->Fill( track->pMom().phi(), corr_dEdx );
			}

			if( track->charge() > 0 ){
				hcorrDedxvsPhi4->Fill( track->pMom().phi(), corr_dEdx );
				if( track->pMom().pseudoRapidity() > 0 ){
					hcorrDedxvsPhi5->Fill( track->pMom().phi(), corr_dEdx );
				}
				if( track->pMom().pseudoRapidity() < 0 ){
					hcorrDedxvsPhi6->Fill( track->pMom().phi(), corr_dEdx );
				}

				if( track->charge() < 0 ){
					hcorrDedxvsPhi7->Fill( track->pMom().phi(), corr_dEdx );
					if( track->pMom().pseudoRapidity() > 0 ){
						hcorrDedxvsPhi8->Fill( track->pMom().phi(), corr_dEdx );
					}
					if( track->pMom().pseudoRapidity() < 0 ){
						hcorrDedxvsPhi9->Fill( track->pMom().phi(), corr_dEdx );
					}


			}

			}
			// hDedxvsMom->Fill( track->pMom().mag(), track->dEdx() );
			//
			// StPicoBTofPidTraits *btofPidTraits = nullptr;
			// if ( track->bTofPidTraitsIndex() >= 0 ){
			// 	btofPidTraits = _rBTofPid.get( track->bTofPidTraitsIndex() );
			// };
			//
			// 	if ( nullptr != btofPidTraits ){
			// 		hInvBetavsMom->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() );
			// 	}


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
