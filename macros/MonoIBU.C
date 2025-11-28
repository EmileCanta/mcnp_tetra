void MonoIBU()
{
    TFile *file1;
    TFile *file2;
    TFile *file3;
    TFile *file4;
    TFile *file5;
    TFile *file6;

    TCanvas* c1 = new TCanvas("c","c",200,10,600,480);

    file1 = TFile::Open("../root_files/500.root");
    file2 = TFile::Open("../root_files/1000.root");
    file3 = TFile::Open("../root_files/1500.root");
    file4 = TFile::Open("../root_files/2000.root");
    file5 = TFile::Open("../root_files/2500.root");
    file6 = TFile::Open("../root_files/3000.root");


    TH1D* h1 = (TH1D*)file1->Get("proba");
    TH1F* h2 = (TH1F*)file2->Get("proba");
    TH1D* h3 = (TH1D*)file3->Get("proba");
    TH1D* h4 = (TH1D*)file4->Get("proba");
    TH1D* h5 = (TH1D*)file5->Get("proba");
    TH1D* h6 = (TH1D*)file6->Get("proba");

    h1->Draw();
    h2->Draw("sameshist");
    h3->Draw("sameshist");
    h4->Draw("sameshist");
    h5->Draw("sameshist");
    h6->Draw("sameshist");

    h1->GetXaxis()->SetTitle("Energy (MeV)");
    h1->GetYaxis()->SetTitle("Probability / 0.1 MeV");

    h1->SetLineWidth(3);
    h1->SetLineColor(kBlack);
    h2->SetLineWidth(3);
    h2->SetLineColor(kBlack);
    h3->SetLineWidth(3);
    h3->SetLineColor(kBlack);
    h4->SetLineWidth(3);
    h4->SetLineColor(kBlack);
    h5->SetLineWidth(3);
    h5->SetLineColor(kBlack);
    h6->SetLineWidth(3);
    h6->SetLineColor(kBlack);

    TLegend* legend = new TLegend(0.1,0.4,0.6,0.9);

    legend->AddEntry(h1,TString::Format("0.5 MeV - Mean = %.1f", h1->GetMean())+" MeV","f");
    legend->AddEntry(h2,TString::Format("1.0 MeV - Mean = %.1f", h2->GetMean())+" MeV","f");
    legend->AddEntry(h3,TString::Format("1.5 MeV - Mean = %.1f", h3->GetMean())+" MeV","f");
    legend->AddEntry(h4,TString::Format("2.0 MeV - Mean = %.1f", h4->GetMean())+" MeV","f");
    legend->AddEntry(h5,TString::Format("2.5 MeV - Mean = %.1f", h5->GetMean())+" MeV","f");
    legend->AddEntry(h6,TString::Format("3.0 MeV - Mean = %.1f", h6->GetMean())+" MeV","f");
    legend->SetBorderSize(0);
    legend->SetTextSize(0.05);

    legend->Draw();
}
