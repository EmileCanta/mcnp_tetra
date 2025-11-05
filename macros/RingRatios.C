#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <iterator>

#include <root/TGraph.h>
#include <root/TCanvas.h>
#include <root/TMultiGraph.h>
#include <root/TPad.h>
#include <root/TAxis.h>

using namespace std;

void RingRatios() {

	std::vector<double> xaxis;
	std::vector<double> Nvectot;
	std::vector<double> Nvec1;
	std::vector<double> Nvec2;
	std::vector<double> Nvec3;
	std::vector<double> Nvec4;

	std::vector<double> ratiovec1;
	std::vector<double> ratiovec2;
	std::vector<double> ratiovec3;
	std::vector<double> ratiovec4;
	std::vector<double> ratiovec5;
	std::vector<double> ratiovec6;

	std::vector<double> Nvectot_maxw;
	std::vector<double> Nvec1_maxw;
	std::vector<double> Nvec2_maxw;
	std::vector<double> Nvec3_maxw;
	std::vector<double> Nvec4_maxw;

	std::vector<double> ratiovec1_maxw;
	std::vector<double> ratiovec2_maxw;
	std::vector<double> ratiovec3_maxw;
	std::vector<double> ratiovec4_maxw;
	std::vector<double> ratiovec5_maxw;
	std::vector<double> ratiovec6_maxw;
	
	for(double i = 0.01; i <= 10.; i = i+0.01)
	{
		xaxis.push_back(i);
	}

	double value1;
	double value2;
	double value3;
	double value4;
	double value5;

	double error1;
	double error2;
	double error3;
	double error4;
	double error5;

	double value1_maxw;
	double value2_maxw;
	double value3_maxw;
	double value4_maxw;
	double value5_maxw;

	double error1_maxw;
	double error2_maxw;
	double error3_maxw;
	double error4_maxw;
	double error5_maxw;

    std::ifstream fichier("/Users/cantacuzene/phd/data/mcnp_tetra/maxw_2bar_full/data.dat");
	std::ifstream fichier2("/Users/cantacuzene/phd/data/mcnp_tetra/maxw_2bar_full/data.dat");

    std::string ligne;

	int binningvar = 0;

    while (1) 
	{
		fichier >> value1 >> error1 >> value2 >> error2 >> value3 >> error3 >> value4 >> error4 >> value5 >> error5;
		fichier2 >> value1_maxw>> error1_maxw >> value2_maxw >> error2_maxw >> value3_maxw >> error3_maxw >> value4_maxw >> error4_maxw >> value5_maxw >> error5_maxw;

		if(binningvar%1 == 0)
      	{
        	Nvectot.push_back(value1);
			Nvec1.push_back(value2);
			Nvec2.push_back(value3);
			Nvec3.push_back(value4);
			Nvec4.push_back(value5);

			ratiovec1.push_back(value3/value2);
			ratiovec2.push_back(value4/value2);
			ratiovec3.push_back(value5/value2);
			ratiovec4.push_back(value4/value3);
			ratiovec5.push_back(value5/value3);
			ratiovec6.push_back(value5/value4);

			Nvectot_maxw.push_back(value1_maxw);
			Nvec1_maxw.push_back(value2_maxw);
			Nvec2_maxw.push_back(value3_maxw);
			Nvec3_maxw.push_back(value4_maxw);
			Nvec4_maxw.push_back(value5_maxw);

			ratiovec1_maxw.push_back(value3_maxw/value2_maxw);
			ratiovec2_maxw.push_back(value4_maxw/value2_maxw);
			ratiovec3_maxw.push_back(value5_maxw/value2_maxw);
			ratiovec4_maxw.push_back(value4_maxw/value3_maxw);
			ratiovec5_maxw.push_back(value5_maxw/value3_maxw);
			ratiovec6_maxw.push_back(value5_maxw/value4_maxw);
      	}

      	binningvar++;

		if(fichier.eof()) break;
    }

	TCanvas *c1 = new TCanvas();
	TCanvas *c2 = new TCanvas();

	TPad* pad1 = new TPad("pad1","This is pad1",0.05,0.05,0.95,0.95);
 	TPad* pad2 = new TPad("pad2","This is pad2",0.60,0.75,0.80,0.80);
	
	TMultiGraph *mg = new TMultiGraph();

	TMultiGraph *mgratios = new TMultiGraph();
	TMultiGraph *mgratioscompare = new TMultiGraph();
	
	TGraph *graph1 = new TGraph();
	TGraph *graph2 = new TGraph();
	TGraph *graph3 = new TGraph();
	TGraph *graph4 = new TGraph();
	TGraph *graph5 = new TGraph();

	TGraph *graph1ratios = new TGraph();
	TGraph *graph2ratios = new TGraph();
	TGraph *graph3ratios = new TGraph();
	TGraph *graph4ratios = new TGraph();
	TGraph *graph5ratios = new TGraph();
	TGraph *graph6ratios = new TGraph();

	TGraph *graphratioscompare = new TGraph();

	TGraph *data_84 = new TGraph();
	TGraph *data_82 = new TGraph();
	TGraph *data_252 = new TGraph();
	
	for(int j = 0; j <= 999; j++)
	{
		graph1->AddPoint(xaxis[j], Nvectot[j]);
		graph2->AddPoint(xaxis[j], Nvec1[j]);
		graph3->AddPoint(xaxis[j], Nvec2[j]);
		graph4->AddPoint(xaxis[j], Nvec3[j]);
		graph5->AddPoint(xaxis[j], Nvec4[j]);

		graph1ratios->AddPoint(xaxis[j], ratiovec1[j]);
		graph2ratios->AddPoint(xaxis[j], ratiovec2[j]);
		graph3ratios->AddPoint(xaxis[j], ratiovec3[j]);
		graph4ratios->AddPoint(xaxis[j], ratiovec4[j]);
		graph5ratios->AddPoint(xaxis[j], ratiovec5[j]);
		graph6ratios->AddPoint(xaxis[j], ratiovec6[j]);

		graphratioscompare->AddPoint(xaxis[j], ratiovec1_maxw[j]);
	}

	TGraph graph1inv = TGraph(graph1ratios->GetN(), graph1ratios->GetY(), graph1ratios->GetX());
	TGraph graph2inv = TGraph(graph2ratios->GetN(), graph2ratios->GetY(), graph2ratios->GetX());
	TGraph graph3inv = TGraph(graph3ratios->GetN(), graph3ratios->GetY(), graph3ratios->GetX());
	TGraph graph4inv = TGraph(graph4ratios->GetN(), graph4ratios->GetY(), graph4ratios->GetX());
	TGraph graph5inv = TGraph(graph5ratios->GetN(), graph5ratios->GetY(), graph5ratios->GetX());
	TGraph graph6inv = TGraph(graph6ratios->GetN(), graph6ratios->GetY(), graph6ratios->GetX());

	//Partie efficacité

	/*double eval1 = graph1->Eval(0.5);
	double eval2 = graph1->Eval(2.2);
	double eval3 = graph1->Eval(1.3);

	cout << "Eff1:" << eval1 << endl;
	cout << "Eff2:" << eval2 << endl;
	cout << "Eff3:" << eval3 << endl;

	TLine *line1 = new TLine(0.5, -0.5, 0.5, 53.3);
	TLine *line2 = new TLine(2.2, -0.5, 2.2, 46.9);
	TLine *line3 = new TLine(1.3, -0.5, 1.3, 50.);

	TLine *line4 = new TLine(-0.2, 53.3, 0.5, 53.3);
	TLine *line5 = new TLine(-0.2, 46.9, 2.2, 46.9);
	TLine *line6 = new TLine(-0.2, 50., 1.3, 50.);*/
	
	graph1->SetTitle("EffTot");
	graph2->SetTitle("EffR1");
	graph3->SetTitle("EffR2");
	graph4->SetTitle("EffR3");
	graph5->SetTitle("EffR4");
	
	graph1->SetLineColor(kBlack);
	graph2->SetLineColor(kRed);
	graph3->SetLineColor(kCyan);
	graph4->SetLineColor(kGreen);
	graph5->SetLineColor(kOrange);
	
	graph1->SetLineWidth(7);
	graph2->SetLineWidth(7);
	graph3->SetLineWidth(7);
	graph4->SetLineWidth(7);
	graph5->SetLineWidth(7);

	mg->Add(graph1);
	mg->Add(graph2);
	mg->Add(graph3);
	mg->Add(graph4);
	mg->Add(graph5);

	c1->cd();
	
    mg->GetXaxis()->SetTitle("Energy (MeV)");
    mg->GetYaxis()->SetTitle("Efficiency (%)");
	mg->Draw("A");

	/*mg->GetXaxis()->SetTitleSize(0.06);
    mg->GetYaxis()->SetTitleSize(0.06);

    mg->GetXaxis()->SetLabelSize(0.05);
    mg->GetYaxis()->SetLabelSize(0.05);

    mg->GetXaxis()->SetTitleOffset(0.90);
    mg->GetYaxis()->SetTitleOffset(0.70);

    mg->GetXaxis()->SetTickSize(0.07);*/
	
	TLegend* legend = new TLegend(0.1,0.7,0.3,0.9);

    legend->AddEntry(graph1,"Total efficiency","l");
    legend->AddEntry(graph2,"Ring 1","l");
    legend->AddEntry(graph3,"Ring 2","l");
	legend->AddEntry(graph4,"Ring 3","l");
	legend->AddEntry(graph5,"Ring 4","l");
    legend->SetBorderSize(1);
    legend->SetTextSize(0.05);

	legend->Draw();

	/*line1->SetLineWidth(7);
   	line1->SetLineColor(kBlack);
   	line1->Draw("same");

	line2->SetLineWidth(7);
   	line2->SetLineColor(kBlack);
   	line2->Draw("same");

	line3->SetLineWidth(7);
   	line3->SetLineColor(kBlack);
   	line3->Draw("same");

	line4->SetLineWidth(7);
   	line4->SetLineColor(kBlack);
   	line4->Draw("same");

	line5->SetLineWidth(7);
   	line5->SetLineColor(kBlack);
   	line5->Draw("same");

	line6->SetLineWidth(7);
   	line6->SetLineColor(kBlack);
   	line6->Draw("same");*/

    /*gPad->SetLeftMargin(0.20);
    gPad->SetBottomMargin(0.25);

    gPad->RedrawAxis();*/

	double r1_82 = (2.10774E-01);
	double r2_82 = (1.79332E-01);
	double r3_82 = (9.85216E-02);
	double r4_82 = (4.51530E-02);

	/*double r1_252 = (1508846.00)+(1508846.00);
	double r2_252 = (1516551.00)+(1516551.00);
	double r3_252 = (1085034.000)+(1085034.000);
	double r4_252 = (677673.000)+(677673.000);*/

	/*exp.push_back(19983.00); //84Ga
  exp.push_back(14649.00);
  exp.push_back(8559.00);
  exp.push_back(6157.000);*/

	double r1_252 = (2.10774E-01);
	double r2_252 = (1.79332E-01);
	double r3_252 = (9.85216E-02);
	double r4_252 = (4.51530E-02);

	double rr1_252 = r2_252/r1_252;
	double rr2_252 = r3_252/r1_252;
	double rr3_252 = r4_252/r1_252;
	double rr4_252 = r3_252/r2_252;
	double rr5_252 = r4_252/r2_252;
	double rr6_252 = r4_252/r3_252;

	double rr1_82 = r2_82/r1_82;
	double rr2_82 = r3_82/r1_82;
	double rr3_82 = r4_82/r1_82;
	double rr4_82 = r3_82/r2_82;
	double rr5_82 = r4_82/r2_82;
	double rr6_82 = r4_82/r3_82;

	double eval1_82 = graph1inv.Eval(rr1_82);
	double eval2_82 = graph2inv.Eval(rr2_82);
	double eval3_82 = graph3inv.Eval(rr3_82);
	double eval4_82 = graph4inv.Eval(rr4_82);
	double eval5_82 = graph5inv.Eval(rr5_82);
	double eval6_82 = graph6inv.Eval(rr6_82);

	double eval1_252 = graph1inv.Eval(rr1_252);
	double eval2_252 = graph2inv.Eval(rr2_252);
	double eval3_252 = graph3inv.Eval(rr3_252);
	double eval4_252 = graph4inv.Eval(rr4_252);
	double eval5_252 = graph5inv.Eval(rr5_252);
	double eval6_252 = graph6inv.Eval(rr6_252);

	data_82->AddPoint(eval1_82, rr1_82);
	data_82->AddPoint(eval2_82, rr2_82);
	data_82->AddPoint(eval3_82, rr3_82);
	data_82->AddPoint(eval4_82, rr4_82);
	data_82->AddPoint(eval5_82, rr5_82);
	data_82->AddPoint(eval6_82, rr6_82);

	data_252->AddPoint(eval1_252, rr1_252);
	data_252->AddPoint(eval2_252, rr2_252);
	data_252->AddPoint(eval3_252, rr3_252);
	data_252->AddPoint(eval4_252, rr4_252);
	data_252->AddPoint(eval5_252, rr5_252);
	data_252->AddPoint(eval6_252, rr6_252);

	double mean_82 = (eval1_82+eval2_82+eval3_82+eval4_82+eval5_82+eval6_82)/6.;

	TLine *line_82 = new TLine(mean_82, -100., mean_82, 100.); 

	double mean_252 = (eval1_252+eval2_252+eval3_252+eval4_252+eval5_252+eval6_252)/6.;

	TLine *line_252 = new TLine(mean_252, -100., mean_252, 100.);

	cout << "Mean_252:" << mean_252 << endl;
	cout << "Mean_82:" << mean_82 << endl;

	double d1_252 = (rr1_252 - graph1ratios->Eval(mean_252));
	double d2_252 = (rr2_252 - graph2ratios->Eval(mean_252));
	double d3_252 = (rr3_252 - graph3ratios->Eval(mean_252));
	double d4_252 = (rr4_252 - graph4ratios->Eval(mean_252));
	double d5_252 = (rr5_252 - graph5ratios->Eval(mean_252));
	double d6_252 = (rr6_252 - graph6ratios->Eval(mean_252));

	double D_252 = pow((d1_252*d1_252)+(d2_252*d2_252)+(d3_252*d3_252)+(d4_252*d4_252)+(d5_252*d5_252)+(d6_252*d6_252), 0.5);

	cout << "D_252:" << D_252 << endl;

	double d1_82 = (rr1_82 - graph1ratios->Eval(mean_82));
	double d2_82 = (rr2_82 - graph2ratios->Eval(mean_82));
	double d3_82 = (rr3_82 - graph3ratios->Eval(mean_82));
	double d4_82 = (rr4_82 - graph4ratios->Eval(mean_82));
	double d5_82 = (rr5_82 - graph5ratios->Eval(mean_82));
	double d6_82 = (rr6_82 - graph6ratios->Eval(mean_82));

	double D_82 = pow((d1_82*d1_82)+(d2_82*d2_82)+(d3_82*d3_82)+(d4_82*d4_82)+(d5_82*d5_82)+(d6_82*d6_82), 0.5);

	cout << "D_82:" << D_82 << endl;

	TLine *line_82_1 = new TLine(-1., rr1_82, 11., rr1_82);
	TLine *line_82_2 = new TLine(-1., rr2_82, 11., rr2_82);
	TLine *line_82_3 = new TLine(-1., rr3_82, 11., rr3_82);
	TLine *line_82_4 = new TLine(-1., rr4_82, 11., rr4_82);
	TLine *line_82_5 = new TLine(-1., rr5_82, 11., rr5_82);
	TLine *line_82_6 = new TLine(-1., rr6_82, 11., rr6_82);

	TLine *line_252_1 = new TLine(-1., rr1_252, 11., rr1_252);
	TLine *line_252_2 = new TLine(-1., rr2_252, 11., rr2_252);
	TLine *line_252_3 = new TLine(-1., rr3_252, 11., rr3_252);
	TLine *line_252_4 = new TLine(-1., rr4_252, 11., rr4_252);
	TLine *line_252_5 = new TLine(-1., rr5_252, 11., rr5_252);
	TLine *line_252_6 = new TLine(-1., rr6_252, 11., rr6_252);

	line_252_1->SetLineColor(kBlue);
	line_252_2->SetLineColor(kRed);
	line_252_3->SetLineColor(kCyan);
	line_252_4->SetLineColor(kGreen);
	line_252_5->SetLineColor(kOrange);
	line_252_6->SetLineColor(kMagenta);

	line_82_1->SetLineColor(kBlue);
	line_82_2->SetLineColor(kRed);
	line_82_3->SetLineColor(kCyan);
	line_82_4->SetLineColor(kGreen);
	line_82_5->SetLineColor(kOrange);
	line_82_6->SetLineColor(kMagenta);

	line_252_1->SetLineWidth(5);
	line_252_2->SetLineWidth(5);
	line_252_3->SetLineWidth(5);
	line_252_4->SetLineWidth(5);
	line_252_5->SetLineWidth(5);
	line_252_6->SetLineWidth(5);

	line_82_1->SetLineWidth(5);
	line_82_2->SetLineWidth(5);
	line_82_3->SetLineWidth(5);
	line_82_4->SetLineWidth(5);
	line_82_5->SetLineWidth(5);
	line_82_6->SetLineWidth(5);
	
	graph1ratios->SetTitle("R2/R1");
	graph2ratios->SetTitle("R3/R1");
	graph3ratios->SetTitle("R4/R1");
	graph4ratios->SetTitle("R3/R2");
	graph5ratios->SetTitle("R4/R2");
	graph6ratios->SetTitle("R4/R3");
	
	graph1ratios->SetLineColor(kBlue);
	graph2ratios->SetLineColor(kRed);
	graph3ratios->SetLineColor(kCyan);
	graph4ratios->SetLineColor(kGreen);
	graph5ratios->SetLineColor(kOrange);
	graph6ratios->SetLineColor(kMagenta);
	
	graph1ratios->SetLineWidth(7);
	graph2ratios->SetLineWidth(7);
	graph3ratios->SetLineWidth(7);
	graph4ratios->SetLineWidth(7);
	graph5ratios->SetLineWidth(7);
	graph6ratios->SetLineWidth(7);

	mgratios->Add(graph1ratios);
	mgratios->Add(graph2ratios);
	mgratios->Add(graph3ratios);
	mgratios->Add(graph4ratios);
	mgratios->Add(graph5ratios);
	mgratios->Add(graph6ratios);

	c2->cd();
	//pad1->Draw();
	//pad1->cd();
	
    mgratios->GetXaxis()->SetTitle("Energy (MeV)");
    mgratios->GetYaxis()->SetTitle("Ring ratios");
	mgratios->Draw("A");

	data_82->Draw("sameP");
	data_82->SetLineWidth(0);
	data_82->SetMarkerStyle(104);
	data_82->SetMarkerColor(1);
	data_82->SetMarkerSize(5);

	//data_252->Draw("sameP");
	data_252->SetLineWidth(0);
	data_252->SetMarkerStyle(106);
	data_252->SetMarkerColor(1);
	data_252->SetMarkerSize(5);

	/*mgratios->GetXaxis()->SetTitleSize(0.06);
    mgratios->GetYaxis()->SetTitleSize(0.06);

    mgratios->GetXaxis()->SetLabelSize(0.05);
    mgratios->GetYaxis()->SetLabelSize(0.05);

    mgratios->GetXaxis()->SetTitleOffset(0.90);
    mgratios->GetYaxis()->SetTitleOffset(0.70);

    mgratios->GetXaxis()->SetTickSize(0.07);*/
	
	TLegend* legendratios = new TLegend(0.1,0.7,0.5,0.9);

    legendratios->AddEntry(graph1ratios,"R2/R1","l");
    legendratios->AddEntry(graph2ratios,"R3/R1","l");
    legendratios->AddEntry(graph3ratios,"R4/R1","l");
	legendratios->AddEntry(graph4ratios,"R3/R2","l");
	legendratios->AddEntry(graph5ratios,"R4/R2","l");
	legendratios->AddEntry(graph6ratios,"R4/R3","l");
	//legendratios->AddEntry(data_252,"137I");
	legendratios->AddEntry(data_82,"82Ga");
    legendratios->SetBorderSize(1);
    legendratios->SetTextSize(0.05);

	TText *t_252 = new TText(.5,.5,TString::Format("Mean = %g",mean_252)+" MeV");
	TText *t_82 = new TText(.5,.5,TString::Format("Mean = %g",mean_82)+" MeV");

	//t_252->Draw();
	t_82->Draw();

	legendratios->Draw();

	line_252->SetLineWidth(7);
	//line_252->Draw("same");

	line_82->SetLineWidth(7);

	//pad2->Draw();
	//pad2->cd();

	mgratioscompare->Add(graph1ratios);
	mgratioscompare->Add(graphratioscompare);

	//mgratioscompare->Draw("A");

	TLegend* legendcompare = new TLegend(0.1,0.7,0.5,0.9);

    legendcompare->AddEntry(graph1ratios,"R2/R1_Dirac","l");
    legendcompare->AddEntry(graphratioscompare,"R2/R1_Maxwellian","l");
	legendcompare->SetBorderSize(1);
    legendcompare->SetTextSize(0.05);

	//legendcompare->Draw();

	line_82->Draw("same");

   	/*line_252_1->Draw("same");
	line_252_2->Draw("same");
	line_252_3->Draw("same");
	line_252_4->Draw("same");
	line_252_5->Draw("same");
	line_252_6->Draw("same");*/

    /*gPad->SetLeftMargin(0.20);
    gPad->SetBottomMargin(0.25);

    gPad->RedrawAxis();*/

    fichier.close();
}