// AnalyzeEventMultiplicity.cpp
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>

void AnalyzeEventMultiplicity() {
    TFile *f = TFile::Open("tag_1_delphes_events.root");
    TTree *tree = (TTree*)f->Get("Delphes");

    TH1F *hMultiplicity = new TH1F("hMultiplicity", "Event Multiplicity", 100, 0, 100);
    tree->Draw("Muon_size>>hMultiplicity"); // Assuming Muon_size gives multiplicity

    TCanvas *c7 = new TCanvas("c7", "Event Multiplicity Distribution", 800, 600);
    hMultiplicity->Draw();
    c7->SaveAs("EventMultiplicity.png");

    delete f;
}

