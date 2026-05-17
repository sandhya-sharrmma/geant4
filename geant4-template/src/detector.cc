#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name) {}

MySensitiveDetector::~MySensitiveDetector() {}

//Do stuff when stuff hits the detectors
G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    //Get track info
    G4Track *track = aStep->GetTrack();

    //Get info about start and end of track
    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

    //Get and print position of photon when it enters detector
    G4ThreeVector posPhoton = preStepPoint->GetPosition();
    G4cout << "Photon position" << posPhoton << G4endl;
}
