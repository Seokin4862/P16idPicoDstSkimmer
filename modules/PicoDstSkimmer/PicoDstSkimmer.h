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

// #include "mapping/Mapper_dEdx.h"

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

		// mapper.load_maps( "/home/fs26/dedx_ana/quantile_dedx.root", "/home/fs26/dedx_ana/quantile_nsigmae.root" );

	}
protected:

	// Mapper_dEdx mapper;

	// Mapper_dEdx mapper;

	TClonesArrayReader < StPicoEvent        > _rEvent;
	TClonesArrayReader < StPicoMtdHit       > _rMtdHit;
	TClonesArrayReader < StPicoTrack        > _rTrack;
	TClonesArrayReader < StPicoMtdPidTraits > _rMtdPid;
	TClonesArrayReader < StPicoBTofPidTraits > _rBTofPid;

	TH1D *hDedx = 0;
	TH1D *hcorrDedx = 0;

	TH2D *hLnDedxvsMom1 = 0;
	TH2D *hInvBetavsMom1 = 0;

	TH2D *hLnDedxvsMom2 = 0;
	TH2D *hInvBetavsMom2 = 0;

	TH2D *hLnDedxvsMom3 = 0;
	TH2D *hInvBetavsMom3 = 0;

	void makeHistograms(){

		hDedx = new TH1D( "dEdx", "dEdx; dEdx; number of tracks", 100, 0, 10 );
		hcorrDedx = new TH1D( "corrDedx", "corrected dEdx; corrected dEdx; number of tracks", 100, 0, 10 );

		hLnDedxvsMom1 = new TH2D( "LnDedxvsMom1", "Ln(dEdx) vs Momentum, all charge; Total Momentum; Ln(dEdx)", 300, 0, 3, 1000, 0, 10 );
		hInvBetavsMom1 = new TH2D( "InvBetavsMom1", "1/Beta vs Momentum, all charge; Total Momentum; 1/Beta", 300, 0, 3, 1000, -1, 1);

		hLnDedxvsMom2 = new TH2D( "LnDedxvsMom2", "Ln(dEdx) vs Momentum, + charge; Total Momentum; Ln(dEdx)", 300, 0, 3, 1000, 0, 10 );
		hInvBetavsMom2 = new TH2D( "InvBetavsMom2", "1/Beta vs Momentum, + charge; Total Momentum; 1/Beta", 300, 0, 3, 1000, .8, 2);

		hLnDedxvsMom3 = new TH2D( "LnDedxvsMom3", "Ln(dEdx) vs Momentum; Total Momentum, - charge; Ln(dEdx)", 300, 0, 3, 1000, 0, 10 );
		hInvBetavsMom3 = new TH2D( "InvBetavsMom3", "1/Beta vs Momentum; Total Momentum, - charge; 1/Beta", 300, 0, 3, 1000, .8, 2);

	}

	virtual void analyzeEvent() {
		StPicoEvent *event = _rEvent.get( 0 );

		if ( nullptr == event ){
			return;
		}

		size_t nTracks =  _rTrack.N();
		for ( size_t i = 0; i < nTracks; i++ ){
			StPicoTrack * track = _rTrack.get( i );

			hLnDedxvsMom1->Fill( track->pMom().mag(), log(track->dEdx()) );

			StPicoBTofPidTraits *btofPidTraits = nullptr;
			if ( track->bTofPidTraitsIndex() >= 0 ){
				btofPidTraits = _rBTofPid.get( track->bTofPidTraitsIndex() );
			};

				if ( nullptr != btofPidTraits ){
					hInvBetavsMom1->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .139570, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
				}

				if( track->charge() > 0 ){

					hLnDedxvsMom2->Fill( track->pMom().mag(), log(track->dEdx()) );

					if ( track->bTofPidTraitsIndex() >= 0 ){
						btofPidTraits = _rBTofPid.get( track->bTofPidTraitsIndex() );
					};

						if ( nullptr != btofPidTraits ){
							hInvBetavsMom2->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() );
						}
				};

				if( track->charge() < 0 ){

					hLnDedxvsMom3->Fill( track->pMom().mag(), log(track->dEdx()) );

					if ( track->bTofPidTraitsIndex() >= 0 ){
						btofPidTraits = _rBTofPid.get( track->bTofPidTraitsIndex() );
					};

						if ( nullptr != btofPidTraits ){
							hInvBetavsMom3->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() );
						}
				};


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
