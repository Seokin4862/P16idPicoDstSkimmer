

void gaussfit() {

TFile * f = new TFile( "/home/sy34/workspace/safe/slices/slicesgraphs.root" );

TCanvas *c = new TCanvas( "c", "c" );

TF1 * fit = new TF1( "fit", "gaus" );

double bag = 1.5;
double end = 2;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
getslice << "alndEdxK" << i;
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
getslice << "alndEdxL" << i;
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
getslice << "aInvBetaK" << i;
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
getslice << "aInvBetaL" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}




double bag = 0;
double end = 20;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
getslice << "plndEdxK" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 0;
double end = 20;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
getslice << "plndEdxL" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 0;
double end = 20;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
getslice << "pInvBetaK" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 0;
double end = 20;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
getslice << "pInvBetaL" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}





double bag = 0;
double end = 20;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
getslice << "nlndEdxK" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 0;
double end = 20;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
getslice << "nlndEdxL" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 0;
double end = 20;

for( int i = 11; i < 36; i++ ){
stringstream getslice;
getslice << "nInvBetaK" << i;
TH1 *turandot = (TH1*)f->Get( getslice.str().c_str() );
turandot->Draw();
c->SetLogy();
turandot->Fit( fit, "R" , "" , bag, end );
bag = fit->GetParameter(1) - 2*fit->GetParameter(2);
end = fit->GetParameter(1) + 2*fit->GetParameter(2);
getslice << "fitted.png";
c->Print( getslice.str().c_str() );
}


double bag = 0;
double end = 20;

for( int i = 8; i < 41; i++ ){
stringstream getslice;
getslice << "nInvBetaL" << i;
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
