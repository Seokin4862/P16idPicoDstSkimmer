

void slices() {

TFile * f = new TFile( "/home/sy34/workspace/safe/lndedx/lndedx.root" );

TFile * rootfile = new TFile("slicesgraphs.root", "RECREATE" );

TCanvas * c = new TCanvas("c","c");

TH2 *hdEdx = (TH2*)f->Get( "LnDedxvsMom1" );
TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMom1" );

hdEdx->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream angie;
  angie << "alndEdxK" << i;
  int a1 = hdEdx->GetXaxis()->FindBin( .01*(i-1) );
  int a2 = hdEdx->GetXaxis()->FindBin( .01*(i) );
  TH1 *bobby = hdEdx->ProjectionY( angie.str().c_str() , a1 , a2 );
  stringstream bobbytitle;
  bobbytitle << "all charge ln(dEdx) for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  bobby->SetTitle( bobbytitle.str().c_str() );
  bobby->SetYTitle( "Number of Tracks" );
  bobby->GetXaxis()->SetRange( 0, 600 );
  bobby->Write();
  bobby->Draw();
  c->SetLogy();
  angie << ".png";
  c->Print( angie.str().c_str() );

}

for( int i = 8; i < 41 ; i++ ) {
  stringstream mitchell;
  mitchell << "alndEdxL" << i;
  int c1 = hdEdx->GetXaxis()->FindBin( .05*(i-1) );
  int c2 = hdEdx->GetXaxis()->FindBin( .05*(i) );
  TH1 *newmark = hdEdx->ProjectionY( mitchell.str().c_str() , c1 , c2 );
  stringstream newmarktitle;
  newmarktitle << "all charge ln(dEdx) for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  newmark->SetTitle( newmarktitle.str().c_str() );
  newmark->SetYTitle( "Number of Tracks" );
  newmark->GetXaxis()->SetRange( 0, 600 );
  newmark->Write();
  newmark->Draw();
  c->SetLogy();
  mitchell << ".png";
  c->Print( mitchell.str().c_str() );

}

hInvBeta->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream poor;
  poor << "aInvBetaK" << i;
  int p1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int p2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *robin = hInvBeta->ProjectionY ( poor.str().c_str(), p1, p2 );
  stringstream robintitle;
  robintitle << "all charge InvBeta for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  robin->SetTitle( robintitle.str().c_str() );
  robin->SetYTitle( "Number of Tracks" );
  robin->Write();
  robin->Draw();
  c->SetLogy();
  poor << ".png";
  c->Print( poor.str().c_str() );

}

for( int i = 8; i < 41; i++ ) {
  stringstream phi;
  phi << "aInvBetaL" << i;
  int h1 = hInvBeta->GetXaxis()->FindBin( .05*(i-1) );
  int h2 = hInvBeta->GetXaxis()->FindBin( .05*(i) );
  TH1 *will = hInvBeta->ProjectionY( phi.str().c_str(), h1, h2 );
  stringstream willtitle;
  willtitle << "all charge InvBeta for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  will->SetTitle( willtitle.str().c_str() );
  will->SetYTitle( "Number of Tracks" );
  will->Write();
  will->Draw();
  c->SetLogy();
  phi << ".png";
  c->Print( phi.str().c_str() );

}




TH2 *hdEdx = (TH2*)f->Get( "LnDedxvsMom2" );
TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMom2" );

hdEdx->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream angie;
  angie << "plndEdxK" << i;
  int a1 = hdEdx->GetXaxis()->FindBin( .01*(i-1) );
  int a2 = hdEdx->GetXaxis()->FindBin( .01*(i) );
  TH1 *bobby = hdEdx->ProjectionY( angie.str().c_str() , a1 , a2 );
  stringstream bobbytitle;
  bobbytitle << "pos charge ln(dEdx) for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  bobby->SetTitle( bobbytitle.str().c_str() );
  bobby->SetYTitle( "Number of Tracks" );
  bobby->GetXaxis()->SetRange( 0, 600 );
  bobby->Write();
  bobby->Draw();
  c->SetLogy();
  angie << ".png";
  c->Print( angie.str().c_str() );

}

for( int i = 8; i < 41 ; i++ ) {
  stringstream mitchell;
  mitchell << "plndEdxL" << i;
  int c1 = hdEdx->GetXaxis()->FindBin( .05*(i-1) );
  int c2 = hdEdx->GetXaxis()->FindBin( .05*(i) );
  TH1 *newmark = hdEdx->ProjectionY( mitchell.str().c_str() , c1 , c2 );
  stringstream newmarktitle;
  newmarktitle << "pos charge ln(dEdx) for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  newmark->SetTitle( newmarktitle.str().c_str() );
  newmark->SetYTitle( "Number of Tracks" );
  newmark->GetXaxis()->SetRange( 0, 600 );
  newmark->Write();
  newmark->Draw();
  c->SetLogy();
  mitchell << ".png";
  c->Print( mitchell.str().c_str() );

}

