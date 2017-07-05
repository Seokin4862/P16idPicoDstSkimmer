

void centedslices() {

TFile * f = new TFile( "/home/sy34/workspace/safe/cented/centedInvBeta.root" );

TFile * rootfile = new TFile("centedslicesgraphs.root", "RECREATE" );

TCanvas * c = new TCanvas("c","c");

TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomPion_a" );

for( int i = 11; i < 36; i++ ){
  stringstream name;
  name << "InvbptPia" << i;
  int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
  stringstream histtitle;
  histtitle << "1/Beta for Momentum Range for All Charge " << .01*(i-1) << " to " << .01*(i) << " Pion Centered" ;
  hist->SetTitle( histtitle.str().c_str() );
  hist->SetYTitle( "Number of Tracks" );
  hist->Write();
  hist->Draw();
  c->SetLogy();
  name << ".png";
  c->Print( name.str().c_str() );
}

for( int i = 8; i < 41; i++ ){
  stringstream name;
  name << "InvbptPia" << i+28;
  int n1 = hInvBeta->GetXaxis()->FindBin( .05*(i-1) );
  int n2 = hInvBeta->GetXaxis()->FindBin( .05*(i) );
  TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
  stringstream histtitle;
  histtitle << "1/Beta for Momentum Range for All Charge " << .05*(i-1) << " to " << .05*(i) << " Pion Centered" ;
  hist->SetTitle( histtitle.str().c_str() );
  hist->SetYTitle( "Number of Tracks" );
  hist->Write();
  hist->Draw();
  c->SetLogy();
  name << ".png";
  c->Print( name.str().c_str() );
}


TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomPion_p" );

for( int i = 11; i < 36; i++ ){
  stringstream name;
  name << "InvbptPip" << i;
  int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
  stringstream histtitle;
  histtitle << "1/Beta for Momentum Range for Positive Charge " << .01*(i-1) << " to " << .01*(i) << " Pion Centered" ;
  hist->SetTitle( histtitle.str().c_str() );
  hist->SetYTitle( "Number of Tracks" );
  hist->Write();
  hist->Draw();
  c->SetLogy();
  name << ".png";
  c->Print( name.str().c_str() );
}

for( int i = 8; i < 41; i++ ){
  stringstream name;
  name << "InvbptPip" << i+28;
  int n1 = hInvBeta->GetXaxis()->FindBin( .05*(i-1) );
  int n2 = hInvBeta->GetXaxis()->FindBin( .05*(i) );
  TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
  stringstream histtitle;
  histtitle << "1/Beta for Momentum Range for Positive Charge " << .05*(i-1) << " to " << .05*(i) << " Pion Centered" ;
  hist->SetTitle( histtitle.str().c_str() );
  hist->SetYTitle( "Number of Tracks" );
  hist->Write();
  hist->Draw();
  c->SetLogy();
  name << ".png";
  c->Print( name.str().c_str() );
}


TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomPion_n" );

for( int i = 11; i < 36; i++ ){
  stringstream name;
  name << "InvbptPin" << i;
  int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
  int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
  TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
  stringstream histtitle;
  histtitle << "1/Beta for Momentum Range for Negative Charge " << .01*(i-1) << " to " << .01*(i) << " Pion Centered" ;
  hist->SetTitle( histtitle.str().c_str() );
  hist->SetYTitle( "Number of Tracks" );
  hist->Write();
  hist->Draw();
  c->SetLogy();
  name << ".png";
  c->Print( name.str().c_str() );
}

for( int i = 8; i < 41; i++ ){
  stringstream name;
  name << "InvbptPin" << i+28;
  int n1 = hInvBeta->GetXaxis()->FindBin( .05*(i-1) );
  int n2 = hInvBeta->GetXaxis()->FindBin( .05*(i) );
  TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
  stringstream histtitle;
  histtitle << "1/Beta for Momentum Range for Negative Charge " << .05*(i-1) << " to " << .05*(i) << " Pion Centered" ;
  hist->SetTitle( histtitle.str().c_str() );
  hist->SetYTitle( "Number of Tracks" );
  hist->Write();
  hist->Draw();
  c->SetLogy();
  name << ".png";
  c->Print( name.str().c_str() );
}

}
