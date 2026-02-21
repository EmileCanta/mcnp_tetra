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
    file2 = TFile::Open("../root_files/mannhart.root");

    TH1D* h1 = (TH1D*)file1->Get("proba");
    TGraph* g1 = (TGraph*)file2->Get("mannhart");

    pad2->cd();

    g1->Scale(0.1);

    h1->Draw();
    g1->Draw("same");

    TLegend* legend = new TLegend(0.1,0.7,0.3,0.9);

    legend->AddEntry(h1,TString::Format("Predicted - Mean = %.1f", h1->GetMean())+" MeV","l");
    legend->AddEntry(g1,"Mannhart evaluation - Mean = 2.1 MeV", "l");
    legend->SetBorderSize(0);
    legend->SetTextSize(0.05);

    TH1D* ratiohist = new TH1D("ratiohist", "ratiohist", h1->GetNbinsX(), 0, h1->GetXaxis()->GetXmax());

    for(int i = 1; i <= h1->GetNbinsX(); i++)
    {
        graph->AddPoint(h1->GetBinCenter(i), h1->GetBinContent(i)/g1->Eval(h1->GetBinCenter(i)));
        ratiohist->SetBinContent(i, h1->GetBinContent(i)/g1->Eval(h1->GetBinCenter(i)));
    }

    TLine* l = new TLine(graph->GetXaxis()->GetXmin(),1,5,1);

    legend->Draw();

    pad1->cd();

    //graph->Draw("AP");
    ratiohist->Draw("same");

    l->Draw("same");
}
