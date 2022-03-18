void greadingdata1(){
fstream file;
file.open("NNPDF31_nnlo_as_0118_0_21.dat",ios::in);
TFile *gluonoutput=new TFile("gluonutput10.root","recreate"); //gluonoutput1 for xfx vs q graph;
TTree *tree=new TTree("gluon10","data from gluon file");
Double_t x,y,z;
tree->Branch("x",&x,"y/D");
tree->Branch("fx",&z,"z/D");
while(1){
file>>x>>y>>z;
if(file.eof()) break;
if(y==10){
tree->Fill();
}

}
gluonoutput->Write();
gluonoutput->Close();

file.close();

}

