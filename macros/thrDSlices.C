void thrDSlices(){

  TFile *f = new TFile( "/home/sy34/workspace/safe/3Dgraphs/3Dgraphs.root" );
  // TFile *f = new TFile( "/home/sy34/workspace/safe/3Dgraphs/3Dgraphs.root" );

  TFile * rootfile = new TFile( "sliceof3Dgraphs.root", "RECREATE" );

  TCanvas * c = new TCanvas( "c","c" );

  for( int i = 1; i  < 201; i++ ){
    TH3 *hInvBetaDedxMom = (TH3*)f->Get( "InvBetaDedxMom" );
    stringstream slicename;
    slicename << "hInvBetaDedx" << i;
    int a1 = hInvBetaDedxMom->GetZaxis()->FindBin( .01*(i-1) );
    int a2 = hInvBetaDedxMom->GetZaxis()->FindBin( .01*(i) );
    hInvBetaDedxMom->GetZaxis()->SetRange( a1, a2 );
    TH2 *slice = (TH2*)hInvBetaDedxMom->Project3D( "xy" );
    stringstream slicetitle;
    slicetitle << "1/Beta vs dE/dx for Total Momentum from " << .01*(i-1) << " to " << .01*(i) << " (GeV)";
    slice->SetTitle( slicetitle.str().c_str() );
    slice->SetXTitle( "dE/dx" );
    slice->SetYTitle( "1/Beta" );
    slice->SetName( slicename.str().c_str() );
    slice->Write();
    slice->Draw();
    slicename << ".png";
    // c->Print( slicename.str().c_str() );
  }

  for( int i = 1; i < 201; i++ ){
    TH3 *hInvBetaDedxMomPion = (TH3*)f->Get( "InvBetaDedxMomPion" );
    stringstream slicename;
    slicename << "hInvBetaDedxPion" << i;
    int a1 = hInvBetaDedxMomPion->GetZaxis()->FindBin( .01*(i-1) );
    int a2 = hInvBetaDedxMomPion->GetZaxis()->FindBin( .01*(i) );
    hInvBetaDedxMomPion->GetZaxis()->SetRange( a1, a2 );
    TH2 *slice = (TH2*)hInvBetaDedxMomPion->Project3D( "xy" );
    stringstream slicetitle;
    slicetitle << "1/Beta vs dE/dx for Total Momentum from " << .01*(i-1) << " to " << .01*(i) << " (GeV, Pion Centered for 1/Beta)";
    slice->SetTitle( slicetitle.str().c_str() );
    slice->SetXTitle( "dE/dx" );
    slice->SetYTitle( "1/Beta" );
    slice->SetName( slicename.str().c_str() );
    slice->Write();
    slice->Draw();
    slicename << ".png";
    // c->Print( slicename.str().c_str() );
  }

  for( int i = 1; i < 201; i++ ){
    TH3 *hInvBetaDedxMomKaon = (TH3*)f->Get( "InvBetaDedxMomKaon" );
    stringstream slicename;
    slicename << "hInvBetaDedxKaon" << i;
    int a1 = hInvBetaDedxMomKaon->GetZaxis()->FindBin( .01*(i-1) );
    int a2 = hInvBetaDedxMomKaon->GetZaxis()->FindBin( .01*(i) );
    hInvBetaDedxMomKaon->GetZaxis()->SetRange( a1, a2 );
    TH2 *slice = (TH2*)hInvBetaDedxMomKaon->Project3D( "xy" );
    stringstream slicetitle;
    slicetitle << "1/Beta vs dE/dx for Total Momentum from " << .01*(i-1) << " to " << .01*(i) << " (GeV, Kaon Centered for 1/Beta)" ;
    slice->SetTitle( slicetitle.str().c_str() );
    slice->SetXTitle( "dE/dx" );
    slice->SetYTitle( "1/Beta" );
    slice->SetName( slicename.str().c_str() );
    slice->Write();
    slice->Draw();
    slicename << ".png";
    // c->Print( slicename.str().c_str() );
  }

  for( int i = 1; i < 201; i++ ){
    TH3 *hInvBetaDedxMomProton = (TH3*)f->Get( "InvBetaDedxMomProton" );
    stringstream slicename;
    slicename << "hInvBetaDedxProton" << i;
    int a1 = hInvBetaDedxMomProton->GetZaxis()->FindBin( .01*(i-1) );
    int a2 = hInvBetaDedxMomProton->GetZaxis()->FindBin( .01*(i) );
    hInvBetaDedxMomProton->GetZaxis()->SetRange( a1, a2 );
    TH2 *slice = (TH2*)hInvBetaDedxMomProton->Project3D( "xy" );
    stringstream slicetitle;
    slicetitle << "1/Beta vs dE/dx for Total Momentum from " << .01*(i-1) << " to " << .01*(i) << " (GeV, Proton Centered for 1/Beta)";
    slice->SetTitle( slicetitle.str().c_str() );
    slice->SetXTitle( "dE/dx" );
    slice->SetYTitle( "1/Beta" );
    slice->SetName( slicename.str().c_str() );
    slice->Write();
    slice->Draw();
    slicename << ".png";
    // c->Print( slicename.str().c_str() );
  }

}
