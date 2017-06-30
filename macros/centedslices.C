

void centedslices() {

TFile * f = new TFile( "/home/sy34/workspace/safe/cented/centedInvBeta.root" );

TFile * rootfile = new TFile("centedslicesgraphs.root", "RECREATE" );

TCanvas * c = new TCanvas("c","c");

TH2 *hInvBeta = (TH2*)f->Get( "hInvBetavsMomPion_a" );

for( int i = 11; i < 36; i++ ){
  strinstream name;
  name << "InvbptPia" << i;
  int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *hist = hdEdx->ProjectionY( name.str().c_str() , n1 , n2 );
  stringstream histtitle;
  histtitle << "all charge 1/Beta for momentum range " << .01*(i-1) << " to " << .01*(i) << "Pion Centered" ;
  hist->SetTitle( histtitle.str().c_str() );
  hist->SetYTitle( "Number of Tracks" );
  hist->Write();
  hist->Draw();
  c->SetLogy();
  name << ".png";
  c->Print( name.str().c_str() );
}
}
