// Double_t eval( Double_t *x, Double_t *bw ){
//    Double_t x0 = x[0];
//    Double_t m = bw[0];
//    Double_t s = bw[1];
//    Double_t y = bw[2];
//    Double_t l = bw[3];
//
//
//    double a1 = s * TMath::Sqrt( 2 * m - 3 );
//
//    double a =  (y * bw) / ( a1 * TMath::Beta( m-0.5, 0.5 ) );
//    double b = pow( 1 + pow( ( x - l ) / a1, 2 ), -m );
//
//    return a * b;
// }

// TF1 *eval = new TF1( "eval", "eval", -100, 100, 4 );
// eval->SetParameters(1,2, 3, 4); // just example, there are 4 parameters
// eval->SetParNames("mean","sigma", "yield", "lambda");


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
  TH1D * hinvbpiam = new TH1D( "hinvbpiam", "Mean of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpias = new TH1D( "hinvbpias", "Sigma of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbpip = new TH1D( "hinvbpip", "Integral of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonpip = new TH1D( "hpearsonpip", "Integral of the Pion Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpipm = new TH1D( "hinvbpipm", "Mean of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpips = new TH1D( "hinvbpips", "Sigma of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbpin = new TH1D( "hinvbpin", "Integral of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonpin = new TH1D( "hpearsonpin", "Integral of the Pion Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpinm = new TH1D( "hinvbpinm", "Mean of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpins = new TH1D( "hinvbpins", "Sigma of the Pion Fit (Gaussian) vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbkia = new TH1D( "hinvbkia", "Integral of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonkia = new TH1D( "hpearsonkia", "Integral of the Kaon Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkiam = new TH1D( "hinvbkiam", "Mean of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkias = new TH1D( "hinvbkias", "Sigma of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbkip = new TH1D( "hinvbkip", "Integral of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonkip = new TH1D( "hpearsonkip", "Integral of the Kaon Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkipm = new TH1D( "hinvbkipm", "Mean of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkips = new TH1D( "hinvbkips", "Sigma of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbkin = new TH1D( "hinvbkin", "Integral of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonkin = new TH1D( "hpearsonkin", "Integral of the Kaon Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkinm = new TH1D( "hinvbkinm", "Mean of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkins = new TH1D( "hinvbkins", "Sigma of the Kaon Fit (Gaussian) vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbpria = new TH1D( "hinvbpria", "Integral of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonpria = new TH1D( "hpearsonpria", "Integral of the Proton Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpriam = new TH1D( "hinvbpriam", "Mean of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbprias = new TH1D( "hinvbprias", "Sigma of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbprip = new TH1D( "hinvbprip", "Integral of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonprip = new TH1D( "hpearsonprip", "Integral of the Proton Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpripm = new TH1D( "hinvbpripm", "Mean of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbprips = new TH1D( "hinvbprips", "Sigma of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbprin = new TH1D( "hinvbprin", "Integral of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
	TH1D * hpearsonprin = new TH1D( "hpearsonprin", "Integral of the Proton Fit (PearsonVII) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbprinm = new TH1D( "hinvbprinm", "Mean of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbprins = new TH1D( "hinvbprins", "Sigma of the Proton Fit (Gaussian) vs Total Momentum", 200, 0, 2 );


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
		temph->Fit( fitL, "L" );
		temph->Fit( evalL, "L" );
    getslice << ".png";
    // c->Print( getslice.str().c_str() );
    hinvbpia->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
		hpearsonpia->SetBinContent( i, eval->Integral( -1.5, 1.5 )/.01 );
    hinvbpiam->SetBinContent( i, fit->GetParameter(1) );
    hinvbpias->SetBinContent( i, fit->GetParameter(2) );
  }

  hinvbpia->Write();
	hinvbpia->Draw();
	hpearsonpia->SetLineColor( 2 );
	hpearsonpia->Draw("same");
	c->Print( "view.png" );
	hpearsonpia->Write();
  hinvbpiam->Write();
  hinvbpias->Write();

	TF1 *eval = new TF1( "eval", PearsonVII, -1, 1, 4 );
	eval->SetParameters(5, .1, 1000, 0);
	eval->SetParNames( "m", "s", "y", "l" );

//   for( int i = 16; i < 201; i++ ){
//     stringstream getslice;
//     getslice << "InvbptPip" << i;
//     TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
//     temph->Draw();
//     c->SetLogy();
//     temph->Fit( fit, "R", "", beg, end );
//     temph->Draw();
// 		temph->Fit( eval, "R", "", beg, end);
// 		temph->Draw();
//     getslice << ".png";
//     // c->Print( getslice.str().c_str() );
//     hinvbpip->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
// 		hpearsonpip->SetBinContent( i, eval->Integral( -1.5, 1.5)/.01 );
//     hinvbpipm->SetBinContent( i, fit->GetParameter(1) );
//     hinvbpips->SetBinContent( i, fit->GetParameter(2) );
//   }
//
//   hinvbpip->Write();
// 	hpearsonpip->Write();
// 	hinvbpip->Draw();
// 	hpearsonpip->SetLineColor( 2 );
// 	hpearsonpip->Draw("same");
// 	c->Print( "view2.png" );
//   hinvbpipm->Write();
//   hinvbpips->Write();
//
// 	TF1 *eval = new TF1( "eval", PearsonVII, -1, 1, 4 );
// 	eval->SetParameters(5, .1, 1000, 0);
// 	eval->SetParNames( "m", "s", "y", "l" );
//
//   for( int i = 16; i < 201; i++ ){
//     stringstream getslice;
//     getslice << "InvbptPin" << i;
//     TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
//     temph->Draw();
//     c->SetLogy();
//     temph->Fit( fit, "R", "", beg, end );
//     temph->Draw();
// 		temph->Fit( eval, "R", "", beg, end);
// 		temph->Draw();
// 		getslice << ".png";
// 		// c->Print( getslice.str().c_str() );
// 		hinvbpin->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
// 		hpearsonpin->SetBinContent( i, eval->Integral( -1.5, 1.5)/.01 );
// 		hinvbpinm->SetBinContent( i, fit->GetParameter(1) );
// 		hinvbpins->SetBinContent( i, fit->GetParameter(2) );
// 		}
//
// 		hinvbpin->Write();
// 		hpearsonpin->Write();
// 		hinvbpin->Draw();
// 		hpearsonpin->SetLineColor( 2 );
// 		hpearsonpin->Draw("same");
// 		c->Print( "view3.png" );
// 		hinvbpinm->Write();
// 		hinvbpins->Write();
//
// 		TF1 *eval = new TF1( "eval", PearsonVII, -1, 1, 4 );
// 		eval->SetParameters(5, .1, 1000, 0);
// 		eval->SetParNames( "m", "s", "y", "l" );
//
//   double beg = -.03;
//   double end = .03;
//
//   for( int i = 16; i < 201; i++ ){
//     stringstream getslice;
//     getslice << "InvbptKia" << i;
//     TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
//     temph->Draw();
//     c->SetLogy();
//     temph->Fit( fit, "R", "", beg, end );
//     temph->Draw();
// 		temph->Fit( eval, "R", "", beg, end);
// 		temph->Draw();
//     getslice << ".png";
//     // c->Print( getslice.str().c_str() );
//     hinvbkia->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
// 		hpearsonkia->SetBinContent( i, eval->Integral( -.6, .6 )/.01 );
// 		hinvbkiam->SetBinContent( i, fit->GetParameter(1) );
//     hinvbkias->SetBinContent( i, fit->GetParameter(2) );
//   }
//
//   hinvbkia->Write();
// 	hpearsonkia->Write();
//   hinvbkiam->Write();
//   hinvbkias->Write();
//
// 	TF1 *eval = new TF1( "eval", PearsonVII, -1, 1, 4 );
// 	eval->SetParameters(5, .1, 1000, 0);
// 	eval->SetParNames( "m", "s", "y", "l" );
//
//   for( int i = 16; i < 201; i++ ){
//     stringstream getslice;
//     getslice << "InvbptKip" << i;
//     TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
//     temph->Draw();
//     c->SetLogy();
//     temph->Fit( fit, "R", "", beg, end );
//     temph->Draw();
// 		temph->Fit( eval, "R", "", beg, end );
// 		temph->Draw();
//     getslice << ".png";
//     // c->Print( getslice.str().c_str() );
//     hinvbkip->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
// 		hpearsonkip->SetBinContent( i, eval->Integral( -.6, .6)/.01 );
//     hinvbkipm->SetBinContent( i, fit->GetParameter(1) );
//     hinvbkips->SetBinContent( i, fit->GetParameter(2) );
//   }
//
//   hinvbkip->Write();
// 	hpearsonkip->Write();
//   hinvbkipm->Write();
//   hinvbkips->Write();
//
// 	TF1 *eval = new TF1( "eval", PearsonVII, -1, 1, 4 );
// 	eval->SetParameters(5, .1, 1000, 0);
// 	eval->SetParNames( "m", "s", "y", "l" );
//
//   for( int i = 16; i < 201; i++ ){
//     stringstream getslice;
//     getslice << "InvbptKin" << i;
//     TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
//     temph->Draw();
//     c->SetLogy();
//     temph->Fit( fit, "R", "", beg, end );
//     temph->Draw();
// 		temph->Fit( eval, "R", "", beg, end );
// 		temph->Draw();
//     getslice << ".png";
//     // c->Print( getslice.str().c_str() );
//     hinvbkin->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
// 		hpearsonkin->SetBinContent( i, eval->Integral( -.6, .6 )/.01 );
//     hinvbkinm->SetBinContent( i, fit->GetParameter(1) );
//     hinvbkins->SetBinContent( i, fit->GetParameter(2) );
//   }
//
//   hinvbkin->Write();
// 	hpearsonkin->Write();
//   hinvbkinm->Write();
//   hinvbkins->Write();
//
// 	TF1 *eval = new TF1( "eval", PearsonVII, -1, 1, 4 );
// 	eval->SetParameters(5, .1, 1000, 0);
// 	eval->SetParNames( "m", "s", "y", "l" );
//
//   double beg = -.05;
//   double end = .05;
//
//   for( int i = 16; i < 201; i++ ){
//     stringstream getslice;
//     getslice << "InvbptPria" << i;
//     TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
//     temph->Draw();
//     c->SetLogy();
//     temph->Fit( fit, "R", "", beg, end );
//     temph->Draw();
// 		temph->Fit( eval, "R", "", beg, end );
// 		temph->Draw();
//     getslice << ".png";
//     // c->Print( getslice.str().c_str() );
//     hinvbpria->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
// 		hpearsonpria->SetBinContent( i, eval->Integral( -.6, .6 )/.01 );
// 		hinvbpriam->SetBinContent( i, fit->GetParameter(1) );
//     hinvbprias->SetBinContent( i, fit->GetParameter(2) );
//   }
//
//   hinvbpria->Write();
// 	hpearsonpria->Write();
//   hinvbpriam->Write();
//   hinvbprias->Write();
//
// 	TF1 *eval = new TF1( "eval", PearsonVII, -1, 1, 4 );
// 	eval->SetParameters(5, .1, 1000, 0);
// 	eval->SetParNames( "m", "s", "y", "l" );
//
//   for( int i = 16; i < 201; i++ ){
//     stringstream getslice;
//     getslice << "InvbptPrip" << i;
//     TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
//     temph->Draw();
//     c->SetLogy();
//     temph->Fit( fit, "R", "", beg, end );
//     temph->Draw();
// 		temph->Fit( eval, "R", "", beg, end );
//     getslice << ".png";
//     // c->Print( getslice.str().c_str() );
//     hinvbprip->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
// 		hpearsonprip->SetBinContent( i, eval->Integral( -.6, .6 )/.01 );
//     hinvbpripm->SetBinContent( i, fit->GetParameter(1) );
//     hinvbprips->SetBinContent( i, fit->GetParameter(2) );
//   }
//
//   hinvbprip->Write();
// 	hpearsonprip->Write();
//   hinvbpripm->Write();
//   hinvbprips->Write();
//
// 	TF1 *eval = new TF1( "eval", PearsonVII, -1, 1, 4 );
// 	eval->SetParameters(5, .1, 1000, 0);
// 	eval->SetParNames( "m", "s", "y", "l" );
//
//   for( int i = 16; i < 201; i++ ){
//     stringstream getslice;
//     getslice << "InvbptPrin" << i;
//     TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
//     temph->Draw();
//     c->SetLogy();
//     temph->Fit( fit, "R", "", beg, end );
//     temph->Draw();
// 		temph->Fit( eval, "R", "", beg, end );
// 		temph->Draw();
// 	  getslice << ".png";
//     // c->Print( getslice.str().c_str() );
//     hinvbprin->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
// 		hpearsonprin->SetBinContent( i, eval->Integral( -.6, .6 )/.01 );
//     hinvbprinm->SetBinContent( i, fit->GetParameter(1) );
//     hinvbprins->SetBinContent( i, fit->GetParameter(2) );
//   }
//
//   hinvbprin->Write();
// 	hpearsonprin->Write();
//   hinvbprinm->Write();
//   hinvbprins->Write();


}
