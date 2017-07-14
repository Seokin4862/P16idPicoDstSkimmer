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

	THnSparse *hInvBetaDedxMom = 0;
	THnSparse *hInvBetaDedxMomPion = 0;
	THnSparse *hInvBetaDedxMomKaon = 0;
	THnSparse *hInvBetaDedxMomProton = 0;

	void makeHistograms(){

		hInvBetaDedxMom = new THnSparse( "InvBetaDedxMom", "1/Beta vs dE/dx vs Momentum; 1/Beta; dE/dx; Momentum;", 300, 0, 3, 1000, 0, 10, 200, 0, 2 );
		hInvBetaDedxMomPion = new THnSparse( "InvBetaDedxMomPion", "1/Beta vs dE/dx vs Momentum for Pion Centered on 1.Beta; 1/Beta - 1/ExpectedBeta(Pion); dE/dx; Momentum", 300, -1.5, 1.5, 1000, 0, 10, 200, 0, 2 );
		hInvBetaDedxMomKaon = new THnSparse( "InvBetaDedxMomKaon", "1/Beta vs dE/dx vs Momentum for Kaon Centered on 1/Beta; 1/Beta - 1/ExpectedBeta(Kaon); dE/dx; Momentum", 300, -1.5, 1.5, 1000, 0, 10, 200, 0, 2 );
		hInvBetaDedxMomProton = new THnSparse( "InvBetaDedxMomProton", "1/Beta vs dE/dx vs Momentum for Proton Centered on 1/Beta; 1/Beta - 1/ExpectedBeta(Proton); dE/dx; Momentum", 300, -1.5, 1.5, 1000, 0, 10, 200, 0, 2 );

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

				if ( nullptr != btofPidTraits ){

					hInvBetaDedxMom->Fill( 1.0/btofPidTraits->btofBeta(), track->dEdx(), track->pMom().mag() );
					hInvBetaDedxMomPion->Fill( 1.0/btofPidTraits->btofBeta() - sqrt( pow( .139570, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()), track->dEdx(), track->pMom().mag() );
					hInvBetaDedxMomKaon->Fill( 1.0/btofPidTraits->btofBeta() - sqrt( pow( .493677, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()), track->dEdx(), track->pMom().mag() );
					hInvBetaDedxMomProton->Fill( 1.0/btofPidTraits->btofBeta() - sqrt( pow( .938272, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()), track->dEdx(), track->pMom().mag() );

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
