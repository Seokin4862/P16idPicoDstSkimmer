

void slices() {

TFile * f = new TFile( "/home/sy34/workspace/safe/8InvBetadEdxMom/dEdxandInvBetavsMom.root" );

TCanvas * c = new TCanvas("c","c");

TH2 *hdEdx = (TH2*)f->Get( "DedxvsMom" );
TH2 *hInvBeta = (TH2*)f->Get( "InvBetavsMom" );

hdEdx->Draw("colz");
c->SetLogz();
c->Print( "dEdxvsMom.png" );

hInvBeta->Draw("colz");
c->SetLogz();
c->Print( "InvBetavsMom.png" );

for( int i = 1; i < 41 ; i++ ) {

  stringstream mona;
  mona << "mona" << i;
  int m1 = hdEdx->GetXaxis()->FindBin( .05*(i-1) );
  int m2 = hdEdx->GetXaxis()->FindBin( .05*(i) );
  TH1 *kid = hdEdx->ProjectionY( mona.str().c_str() , m1 , m2 );
  kid->Draw();
  c->SetLogy();
  mona << ".png";
  c->Print( mona.str().c_str() );

  stringstream lisa;
  lisa << "lisa" << i;
  int l1 = hInvBeta->GetXaxis()->FindBin( .05*(i-1) );
  int l2 = hInvBeta->GetXaxis()->FindBin( .05(i) );
  TH1 *child = hInvBeta->ProjectionY( lisa.str().c_str(), l1, l2 );
  child->Draw();
  c->SetLogy();
  lisa << ".png";
  c->Print( lisa.str().c_str() );
}

}

// for( int i = 1 ; i < 10 ; i++  ) {
//   // i < number - 1
// stringstream refer;
// refer << "hdEdxvsRunN1" << i;
//
// TH2 *h = (TH2*)f->Get( refer.str().c_str());
// if( 0 == h ) continue;
//
// h->Draw("colz");
// h->SetAxisRange(1.5, 5, "Y");
// h->SetAxisRange(1350, 1900, "X");
// stringstream name;
// name << refer.str() << ".png";
// c->Print( name.str().c_str() );
//
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
//
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
//
// stringstream title_1;
// title_1 << h->GetTitle() << " Fitted Mean";
// h_1->SetTitle( title_1.str().c_str() );
// h_1->SetAxisRange( 2.6, 2.9, "Y" );
// h_1->SetAxisRange(1350, 1900, "X");
// h_1->Draw();
// name_fs1<< ".png";
// c->Print( name_fs1.str().c_str());
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
//
// }
//
// }
