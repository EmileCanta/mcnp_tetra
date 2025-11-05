#include "TFile.h"
#include "TF1.h"
#include "fstream"

#include <math.h>

using namespace std;

Double_t f1(Double_t *x, Double_t *par)
{
	return 1.21393103e4/(x[0] * x[0]);
}

Double_t f2(Double_t *x, Double_t *par)
{
	return 1.21393103e4/(x[0] * x[0]);
}

Double_t f3(Double_t *x, Double_t *par)
{
	return 1.;
}

Double_t f4(Double_t *x, Double_t *par)
{
	return 0.9*(pow((1/(M_PI*0.33)), 1.5))*2*M_PI*((pow(x[0], 0.5))*(exp(-x[0]/0.33)))
	+0.1*((1/(0.1*pow(2*M_PI,0.5)))*(exp(-(pow((x[0]-3.0),2)/(2*pow(0.1,2))))));
}

void PlotFunction()
{
	TCanvas* c1 = new TCanvas();
	
	TF1* function1 = new TF1("f1", f1, 0, 20);
	TF1* function2 = new TF1("f2", f2, 0, 20);
	TF1* function3 = new TF1("f3", f3, 0, 20);
	TF1* function4 = new TF1("f4", f4, 0, 20);
	
	TH1F* hist1 = new TH1F("hist1", "hist1", 20000, 0, 20);
	TH1F* hist2 = new TH1F("hist2", "hist2", 200, 0, 20);
	TH1F* hist3 = new TH1F("hist3", "hist3", 200, 0, 20);
	TH1F* hist4 = new TH1F("hist4", "hist4", 200, 0, 20);

	for(int i=0; i<=200; i++)
	{
		hist2->SetBinContent(i,function2->Eval((float)i/10.));
	}

	for(int i=0; i<=20000; i++)
	{
		hist1->SetBinContent(i,function1->Eval((float)i/1000.));
	}

	hist1->Draw();
	hist2->Draw("sameshistplc");
	//hist2->Draw("sameshist");
	//hist4->Draw();
	//hist3->Draw("same");

	//hist2->SetLineColor(kCyan);

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
