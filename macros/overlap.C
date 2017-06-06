

void overlap() {

TFile * f = new TFile( "/home/sy34/workspace/safe/65dEdxvsRunN/dEdxvsRunN.root" );

TCanvas * c = new TCanvas("c","c");

for( int i = 1 ; i < 10 ; i++  ) {
  // i < number - 1
stringstream refer;
refer << "hdEdxvsRunN0" << i;

TH2 *h1 = (TH2*)f->Get( refer.str().c_str() );
TH2 *h2 = (TH2*)f->Get( refer.str().c_str() );
if( 0 == h1 ) continue;
if( 0 == h2 ) continue;

h1->FitSlicesY( 0, 0, -1, 30 );

stringstream name_fs10;
name_fs10<< refer.str();
name_fs10<< "_0";
TH1 * h_10 = (TH1*)gDirectory->Get( name_fs10.str().c_str() );
stringstream name_fs11;
name_fs11<< refer.str();
name_fs11<< "_1";
TH1 * h_11 = (TH1*)gDirectory->Get( name_fs11.str().c_str() );
stringstream name_fs12;
name_fs12<< refer.str();
name_fs12<< "_2";
TH1 * h_12 = (TH1*)gDirectory->Get( name_fs12.str().c_str() );

h2->FitSlicesY( 0, 0, -1, 30 );

stringstream name_fs20;
name_fs20<< refer.str();
name_fs20<< "_0";
TH1 * h_20 = (TH1*)gDirectory->Get( name_fs20.str().c_str() );
stringstream name_fs21;
name_fs21<< refer.str();
name_fs21<< "_1";
TH1 * h_21 = (TH1*)gDirectory->Get( name_fs21.str().c_str() );
stringstream name_fs22;
name_fs22<< refer.str();
name_fs22<< "_2";
TH1 * h_22 = (TH1*)gDirectory->Get( name_fs22.str().c_str() );




stringstream title_1;
title_1 << h->GetTitle() << " Fitted Mean";
h_11->SetTitle( title_1.str().c_str() );
h_11->SetAxisRange( 2.6, 2.9, "Y" );
h_11->SetAxisRange(1350, 1900, "X");
h_11->Draw();
h_12->Draw( "same" );

name_fs1<< ".png";
c->Print( name_fs1.str().c_str());


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

// h->FitSlicesY( 0, 0, -1, 30);
//
//
//
// stringstream title_2;
// title_2 << h->GetTitle() << " Fitted Sigma";
// h_2->SetTitle( title_2.str().c_str() );
// h_2->SetAxisRange( .1, .3, "Y" );
// h_2->SetAxisRange(1350, 1900, "X");
// h_2->Draw();
// name_fs2<< ".png";
// c->Print( name_fs2.str().c_str());
//

}

}
