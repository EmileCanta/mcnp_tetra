#include "TFile.h"
#include "TF1.h"
#include "fstream"

using namespace std;

Double_t mu = 1.;
Double_t sigma = 1.;

Double_t f1(Double_t *x, Double_t *par)
{
	return (1/(sigma*pow(2*M_PI,0.5)))*(exp(-pow(((x[0]-mu)/sigma),2)));
	//1*((pow(x[0], 0.5))*(exp(-x[0]/0.2)))+6*((pow(x[0], 0.5))*(exp(-x[0]/0.4667)))+5*((pow(x[0], 0.5))*(exp(-x[0]/0.8667)))+5*((pow(x[0], 0.5))*(exp(-x[0]/0.8)))+4*((pow(x[0], 0.5))*(exp(-x[0]/1.4)))+3*((pow(x[0], 0.5))*(exp(-x[0]/2.2667)));
		
}

void plot()
{
	TCanvas* c1 = new TCanvas();
	
	TF1* function = new TF1("f1", f1, 0, 20);

	//function->Draw();

	TH1F* hist = new TH1F("hist","hist", 100,0,10);

	fstream file;
	file.open("energies.dat", ios::in);

	double value1;
	double value2;

	while(1)
	{
		file >> value1 >> value2;
		hist->Fill(value1,value2);

		if(file.eof()) break;
	}

	file.close();

	hist->Draw("hist");
}
