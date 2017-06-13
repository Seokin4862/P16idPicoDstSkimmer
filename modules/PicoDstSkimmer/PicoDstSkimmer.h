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

	// TH2D *hDedxvsMom = 0;
	// TH2D *hInvBetavsMom = 0;

	void makeHistograms(){

		hDedx = new TH1D( "dEdx", "dEdx; dEdx; number of tracks", 100, 0, 10 );
		hcorrDedx = new TH1D( "corrdEdx", "corrected dEdx; corrected dEdx; number of tracks", 100, 0, 10 );
		// hDedxvsMom = new TH2D( "DedxvsMom", "dEdx vs Momentum; Total Momentum; dEdx", 300, 0, 3, 1000, 0, 60 );
		// hInvBetavsMom = new TH2D( "InvBetavsMom", "1/Beta vs Momentum; Total Momentum; 1/Beta", 300, 0, 3, 1000, .8, 2);

	}

	virtual void analyzeEvent() {
		StPicoEvent *event = _rEvent.get( 0 );

		if ( nullptr == event ){
			return;
		}

		size_t nTracks =  _rTrack.N();
		for ( size_t i = 0; i < nTracks; i++ ){
			StPicoTrack * track = _rTrack.get( i );


			float corr_dEdx = 0;
			float corr_nSigmaE = 0;
			mapper.apply_map_dEdx_nsigmaE( track->pMom().phi(), track->pMom().pseudoRapidity(), track->charge(), track->gPt(), track->dEdx(), track->nSigmaElectron(), corr_dEdx, corr_nSigmaE );

			hDedx->Fill( track->dEdx() );
			hcorrDedx->Fill( corr_dEdx );


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
