
#include "TMath.h"
#include "TF1.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TFile.h"
#include <sstream>

using namespace std;


Double_t PearsonVII( Double_t *x, Double_t *par ){
	Double_t x0 = x[0];

	Double_t m = par[0];
	Double_t s = par[1];
	Double_t y = par[2];
	Double_t l = par[3];

	double a1 = s * TMath::Sqrt( 2 * m - 3 );

	double a = ( y )	/ ( a1 * TMath::Beta( m - 0.5, -0.5 ) );
	double b = pow( 1 + pow( ( x0 - l ) / a1, 2 ), -m );

	return a * b;
}

void fittestslices(){

  TFile *f = new TFile( "/home/sy34/workspace/safe/testslices/testslices.root" );

  TCanvas *c = new TCanvas( "c","c" );

  TF1 *fit = new TF1( "fit", "gaus" );

	TF1 *fitL = new TF1( "fitL", "gaus" );

  TFile *rootfile = new TFile( "fittestslices.root", "RECREATE" );

  TH1D * hinvbpia = new TH1D( "hinvbpia", "Integral of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonpia = new TH1D( "hpearsonpia", "Integral of the Pion Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
	TH1D * hinvbpiaL = new TH1D( "hinvbpiaL", "Integral of the Pion Fit (Gaussian Log Likelihood) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonpiaL = new TH1D( "hpearsonpiaL", "Integral of the Pion Fit (PearsonVII Log Likelihood) vs Total Momentum", 200, 0, 2 );
	TH1D * hratio = new TH1D( "hratio", "Ratio of the Integral of the Pion Fit (Gaus/PearsonVII) vs Total Momentum", 200, 0, 2 );
	TH1D * hratioL = new TH1D( "hratioL", "Ratio of the Integral of the Pion Fit (Gaus/PearsonVII Log Likelihood) vs Total Momentum", 200, 0, 2 );

  // TH1D * hinvbpip = new TH1D( "hinvbpip", "Integral of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	// TH1D * hpearsonpip = new TH1D( "hpearsonpip", "Integral of the Pion Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbpipm = new TH1D( "hinvbpipm", "Mean of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbpips = new TH1D( "hinvbpips", "Sigma of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	//
  // TH1D * hinvbpin = new TH1D( "hinvbpin", "Integral of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	// TH1D * hpearsonpin = new TH1D( "hpearsonpin", "Integral of the Pion Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbpinm = new TH1D( "hinvbpinm", "Mean of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbpins = new TH1D( "hinvbpins", "Sigma of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	//
  // TH1D * hinvbkia = new TH1D( "hinvbkia", "Integral of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	// TH1D * hpearsonkia = new TH1D( "hpearsonkia", "Integral of the Kaon Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbkiam = new TH1D( "hinvbkiam", "Mean of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbkias = new TH1D( "hinvbkias", "Sigma of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	//
  // TH1D * hinvbkip = new TH1D( "hinvbkip", "Integral of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	// TH1D * hpearsonkip = new TH1D( "hpearsonkip", "Integral of the Kaon Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbkipm = new TH1D( "hinvbkipm", "Mean of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbkips = new TH1D( "hinvbkips", "Sigma of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	//
  // TH1D * hinvbkin = new TH1D( "hinvbkin", "Integral of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	// TH1D * hpearsonkin = new TH1D( "hpearsonkin", "Integral of the Kaon Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbkinm = new TH1D( "hinvbkinm", "Mean of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbkins = new TH1D( "hinvbkins", "Sigma of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	//
  // TH1D * hinvbpria = new TH1D( "hinvbpria", "Integral of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	// TH1D * hpearsonpria = new TH1D( "hpearsonpria", "Integral of the Proton Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbpriam = new TH1D( "hinvbpriam", "Mean of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbprias = new TH1D( "hinvbprias", "Sigma of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	//
  // TH1D * hinvbprip = new TH1D( "hinvbprip", "Integral of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	// TH1D * hpearsonprip = new TH1D( "hpearsonprip", "Integral of the Proton Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbpripm = new TH1D( "hinvbpripm", "Mean of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbprips = new TH1D( "hinvbprips", "Sigma of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	//
  // TH1D * hinvbprin = new TH1D( "hinvbprin", "Integral of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	// TH1D * hpearsonprin = new TH1D( "hpearsonprin", "Integral of the Proton Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbprinm = new TH1D( "hinvbprinm", "Mean of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  // TH1D * hinvbprins = new TH1D( "hinvbprins", "Sigma of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );

	TF1 *eval = new TF1( "eval", PearsonVII, -1, 1, 4 );
	eval->SetParameters(5, .1, 1000, 0);
	eval->SetParNames( "m", "s", "y", "l" );

	TF1 *evalL = new TF1( "evalL", PearsonVII, -1, 1, 4 );
	evalL->SetParameters( 5, .1, 1000, 0 );
	evalL->SetParNames( "mL", "sL", "yL", "lL" );

  double beg = -.05;
  double end = .05;

  for( int i = 16; i < 201; i++ ){
    stringstream getslice;
    getslice << "InvbptPia" << i;
    TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
    temph->Draw();
    c->SetLogy();
    temph->Fit( fit, "R", "", beg, end );
    temph->Draw();
    temph->Fit( eval, "R", "", beg, end);
		temph->Draw();
		temph->Fit( fitL, "L", "", beg, end );
		temph->Fit( evalL, "L", "", beg, end );
    getslice << ".png";
    // c->Print( getslice.str().c_str() );
    hinvbpia->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
		hpearsonpia->SetBinContent( i, eval->Integral( -1.5, 1.5 )/.01 );
		hinvbpiaL->SetBinContent( i, fitL->Integral( -.1, .1 )/.01 );
		hpearsonpiaL->SetBinContent( i, evalL->Integral( -1.5, 1.5 )/.01 );
		hratio->SetBinContent( i, fit->Integral( -.1, .1 )/eval->Integral( -1.5, 1.5 ) );
		hratioL->SetBinContent( i, fitL->Integral( -.1, .1 )/evalL->Integral( -1.5, 1.5 ) );
  }

  hinvbpia->Write();
	hinvbpia->Draw();
	hpearsonpia->SetLineColor( 2 );
	hpearsonpia->Draw("same");
	c->Print( "view.png" );
	hpearsonpia->Write();
	hinvbpiaL->Write();
	hpearsonpiaL->Write();
	hratio->Write();
	hratioL->Write();


}
