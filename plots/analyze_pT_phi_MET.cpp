#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
//pT,phi,MET
void analyze_pT_phi_MET() {
    TFile *file = TFile::Open("tag_1_delphes_events.root");
    TTree *tree = (TTree*)file->Get("Delphes");

    //Transverse Momentum (pT) Distribution
    TCanvas *c1 = new TCanvas("c1", "Transverse Momentum Distribution", 800, 600);
    TH1F *h_pT = new TH1F("h_pT", "Transverse Momentum Distribution; pT [GeV]; Events", 100, 0, 500);
    tree->Draw("Particle.PT>>h_pT");
    h_pT->SetLineColor(kBlue);
    h_pT->SetTitle("Transverse Momentum Distribution");
    h_pT->GetXaxis()->SetTitle("pT [GeV]");
    h_pT->GetYaxis()->SetTitle("Events");
    h_pT->Draw();
    c1->SaveAs("pT_distribution.png");

    //Azimuthal Angle Distribution (Phi)
    TCanvas *c2 = new TCanvas("c2", "Azimuthal Angle Distribution", 800, 600);
    TH1F *h_phi = new TH1F("h_phi", "Azimuthal Angle Distribution; #phi [rad]; Events", 100, -3.14, 3.14);
    tree->Draw("Particle.Phi>>h_phi");
    h_phi->SetLineColor(kRed);
    h_phi->SetTitle("Azimuthal Angle Distribution");
    h_phi->GetXaxis()->SetTitle("#phi [rad]");
    h_phi->GetYaxis()->SetTitle("Events");
    h_phi->Draw();
    c2->SaveAs("phi_distribution.png");

    //Missing ET (MET) Distribution
    TCanvas *c3 = new TCanvas("c3", "Missing ET Distribution", 800, 600);
    TH1F *h_met = new TH1F("h_met", "Missing ET Distribution; MET [GeV]; Events", 100, 0, 500);
    tree->Draw("MissingET.MET>>h_met");
    h_met->SetLineColor(kGreen);
    h_met->SetTitle("Missing ET Distribution");
    h_met->GetXaxis()->SetTitle("MET [GeV]");
    h_met->GetYaxis()->SetTitle("Events");
    h_met->Draw();
    c3->SaveAs("met_distribution.png");
}

