#include "TFile.h"
#include "TF1.h"
#include "fstream"

#include <math.h>

using namespace std;

void PlotData()
{
	TCanvas* c1 = new TCanvas();

    fstream file;
    double x;
    double y;

    TH1D* hist = new TH1D("hist", "hist", 200, 0, 2);

    file.open("../numerized_data/85As.dat");

    while(1)
    {
        file >> x >> y;

        if(file.eof()) break;

        hist->Fill(x,y*100.);
        //hist->Scale(1./(hist->GetEntries()));
    }

	//hist1->Draw();
	//hist2->Draw("same");
	hist->Draw("hist");
	//hist3->Draw("same");

	/*hist1->SetLineColor(kRed);
	hist2->SetLineColor(kCyan);
	hist3->SetLineColor(kGreen);
	hist4->SetLineColor(kOrange);

	hist1->SetLineWidth(7);
	hist2->SetLineWidth(7);
	hist3->SetLineWidth(7);
	hist4->SetLineWidth(7);

	hist1->GetXaxis()->SetRangeUser(0,20);
	hist1->GetYaxis()->SetRangeUser(0,1);

	hist1->GetXaxis()->SetTitle("Energy (MeV)");
    hist1->GetYaxis()->SetTitle("A.U.");

    hist1->GetXaxis()->SetTitleSize(0.06);
    hist1->GetYaxis()->SetTitleSize(0.06);

    hist1->GetXaxis()->SetLabelSize(0.05);
    hist1->GetYaxis()->SetLabelSize(0.05);

	hist1->GetXaxis()->SetTitleOffset(0.90);
    hist1->GetYaxis()->SetTitleOffset(0.90);

    hist1->GetXaxis()->SetTickSize(0.07);

	//gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

	TLegend *legend = new TLegend(0.65,0.65,0.80,0.85);

    legend->SetTextSize(0.05);
	legend->SetHeader("Mean energy (MeV)","C");
    legend->AddEntry(hist1,"0.2","l");
	legend->AddEntry(hist2,"0.5","l");
	legend->AddEntry(hist3,"1","l");
	legend->AddEntry(hist4,"sum","l");
    legend->SetBorderSize(0);
	legend->Draw();

    gPad->SetLeftMargin(0.20);
    gPad->SetBottomMargin(0.25);

    gPad->RedrawAxis();

	hist1->GetXaxis()->SetTitle("Energy (MeV)");
    hist1->GetYaxis()->SetTitle("A.U.");

	//gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);*/
}
