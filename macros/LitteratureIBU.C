void LitteratureIBU()
{
    TFile *file1;
    TFile *file2;
    TFile *file3;
    TFile *file4;

    TCanvas* c = new TCanvas("c","Canvas Example",0,0,500,1000);

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
    
    h1->Scale(1./h1->Integral());
    h2->Scale(1./h2->Integral());
    h3->Scale(1./h3->Integral());
    h4->Scale(1./h4->Integral());

    pad1->Draw();
    pad2->Draw();

    pad1->cd();

    h1->Draw("HIST");
    h1->Draw("SAME HIST P");
    h2->Draw("SAME HIST");
    h2->Draw("SAME HIST P");
    
    h1->SetLineWidth(3);
    h1->SetLineColor(kRed);

    h2->SetLineWidth(3);
    h2->SetLineColor(kBlue); 
    
    h1->SetMarkerStyle(20);
    h1->SetMarkerColor(kRed);
    h1->SetMarkerSize(3.);
    
    h2->SetMarkerStyle(21);
    h2->SetMarkerColor(kBlue);
    h2->SetMarkerSize(3.);
    
    h1->GetXaxis()->SetTitle("Energy (MeV)");
    h1->GetXaxis()->SetRangeUser(0,2.5);
    h1->GetYaxis()->SetTitle("Arbitrary units");
    
    TLegend* legend1 = new TLegend(0.1,0.7,0.3,0.9);

    legend1->AddEntry(h1,TString::Format("Predicted : Mean = %.2f", h1->GetMean())+" MeV - "+ TString::Format("StdDev = %.2f", h1->GetStdDev()) + " MeV","P");
    legend1->AddEntry(h2,TString::Format("Litterature : Mean = %.2f", h2->GetMean())+" MeV - "+ TString::Format("StdDev = %.2f", h2->GetStdDev()) + " MeV","P");
    //legend1->AddEntry(h1,TString::Format("Predicted - Skew = %.2f", h1->GetSkewness())+" MeV","f");
    //legend1->AddEntry(h1,TString::Format("Predicted - Dev = %.2f", h1->GetStdDev())+" MeV","f");
    //legend1->AddEntry(h2,TString::Format("Litterature - Mean = %.2f", h2->GetMean())+" MeV","f");
    //legend1->AddEntry(h2,TString::Format("Litterature - Skew = %.2f", h2->GetSkewness())+" MeV","f");
    //legend1->AddEntry(h2,TString::Format("Litterature - Dev = %.2f", h2->GetStdDev())+" MeV","f");
    legend1->SetBorderSize(0);
    legend1->SetTextSize(0.05);

    legend1->Draw();

    pad2->cd();

    h3->Draw("HIST");
    h3->Draw("SAME HIST P");
    h4->Draw("SAME HIST");
    h4->Draw("SAME HIST P");
    
    h3->SetLineWidth(3);
    h3->SetLineColor(kRed);

    h4->SetLineWidth(3);
    h4->SetLineColor(kBlue); 
    
    h3->SetMarkerStyle(20);
    h3->SetMarkerColor(kRed);
    h3->SetMarkerSize(3.);
    
    h4->SetMarkerStyle(21);
    h4->SetMarkerColor(kBlue);
    h4->SetMarkerSize(3.);
    
    h3->GetXaxis()->SetTitle("Energy (MeV)");
    h3->GetXaxis()->SetRangeUser(0,2.5);
    h3->GetYaxis()->SetTitle("Arbitrary units");

    //h3->Draw();
    //h4->Draw("sameshist");

    TLegend* legend2 = new TLegend(0.1,0.7,0.3,0.9);


    legend2->AddEntry(h3,TString::Format("Predicted : Mean = %.2f", h3->GetMean())+" MeV - "+ TString::Format("StdDev = %.2f", h3->GetStdDev()) + " MeV","P");
    legend2->AddEntry(h4,TString::Format("Litterature : Mean = %.2f", h4->GetMean())+" MeV - "+ TString::Format("StdDev = %.2f", h4->GetStdDev()) + " MeV","P");
    //legend2->AddEntry(h3,TString::Format("Predicted - Mean = %.2f", h3->GetMean())+" MeV","f");
    //legend2->AddEntry(h3,TString::Format("Predicted - Skew = %.2f", h3->GetSkewness())+" MeV","f");
    //legend2->AddEntry(h3,TString::Format("Predicted - Dev = %.2f", h3->GetStdDev())+" MeV","f");
    //legend2->AddEntry(h4,TString::Format("Litterature - Mean = %.2f", h4->GetMean())+" MeV","f");
    //legend2->AddEntry(h4,TString::Format("Litterature - Skew = %.2f", h4->GetSkewness())+" MeV","f");
    //legend2->AddEntry(h4,TString::Format("Litterature - Dev = %.2f", h4->GetStdDev())+" MeV","f");
    legend2->SetBorderSize(0);
    legend2->SetTextSize(0.05);

    legend2->Draw();
}
