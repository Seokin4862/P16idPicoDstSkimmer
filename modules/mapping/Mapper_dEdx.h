#ifndef MAPPER_DEDX_H
#define MAPPER_DEDX_H

#include "TGraph.h"
#include "TString.h"


class Mapper_dEdx {

protected:

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

public:

  Mapper_dEdx(){

  }

  Mapper_dEdx(TString f_dEdx, TString f_nSigmaE){
    load_maps(f_dEdx, f_nSigmaE);
  }


  void load_maps( TString f_dEdx, TString f_nSigmaE ){
    mMapfileName_dEdx = f_dEdx;
    mMapfileName_nsigmaE = f_nSigmaE;

    load_map_dEdx();
    load_map_nsigmaE();
  }


  void load_map_dEdx()
  {
      MapFile_dEdx = new TFile(mMapfileName_dEdx, "OPEN");

      if(MapFile_dEdx)
      {
          for(Int_t i=0; i<map_nBinsPt; i++)
          {
              //cout << i << endl;

              for(Int_t j=0; j<map_nBinsEta; j++)
              {
                  for(Int_t k=0; k<map_nBinsPhi; k++)
                  {
                          gr_dEdx_map_pp[i][j][k] = (TGraph*) MapFile_dEdx->Get(Form("gr_dedx_map_ptbin_%d_etabin_%d_pp_%d", i, j, k));
                          gr_dEdx_map_pn[i][j][k] = (TGraph*) MapFile_dEdx->Get(Form("gr_dedx_map_ptbin_%d_etabin_%d_pn_%d", i, j, k));
                          gr_dEdx_map_np[i][j][k] = (TGraph*) MapFile_dEdx->Get(Form("gr_dedx_map_ptbin_%d_etabin_%d_np_%d", i, j, k));
                          gr_dEdx_map_nn[i][j][k] = (TGraph*) MapFile_dEdx->Get(Form("gr_dedx_map_ptbin_%d_etabin_%d_nn_%d", i, j, k));

                          gr_dEdx_map_pp[i][j][k]->SetBit(BIT(19));
                          gr_dEdx_map_pn[i][j][k]->SetBit(BIT(19));
                          gr_dEdx_map_np[i][j][k]->SetBit(BIT(19));
                          gr_dEdx_map_nn[i][j][k]->SetBit(BIT(19));
                  }
              }
          }
          cout << "  ## -- ## maps for dEdx loaded ## -- ##  " << endl;
     }

  }

  void load_map_nsigmaE()
  {
      MapFile_nsigmaE = new TFile(mMapfileName_nsigmaE, "OPEN");

      if(MapFile_nsigmaE)
      {
          for(Int_t i=0; i<map_nBinsPt; i++)
          {
              //cout << i << endl;

              for(Int_t j=0; j<map_nBinsEta; j++)
              {
                  for(Int_t k=0; k<map_nBinsPhi; k++)
                  {
                          gr_nsigmaE_map_pp[i][j][k] = (TGraph*) MapFile_nsigmaE->Get(Form("gr_nsigmae_map_ptbin_%d_etabin_%d_pp_%d", i, j, k));
                          gr_nsigmaE_map_pn[i][j][k] = (TGraph*) MapFile_nsigmaE->Get(Form("gr_nsigmae_map_ptbin_%d_etabin_%d_pn_%d", i, j, k));
                          gr_nsigmaE_map_np[i][j][k] = (TGraph*) MapFile_nsigmaE->Get(Form("gr_nsigmae_map_ptbin_%d_etabin_%d_np_%d", i, j, k));
                          gr_nsigmaE_map_nn[i][j][k] = (TGraph*) MapFile_nsigmaE->Get(Form("gr_nsigmae_map_ptbin_%d_etabin_%d_nn_%d", i, j, k));

                          gr_nsigmaE_map_pp[i][j][k]->SetBit(BIT(19));
                          gr_nsigmaE_map_pn[i][j][k]->SetBit(BIT(19));
                          gr_nsigmaE_map_np[i][j][k]->SetBit(BIT(19));
                          gr_nsigmaE_map_nn[i][j][k]->SetBit(BIT(19));
                  }
              }
          }
          cout << "  ## -- ## maps for nsigmaE loaded ## -- ##  " << endl;
      }
  }


