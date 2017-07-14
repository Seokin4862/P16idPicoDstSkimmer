
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
	TH1D * hratiopa = new TH1D( "hratiopa", "Ratio of the Integral of the Pion Fit (Gaus/PearsonVII) vs Total Momentum", 200, 0, 2 );
	TH1D * hratiopaL = new TH1D( "hratiopaL", "Ratio of the Integral of the Pion Fit (Gaus/PearsonVII Log Likelihood) vs Total Momentum", 200, 0, 2 );

	TH1D * hinvbpka = new TH1D( "hinvbkia", "Integral of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonkia = new TH1D( "hpearsonkia", "Integral of the Kaon Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
	TH1D * hinvbkiaL = new TH1D( "hinvbkiaL", "Integral of the Kaon Fit (Gaussian Log Likelihood) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonkiaL = new TH1D( "hpearsonkiaL", "Integral of the Kaon Fit (PearsonVII Log Likelihood) vs Total Momentum", 200, 0, 2 );
	TH1D * hratioka = new TH1D( "hratioka", "Ratio of the Integral of the Kaon Fit (Gaus/PearsonVII) vs Total Momentum", 200, 0, 2 );
	TH1D * hratiokaL = new TH1D( "hratiokaL", "Ratio of the Integral of the Kaon Fit (Gaus/PearsonVII Log Likelihood) vs Total Momentum", 200, 0, 2 );

	TH1D * hinvbpria = new TH1D( "hinvbpria", "Integral of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonpria = new TH1D( "hpearsonpria", "Integral of the Proton Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
	TH1D * hinvbpriaL = new TH1D( "hinvbpriaL", "Integral of the Proton Fit (Gaussian Log Likelihood) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonpriaL = new TH1D( "hpearsonpriaL", "Integral of the Proton Fit (PearsonVII Log Likelihood) vs Total Momentum", 200, 0, 2 );
	TH1D * hratiopra = new TH1D( "hratiopra", "Ratio of the Integral of the Proton Fit (Gaus/PearsonVII) vs Total Momentum", 200, 0, 2 );
	TH1D * hratiopraL = new TH1D( "hratiopraL", "Ratio of the Integral of the Proton Fit (Gaus/PearsonVII Log Likelihood) vs Total Momentum", 200, 0, 2 );


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
		hratiopa->SetBinContent( i, fit->Integral( -.1, .1 )/eval->Integral( -1.5, 1.5 ) );
		hratiopaL->SetBinContent( i, fitL->Integral( -.1, .1 )/evalL->Integral( -1.5, 1.5 ) );
  }

  hinvbpia->Write();
	hinvbpia->Draw();
	hpearsonpia->SetLineColor( 2 );
	hpearsonpia->Draw("same");
	c->Print( "view.png" );
	hpearsonpia->Write();
	hinvbpiaL->Write();
	hpearsonpiaL->Write();
	hratiopa->Write();
	hratiopaL->SetAxisRange( 0, 3, "Y" );
	hratiopaL->Write();


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
    getslice << "InvbptKia" << i;
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
    hinvbkia->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
		hpearsonkia->SetBinContent( i, eval->Integral( -1.5, 1.5 )/.01 );
		hinvbkiaL->SetBinContent( i, fitL->Integral( -.1, .1 )/.01 );
		hpearsonkiaL->SetBinContent( i, evalL->Integral( -1.5, 1.5 )/.01 );
		hratioka->SetBinContent( i, fit->Integral( -.1, .1 )/eval->Integral( -1.5, 1.5 ) );
		hratiokaL->SetBinContent( i, fitL->Integral( -.1, .1 )/evalL->Integral( -1.5, 1.5 ) );
  }

  hinvbkia->Write();
	hinvbkia->Draw();
	hpearsonkia->SetLineColor( 2 );
	hpearsonkia->Draw("same");
	c->Print( "view.png" );
	hpearsonkia->Write();
	hinvbkiaL->Write();
	hpearsonkiaL->Write();
	hratioka->Write();
	hratiokaL->SetAxisRange( 0, 3, "Y" );
	hratiokaL->Write();



}
