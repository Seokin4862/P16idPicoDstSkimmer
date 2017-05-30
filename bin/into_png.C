void into_png() {
cout<<"Iwork"<<endl;

TFile * f = new TFile("/home/sy34/workspace/P16idPicoDstSkimmer/bin/graphs_nSigmaProton2.root");

TTree * graphs = (TTree*)f->Get("graphs_nSigmaProton2");

TCanvas * c1 = new TCanvas("c1","c1");

dEdxphi1->Draw("colz");

c1->Print( "dEdxphi1.png" );

dEdxphi2->Draw("colz");

c1->Print( "dEdxphi2.png" );

dEdxphi3->Draw("colz");

c1->Print( "dEdxphi3.png" );

dEdxphi4->Draw("colz");

c1->Print( "dEdxphi4.png" );

dEdxphi5->Draw("colz");

c1->Print( "dEdxphi5.png" );

dEdxphi6->Draw("colz");

c1->Print( "dEdxphi6.png" );

dEdxphi7->Draw("colz");

c1->Print( "dEdxphi7.png" );

dEdxphi8->Draw("colz");

c1->Print( "dEdxphi8.png" );

dEdxphi9->Draw("colz");

c1->Print( "dEdxphi9.png" );
}

