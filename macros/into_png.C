

void into_png() {

TFile * f = new TFile( "/home/sy34/workspace/safe/dEdxvsphi/Pion1Data/nSigmaPion1.root" );

TCanvas * c = new TCanvas("c","c");

for( int i = 1 ; i < 20 ; i++  ) {
  // i < number - 1
if(i % 10 == 0) continue;
stringstream refer;
refer << "dEdxphi" << i;

TH2 *h = (TH2*)f->Get( refer.str().c_str());
if( 0 == h ) continue;

h->Draw("colz");
stringstream name;
name << refer.str() << ".png";
c->Print( name.str().c_str() );

stringstream title_px;
TProfile * hpx = h->ProfileX();
title_px << hpx->GetTitle() << " ProfileX";
hpx->SetTitle( title_px.str().c_str() );
hpx->SetXTitle( "#phi" );
hpx->SetYTitle( "dEdx" );
hpx->SetAxisRange( 2. , 3. , "Y");
hpx->Draw();
stringstream name_px;
name_px << refer.str() << "_px" << ".png";
c->Print( name_px.str().c_str() );

h->FitSlicesY();

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

h_1->Draw();
name_fs1<< ".png";
c->Print( name_fs1.str().c_str());
h_2->Draw();
name_fs2<< ".png";
c->Print( name_fs2.str().c_str());


}

}
