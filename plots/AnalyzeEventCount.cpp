#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>

void AnalyzeEventCount() {
    TFile *f = TFile::Open("tag_1_delphes_events.root");
    TTree *tree = (TTree*)f->Get("Delphes");

    Long64_t nEvents = tree->GetEntries();
    std::cout << "Total number of events: " << nEvents << std::endl;

    delete f;
}

