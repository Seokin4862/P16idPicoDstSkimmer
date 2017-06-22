

void gaussfit() {

TFile * f = new TFile( "/home/sy34/workspace/safe/slices/slicesgraphs.root" );

TCanvas *c = new TCanvas( "c", "c" );

TF1 * fit = new TF1( "fit", "gaus" );

double bag = 1.5;
double end = 2;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "alndEdxK0" << i;
} else {
  getslice << "alndEdxK" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = .7;
double end = 1.3;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "alndEdxL0" << i;
} else {
  getslice << "alndEdxL" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 1.3;
double end = 1.45;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "aInvBetaK0" << i;
} else {
  getslice << "aInvBetaK" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 1.04;
double end = 1.13;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "aInvBetaL0" << i;
} else {
  getslice << "aInvBetaL" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}




double bag = 1.5;
double end = 2;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "plndEdxK0" << i;
} else {
  getslice << "plndEdxK" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = .7;
double end = 1.3;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "plndEdxL0" << i;
} else {
  getslice << "plndEdxL" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 1.3;
double end = 1.45;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "pInvBetaK0" << i;
} else {
  getslice << "pInvBetaK" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 1.04;
double end = 1.13;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "pInvBetaL0" << i;
} else {
  getslice << "pInvBetaL" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}





double bag = 1.5;
double end = 2;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "nlndEdxK0" << i;
} else {
  getslice << "nlndEdxK" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = .7;
double end = 1.3;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "nlndEdxL0" << i;
} else {
  getslice << "nlndEdxL" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 1.3;
double end = 1.45;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "nInvBetaK0" << i;
} else {
  getslice << "nInvBetaK" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 1.04;
double end = 1.13;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
if( i < 10 ) {
  getslice << "nInvBetaL0" << i;
} else {
  getslice << "nInvBetaL" << i;
}
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}

}
