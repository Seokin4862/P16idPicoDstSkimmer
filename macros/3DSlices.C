void 3DSlices(){

  TFile *f = new TFile( "/home/sy34/workspace/safe/3Dgraphs/3Dgraphs.root" );

  TFile * rootfile = new TFile( "sliceof3Dgraphs.root", "RECREATE" );

  TCanvas * c = new TCanvas( "c","c" );

  TH3 *hInvBetaDedxMom = (TH2*)f->Get( "hInvBetaDedxMom" );
  TH3 *hInvBetaDedxMomPion = (TH2*)f->Get( "hInvBetaDedxMomPion" );
  TH3 *hInvBetaDedxMomKaon = (TH2*)f->Get( "hInvBetaDedxMomKaon" );
  TH3 *hInvBetaDedxMomProton = (TH2*)f->Get( "hInvBetaDedxMomProton" );

  for(  )

}
