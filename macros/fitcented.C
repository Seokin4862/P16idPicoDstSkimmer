void fitcented(){

  TFile *f = new TFile( "/home/sy34/workspace/safe/centedslices/centedslicesgraphs.root" );

  TCanvas *c = new TCanvas( "c","c" );

  TF1 *fit = new TF1( "fit", "gaus" );

  TFile *rootfile = new TFile( "fitcented.root", "RECREATE" )

  float binEdges[] = {0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18, 0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31, 0.32, 0.33, 0.34, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1.0, 1.05, 1.1, 1.15, 1.2, 1.25, 1.3, 1.35, 1.4, 1.45, 1.5, 1.55, 1.6, 1.65, 1.7, 1.75, 1.8, 1.85, 1.9, 1.95, 2.0};
  int nBins = 68;

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

  for( int i = 11; i < 36; i++ ){
    stringstream getslice;
    getslice << "InvbptPia" << i;
    TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
    temph->Draw();
    c->SetLogy();
    temph->Fit( fit, "R", "", beg, end );
    temph->Draw();
    getslice << ".png";
    c->Print( getslice.str().c_str() );
    hinvbpia->SetBinContent( i, fit->Integral( -1, 1 )/.01 );
    hinvbpiam->SetBinContent( i, fit->GetParameter(1) );
    hinvbpias->SetBinContent( i, fit->GetParameter(2) );
  }

  for( int i = 8; i < 41; i++ ){
    stringstream getslice;
    getslice << "InvbptPia" << i+28;
    TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
    temph->Draw();
    c->SetLogy();
    temph->Fit( fit, "R", "", beg, end );
    temph->Draw();
    getslice << ".png";
    c->Print( getslice.str().c_str() );
    hinvbpia->SetBinContent( i+28, fit->Integral( -1, 1 )/.05 );
    hinvbpiam->SetBinContent( i+28, fit->GetParameter(1) );
    hinvbpias->SetBinContent( i+28, fit->GetParameter(2) );
  }

  hinvbpia->Write();
  hinvbpiam->Write();
  hinvbpias->Write();


  double beg = -.05;
  double end = .05;

  for( int i = 11; i < 36; i++ ){
    stringstream getslice;
    getslice << "InvbptPin" << i;
    TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
    temph->Draw();
    c->SetLogy();
    temph->Fit( fit, "R", "", beg, end );
    temph->Draw();
    getslice << ".png";
    c->Print( getslice.str().c_str() );
    hinvbpin->SetBinContent( i, fit->Integral( -1, 1 )/.01 );
    hinvbpinm->SetBinContent( i, fit->GetParameter(1) );
    hinvbpins->SetBinContent( i, fit->GetParameter(2) );
  }

  for( int i = 8; i < 41; i++ ){
    stringstream getslice;
    getslice << "InvbptPin" << i+28;
    TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
    temph->Draw();
    c->SetLogy();
    temph->Fit( fit, "R", "", beg, end );
    temph->Draw();
    getslice << ".png";
    c->Print( getslice.str().c_str() );
    hinvbpin->SetBinContent( i+28, fit->Integral( -1, 1 )/.05 );
    hinvbpinm->SetBinContent( i+28, fit->GetParameter(1) );
    hinvbpins->SetBinContent( i+28, fit->GetParameter(2) );
  }

  hinvbpin->Write();
  hinvbpinm->Write();
  hinvbpins->Write();


  double beg = -.05;
  double end = .05;

  for( int i = 11; i < 36; i++ ){
    stringstream getslice;
    getslice << "InvbptPip" << i;
    TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
    temph->Draw();
    c->SetLogy();
    temph->Fit( fit, "R", "", beg, end );
    temph->Draw();
    getslice << ".png";
    c->Print( getslice.str().c_str() );
    hinvbpip->SetBinContent( i, fit->Integral( -1, 1 )/.01 );
    hinvbpipm->SetBinContent( i, fit->GetParameter(1) );
    hinvbpips->SetBinContent( i, fit->GetParameter(2) );
  }

  for( int i = 8; i < 41; i++ ){
    stringstream getslice;
    getslice << "InvbptPip" << i+28;
    TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
    temph->Draw();
    c->SetLogy();
    temph->Fit( fit, "R", "", beg, end );
    temph->Draw();
    getslice << ".png";
    c->Print( getslice.str().c_str() );
    hinvbpip->SetBinContent( i+28, fit->Integral( -1, 1 )/.05 );
    hinvbpipm->SetBinContent( i+28, fit->GetParameter(1) );
    hinvbpips->SetBinContent( i+28, fit->GetParameter(2) );
  }

  hinvbpip->Write();
  hinvbpipm->Write();
  hinvbpips->Write();
}
