

void fitmomgraph() {

TFile * f = new TFile( "/home/sy34/workspace/safe/slices/slicesgraphs.root" );

TCanvas *c = new TCanvas( "c", "c" );

TF1 * fit = new TF1( "fit", "gaus" );

double bag = 1.5;
double end = 2;
const Int_t NBINS = 34;
Double_t edges[35] = {};

for( int i = 11; i < 36; i++ ){
stringstream getslice;
getslice << "alndEdxK" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
double inted[i-1] = fit->Integral( 0, 10 );
edges[i-1] = .01*(i-1) ;
}
edges[35] = .35;
TH1D * intedmom = new TH1D( "intedmom" , "Integral of the Fit against Momentum Range" , NBINS , edges );
for( int i = 11; i < 36; i++ ){
intedmom->SetBinContent( i-1, inted[i-1] );
}
intedmom->Draw();

}
