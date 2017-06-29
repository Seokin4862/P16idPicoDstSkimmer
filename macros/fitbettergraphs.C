
void fitbettergraphs(){

TFile * f = new TFile( "/home/sy34/workspace/safe/slices/slicesgraphs.root" );

TCanvas *c = new TCanvas( "c" , "c" );

TF1 *fit = new TF1( "fit" , "gaus" );

float binEdges[] = {0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18, 0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31, 0.32, 0.33, 0.34, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1.0, 1.05, 1.1, 1.15, 1.2, 1.25, 1.3, 1.35, 1.4, 1.45, 1.5, 1.55, 1.6, 1.65, 1.7, 1.75, 1.8, 1.85, 1.9, 1.95, 2.0};
int nBins = 67;

TH1D * hintpt = new TH1D( "intpt", "Integral of the Pion Fit Ln(dEdx) vs Total Momentum", nBins, binEdges );
TH1D * hinvbpt = new TH1D( "invbpt", "Integral of the Pion Fit 1/Beta vs Total Momentum", nBins, binEdges );



double beg = 1.5;
double end = 2;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
getslice << "alndEdxK" << i;
TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
temph->Draw();
c->SetLogy();
temph->Fit( fit, "R" , "" , beg, end );
beg = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
temph->Draw();
getslice<< ".png";
// c->Print( getslice.str().c_str() );
hintpt->SetBinContent( i, fit->Integral( .1, 10 )/.01 );
}

double beg = .7;
double end = 1.3;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
getslice << "alndEdxL" << i;
TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
temph->Draw();
c->SetLogy();
temph->Fit( fit, "R" , "" , beg, end );
beg = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
temph->Draw();
getslice<< ".png";
// c->Print( getslice.str().c_str() );
hintpt->SetBinContent( i+28, fit->Integral( .1, 10 )/.05 );
}

hintpt->Draw();
c->Print( "alndEdx.png" );

double beg = 1.3;
double end = 1.45;

for( int i = 16; i < 36; i++ ){
stringstream getslice;
getslice << "aInvBetaK" << i;
TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
temph->Draw();
c->SetLogy();
temph->Fit( fit, "R" , "" , beg, end );
beg = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
temph->Draw();
getslice<< ".png";
// c->Print( getslice.str().c_str() );
hinvbpt->SetBinContent( i, fit->Integral( .1, 10 )/.01 );
}

double beg = 1.04;
double end = 1.13;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
getslice << "aInvBetaL" << i;
TH1 *temph = (TH1*)f->Get( getslice.str().c_str() );
temph->Draw();
c->SetLogy();
temph->Fit( fit, "R" , "" , beg, end );
beg = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
temph->Draw();
getslice<< ".png";
// c->Print( getslice.str().c_str() );
hinvbpt->SetBinContent( i+28, fit->Integral( .1, 10 )/.05 );
}

hinvbpt->Draw();
c->Print( "aInvBeta.png" );


}
