

void overlap() {

TFile * f = new TFile( "/home/sy34/workspace/safe/65dEdxvsRunN/dEdxvsRunN.root" );

TCanvas * c = new TCanvas("c","c");

for( int i = 1 ; i < 10 ; i++  ) {
  // i < number - 1
stringstream refer;
refer << "hdEdxvsRunN0" << i;
stringstream refer2;
refer2 << "hdEdxvsRunN1" << i;

TH2 *h = (TH2*)f->Get( refer.str().c_str());
if( 0 == h ) continue;

TH2 *h2 = (TH2*)f->Get( refer2.str().c_str());
if( 0 == h2 ) continue;

// h->Draw("colz");
// h->SetAxisRange(1.5, 5, "Y");
// h->SetAxisRange(1350, 1900, "X");
// stringstream name;
// name << refer.str() << ".png";
// c->Print( name.str().c_str() );

// stringstream title_px;
// TProfile * hpx = h->ProfileX();
// title_px << hpx->GetTitle() << " ProfileX";
// hpx->SetTitle( title_px.str().c_str() );
// hpx->SetXTitle( "run number" );
// hpx->SetAxisRange( 2.6 , 3.0 , "Y");
// hpx->SetAxisRange(1350, 1900, "X");
// hpx->Draw();
// stringstream name_px;
// name_px << refer.str() << "_px" << ".png";
// c->Print( name_px.str().c_str() );

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

h2->FitSlicesY( 0, 0, -1, 30);

stringstream name2_fs0;
name2_fs0<< refer2.str();
name2_fs0<< "_0";
TH1 * h2_0 = (TH1*)gDirectory->Get( name2_fs0.str().c_str() );
stringstream name2_fs1;
name2_fs1<< refer2.str();
name2_fs1<< "_1";
TH1 * h2_1 = (TH1*)gDirectory->Get( name2_fs1.str().c_str() );
stringstream name2_fs2;
name2_fs2<< refer2.str();
name2_fs2<< "_2";
TH1 * h2_2 = (TH1*)gDirectory->Get( name2_fs2.str().c_str() );


stringstream title_1;
title_1 << h->GetTitle() << " Fitted Mean with same from Mom -.55 to -.6";
h_1->SetTitle( title_1.str().c_str() );
h_1->SetAxisRange( 2.6, 2.9, "Y" );
h_1->SetAxisRange( 1350, 1900, "X" );
h2_1->SetTitle( title_1.str().c_str() );
h2_1->SetAxisRange( 2.6, 2.9, "Y" );
h2_1->SetAxisRange( 1350, 1900, "X" );
h2_1->SetLineColor( 2 );
h_1->Draw(  );
h2_1->Draw( "same" );
stringstream overlap;
overlap << "mean_overlap" << i << ".png";
c->Print( overlap.str().c_str() );

stringstream title_2;
title_2 << h->GetTitle() << " Fitted Sigma with same from Mom -.55 to -.6";
h_2->SetTitle( title_2.str().c_str() );
h_2->SetAxisRange( .1, .3, "Y" );
h_2->SetAxisRange( 1350, 1900, "X" );
h2_2->SetTitle( title_2.str().c_str() );
h2_2->SetAxisRange( .1, .3, "Y" );
h2_2->SetAxisRange( 1350, 1900, "X" );
h2_2->SetLineColor( 2 );
h_2->Draw(  );
h2_2->Draw( "same" );
stringstream overlap;
overlap << "sigma_overlap" << i << ".png";
c->Print( overlap.str().c_str() );

// stringstream title_1;
// title_1 << h->GetTitle() << " Fitted Mean";
// h_1->SetTitle( title_1.str().c_str() );
// h_1->SetAxisRange( 2.6, 2.9, "Y" );
// h_1->SetAxisRange(1350, 1900, "X");
// h_1->Draw();
// name_fs1<< ".png";
// c->Print( name_fs1.str().c_str());

// stringstream title_2;
// title_2 << h->GetTitle() << " Fitted Sigma";
// h_2->SetTitle( title_2.str().c_str() );
// h_2->SetAxisRange( .1, .3, "Y" );
// h_2->SetAxisRange(1350, 1900, "X");
// h_2->Draw();
// name_fs2<< ".png";
// c->Print( name_fs2.str().c_str());

}

}
