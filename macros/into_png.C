

void into_png() {

TFile * f = new TFile( "/home/sy34/workspace/safe/dEdxvsphi/Pion1Data/nSigmaPion1.root" );

for( int i = 1 ; i = 8 ; i++  ) {
stringname refer;
refer << histo_name << i
cout<< "name of histogram: " << refer.str() << endl;
}

}
