

void into_png( string data_file , string histo_name , int nHistos) {

TFile * f = new TFile( data_file.c_str() );

for( int i = 1 ; i = nHistos ; i++  ) {
stringname refer;
refer << histo_name << i
cout<< "name of histogram: " << refer.str() << endl;
}

}
