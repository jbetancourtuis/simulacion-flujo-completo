#include "G4Timer.hh"
#include "RunAction.hh"
#include "G4Run.hh"
#include "g4root.hh"
#include "G4SystemOfUnits.hh"



RunAction::RunAction()
 : G4UserRunAction(),
   fTimer(0)
{
  fTimer = new G4Timer;

	G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

	analysisManager->SetVerboseLevel(1);
	analysisManager->SetActivation(true);

  analysisManager->CreateH1("entran_al_suelo"," ", 2, 0., 2.);
  analysisManager->CreateH1("total_particulas_generadas"," ", 6, 0., 6.);
  analysisManager->CreateH1("energia_e"," ", 10000, 0., 100.);
  analysisManager->CreateH1("energia_gamma"," ", 10000, 0., 100.);
  analysisManager->CreateH1("energia_n"," ", 10000, 0., 100.);
  analysisManager->CreateH1("energia_p"," ", 10000, 0., 100.);
  analysisManager->CreateH1("e_detectados"," ", 3, 0., 3.);
  analysisManager->CreateH1("gamma_detectados"," ", 3, 0., 3.);
  analysisManager->CreateH1("energia_e_detectados"," ", 10000, 0., 100.);
  analysisManager->CreateH1("energia_gamma_detectados"," ", 10000, 0., 100.);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{
  delete fTimer;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* aRun)
{
  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
  fTimer->Start();

  G4AnalysisManager* analysisManager
     = G4AnalysisManager::Instance();

  G4String rootFile = "minas";
  analysisManager->OpenFile(rootFile);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* aRun)
{
  fTimer->Stop();
 G4cout << "number of event = " << aRun->GetNumberOfEvent();

  G4AnalysisManager* analysisManager
     = G4AnalysisManager::Instance();
  analysisManager->Write(); 
  analysisManager->CloseFile();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