hInvBeta->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream poor;
  poor << "pInvBetaK" << i;
  int p1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int p2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *robin = hInvBeta->ProjectionY ( poor.str().c_str(), p1, p2 );
  stringstream robintitle;
  robintitle << "pos charge InvBeta for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  robin->SetTitle( robintitle.str().c_str() );
  robin->SetYTitle( "Number of Tracks" );
  robin->Write();
  robin->Draw();
  c->SetLogy();
  poor << ".png";
  c->Print( poor.str().c_str() );

}

for( int i = 8; i < 41; i++ ) {
  stringstream phi;
  phi << "pInvBetaL" << i;
  int h1 = hInvBeta->GetXaxis()->FindBin( .05*(i-1) );
  int h2 = hInvBeta->GetXaxis()->FindBin( .05*(i) );
  TH1 *will = hInvBeta->ProjectionY( phi.str().c_str(), h1, h2 );
  stringstream willtitle;
  willtitle << "pos charge InvBeta for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  will->SetTitle( willtitle.str().c_str() );
  will->SetYTitle( "Number of Tracks" );
  will->Write();
  will->Draw();
  c->SetLogy();
  phi << ".png";
  c->Print( phi.str().c_str() );

}




TH2 *hdEdx = (TH2*)f->Get( "LnDedxvsMom3" );
TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMom3" );

hdEdx->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream angie;
  angie << "nlndEdxK" << i;
  int a1 = hdEdx->GetXaxis()->FindBin( .01*(i-1) );
  int a2 = hdEdx->GetXaxis()->FindBin( .01*(i) );
  TH1 *bobby = hdEdx->ProjectionY( angie.str().c_str() , a1 , a2 );
  stringstream bobbytitle;
  bobbytitle << "neg charge ln(dEdx) for moment um range " << .01*(i-1) << " to " << .01*(i) ;
  bobby->SetTitle( bobbytitle.str().c_str() );
  bobby->SetYTitle( "Number of Tracks" );
  bobby->GetXaxis()->SetRange( 0, 600 );
  bobby->Write();
  bobby->Draw();
  c->SetLogy();
  angie << ".png";
  c->Print( angie.str().c_str() );

}

for( int i = 8; i < 41 ; i++ ) {
  stringstream mitchell;
  mitchell << "nlndEdxL" << i;
  int c1 = hdEdx->GetXaxis()->FindBin( .05*(i-1) );
  int c2 = hdEdx->GetXaxis()->FindBin( .05*(i) );
  TH1 *newmark = hdEdx->ProjectionY( mitchell.str().c_str() , c1 , c2 );
  stringstream newmarktitle;
  newmarktitle << "neg charge ln(dEdx) for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  newmark->SetTitle( newmarktitle.str().c_str() );
  newmark->SetYTitle( "Number of Tracks" );
  newmark->GetXaxis()->SetRange( 0, 600 );
  newmark->Write();
  newmark->Draw();
  c->SetLogy();
  mitchell << ".png";
  c->Print( mitchell.str().c_str() );

}

hInvBeta->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream poor;
  poor << "nInvBetaK" << i;
  int p1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int p2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *robin = hInvBeta->ProjectionY ( poor.str().c_str(), p1, p2 );
  stringstream robintitle;
  robintitle << "neg charge InvBeta for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  robin->SetTitle( robintitle.str().c_str() );
  robin->SetYTitle( "Number of Tracks" );
  robin->Write();
  robin->Draw();
  c->SetLogy();
  poor << ".png";
  c->Print( poor.str().c_str() );

}

for( int i = 8; i < 41; i++ ) {
  stringstream phi;
  phi << "nInvBetaL" << i;
  int h1 = hInvBeta->GetXaxis()->FindBin( .05*(i-1) );
  int h2 = hInvBeta->GetXaxis()->FindBin( .05*(i) );
  TH1 *will = hInvBeta->ProjectionY( phi.str().c_str(), h1, h2 );
  stringstream willtitle;
  willtitle << "neg charge InvBeta for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  will->SetTitle( willtitle.str().c_str() );
  will->SetYTitle( "Number of Tracks" );
  will->Write();
  will->Draw();
  c->SetLogy();
  phi << ".png";
  c->Print( phi.str().c_str() );

}

rootfile->Close();

}
