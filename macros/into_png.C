void into_png() {

TFile * f = new TFile( data_file.c_str() );

for( int i = 1 ; i = nHistos ; i++  ) {
stringname refer;
refer << histo_name << i
cout<< "name of histogram: " << refer.str() << endl;
}

}
