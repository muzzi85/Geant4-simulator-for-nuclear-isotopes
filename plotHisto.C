{
  gROOT->Reset();
  
  // Draw histos filled by Geant4 simulation 
  //   
  TFile f = TFile("essai.root");      
  TCanvas* c1 = new TCanvas("c1", "  ");
  
  ///TH1D* hist1 = (TH1D*)f.Get("1");
  ///hist1->Draw("HIST");
  
  TH1D* hist2 = (TH1D*)f.Get("2");
  hist2->Draw("HIST");  

  TH1D* hist4 = (TH1D*)f.Get("4");
  hist4->Draw("HIST");
     
  TH1D* hist6 = (TH1D*)f.Get("6");
  hist6->Draw("HIST");

  TH1D* hist14 = (TH1D*)f.Get("14");
  hist14->Draw("HIST");

  TH1D* hist15 = (TH1D*)f.Get("15");
  hist15->Draw("HIST");

  TH1D* hist16 = (TH1D*)f.Get("16");
  hist16->Draw("HIST");

  TH1D* hist17 = (TH1D*)f.Get("17");
  hist17->Draw("HIST");

  TH1D* hist18 = (TH1D*)f.Get("18");
  hist18->Draw("HIST");
}  
