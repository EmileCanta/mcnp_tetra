#include <iostream>
#include <vector>
#include <fstream>

#include <root/TGraph.h>
#include <root/TCanvas.h>
#include <root/TMultiGraph.h>
#include <root/TPad.h>
#include <root/TAxis.h>

using namespace std;

void RingRatiosOld()
{	
	
	std::vector<double> energy;
	std::vector<double> ratiovec1;
	std::vector<double> ratiovec2;
	std::vector<double> ratiovec3;
	std::vector<double> ratiovec4;
	std::vector<double> ratiovec5;
	std::vector<double> ratiovec6;

	
	for(double i = 0.1; i <= 5; i = i+0.1)
	{
		energy.push_back(i);
	}

	fstream infile1;
	fstream infile2;
	fstream infile3;
	fstream infile4;
	fstream infile5;
	fstream infile6;
	
	infile1.open("/Users/cantacuzene/data/mcnp_tetra/maxwell_2bar/Ratio1File.dat", ios::in);
	infile2.open("/Users/cantacuzene/data/mcnp_tetra/maxwell_2bar/Ratio2File.dat", ios::in);
	infile3.open("/Users/cantacuzene/data/mcnp_tetra/maxwell_2bar/Ratio3File.dat", ios::in);
	infile4.open("/Users/cantacuzene/data/mcnp_tetra/maxwell_2bar/Ratio4File.dat", ios::in);
	infile5.open("/Users/cantacuzene/data/mcnp_tetra/maxwell_2bar/Ratio5File.dat", ios::in);
	infile6.open("/Users/cantacuzene/data/mcnp_tetra/maxwell_2bar/Ratio6File.dat", ios::in);
	
	double value1;
	double value2;
	double value3;
	double value4;
	double value5;
	double value6;
		
	while(1) 
	{
		infile1 >> value1;
		infile2 >> value2;
		infile3 >> value3;
		infile4 >> value4;
		infile5 >> value5;
		infile6 >> value6;
		
		if(infile1.eof()) break;
		if(infile2.eof()) break;
		if(infile3.eof()) break;
		if(infile4.eof()) break;
		if(infile5.eof()) break;
		if(infile6.eof()) break;
		
		ratiovec1.push_back(value1);
		ratiovec2.push_back(value2);
		ratiovec3.push_back(value3);
		ratiovec4.push_back(value4);
		ratiovec5.push_back(value5);
		ratiovec6.push_back(value6);
	}

	//cout << "Energy vector size:" << energy.size() << endl << "Ratio 1 vector size:" << ratiovec1.size() << endl << "Ratio 2 vector size:" << ratiovec2.size() << endl << "Ratio 3 vector size:" << ratiovec3.size() << endl << "Ratio 4 vector size:" << ratiovec4.size() << endl << "Ratio 5 vector size:" << ratiovec5.size() << endl << "Ratio 6 vector size:" << ratiovec6.size() << endl;
	
	infile1.close();
	infile2.close();
	infile3.close();
	infile4.close();
	infile5.close();
	infile6.close();
	
	TCanvas *c1 = new TCanvas();
	
	TMultiGraph *mg = new TMultiGraph();
	
	TGraph *graph1 = new TGraph();
	TGraph *graph2 = new TGraph();
	TGraph *graph3 = new TGraph();
	TGraph *graph4 = new TGraph();
	TGraph *graph5 = new TGraph();
	TGraph *graph6 = new TGraph();

	TGraph *data_84 = new TGraph();
	TGraph *data_82 = new TGraph();
	TGraph *data_cf = new TGraph();
	TGraph *data_80ga = new TGraph();
	
	for(int j = 0; j <= 49; j++)
	{
		graph1->AddPoint(energy[j],ratiovec1[j]);
		graph2->AddPoint(energy[j],ratiovec2[j]);
		graph3->AddPoint(energy[j],ratiovec3[j]);
		graph4->AddPoint(energy[j],ratiovec4[j]);
		graph5->AddPoint(energy[j],ratiovec5[j]);
		graph6->AddPoint(energy[j],ratiovec6[j]);
	}

	TGraph graph1inv = TGraph(graph1->GetN(), graph1->GetY(), graph1->GetX());
	TGraph graph2inv = TGraph(graph2->GetN(), graph2->GetY(), graph2->GetX());
	TGraph graph3inv = TGraph(graph3->GetN(), graph3->GetY(), graph3->GetX());
	TGraph graph4inv = TGraph(graph4->GetN(), graph4->GetY(), graph4->GetX());
	TGraph graph5inv = TGraph(graph5->GetN(), graph5->GetY(), graph5->GetX());
	TGraph graph6inv = TGraph(graph6->GetN(), graph6->GetY(), graph6->GetX());
	
	double rr1_84 = 0.72;
	double rr2_84 = 0.42;
	double rr3_84 = 0.30;
	double rr4_84 = 0.58;
	double rr5_84 = 0.41;
	double rr6_84 = 0.715;

	double rr1_82 = 0.71;
	double rr2_82 = 0.34;
	double rr3_82 = 0.17;
	double rr4_82 = 0.48;
	double rr5_82 = 0.24;
	double rr6_82 = 0.50;

	double rr1_cf = 1.0;
	double rr2_cf = 0.74;
	double rr3_cf = 0.47;
	double rr4_cf = 0.71;
	double rr5_cf = 0.45;
	double rr6_cf = 0.63;

	/*double rtot = 4.71381E-01; 252Cf simulée
	double r1 = 1.50246E-01;
	double r2 = 1.50313E-01;
	double r3 = 1.02585E-01;
	double r4 = 6.82371E-02;*/

	double r1 = 128539.00;	//Tests
	double r2 = 129716.00;
	double r3 = 94376.000;
	double r4 = 60937.000;

	/*double rtot_80ga = 5.43541E-01; //80Ga
	double r1_80ga = 2.45619E-01;
	double r2_80ga = 1.83915E-01;
	double r3_80ga = 8.25209E-02;
	double r4_80ga = 3.14861E-02;

	double rtot_80ga = 5.32129E-01; //85As
	double r1_80ga = 2.03443E-01;
	double r2_80ga = 1.76953E-01;
	double r3_80ga = 1.01535E-01;
	double r4_80ga = 5.01977E-02;*/

	double rtot_80ga = 5.34212E-01; //137I
	double r1_80ga = 2.11197E-01;
	double r2_80ga = 1.80289E-01;
	double r3_80ga = 9.79953E-02;
	double r4_80ga = 4.47307E-02;

	double rr1_cf_sim = (r2/r1);
	double rr2_cf_sim = (r3/r1);
	double rr3_cf_sim = (r4/r1);
	double rr4_cf_sim = (r3/r2);
	double rr5_cf_sim = (r4/r2);
	double rr6_cf_sim = (r4/r3);

	double rr1_80ga = (r2_80ga/r1_80ga);
	double rr2_80ga = (r3_80ga/r1_80ga);
	double rr3_80ga = (r4_80ga/r1_80ga);
	double rr4_80ga = (r3_80ga/r2_80ga);
	double rr5_80ga = (r4_80ga/r2_80ga);
	double rr6_80ga = (r4_80ga/r3_80ga);

	double eval1_84 = graph1inv.Eval(rr1_84);
	double eval2_84 = graph2inv.Eval(rr2_84);
	double eval3_84 = graph3inv.Eval(rr3_84);
	double eval4_84 = graph4inv.Eval(rr4_84);
	double eval5_84 = graph5inv.Eval(rr5_84);
	double eval6_84 = graph6inv.Eval(rr6_84);

	double eval1_82 = graph1inv.Eval(rr1_82);
	double eval2_82 = graph2inv.Eval(rr2_82);
	double eval3_82 = graph3inv.Eval(rr3_82);
	double eval4_82 = graph4inv.Eval(rr4_82);
	double eval5_82 = graph5inv.Eval(rr5_82);
	double eval6_82 = graph6inv.Eval(rr6_82);

	double eval1_cf = graph1inv.Eval(rr1_cf_sim);
	double eval2_cf = graph2inv.Eval(rr2_cf_sim);
	double eval3_cf = graph3inv.Eval(rr3_cf_sim);
	double eval4_cf = graph4inv.Eval(rr4_cf_sim);
	double eval5_cf = graph5inv.Eval(rr5_cf_sim);
	double eval6_cf = graph6inv.Eval(rr6_cf_sim);

	double eval1_80ga = graph1inv.Eval(rr1_80ga);
	double eval2_80ga = graph2inv.Eval(rr2_80ga);
	double eval3_80ga = graph3inv.Eval(rr3_80ga);
	double eval4_80ga = graph4inv.Eval(rr4_80ga);
	double eval5_80ga = graph5inv.Eval(rr5_80ga);
	double eval6_80ga = graph6inv.Eval(rr6_80ga);

	data_84->AddPoint(eval1_84, rr1_84);
	data_84->AddPoint(eval2_84, rr2_84);
	data_84->AddPoint(eval3_84, rr3_84);
	data_84->AddPoint(eval4_84, rr4_84);
	data_84->AddPoint(eval5_84, rr5_84);
	data_84->AddPoint(eval6_84, rr6_84);

	data_82->AddPoint(eval1_82, rr1_82);
	data_82->AddPoint(eval2_82, rr2_82);
	data_82->AddPoint(eval3_82, rr3_82);
	data_82->AddPoint(eval4_82, rr4_82);
	data_82->AddPoint(eval5_82, rr5_82);
	data_82->AddPoint(eval6_82, rr6_82);

	data_cf->AddPoint(eval1_cf, rr1_cf_sim);
	data_cf->AddPoint(eval2_cf, rr2_cf_sim);
	data_cf->AddPoint(eval3_cf, rr3_cf_sim);
	data_cf->AddPoint(eval4_cf, rr4_cf_sim);
	data_cf->AddPoint(eval5_cf, rr5_cf_sim);
	data_cf->AddPoint(eval6_cf, rr6_cf_sim);

	data_80ga->AddPoint(eval1_80ga, rr1_80ga);
	data_80ga->AddPoint(eval2_80ga, rr2_80ga);
	data_80ga->AddPoint(eval3_80ga, rr3_80ga);
	data_80ga->AddPoint(eval4_80ga, rr4_80ga);
	data_80ga->AddPoint(eval5_80ga, rr5_80ga);
	data_80ga->AddPoint(eval6_80ga, rr6_80ga);

	double mean_84 = (eval1_84+eval2_84+eval3_84+eval4_84+eval5_84+eval6_84)/6.;

	//cout << "R2/R1_84:" << eval1_84 << endl;
	//cout << "R3/R1_84:" << eval2_84 << endl;
	//cout << "R4/R1_84:" << eval3_84 << endl;
	//cout << "R3/R2_84:" << eval4_84 << endl;
	//cout << "R4/R2_84:" << eval5_84 << endl;
	//cout << "R4/R3_84:" << eval6_84 << endl;

	//cout << "Mean_84:" << mean_84 << endl;

	TLine *line_84 = new TLine(mean_84, 0., mean_84, 1.2);

	double mean_82 = (eval1_82+eval2_82+eval3_82+eval4_82+eval5_82+eval6_82)/6.;

	//cout << "R2/R1_82:" << eval1_82 << endl;
	//cout << "R3/R1_82:" << eval2_82 << endl;
	//cout << "R4/R1_82:" << eval3_82 << endl;
	//cout << "R3/R2_82:" << eval4_82 << endl;
	//cout << "R4/R2_82:" << eval5_82 << endl;
	//cout << "R4/R3_82:" << eval6_82 << endl;

	//cout << "Mean_82:" << mean_82 << endl;

	TLine *line_82 = new TLine(mean_82, 0., mean_82, 1.2);

	double mean_80ga = (eval1_80ga+eval2_80ga+eval3_80ga+eval4_80ga+eval5_80ga+eval6_80ga)/6.;

	//cout << "R2/R1_cf:" << eval1_80ga << endl;
	//cout << "R3/R1_cf:" << eval2_80ga << endl;
	//cout << "R4/R1_cf:" << eval3_80ga << endl;
	//cout << "R3/R2_cf:" << eval4_80ga << endl;
	//cout << "R4/R2_cf:" << eval5_80ga << endl;
	//cout << "R4/R3_cf:" << eval6_80ga << endl;

	//cout << "Mean_80Ga:" << mean_80ga << endl;

	TLine *line_80ga = new TLine(mean_80ga, 0., mean_80ga, 1.2);

	double mean_cf = (eval1_cf+eval2_cf+eval3_cf+eval4_cf+eval5_cf+eval6_cf)/6.;

	double d1 = (rr1_cf_sim - graph1->Eval(mean_cf));
	double d2 = (rr2_cf_sim - graph2->Eval(mean_cf));
	double d3 = (rr3_cf_sim - graph3->Eval(mean_cf));
	double d4 = (rr4_cf_sim - graph4->Eval(mean_cf));
	double d5 = (rr5_cf_sim - graph5->Eval(mean_cf));
	double d6 = (rr6_cf_sim - graph6->Eval(mean_cf));

	double D = pow((d1*d1)+(d2*d2)+(d3*d3)+(d4*d4)+(d5*d5)+(d6*d6), 0.5);

	cout << "D:" << D << endl;

	//cout << "R2/R1_cf:" << eval1_cf << endl;
	//cout << "R3/R1_cf:" << eval2_cf << endl;
	//cout << "R4/R1_cf:" << eval3_cf << endl;
	//cout << "R3/R2_cf:" << eval4_cf << endl;
	//cout << "R4/R2_cf:" << eval5_cf << endl;
	//cout << "R4/R3_cf:" << eval6_cf << endl;

	cout << "Mean_Cf:" << mean_cf << endl;

	TLine *line_cf = new TLine(mean_cf, 0., mean_cf, 1.2);
	
	graph1->SetTitle("R2/R1");
	graph2->SetTitle("R3/R1");
	graph3->SetTitle("R4/R1");
	graph4->SetTitle("R3/R2");
	graph5->SetTitle("R4/R2");
	graph6->SetTitle("R4/R3");
	//data_84->SetTitle("84Ga");
	//data_82->SetTitle("82Ga");
	//data_cf->SetTitle("252Cf");
	
	graph1->SetLineColor(kBlue);
	graph2->SetLineColor(kRed);
	graph3->SetLineColor(kCyan);
	graph4->SetLineColor(kGreen);
	graph5->SetLineColor(kOrange);
	graph6->SetLineColor(kMagenta);
	
	graph1->SetLineWidth(9);
	graph2->SetLineWidth(9);
	graph3->SetLineWidth(9);
	graph4->SetLineWidth(9);
	graph5->SetLineWidth(9);
	graph6->SetLineWidth(9);

	mg->Add(graph1);
	mg->Add(graph2);
	mg->Add(graph3);
	mg->Add(graph4);
	mg->Add(graph5);
	mg->Add(graph6);
	
    mg->GetXaxis()->SetTitle("Energy (MeV)");
    mg->GetYaxis()->SetTitle("Ring ratios");
	mg->Draw("A");

	//data_84->Draw("sameP");
	data_84->SetLineWidth(0);
	data_84->SetMarkerStyle(105);
	data_84->SetMarkerColor(1);
	data_84->SetMarkerSize(5);

	//data_82->Draw("sameP");
	data_82->SetLineWidth(0);
	data_82->SetMarkerStyle(104);
	data_82->SetMarkerColor(1);
	data_82->SetMarkerSize(5);

	data_cf->Draw("sameP");
	data_cf->SetLineWidth(0);
	data_cf->SetMarkerStyle(106);
	data_cf->SetMarkerColor(1);
	data_cf->SetMarkerSize(5);

	//data_80ga->Draw("sameP");
	data_80ga->SetLineWidth(0);
	data_80ga->SetMarkerStyle(106);
	data_80ga->SetMarkerColor(1);
	data_80ga->SetMarkerSize(5);

	mg->GetXaxis()->SetTitleSize(0.06);
    mg->GetYaxis()->SetTitleSize(0.06);

    mg->GetXaxis()->SetLabelSize(0.05);
    mg->GetYaxis()->SetLabelSize(0.05);

    mg->GetXaxis()->SetTitleOffset(0.90);
    mg->GetYaxis()->SetTitleOffset(0.70);

    mg->GetXaxis()->SetTickSize(0.07);
	
	TLegend* legend = new TLegend(0.1,0.7,0.5,0.9);

    legend->AddEntry(graph1,"R2/R1","l");
    legend->AddEntry(graph2,"R3/R1","l");
    legend->AddEntry(graph3,"R4/R1","l");
	legend->AddEntry(graph4,"R3/R2","l");
	legend->AddEntry(graph5,"R4/R2","l");
	legend->AddEntry(graph6,"R4/R3","l");
	//legend->AddEntry(data_84,"84Ga");
	//legend->AddEntry(data_82,"82Ga");
	//legend->AddEntry(data_cf,"252Cf");
    legend->SetBorderSize(1);
    legend->SetTextSize(0.05);

	legend->Draw();

	line_84->SetLineWidth(7);
   	line_84->SetLineColor(kBlack);
   	//line_84->Draw("same");

	line_82->SetLineWidth(7);
   	line_82->SetLineColor(kBlack);
   	//line_82->Draw("same");

	line_cf->SetLineWidth(7);
   	line_cf->SetLineColor(kBlack);
   	line_cf->Draw("same");

	line_80ga->SetLineWidth(7);
   	line_80ga->SetLineColor(kBlack);
   	//line_80ga->Draw("same");

    gPad->SetLeftMargin(0.20);
    gPad->SetBottomMargin(0.25);

    gPad->RedrawAxis();
}
