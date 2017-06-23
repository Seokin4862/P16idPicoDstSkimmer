

void yami() {

  TFile *f = new TFile("/");

  TCanvas *c = new TCanvas("c","c");

  TH2 *h = (TH2*)f->Get( "" );

  TProfile *hpx = h->ProfileX();

  title_px << hpx->GetTitle() << " ProfileX";
  hpx->SetTitle( title_px.str().c_str() );
  hpx->SetXTitle( "run number" );
  hpx->SetAxisRange( 2.6 , 3.0 , "Y");
  hpx->SetAxisRange(1350, 1900, "X");
  hpx->Draw();
  c->Print( "" );

  h->FitSlicesY( 0, 0, -1, 30);

  stringstream name_fs0;
  name_fs0<< refer.str();
  name_fs0<< "_0";
  TH1 * h_0 = (TH1*)gDirectory->Get( name_fs0.str().c_str() );
  stringstream name_fs1;
  name_fs1<< refer.str();
  name_fs1<< "_1";
  TH1 * h_1 = (TH1*)gDirectory->Get( name_fs1.str().c_str() );
  stringstream name_fs2;
  name_fs2<< refer.str();
  name_fs2<< "_2";
  TH1 * h_2 = (TH1*)gDirectory->Get( name_fs2.str().c_str() );
}
