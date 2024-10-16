#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>

void AnalyzePhoton_PT() {
    TFile *f = TFile::Open("tag_1_delphes_events.root");
    TTree *tree = (TTree*)f->Get("Delphes");

    TH1F *hPhotonPT = new TH1F("hPhotonPT", "Photon PT", 100, 0, 500);
    tree->Draw("Photon.PT>>hPhotonPT");

    TCanvas *c3 = new TCanvas("c3", "Photon PT Distribution", 800, 600);
    hPhotonPT->Draw();
    c3->SaveAs("Photon_PT.png");

    delete f;
}

