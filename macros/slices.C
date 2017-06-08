

void slices() {

TFile * f = new TFile( "/home/sy34/workspace/safe/8InvBetadEdxMom/dEdxandInvBetavsMom.root" );

TCanvas * c = new TCanvas("c","c");

TH2 *hdEdx = (TH2*)f->Get( "DedxvsMom" );
TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMom" );

hdEdx->Draw("colz");
c->SetLogz();
c->Print( "dEdxvsMom.png" );

hInvBeta->Draw("colz");
c->SetLogz();
c->Print( "InvBetavsMom.png" );

for( int i = 1; i < 41 ; i++ ) {

  stringstream mona;
  mona << "mona" << i;
  int m1 = hdEdx->GetXaxis()->FindBin( .05*(i-1) );
  int m2 = hdEdx->GetXaxis()->FindBin( .05*(i) );
  TH1 *kid = hdEdx->ProjectionY( mona.str().c_str() , m1 , m2 );
  stringstream kidtitle;
  kidtitle << "dEdx for momentum range " << .05*(i-1) << " to " << .05*(i) ;
  kid->SetTitle( kidtitle.str().c_str() );
  kid->Draw();
  c->SetLogy();
  mona << ".png";
  c->Print( mona.str().c_str() );

  stringstream lisa;
  lisa << "lisa" << i;
  int l1 = hInvBeta->GetXaxis()->FindBin( .05*(i-1) );
  int l2 = hInvBeta->GetXaxis()->FindBin( .05*(i) );
  TH1 *africa = hInvBeta->ProjectionY( lisa.str().c_str(), l1, l2 );
  stringstream africatitle;
  africatitle << "InvBeta for momentum range " << .05*(i-1) << " to " << .05(i) ;
  africa->SetTitle( africatitle.str().c_str() );
  africa->Draw();
  c->SetLogy();
  lisa << ".png";
  c->Print( lisa.str().c_str() );
}

}
