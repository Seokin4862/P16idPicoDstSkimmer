void thrDfit(){

  TFile *f = new TFile( "/home/sy34/workspace/safe/sliceof3Dgraphs/sliceof3Dgraphs.root" );

  TH2 *h = (TH2*)f->Get( "hInvBetaDedx50" );

  TCanvas *c = new TCanvas( "c","c" );

  TH2 *hdEdx = (TH2*)f->ProjectionY( "" );
  TH2 *hInvBeta = (TH2*)f->ProjectionX( "" );



}
