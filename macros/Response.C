#include <iostream>
#include <vector>
#include <fstream>

#include <root/TGraph.h>
#include <root/TCanvas.h>
#include <root/TMultiGraph.h>
#include <root/TPad.h>
#include <root/TAxis.h>

#include <stdlib.h>
#include <stdio.h>

#include "TFile.h"
#include "TTree.h"
#include "TStopwatch.h"
#include "TVector3.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TROOT.h"
#include "TDirectory.h"
#include "TCutG.h"
#include "TRandom.h"

using namespace std;

void Response()
{	

  std::vector<double> energy;
  std::vector<double> Nvectot;
  std::vector<double> Nvec1;
  std::vector<double> Nvec2;
  std::vector<double> Nvec3;
  std::vector<double> Nvec4;

  vector<double> exp;

  vector<double> chi2vec;

  //Main parameters

  double nbin = 1000;
  double nrebin = 100;
  double maxvaluehist = 10.01;
  double chi2min = 1e-8;
  int itmax = 1000;
  const char* name = "./histograms/numerized_137I.root";

  //To define ring numbers by hand

  /*exp.push_back(1.20688E-1); //Gauss 2.5 0.5
  exp.push_back(1.35180E-1);
  exp.push_back(1.10132E-1);
  exp.push_back(8.21596E-2);*/

  /*exp.push_back(2.16940E-1); //Mono 0.5
  exp.push_back(1.83709E-1);
  exp.push_back(9.75525E-2);
  exp.push_back(4.19857E-2);*/

  /*exp.push_back(1.76661E-1); //Mono 1.
  exp.push_back(1.70952E-1);
  exp.push_back(1.10135E-1);
  exp.push_back(6.06350E-2);*/

  /*exp.push_back(1.48195E-1); //Mono 1.5
  exp.push_back(1.56496E-1);
  exp.push_back(1.13751E-1);
  exp.push_back(7.33254E-2);*/

  /*exp.push_back(1.37249E-1); //Mono 1.8
  exp.push_back(1.48886E-1);
  exp.push_back(1.13205E-1);
  exp.push_back(7.75695E-2);*/

  /*exp.push_back(1.31219E-1); //Mono 2.
  exp.push_back(1.44131E-1);
  exp.push_back(1.12501E-1);
  exp.push_back(7.98605E-2);*/

  /*exp.push_back(1.18879E-1); //Mono 2.5
  exp.push_back(1.34631E-1);
  exp.push_back(1.10211E-1);
  exp.push_back(8.33350E-2);*/

  /*exp.push_back(1.04596E-1); //Mono 3.
  exp.push_back(1.23688E-1);
  exp.push_back(1.07124E-1);
  exp.push_back(8.61866E-2);*/

  /*exp.push_back(7.83929E-2); //Mono 5.
  exp.push_back(9.71878E-2);
  exp.push_back(9.26620E-2);
  exp.push_back(8.50876E-2);*/

  /*exp.push_back(301397.00); //82Ga
  exp.push_back(215293.00);
  exp.push_back(103025.00);
  exp.push_back(51063.000);*/

  /*exp.push_back(293982.00); //82Ga_test
  exp.push_back(210302.00);
  exp.push_back(100539.00);
  exp.push_back(49523.000);*/

  /*exp.push_back(19983.00); //84Ga
  exp.push_back(14649.00);
  exp.push_back(8559.00);
  exp.push_back(6157.000);*/

  exp.push_back(2.10774E-01); //137I numérisé
  exp.push_back(1.79332E-01);
  exp.push_back(9.85216E-02);
  exp.push_back(4.51530E-02);

  /*exp.push_back(2.00938E-01); //85As numérisé
  exp.push_back(1.77277E-01);
  exp.push_back(1.02494E-01);
  exp.push_back(4.94971E-02);*/

  /*exp.push_back(1.44753E5); //252Cf simulée avec Watz
  exp.push_back(1.45772E5);
  exp.push_back(1.04212E5);
  exp.push_back(6.97515E4);*/

  /*exp.push_back(1.52175E-01); //252Cf simulée avec Maxw
  exp.push_back(1.48790E-01);
  exp.push_back(1.03791E-01);
  exp.push_back(6.78615E-02);*/

  /*exp.push_back(2.45384E-01); //80Ga numérisé
  exp.push_back(1.80363E-01);
  exp.push_back(8.44331E-02);
  exp.push_back(3.26764E-02);*/

  /*exp.push_back(658671.00); //252Cf_runGe3cm
  exp.push_back(686330.00);
  exp.push_back(488457.00);
  exp.push_back(307183.00);*/

  /*exp.push_back(128539.00); //252Cf+152Eu_sansGe
  exp.push_back(129716.00);
  exp.push_back(94376.000);
  exp.push_back(60937.000);*/

  /*exp.push_back(1508846.00); //tetra23 run6
  exp.push_back(1516551.00);
  exp.push_back(1085034.000);
  exp.push_back(677673.000);*/

  /*exp.push_back(1508846.00+128539.00); //somme 252cf
  exp.push_back(1516551.00+129716.00);
  exp.push_back(1085034.00+94376.000);
  exp.push_back(677673.000+60937.000);*/

  /*exp.push_back(2615816.0); //run Malia (tetra ouvert)
  exp.push_back(189397.00);
  exp.push_back(243564.00);
  exp.push_back(282339.00);*/

  for(double i = 0.01; i < maxvaluehist; i = i+0.01)
  {
      energy.push_back(i);
  }

  std::ifstream fichier("/Users/cantacuzene/phd/data/mcnp_tetra/mono_2bar_full/data.dat");
  if (!fichier) 
  {
    std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
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

  int it=0;

  int binningvar = 0;
      
  while (1) {

      fichier >> value1 >> error1 
              >> value2 >> error2 
              >> value3 >> error3
              >> value4 >> error4 
              >> value5 >> error5;

      if(binningvar%1 == 0)
      {
        Nvectot.push_back(value1);
        Nvec1.push_back(value2);
        Nvec2.push_back(value3);
        Nvec3.push_back(value4);
        Nvec4.push_back(value5);
      }

      binningvar++;

      if(fichier.eof()) break;
      }

  //cout << "Energy vector size:" << energy.size() << endl << "Ratio 1 vector size:" << ratiovec1.size() << endl << "Ratio 2 vector size:" << ratiovec2.size() << endl << "Ratio 3 vector size:" << ratiovec3.size() << endl << "Ratio 4 vector size:" << ratiovec4.size() << endl << "Ratio 5 vector size:" << ratiovec5.size() << endl << "Ratio 6 vector size:" << ratiovec6.size() << endl;

  TH2D* response = new TH2D("response","response",4,1,5,nbin,0.,maxvaluehist);

  for(int i = 0; i<energy.size(); i++)
  {
      response->SetBinContent(1,i+1,Nvec1[i]);
      response->SetBinContent(2,i+1,Nvec2[i]);
      response->SetBinContent(3,i+1,Nvec3[i]);
      response->SetBinContent(4,i+1,Nvec4[i]);
  }

  response->RebinY(nbin/nrebin);

  double sum;
  double arg;
  double addeff;

  double chi2 = 1.;

  vector<double> eff;

  TH1D* p0 = new TH1D("p0","p0",nrebin,0.,maxvaluehist);
  TH1D* n0 = new TH1D("n0","n0",nrebin,0.,maxvaluehist);

  TH2D* inverse = new TH2D("inverse","inverse", 4,1,5,nrebin,0.,maxvaluehist);

  TH1D* causes = new TH1D("causes", "causes", nrebin,0.,maxvaluehist);
  TH1D* probas = new TH1D("probas", "probas", nrebin,0.,maxvaluehist);

  TGraph* chi2graph = new TGraph();

  TCanvas* c1 = new TCanvas("c1","Canvas Example",200,10,600,480);

  TPad* pad1 = new TPad("pad1","This is pad1",0.05,0.52,0.95,0.97);
  TPad* pad2 = new TPad("pad2","This is pad2",0.05,0.02,0.95,0.47);

  //Defining first p0 : Uniform distribution

  for(int i=1; i<nrebin+1; i++)
  { 
    p0->SetBinContent(i, 1./nrebin);
    n0->SetBinContent(i, (1./nrebin)*413568);
    
    //p0->Draw();
  }

  //Constructing efficiency vector

  for(int i=1; i<nrebin+1; i++)
  {
    addeff = 0;
    
    for(int j=1; j<5; j++)
    { 
      addeff = addeff + response->GetBinContent(j,i);
    }
    
    eff.push_back(addeff);
    //cout << eff[i-1] << endl;
  }

  //Starting while for Chi2 reduction

  while(it <= itmax)
  {
    double oug = 0.;
    
    for(int i=1; i<5; i++)
    {
      sum = 0.;

      for(int j=1; j<nrebin+1; j++)
      { 
        sum = sum + (response->GetBinContent(i,j))*(p0->GetBinContent(j));
      }
      
      for(int k=1; k<nrebin+1; k++)
      {
        double numerator = (response->GetBinContent(i,k))*(p0->GetBinContent(k));
        
        inverse->SetBinContent(i,k,(numerator/sum));
      }
    }
    
    //inverse->Draw("colz");
    
    for(int i=1; i<nrebin+1; i++)
    {
      arg=0.;

      for(int j=1; j<5; j++)
      { 
        arg = arg + (exp[j-1]*inverse->GetBinContent(j,i));
      }
      
      causes->SetBinContent(i, (arg/eff[i-1]));
    }

    //causes->Draw("hist");

    for(int i=1; i<nrebin+1; i++)
    {
      oug = oug + causes->GetBinContent(i);
    }

    for(int i=1; i<nrebin+1; i++)
    {
      probas->SetBinContent(i,causes->GetBinContent(i)/oug); 
    }

    //probas->Draw("sameshist");

    //chi2 = probas->Chi2Test(p0,"WWCHI2/NDF");
    chi2 = causes->Chi2Test(n0,"WWCHI2/NDF");

    //cout << chi2 << endl;

    for(int i=1; i<nrebin+1; i++)
    {
      p0->Clear();
      p0->SetBinContent(i,probas->GetBinContent(i));

      n0->Clear();
      n0->SetBinContent(i,causes->GetBinContent(i));
    }

    inverse->Clear();
    causes->Clear();
    probas->Clear();

    chi2vec.push_back(chi2);
    it++;
  }

  for(int i = 0; i<=it; i++)
  {
    chi2graph->AddPoint(i,chi2vec[i]);
  }

  //pad1->SetLogy();

  pad1->Draw();
  pad2->Draw();

  pad1->cd();

  chi2graph->Draw();

  pad2->cd();

  /*n0->ResetStats();
  n0->SetName("counts");
  n0->Draw("hist");
  n0->SetLineColor(kRed);*/

  p0->ResetStats();

  TH1D* proba = (TH1D*)p0->Clone("proba");

  //proba->Rebin(10);

  proba->Draw("hist");
  proba->SetLineColor(kBlack);
  //proba->SaveAs(name);


  //response->Draw("colz");
}
