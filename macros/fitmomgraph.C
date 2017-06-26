

void fitmomgraph() {

TFile * f = new TFile( "/home/sy34/workspace/safe/slices/slicesgraphs.root" );

TCanvas *c = new TCanvas( "c", "c" );

TF1 * fit = new TF1( "fit", "gaus" );

double bag = 1.5;
double end = 2;
int edges[35] = {};

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
double inted = fit->Integrate( 0, 10 );
edges[i-1] = hdEdx->GetXaxis()->FindBin( .01*(i-1) );
}
edges[35] = .35
TH1* intedmom = new TH1D( "intedmom" , "Integral of the Fit against Momentum Range" , 35 , edges );
intedmom->Draw();

}
