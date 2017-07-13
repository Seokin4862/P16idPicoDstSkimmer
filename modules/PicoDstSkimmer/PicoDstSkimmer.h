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
	TH1D *hInvBeta = 0;

	TH2D *hLnDedxvsMom1 = 0;
	TH2D *hLnDedxvsMom2 = 0;
	TH2D *hLnDedxvsMom3 = 0;

	TH3D *hInvBetaDedxMom = 0;
	TH3D *hInvBetaDedxMomPion = 0;
	TH3D *hInvBetaDedxMomKaon = 0;
	TH3D *hInvBetaDedxMomProton = 0;

	TH2D *hInvBetavsMomPion_a = 0;
	TH2D *hInvBetavsMomPion_p = 0;
	TH2D *hInvBetavsMomPion_n = 0;

	TH2D *hInvBetavsMomKaon_a = 0;
	TH2D *hInvBetavsMomKaon_p = 0;
	TH2D *hInvBetavsMomKaon_n = 0;

	TH2D *hInvBetavsMomProton_a = 0;
	TH2D *hInvBetavsMomProton_p = 0;
	TH2D *hInvBetavsMomProton_n = 0;

	void makeHistograms(){

		hLnDedxvsMom1 = new TH2D( "LnDedxvsMom1", "Ln(dEdx) vs Momentum, all charge; Total Momentum; Ln(dEdx)", 300, 0, 3, 1000, 0, 10 );
		hLnDedxvsMom2 = new TH2D( "LnDedxvsMom2", "Ln(dEdx) vs Momentum, + charge; Total Momentum; Ln(dEdx)", 300, 0, 3, 1000, 0, 10 );
		hLnDedxvsMom3 = new TH2D( "LnDedxvsMom3", "Ln(dEdx) vs Momentum, - charge; Total Momentum; Ln(dEdx)", 300, 0, 3, 1000, 0, 10 );

		hInvBetaDedxMom = new TH3D( "InvBetaDedxMom", "1/Beta vs dE/dx vs Momentum; 1/Beta; dE/dx; Momentum;", 300, 0, 3, 1000, 0, 10, 200, -1, 1 );
		hInvBetaDedxMomPion = new TH3D( "InvBetaDedxMomPion", "1/Beta vs dE/dx vs Momentum for Pion; 1/Beta; dE/dx; Momentum", 300, 0, 3, 1000, 0, 10, 200, -1, 1 );
		hInvBetaDedxMomKaon = new TH3D( "InvBetaDedxMomKaon", "1/Beta vs dE/dx vs Momentum for Kaon; 1/Beta; dE/dx; Momentum", 300, 0, 3, 1000, 0, 10, 200, -1, 1 );
		hInvBetaDedxMomProton = new TH3D( "InvBetaDedxMomProton", "1/Beta vs dE/dx vs Momentum for Proton; 1/Beta; dE/dx; Momentum", 300, 0, 3, 1000, 0, 10, 200, -1, 1 );

		hInvBetavsMomPion_a = new TH2D( "InvBetavsMomPion_a", "1/Beta vs Momentum, all charge, Pion Centered; Total Momentum; 1/Beta - 1/ExpectedBeta(Pion)", 300, 0, 3, 1000, -.6, .6 );
		hInvBetavsMomPion_p = new TH2D( "InvBetavsMomPion_p", "1/Beta vs Momentum, + charge, Pion Centered; Total Momentum; 1/Beta - 1/ExpectedBeta(Pion)", 300, 0, 3, 1000, -.6, .6 );
		hInvBetavsMomPion_n = new TH2D( "InvBetavsMomPion_n", "1/Beta vs Momentum, - charge, Pion Centered; Total Momentum; 1/Beta - 1/ExpectedBeta(Pion)", 300, 0, 3, 1000, -.6, .6 );

		hInvBetavsMomKaon_a = new TH2D( "InvBetavsMomKaon_a", "1/Beta vs Momentum, all charge, Kaon Centered; Total Momentum; 1/Beta - 1/ExpectedBeta(Kaon)", 300, 0, 3, 1000, -.6, .6 );
		hInvBetavsMomKaon_p = new TH2D( "InvBetavsMomKaon_p", "1/Beta vs Momentum, + charge, Kaon Centered; Total Momentum; 1/Beta - 1/ExpectedBeta(Kaon)", 300, 0, 3, 1000, -.6, .6 );
		hInvBetavsMomKaon_n = new TH2D( "InvBetavsMomKaon_n", "1/Beta vs Momentum, - charge, Kaon Centered; Total Momentum; 1/Beta - 1/ExpectedBeta(Kaon)", 300, 0, 3, 1000, -.6, .6 );

		hInvBetavsMomProton_a = new TH2D( "InvBetavsMomProton_a", "1/Beta vs Momentum, all charge, Proton Centered; Total Momentum; 1/Beta - 1/ExpectedBeta(Proton)", 300, 0, 3, 1000, -.6, .6 );
		hInvBetavsMomProton_p = new TH2D( "InvBetavsMomProton_p", "1/Beta vs Momentum, + charge, Proton Centered; Total Momentum; 1/Beta - 1/ExpectedBeta(Proton)", 300, 0, 3, 1000, -.6, .6 );
		hInvBetavsMomProton_n = new TH2D( "InvBetavsMomProton_n", "1/Beta vs Momentum, - charge, Proton Centered; Total Momentum; 1/Beta - 1/ExpectedBeta(Proton)", 300, 0, 3, 1000, -.6, .6 );

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

					hInvBetaDedxMom->Fill( track->dEdx(), 1.0/btofPidTraits->btofBeta(), track->pMom().mag() );
					hInvBetaDedxMomPion->Fill( track->dEdx(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .139570, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()), track->pMom().mag() );
					hInvBetaDedxMomKaon->Fill( track->dEdx(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .493677, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()), track->pMom().mag() );
					hInvBetaDedxMomProton->Fill( track->dEdx(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .938272, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()), track->pMom().mag() );

					hInvBetavsMomPion_a->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .139570, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
					hInvBetavsMomKaon_a->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .493677, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
					hInvBetavsMomProton_a->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .938272, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
				}

				if( track->charge() > 0 ){

					hLnDedxvsMom2->Fill( track->pMom().mag(), log(track->dEdx()) );

					if ( track->bTofPidTraitsIndex() >= 0 ){
						btofPidTraits = _rBTofPid.get( track->bTofPidTraitsIndex() );
					};

						if ( nullptr != btofPidTraits ){
							hInvBetavsMomPion_p->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .139570, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
							hInvBetavsMomKaon_p->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .493677, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
							hInvBetavsMomProton_p->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .938272, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
						}
				};

				if( track->charge() < 0 ){

					hLnDedxvsMom3->Fill( track->pMom().mag(), log(track->dEdx()) );

					if ( track->bTofPidTraitsIndex() >= 0 ){
						btofPidTraits = _rBTofPid.get( track->bTofPidTraitsIndex() );
					};

						if ( nullptr != btofPidTraits ){
							hInvBetavsMomPion_n->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .139570, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
							hInvBetavsMomKaon_n->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .493677, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
							hInvBetavsMomProton_n->Fill( track->pMom().mag(),  1.0/btofPidTraits->btofBeta() - sqrt( pow( .938272, 2 ) + pow( track->pMom().mag(), 2 ) )/(track->pMom().mag()) );
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
