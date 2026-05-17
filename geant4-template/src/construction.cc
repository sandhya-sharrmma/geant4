#include "construction.hh"
#include "detector.hh"
#include "G4VisAttributes.hh"

MyDetectorConstruction::MyDetectorConstruction() {}

MyDetectorConstruction::~MyDetectorConstruction() {}

G4VPhysicalVolume *MyDetectorConstruction::Construct() {

    // Get particle data manager
    G4NistManager *nist = G4NistManager::Instance();

    // Define concrete
    G4Material *concrete = new G4Material("Concrete", 2.300 * g/cm3, 10);
    G4double fractionmass;
    concrete->AddElement(nist->FindOrBuildElement("H"),  fractionmass= 1.0000 * perCent);
    concrete->AddElement(nist->FindOrBuildElement("C"),  fractionmass= 0.1000 * perCent);
    concrete->AddElement(nist->FindOrBuildElement("O"),  fractionmass=52.9107 * perCent);
    concrete->AddElement(nist->FindOrBuildElement("Na"), fractionmass= 1.6000 * perCent);
    concrete->AddElement(nist->FindOrBuildElement("Mg"), fractionmass= 0.2000 * perCent);
    concrete->AddElement(nist->FindOrBuildElement("Al"), fractionmass= 3.3872 * perCent);
    concrete->AddElement(nist->FindOrBuildElement("Si"), fractionmass=33.7021 * perCent);
    concrete->AddElement(nist->FindOrBuildElement("K"),  fractionmass= 1.3000 * perCent);
    concrete->AddElement(nist->FindOrBuildElement("Ca"), fractionmass= 4.4000 * perCent);
    concrete->AddElement(nist->FindOrBuildElement("Fe"), fractionmass= 1.4000 * perCent);

    // Get air as a usable material
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    // Define world volume, fill it with air
    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

    // Define concrete block
    G4Box *solidConcrete = new G4Box("solidConcrete", 0.4 * m, 0.4 * m, 0.4 * m);
    G4LogicalVolume *logicConcrete  = new G4LogicalVolume(solidConcrete, concrete, "logicConcrete");
    G4VPhysicalVolume *physConcrete = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicConcrete, "physConcrete", 
                                                        logicWorld, false, 0, true);

    // Color Concrete
    G4VisAttributes * concAtts = new G4VisAttributes(G4Colour(0.1, 0.1, 0.1, 0.5));
    concAtts->SetVisibility(true);
    concAtts->SetForceWireframe(true);
    concAtts->SetForceSolid(true);
    logicConcrete->SetVisAttributes(concAtts);

    // Define detector shape
    G4double detectorThickness = 0.01 * m;
    G4Box *solidDetector = new G4Box("solidDetector", 0.4*m, 0.4*m, 0.5*detectorThickness);
    logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");

    // Set detector visual attributes
    G4VisAttributes * detectorAtts = new G4VisAttributes(G4Colour(0.224, 1.0, 0.078, 0.3));
    detectorAtts->SetVisibility(true);
    detectorAtts->SetForceWireframe(true);
    detectorAtts->SetForceSolid(true);
    logicDetector->SetVisAttributes(detectorAtts);

    /// Place 3 detector-layers on each side of the concrete block
    for(G4int i = 0; i < 3; i++)
    {
        G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(0.0 * m, 0.0 * m, 0.4*m + 2 * i * detectorThickness), 
                                                            logicDetector, "physDetector", logicWorld, false, i, true);
    }

    for(G4int i = 0; i < 3; i++)
    {
        G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(0.0 * m, 0.0 * m, -0.4*m - 2 * i * detectorThickness), 
                                                            logicDetector, "physDetector", logicWorld, false, i, true);
    }

    return physWorld;
}

//Set up the small bois as detectors (see detector.hh/cc for further code)
void MyDetectorConstruction::ConstructSDandField()
{
    MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
    logicDetector->SetSensitiveDetector(sensDet);
}
