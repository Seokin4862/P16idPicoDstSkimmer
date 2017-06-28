

void fitmomgraph() {

TFile * f = new TFile( "/home/sy34/workspace/safe/slices/slicesgraphs.root" );

TCanvas *c = new TCanvas( "c", "c" );

TF1 * fit = new TF1( "fit", "gaus" );

float binEdges[] = {0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18, 0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31, 0.32, 0.33, 0.34, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1.0, 1.05, 1.1, 1.15, 1.2, 1.25, 1.3, 1.35, 1.4, 1.45, 1.5, 1.55, 1.6, 1.65, 1.7, 1.75, 1.8, 1.85, 1.9, 1.95, 2.0};
int nBins = 67;

TH1D * hYield = new TH1D( "yield", "", nBins, binEdges );

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
hYield->SetBinContent( i, fit->Integral( 0, 10 ) );

// inted1[i-1] = fit->Integral( 0, 10 );
// edges1[i-1] = .01*(i-1) ;
}

edges1[35] = .35;
TH1D * intedmom1 = new TH1D( "intedmom1" , "Integral of the Fit against Momentum Range" , NBins1 , edges1 );

for( int i = 11; i < 36; i++ ){
intedmom1->SetBinContent( i-1, inted1[i-1] );
}

intedmom1->Draw();

double bag = .7;
double end = 1.3;
const Int_t NBins2 = 39;
Double_t edges2[40] = {};
Double_t inted2[40] = {};


for( int i = 8; i < 41; i++ ){
stringstream getslice;
getslice << "alndEdxL" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
inted2[i-1] = fit->Integral( 0, 10);
edges2[i-1] = .05*(i-1) ;
}

edges2[40] = 2.0;

TH1D * intedmom2 = new TH1D( "intedmom2" , "Integral of the Fit against Momentum Range" , NBins2 , edges2 );

for( int i = 8; i < 41; i++ ){
intedmom2->SetBinContent( i-1, inted2[i-1] );
}

intedmom2->Draw();

}
