// virtual double eval( double x, double bw = 1.0 ){
//
// 		// e is an efficiency param
// 		double a1 = s * TMath::Sqrt( 2 * m - 3 );
// 		double a =  (y * bw) / ( a1 * TMath::Beta( m-0.5, 0.5 ) );
// 		double b = pow( 1 + pow( ( x - l ) / a1, 2 ), -m );
//
// 		return a * b;
// 	}


void fittestslices(){

  TFile *f = new TFile( "/home/sy34/workspace/safe/testslices/testslices.root" );

  TCanvas *c = new TCanvas( "c","c" );

  TF1 *fit = new TF1( "fit", "gaus" );

  // TF1 *eval = new TF1( "eval", "eval" );

  TFile *rootfile = new TFile( "fittestslices.root", "RECREATE" );

  TH1D * hinvbpia = new TH1D( "hinvbpia", "Integral of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbpiam = new TH1D( "hinvbpiam", "Mean of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbpias = new TH1D( "hinvbpias", "Sigma of the Pion Fit vs Total Momentum", nBins, binEdges );

  TH1D * hinvbpip = new TH1D( "hinvbpip", "Integral of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbpipm = new TH1D( "hinvbpipm", "Mean of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbpips = new TH1D( "hinvbpips", "Sigma of the Pion Fit vs Total Momentum", nBins, binEdges );

  TH1D * hinvbpin = new TH1D( "hinvbpin", "Integral of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbpinm = new TH1D( "hinvbpinm", "Mean of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbpins = new TH1D( "hinvbpins", "Sigma of the Pion Fit vs Total Momentum", nBins, binEdges );

  TH1D * hinvbkia = new TH1D( "hinvbkia", "Integral of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbkiam = new TH1D( "hinvbkiam", "Mean of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbkias = new TH1D( "hinvbkias", "Sigma of the Pion Fit vs Total Momentum", nBins, binEdges );

  TH1D * hinvbkip = new TH1D( "hinvbkip", "Integral of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbkipm = new TH1D( "hinvbkipm", "Mean of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbkips = new TH1D( "hinvbkips", "Sigma of the Pion Fit vs Total Momentum", nBins, binEdges );

  TH1D * hinvbkin = new TH1D( "hinvbkin", "Integral of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbkinm = new TH1D( "hinvbkinm", "Mean of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbkins = new TH1D( "hinvbkins", "Sigma of the Pion Fit vs Total Momentum", nBins, binEdges );

  TH1D * hinvbpria = new TH1D( "hinvbpria", "Integral of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbpriam = new TH1D( "hinvbpriam", "Mean of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbprias = new TH1D( "hinvbprias", "Sigma of the Pion Fit vs Total Momentum", nBins, binEdges );

  TH1D * hinvbprip = new TH1D( "hinvbprip", "Integral of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbpripm = new TH1D( "hinvbpripm", "Mean of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbprips = new TH1D( "hinvbprips", "Sigma of the Pion Fit vs Total Momentum", nBins, binEdges );

  TH1D * hinvbprin = new TH1D( "hinvbprin", "Integral of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbprinm = new TH1D( "hinvbprinm", "Mean of the Pion Fit vs Total Momentum", nBins, binEdges );
  TH1D * hinvbprins = new TH1D( "hinvbprins", "Sigma of the Pion Fit vs Total Momentum", nBins, binEdges );



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
    getslice << ".png";
    c->Print( getslice.str().c_str() );
    hinvbpia->SetBinContent( i, fit->Integral( -.1, .1 )/.01 );
    hinvbpiam->SetBinContent( i, fit->GetParameter(1) );
    hinvbpias->SetBinContent( i, fit->GetParameter(2) );
  }

  hinvbpia->Write();
  hinvbpiam->Write();
  hinvbpias->Write();



}
