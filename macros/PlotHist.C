#include <sstream>

void PlotHist()
{
    TFile *file1;
    TFile *file2;
    TFile *file3;
    TFile *file4;
    TFile *file5;
    TFile *file6;
    TFile *file7;

    TCanvas* c1 = new TCanvas("c1","Canvas Example",200,10,600,480);

    TPad* pad1 = new TPad("pad1","This is pad1",0.05,0.05,0.5,0.95);
    TPad* pad2 = new TPad("pad2","This is pad2",0.5,0.05,0.95,0.95);

    file1 = TFile::Open("../root_files/80Ga_ibu.root");
    file2 = TFile::Open("../root_files/80Ga.root");
    file3 = TFile::Open("../root_files/137I_ibu.root");
    file4 = TFile::Open("../root_files/137I.root");
    file5 = TFile::Open("../root_files/2500.root");
    file6 = TFile::Open("../root_files/3000.root");
    file7 = TFile::Open("../root_files/mono_5000.root");

    TH1D* h1 = (TH1D*)file1->Get("proba");
    TH1F* h2 = (TH1F*)file2->Get("hist");
    TH1D* h3 = (TH1D*)file3->Get("proba");
    TH1D* h4 = (TH1D*)file4->Get("hist");
    TH1D* h5 = (TH1D*)file5->Get("proba");
    TH1D* h6 = (TH1D*)file6->Get("proba");
    TH1D* h7 = (TH1D*)file7->Get("proba");

    //Graphics part

    //h1->Rebin(64);
    h2->Rebin(10);
    h4->Rebin(10);

    h2->Scale(1./100.);
    h4->Scale(1./100.);

    pad1->Draw();
    pad2->Draw();

    pad1->cd();

    //h3->Scale(1./134.);
    h1->Draw();
    h2->Draw("sameshist");
    //h3->Draw("same");
    //h4->Draw("same");
    //h5->Draw("same");
    //h6->Draw("same");
    //h7->Draw("same");
    gStyle->SetOptStat(0);

    TLegend* legend1 = new TLegend(0.1,0.7,0.3,0.9);

    legend1->AddEntry(h1,TString::Format("80Ga predicted ; Mean = %.2f", h1->GetMean())+" MeV","l");
    legend1->AddEntry(h2,TString::Format("80Ga litterature ; Mean = %.2f", h2->GetMean())+" MeV","l");
    //legend1->AddEntry(h3,TString::Format("1.5 MeV mono-energetic distribution ; Mean = %g", h3->GetMean())+" MeV","l");
    //legend1->AddEntry(h4,TString::Format("2.0 MeV mono-energetic distribution ; Mean = %g", h4->GetMean())+" MeV","l");
    //legend1->AddEntry(h5,TString::Format("2.5 MeV mono-energetic distribution ; Mean = %g", h5->GetMean())+" MeV","l");
    //legend1->AddEntry(h6,TString::Format("3.0 MeV mono-energetic distribution ; Mean = %g", h6->GetMean())+" MeV","l");
    //legend1->AddEntry(h7,TString::Format("5.0 MeV mono-energetic distribution ; Mean = %g", h7->GetMean())+" MeV","l");
    legend1->SetBorderSize(0);
    legend1->SetTextSize(0.03);

    legend1->Draw();

    pad2->cd();

    h3->Draw();
    h4->Draw("sameshist");
    gStyle->SetOptStat(0);
    /*h1->Draw("same");
    h2->Draw("same");
    h4->Draw("same");
    h5->Draw("same");*/
    
    h1->SetLineColor(kAzure-4);
    h1->SetLineWidth(7);
    h2->SetLineColor(kViolet-5);
    h2->SetLineWidth(7);
    h3->SetLineColor(kAzure-4);
    h3->SetLineWidth(7);
    h4->SetLineColor(kAzure-3);
    h4->SetLineWidth(7);
    h5->SetLineColor(kAzure-2);
    h5->SetLineWidth(7);
    h6->SetLineColor(kAzure-1);
    h6->SetLineWidth(7);
    h7->SetLineColor(kAzure);
    h7->SetLineWidth(7);

    /*h3->GetXaxis()->SetTitle("Energy (keV)");
    h3->GetYaxis()->SetTitle("Probability / 10 keV");

    h3->GetXaxis()->SetTitleSize(0.05);
    h3->GetYaxis()->SetTitleSize(0.05);

    h3->GetXaxis()->SetLabelSize(0.04);
    h3->GetYaxis()->SetLabelSize(0.04);

    h3->GetXaxis()->SetTitleOffset(0.8);
    h3->GetYaxis()->SetTitleOffset(1.0);

    h3->GetXaxis()->SetTickSize(0.03);*/

    /*gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);*/

    TLegend* legend2 = new TLegend(0.1,0.7,0.3,0.9);

    legend2->AddEntry(h3,TString::Format("137I predicted ; Mean = %.2f", h3->GetMean())+" MeV","l");
    legend2->AddEntry(h4,TString::Format("137I litterature ; Mean = %.2f", h4->GetMean())+" MeV","l");
    //legend2->AddEntry(h5,TString::Format("Predicted distribution with 5. MeV monoenergetic input ; Mean = %g", h5->GetMean())+" MeV","l");
    legend2->SetBorderSize(0);
    legend2->SetTextSize(0.03);

    legend2->Draw();

    /*gPad->SetLeftMargin(0.20);
    gPad->SetBottomMargin(0.25);
    
    gPad->SetLeftMargin(0.20);
    gPad->SetBottomMargin(0.25);

    gPad->RedrawAxis();*/
}