


void png_maker( ) {

  TFile * f = new TFile( "/home/sy34/workspace/safe/dEdxvsphi/Pion1Data/nSigmaPion1.root" );

  string name = "dEdxphi";
  for ( int i = 0; i < 10; i++ ){
      stringstream sstr;
      sstr << name << i;
      cout << "name of histo: " << sstr.str() << endl;

      TH1 * h = (TH1*)f->Get( sstr.str().c_str() );

      cout << "i am a histogram : " << h->GetName() <<endl;


  }





}
