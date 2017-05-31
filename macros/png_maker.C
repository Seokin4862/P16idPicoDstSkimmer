


void png_maker( ) {

  TFile * f = new TFile( "/home/sy34/workspace/safe/dEdxvsphi/Pion1Data/nSigmaPion1.root" );

  string name = "dEdxphi";
  for ( int i = 1; i < 10; i++ ){
      stringstream sstr;
      sstr << name << i;
      cout << "name of histo: " << sstr.str() << endl;

      TH1 * h = (TH1*)f->Get( sstr.str().c_str() );
      if ( 0 == h ) continue;
      cout << "i am a histogram : " << h->GetName() <<endl;
      h->Draw();

      // this ould empty out the sstr
      // sstr.str( "" );
      string cn = h->Class_Name();
      if ( "TH2D" == cn ){
        cout << "I am 2D" << endl;
      }
      sstr << ".png";
      c->Print( sstr.str().c_str() );

  }





}
