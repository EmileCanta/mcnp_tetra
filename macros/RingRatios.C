void RingRatios()
{
	std::vector<double> xaxis;

	std::vector<double> ratiovec1_mono;
	std::vector<double> ratiovec2_mono;
	std::vector<double> ratiovec3_mono;
	std::vector<double> ratiovec4_mono;
	std::vector<double> ratiovec5_mono;
	std::vector<double> ratiovec6_mono;

	std::vector<double> ratiovec1_maxw;
	std::vector<double> ratiovec2_maxw;
	std::vector<double> ratiovec3_maxw;
	std::vector<double> ratiovec4_maxw;
	std::vector<double> ratiovec5_maxw;
	std::vector<double> ratiovec6_maxw;
	
	for(double i = 0.01; i <= 5.0; i = i+0.01)
	{
		xaxis.push_back(i);
	}

	double valuet_mono;
	double value1_mono;
	double value2_mono;
	double value3_mono;
	double value4_mono;

	double errort_mono;
	double error1_mono;
	double error2_mono;
	double error3_mono;
	double error4_mono;

	double valuet_maxw;
	double value1_maxw;
	double value2_maxw;
	double value3_maxw;
	double value4_maxw;

	double errort_maxw;
	double error1_maxw;
	double error2_maxw;
	double error3_maxw;
	double error4_maxw;

    fstream fichier_mono;
	fstream fichier_maxw;

    fichier_mono.open("/home/emile/phd/data/mcnp_tetra/mono_2bar_full/data.dat");
    fichier_maxw.open("/home/emile/phd/data/mcnp_tetra/maxw_2bar_full/data.dat");

	int binningvar = 0;

    while(1) 
	{
		fichier_mono >> valuet_mono >> errort_mono >> value1_mono >> error1_mono >> value2_mono >> error2_mono >> value3_mono >> error3_mono >> value4_mono >> error4_mono;
		fichier_maxw >> valuet_maxw >> errort_maxw >> value1_maxw >> error1_maxw >> value2_maxw >> error2_maxw >> value3_maxw >> error3_maxw >> value4_maxw >> error4_maxw;

		if(binningvar%1 == 0)
      	{
			ratiovec1_mono.push_back(value2_mono/value1_mono);
			ratiovec2_mono.push_back(value3_mono/value1_mono);
			ratiovec3_mono.push_back(value4_mono/value1_mono);
			ratiovec4_mono.push_back(value3_mono/value2_mono);
			ratiovec5_mono.push_back(value4_mono/value2_mono);
			ratiovec6_mono.push_back(value4_mono/value3_mono);
             
			ratiovec1_maxw.push_back(value2_maxw/value1_maxw);
			ratiovec2_maxw.push_back(value3_maxw/value1_maxw);
			ratiovec3_maxw.push_back(value4_maxw/value1_maxw);
			ratiovec4_maxw.push_back(value3_maxw/value2_maxw);
			ratiovec5_maxw.push_back(value4_maxw/value2_maxw);
			ratiovec6_maxw.push_back(value4_maxw/value3_maxw);
      	}

      	binningvar++;

        if(fichier_mono.eof()) break;
    }

	TCanvas* c = new TCanvas("c","c", 800, 600);

    c->cd();

	TPad* pad_mono = new TPad("pad_mono","pad_mono",0,0,1,0.5);
 	TPad* pad_maxw = new TPad("pad_maxw","pad_maxw",0,0.5,1,1);
    
    pad_mono->Draw();
    pad_maxw->Draw();

    //###################Filling mono##########################//

    pad_mono->cd();

	TMultiGraph *mg_mono = new TMultiGraph();
	
	TGraph *graph1_mono = new TGraph();
	TGraph *graph2_mono = new TGraph();
	TGraph *graph3_mono = new TGraph();
	TGraph *graph4_mono = new TGraph();
	TGraph *graph5_mono = new TGraph();
	TGraph *graph6_mono = new TGraph();

	for(int j = 0; j <= 499; j++)
	{
		graph1_mono->AddPoint(xaxis[j], ratiovec1_mono[j]);
		graph2_mono->AddPoint(xaxis[j], ratiovec2_mono[j]);
		graph3_mono->AddPoint(xaxis[j], ratiovec3_mono[j]);
		graph4_mono->AddPoint(xaxis[j], ratiovec4_mono[j]);
		graph5_mono->AddPoint(xaxis[j], ratiovec5_mono[j]);
		graph6_mono->AddPoint(xaxis[j], ratiovec6_mono[j]);
	}

	graph1_mono->SetTitle("R2/R1");
	graph2_mono->SetTitle("R3/R1");
	graph3_mono->SetTitle("R4/R1");
	graph4_mono->SetTitle("R3/R2");
	graph5_mono->SetTitle("R4/R2");
	graph6_mono->SetTitle("R4/R3");
	
    mg_mono->Add(graph1_mono);
    mg_mono->Add(graph2_mono);
	mg_mono->Add(graph3_mono);
	mg_mono->Add(graph4_mono);
	mg_mono->Add(graph5_mono);
	mg_mono->Add(graph6_mono);
	
    mg_mono->GetXaxis()->SetTitle("Energy (MeV)");
    mg_mono->GetYaxis()->SetTitle("Efficiency ratio");
	mg_mono->Draw("AP");

	TLegend* legend_mono = new TLegend(0.1,0.7,0.3,0.9);

    legend_mono->AddEntry(graph1_mono,"R2/R1","p");
    legend_mono->AddEntry(graph2_mono,"R3/R1","p");
	legend_mono->AddEntry(graph3_mono,"R4/R1","p");
	legend_mono->AddEntry(graph4_mono,"R3/R2","p");
	legend_mono->AddEntry(graph5_mono,"R4/R2","p");
	legend_mono->AddEntry(graph6_mono,"R4/R3","p");
    legend_mono->SetBorderSize(0);
    legend_mono->SetTextSize(0.05);

	legend_mono->Draw();

    double counts1 = 210774.;
    double counts2 = 179332.;
    double counts3 = 98521.6;
    double counts4 = 45153.0;
    
    TGraph invg1_mono(graph1_mono->GetN(), graph1_mono->GetY(), graph1_mono->GetX());
    TGraph invg2_mono(graph2_mono->GetN(), graph2_mono->GetY(), graph2_mono->GetX());
    TGraph invg3_mono(graph3_mono->GetN(), graph3_mono->GetY(), graph3_mono->GetX());
    TGraph invg4_mono(graph4_mono->GetN(), graph4_mono->GetY(), graph4_mono->GetX());
    TGraph invg5_mono(graph5_mono->GetN(), graph5_mono->GetY(), graph5_mono->GetX());
    TGraph invg6_mono(graph6_mono->GetN(), graph6_mono->GetY(), graph6_mono->GetX());

    double energy_mono1 = invg1_mono.Eval(counts2/counts1);
    double energy_mono2 = invg2_mono.Eval(counts3/counts1);
    double energy_mono3 = invg3_mono.Eval(counts4/counts1);
    double energy_mono4 = invg4_mono.Eval(counts3/counts2);
    double energy_mono5 = invg5_mono.Eval(counts4/counts2);
    double energy_mono6 = invg6_mono.Eval(counts4/counts3);

    double mean_energy_mono = (energy_mono1+energy_mono2+energy_mono3+energy_mono4+energy_mono5+energy_mono6) / 6.;
    double mean_energy_monobis = (energy_mono1+energy_mono2+energy_mono3) / 3.;

    cout << mean_energy_mono << endl << mean_energy_monobis << endl;

    //###################Filling maxw##########################//

    pad_maxw->cd();

	TMultiGraph *mg_maxw = new TMultiGraph();
	
	TGraph *graph1_maxw = new TGraph();
	TGraph *graph2_maxw = new TGraph();
	TGraph *graph3_maxw = new TGraph();
	TGraph *graph4_maxw = new TGraph();
	TGraph *graph5_maxw = new TGraph();
	TGraph *graph6_maxw = new TGraph();

	for(int j = 0; j <= 499; j++)
	{
		graph1_maxw->AddPoint(xaxis[j], ratiovec1_maxw[j]);
		graph2_maxw->AddPoint(xaxis[j], ratiovec2_maxw[j]);
		graph3_maxw->AddPoint(xaxis[j], ratiovec3_maxw[j]);
		graph4_maxw->AddPoint(xaxis[j], ratiovec4_maxw[j]);
		graph5_maxw->AddPoint(xaxis[j], ratiovec5_maxw[j]);
		graph6_maxw->AddPoint(xaxis[j], ratiovec6_maxw[j]);
	}

	graph1_maxw->SetTitle("R2/R1");
	graph2_maxw->SetTitle("R3/R1");
	graph3_maxw->SetTitle("R4/R1");
	graph4_maxw->SetTitle("R3/R2");
	graph5_maxw->SetTitle("R4/R2");
	graph6_maxw->SetTitle("R4/R3");
	
    mg_maxw->Add(graph1_maxw);
    mg_maxw->Add(graph2_maxw);
	mg_maxw->Add(graph3_maxw);
	mg_maxw->Add(graph4_maxw);
	mg_maxw->Add(graph5_maxw);
	mg_maxw->Add(graph6_maxw);
	
    mg_maxw->GetXaxis()->SetTitle("Energy (MeV)");
    mg_maxw->GetYaxis()->SetTitle("Efficiency ratio");
	mg_maxw->Draw("AP");

	TLegend* legend_maxw = new TLegend(0.1,0.7,0.3,0.9);

    legend_maxw->AddEntry(graph1_maxw,"R2/R1","p");
    legend_maxw->AddEntry(graph2_maxw,"R3/R1","p");
	legend_maxw->AddEntry(graph3_maxw,"R4/R1","p");
	legend_maxw->AddEntry(graph4_maxw,"R3/R2","p");
	legend_maxw->AddEntry(graph5_maxw,"R4/R2","p");
	legend_maxw->AddEntry(graph6_maxw,"R4/R3","p");
    legend_maxw->SetBorderSize(0);
    legend_maxw->SetTextSize(0.06);

	legend_maxw->Draw();
    
    TGraph invg1_maxw(graph1_maxw->GetN(), graph1_maxw->GetY(), graph1_maxw->GetX());
    TGraph invg2_maxw(graph2_maxw->GetN(), graph2_maxw->GetY(), graph2_maxw->GetX());
    TGraph invg3_maxw(graph3_maxw->GetN(), graph3_maxw->GetY(), graph3_maxw->GetX());
    TGraph invg4_maxw(graph4_maxw->GetN(), graph4_maxw->GetY(), graph4_maxw->GetX());
    TGraph invg5_maxw(graph5_maxw->GetN(), graph5_maxw->GetY(), graph5_maxw->GetX());
    TGraph invg6_maxw(graph6_maxw->GetN(), graph6_maxw->GetY(), graph6_maxw->GetX());

    double energy_maxw1 = invg1_maxw.Eval(counts2/counts1);
    double energy_maxw2 = invg2_maxw.Eval(counts3/counts1);
    double energy_maxw3 = invg3_maxw.Eval(counts4/counts1);
    double energy_maxw4 = invg4_maxw.Eval(counts3/counts2);
    double energy_maxw5 = invg5_maxw.Eval(counts4/counts2);
    double energy_maxw6 = invg6_maxw.Eval(counts4/counts3);
    
    double mean_energy_maxw = (energy_maxw1+energy_maxw2+energy_maxw3+energy_maxw4+energy_maxw5+energy_maxw6) / 6.;
    double mean_energy_maxwbis = (energy_maxw1+energy_maxw2+energy_maxw3) / 3.;

    cout << mean_energy_maxw << endl << mean_energy_maxwbis << endl;
}
