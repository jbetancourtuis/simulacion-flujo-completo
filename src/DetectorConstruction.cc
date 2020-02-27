
// Geant4 Libraries
//
#include "G4Material.hh"
#include "G4Element.hh"

#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpticalSurface.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSEnergyDeposit.hh"
#include "G4VPhysicalVolume.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4UnitsTable.hh"
#include "G4PhysicalConstants.hh"

#include "G4RunManager.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"

// Local Libraries
//
#include "DetectorConstruction.hh"
#include "PMTSD.hh"

DetectorConstruction::DetectorConstruction()
 : G4VUserDetectorConstruction()
{ 
 /*   O = H = C = NULL;
  water = glass = alum = NULL;
  expHall_mat = glass = alum = NULL;
*/ 
}


DetectorConstruction::~DetectorConstruction()
{}


// ****************************
// Doing Elements and Materials
// ****************************
G4VPhysicalVolume* DetectorConstruction::Construct()
{

G4NistManager* nist = G4NistManager::Instance();

G4double z, a, density;
G4String name, symbol;
G4int ncomponents, natoms;

a = 1.01*g/mole;
G4Element* elH  = new G4Element(name="Hydrogen",symbol="H" , z= 1., a);

a = 16.00*g/mole;
G4Element* elO  = new G4Element(name="Oxygen"  ,symbol="O" , z= 8., a);

a= 14.00*g/mole;
G4Element* elN = new G4Element(name="Nitrogen", symbol="N", z= 7., a);

a = 26.98*g/mole;
G4Element* elAl = new G4Element(name="Aluminium", symbol="Al", z=13., a);

a = 28.09*g/mole;
G4Element* elSi = new G4Element(name="Silicon", symbol="Si", z=14., a);

a = 22.98*g/mole;
G4Element* elNa = new G4Element(name="Sodium", symbol="Na", z=11., a);

a = 39.09*g/mole;
G4Element* elK = new G4Element(name="Potassium", symbol="K", z=19., a);

a = 40.07*g/mole;
G4Element* elCa = new G4Element(name="Calcium", symbol="Ca", z=20., a);

a = 24.31*g/mole;
G4Element* elMg = new G4Element(name="Magnesium", symbol="Mg", z=12., a);

a = 32.07*g/mole;
G4Element* elS= new G4Element(name="Sulphur", symbol="S", z=16., a);

a = 30.97*g/mole;
G4Element* elP = new G4Element(name="Phosphorus", symbol="P", z=15., a);

a = 47.87*g/mole;
G4Element* elTi = new G4Element(name="Titanium", symbol="Ti", z=22., a);

a = 55.85*g/mole;
G4Element* elFe = new G4Element(name="Iron"    ,symbol="Fe", z=26., a);

a=12.00*g/mole;
G4Element* elC =new G4Element(name="Carbon",symbol="C", z=6., a);

//Nitrato de amonio
density = 1.72*g/cm3;
G4Material* NH4NO3 = new G4Material(name="Nitrato",density,ncomponents=3);
NH4NO3->AddElement(elH, natoms=4);
NH4NO3->AddElement(elO, natoms=3);
NH4NO3->AddElement(elN, natoms=2);

//Diesel n2
//Alcanos
//n-dodecane
density = 0.8*g/cm3;
G4Material* C12H26Li = new G4Material(name="n-dodecane",density,ncomponents=2);
C12H26Li->AddElement(elH, natoms=26);
C12H26Li->AddElement(elC, natoms=12);
//n-tridecane
density = 0.8*g/cm3;
G4Material* C13H28Li = new G4Material(name="n-tridecane",density,ncomponents=2);
C13H28Li->AddElement(elH, natoms=28);
C13H28Li->AddElement(elC, natoms=13);
//n-tetradecane
density = 0.8*g/cm3;
G4Material* C14H30Li = new G4Material(name="n-tetradecane",density,ncomponents=2);
C14H30Li->AddElement(elH, natoms=30);
C14H30Li->AddElement(elC, natoms=14);
//n-pentadecane
density = 0.8*g/cm3;
G4Material* C15H32Li = new G4Material(name="n-pentadecane",density,ncomponents=2);
C15H32Li->AddElement(elH, natoms=32);
C15H32Li->AddElement(elC, natoms=15);
//n-hexadecane
density = 0.8*g/cm3;
G4Material* C16H34Li = new G4Material(name="n-hexadecane",density,ncomponents=2);
C16H34Li->AddElement(elH, natoms=34);
C16H34Li->AddElement(elC, natoms=16);
//n-heptadecane
density = 0.8*g/cm3;
G4Material* C17H36Li = new G4Material(name="n-heptadecane",density,ncomponents=2);
C17H36Li->AddElement(elH, natoms=36);
C17H36Li->AddElement(elC, natoms=17);
//Alcanos ramificados
//2,6,10-trimethyl undecane
density = 0.8*g/cm3;
G4Material* C14H30ra = new G4Material(name="2,6,10-trimethyl undecane",density,ncomponents=2);
C14H30ra->AddElement(elH, natoms=30);
C14H30ra->AddElement(elC, natoms=14);
//Cicloalcanos saturados
//heptylcyclohexane
density = 0.8*g/cm3;
G4Material* C13H26Ci = new G4Material(name="heptylcyclohexane",density,ncomponents=2);
C13H26Ci->AddElement(elH, natoms=26);
C13H26Ci->AddElement(elC, natoms=13);
//octylcyclohexane
density = 0.8*g/cm3;
G4Material* C14H28Ci = new G4Material(name="octylcyclohexane",density,ncomponents=2);
C14H28Ci->AddElement(elH, natoms=28);
C14H28Ci->AddElement(elC, natoms=14);
//nonylcyclohexane
density = 0.8*g/cm3;
G4Material* C15H30Ci = new G4Material(name="nonylcyclohexane",density,ncomponents=2);
C15H30Ci->AddElement(elH, natoms=30);
C15H30Ci->AddElement(elC, natoms=15);
//Hidrocarburo policiclico aromatico
//naphthalene
density = 1.0253*g/cm3;
G4Material* C10H8PAHs = new G4Material(name="naphthalene",density,ncomponents=2);
C10H8PAHs->AddElement(elH, natoms=8);
C10H8PAHs->AddElement(elC, natoms=10);
//Biphenyl
density = 1.0*g/cm3;
G4Material* C12H10PAHs = new G4Material(name="biphenyl",density,ncomponents=2);
C12H10PAHs->AddElement(elH, natoms=10);
C12H10PAHs->AddElement(elC, natoms=12);
//Hidrocarburo policiclico aromatico alquilados
//2-methylnapthalene
density = 1.0*g/cm3;
G4Material* C11H10PAHsA = new G4Material(name="2-methylnapthalene",density,ncomponents=2);
C11H10PAHsA->AddElement(elH, natoms=10);
C11H10PAHsA->AddElement(elC, natoms=11);
//1,7 dimethylnapthtalene
density = 1.0*g/cm3;
G4Material* C12H12PAHsA = new G4Material(name="1,7 dimethylnapthtalene",density,ncomponents=2);
C12H12PAHsA->AddElement(elH, natoms=12);
C12H12PAHsA->AddElement(elC, natoms=12);
//trimethylnaphtalene
density = 1.0*g/cm3;
G4Material* C13H14PAHsA = new G4Material(name="trimethylnaphtalene",density,ncomponents=2);
C13H14PAHsA->AddElement(elH, natoms=14);
C13H14PAHsA->AddElement(elC, natoms=13);
//Alquilbencenos
//tolueno
density = 0.9*g/cm3;
G4Material* C7H8 = new G4Material(name="tolueno",density,ncomponents=2);
C7H8->AddElement(elH, natoms=8);
C7H8->AddElement(elC, natoms=7);
//benceno
density = 0.9*g/cm3;
G4Material* C6H6 = new G4Material(name="benceno",density,ncomponents=2);
C6H6->AddElement(elH, natoms=6);
C6H6->AddElement(elC, natoms=6);
		
//Diesel
G4double  fractionmass;
density = 0.8145*g/cm3;
G4Material* Diesel = new G4Material(name="Diesel",density,ncomponents=17);
Diesel->AddMaterial(C12H26Li, fractionmass=3.205*perCent);
Diesel->AddMaterial(C13H28Li, fractionmass=5.389*perCent);
Diesel->AddMaterial(C14H30Li, fractionmass=4.785*perCent);
Diesel->AddMaterial(C15H32Li, fractionmass=5.169*perCent);
Diesel->AddMaterial(C16H34Li, fractionmass=4.479*perCent);
Diesel->AddMaterial(C17H36Li, fractionmass=4.874*perCent);
Diesel->AddMaterial(C14H30ra, fractionmass=53.87*perCent);
Diesel->AddMaterial(C13H26Ci, fractionmass=2.883*perCent);
Diesel->AddMaterial(C14H28Ci, fractionmass=2.515*perCent);
Diesel->AddMaterial(C15H30Ci, fractionmass=2.321*perCent);
Diesel->AddMaterial(C10H8PAHs, fractionmass=0.165*perCent);
Diesel->AddMaterial(C12H10PAHs, fractionmass=0.095*perCent);
Diesel->AddMaterial(C11H10PAHsA, fractionmass=0.494*perCent);
Diesel->AddMaterial(C12H12PAHsA, fractionmass=0.549*perCent);
Diesel->AddMaterial(C13H14PAHsA, fractionmass=2.657*perCent);
Diesel->AddMaterial(C7H8, fractionmass=0.201*perCent);
Diesel->AddMaterial(C6H6, fractionmass=6.349*perCent);

//ANFO
density=1.66*g/cm3;
G4Material* ANFO= new G4Material(name="ANFO",density, ncomponents=2);
ANFO->AddMaterial(NH4NO3, fractionmass=94.3*perCent);
ANFO->AddMaterial(Diesel, fractionmass=5.7*perCent);

//TIPOS DE SUELO
//Suelo base seca
density=2700*kg/m3;
G4Material* SueloBS= new G4Material(name="SueloBS",density, ncomponents=14);
SueloBS->AddElement(elO, fractionmass=49*perCent);
SueloBS->AddElement(elSi, fractionmass=33*perCent);
SueloBS->AddElement(elAl, fractionmass=7.13*perCent);
SueloBS->AddElement(elNa, fractionmass=0.63*perCent);
SueloBS->AddElement(elK, fractionmass=1.36*perCent);
SueloBS->AddElement(elCa, fractionmass=1.37*perCent);
SueloBS->AddElement(elFe, fractionmass=3.80*perCent);
SueloBS->AddElement(elMg, fractionmass=0.60*perCent);
SueloBS->AddElement(elC, fractionmass=2.0*perCent);
SueloBS->AddElement(elS, fractionmass=0.08*perCent);
SueloBS->AddElement(elN, fractionmass=0.10*perCent);
SueloBS->AddElement(elP, fractionmass=0.09*perCent);
SueloBS->AddElement(elTi, fractionmass=0.46*perCent);
SueloBS->AddElement(elH, fractionmass=0.38*perCent);

//Agua
G4Material* elH2O= nist->FindOrBuildMaterial("G4_WATER");

//Suelo base humeda 1, 10% humedad
density=2700*kg/m3;
G4Material* SueloBH1= new G4Material(name="SueloBH1",density, ncomponents=2); 
SueloBH1->AddMaterial(SueloBS, fractionmass=90*perCent);
SueloBH1->AddMaterial(elH2O, fractionmass=10*perCent);
//Suelo base humeda 2, 20% humedad
density=2700*kg/m3;
G4Material* SueloBH2= new G4Material(name="SueloBH2",density, ncomponents=2);  
SueloBH2->AddMaterial(SueloBS, fractionmass=80*perCent);
SueloBH2->AddMaterial(elH2O, fractionmass=20*perCent);
//Suelo base humeda 3, 30%humedad
density=2700*kg/m3;
G4Material* SueloBH3= new G4Material(name="SueloBH3",density, ncomponents=2); 
SueloBH3->AddMaterial(SueloBS, fractionmass=70*perCent);
SueloBH3->AddMaterial(elH2O, fractionmass=30*perCent);

//Suelo con nitrato 1
density=2700*kg/m3;
G4Material* SueloN1= new G4Material(name="SueloN1",density, ncomponents=2);  
SueloN1->AddMaterial(SueloBS, fractionmass=99.999*perCent);
SueloN1->AddMaterial(NH4NO3, fractionmass=0.001*perCent);
//Suelo con nitrato 2
density=2700*kg/m3;
G4Material* SueloN2= new G4Material(name="SueloN2",density, ncomponents=2); 
SueloN2->AddMaterial(SueloBS, fractionmass=99.998*perCent);
SueloN2->AddMaterial(NH4NO3, fractionmass=0.002*perCent);


// ****************************
// Doing the geometries
// ****************************
   
G4bool checkOverlaps = true;

  //
  // First World
  //
  G4double fworld_sizeXY = 240.*cm;
  G4double fworld_sizeZ  = 240.*cm;
  G4Material* fworld_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* fsolidWorld =    
    new G4Box("fWorld",
		fworld_sizeXY,
		fworld_sizeXY,
		fworld_sizeZ);    
      
  G4LogicalVolume* flogicWorld =                   
    new G4LogicalVolume(fsolidWorld, 
			fworld_mat,
               		"fWorld",
			0,0,0);  
         
  G4VPhysicalVolume* fphysWorld =                         
    new G4PVPlacement(0,                    
                      G4ThreeVector(),       
                      flogicWorld,   
                      "fWorld",  
                      0,   
                      false,   
                      0,    
                      checkOverlaps);    


  //     
  // World
  //
  G4double world_sizeXY = 140.*cm;
  G4double world_sizeZ  = 140.*cm;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("World",
		world_sizeXY,
		world_sizeXY,
		world_sizeZ);    
      
  G4LogicalVolume* logicWorld =                   
    new G4LogicalVolume(solidWorld, 
			world_mat,
               		"World",
			0,0,0);  
                                   
  new G4PVPlacement(0,                    
                      G4ThreeVector(),       
                      logicWorld,   
                      "World",  
                      flogicWorld,   
                      false,   
                      0,    
                      checkOverlaps);    
  //     
  //Suelo
  //     
  G4double suelo_sizeXY = 6.81*cm;
  G4double suelo_sizeZ  = 6.81*cm;
  
  G4Box* solidsuelo =    
    new G4Box("suelo",
       		suelo_sizeXY,
		suelo_sizeXY,
		suelo_sizeZ);     
      
  G4LogicalVolume* logicsuelo =                         
    new G4LogicalVolume(solidsuelo, 
                        SueloN2, //cambiar aquí el material del suelo
                        "suelo",
			0,0,0); 
                                   
    new G4PVPlacement(0,                     
                      G4ThreeVector(),       
                      logicsuelo,          
                      "suelo",        
                      logicWorld,         
                      false,                
                      0,                     
                      checkOverlaps);       
  //
  //ANFO                     
  //     
  G4Orb* solidmina =
	new G4Orb("mina", 4.81*cm);

  G4LogicalVolume* logicmina =
	new G4LogicalVolume(solidmina,
				SueloBS,//ANFO, //cambiar aquí el material en caso de que haya mina o no
				"mina",
				0,0,0);

	new G4PVPlacement(0, 
			G4ThreeVector(),
			logicmina,
			"mina",
			logicsuelo,                
                    	false,                   
                    	0,                       
                    	checkOverlaps);
  //
  //Ground
  //
  G4double ground_sizeXY = 140*cm;
  G4double ground_sizeZ  = 0.5*cm;
  
  G4Box* solidground =    
    new G4Box("ground",
       		ground_sizeXY,
		ground_sizeXY,
		ground_sizeZ);     
      
  G4LogicalVolume* logicground =                         
    new G4LogicalVolume(solidground, 
                        world_mat,     
                        "ground",
			0,0,0); 
                                   
    new G4PVPlacement(0,                     
                      G4ThreeVector(0.,0.,-7.31*cm),       
                      logicground,          
                      "ground",        
                      logicWorld,         
                      false,                
                      0,                     
                      checkOverlaps);   

  //
  //Detector
  //
  G4double detector_sizeXY = 50.*cm;
  G4double detector_sizeZ  = 0.5*mm;
  G4Material* detector_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* soliddetector =    
    new G4Box("detector",                       
		detector_sizeXY,
		detector_sizeXY,
		detector_sizeZ);  
       
  G4LogicalVolume* logicdetector =                         
    new G4LogicalVolume(soliddetector,          
                        detector_mat,           
                        "detector",
			0,0,0);       

    new G4PVPlacement(0,                     
                      G4ThreeVector(0,0,6.86*cm),  
                      logicdetector,            
                      "detector",               
                      logicWorld,                   
                      false,                
                      0,                     
                      checkOverlaps);        

  //always return the physical World
  return fphysWorld;


}
