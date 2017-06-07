   // - - - - - - - - - -
   // dEdx mapping
   // - - - - - - - - - -
   TString       mMapfileName_dEdx;     // name of the file for dEdx mapping
   TString       mMapfileName_nsigmaE;  // name of the file for nsigmaE mapping
   TFile*        MapFile_dEdx;            // file pointer
   TFile*        MapFile_nsigmaE;      // file pointer

   static const Int_t map_nBinsPt  =  20;
   static const Int_t map_nBinsEta =   5;
   static const Int_t map_nBinsPhi = 180;

   Float_t       map_phi_range = TMath::TwoPi();

   // graphs to load (map for dEdx)
   TGraph* gr_dEdx_map_pp[map_nBinsPt][map_nBinsEta][map_nBinsPhi];
   TGraph* gr_dEdx_map_pn[map_nBinsPt][map_nBinsEta][map_nBinsPhi];
   TGraph* gr_dEdx_map_np[map_nBinsPt][map_nBinsEta][map_nBinsPhi];
   TGraph* gr_dEdx_map_nn[map_nBinsPt][map_nBinsEta][map_nBinsPhi];

   // graphs to load (map for nsigmaE)
   TGraph* gr_nsigmaE_map_pp[map_nBinsPt][map_nBinsEta][map_nBinsPhi];
   TGraph* gr_nsigmaE_map_pn[map_nBinsPt][map_nBinsEta][map_nBinsPhi];
   TGraph* gr_nsigmaE_map_np[map_nBinsPt][map_nBinsEta][map_nBinsPhi];
   TGraph* gr_nsigmaE_map_nn[map_nBinsPt][map_nBinsEta][map_nBinsPhi];
