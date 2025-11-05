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

void CompareG4_MCNP()
{   
    vector<double> exp;
    vector<double> g4;
    vector<double> mcnp;

    TGraph* graph = new TGraph();

    mcnp.push_back(1.52175E-01);
    mcnp.push_back(1.48790E-01);
    mcnp.push_back(1.03791E-01);
    mcnp.push_back(6.78615E-02);

    exp.push_back(128539.00)
    exp.push_back(129716.00);
    exp.push_back(94376.000);
    exp.push_back(60937.000);

    g4.push_back(20157.);
    g4.push_back(18415.);
    g4.push_back(10299.);
    g4.push_back(5581.);

    graph->AddPoint(mcnp[0]);

       const Int_t n = 4;
   Double_t ring[n]  = {1.,2.,3.,4.};
   Double_t mcnp[n]  = {1.52175E1,};
   Double_t errorexp[n] = 
   Double_t ex[n] = {0.,0.,0.,0.};
   Double_t ey[n] = {.8,.7,.6,.5,.4,.4,.5,.6,.7,.8};
   auto gr = new TGraphErrors(n,x,y,ex,ey);
}