void thrDSlices(){

  TFile *f = new TFile( "/home/sy34/workspace/safe/3Dgraphs/3Dgraphs.root" );
  // TFile *f = new TFile( "/home/sy34/workspace/safe/3Dgraphs/3Dgraphs.root" );

  TFile * rootfile = new TFile( "sliceof3Dgraphs.root", "RECREATE" );

  TCanvas * c = new TCanvas( "c","c" );

  TH3 *hInvBetaDedxMom = (TH3*)f->Get( "InvBetaDedxMom" );
  TH3 *hInvBetaDedxMomPion = (TH3*)f->Get( "InvBetaDedxMomPion" );
  TH3 *hInvBetaDedxMomKaon = (TH3*)f->Get( "InvBetaDedxMomKaon" );
  TH3 *hInvBetaDedxMomProton = (TH3*)f->Get( "InvBetaDedxMomProton" );

  for( int i = 1; i  < 201; i++ ){
    stringstream slicename;
    slicename << "hInvBetaDedx" << i;
    int a1 = hInvBetaDedxMom->GetZaxis()->FindBin( .01*(i-1) );
    int a2 = hInvBetaDedxMom->GetZaxis()->FindBin( .01*(i-1) );
    TH2 *slice = hInvBetaDedxMom->ProjectionXY( slicename.str().c_str(), a1, a2 );
    stringstream slicetitle;
    slicetitle << "" << .01*(i-1) << " to " << .01*(i);
    slice->SetTitle( slicetitle.str().c_str() );
    slice->SetXTitle( "dE/dx" );
    slice->SetYTitle( "1/Beta" );
    slice->GetXaxis()->SetRange( 0,10 );
    slice->GetYaxis()->SetRange( -1.5,1.5 );
    slice->Write();
    slice->Draw();
    slicename << ".png";
    c->Print( slicename.str().c_str() );
  }

}
