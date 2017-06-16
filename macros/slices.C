

void slices() {

TFile * f = new TFile( "/home/sy34/workspace/safe/newbtofs/newbtofs.root" );

TCanvas * c = new TCanvas("c","c");

TH2 *hdEdx = (TH2*)f->Get( "DedxvsMom1" );
TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMom1" );

hdEdx->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream angie;
  angie << "adEdxS" << i;
  int a1 = hdEdx->GetXaxis()->FindBin( .01*(i-1) );
  int a2 = hdEdx->GetXaxis()->FindBin( .01*(i) );
  TH1 *bobby = hdEdx->ProjectionY( angie.str().c_str() , a1 , a2 );
  stringstream bobbytitle;
  bobbytitle << "all charge dEdx for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  bobby->SetTitle( bobbytitle.str().c_str() );
  bobby->SetYTitle( "Number of Tracks" );
  bobby->Draw();
  c->SetLogy();
  angie << ".png";
  c->Print( angie.str().c_str() );

}

for( int i = 8; i < 41 ; i++ ) {
  stringstream mitchell;
  mitchell << "adEdxL" << i;
  int c1 = hdEdx->GetXaxis()->FindBin( .05*(i-1) );
  int c2 = hdEdx->GetXaxis()->FindBin( .05*(i) );
  TH1 *newmark = hdEdx->ProjectionY( mitchell.str().c_str() , c1 , c2 );
  stringstream newmarktitle;
  newmarktitle << "all charge dEdx for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  newmark->SetTitle( newmarktitle.str().c_str() );
  newmark->SetYTitle( "Number of Tracks" );
  newmark->Draw();
  c->SetLogy();
  mitchell << ".png";
  c->Print( mitchell.str().c_str() );

}

hInvBeta->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream poor;
  poor << "aInvBetaS" << i;
  int p1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int p2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *robin = hInvBeta->ProjectionY ( poor.str().c_str(), p1, p2 );
  stringstream robintitle;
  robintitle << "all charge InvBeta for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  robin->SetTitle( robintitle.str().c_str() );
  robin->SetYTitle( "Number of Tracks" );
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
  TH1 *will = hInvBeta->ProjectionY( poor.str().c_str(), h1, h2 );
  stringstream willtitle;
  willtitle << "all charge InvBeta for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  will->SetTitle( willtitle.str().c_str() );
  will->SetYTitle( "Number of Tracks" );
  will->Draw();
  c->SetLogy();
  phi << ".png";
  c->Print( phi.str().c_str() );

}




TH2 *hdEdx = (TH2*)f->Get( "DedxvsMom2" );
TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMom2" );

hdEdx->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream angie;
  angie << "pdEdxS" << i;
  int a1 = hdEdx->GetXaxis()->FindBin( .01*(i-1) );
  int a2 = hdEdx->GetXaxis()->FindBin( .01*(i) );
  TH1 *bobby = hdEdx->ProjectionY( angie.str().c_str() , a1 , a2 );
  stringstream bobbytitle;
  bobbytitle << "pos charge dEdx for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  bobby->SetTitle( bobbytitle.str().c_str() );
  bobby->SetYTitle( "Number of Tracks" );
  bobby->Draw();
  c->SetLogy();
  angie << ".png";
  c->Print( angie.str().c_str() );

}

for( int i = 8; i < 41 ; i++ ) {
  stringstream mitchell;
  mitchell << "pdEdxL" << i;
  int c1 = hdEdx->GetXaxis()->FindBin( .05*(i-1) );
  int c2 = hdEdx->GetXaxis()->FindBin( .05*(i) );
  TH1 *newmark = hdEdx->ProjectionY( mitchell.str().c_str() , c1 , c2 );
  stringstream newmarktitle;
  newmarktitle << "pos charge dEdx for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  newmark->SetTitle( newmarktitle.str().c_str() );
  newmark->SetYTitle( "Number of Tracks" );
  newmark->Draw();
  c->SetLogy();
  mitchell << ".png";
  c->Print( mitchell.str().c_str() );

}

hInvBeta->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream poor;
  poor << "pInvBetaS" << i;
  int p1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int p2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *robin = hInvBeta->ProjectionY ( poor.str().c_str(), p1, p2 );
  stringstream robintitle;
  robintitle << "pos charge InvBeta for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  robin->SetTitle( robintitle.str().c_str() );
  robin->SetYTitle( "Number of Tracks" );
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
  TH1 *will = hInvBeta->ProjectionY( poor.str().c_str(), h1, h2 );
  stringstream willtitle;
  willtitle << "pos charge InvBeta for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  will->SetTitle( willtitle.str().c_str() );
  will->SetYTitle( "Number of Tracks" );
  will->Draw();
  c->SetLogy();
  phi << ".png";
  c->Print( phi.str().c_str() );

}




TH2 *hdEdx = (TH2*)f->Get( "DedxvsMom3" );
TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMom3" );

hdEdx->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream angie;
  angie << "ndEdxS" << i;
  int a1 = hdEdx->GetXaxis()->FindBin( .01*(i-1) );
  int a2 = hdEdx->GetXaxis()->FindBin( .01*(i) );
  TH1 *bobby = hdEdx->ProjectionY( angie.str().c_str() , a1 , a2 );
  stringstream bobbytitle;
  bobbytitle << "neg charge dEdx for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  bobby->SetTitle( bobbytitle.str().c_str() );
  bobby->SetYTitle( "Number of Tracks" );
  bobby->Draw();
  c->SetLogy();
  angie << ".png";
  c->Print( angie.str().c_str() );

}

for( int i = 8; i < 41 ; i++ ) {
  stringstream mitchell;
  mitchell << "ndEdxL" << i;
  int c1 = hdEdx->GetXaxis()->FindBin( .05*(i-1) );
  int c2 = hdEdx->GetXaxis()->FindBin( .05*(i) );
  TH1 *newmark = hdEdx->ProjectionY( mitchell.str().c_str() , c1 , c2 );
  stringstream newmarktitle;
  newmarktitle << "neg charge dEdx for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  newmark->SetTitle( newmarktitle.str().c_str() );
  newmark->SetYTitle( "Number of Tracks" );
  newmark->Draw();
  c->SetLogy();
  mitchell << ".png";
  c->Print( mitchell.str().c_str() );

}

hInvBeta->Draw("colz");
c->SetLogz();

for( int i = 11; i < 36 ; i++ ) {
  stringstream poor;
  poor << "nInvBetaS" << i;
  int p1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int p2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *robin = hInvBeta->ProjectionY ( poor.str().c_str(), p1, p2 );
  stringstream robintitle;
  robintitle << "neg charge InvBeta for momentum range " << .01*(i-1) << " to " << .01*(i) ;
  robin->SetTitle( robintitle.str().c_str() );
  robin->SetYTitle( "Number of Tracks" );
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
  TH1 *will = hInvBeta->ProjectionY( poor.str().c_str(), h1, h2 );
  stringstream willtitle;
  willtitle << "neg charge InvBeta for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  will->SetTitle( willtitle.str().c_str() );
  will->SetYTitle( "Number of Tracks" );
  will->Draw();
  c->SetLogy();
  phi << ".png";
  c->Print( phi.str().c_str() );

}

}
