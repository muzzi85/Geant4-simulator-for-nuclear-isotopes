//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file hadronic/Hadr03/src/DetectorConstruction.cc
/// \brief Implementation of the DetectorConstruction class
//
// $Id: DetectorConstruction.cc 70755 2013-06-05 12:17:48Z ihrivnac $
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4Box.hh"
//#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RunManager.hh"

#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

#include "G4ProductionCuts.hh"

#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"
//#include "SensDet.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction(),
  fLAbsor(0),fLAbsor1(0),   fPWorld(0), fDetectorMessenger(0), fWorldMat(0)//, 
,  fScoringVolume(0), fMaterial(0)
{
  fRadius = 30*cm;
  fWorldSize2 = 1.1*fRadius;
  DefineMaterials();
  SetMaterial("G4_Gd");  
  fDetectorMessenger = new DetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ delete fDetectorMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  return ConstructVolumes();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::DefineMaterials()
{
  // specific element name for thermal neutronHP
  // (see G4ParticleHPThermalScatteringNames.cc)
 // G4Element* H  = new G4Element("TS_H_of_Water" ,"H" , 1., 1.0079*g/mole);
 // G4Element* O  = new G4Element("Oxygen"        ,"O" , 8., 16.00*g/mole);
  
  G4int ncomponents;//, natoms;
  //G4double density, z, molar;
  G4String name, symbol;
  G4NistManager* nist = G4NistManager::Instance();
   
 /* G4Material* H2O = 
  new G4Material("Water_ts", 1.000*g/cm3, ncomponents=2,
                         kStateLiquid, 593*kelvin, 150*bar);
  H2O->AddElement(H, natoms=2);
  H2O->AddElement(O, natoms=1);
  H2O->GetIonisation()->SetMeanExcitationEnergy(78.0*eV);*/

  // graphite
/*  G4Isotope* C12 = new G4Isotope("C12", 6, 12);  
  G4Element* elC = new G4Element("TS_C_of_Graphite","C", ncomponents=1);
  elC->AddIsotope(C12, 100.*perCent);
  G4Material* graphite = 
  new G4Material("graphite", 2.27*g/cm3, ncomponents=1,
                         kStateSolid, 293*kelvin, 1*atmosphere);
  graphite->AddElement(elC, natoms=1);*/
      
  // example of vacuum
 // fWorldMat = new G4Material("Galactic", 1, 1.01*g/mole, universe_mean_density,
 //                kStateGas, 2.73*kelvin, 3.e-18*pascal);
   
                
 //Converter
 // G4Element* elB = new G4Element(name="Boron", symbol="B", z=5, molar=10.012*g/mole);
  //G4Element* elC = new G4Element(name="Carbon", symbol="C", z=6, molar=12.0*g/mole);
  //G4Element* elN = new G4Element(name="Nitrogen", symbol="N", z=7, molar=14.003*g/mole);
  //G4Element* elO = new G4Element(name="Oxygen", symbol="O", z=8, molar=15.994*g/mole);
  //G4Element* elGd5 = new G4Element(name="Gadolinium155", symbol="Gd155", z=64, molar=154.922*g/mole);
  //G4Element* elGd7 = new G4Element(name="Gadolinium157", symbol="Gd157", z=64, molar=156.923*g/mole);


 // fB4C = new G4Material("B4C",density=2.52*g/cm3,ncomponents=2);
 // fB4C->AddElement(elB, 80*perCent);
//  fB4C->AddElement(elC, 20*perCent);

  /* fBN = new G4Material("BN",density=2.1*g/cm3,ncomponents=2);
  fBN->AddElement(elB, 50*perCent);
  fBN->AddElement(elN, 40*perCent);

  fB2O3 = new G4Material("B2O3",density=2.55*g/cm3,ncomponents=2);
  fB2O3->AddElement(elB, 40*perCent);
  fB2O3->AddElement(elO, 60*perCent);*/

  // fA155Gd2O3 = new G4Material("A155Gd2O3",density=7.41*g/cm3,ncomponents=2);
  // fA155Gd2O3->AddElement(elGd5, 40*perCent);
  // fA155Gd2O3->AddElement(elO, 60*perCent);

  /* fA157Gd2O3 = new G4Material("A157Gd2O3",density=7.41*g/cm3,ncomponents=2);
  fA157Gd2O3->AddElement(elGd7, 40*perCent);
  fA157Gd2O3->AddElement(elO, 60*perCent); 

*/


  //CZT
  G4Element* Cd = new G4Element("Cadmium","Cd",48., 112.41*g/mole);
  G4Element* Zn = new G4Element("Zinc","Zn", 30., 65.38*g/mole);
  G4Element* Te = new G4Element("Tellurium","Te", 52., 127.60*g/mole);
  fCZT = new G4Material("CZT", 5.8*g/cm3, ncomponents=3);
  fCZT->AddElement(Cd, 45*perCent);
  fCZT->AddElement(Zn, 05*perCent);
  fCZT->AddElement(Te, 50*perCent);

// Detector
  fSi2 = nist->FindOrBuildMaterial("G4_Si");
  fAir = nist->FindOrBuildMaterial("G4_AIR");
  fGd = nist->FindOrBuildMaterial("G4_Gd");



 // Gadolinium

  G4Element* Gd = new G4Element("Gadolinium","Gd",64., 160*g/mole);
  fGdd = new G4Material("Gd", 7.90*g/cm3, ncomponents=1);
  fGdd->AddElement(Gd, 100*perCent);
 ///G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/*G4Material* DetectorConstruction::MaterialWithSingleIsotope( G4String name,
                           G4String symbol, G4double density, G4int Z, G4int A)
{
 // define a material from an isotope
 //
 G4int ncomponents;
 G4double abundance, massfraction;

 G4Isotope* isotope = new G4Isotope(symbol, Z, A);
 
 G4Element* element  = new G4Element(name, symbol, ncomponents=1);
 element->AddIsotope(isotope, abundance= 100.*perCent);
 
 G4Material* material = new G4Material(name, density, ncomponents=1);
 material->AddElement(element, massfraction=100.*perCent);

 return material;
}*/

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::ConstructVolumes()
{
  // Cleanup old geometry
/*  G4GeometryManager::GetInstance()->OpenGeometry();
  G4PhysicalVolumeStore::GetInstance()->Clean();
  G4LogicalVolumeStore::GetInstance()->Clean();
  G4SolidStore::GetInstance()->Clean();*/

  G4double fWorldSize = 30*cm;
  // World
  //
  G4Box*
  sWorld = new G4Box("World",                           //name
                   fWorldSize,fWorldSize,fWorldSize);   //dimensions
                   
  G4LogicalVolume*
  lWorld = new G4LogicalVolume(sWorld,                  //shape
                             fAir,                 //material
                             "World");                  //name

  fPWorld = new G4PVPlacement(0,                        //no rotation
                            G4ThreeVector(),            //at (0,0,0)
                            lWorld,                     //logical volume
                            "World",                    //name
                            0,                          //mother volume
                            false,                      //no boolean operation
                            0);                         //copy number
                            
  // Detector CZT
  //
  G4double env_sizeX2 = 0.3*cm;
  G4double env_sizeY2 = 0.3*cm; 
  G4double env_sizeZ2 = 0.3*cm;
  G4Box* 
  sAbsor = new G4Box("Absorber",                     //name
     env_sizeX2, env_sizeY2, env_sizeZ2);   //dimensions

  fLAbsor = new G4LogicalVolume(sAbsor,                  //shape
                             fCZT,                 //material 
                             "Absorber",      //name
                              0,0,0
);

           new G4PVPlacement(0,                         //no rotation
                           G4ThreeVector(0,0,0.4*cm),             //at (0,0,0)
                           fLAbsor,                     //logical volume
                           "Absorber",        //name
                           lWorld,                      //mother  volume
                           false,                       //no boolean operation
                           0);                          //copy number


   // Detector Gd
  
  G4double env_sizeX22 = 0.3*cm;
  G4double env_sizeY22 = 0.3*cm; 
  G4double env_sizeZ22 = 0.03*cm;

  G4Box* 
  sAbsor1 = new G4Box("AbsorberGD",                     //name
     env_sizeX22, env_sizeY22, env_sizeZ22);   //dimensions

  fLAbsor1 = new G4LogicalVolume(sAbsor1,                  //shape
                             fGdd,                 //material 
                             "AbsorberGD",      //name
                              0,0,0
);

           new G4PVPlacement(0,                         //no rotation
                           G4ThreeVector(0,0,0.07*cm),             //at (0,0,0)
                           fLAbsor1,                     //logical volume
                           "AbsorberGD",        //name
                           lWorld,                      //mother  volume
                           false,                       //no boolean operation
                           0);                          //copy number


  PrintParameters();
  // Set CZT as scoring volume
  //
  fScoringVolume = fLAbsor1;

  fScoringVolume = fLAbsor;


  //always return the root volume
  //
  return fPWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::PrintParameters()
{
  G4cout << "\n The Absorber is " << G4BestUnit(fRadius,"Length")
         << " of " << fMaterial->GetName() 
         << "\n \n" << fMaterial << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetMaterial(G4String materialChoice)
{
  // search the material by its name
  G4Material* pttoMaterial =
     G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);   
  
  if (pttoMaterial) { 
    fMaterial = pttoMaterial;
    if(fLAbsor) { fLAbsor->SetMaterial(fMaterial); }
    G4RunManager::GetRunManager()->PhysicsHasBeenModified();
  } else {
    G4cout << "\n--> warning from DetectorConstruction::SetMaterial : "
           << materialChoice << " not found" << G4endl;
  }              
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::SetRadius(G4double value)
{
  fRadius = value;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::ConstructSDandField()
{
 
/* G4VSensitiveDetector* sensBox = new SensDet("/MyDetector");
 G4SDManager* SDManager = G4SDManager::GetSDMpointer();
 SDManager -> AddNewDetector(sensBox);
 fLAbsor -> SetSensitiveDetector(sensBox);*/

//Sensitive detector
  // static G4ThreadLocal G4bool initialized = false;
 //   if ( ! initialized ) {
        // Prepare sensitive detectors
      //  CheckVolumeSD* fCheckSD = new CheckVolumeSD("checkSD");
      //  (G4SDManager::GetSDMpointer())->AddNewDetector( fCheckSD );
     //   fLogicCheck->SetSensitiveDetector(fCheckSD);

    //    TargetSD* fTargetSD = new TargetSD("Absorber");
    //    (G4SDManager::GetSDMpointer())->AddNewDetector( fTargetSD );
   //     logicEnvSi->SetSensitiveDetector(fTargetSD);
    //    initialized=true;
     //   }



  // Construct the field creator - this will register the field it creates

    //Electric field equation from GetFieldValue
 // B1ElectricField* fEMfield=new B1ElectricField();

/*    G4UniformElectricField* 
   fEMfield = new G4UniformElectricField(G4ThreeVector(0.0,10.0*kilovolt/cm,0.0)); 

   //G4EqMagElectricField* 
  fLocalEquation = new G4EqMagElectricField(fEMfield);

   G4int nvar = 8;  //integrate 8 variables: x,y,z,p[xyz],E,t 
  // G4MagIntegratorStepper* 
   fLocalStepper = new G4ClassicalRK4( fLocalEquation, nvar );

  G4double 
 fMinStep = 0.010*mm;
//  fMinStep = 0.005*mm;
    G4MagInt_Driver*  
  fIntgrDriver = new G4MagInt_Driver(fMinStep, 
                                     fLocalStepper, 
                                     fLocalStepper->GetNumberOfVariables() );
  G4ChordFinder* 
  fLocalChordFinder = new G4ChordFinder(fIntgrDriver);

  G4FieldManager* 
  fLocalFieldManager = new G4FieldManager();
  fLocalFieldManager->SetDetectorField(fEMfield);  
  fLocalFieldManager->SetChordFinder(fLocalChordFinder);

  G4bool allLocal = true ;
  fLAbsor->SetFieldManager(fLocalFieldManager,allLocal); */


}

