void testslices(){

  TFile *f = new TFile( "/home/sy34/workspace/safe/cented/centedInvBeta.root" );

  TCanvas *c = new TCanvas( "c","c" );

  TF1 *fit = new TF1( "fit", "gaus" );

  TFile *rootfile = new TFile( "testslices.root", "RECREATE" );

  TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomPion_a" );

  for( int i = 16; i < 200; i++ ){
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
  }

  TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomPion_p" );

  for( int i = 16; i < 200; i++ ){
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
  }


  TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomPion_n" );

  for( int i = 16; i < 200; i++ ){
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
  }


  TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomKaon_a" );

  for( int i = 16; i < 200; i++ ){
    stringstream name;
    name << "InvbptKia" << i;
    int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
    int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
    TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
    stringstream histtitle;
    histtitle << "1/Beta for Momentum Range for All Charge " << .01*(i-1) << " to " << .01*(i) << " Kaon Centered" ;
    hist->SetTitle( histtitle.str().c_str() );
    hist->SetYTitle( "Number of Tracks" );
    hist->Write();
  }

  TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomKaon_p" );

  for( int i = 16; i < 200; i++ ){
    stringstream name;
    name << "InvbptKip" << i;
    int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
    int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
    TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
    stringstream histtitle;
    histtitle << "1/Beta for Momentum Range for Postive Charge " << .01*(i-1) << " to " << .01*(i) << " Kaon Centered" ;
    hist->SetTitle( histtitle.str().c_str() );
    hist->SetYTitle( "Number of Tracks" );
    hist->Write();
  }

  TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomKaon_n" );

  for( int i = 16; i < 200; i++ ){
    stringstream name;
    name << "InvbptKin" << i;
    int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
    int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
    TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
    stringstream histtitle;
    histtitle << "1/Beta for Momentum Range for Negative Charge " << .01*(i-1) << " to " << .01*(i) << " Kaon Centered" ;
    hist->SetTitle( histtitle.str().c_str() );
    hist->SetYTitle( "Number of Tracks" );
    hist->Write();
  }


  TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomProton_a" );

  for( int i = 16; i < 36; i++ ){
    stringstream name;
    name << "InvbptPria" << i;
    int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
    int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
    TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
    stringstream histtitle;
    histtitle << "1/Beta for Momentum Range for All Charge " << .01*(i-1) << " to " << .01*(i) << " Proton Centered" ;
    hist->SetTitle( histtitle.str().c_str() );
    hist->SetYTitle( "Number of Tracks" );
    hist->Write();
  }

  TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomProton_p" );

  for( int i = 16; i < 36; i++ ){
    stringstream name;
    name << "InvbptPrip" << i;
    int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
    int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
    TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
    stringstream histtitle;
    histtitle << "1/Beta for Momentum Range for Positive Charge " << .01*(i-1) << " to " << .01*(i) << " Proton Centered" ;
    hist->SetTitle( histtitle.str().c_str() );
    hist->SetYTitle( "Number of Tracks" );
    hist->Write();
  }

  TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMomProton_n" );

  for( int i = 16; i < 36; i++ ){
    stringstream name;
    name << "InvbptPrin" << i;
    int n1 = hInvBeta->GetXaxis()->FindBin( .01*(i-1) );
    int n2 = hInvBeta->GetXaxis()->FindBin( .01*(i) );
    TH1 *hist = hInvBeta->ProjectionY( name.str().c_str() , n1 , n2 );
    stringstream histtitle;
    histtitle << "1/Beta for Momentum Range for Negative Charge " << .01*(i-1) << " to " << .01*(i) << " Proton Centered" ;
    hist->SetTitle( histtitle.str().c_str() );
    hist->SetYTitle( "Number of Tracks" );
    hist->Write();
  }
}
