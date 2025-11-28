void GaIBU()
{
    TFile *file1;

    TCanvas* c = new TCanvas("c","c",200,10,600,480);

    file1 = TFile::Open("../root_files/tests_regina/gaibu.root");

    TH1D* h1 = (TH1D*)file1->Get("proba");

    h1->GetXaxis()->SetRangeUser(0,5);

    h1->Draw();

    TLegend* legend = new TLegend(0.1,0.7,0.3,0.9);

    legend->AddEntry(h1,TString::Format("Data - Mean = %.1f", h1->GetMean())+" MeV","f");
    legend->SetBorderSize(0);
    legend->SetTextSize(0.05);

    legend->Draw();
}
