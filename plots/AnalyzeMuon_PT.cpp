// AnalyzeMuon_PT.cpp
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>

void AnalyzeMuon_PT() {
    TFile *f = TFile::Open("tag_1_delphes_events.root");
    TTree *tree = (TTree*)f->Get("Delphes");

    TH1F *hMuonPT = new TH1F("hMuonPT", "Muon PT", 100, 0, 500);
    tree->Draw("Muon.PT>>hMuonPT");

    TCanvas *c4 = new TCanvas("c4", "Muon PT Distribution", 800, 600);
    hMuonPT->Draw();
    c4->SaveAs("Muon_PT.png");

    delete f;
}