  void apply_map_dEdx_nsigmaE(Float_t _phi, Float_t _eta, Short_t _charge, Float_t _pt, Float_t _dEdx, Float_t _nsigmaE,
                                                                    Float_t& _dEdx_mapped, Float_t& _nsigmaE_mapped
                                                                   )
  {
      // find phi bin
      Int_t phi_index = TMath::Floor(map_nBinsPhi * (_phi + map_phi_range/2.) / map_phi_range);

      // just in case somthing with index edges goes wrong
      if(phi_index<0)
      {
          cout << "phi_index < 0 -> set to 0" << endl;
          phi_index = 0;
      }
      if(phi_index>map_nBinsPhi-1)
      {
          cout << "phi_index > max. range -> set to max." << endl;
          phi_index = map_nBinsPhi-1;
      }


      // find pt bin
      Int_t ptbin = map_invpt_bins(_pt);

      //cout << pt << "  "  << ptbin << "   " << phi_index << endl;

      if(ptbin>19) ptbin = 19;
      if(ptbin< 0) return;



      // find eta bin
      Int_t etabin = map_eta_bins(_eta);
      if(etabin<0) return;



      // dEdx & nsigmaE mapping with TGraphs
      if(_charge>0 && _eta >= 0) _dEdx_mapped = gr_dEdx_map_pp[ptbin][etabin][phi_index]->Eval(_dEdx);
      else if(_charge>0 && _eta <  0) _dEdx_mapped = gr_dEdx_map_pn[ptbin][etabin][phi_index]->Eval(_dEdx);
      else if(_charge<0 && _eta >= 0) _dEdx_mapped = gr_dEdx_map_np[ptbin][etabin][phi_index]->Eval(_dEdx);
      else if(_charge<0 && _eta <  0) _dEdx_mapped = gr_dEdx_map_nn[ptbin][etabin][phi_index]->Eval(_dEdx);

      if(_charge>0 && _eta >= 0) _nsigmaE_mapped = gr_nsigmaE_map_pp[ptbin][etabin][phi_index]->Eval(_nsigmaE);
      else if(_charge>0 && _eta <  0) _nsigmaE_mapped = gr_nsigmaE_map_pn[ptbin][etabin][phi_index]->Eval(_nsigmaE);
      else if(_charge<0 && _eta >= 0) _nsigmaE_mapped = gr_nsigmaE_map_np[ptbin][etabin][phi_index]->Eval(_nsigmaE);
      else if(_charge<0 && _eta <  0) _nsigmaE_mapped = gr_nsigmaE_map_nn[ptbin][etabin][phi_index]->Eval(_nsigmaE);
  }

  //------------------------------------------------------------------------------------------------------


  //------------------------------------------------------------------------------------------------------
  // helper functions to find the pt and eta bins for the graphs
  //------------------------------------------------------------------------------------------------------

  inline UInt_t map_invpt_bins(Float_t _pt)
  {
      Float_t invpt = 999;

      if(_pt>0) invpt = 1./_pt;

      Int_t bin = -1;

      if(     invpt > 5.0) bin = 0;
      else if(invpt > 4.5) bin = 1;
      else if(invpt > 4.0) bin = 2;
      else if(invpt > 3.5) bin = 3;
      else if(invpt > 3.0) bin = 4;
      else if(invpt > 2.6) bin = 5;
      else if(invpt > 2.2) bin = 6;
      else if(invpt > 1.8) bin = 7;
      else if(invpt > 1.6) bin = 8;
      else if(invpt > 1.4) bin = 9;
      else if(invpt > 1.2) bin = 10;
      else if(invpt > 1.0) bin = 11;
      else if(invpt > 0.8) bin = 12;
      else if(invpt > 0.7) bin = 13;
      else if(invpt > 0.6) bin = 14;
      else if(invpt > 0.5) bin = 15;
      else if(invpt > 0.4) bin = 16;
      else if(invpt > 0.3) bin = 17;
      else if(invpt > 0.2) bin = 18;
      else                 bin = 19;

      return bin;
  }

  //------------------------------------------------------------------------------------------------------

  inline UInt_t map_eta_bins(Float_t _eta)
  {

      Int_t bin = -1;

      if(     fabs(_eta) < 0.2) bin = 0;
      else if(fabs(_eta) < 0.4) bin = 1;
      else if(fabs(_eta) < 0.6) bin = 2;
      else if(fabs(_eta) < 0.8) bin = 3;
      else if(fabs(_eta) < 1.0) bin = 4;

      return bin;
  }



};

#endif
