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

Double_t eval( Double_t *x, Double_t *par ){
	Double_t x0 = x[0];

	Double_t m = par[0];
	Double_t s = par[1];
	Double_t y = par[2];
	Double_t l = par[3];

	double a1 = s * TMath::Sqrt( 2 * m - 3 );

	double a = ( y )	/ ( a1 * TMath::Beta( m - 0.5, -0.5 ) );
	double b = pow( 1 + pow( ( x - L ) / a1, 2 ), -m );

	return a * b;
}

void fittestslices(){

  TFile *f = new TFile( "/home/sy34/workspace/safe/testslices/testslices.root" );

  TCanvas *c = new TCanvas( "c","c" );

  TF1 *fit = new TF1( "fit", "gaus" );



  TFile *rootfile = new TFile( "fittestslices.root", "RECREATE" );

  TH1D * hinvbpia = new TH1D( "hinvbpia", "Integral of the Pion Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpiam = new TH1D( "hinvbpiam", "Mean of the Pion Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpias = new TH1D( "hinvbpias", "Sigma of the Pion Fit vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbpip = new TH1D( "hinvbpip", "Integral of the Pion Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpipm = new TH1D( "hinvbpipm", "Mean of the Pion Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpips = new TH1D( "hinvbpips", "Sigma of the Pion Fit vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbpin = new TH1D( "hinvbpin", "Integral of the Pion Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpinm = new TH1D( "hinvbpinm", "Mean of the Pion Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpins = new TH1D( "hinvbpins", "Sigma of the Pion Fit vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbkia = new TH1D( "hinvbkia", "Integral of the Kaon Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkiam = new TH1D( "hinvbkiam", "Mean of the Kaon Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkias = new TH1D( "hinvbkias", "Sigma of the Kaon Fit vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbkip = new TH1D( "hinvbkip", "Integral of the Kaon Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkipm = new TH1D( "hinvbkipm", "Mean of the Kaon Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkips = new TH1D( "hinvbkips", "Sigma of the Kaon Fit vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbkin = new TH1D( "hinvbkin", "Integral of the Kaon Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkinm = new TH1D( "hinvbkinm", "Mean of the Kaon Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbkins = new TH1D( "hinvbkins", "Sigma of the Kaon Fit vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbpria = new TH1D( "hinvbpria", "Integral of the Proton Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpriam = new TH1D( "hinvbpriam", "Mean of the Proton Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbprias = new TH1D( "hinvbprias", "Sigma of the Proton Fit vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbprip = new TH1D( "hinvbprip", "Integral of the Proton Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbpripm = new TH1D( "hinvbpripm", "Mean of the Proton Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbprips = new TH1D( "hinvbprips", "Sigma of the Proton Fit vs Total Momentum", 200, 0, 2 );

  TH1D * hinvbprin = new TH1D( "hinvbprin", "Integral of the Proton Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbprinm = new TH1D( "hinvbprinm", "Mean of the Proton Fit vs Total Momentum", 200, 0, 2 );
  TH1D * hinvbprins = new TH1D( "hinvbprins", "Sigma of the Proton Fit vs Total Momentum", 200, 0, 2 );


	TF1 *eval = new TF1( "eval", "eval", -1, 1, 4 );
	eval->SetParameters(0, .1, 1000, 0);
	eval->SetParNames( "mean", "sigma", "yield", "lambda" );

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
    getslice << ".png";
    c->Print( getslice.str().c_str() );
    hinvbpia->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
    hinvbpiam->SetBinContent( i, fit->GetParameter(1) );
    hinvbpias->SetBinContent( i, fit->GetParameter(2) );
  }

  hinvbpia->Write();
  hinvbpiam->Write();
  hinvbpias->Write();


  // double beg = -.05;
  // double end = .05;
  //
  // for( int i = 16; i < 201; i++ ){
  //   stringstream getslice;
  //   getslice << "InvbptPip" << i;
  //   TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
  //   temph->Draw();
  //   c->SetLogy();
  //   temph->Fit( fit, "R", "", beg, end );
  //   temph->Draw();
  //   getslice << ".png";
  //   // c->Print( getslice.str().c_str() );
  //   hinvbpip->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
  //   hinvbpipm->SetBinContent( i, fit->GetParameter(1) );
  //   hinvbpips->SetBinContent( i, fit->GetParameter(2) );
  // }
  //
  // hinvbpip->Write();
  // hinvbpipm->Write();
  // hinvbpips->Write();
  //
  //
  // double beg = -.05;
  // double end = .05;
  //
  // for( int i = 16; i < 201; i++ ){
  //   stringstream getslice;
  //   getslice << "InvbptPin" << i;
  //   TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
  //   temph->Draw();
  //   c->SetLogy();
  //   temph->Fit( fit, "R", "", beg, end );
  //   temph->Draw();
  //   getslice << ".png";
  //   // c->Print( getslice.str().c_str() );
  //   hinvbpin->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
  //   hinvbpinm->SetBinContent( i, fit->GetParameter(1) );
  //   hinvbpins->SetBinContent( i, fit->GetParameter(2) );
  // }
  //
  // hinvbpin->Write();
  // hinvbpinm->Write();
  // hinvbpins->Write();
  //
  //
  // double beg = -.03;
  // double end = .03;
  //
  // for( int i = 16; i < 201; i++ ){
  //   stringstream getslice;
  //   getslice << "InvbptKia" << i;
  //   TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
  //   temph->Draw();
  //   c->SetLogy();
  //   temph->Fit( fit, "R", "", beg, end );
  //   temph->Draw();
  //   getslice << ".png";
  //   // c->Print( getslice.str().c_str() );
  //   hinvbkia->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
  //   hinvbkiam->SetBinContent( i, fit->GetParameter(1) );
  //   hinvbkias->SetBinContent( i, fit->GetParameter(2) );
  // }
  //
  // hinvbkia->Write();
  // hinvbkiam->Write();
  // hinvbkias->Write();
  //
  //
  // double beg = -.03;
  // double end = .03;
  //
  // for( int i = 16; i < 201; i++ ){
  //   stringstream getslice;
  //   getslice << "InvbptKip" << i;
  //   TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
  //   temph->Draw();
  //   c->SetLogy();
  //   temph->Fit( fit, "R", "", beg, end );
  //   temph->Draw();
  //   getslice << ".png";
  //   // c->Print( getslice.str().c_str() );
  //   hinvbkip->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
  //   hinvbkipm->SetBinContent( i, fit->GetParameter(1) );
  //   hinvbkips->SetBinContent( i, fit->GetParameter(2) );
  // }
  //
  // hinvbkip->Write();
  // hinvbkipm->Write();
  // hinvbkips->Write();
  //
  //
  // double beg = -.03;
  // double end = .03;
  //
  // for( int i = 16; i < 201; i++ ){
  //   stringstream getslice;
  //   getslice << "InvbptKin" << i;
  //   TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
  //   temph->Draw();
  //   c->SetLogy();
  //   temph->Fit( fit, "R", "", beg, end );
  //   temph->Draw();
  //   getslice << ".png";
  //   // c->Print( getslice.str().c_str() );
  //   hinvbkin->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
  //   hinvbkinm->SetBinContent( i, fit->GetParameter(1) );
  //   hinvbkins->SetBinContent( i, fit->GetParameter(2) );
  // }
  //
  // hinvbkin->Write();
  // hinvbkinm->Write();
  // hinvbkins->Write();
  //
  //
  // double beg = -.05;
  // double end = .05;
  //
  // for( int i = 16; i < 201; i++ ){
  //   stringstream getslice;
  //   getslice << "InvbptPria" << i;
  //   TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
  //   temph->Draw();
  //   c->SetLogy();
  //   temph->Fit( fit, "R", "", beg, end );
  //   temph->Draw();
  //   getslice << ".png";
  //   // c->Print( getslice.str().c_str() );
  //   hinvbpria->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
  //   hinvbpriam->SetBinContent( i, fit->GetParameter(1) );
  //   hinvbprias->SetBinContent( i, fit->GetParameter(2) );
  // }
  //
  // hinvbpria->Write();
  // hinvbpriam->Write();
  // hinvbprias->Write();
  //
  //
  // double beg = -.05;
  // double end = .05;
  //
  // for( int i = 16; i < 201; i++ ){
  //   stringstream getslice;
  //   getslice << "InvbptPrip" << i;
  //   TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
  //   temph->Draw();
  //   c->SetLogy();
  //   temph->Fit( fit, "R", "", beg, end );
  //   temph->Draw();
  //   getslice << ".png";
  //   // c->Print( getslice.str().c_str() );
  //   hinvbprip->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
  //   hinvbpripm->SetBinContent( i, fit->GetParameter(1) );
  //   hinvbprips->SetBinContent( i, fit->GetParameter(2) );
  // }
  //
  // hinvbprip->Write();
  // hinvbpripm->Write();
  // hinvbprips->Write();
  //
  //
  //
  // double beg = -.05;
  // double end = .05;
  //
  // for( int i = 16; i < 201; i++ ){
  //   stringstream getslice;
  //   getslice << "InvbptPrin" << i;
  //   TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
  //   temph->Draw();
  //   c->SetLogy();
  //   temph->Fit( fit, "R", "", beg, end );
  //   temph->Draw();
  //   getslice << ".png";
  //   // c->Print( getslice.str().c_str() );
  //   hinvbprin->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
  //   hinvbprinm->SetBinContent( i, fit->GetParameter(1) );
  //   hinvbprins->SetBinContent( i, fit->GetParameter(2) );
  // }
  //
  // hinvbprin->Write();
  // hinvbprinm->Write();
  // hinvbprins->Write();


}
