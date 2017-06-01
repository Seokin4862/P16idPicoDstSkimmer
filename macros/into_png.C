

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
stringstream name;
name << refer.str() << ".png";
c->Print( name.str().c_str() );

TProfile * hpx = h->ProfileX();
hpx->Draw();
stringstream name_px;
name_px << refer.str() << "_px" << ".png";
c->Print( name_px.str().c_str() );

h->FitSlicesY();
TH1 * h_0 = (TH1*)gDirectory->Get( (refer + "_0").c_str() );
TH1 * h_1 = (TH1*)gDirectory->Get( (refer + "_1").c_str() );
TH1 * h_2 = (TH1*)gDirectory->Get( (refer + "_2").c_str() );

h_1->Draw();
c->Print( (refer+"_1"+".png").c_str());
h_2->Draw();
c->Print( (refer+"_2"+".png").c_str());


}

}
