void Response()
{	

    std::vector<double> energy;
    std::vector<double> Nvectot;
    std::vector<double> Nvec1;
    std::vector<double> Nvec2;
    std::vector<double> Nvec3;
    std::vector<double> Nvec4;
    
    TFile *file2;
    file2 = TFile::Open("~/phd/analysis/monster25/root_files/En82Ga.root");
    TH1D* h2 = (TH1D*)file2->Get("hist_E_corrected_MonAndPla");

    vector<double> exp;

    vector<double> chi2vec;

    //Main parameters

    int nbin = 1000;
    int nrebin = 1000;
    double maxvaluehist = 10.01;
    double minvaluehist = 0.01;
    
    double chi2min = 1e-8;
    int itmax = 100000;

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

    /* exp.push_back(301397.00); //82Ga
       exp.push_back(215293.00);
       exp.push_back(103025.00);
       exp.push_back(51063.000);
       */
    /*exp.push_back(293982.00); //82Ga_test
      exp.push_back(210302.00);
      exp.push_back(100539.00);
      exp.push_back(49523.000);*/

    /*exp.push_back(19983.00); //84Ga
      exp.push_back(14649.00);
      exp.push_back(8559.00);
      exp.push_back(6157.000);*/

    /* exp.push_back(210774.); //137I numérisé
       exp.push_back(179332.);
       exp.push_back(98521.6);
       exp.push_back(45153.0); */

      /* exp.push_back(200938.); //85As numérisé
         exp.push_back(177277.);
         exp.push_back(102494.);
         exp.push_back(49497.1); */

    /*exp.push_back(1.44753E5); //252Cf simulée avec Watz
      exp.push_back(1.45772E5);
      exp.push_back(1.04212E5);
      exp.push_back(6.97515E4);*/

    /*exp.push_back(152175); //252Cf simulée avec Maxw
      exp.push_back(148790);
      exp.push_back(103791);
      exp.push_back(67861.5);*/

      exp.push_back(245384.); //80Ga numérisé
         exp.push_back(180363.);
         exp.push_back(84433.1);
         exp.push_back(32676.4); 

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

    double step = 0;

    for(int i = 1; i <= nrebin; i++)
    {
        step = minvaluehist*i;
        
        energy.push_back(step);
    }

    std::ifstream fichier("/home/emile/phd/data/mcnp_tetra/mono_2bar_full/data.dat");

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

    int parsing_var = minvaluehist*100.;

    while (1) {

        fichier >> value1 >> error1 
            >> value2 >> error2 
            >> value3 >> error3
            >> value4 >> error4 
            >> value5 >> error5;

        if(binningvar%parsing_var == 0)
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

    TH2D* response = new TH2D("response","response",4,1,5,nbin,minvaluehist,maxvaluehist);

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

    double ntot = 0.;

    vector<double> eff;

    TH1D* p0 = new TH1D("p0","p0",nrebin,minvaluehist,maxvaluehist);
    TH1D* n0 = new TH1D("n0","n0",nrebin,minvaluehist,maxvaluehist);

    TH2D* inverse = new TH2D("inverse","inverse", 4,1,5,nrebin,minvaluehist,maxvaluehist);

    TH1D* causes = new TH1D("causes", "causes", nrebin,minvaluehist,maxvaluehist);
    TH1D* probas = new TH1D("probas", "probas", nrebin,minvaluehist,maxvaluehist);

    TGraph* chi2graph = new TGraph();

    //TCanvas* c1 = new TCanvas("c1","Canvas Example",1000,1000);

    //Defining first p0 : Uniform distribution

    for(int i=0; i <= 3; i++)
    {
        ntot = ntot + exp[i];
    }

    for(int i=1; i<nrebin+1; i++)
    { 
        p0->SetBinContent(i, 1./nrebin);
        n0->SetBinContent(i, (1./nrebin)*ntot);

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

        chi2 = causes->Chi2Test(n0,"WWCHI2/NDF");

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
        chi2graph->AddPoint(i,chi2vec[i-1]);
    }

    //chi2graph->Draw("ACL");

    p0->ResetStats();
    n0->ResetStats();

    TH1D* proba = (TH1D*)p0->Clone("proba");
    TH1D* spectrum = (TH1D*)n0->Clone("spectrum");

    TCanvas* cbis = new TCanvas("cbis","cbis",1000,1000);

    proba->Draw("hist");
    //spectrum->Draw("hist");
    //spectrum->SetLineColor(kBlack);

    //h2->Draw("samehiste");
    //spectrum->GetXaxis()->SetRangeUser(0.,5.3);
    //spectrum->GetYaxis()->UnZoom();

    double MeanIBU = spectrum->GetMean();
    cout << "Mean IBU = " << MeanIBU << endl;
    
    double ResultMean;
    double ResultMeanErr;
    
    double meansum = 0.;
    double sumcontent = 0.;
    double sumvar = 0.;

    for(int i = h2->GetXaxis()->FindBin(0.); i <= h2->GetXaxis()->FindBin(5.3); ++i)
    {
        double x = h2->GetBinCenter(i);
        double y = h2->GetBinContent(i);
        double err = h2->GetBinError(i);

        meansum += x * y;
        sumcontent += y;
        sumvar += (err * err) * (x * x);
    }

    ResultMean = meansum / sumcontent;
    ResultMeanErr = sqrt(sumvar) / fabs(sumcontent);
    
    cout << "Mean DATA = " << ResultMean << " +/- " << ResultMeanErr << endl;

    TLegend* legend = new TLegend();

    legend->AddEntry(spectrum,TString::Format("Predicted - Mean = %.2f", MeanIBU)+" MeV","f");
    legend->AddEntry(h2,TString::Format("Data - Mean = %.2f", ResultMean)+" +/- "+TString::Format("%.2f", ResultMeanErr) + " MeV", "pe");
    legend->SetBorderSize(0);
    legend->SetTextSize(0.05);

    //legend->Draw();

    //causes->Draw("hist");
    //response->Draw("colz");
}
