

void fitmomgraph() {

TFile * f = new TFile( "/home/sy34/workspace/safe/slices/slicesgraphs.root" );

TCanvas *c = new TCanvas( "c", "c" );

TF1 * fit = new TF1( "fit", "gaus" );

double bag = 1.5;
double end = 2;
const Int_t NBins1 = 34;
Double_t edges1[35] = {};
Double_t inted1[35] = {};

for( int i = 11; i < 36; i++ ){
stringstream getslice;
getslice << "alndEdxK" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
inted1[i-1] = fit->Integral( 0, 10 );
edges1[i-1] = .01*(i-1) ;
}

edges1[35] = .35;
TH1D * intedmom = new TH1D( "intedmom" , "Integral of the Fit against Momentum Range" , NBins1 , edges1 );

for( int i = 11; i < 36; i++ ){
intedmom->SetBinContent( i-1, inted1[i-1] );
}


// double bag = .7;
// double end = 1.3;
// const Int_t NBins2 = 49;
// Double_t edges2[40] = {};
// Double_t inted2[40] = {};
//
//
// for( int i = 8; i < 41; i++ ){
// stringstream getslice;
// getslice << "alndEdxL" << i;
// TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
// turandot->Draw();
// c->SetLogy();
// turandot->Fit( fit, "R" , "" , bag, end );
// bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
// end = fit->GetParameter(1) + 2*fit->GetParameter(2);
// inted2[i-1] = fit->Integral( 0, 10);
// edges2[i-1] = .05*(i-1) ;
// }
//
// edges2[40] = ;
//
// Double_t aedges[76] = {};

intedmom->Draw();

}
