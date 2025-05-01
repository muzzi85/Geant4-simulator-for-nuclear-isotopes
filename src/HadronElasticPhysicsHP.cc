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
/// \file hadronic/Hadr06/include/HadronElasticPhysicsHP.hh
/// \brief Definition of the HadronElasticPhysicsHP class
//
// $Id:HadronElasticPhysicsHP.cc 71037 2013-06-10 09:20:54Z gcosmo $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//
// HP models for neutron < 20 MeV

#include "HadronElasticPhysicsHP.hh"

#include "NeutronHPMessenger.hh"

#include "G4HadronicProcess.hh"
#include "G4ParticleHPElastic.hh"
#include "G4ParticleHPElasticData.hh"
#include "G4ParticleHPThermalScattering.hh"
#include "G4ParticleHPThermalScatteringData.hh"

#include "G4SystemOfUnits.hh"

///

#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessTable.hh"

// Processes

#include "G4HadronElasticProcess.hh"
#include "G4ParticleHPElasticData.hh"
#include "G4ParticleHPThermalScatteringData.hh"
#include "G4ParticleHPElastic.hh"
#include "G4ParticleHPThermalScattering.hh"

#include "G4NeutronInelasticProcess.hh"
#include "G4ParticleHPInelasticData.hh"
#include "G4ParticleHPInelastic.hh"

#include "G4HadronCaptureProcess.hh"
#include "G4ParticleHPCaptureData.hh"
#include "G4ParticleHPCapture.hh"

#include "G4HadronFissionProcess.hh"
#include "G4ParticleHPFissionData.hh"
#include "G4ParticleHPFission.hh"

#include "G4NeutronHPThermalScattering.hh"
#include "G4NeutronHPThermalScatteringData.hh"

#include "G4NeutronHPCapture.hh"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HadronElasticPhysicsHP::HadronElasticPhysicsHP(G4int ver)
: G4HadronElasticPhysics(ver),
  fThermal(false), fNeutronMessenger(0)  
{
  fNeutronMessenger   = new NeutronHPMessenger(this);  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HadronElasticPhysicsHP::~HadronElasticPhysicsHP()
{
  delete fNeutronMessenger;  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void HadronElasticPhysicsHP::ConstructProcess()
{
  G4HadronElasticPhysics::ConstructProcess();
  GetNeutronModel()->SetMinEnergy(0.5*eV);
//GetNeutronModel()->SetMinEnergy(19.5*MeV);

//  G4HadronicProcess* process = GetNeutronProcess();
//  G4ParticleHPElastic* model1 = new G4ParticleHPElastic();
//  process->RegisterMe(model1);
//  process->AddDataSet(new G4ParticleHPElasticData());

  /*if (fThermal) {    
    G4ParticleHPThermalScattering* model2 = new G4ParticleHPThermalScattering();
    process->RegisterMe(model2);
    process->AddDataSet(new G4ParticleHPThermalScatteringData());  
    model1->SetMinEnergy(4*eV);*/


  G4ParticleDefinition* neutron = G4Neutron::Neutron();
  G4ProcessManager* pManager = neutron->GetProcessManager();
   
  // delete all neutron processes if already registered
  //
  G4ProcessTable* processTable = G4ProcessTable::GetProcessTable();
  G4VProcess* process = 0;
  process = processTable->FindProcess("hadElastic", neutron);      
  if (process) pManager->RemoveProcess(process);
  //
  process = processTable->FindProcess("neutronInelastic", neutron);
  if (process) pManager->RemoveProcess(process);
  //
  process = processTable->FindProcess("nCapture", neutron);      
  if (process) pManager->RemoveProcess(process);
  //
  process = processTable->FindProcess("nFission", neutron);      
  if (process) pManager->RemoveProcess(process);      
         
  // (re) create process: elastic
  //
  G4HadronElasticProcess* process1 = new G4HadronElasticProcess();
  pManager->AddDiscreteProcess(process1);
  //
  // model1a
  G4ParticleHPElastic*  model1a = new G4ParticleHPElastic();
  process1->RegisterMe(model1a);
  process1->AddDataSet(new G4ParticleHPElasticData());
  //
  // model1b
  if (fThermal) {
    model1a->SetMinEnergy(4*eV);   
   // G4ParticleHPThermalScattering* model1b = new G4ParticleHPThermalScattering();
  //  process1->RegisterMe(model1b);
   // process1->AddDataSet(new G4ParticleHPThermalScatteringData()); 
  process1->RegisterMe(new G4NeutronHPThermalScattering);
  process1->AddDataSet(new G4NeutronHPThermalScatteringData);        
  }
   
  // (re) create process: inelastic
  //
  G4NeutronInelasticProcess* process2 = new G4NeutronInelasticProcess();
  pManager->AddDiscreteProcess(process2);   
  //
  // cross section data set
  G4ParticleHPInelasticData* dataSet2 = new G4ParticleHPInelasticData();
  process2->AddDataSet(dataSet2);                               
  //
  // models
  G4ParticleHPInelastic* model2 = new G4ParticleHPInelastic();
  process2->RegisterMe(model2);    

  // (re) create process: nCapture   
  //
//G4NeutronHPCapture* captureModel = new G4NeutronHPCapture();
//G4HadronCaptureProcess* process3 = new G4HadronCaptureProcess();
//process3->RegisterMe(captureModel);
//pManager->AddDiscreteProcess(process3);
  G4HadronCaptureProcess* process3 = new G4HadronCaptureProcess();
  pManager->AddDiscreteProcess(process3);   
 
  //
  // cross section data set
  G4ParticleHPCaptureData* dataSet3 = new G4ParticleHPCaptureData();
  process3->AddDataSet(dataSet3);                               
  //
  // models
  G4ParticleHPCapture* model3 = new G4ParticleHPCapture();
  process3->RegisterMe(model3);
   
  // (re) create process: nFission   
  //
  G4HadronFissionProcess* process4 = new G4HadronFissionProcess();
  pManager->AddDiscreteProcess(process4);    
  //
  // cross section data set
  G4ParticleHPFissionData* dataSet4 = new G4ParticleHPFissionData();
  process4->AddDataSet(dataSet4);                               
  //
  // models
  G4ParticleHPFission* model4 = new G4ParticleHPFission();
  process4->RegisterMe(model4);       
  //}      
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


