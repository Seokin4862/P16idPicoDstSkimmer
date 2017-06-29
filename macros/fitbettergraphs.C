
void fitbettergraphs(){

TFile * f = new TFile( "/home/sy34/workspace/safe/slices/slicesgraphs.root" );

TCanvas *c = new TCanvas( "c" , "c" );

TF1 *fit = new TF1( "fit" , "gaus" );

float binEdges[] = {0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18, 0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31, 0.32, 0.33, 0.34, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1.0, 1.05, 1.1, 1.15, 1.2, 1.25, 1.3, 1.35, 1.4, 1.45, 1.5, 1.55, 1.6, 1.65, 1.7, 1.75, 1.8, 1.85, 1.9, 1.95, 2.0};
int nBins = 67;

TH1D * hadedxpt = new TH1D( "adedxpt", "Integral of the Pion Fit Ln(dEdx) vs Total Momentum", nBins, binEdges );
TH1D * hadedxptm = new TH1D( "adedxptm", "Mean of the Pion Fit Ln(dEdx) vs Total Momentum", nBins, binEdges );
TH1D * hadedxpts = new TH1D( "adedxpts", "Sigma of the Pion Fit Ln(dEdx) vs Total Momentum", nBins, binEdges );
TH1D * hainvbpt = new TH1D( "ainvbpt", "Integral of the Pion Fit 1/Beta vs Total Momentum", nBins, binEdges );
TH1D * hainvbptm = new TH1D( "ainvbptm", "Mean of the Pion Fit 1/Beta vs Total Momentum", nBins, binEdges );
TH1D * hainvbpts = new TH1D( "ainvbpts", "Sigma of the Pion Fit 1/Beta vs Total Momentum", nBins, binEdges );

TH1D * hpdedxpt = new TH1D( "pdedxpt", "Integral of the Pion Fit Ln(dEdx), + Charge vs Total Momentum", nBins, binEdges );
TH1D * hpdedxptm = new TH1D( "pdedxptm", "Mean of the Pion Fit Ln(dEdx), + Charge vs Total Momentum", nBins, binEdges );
TH1D * hpdedxpts = new TH1D( "pdedxpts", "Sigma of the Pion Fit Ln(dEdx), + Charge vs Total Momentum", nBins, binEdges );
TH1D * hpinvbpt = new TH1D( "pinvbpt", "Integral of the Pion Fit 1/Beta, + Charge vs Total Momentum", nBins, binEdges );
TH1D * hpinvbptm = new TH1D( "pinvbptm", "Mean of the Pion Fit 1/Beta, + Charge vs Total Momentum", nBins, binEdges );
TH1D * hpinvbpts = new TH1D( "pinvbpts", "Sigma of the Pion Fit 1/Beta, + Charge vs Total Momentum", nBins, binEdges );

TH1D * hndedxpt = new TH1D( "ndedxpt", "Integral of the Pion Fit Ln(dEdx), - Charge vs Total Momentum", nBins, binEdges );
TH1D * hndedxptm = new TH1D( "ndedxptm", "Mean of the Pion Fit Ln(dEdx), - Charge vs Total Momentum", nBins, binEdges );
TH1D * hndedxpts = new TH1D( "ndedxpts", "Sigma of the Pion Fit Ln(dEdx), - Charge vs Total Momentum", nBins, binEdges );
TH1D * hninvbpt = new TH1D( "ninvbpt", "Integral of the Pion Fit 1/Beta, - Charge vs Total Momentum", nBins, binEdges );
TH1D * hninvbptm = new TH1D( "ninvbptm", "Mean of the Pion Fit 1/Beta, - Charge vs Total Momentum", nBins, binEdges );
TH1D * hninvbpts = new TH1D( "ninvbpts", "Sigma of the Pion Fit 1/Beta, - Charge vs Total Momentum", nBins, binEdges );


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
hadedxpt->SetBinContent( i, fit->Integral( 0, 10 )/.01 );
hadedxptm->SetBinContent( i, fit->GetParameter(1) );
hadedxpts->SetBinContent( i, fit->GetParameter(2) );
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
hadedxpt->SetBinContent( i+28, fit->Integral( 0, 10 )/.05 );
hadedxptm->SetBinContent( i+28, fit->GetParameter(1) );
hadedxpts->SetBinContent( i+28, fit->GetParameter(2) );
}

hadedxpt->Draw();
c->Print( "alndEdx1.png" );

hadedxptm->Draw();
c->Print( "alndEdx2.png" );

hadedxpts->Draw();
c->Print( "alndEdx3.png" );


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
hainvbpt->SetBinContent( i, fit->Integral( 1, 10 )/.01 );
hainvbptm->SetBinContent( i, fit->GetParameter(1) );
hainvbpts->SetBinContent( i, fit->GetParameter(2) );
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
hainvbpt->SetBinContent( i+28, fit->Integral( 1, 10 )/.05 );
hainvbptm->SetBinContent( i+28, fit->GetParameter(1) );
hainvbpts->SetBinContent( i+28, fit->GetParameter(2) );
}

hainvbpt->Draw();
c->Print( "aInvBeta1.png" );

hainvbptm->Draw();
c->Print( "aInvBeta2.png" );

hainvbpts->Draw();
c->Print( "aInvBeta3.png" );

}
