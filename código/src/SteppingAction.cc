// Geant4 Libraries
//
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4OpticalPhoton.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "g4root.hh"
#include "G4SDManager.hh"
#include "G4TransportationManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4UserEventAction.hh"
#include "G4Event.hh"

#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "PMTSD.hh"
#include "PMTHit.hh"
#include "UserEventAction.hh"
#include "PrimarySpectrum.hh"

SteppingAction::SteppingAction()
  : G4UserSteppingAction()
{

  G4TransportationManager::GetTransportationManager()
    ->GetNavigatorForTracking()->SetPushVerbosity(0);

fEventNumber = -1;
alsuelo=0;
generadas = 0;
ener_e=0;
ener_g=0;
ener_n=0;
ener_p=0;
detect_g=0;
detect_e=0;
ener_e_det=0;
ener_g_det=0;

  detectorConstruction 
     = static_cast < const DetectorConstruction* 
     > (G4RunManager::GetRunManager()
         ->GetUserDetectorConstruction());
}

SteppingAction::~SteppingAction()
{}


void SteppingAction::UserSteppingAction(const G4Step* step)
{


  // ==========================
  // Get current PhysicalVolume
  thePostPV = step->GetPostStepPoint()->GetPhysicalVolume()->GetName();
  thePrePV = step->GetPreStepPoint()->GetPhysicalVolume()->GetName();


  // =========
  // Get Track
  G4Track* track = step->GetTrack();

  // ============
  // Get Event Id
  G4int eventNumber                
    = G4RunManager::GetRunManager()
    ->GetCurrentEvent()
    ->GetEventID();
  
  // =================
  // Get Particle Name
  G4String ParticleName 
    = track->GetDynamicParticle()->GetParticleDefinition()->GetParticleName();

  // =================
  // Get Histograms
  G4AnalysisManager* analysisManager
    = G4AnalysisManager::Instance();

  //==========================
  // Global time
  //G4double tiempo = track->GetGlobalTime();

  // =================
  // Get parent ID
  G4double parentID = step->GetTrack()->GetParentID();

  // =================
  // Get current step number
  G4double paso = step->GetTrack()->GetCurrentStepNumber();


  // ******************************
  // Reset variables for each event
  // ******************************
  if (eventNumber != fEventNumber)
  {fEventNumber = eventNumber;
     ener_e=0;
     ener_g=0;
     ener_n=0;
     ener_p=0;
     ener_e_det=0;
     ener_g_det=0;
   }

  if( parentID == 0 && thePostPV == "ground")
    track->SetTrackStatus(fStopAndKill);

  if ( thePostPV == "fWorld" || thePostPV  == "ground" )
    track->SetTrackStatus(fStopAndKill);
 
//Secondaries that interact with the "Suelo"
  if( parentID == 0 && thePrePV == "World" && thePostPV == "suelo")
    {alsuelo=1; analysisManager->FillH1(0,alsuelo);

     }

//Generated particles, count and energy

	if(parentID>0  && paso==1 && (thePrePV == "suelo" || thePrePV == "mina")){
       //Total particles generated
	generadas=1;
        analysisManager->FillH1(1,generadas);

       //Total electrons and positrons generated
	if(ParticleName== "e-" || ParticleName=="e+")
		{generadas=2; 
		analysisManager->FillH1(1,generadas);
		ener_e = step->GetPreStepPoint()->GetKineticEnergy();
		analysisManager->FillH1(2,ener_e);
       			//Total electrons detected
			if (thePrePV == "suelo" && thePostPV == "detector")
				{detect_e = 1;
				analysisManager->FillH1(6,detect_e);
				ener_e_det = step->GetPreStepPoint()->GetKineticEnergy();
				analysisManager->FillH1(8,ener_e_det);
				track->SetTrackStatus(fStopAndKill);		
				}
		}

       //Total gammas generated
	if(ParticleName== "gamma" || ParticleName== "opticalphoton")
		{generadas=3; 
		analysisManager->FillH1(1,generadas);
		ener_g =step->GetPreStepPoint()->GetKineticEnergy();
		analysisManager->FillH1(3,ener_g);
       			//Total gammas detected
			if (thePrePV == "suelo" && thePostPV == "detector")
				{detect_g = 1;
				analysisManager->FillH1(7,detect_g);
				ener_g_det = step->GetPreStepPoint()->GetKineticEnergy();
				analysisManager->FillH1(9,ener_g_det);
				track->SetTrackStatus(fStopAndKill);		
				}
		}	

       //Total neutrons generated
        if(ParticleName== "neutron" || ParticleName=="anti_neutron")
		{generadas=4;
		analysisManager->FillH1(1,generadas);
		ener_n =step->GetPreStepPoint()->GetKineticEnergy();
		analysisManager->FillH1(4,ener_n);
		}

       //Total protons generated
        if(ParticleName== "proton" || ParticleName=="anti_proton")
		{generadas=5;
		analysisManager->FillH1(1,generadas);
		ener_p =step->GetPreStepPoint()->GetKineticEnergy();
		analysisManager->FillH1(5,ener_p);
		}

										}

}


