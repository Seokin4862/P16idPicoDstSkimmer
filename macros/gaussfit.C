

void gaussfit() {

TFile *f = new TFile( "/" );

TCanvas *c = new TCanvas( "c", "c" );

TH2 *hdEdx = (TF2*)f->Get( "LnDedxvsMom1" );
TH2 *hInvBeta = (TF2*)f->Get( "LnInvBetavsMom1" );
}
