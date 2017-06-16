

void slices() {

TFile * f = new TFile( "/home/sy34/workspace/safe/newbtofs/newbtofs.root" );

TCanvas * c = new TCanvas("c","c");

TH2 *hdEdx = (TH2*)f->Get( "DedxvsMom1" );
TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMom1" );

hdEdx->Draw("colz");
c->SetLogz();

for( int i = 1; i < 36 ; i++ ) {
  stringstream angie;
  angie << "dEdxS" << i;
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

for( int i = 7; i < 41 ; i++ ) {
  stringstream mitchell;
  mitchell << "dEdxL" << i;
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

for( int i = 1; i < 36 ; i++ ) {
  stringstream poor;
  poor << "InvBetaS" << i;
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

for( int i = 7; i < 41; i++ ) {
  stringstream phi;
  phi << "InvBetaL" << i;
  int h1 = hInvBeta->GetXaxis()->FindBin( .05*(i-1) );
  int h2 = hInvBeta->GetXaxis()->FindBin( .05*(i) );
  TH1 *will = hInvBeta->ProjectionY( poor.str().c_str(), h1, h2 );
  stringstream willtitle;
  willtitle << "all charge InvBeta for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  will->SetTitle( willtitle.str().c_str() );
  will->SetYTitle( "Number of Tracks" );
  will->Draw();
  c->SetLogy();
  poor << ".png";
  c->Print( poor.str().c_str() );

}

}
