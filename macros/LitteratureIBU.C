void LitteratureIBU()
{
    TFile *file1;
    TFile *file2;
    TFile *file3;
    TFile *file4;

    TCanvas* c = new TCanvas("c","Canvas Example",200,10,600,480);

    TPad* pad1 = new TPad("p1","p1",0,0,1,0.5);
    TPad* pad2 = new TPad("p2","p2",0,0.5,1,1);

    file1 = TFile::Open("../root_files/80Ga_ibu.root");
    file2 = TFile::Open("../root_files/80Ga.root");
    file3 = TFile::Open("../root_files/137I_ibu.root");
    file4 = TFile::Open("../root_files/137I.root");

    TH1D* h1 = (TH1D*)file1->Get("proba");
    TH1F* h2 = (TH1F*)file2->Get("hist");
    TH1D* h3 = (TH1D*)file3->Get("proba");
    TH1D* h4 = (TH1D*)file4->Get("hist");

    h2->RebinX(10.);
    h4->RebinX(10.);
    
    h2->Scale(7./1000.);
    h4->Scale(7./1000.);

    pad1->Draw();
    pad2->Draw();

    pad1->cd();

    h1->Draw();
    h2->Draw("sameshist");

    h1->GetXaxis()->SetTitle("Energy (MeV)");
    h1->GetYaxis()->SetTitle("Probability / 0.1 MeV");

    h1->SetLineWidth(3);
    h1->SetLineColor(kBlack);
    h2->SetLineWidth(3);
    h2->SetLineColor(kBlack);
    
    TLegend* legend1 = new TLegend(0.1,0.7,0.3,0.9);

    legend1->AddEntry(h1,TString::Format("Predicted - Mean = %.1f", h1->GetMean())+" MeV","f");
    legend1->AddEntry(h2,TString::Format("Litterature - Mean = %.1f", h2->GetMean())+" MeV","f");
    legend1->SetBorderSize(0);
    legend1->SetTextSize(0.05);

    legend1->Draw();

    pad2->cd();
    
    h3->GetXaxis()->SetTitle("Energy (MeV)");
    h3->GetYaxis()->SetTitle("Probability / 0.1 MeV");

    h3->SetLineWidth(3);
    h3->SetLineColor(kBlack);
    h4->SetLineWidth(3);
    h4->SetLineColor(kBlack);

    h3->Draw();
    h4->Draw("sameshist");

    TLegend* legend2 = new TLegend(0.1,0.7,0.3,0.9);

    legend2->AddEntry(h3,TString::Format("Predicted - Mean = %.1f", h3->GetMean())+" MeV","f");
    legend2->AddEntry(h4,TString::Format("Litterature - Mean = %.1f", h4->GetMean())+" MeV","f");
    legend2->SetBorderSize(0);
    legend2->SetTextSize(0.05);

    legend2->Draw();
}
