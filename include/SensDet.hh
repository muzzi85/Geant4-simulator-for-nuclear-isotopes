#ifndef SensDet_h
#define SensDet_h 1

#include "G4VSensitiveDetector.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class G4Step;
class G4TouchableHistory;
class G4HCofThisEvent;
class HistoManager;
class SteppingAction;

class SensDet : public G4VSensitiveDetector
{
public: // Without description

  SensDet(const G4String&);
  virtual ~SensDet();

  virtual void Initialize(G4HCofThisEvent*);
  virtual G4bool ProcessHits(G4Step*,G4TouchableHistory*);
  virtual void EndOfEvent(G4HCofThisEvent*);
  virtual void clear();
  virtual void PrintAll();

private:

  HistoManager*  fHisto;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#endif

