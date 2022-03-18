void plotxfx10gev(){
TCanvas *C1=new TCanvas("xfx10gev","plot",100,100,1000,1000);
C1->SetLogx();
C1->SetTickx();
C1->SetTicky();

TMultiGraph *mg=new TMultiGraph();
//mg->GetXaxis()->SetTitle("X");
//mg->GetXaxis()->CenterTitle();
//mg->GetYaxis()->SetTitle("xf(x,q2)");
//mg->GetYaxis()->CenterTitle();
//mg->GetXaxis()->SetRangeUser(1.0e-5,1);
//mg->GetYaxis()->SetRangeUser(0,2);

TGraph *gr1=new TGraph();
gr1->SetLineColor(2);
gr1->SetLineWidth(2);


//gr1->GetXaxis()->SetRangeUser(1.0e-5,1);
TFile *input1=new TFile("gluonoutput.root","read");
TTree *tree1=(TTree*)input1->Get("gluon");
Double_t x,z;
tree1->SetBranchAddress("x",&x);
tree1->SetBranchAddress("fx",&z);



Double_t entries1 =tree1->GetEntries();
for (Double_t i =0;i<=entries1;i++)
        {tree1->GetEntry(i);
	//cout<<x<<" "<<z<<endl;

        gr1->SetPoint(gr1->GetN(),x,z/5);
        }
mg->Add(gr1);
input1->Close();

TGraph *gr2=new TGraph();

gr2->SetLineColor(3);
gr2->SetLineWidth(2);

//gr2->GetXaxis()->SetRangeUser(1.0e-10,1);
TFile *input2=new TFile("doutput.root","read");
TTree *tree2=(TTree*)input2->Get("d10gev");
Double_t a,b;
tree2->SetBranchAddress("x",&a);
tree2->SetBranchAddress("fx",&b);



Double_t entries2 =tree2->GetEntries();
for (Double_t k =0;k<=entries2;k++)
        {tree2->GetEntry(k);

        gr2->SetPoint(gr2->GetN(),a,b);
        }
mg->Add(gr2);
input2->Close();

TGraph *gr3=new TGraph();

gr3->SetLineColor(4);
gr3->SetLineWidth(2);

//gr3->GetXaxis()->SetRangeUser(1.0e-10,1);
TFile *input3=new TFile("uoutput.root","read");
TTree *tree3=(TTree*)input3->Get("u10gev");
Double_t c,d;
tree3->SetBranchAddress("x",&c);
tree3->SetBranchAddress("fx",&d);



Double_t entries3 =tree3->GetEntries();
for (Double_t k =0;k<=entries3;k++)
        {tree3->GetEntry(k);
       

        gr3->SetPoint(gr3->GetN(),c,d);
        }
mg->Add(gr3);
input3->Close();

TGraph *gr4=new TGraph();
gr4->SetLineColor(5);
gr4->SetLineWidth(2);


TFile *input4=new TFile("soutput.root","read");
TTree *tree4=(TTree*)input4->Get("s10gev");
Double_t e,f;
tree4->SetBranchAddress("x",&e);
tree4->SetBranchAddress("fx",&f);



Double_t entries4 =tree4->GetEntries();
for (Double_t k =0;k<=entries4;k++)
        {tree4->GetEntry(k);
        

        gr4->SetPoint(gr4->GetN(),e,f);
        }
mg->Add(gr4);
input4->Close();

TGraph *gr5=new TGraph();
gr5->SetLineColor(6);
gr5->SetLineWidth(2);


TFile *input5=new TFile("coutput.root","read");
TTree *tree5=(TTree*)input5->Get("c10gev");
Double_t g,h;
tree5->SetBranchAddress("x",&g);
tree5->SetBranchAddress("fx",&h);



Double_t entries5 =tree5->GetEntries();
for (Double_t k =0;k<=entries5;k++)
        {tree5->GetEntry(k);
        

        gr5->SetPoint(gr5->GetN(),g,h);
        }
mg->Add(gr5);
input5->Close();

TGraph *gr6=new TGraph();
gr6->SetLineColor(7);
gr6->SetLineWidth(2);


TFile *input6=new TFile("boutput.root","read");
TTree *tree6=(TTree*)input6->Get("b10gev");
Double_t i,j;
tree6->SetBranchAddress("x",&i);
tree6->SetBranchAddress("fx",&j);


Double_t entries6 =tree6->GetEntries();
for (Double_t k =0;k<=entries6;k++)
        {tree6->GetEntry(k);


        gr6->SetPoint(gr6->GetN(),i,j);
        }
mg->Add(gr6);
input5->Close();


//mg->GetXaxis()->SetRange(1.0e-5,1);
//mg->GetYaxis()->SetRangeUser(0,10);

mg->Draw("ALP");
//mg->SetTitle("Private Work");
gStyle->SetTitleFontSize(0.06);
mg->GetXaxis()->SetTitle("X");
mg->GetXaxis()->SetTitleSize(0.05);
//mg->GetXaxis()->CenterTitle();
mg->GetYaxis()->SetTitle("xf(x,q2)");
mg->GetYaxis()->SetTitleSize(0.05);
mg->GetYaxis()->CenterTitle();


TLegend *leg=new TLegend(0.7,0.7,0.9,0.9);
leg->SetHeader("NNPDF31_NNLO at q^{2}=10GeV^{2}","c");
leg->SetTextSize(0.04);



TLegendEntry *le1 = leg->AddEntry(gr1,"xf, flav =g/5","l");
TLegendEntry *le2 = leg->AddEntry(gr2,"xf, flav =d","l");
TLegendEntry *le3 = leg->AddEntry(gr3,"xf, flav =u","l");
TLegendEntry *le4 = leg->AddEntry(gr4,"xf, flav =s","l");
TLegendEntry *le5 = leg->AddEntry(gr5,"xf, flav =c","l");
TLegendEntry *le6 = leg->AddEntry(gr6,"xf, flav =b","l");
leg->SetBorderSize(0);
leg->Draw();



gPad->Update();
gPad->Modified();
mg->GetXaxis()->SetRangeUser(0.001,1);
mg->GetYaxis()->SetRangeUser(0,10);
}
