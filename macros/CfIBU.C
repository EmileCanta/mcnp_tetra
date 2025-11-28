void CfIBU()
{
    TFile *file1;
    TFile *file2;
    TFile *file3;

    TCanvas* c = new TCanvas("c","c",200,10,600,480);

    TPad* pad1 = new TPad("pad1","pad1",0,0,1,0.3);
 	TPad* pad2 = new TPad("pad2","pad2",0,0.3,1,1);
    
    pad1->Draw();
    pad2->Draw();
    
    TGraph* graph = new TGraph();

    file1 = TFile::Open("../root_files/tests_regina/sansge.root");
    file2 = TFile::Open("../root_files/tests_regina/anamaxw.root");

    TH1D* h1 = (TH1D*)file1->Get("proba");
    TH1D* h2 = (TH1D*)file2->Get("hist2");

    pad2->cd();

    h1->Draw();
    h2->Draw("sameshist");

    TLegend* legend = new TLegend(0.1,0.7,0.3,0.9);

    legend->AddEntry(h1,TString::Format("Predicted - Mean = %.1f", h1->GetMean())+" MeV","f");
    legend->AddEntry(h2,TString::Format("Maxwellian distribution - Mean = %.1f", h2->GetMean())+" MeV","f");
    legend->SetBorderSize(0);
    legend->SetTextSize(0.05);

    for(int i = 1; i <= h1->GetNbinsX(); i++)
    {
        graph->AddPoint(h1->GetBinCenter(i), (h2->GetBinContent(i)-h1->GetBinContent(i))/h2->GetBinContent(i));
    }

    TLine* l = new TLine(graph->GetXaxis()->GetXmin(),0,5,0);

    legend->Draw();

    pad1->cd();

    graph->Draw("AP");

    l->Draw("same");
}
