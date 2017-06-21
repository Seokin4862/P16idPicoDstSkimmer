

void gaussfit() {

TFile * f = new TFile( "/home/sy34/workspace/safe/slices/slicesgraphs.root" );

TCanvas *c = new TCanvas( "c", "c" );

TF1 * fit = new TF1( "fit", "gaus" );

for( int i = 11; i < 36; i++ ){
stringstream getslice;
getslice << aLndEdxK << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Fit( fit );
}

}
