

void yami() {

  TFile *f = new TFile("/home/sy34/workspace/safe/corrdEdx/corrdEdx.root");

  TCanvas *c = new TCanvas("c","c");

  for( int i = 1 ; i < 10 ; i++  ){

  stringstream refer;
  refer << "DedxvsPhi" << i;

  TH2 *h = (TH2*)f->Get( refer.str().c_str());
  TProfile *hpx = h->ProfileX();

  stringstream title_px;
  title_px << hpx->GetTitle() << " ProfileX";
  hpx->SetTitle( title_px.str().c_str() );
  hpx->SetYTitle( "dEdx" );
  hpx->SetAxisRange( 2.6 , 3.0 , "Y");
  hpx->Draw();
  stringstream name;
  name << refer.str() << ".png";
  c->Print( name.str().c_str() );
}

for( int i = 1 ; i < 10 ; i++  ){

stringstream refer;
refer << "corrDedxvsPhi" << i;

TH2 *h = (TH2*)f->Get( refer.str().c_str());
TProfile *hpx = h->ProfileX();

stringstream title_px;
title_px << hpx->GetTitle() << " ProfileX";
hpx->SetTitle( title_px.str().c_str() );
hpx->SetYTitle( "dEdx" );
hpx->SetAxisRange( 2.6 , 3.0 , "Y");
hpx->Draw();
stringstream name;
name << refer.str() << ".png";
c->Print( name.str().c_str() );
}

  // h->FitSlicesY( 0, 0, -1, 30);
  //
  // stringstream name_fs0;
  // name_fs0<< refer.str();
  // name_fs0<< "_0";
  // TH1 * h_0 = (TH1*)gDirectory->Get( name_fs0.str().c_str() );
  // stringstream name_fs1;
  // name_fs1<< refer.str();
  // name_fs1<< "_1";
  // TH1 * h_1 = (TH1*)gDirectory->Get( name_fs1.str().c_str() );
  // stringstream name_fs2;
  // name_fs2<< refer.str();
  // name_fs2<< "_2";
  // TH1 * h_2 = (TH1*)gDirectory->Get( name_fs2.str().c_str() );
}
