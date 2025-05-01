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
/// \file hadronic/Hadr03/include/DetectorConstruction.hh
/// \brief Definition of the DetectorConstruction class
//
// $Id: DetectorConstruction.hh 66586 2012-12-21 10:48:39Z ihrivnac $
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

#include "G4ElectricField.hh"
#include "G4ChordFinder.hh"
#include "G4MagIntegratorStepper.hh"

  #include "G4EqMagElectricField.hh"
  #include "G4UniformElectricField.hh"

class G4LogicalVolume;
class G4Material;
class DetectorMessenger;
class G4VSensitiveDetector;

//class G4VPhysicalVolume;
class ElectricFieldSetup;
class G4FieldManager;
class G4EqMagElectricField;
class G4ChordFinder;
class G4EquationOfMotion;
class G4Mag_EqRhs;
class G4MagIntegratorStepper;
class G4MagInt_Driver;
class G4UniformMagField;
class G4MaterialPropertiesTable;

class G4UniformElectricField;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
    DetectorConstruction();
   ~DetectorConstruction();

  public:
  
    virtual G4VPhysicalVolume* Construct();

    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

    G4Material* 
    MaterialWithSingleIsotope(G4String, G4String, G4double, G4int, G4int);
         
    void SetRadius   (G4double);              
    void SetMaterial (G4String);      

    virtual void ConstructSDandField();    

  public:  
                    
     G4double           GetRadius()     {return fRadius;};      
     G4Material*        GetMaterial()   {return fMaterial;};
                   
    void               PrintParameters();

  protected:

    G4LogicalVolume*   fLAbsor;
    G4LogicalVolume*   fLAbsor1;
     G4VPhysicalVolume* fPWorld;
      DetectorMessenger* fDetectorMessenger;  
    G4Material*        fWorldMat;

    G4LogicalVolume*  fScoringVolume;  

  private:
     
     G4double           fRadius;
     G4Material*        fMaterial;

     
     G4double           fWorldSize2;
 
     G4LogicalVolume*   logicEnv;                      
  
     G4Material* fB4C;
     G4Material* fSi2;
     G4Material* fAir;
     G4Material* fGd;
     G4Material* fGdd;
     G4Material* fCZT;

  private:
    
     void               DefineMaterials();
     G4VPhysicalVolume* ConstructVolumes();     

/*  //   G4FieldManager*          fLocalFieldManager;
     G4EqMagElectricField*    fLocalEquation;
     G4MagIntegratorStepper*  fLocalStepper; 
  //   G4ElectricField*         fEMfield;                //Pointers to local E field 
     G4ChordFinder*           fLocalChordFinder; 
     G4double                 fMinStep ; 
     G4MagInt_Driver*         fIntgrDriver;*/

  //  G4UniformElectricField*   fEMfield;

  //   G4VSensitiveDetector*     SensDet;
//G4VSensitiveDetector* sensBox;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


#endif

