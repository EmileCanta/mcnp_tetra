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

    h1->Draw("HIST");
    h1->Draw("SAME P");
    h2->Draw("SAME HIST");
    h2->Draw("SAME P");
    h3->Draw("SAME HIST");
    h3->Draw("SAME P");
    h4->Draw("SAME HIST");
    h4->Draw("SAME P");
    h5->Draw("SAME HIST");
    h5->Draw("SAME P");
    h6->Draw("SAME HIST");
    h6->Draw("SAME P");

    h1->GetXaxis()->SetTitle("Energy (MeV)");
    h1->GetXaxis()->SetRangeUser(0, 5);
    h1->GetYaxis()->SetTitle("Probability / 0.1 MeV");

    h1->SetLineWidth(3);
    h1->SetLineColor(kOrange-3);
    h2->SetLineWidth(3);
    h2->SetLineColor(kRed);
    h3->SetLineWidth(3);
    h3->SetLineColor(kPink-4);
    h4->SetLineWidth(3);
    h4->SetLineColor(kAzure-3);
    h5->SetLineWidth(3);
    h5->SetLineColor(kGreen+1);
    h6->SetLineWidth(3);
    h6->SetLineColor(kBlue+2);
    
    h1->SetMarkerStyle(20);
    h1->SetMarkerColor(kOrange-3);
    h1->SetMarkerSize(3.); 
    h2->SetMarkerStyle(21);
    h2->SetMarkerColor(kRed);
    h2->SetMarkerSize(3.);
    h3->SetMarkerStyle(22);
    h3->SetMarkerColor(kPink-4);
    h3->SetMarkerSize(3.);
    h4->SetMarkerStyle(23);
    h4->SetMarkerColor(kAzure-3);
    h4->SetMarkerSize(3.);
    h5->SetMarkerStyle(24);
    h5->SetMarkerColor(kGreen+1);
    h5->SetMarkerSize(3.);
    h6->SetMarkerStyle(25);
    h6->SetMarkerColor(kBlue+2);
    h6->SetMarkerSize(3.);

    //h1->SetFillColorAlpha(kOrange-3, 0.5);
    //h2->SetFillColorAlpha(kRed, 0.5);
    //h3->SetFillColorAlpha(kPink-4, 0.5);
    //h4->SetFillColorAlpha(kAzure-3, 0.5);
    //h5->SetFillColorAlpha(kGreen+1, 0.5);
    //h6->SetFillColorAlpha(kBlue+2, 0.5);

    TLegend* legend = new TLegend(0.1,0.4,0.6,0.9);

    legend->AddEntry(h1,TString::Format("Mean = %.1f", h1->GetMean()) + " MeV " + TString::Format("StdDev = %.1f", h1->GetStdDev()) + " MeV","P");
    legend->AddEntry(h2,TString::Format("Mean = %.1f", h2->GetMean()) + " MeV " + TString::Format("StdDev = %.1f", h2->GetStdDev()) + " MeV","P");
    legend->AddEntry(h3,TString::Format("Mean = %.1f", h3->GetMean()) + " MeV " + TString::Format("StdDev = %.1f", h3->GetStdDev()) + " MeV","P");
    legend->AddEntry(h4,TString::Format("Mean = %.1f", h4->GetMean()) + " MeV " + TString::Format("StdDev = %.1f", h4->GetStdDev()) + " MeV","P");
    legend->AddEntry(h5,TString::Format("Mean = %.1f", h5->GetMean()) + " MeV " + TString::Format("StdDev = %.1f", h5->GetStdDev()) + " MeV","P");
    legend->AddEntry(h6,TString::Format("Mean = %.1f", h6->GetMean()) + " MeV " + TString::Format("StdDev = %.1f", h6->GetStdDev()) + " MeV","P");
    //legend->AddEntry(h2,TString::Format("1.0 MeV - Mean = %.1f", h2->GetMean())+" MeV","P");
    //legend->AddEntry(h3,TString::Format("1.5 MeV - Mean = %.1f", h3->GetMean())+" MeV","P");
    //legend->AddEntry(h4,TString::Format("2.0 MeV - Mean = %.1f", h4->GetMean())+" MeV","P");
    //legend->AddEntry(h5,TString::Format("2.5 MeV - Mean = %.1f", h5->GetMean())+" MeV","P");
    //legend->AddEntry(h6,TString::Format("3.0 MeV - Mean = %.1f", h6->GetMean())+" MeV","P");
    legend->SetBorderSize(0);
    legend->SetTextSize(0.05);

    legend->Draw();
}
