// AnalyzeFatJet_PT.cpp
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>

void AnalyzeFatJet_PT() {
    TFile *f = TFile::Open("tag_1_delphes_events.root");
    TTree *tree = (TTree*)f->Get("Delphes");

    TH1F *hFatJetPT = new TH1F("hFatJetPT", "Fat Jet PT", 100, 0, 500);
    tree->Draw("FatJet.PT>>hFatJetPT");

    TCanvas *c5 = new TCanvas("c5", "Fat Jet PT Distribution", 800, 600);
    hFatJetPT->Draw();
    c5->SetLogy();

    // Update the canvas to reflect changes
    c5->Update();
    c5->SaveAs("FatJet_PT.png");

    delete f;
}

