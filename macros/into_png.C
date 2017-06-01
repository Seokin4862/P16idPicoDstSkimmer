

void into_png() {

TFile * f = new TFile( "/home/sy34/workspace/safe/dEdxvsphi/Pion1Data/nSigmaPion1.root" );

TCanvas * c = new TCanvas("c","c");

for( int i = 1 ; i < 20 ; i++  ) {
  // i < number - 1
if(i % 10 == 0) continue;
stringstream refer;
refer << "dEdxphi" << i;

TH2 *h = (TH2*)f->Get( refer.str().c_str());
if( 0 == h ) continue;
h->Draw("colz");
name = refer;
c->print( (name + ".png").str() );

}

}
