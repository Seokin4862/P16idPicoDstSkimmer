


void process_histo( TH2 * h, string name ){

  h->Draw("colz");
  c->Print( (name + ".png").c_str() );

  // plot profile
  TProfileX *hpx = h->ProfileX(....)
  hpx->Draw();
  name_px = name + "_profile";
  c->Print( (name_px + ".png").c_str() );


  h->FitSlicesY();
  TH1 * h_0 = (TH1*)gDirectory->Get( (name + "_0").cstr() );
  TH1 * h_1 = (TH1*)gDirectory->Get( (name + "_1").cstr() );
  TH1 * h_2 = (TH1*)gDirectory->Get( (name + "_2").cstr() );



}

stringtream sstr;

string s = sstr.str();

s.c_str()

void png_maker( string data_file, string histo_name, int nHistos ) {

  TFile * f = new TFile( "/home/sy34/workspace/safe/dEdxvsphi/Pion1Data/nSigmaPion1.root" );

  string name = "dEdxphi";
  for ( int i = 1; i < 10; i++ ){
      stringstream sstr;
      sstr << name << i;
      cout << "name of histo: " << sstr.str() << endl;

      TH2 * h = (TH2*)f->Get( sstr.str().c_str() );
      if ( 0 == h ) continue;
      process_histo( h, sstr.str() );


      // cout << "i am a histogram : " << h->GetName() <<endl;
      // h->Draw();
      //
      // // this ould empty out the sstr
      // // sstr.str( "" );
      // string cn = h->ClassName();
      // cout << "Class:" << cn << endl;
      // if ( "TH2D" == cn ){
      //   cout << "I am 2D" << endl;
      // }
      // sstr << ".png";
      // // c->Print( sstr.str().c_str() );

  }





}
