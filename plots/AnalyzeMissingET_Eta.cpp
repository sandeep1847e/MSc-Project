// AnalyzeMissingET_Eta.cpp
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>

void AnalyzeMissingET_Eta() {
    TFile *f = TFile::Open("tag_1_delphes_events.root");
    TTree *tree = (TTree*)f->Get("Delphes");

    TH1F *hEta = new TH1F("hEta", "Missing ET Eta", 100, -5, 5);
    tree->Draw("MissingET.Eta>>hEta");

    TCanvas *c8 = new TCanvas("c8", "Missing ET Eta Distribution", 800, 600);
    hEta->Draw();
    c8->SaveAs("MissingET_Eta.png");

    delete f;
}

